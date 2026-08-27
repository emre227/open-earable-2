/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_filter_private.h
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

#ifndef echo_filter_private_h_
#define echo_filter_private_h_
#include "rtwtypes.h"
#include "echo_filter_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_BKrb1W4mJJua;

#define rtCP_gain_left_Gain            rtCP_pooled_BKrb1W4mJJua  /* Computed Parameter: rtCP_gain_left_Gain
                                                                  * Referenced by: '<Root>/gain_left'
                                                                  */
#define rtCP_gain_right_Gain           rtCP_pooled_BKrb1W4mJJua  /* Computed Parameter: rtCP_gain_right_Gain
                                                                  * Referenced by: '<Root>/gain_right'
                                                                  */
#endif                                 /* echo_filter_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
