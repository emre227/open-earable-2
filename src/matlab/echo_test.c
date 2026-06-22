/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_test.c
 *
 * Code generated for Simulink model 'echo_test'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Wed Jun 17 14:22:28 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "echo_test.h"
#include "rtwtypes.h"
#include "echo_test_private.h"
#include <string.h>

/* System initialize for referenced model: 'echo_test' */
void echo_test_Init(DW_echo_test_f_T *localDW)
{
  /* InitializeConditions for Delay: '<Root>/Delay' */
  localDW->CircBufIdx = 0U;
}

/* Output and update for referenced model: 'echo_test' */
void echo_test(const int16_T *rtu_data, int16_T *rty_Out1, DW_echo_test_f_T
               *localDW)
{
  int32_T tmp;

  /* Sum: '<Root>/Add' incorporates:
   *  Delay: '<Root>/Delay'
   */
  tmp = *rtu_data + localDW->Delay_DSTATE[localDW->CircBufIdx];
  if (tmp > 32767) {
    tmp = 32767;
  } else if (tmp < -32768) {
    tmp = -32768;
  }

  *rty_Out1 = (int16_T)tmp;

  /* End of Sum: '<Root>/Add' */

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Gain: '<Root>/Gain'
   */
  localDW->Delay_DSTATE[localDW->CircBufIdx] = (int16_T)(*rty_Out1 >> 2);
  if (localDW->CircBufIdx < 7999U) {
    localDW->CircBufIdx++;
  } else {
    localDW->CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<Root>/Delay' */
}

/* Model initialize function */
void echo_test_initialize(const char_T **rt_errorStatus, RT_MODEL_echo_test_T *
  const echo_test_M, DW_echo_test_f_T *localDW)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(echo_test_M, rt_errorStatus);

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_echo_test_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
