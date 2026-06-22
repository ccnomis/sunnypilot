#!/usr/bin/env python3
import argparse
import hashlib
import json
import os
import tempfile
import urllib.request
from pathlib import Path

from openpilot.common.params import Params
from openpilot.system.hardware.hw import Paths


MANIFEST_URL = "https://docs.sunnypilot.ai/models_v4.json"
DEFAULT_MODEL_KEY = "NDv2"


def sha256sum(path: Path) -> str:
  h = hashlib.sha256()
  with path.open("rb") as f:
    for chunk in iter(lambda: f.read(1024 * 1024), b""):
      h.update(chunk)
  return h.hexdigest()


def download_json(url: str) -> dict:
  with urllib.request.urlopen(url, timeout=30) as response:
    return json.loads(response.read().decode("utf-8"))


def download_file(url: str, destination: Path, expected_sha256: str) -> None:
  if destination.exists() and sha256sum(destination) == expected_sha256:
    print(f"{destination.name}: already present and verified")
    return

  destination.parent.mkdir(parents=True, exist_ok=True)
  fd, tmp_name = tempfile.mkstemp(prefix=f".{destination.name}.", suffix=".tmp", dir=destination.parent)
  os.close(fd)
  tmp_path = Path(tmp_name)

  try:
    print(f"{destination.name}: downloading")
    urllib.request.urlretrieve(url, tmp_path)
    actual_sha256 = sha256sum(tmp_path)
    if actual_sha256 != expected_sha256:
      raise RuntimeError(
        f"{destination.name}: sha256 mismatch, expected {expected_sha256}, got {actual_sha256}"
      )
    tmp_path.replace(destination)
    print(f"{destination.name}: downloaded and verified")
  finally:
    if tmp_path.exists():
      tmp_path.unlink()


def install_model(model_key: str, manifest_url: str) -> None:
  manifest = download_json(manifest_url)
  if model_key not in manifest:
    available = ", ".join(sorted(manifest))
    raise RuntimeError(f"model key {model_key!r} not found. Available keys: {available}")

  model = manifest[model_key]
  model_root = Path(Paths.model_root())

  download_file(
    model["download_uri"]["url"],
    model_root / model["file_name"],
    model["download_uri"]["sha256"],
  )
  download_file(
    model["download_uri_metadata"]["url"],
    model_root / model["file_name_metadata"],
    model["download_uri_metadata"]["sha256"],
  )

  params = Params()
  params.put("DrivingModelText", model["full_name"])
  params.put("DrivingModelName", model["display_name"])
  params.put("DrivingModelMetadataText", model["full_name_metadata"])
  params.put("DrivingModelGeneration", model["generation"])
  params.put_bool("CustomDrivingModel", True)

  # Generation 4 models do not use a custom nav model in this release-c3 tree.
  if model.get("full_name_nav"):
    params.put("NavModelText", model["full_name_nav"])

  print(f"Installed driving model: {model['display_name']}")
  print(f"Model files are in: {model_root}")


def main() -> None:
  parser = argparse.ArgumentParser(description="Install a sunnypilot custom driving model on-device.")
  parser.add_argument("--model-key", default=DEFAULT_MODEL_KEY,
                      help=f"models_v4.json key to install, default: {DEFAULT_MODEL_KEY}")
  parser.add_argument("--manifest-url", default=MANIFEST_URL,
                      help=f"model manifest URL, default: {MANIFEST_URL}")
  args = parser.parse_args()
  install_model(args.model_key, args.manifest_url)


if __name__ == "__main__":
  main()
