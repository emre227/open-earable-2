/*
Copyright 2023 The MathWorks, Inc.
*/
/* mw_arm_fir.h

    This file contains utility functions which might be used with arm_cortex-m cmsis library.
*/
#ifndef __MW_ARM_FIR_H__
#define __MW_ARM_FIR_H__

#include "arm_math.h"
#include <stdint.h>

void mw_arm_fir_f32(arm_fir_instance_f32 *S, float32_t *pSrc,
		float32_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps, float32_t *pState);
void mw_arm_fir_init_f32(arm_fir_instance_f32 *S, uint16_t numTaps, 
		float32_t *qCoeff, float32_t *pState, uint32_t blockSize, uint32_t numChannels);


void mw_arm_fir_lattice_init_f32(arm_fir_lattice_instance_f32 *S, uint16_t numStages,
		float32_t *qCoeff, float32_t *pState, uint32_t blockSize, uint32_t numChannels);
void mw_arm_fir_lattice_f32(arm_fir_lattice_instance_f32 *S, float32_t *pSrc,
		float32_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numStages, float32_t *pState);


void mw_arm_fir_q15(arm_fir_instance_q15 *S, q15_t *pSrc,
		q15_t *pDst, uint32_t blockSize, uint32_t numChannels,uint16_t numTaps, q15_t *pState);
void mw_arm_fir_init_q15(arm_fir_instance_q15 *S, uint16_t numTaps,
		q15_t *qCoeff, q15_t *pState, uint32_t blockSize, uint32_t numChannels);


void mw_arm_fir_q7(arm_fir_instance_q7 *S, q7_t *pSrc,
		q7_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps, q7_t *pState);
void mw_arm_fir_init_q7(arm_fir_instance_q7 *S, uint16_t numTaps,
		q7_t *qCoeff, q7_t *pState, uint32_t blockSize, uint32_t numChannels);

void mw_arm_fir_q31(arm_fir_instance_q31 *S, q31_t *pSrc,
		q31_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps,q31_t *pState);
void mw_arm_fir_init_q31(arm_fir_instance_q31 *S, uint16_t numTaps,
		q31_t *qCoeff, q31_t *pState, uint32_t blockSize, uint32_t numChannels);

#endif