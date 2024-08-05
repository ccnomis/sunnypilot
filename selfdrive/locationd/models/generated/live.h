#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_1858514917797787888);
void live_err_fun(double *nom_x, double *delta_x, double *out_4875484729766190714);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_179592295699275847);
void live_H_mod_fun(double *state, double *out_2512967513516333080);
void live_f_fun(double *state, double dt, double *out_8075543098903494570);
void live_F_fun(double *state, double dt, double *out_8357313174235544082);
void live_h_4(double *state, double *unused, double *out_7334055422967863267);
void live_H_4(double *state, double *unused, double *out_6639957704822612649);
void live_h_9(double *state, double *unused, double *out_3520759080716796977);
void live_H_9(double *state, double *unused, double *out_6398768058193022004);
void live_h_10(double *state, double *unused, double *out_5076226494856352036);
void live_H_10(double *state, double *unused, double *out_3492147269173791695);
void live_h_12(double *state, double *unused, double *out_7799849093775983163);
void live_H_12(double *state, double *unused, double *out_1620501296790650854);
void live_h_35(double *state, double *unused, double *out_1065356635111222550);
void live_H_35(double *state, double *unused, double *out_3273295647450005273);
void live_h_32(double *state, double *unused, double *out_8684744143550933566);
void live_H_32(double *state, double *unused, double *out_8258583922565429987);
void live_h_13(double *state, double *unused, double *out_6150788468479529992);
void live_H_13(double *state, double *unused, double *out_624909247907915424);
void live_h_14(double *state, double *unused, double *out_3520759080716796977);
void live_H_14(double *state, double *unused, double *out_6398768058193022004);
void live_h_33(double *state, double *unused, double *out_4404488338798221623);
void live_H_33(double *state, double *unused, double *out_122738642811147669);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}