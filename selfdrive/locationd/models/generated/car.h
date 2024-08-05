#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_5621100342814663479);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_8970128518689902605);
void car_H_mod_fun(double *state, double *out_8196959268395076182);
void car_f_fun(double *state, double dt, double *out_2999164178649114642);
void car_F_fun(double *state, double dt, double *out_5412739661144738003);
void car_h_25(double *state, double *unused, double *out_2824946284180033455);
void car_H_25(double *state, double *unused, double *out_6204205657810891431);
void car_h_24(double *state, double *unused, double *out_3909160413323954336);
void car_H_24(double *state, double *unused, double *out_7496029088932151151);
void car_h_30(double *state, double *unused, double *out_6765102305005839921);
void car_H_30(double *state, double *unused, double *out_3685872699303642804);
void car_h_26(double *state, double *unused, double *out_1763429037344994276);
void car_H_26(double *state, double *unused, double *out_8501035097024603961);
void car_h_27(double *state, double *unused, double *out_6825488325263521021);
void car_H_27(double *state, double *unused, double *out_5860636011104067715);
void car_h_29(double *state, double *unused, double *out_366060787591990775);
void car_H_29(double *state, double *unused, double *out_3175641354989250620);
void car_h_28(double *state, double *unused, double *out_7768998178165183456);
void car_H_28(double *state, double *unused, double *out_8258040372058781194);
void car_h_31(double *state, double *unused, double *out_2982132952531162600);
void car_H_31(double *state, double *unused, double *out_7874826994791252485);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}