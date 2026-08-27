/* 
Copyright 2023 The MathWorks, Inc. 
*/
/* mw_arm_fir.c

   This file contains utility functions which might be used with arm_cortex-m cmsis library.
*/
#include "mw_arm_fir.h"

/*Discrete FIR Filter - Direct Form structure with single data type input*/
void mw_arm_fir_f32(arm_fir_instance_f32 *S, float32_t *pSrc,
        float32_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps, float32_t *pState){

    uint32_t channelIndex;
    float32_t *pIn, *pOut;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        pIn = pSrc + (channelIndex * blockSize);
        pOut = pDst + (channelIndex * blockSize);
        S->pState = pState + (channelIndex * (blockSize + numTaps - 1));
        arm_fir_f32(S,pIn,pOut,blockSize);
    }
}

void mw_arm_fir_init_f32(arm_fir_instance_f32 *S, uint16_t numTaps,
        float32_t *qCoeff, float32_t *pState, uint32_t blockSize, uint32_t numChannels){

    uint32_t channelIndex;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        S->pState = pState + (channelIndex * (blockSize + numTaps - 1));
        arm_fir_init_f32(S,numTaps,qCoeff,pState,blockSize);
    }
}

/*Discrete FIR Filter - Lattice MA structure with single data type input*/
void mw_arm_fir_lattice_f32(arm_fir_lattice_instance_f32 *S, float32_t *pSrc,
        float32_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numStages, float32_t *pState){

    uint32_t channelIndex;
    float32_t *pIn, *pOut;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        pIn = pSrc + (channelIndex * blockSize);
        pOut = pDst + (channelIndex * blockSize);
        S->pState = pState + (channelIndex * numStages);
        arm_fir_lattice_f32(S,pIn,pOut,blockSize);
    }
}

void mw_arm_fir_lattice_init_f32(arm_fir_lattice_instance_f32 *S, uint16_t numStages,
    float32_t *qCoeff, float32_t *pState, uint32_t blockSize, uint32_t numChannels){

    uint32_t channelIndex;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
         S->pState = pState + (channelIndex * numStages);
        arm_fir_lattice_init_f32(S,numStages,qCoeff,pState); 
    }
}

/*Discrete FIR Filter - Direct Form structure with fixed-point q15 data type input*/
void mw_arm_fir_q15(arm_fir_instance_q15 *S, q15_t *pSrc,
        q15_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps, q15_t *pState){

    uint32_t channelIndex;
    q15_t *pIn, *pOut;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        pIn = pSrc + (channelIndex * blockSize);
        pOut = pDst + (channelIndex * blockSize);
        S->pState = pState + (channelIndex * (blockSize + numTaps));
        arm_fir_q15(S,pIn,pOut,blockSize);
    }
}

void mw_arm_fir_init_q15(arm_fir_instance_q15 *S, uint16_t numTaps,
        q15_t *qCoeff, q15_t *pState, uint32_t blockSize, uint32_t numChannels){

    uint32_t channelIndex;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        S->pState = pState + (channelIndex * (blockSize + numTaps));
        arm_fir_init_q15(S,numTaps,qCoeff,pState,blockSize);
    }
}

/*Discrete FIR Filter - Direct Form structure with fixed-point q7 data type input*/
void mw_arm_fir_q7(arm_fir_instance_q7 *S, q7_t *pSrc,
        q7_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps, q7_t *pState){

    uint32_t channelIndex;
    q7_t *pIn, *pOut;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        pIn = pSrc + (channelIndex * blockSize);
        pOut = pDst + (channelIndex * blockSize);
        S->pState = pState + (channelIndex * (blockSize + numTaps - 1));
        arm_fir_q7(S,pIn,pOut,blockSize);
    }
}

void mw_arm_fir_init_q7(arm_fir_instance_q7 *S, uint16_t numTaps,
        q7_t *qCoeff, q7_t *pState, uint32_t blockSize, uint32_t numChannels){

    uint32_t channelIndex;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        S->pState = pState + (channelIndex * (blockSize + numTaps - 1));
        arm_fir_init_q7(S,numTaps,qCoeff,pState,blockSize); 
    }
}

/*Discrete FIR Filter - Direct Form structure with fixed-point q31 data type input*/
void mw_arm_fir_q31(arm_fir_instance_q31 *S, q31_t *pSrc,
        q31_t *pDst, uint32_t blockSize, uint32_t numChannels, uint16_t numTaps, q31_t *pState){

    uint32_t channelIndex;
    q31_t *pIn, *pOut;

        for(channelIndex= 0; channelIndex < numChannels; channelIndex++){
        pIn = pSrc + (channelIndex * blockSize);
        pOut = pDst + (channelIndex * blockSize);
        S->pState = pState + (channelIndex * (blockSize + numTaps - 1));
     arm_fir_q31(S,pIn,pOut,blockSize);
    }
}

void mw_arm_fir_init_q31(arm_fir_instance_q31 *S, uint16_t numTaps,
        q31_t *qCoeff, q31_t *pState, uint32_t blockSize, uint32_t numChannels){

    uint32_t channelIndex;

    for(channelIndex = 0; channelIndex < numChannels; channelIndex++){
        S->pState = pState + (channelIndex * (blockSize + numTaps - 1));
        arm_fir_init_q31(S,numTaps,qCoeff,pState,blockSize);
    }
}