/******************** (C) COPYRIGHT 2013 STMicroelectronics *******************
* Project		: xxx
* File Name   	: intc.h
* Author      	: Radek Pulpan
* Version		: 1.0
* Date			: Dec 9, 2013
* Procesor		: SPC57xx
* Compilator	: HighTex
* Description 	: service routines for INTC
********************************************************************************
* History:
* Dec 9, 2013: Version 1.0
*******************************************************************************/

#ifndef INTC_H_
#define INTC_H_

	#include "common.h"

	#define _EI	__asm__ volatile(" wrteei 1");	    	   /* Enable external interrupts */


	#define INTR_PROLOG1 \
	  __asm__ volatile ("" \
			"stwu       r1,-80(r1)      # allocate stack space\n\t" \
			"e_stmvsrrw 8(r1)           # save SRR0 & SRR1 register\n\t" \
			"e_stmvsprw 16(r1)          # save CR, LR, CTR, and XER\n\t" \
			"e_stmvgprw 32(r1)          # save r0, r3:r12\n\t" \
	"")

	#define INTR_EPILOG1 \
	  __asm__ volatile ("" \
			".equ INTC_0_EOIR2_ADDR,   0xFC040038 \n\t" \
			"e_lis  r3,INTC_0_EOIR2_ADDR@ha\n\t" \
			"ori    r3,r3,INTC_0_EOIR2_ADDR@l\n\t" \
			"li     r4,0\n\t" \
			"stw        r4,0(r3)    # write to EOIR\n\t" \
			"e_lmvgprw  32(r1)      # restore r0, r3:r12\n\t" \
			"e_lmvsprw  16(r1)      # restore CR, LR, CTR, and XER\n\t" \
			"e_lmvsrrw  8(r1)       # restore SRR0 & SRR1\n\t" \
			"addi   r1,r1,80        # deallocate stack space\n\t" \
			"rfi                    # End of Interrupt\n\t" \
	"")


	void initIrqVectors(void);
	void initINTC(void);
	void enableIrq(void);

#endif /* INTC_H_ */
