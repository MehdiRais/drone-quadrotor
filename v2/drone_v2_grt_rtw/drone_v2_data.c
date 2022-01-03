/*
 * drone_v2_data.c
 *
 * Code generation for model "drone_v2".
 *
 * Model version              : 1.118
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Sun Jan 02 15:53:51 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "drone_v2.h"
#include "drone_v2_private.h"

/* Block parameters (auto storage) */
P_drone_v2_T drone_v2_P = {
  0.0,                                 /* Mask Parameter: PIDController2DOF_D
                                        * Referenced by: '<S6>/Derivative Gain'
                                        */
  1.0,                                 /* Mask Parameter: PIDController2DOF_I
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  100.0,                               /* Mask Parameter: PIDController2DOF_N
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  1.0,                                 /* Mask Parameter: PIDController2DOF_P
                                        * Referenced by: '<S6>/Proportional Gain'
                                        */
  1.0,                                 /* Mask Parameter: PIDController2DOF_b
                                        * Referenced by: '<S6>/Setpoint Weighting (Proportional)'
                                        */
  1.0,                                 /* Mask Parameter: PIDController2DOF_c
                                        * Referenced by: '<S6>/Setpoint Weighting (Derivative)'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator11'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator10'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator9'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator8'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator7'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator6'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S6>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S6>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S4>/Integrator4'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<S4>/Integrator5'
                                        */
};
