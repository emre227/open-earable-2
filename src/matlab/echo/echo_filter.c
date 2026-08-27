/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_filter.c
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

#include "echo_filter.h"
#include "rtwtypes.h"
#include "mw_cmsis.h"
#include <math.h>
#include "echo_filter_private.h"
#include <string.h>

/* System initialize for referenced model: 'echo_filter' */
void echo_filter_Init(DW_echo_filter_f_T *localDW)
{
  /* InitializeConditions for Delay: '<Root>/delay_left' */
  localDW->CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<Root>/delay_right' */
  localDW->CircBufIdx_k = 0U;
}

/* Output and update for referenced model: 'echo_filter' */
void echo_filter(const int16_T rtu_left_in[48], const int16_T rtu_right_in[48],
                 int16_T rty_left_out[48], int16_T rty_right_out[48],
                 DW_echo_filter_f_T *localDW)
{
  int32_T i;
  real32_T rtb_add_right[48];
  real32_T rtb_delay_right[48];
  real32_T rtb_gain_left[48];
  real32_T rtb_gain_right[48];
  real32_T tmp;
  uint32_T currIdx;

  /* Delay: '<Root>/delay_left' incorporates:
   *  Sum: '<Root>/add_right'
   */
  currIdx = localDW->CircBufIdx;
  for (i = 0; i < 48; i++) {
    rtb_add_right[i] = localDW->delay_left_DSTATE[currIdx];
    currIdx++;
    if (currIdx >= 4000U) {
      currIdx = 0U;
    }

    /* Sum: '<Root>/add_left' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion'
     *  Sum: '<Root>/add_right'
     */
    rtb_gain_right[i] = rtu_left_in[i];
  }

  /* End of Delay: '<Root>/delay_left' */

  /* Sum: '<Root>/add_left' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Delay: '<Root>/delay_right'
   *  Sum: '<Root>/add_right'
   */
  mw_arm_add_f32(&rtb_gain_right[0], &rtb_add_right[0], &rtb_delay_right[0], 48U);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Delay: '<Root>/delay_right'
   */
  for (i = 0; i < 48; i++) {
    tmp = floorf(rtb_delay_right[i]);
    if (tmp < 32768.0F) {
      if (tmp >= -32768.0F) {
        rty_left_out[i] = (int16_T)tmp;
      } else {
        rty_left_out[i] = MIN_int16_T;
      }
    } else {
      rty_left_out[i] = MAX_int16_T;
    }
  }

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* Gain: '<Root>/gain_left' incorporates:
   *  Delay: '<Root>/delay_right'
   */
  mw_arm_scale_1_f32((real32_T *)&rtCP_gain_left_Gain, &rtb_delay_right[0],
                     &rtb_gain_left[0], 48U);

  /* Delay: '<Root>/delay_right' */
  currIdx = localDW->CircBufIdx_k;
  for (i = 0; i < 48; i++) {
    rtb_delay_right[i] = localDW->delay_right_DSTATE[currIdx];
    currIdx++;
    if (currIdx >= 4000U) {
      currIdx = 0U;
    }

    /* Sum: '<Root>/add_right' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion1'
     *  Delay: '<Root>/delay_right'
     */
    rtb_gain_right[i] = rtu_right_in[i];
  }

  /* End of Delay: '<Root>/delay_right' */

  /* Sum: '<Root>/add_right' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  Delay: '<Root>/delay_right'
   */
  mw_arm_add_f32(&rtb_gain_right[0], &rtb_delay_right[0], &rtb_add_right[0], 48U);

  /* Update for Delay: '<Root>/delay_left' */
  currIdx = localDW->CircBufIdx;
  for (i = 0; i < 48; i++) {
    /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
     *  Sum: '<Root>/add_right'
     */
    tmp = floorf(rtb_add_right[i]);
    if (tmp < 32768.0F) {
      if (tmp >= -32768.0F) {
        rty_right_out[i] = (int16_T)tmp;
      } else {
        rty_right_out[i] = MIN_int16_T;
      }
    } else {
      rty_right_out[i] = MAX_int16_T;
    }

    /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

    /* Update for Delay: '<Root>/delay_left' incorporates:
     *  Gain: '<Root>/gain_left'
     */
    localDW->delay_left_DSTATE[currIdx] = rtb_gain_left[i];
    currIdx++;
    if (currIdx >= 4000U) {
      currIdx = 0U;
    }
  }

  /* Gain: '<Root>/gain_right' incorporates:
   *  Sum: '<Root>/add_right'
   */
  mw_arm_scale_1_f32((real32_T *)&rtCP_gain_right_Gain, &rtb_add_right[0],
                     &rtb_gain_right[0], 48U);

  /* Update for Delay: '<Root>/delay_left' */
  if (localDW->CircBufIdx < 3952U) {
    localDW->CircBufIdx += 48U;
  } else {
    localDW->CircBufIdx -= 3952U;
  }

  /* Update for Delay: '<Root>/delay_right' incorporates:
   *  Gain: '<Root>/gain_right'
   */
  currIdx = localDW->CircBufIdx_k;
  for (i = 0; i < 48; i++) {
    localDW->delay_right_DSTATE[currIdx] = rtb_gain_right[i];
    currIdx++;
    if (currIdx >= 4000U) {
      currIdx = 0U;
    }
  }

  if (localDW->CircBufIdx_k < 3952U) {
    localDW->CircBufIdx_k += 48U;
  } else {
    localDW->CircBufIdx_k -= 3952U;
  }

  /* End of Update for Delay: '<Root>/delay_right' */
}

/* Model initialize function */
void echo_filter_initialize(const char_T **rt_errorStatus,
  RT_MODEL_echo_filter_T *const echo_filter_M, DW_echo_filter_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(echo_filter_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_echo_filter_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
