/*
 * drone_v2.c
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

/* Block signals (auto storage) */
B_drone_v2_T drone_v2_B;

/* Continuous states */
X_drone_v2_T drone_v2_X;

/* Block states (auto storage) */
DW_drone_v2_T drone_v2_DW;

/* Real-time model */
RT_MODEL_drone_v2_T drone_v2_M_;
RT_MODEL_drone_v2_T *const drone_v2_M = &drone_v2_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  drone_v2_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  drone_v2_step();
  drone_v2_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  drone_v2_step();
  drone_v2_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void drone_v2_step(void)
{
  if (rtmIsMajorTimeStep(drone_v2_M)) {
    /* set solver stop time */
    if (!(drone_v2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&drone_v2_M->solverInfo,
                            ((drone_v2_M->Timing.clockTickH0 + 1) *
        drone_v2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&drone_v2_M->solverInfo,
                            ((drone_v2_M->Timing.clockTick0 + 1) *
        drone_v2_M->Timing.stepSize0 + drone_v2_M->Timing.clockTickH0 *
        drone_v2_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(drone_v2_M)) {
    drone_v2_M->Timing.t[0] = rtsiGetT(&drone_v2_M->solverInfo);
  }

  {
    real_T (*lastU)[6];
    real_T (*lastU_0)[3];
    real_T vz;
    real_T b;
    real_T rtb_Clock;
    real_T rtb_Derivative[6];
    int32_T i;
    real_T rtb_Derivative1_idx_0;
    real_T rtb_Derivative1_idx_1;
    real_T rtb_Memory_idx_2;
    real_T rtb_Memory_idx_3;

    /* Integrator: '<S4>/Integrator11' */
    drone_v2_B.VectorConcatenate[0] = drone_v2_X.Integrator11_CSTATE;

    /* Integrator: '<S4>/Integrator10' */
    drone_v2_B.VectorConcatenate[1] = drone_v2_X.Integrator10_CSTATE;

    /* Integrator: '<S4>/Integrator9' */
    drone_v2_B.VectorConcatenate[2] = drone_v2_X.Integrator9_CSTATE;

    /* SignalConversion: '<S4>/ConcatBufferAtVector ConcatenateIn4' incorporates:
     *  Integrator: '<S4>/Integrator8'
     */
    drone_v2_B.VectorConcatenate[3] = drone_v2_X.Integrator8_CSTATE;

    /* SignalConversion: '<S4>/ConcatBufferAtVector ConcatenateIn5' incorporates:
     *  Integrator: '<S4>/Integrator7'
     */
    drone_v2_B.VectorConcatenate[4] = drone_v2_X.Integrator7_CSTATE;

    /* SignalConversion: '<S4>/ConcatBufferAtVector ConcatenateIn6' incorporates:
     *  Integrator: '<S4>/Integrator6'
     */
    drone_v2_B.VectorConcatenate[5] = drone_v2_X.Integrator6_CSTATE;
    if (rtmIsMajorTimeStep(drone_v2_M)) {
    }

    /* Derivative: '<S1>/Derivative' */
    if ((drone_v2_DW.TimeStampA >= drone_v2_M->Timing.t[0]) &&
        (drone_v2_DW.TimeStampB >= drone_v2_M->Timing.t[0])) {
      for (i = 0; i < 6; i++) {
        rtb_Derivative[i] = 0.0;
      }
    } else {
      rtb_Clock = drone_v2_DW.TimeStampA;
      lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeA;
      if (drone_v2_DW.TimeStampA < drone_v2_DW.TimeStampB) {
        if (drone_v2_DW.TimeStampB < drone_v2_M->Timing.t[0]) {
          rtb_Clock = drone_v2_DW.TimeStampB;
          lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeB;
        }
      } else {
        if (drone_v2_DW.TimeStampA >= drone_v2_M->Timing.t[0]) {
          rtb_Clock = drone_v2_DW.TimeStampB;
          lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeB;
        }
      }

      rtb_Clock = drone_v2_M->Timing.t[0] - rtb_Clock;
      for (i = 0; i < 6; i++) {
        rtb_Derivative[i] = (drone_v2_B.VectorConcatenate[i] - (*lastU)[i]) /
          rtb_Clock;
      }
    }

    /* End of Derivative: '<S1>/Derivative' */

    /* Clock: '<S3>/Clock' */
    rtb_Clock = drone_v2_M->Timing.t[0];

    /* MATLAB Function: '<S3>/Planner' */
    /* MATLAB Function 'Planner/Planner': '<S7>:1' */
    /* '<S7>:1:3' */
    /* '<S7>:1:4' */
    /* '<S7>:1:5' */
    /* '<S7>:1:6' */
    /* '<S7>:1:7' */
    drone_v2_B.Xd[0] = sin(rtb_Clock / 2.0) * 10.0;
    drone_v2_B.Xd[1] = 0.0;
    drone_v2_B.Xd[2] = sin(rtb_Clock / 2.0) * 10.0;

    /* Derivative: '<S1>/Derivative1' */
    if ((drone_v2_DW.TimeStampA_a >= drone_v2_M->Timing.t[0]) &&
        (drone_v2_DW.TimeStampB_p >= drone_v2_M->Timing.t[0])) {
      rtb_Derivative1_idx_0 = 0.0;
      rtb_Derivative1_idx_1 = 0.0;
      rtb_Clock = 0.0;
    } else {
      rtb_Clock = drone_v2_DW.TimeStampA_a;
      lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeA_c;
      if (drone_v2_DW.TimeStampA_a < drone_v2_DW.TimeStampB_p) {
        if (drone_v2_DW.TimeStampB_p < drone_v2_M->Timing.t[0]) {
          rtb_Clock = drone_v2_DW.TimeStampB_p;
          lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeB_i;
        }
      } else {
        if (drone_v2_DW.TimeStampA_a >= drone_v2_M->Timing.t[0]) {
          rtb_Clock = drone_v2_DW.TimeStampB_p;
          lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeB_i;
        }
      }

      rtb_Clock = drone_v2_M->Timing.t[0] - rtb_Clock;
      rtb_Derivative1_idx_0 = (drone_v2_B.Xd[0] - (*lastU_0)[0]) / rtb_Clock;
      rtb_Derivative1_idx_1 = (drone_v2_B.Xd[1] - (*lastU_0)[1]) / rtb_Clock;
      rtb_Clock = (drone_v2_B.Xd[2] - (*lastU_0)[2]) / rtb_Clock;
    }

    /* End of Derivative: '<S1>/Derivative1' */

    /* MATLAB Function: '<S1>/FeedBack Linearization' */
    /* MATLAB Function 'Feedback Linearization/FeedBack Linearization': '<S5>:1' */
    /* '<S5>:1:3' */
    /* '<S5>:1:4' */
    /* '<S5>:1:6' */
    /* '<S5>:1:7' */
    /* '<S5>:1:8' */
    /* '<S5>:1:10' */
    /* '<S5>:1:11' */
    /* '<S5>:1:12' */
    /* '<S5>:1:13' */
    /* '<S5>:1:17' */
    /* '<S5>:1:18' */
    /* '<S5>:1:19' */
    vz = (drone_v2_B.Xd[2] - drone_v2_B.VectorConcatenate[2]) * 100.0 +
      (rtb_Clock - rtb_Derivative[2]) * 120.0;

    /* '<S5>:1:21' */
    rtb_Clock = ((drone_v2_B.Xd[0] - drone_v2_B.VectorConcatenate[0]) * 100.0 +
                 (rtb_Derivative1_idx_0 - rtb_Derivative[0]) * 120.0) / (vz +
      9.81);

    /* '<S5>:1:22' */
    b = ((drone_v2_B.Xd[1] - drone_v2_B.VectorConcatenate[1]) * 100.0 +
         (rtb_Derivative1_idx_1 - rtb_Derivative[1]) * 120.0) / (vz + 9.81);

    /* '<S5>:1:23' */
    rtb_Derivative1_idx_0 = cos(drone_v2_B.VectorConcatenate[5]);

    /* '<S5>:1:24' */
    rtb_Derivative1_idx_1 = sin(drone_v2_B.VectorConcatenate[5]);

    /* '<S5>:1:26' */
    drone_v2_B.VectorConcatenate1[0] = (vz + 9.81) * 0.698 / (cos
      (drone_v2_B.VectorConcatenate[3]) * cos(drone_v2_B.VectorConcatenate[4]));

    /* '<S5>:1:27' */
    if ((fabs(drone_v2_B.VectorConcatenate[5]) < 0.78539816339744828) || (fabs
         (drone_v2_B.VectorConcatenate[5]) > 2.3561944901923448)) {
      /* '<S5>:1:29' */
      /* '<S5>:1:30' */
      vz = atan((tan(drone_v2_B.VectorConcatenate[4]) * rtb_Derivative1_idx_1 -
                 b) * cos(drone_v2_B.VectorConcatenate[4]) /
                rtb_Derivative1_idx_0);
    } else {
      /* '<S5>:1:32' */
      vz = atan((rtb_Clock - tan(drone_v2_B.VectorConcatenate[4]) *
                 rtb_Derivative1_idx_0) * cos(drone_v2_B.VectorConcatenate[4]) /
                rtb_Derivative1_idx_1);
    }

    drone_v2_B.phid = vz;
    drone_v2_B.thetad = atan(rtb_Clock * rtb_Derivative1_idx_0 + b *
      rtb_Derivative1_idx_1);

    /* End of MATLAB Function: '<S1>/FeedBack Linearization' */
    if (rtmIsMajorTimeStep(drone_v2_M)) {
      /* Gain: '<S6>/Setpoint Weighting (Derivative)' */
      drone_v2_B.SetpointWeightingDerivative = drone_v2_P.PIDController2DOF_c *
        0.0;

      /* Sum: '<S6>/Sum2' */
      drone_v2_B.Sum2 = 0.0;
    }

    /* Gain: '<S6>/Filter Coefficient' incorporates:
     *  Gain: '<S6>/Derivative Gain'
     *  Integrator: '<S6>/Filter'
     *  Sum: '<S6>/Sum3'
     *  Sum: '<S6>/SumD'
     */
    drone_v2_B.FilterCoefficient = (drone_v2_P.PIDController2DOF_D *
      drone_v2_B.SetpointWeightingDerivative - drone_v2_X.Filter_CSTATE) *
      drone_v2_P.PIDController2DOF_N;

    /* Gain: '<S6>/Integral Gain' */
    drone_v2_B.IntegralGain = drone_v2_P.PIDController2DOF_I * drone_v2_B.Sum2;
    if (rtmIsMajorTimeStep(drone_v2_M)) {
      /* Gain: '<S6>/Setpoint Weighting (Proportional)' */
      drone_v2_B.SetpointWeightingProportional = drone_v2_P.PIDController2DOF_b *
        0.0;
    }

    /* Sum: '<S6>/Sum' incorporates:
     *  Gain: '<S6>/Proportional Gain'
     *  Integrator: '<S6>/Integrator'
     *  Sum: '<S6>/Sum1'
     */
    drone_v2_B.VectorConcatenate1[1] = (drone_v2_P.PIDController2DOF_P *
      drone_v2_B.SetpointWeightingProportional + drone_v2_X.Integrator_CSTATE) +
      drone_v2_B.FilterCoefficient;
    if (rtmIsMajorTimeStep(drone_v2_M)) {
      /* MATLAB Function: '<S4>/Omega Calcul' incorporates:
       *  Memory: '<S4>/Memory'
       */
      /* MATLAB Function 'Plant/Omega Calcul': '<S9>:1' */
      /* '<S9>:1:8' */
      /* '<S9>:1:9' */
      rtb_Clock = drone_v2_DW.Memory_PreviousInput[1] / 1.3016246400000001E-8;

      /* '<S9>:1:10' */
      b = drone_v2_DW.Memory_PreviousInput[2] / 1.3016246400000001E-8;

      /* '<S9>:1:11' */
      rtb_Derivative1_idx_1 = drone_v2_DW.Memory_PreviousInput[3] /
        2.6839000000000002E-9;

      /* '<S9>:1:13' */
      rtb_Derivative1_idx_0 = ((drone_v2_DW.Memory_PreviousInput[0] / 7.61184E-8
        + 2.0 * rtb_Clock) + rtb_Derivative1_idx_1) / 4.0;

      /* '<S9>:1:14' */
      rtb_Derivative1_idx_1 = (((2.0 * rtb_Derivative1_idx_0 +
        -rtb_Derivative1_idx_1) - rtb_Clock) + b) / 2.0;

      /* '<S9>:1:15' */
      /* '<S9>:1:16' */
      /* '<S9>:1:18' */
      vz = rtb_Derivative1_idx_1 - b;
      b = rtb_Derivative1_idx_0 - rtb_Clock;
      if (vz < 0.0) {
        /* '<S9>:1:19' */
        vz = 0.0;
      }

      if (b < 0.0) {
        /* '<S9>:1:19' */
        b = 0.0;
      }

      if (rtb_Derivative1_idx_1 < 0.0) {
        /* '<S9>:1:19' */
        rtb_Derivative1_idx_1 = 0.0;
      }

      if (rtb_Derivative1_idx_0 < 0.0) {
        /* '<S9>:1:19' */
        rtb_Derivative1_idx_0 = 0.0;
      }

      /* '<S9>:1:21' */
      rtb_Clock = sqrt(vz);
      vz = sqrt(b);
      rtb_Derivative1_idx_1 = sqrt(rtb_Derivative1_idx_1);
      rtb_Derivative1_idx_0 = sqrt(rtb_Derivative1_idx_0);
      if (rtb_Clock > 14800.0) {
        /* '<S9>:1:22' */
        rtb_Clock = 14800.0;
      }

      if (vz > 14800.0) {
        /* '<S9>:1:22' */
        vz = 14800.0;
      }

      if (rtb_Derivative1_idx_1 > 14800.0) {
        /* '<S9>:1:22' */
        rtb_Derivative1_idx_1 = 14800.0;
      }

      if (rtb_Derivative1_idx_0 > 14800.0) {
        /* '<S9>:1:22' */
        rtb_Derivative1_idx_0 = 14800.0;
      }

      /*  max vitesse rotation d'un moteur 1000 kV alimenté par lipo 4S */
      /* '<S9>:1:24' */
      drone_v2_B.Omega = ((-rtb_Clock + vz) - rtb_Derivative1_idx_1) +
        rtb_Derivative1_idx_0;

      /* '<S9>:1:25' */
      b = (rtb_Derivative1_idx_0 * rtb_Derivative1_idx_0 - vz * vz) *
        1.3016246400000001E-8;
      rtb_Memory_idx_2 = (rtb_Derivative1_idx_1 * rtb_Derivative1_idx_1 -
                          rtb_Clock * rtb_Clock) * 1.3016246400000001E-8;
      rtb_Memory_idx_3 = (((-(rtb_Clock * rtb_Clock) + vz * vz) -
                           rtb_Derivative1_idx_1 * rtb_Derivative1_idx_1) +
                          rtb_Derivative1_idx_0 * rtb_Derivative1_idx_0) *
        2.6839000000000002E-9;
      if (b < 0.0) {
        /* '<S9>:1:29' */
        b = 0.0;
      }

      drone_v2_B.u2 = b;
      b = rtb_Memory_idx_2;
      if (rtb_Memory_idx_2 < 0.0) {
        /* '<S9>:1:29' */
        b = 0.0;
      }

      drone_v2_B.u3 = b;
      b = rtb_Memory_idx_3;
      if (rtb_Memory_idx_3 < 0.0) {
        /* '<S9>:1:29' */
        b = 0.0;
      }

      /* '<S9>:1:30' */
      drone_v2_B.u1 = (((rtb_Clock * rtb_Clock + vz * vz) +
                        rtb_Derivative1_idx_1 * rtb_Derivative1_idx_1) +
                       rtb_Derivative1_idx_0 * rtb_Derivative1_idx_0) *
        7.61184E-8;

      /* '<S9>:1:31' */
      /* '<S9>:1:32' */
      /* '<S9>:1:33' */
      drone_v2_B.u4 = b;

      /* End of MATLAB Function: '<S4>/Omega Calcul' */
    }

    /* SignalConversion: '<S4>/ConcatBufferAtVector Concatenate1In3' */
    drone_v2_B.VectorConcatenate1[2] = 0.0;

    /* SignalConversion: '<S4>/ConcatBufferAtVector Concatenate1In4' */
    drone_v2_B.VectorConcatenate1[3] = 0.0;

    /* Integrator: '<S4>/Integrator' */
    drone_v2_B.Integrator = drone_v2_X.Integrator_CSTATE_c;

    /* Integrator: '<S4>/Integrator1' */
    drone_v2_B.Integrator1 = drone_v2_X.Integrator1_CSTATE;

    /* Integrator: '<S4>/Integrator2' */
    drone_v2_B.Integrator2 = drone_v2_X.Integrator2_CSTATE;

    /* Integrator: '<S4>/Integrator3' */
    drone_v2_B.Integrator3 = drone_v2_X.Integrator3_CSTATE;

    /* Integrator: '<S4>/Integrator4' */
    drone_v2_B.Integrator4 = drone_v2_X.Integrator4_CSTATE;

    /* Integrator: '<S4>/Integrator5' */
    drone_v2_B.Integrator5 = drone_v2_X.Integrator5_CSTATE;

    /* MATLAB Function: '<S4>/Model Equation' incorporates:
     *  Integrator: '<S4>/Integrator6'
     *  Integrator: '<S4>/Integrator7'
     *  Integrator: '<S4>/Integrator8'
     *  SignalConversion: '<S8>/TmpSignal ConversionAt SFunction Inport7'
     */
    /* MATLAB Function 'Plant/Model Equation': '<S8>:1' */
    /* '<S8>:1:6' */
    /* '<S8>:1:7' */
    /* '<S8>:1:8' */
    /* '<S8>:1:10' */
    /* '<S8>:1:11' */
    /* '<S8>:1:14' */
    drone_v2_B.ddx = (cos(drone_v2_X.Integrator8_CSTATE) * sin
                      (drone_v2_X.Integrator7_CSTATE) * cos
                      (drone_v2_X.Integrator6_CSTATE) + sin
                      (drone_v2_X.Integrator8_CSTATE) * sin
                      (drone_v2_X.Integrator6_CSTATE)) * drone_v2_B.u1 / 0.698;

    /* '<S8>:1:15' */
    drone_v2_B.ddy = (cos(drone_v2_X.Integrator8_CSTATE) * sin
                      (drone_v2_X.Integrator7_CSTATE) * sin
                      (drone_v2_X.Integrator6_CSTATE) - sin
                      (drone_v2_X.Integrator8_CSTATE) * cos
                      (drone_v2_X.Integrator6_CSTATE)) * drone_v2_B.u1 / 0.698;

    /* '<S8>:1:16' */
    drone_v2_B.ddz = cos(drone_v2_X.Integrator8_CSTATE) * cos
      (drone_v2_X.Integrator7_CSTATE) * drone_v2_B.u1 / 0.698 + -9.81;

    /* '<S8>:1:18' */
    drone_v2_B.ddphi = (drone_v2_B.Integrator3 * drone_v2_B.Integrator5 *
                        -0.76470588235294135 - 1.302E-5 * drone_v2_B.Integrator4
                        * drone_v2_B.Omega / 0.0034) + 0.171 * drone_v2_B.u2 /
      0.0034;

    /* '<S8>:1:19' */
    drone_v2_B.ddtheta = (1.302E-5 * drone_v2_B.Integrator4 * drone_v2_B.Omega /
                          0.0034 + drone_v2_B.Integrator3 *
                          drone_v2_B.Integrator5 * 0.76470588235294135) + 0.171 *
      drone_v2_B.u3 / 0.0034;

    /* '<S8>:1:20' */
    drone_v2_B.ddpsi = drone_v2_B.Integrator4 * drone_v2_B.Integrator3 * 0.0 +
      drone_v2_B.u4 / 0.006;
  }

  if (rtmIsMajorTimeStep(drone_v2_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(drone_v2_M->rtwLogInfo, (drone_v2_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(drone_v2_M)) {
    real_T (*lastU)[6];
    real_T (*lastU_0)[3];
    int32_T i;

    /* Update for Derivative: '<S1>/Derivative' */
    if (drone_v2_DW.TimeStampA == (rtInf)) {
      drone_v2_DW.TimeStampA = drone_v2_M->Timing.t[0];
      lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeA;
    } else if (drone_v2_DW.TimeStampB == (rtInf)) {
      drone_v2_DW.TimeStampB = drone_v2_M->Timing.t[0];
      lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeB;
    } else if (drone_v2_DW.TimeStampA < drone_v2_DW.TimeStampB) {
      drone_v2_DW.TimeStampA = drone_v2_M->Timing.t[0];
      lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeA;
    } else {
      drone_v2_DW.TimeStampB = drone_v2_M->Timing.t[0];
      lastU = (real_T (*)[6])drone_v2_DW.LastUAtTimeB;
    }

    for (i = 0; i < 6; i++) {
      (*lastU)[i] = drone_v2_B.VectorConcatenate[i];
    }

    /* End of Update for Derivative: '<S1>/Derivative' */

    /* Update for Derivative: '<S1>/Derivative1' */
    if (drone_v2_DW.TimeStampA_a == (rtInf)) {
      drone_v2_DW.TimeStampA_a = drone_v2_M->Timing.t[0];
      lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeA_c;
    } else if (drone_v2_DW.TimeStampB_p == (rtInf)) {
      drone_v2_DW.TimeStampB_p = drone_v2_M->Timing.t[0];
      lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeB_i;
    } else if (drone_v2_DW.TimeStampA_a < drone_v2_DW.TimeStampB_p) {
      drone_v2_DW.TimeStampA_a = drone_v2_M->Timing.t[0];
      lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeA_c;
    } else {
      drone_v2_DW.TimeStampB_p = drone_v2_M->Timing.t[0];
      lastU_0 = (real_T (*)[3])drone_v2_DW.LastUAtTimeB_i;
    }

    (*lastU_0)[0] = drone_v2_B.Xd[0];
    (*lastU_0)[1] = drone_v2_B.Xd[1];
    (*lastU_0)[2] = drone_v2_B.Xd[2];

    /* End of Update for Derivative: '<S1>/Derivative1' */
    if (rtmIsMajorTimeStep(drone_v2_M)) {
      /* Update for Memory: '<S4>/Memory' */
      drone_v2_DW.Memory_PreviousInput[0] = drone_v2_B.VectorConcatenate1[0];
      drone_v2_DW.Memory_PreviousInput[1] = drone_v2_B.VectorConcatenate1[1];
      drone_v2_DW.Memory_PreviousInput[2] = drone_v2_B.VectorConcatenate1[2];
      drone_v2_DW.Memory_PreviousInput[3] = drone_v2_B.VectorConcatenate1[3];
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(drone_v2_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(drone_v2_M)!=-1) &&
          !((rtmGetTFinal(drone_v2_M)-(((drone_v2_M->Timing.clockTick1+
               drone_v2_M->Timing.clockTickH1* 4294967296.0)) * 0.001)) >
            (((drone_v2_M->Timing.clockTick1+drone_v2_M->Timing.clockTickH1*
               4294967296.0)) * 0.001) * (DBL_EPSILON))) {
        rtmSetErrorStatus(drone_v2_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&drone_v2_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++drone_v2_M->Timing.clockTick0)) {
      ++drone_v2_M->Timing.clockTickH0;
    }

    drone_v2_M->Timing.t[0] = rtsiGetSolverStopTime(&drone_v2_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.001s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.001, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      drone_v2_M->Timing.clockTick1++;
      if (!drone_v2_M->Timing.clockTick1) {
        drone_v2_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void drone_v2_derivatives(void)
{
  XDot_drone_v2_T *_rtXdot;
  _rtXdot = ((XDot_drone_v2_T *) drone_v2_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator11' */
  _rtXdot->Integrator11_CSTATE = drone_v2_B.Integrator;

  /* Derivatives for Integrator: '<S4>/Integrator10' */
  _rtXdot->Integrator10_CSTATE = drone_v2_B.Integrator1;

  /* Derivatives for Integrator: '<S4>/Integrator9' */
  _rtXdot->Integrator9_CSTATE = drone_v2_B.Integrator2;

  /* Derivatives for Integrator: '<S4>/Integrator8' */
  _rtXdot->Integrator8_CSTATE = drone_v2_B.Integrator3;

  /* Derivatives for Integrator: '<S4>/Integrator7' */
  _rtXdot->Integrator7_CSTATE = drone_v2_B.Integrator4;

  /* Derivatives for Integrator: '<S4>/Integrator6' */
  _rtXdot->Integrator6_CSTATE = drone_v2_B.Integrator5;

  /* Derivatives for Integrator: '<S6>/Filter' */
  _rtXdot->Filter_CSTATE = drone_v2_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = drone_v2_B.IntegralGain;

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE_c = drone_v2_B.ddx;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = drone_v2_B.ddy;

  /* Derivatives for Integrator: '<S4>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = drone_v2_B.ddz;

  /* Derivatives for Integrator: '<S4>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = drone_v2_B.ddphi;

  /* Derivatives for Integrator: '<S4>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = drone_v2_B.ddtheta;

  /* Derivatives for Integrator: '<S4>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = drone_v2_B.ddpsi;
}

/* Model initialize function */
void drone_v2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)drone_v2_M, 0,
                sizeof(RT_MODEL_drone_v2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&drone_v2_M->solverInfo,
                          &drone_v2_M->Timing.simTimeStep);
    rtsiSetTPtr(&drone_v2_M->solverInfo, &rtmGetTPtr(drone_v2_M));
    rtsiSetStepSizePtr(&drone_v2_M->solverInfo, &drone_v2_M->Timing.stepSize0);
    rtsiSetdXPtr(&drone_v2_M->solverInfo, &drone_v2_M->derivs);
    rtsiSetContStatesPtr(&drone_v2_M->solverInfo, (real_T **)
                         &drone_v2_M->contStates);
    rtsiSetNumContStatesPtr(&drone_v2_M->solverInfo,
      &drone_v2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&drone_v2_M->solverInfo,
      &drone_v2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&drone_v2_M->solverInfo,
      &drone_v2_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&drone_v2_M->solverInfo,
      &drone_v2_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&drone_v2_M->solverInfo, (&rtmGetErrorStatus
      (drone_v2_M)));
    rtsiSetRTModelPtr(&drone_v2_M->solverInfo, drone_v2_M);
  }

  rtsiSetSimTimeStep(&drone_v2_M->solverInfo, MAJOR_TIME_STEP);
  drone_v2_M->intgData.y = drone_v2_M->odeY;
  drone_v2_M->intgData.f[0] = drone_v2_M->odeF[0];
  drone_v2_M->intgData.f[1] = drone_v2_M->odeF[1];
  drone_v2_M->intgData.f[2] = drone_v2_M->odeF[2];
  drone_v2_M->contStates = ((X_drone_v2_T *) &drone_v2_X);
  rtsiSetSolverData(&drone_v2_M->solverInfo, (void *)&drone_v2_M->intgData);
  rtsiSetSolverName(&drone_v2_M->solverInfo,"ode3");
  rtmSetTPtr(drone_v2_M, &drone_v2_M->Timing.tArray[0]);
  rtmSetTFinal(drone_v2_M, 30.0);
  drone_v2_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    drone_v2_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(drone_v2_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(drone_v2_M->rtwLogInfo, (NULL));
    rtliSetLogT(drone_v2_M->rtwLogInfo, "tout");
    rtliSetLogX(drone_v2_M->rtwLogInfo, "");
    rtliSetLogXFinal(drone_v2_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(drone_v2_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(drone_v2_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(drone_v2_M->rtwLogInfo, 0);
    rtliSetLogDecimation(drone_v2_M->rtwLogInfo, 1);
    rtliSetLogY(drone_v2_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(drone_v2_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(drone_v2_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &drone_v2_B), 0,
                sizeof(B_drone_v2_T));

  /* states (continuous) */
  {
    (void) memset((void *)&drone_v2_X, 0,
                  sizeof(X_drone_v2_T));
  }

  /* states (dwork) */
  (void) memset((void *)&drone_v2_DW, 0,
                sizeof(DW_drone_v2_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(drone_v2_M->rtwLogInfo, 0.0, rtmGetTFinal
    (drone_v2_M), drone_v2_M->Timing.stepSize0, (&rtmGetErrorStatus(drone_v2_M)));

  /* InitializeConditions for Integrator: '<S4>/Integrator11' */
  drone_v2_X.Integrator11_CSTATE = drone_v2_P.Integrator11_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator10' */
  drone_v2_X.Integrator10_CSTATE = drone_v2_P.Integrator10_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator9' */
  drone_v2_X.Integrator9_CSTATE = drone_v2_P.Integrator9_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator8' */
  drone_v2_X.Integrator8_CSTATE = drone_v2_P.Integrator8_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator7' */
  drone_v2_X.Integrator7_CSTATE = drone_v2_P.Integrator7_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator6' */
  drone_v2_X.Integrator6_CSTATE = drone_v2_P.Integrator6_IC;

  /* InitializeConditions for Derivative: '<S1>/Derivative' */
  drone_v2_DW.TimeStampA = (rtInf);
  drone_v2_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Derivative: '<S1>/Derivative1' */
  drone_v2_DW.TimeStampA_a = (rtInf);
  drone_v2_DW.TimeStampB_p = (rtInf);

  /* InitializeConditions for Integrator: '<S6>/Filter' */
  drone_v2_X.Filter_CSTATE = drone_v2_P.Filter_IC;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  drone_v2_X.Integrator_CSTATE = drone_v2_P.Integrator_IC;

  /* InitializeConditions for Memory: '<S4>/Memory' */
  drone_v2_DW.Memory_PreviousInput[0] = drone_v2_P.Memory_X0;
  drone_v2_DW.Memory_PreviousInput[1] = drone_v2_P.Memory_X0;
  drone_v2_DW.Memory_PreviousInput[2] = drone_v2_P.Memory_X0;
  drone_v2_DW.Memory_PreviousInput[3] = drone_v2_P.Memory_X0;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  drone_v2_X.Integrator_CSTATE_c = drone_v2_P.Integrator_IC_f;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  drone_v2_X.Integrator1_CSTATE = drone_v2_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator2' */
  drone_v2_X.Integrator2_CSTATE = drone_v2_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator3' */
  drone_v2_X.Integrator3_CSTATE = drone_v2_P.Integrator3_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator4' */
  drone_v2_X.Integrator4_CSTATE = drone_v2_P.Integrator4_IC;

  /* InitializeConditions for Integrator: '<S4>/Integrator5' */
  drone_v2_X.Integrator5_CSTATE = drone_v2_P.Integrator5_IC;
}

/* Model terminate function */
void drone_v2_terminate(void)
{
  /* (no terminate code required) */
}
