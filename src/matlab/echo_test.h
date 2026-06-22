/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: echo_test.h
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

#ifndef echo_test_h_
#define echo_test_h_
#ifndef echo_test_COMMON_INCLUDES_
#define echo_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* echo_test_COMMON_INCLUDES_ */

#include "echo_test_types.h"
#include <string.h>

/* Block states (default storage) for model 'echo_test' */
typedef struct {
  uint32_T CircBufIdx;                 /* '<Root>/Delay' */
  int16_T Delay_DSTATE[8000];          /* '<Root>/Delay' */
} DW_echo_test_f_T;

/* Real-time Model Data Structure */
struct tag_RTM_echo_test_T {
  const char_T **errorStatus;
};

typedef struct {
  DW_echo_test_f_T rtdw;
  RT_MODEL_echo_test_T rtm;
} MdlrefDW_echo_test_T;

/* Model reference registration function */
extern void echo_test_initialize(const char_T **rt_errorStatus,
  RT_MODEL_echo_test_T *const echo_test_M, DW_echo_test_f_T *localDW);
extern void echo_test_Init(DW_echo_test_f_T *localDW);
extern void echo_test(const int16_T *rtu_data, int16_T *rty_Out1,
                      DW_echo_test_f_T *localDW);

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
 * '<Root>' : 'echo_test'
 */
#endif                                 /* echo_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
