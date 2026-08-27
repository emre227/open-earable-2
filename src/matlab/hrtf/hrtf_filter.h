/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: hrtf_filter.h
 *
 * Code generated for Simulink model 'hrtf_filter'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Jul  1 16:55:49 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef hrtf_filter_h_
#define hrtf_filter_h_
#ifndef hrtf_filter_COMMON_INCLUDES_
#define hrtf_filter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* hrtf_filter_COMMON_INCLUDES_ */

#include "hrtf_filter_types.h"
#include "mw_arm_fir.h"
#include <string.h>
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  arm_fir_instance_f32 S;              /* synthesized block */
  arm_fir_instance_f32 S_l;            /* synthesized block */
  arm_fir_instance_f32 S_li;           /* synthesized block */
  arm_fir_instance_f32 S_lid;          /* synthesized block */
  real32_T pState[247];                /* synthesized block */
  real32_T qCoeff[200];                /* synthesized block */
  real32_T pState_l[247];              /* synthesized block */
  real32_T qCoeff_m[200];              /* synthesized block */
  real32_T pState_lz[247];             /* synthesized block */
  real32_T qCoeff_c[200];              /* synthesized block */
  real32_T pState_lz5[247];            /* synthesized block */
  real32_T qCoeff_k[200];              /* synthesized block */
} DW_hrtf_filter_T;

/* Real-time Model Data Structure */
struct tag_RTM_hrtf_filter_T {
  const char_T * volatile errorStatus;
  DW_hrtf_filter_T *dwork;
};

/* Model entry point functions */
extern void hrtf_filter_initialize(RT_MODEL_hrtf_filter_T *const hrtf_filter_M,
  int16_T hrtf_filter_U_left_in[48], int16_T hrtf_filter_U_right_in[48], int16_T
  hrtf_filter_Y_left_out[48], int16_T hrtf_filter_Y_right_out[48]);
extern void hrtf_filter_step(RT_MODEL_hrtf_filter_T *const hrtf_filter_M,
  int16_T hrtf_filter_U_left_in[48], int16_T hrtf_filter_U_right_in[48], int16_T
  hrtf_filter_Y_left_out[48], int16_T hrtf_filter_Y_right_out[48]);
extern void hrtf_filter_terminate(RT_MODEL_hrtf_filter_T *const hrtf_filter_M);

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
 * '<Root>' : 'hrtf_filter'
 */
#endif                                 /* hrtf_filter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
