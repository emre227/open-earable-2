/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_filter.h
 *
 * Code generated for Simulink model 'echo_filter'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Thu Jul  2 13:13:38 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef echo_filter_h_
#define echo_filter_h_
#ifndef echo_filter_COMMON_INCLUDES_
#define echo_filter_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* echo_filter_COMMON_INCLUDES_ */

#include "echo_filter_types.h"
#include <string.h>

/* Block states (default storage) for model 'echo_filter' */
typedef struct {
  real32_T delay_left_DSTATE[4000];    /* '<Root>/delay_left' */
  real32_T delay_right_DSTATE[4000];   /* '<Root>/delay_right' */
  uint32_T CircBufIdx;                 /* '<Root>/delay_left' */
  uint32_T CircBufIdx_k;               /* '<Root>/delay_right' */
} DW_echo_filter_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_echo_filter_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_echo_filter_f_T rtdw;
  RT_MODEL_echo_filter_T rtm;
} MdlrefDW_echo_filter_T;

/* Model reference registration function */
extern void echo_filter_initialize(const char_T **rt_errorStatus,
  RT_MODEL_echo_filter_T *const echo_filter_M, DW_echo_filter_f_T *localDW);
extern void echo_filter_Init(DW_echo_filter_f_T *localDW);
extern void echo_filter(const int16_T rtu_left_in[48], const int16_T
  rtu_right_in[48], int16_T rty_left_out[48], int16_T rty_right_out[48],
  DW_echo_filter_f_T *localDW);

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
 * '<Root>' : 'echo_filter'
 */
#endif                                 /* echo_filter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
