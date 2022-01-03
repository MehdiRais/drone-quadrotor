/*
 * drone_v2.h
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

#ifndef RTW_HEADER_drone_v2_h_
#define RTW_HEADER_drone_v2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef drone_v2_COMMON_INCLUDES_
# define drone_v2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* drone_v2_COMMON_INCLUDES_ */

#include "drone_v2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T VectorConcatenate[6];         /* '<S4>/Vector Concatenate' */
  real_T SetpointWeightingDerivative;  /* '<S6>/Setpoint Weighting (Derivative)' */
  real_T FilterCoefficient;            /* '<S6>/Filter Coefficient' */
  real_T Sum2;                         /* '<S6>/Sum2' */
  real_T IntegralGain;                 /* '<S6>/Integral Gain' */
  real_T SetpointWeightingProportional;/* '<S6>/Setpoint Weighting (Proportional)' */
  real_T Integrator;                   /* '<S4>/Integrator' */
  real_T Integrator1;                  /* '<S4>/Integrator1' */
  real_T Integrator2;                  /* '<S4>/Integrator2' */
  real_T Integrator3;                  /* '<S4>/Integrator3' */
  real_T Integrator4;                  /* '<S4>/Integrator4' */
  real_T Integrator5;                  /* '<S4>/Integrator5' */
  real_T VectorConcatenate1[4];        /* '<S4>/Vector Concatenate1' */
  real_T Omega;                        /* '<S4>/Omega Calcul' */
  real_T u1;                           /* '<S4>/Omega Calcul' */
  real_T u2;                           /* '<S4>/Omega Calcul' */
  real_T u3;                           /* '<S4>/Omega Calcul' */
  real_T u4;                           /* '<S4>/Omega Calcul' */
  real_T ddx;                          /* '<S4>/Model Equation' */
  real_T ddy;                          /* '<S4>/Model Equation' */
  real_T ddz;                          /* '<S4>/Model Equation' */
  real_T ddphi;                        /* '<S4>/Model Equation' */
  real_T ddtheta;                      /* '<S4>/Model Equation' */
  real_T ddpsi;                        /* '<S4>/Model Equation' */
  real_T Xd[3];                        /* '<S3>/Planner' */
  real_T phid;                         /* '<S1>/FeedBack Linearization' */
  real_T thetad;                       /* '<S1>/FeedBack Linearization' */
} B_drone_v2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T TimeStampA;                   /* '<S1>/Derivative' */
  real_T LastUAtTimeA[6];              /* '<S1>/Derivative' */
  real_T TimeStampB;                   /* '<S1>/Derivative' */
  real_T LastUAtTimeB[6];              /* '<S1>/Derivative' */
  real_T TimeStampA_a;                 /* '<S1>/Derivative1' */
  real_T LastUAtTimeA_c[3];            /* '<S1>/Derivative1' */
  real_T TimeStampB_p;                 /* '<S1>/Derivative1' */
  real_T LastUAtTimeB_i[3];            /* '<S1>/Derivative1' */
  real_T Memory_PreviousInput[4];      /* '<S4>/Memory' */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[4];
  } Scope_PWORK_c;                     /* '<S4>/Scope' */
} DW_drone_v2_T;

/* Continuous states (auto storage) */
typedef struct {
  real_T Integrator11_CSTATE;          /* '<S4>/Integrator11' */
  real_T Integrator10_CSTATE;          /* '<S4>/Integrator10' */
  real_T Integrator9_CSTATE;           /* '<S4>/Integrator9' */
  real_T Integrator8_CSTATE;           /* '<S4>/Integrator8' */
  real_T Integrator7_CSTATE;           /* '<S4>/Integrator7' */
  real_T Integrator6_CSTATE;           /* '<S4>/Integrator6' */
  real_T Filter_CSTATE;                /* '<S6>/Filter' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S4>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S4>/Integrator5' */
} X_drone_v2_T;

/* State derivatives (auto storage) */
typedef struct {
  real_T Integrator11_CSTATE;          /* '<S4>/Integrator11' */
  real_T Integrator10_CSTATE;          /* '<S4>/Integrator10' */
  real_T Integrator9_CSTATE;           /* '<S4>/Integrator9' */
  real_T Integrator8_CSTATE;           /* '<S4>/Integrator8' */
  real_T Integrator7_CSTATE;           /* '<S4>/Integrator7' */
  real_T Integrator6_CSTATE;           /* '<S4>/Integrator6' */
  real_T Filter_CSTATE;                /* '<S6>/Filter' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator_CSTATE_c;          /* '<S4>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T Integrator3_CSTATE;           /* '<S4>/Integrator3' */
  real_T Integrator4_CSTATE;           /* '<S4>/Integrator4' */
  real_T Integrator5_CSTATE;           /* '<S4>/Integrator5' */
} XDot_drone_v2_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator11_CSTATE;       /* '<S4>/Integrator11' */
  boolean_T Integrator10_CSTATE;       /* '<S4>/Integrator10' */
  boolean_T Integrator9_CSTATE;        /* '<S4>/Integrator9' */
  boolean_T Integrator8_CSTATE;        /* '<S4>/Integrator8' */
  boolean_T Integrator7_CSTATE;        /* '<S4>/Integrator7' */
  boolean_T Integrator6_CSTATE;        /* '<S4>/Integrator6' */
  boolean_T Filter_CSTATE;             /* '<S6>/Filter' */
  boolean_T Integrator_CSTATE;         /* '<S6>/Integrator' */
  boolean_T Integrator_CSTATE_c;       /* '<S4>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator2_CSTATE;        /* '<S4>/Integrator2' */
  boolean_T Integrator3_CSTATE;        /* '<S4>/Integrator3' */
  boolean_T Integrator4_CSTATE;        /* '<S4>/Integrator4' */
  boolean_T Integrator5_CSTATE;        /* '<S4>/Integrator5' */
} XDis_drone_v2_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (auto storage) */
struct P_drone_v2_T_ {
  real_T PIDController2DOF_D;          /* Mask Parameter: PIDController2DOF_D
                                        * Referenced by: '<S6>/Derivative Gain'
                                        */
  real_T PIDController2DOF_I;          /* Mask Parameter: PIDController2DOF_I
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  real_T PIDController2DOF_N;          /* Mask Parameter: PIDController2DOF_N
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  real_T PIDController2DOF_P;          /* Mask Parameter: PIDController2DOF_P
                                        * Referenced by: '<S6>/Proportional Gain'
                                        */
  real_T PIDController2DOF_b;          /* Mask Parameter: PIDController2DOF_b
                                        * Referenced by: '<S6>/Setpoint Weighting (Proportional)'
                                        */
  real_T PIDController2DOF_c;          /* Mask Parameter: PIDController2DOF_c
                                        * Referenced by: '<S6>/Setpoint Weighting (Derivative)'
                                        */
  real_T Integrator11_IC;              /* Expression: 0
                                        * Referenced by: '<S4>/Integrator11'
                                        */
  real_T Integrator10_IC;              /* Expression: 0
                                        * Referenced by: '<S4>/Integrator10'
                                        */
  real_T Integrator9_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator9'
                                        */
  real_T Integrator8_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator8'
                                        */
  real_T Integrator7_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator7'
                                        */
  real_T Integrator6_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator6'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S6>/Filter'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T Integrator_IC_f;              /* Expression: 0
                                        * Referenced by: '<S4>/Integrator'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator3'
                                        */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator4'
                                        */
  real_T Integrator5_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator5'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_drone_v2_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  RTWSolverInfo solverInfo;
  X_drone_v2_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  real_T odeY[14];
  real_T odeF[3][14];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_drone_v2_T drone_v2_P;

/* Block signals (auto storage) */
extern B_drone_v2_T drone_v2_B;

/* Continuous states (auto storage) */
extern X_drone_v2_T drone_v2_X;

/* Block states (auto storage) */
extern DW_drone_v2_T drone_v2_DW;

/* Model entry point functions */
extern void drone_v2_initialize(void);
extern void drone_v2_step(void);
extern void drone_v2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_drone_v2_T *const drone_v2_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'drone_v2'
 * '<S1>'   : 'drone_v2/Feedback Linearization'
 * '<S2>'   : 'drone_v2/PIDs'
 * '<S3>'   : 'drone_v2/Planner'
 * '<S4>'   : 'drone_v2/Plant'
 * '<S5>'   : 'drone_v2/Feedback Linearization/FeedBack Linearization'
 * '<S6>'   : 'drone_v2/PIDs/PID Controller (2DOF)'
 * '<S7>'   : 'drone_v2/Planner/Planner'
 * '<S8>'   : 'drone_v2/Plant/Model Equation'
 * '<S9>'   : 'drone_v2/Plant/Omega Calcul'
 */
#endif                                 /* RTW_HEADER_drone_v2_h_ */
