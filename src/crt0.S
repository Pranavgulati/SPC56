///*
//    SPC5 HAL - Copyright (C) 2013 STMicroelectronics
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//*/
//
///**
// * @file    boot.s
// * @brief   SPC56ELxx boot-related code.
// *
// * @addtogroup PPC_BOOT
// * @{
// */

#include "boot.h"
        .globl      _boot_address
        .type       _boot_address, @function

       // /* BAM record.*/
        .section    .boot, "avx"
        .long       0x015A0000 //VLE enabled, Watchdog disabled, PS=32bit
	.long	    _reset_address
	 b	    _reset_address

        .section    .crt0, "avx"

        .align      2
        .globl      _reset_address
        .globl      unhandled_IVOR
        .globl		Interrupt_SW
        .type       _reset_address, @function

///**************************************************************************************************/
_reset_address:
	bl          _coreinit
	bl          _ivinit
	b           _boot_address

///**************************************************************************************************/
_ramcode:
        tlbwe
        isync
        blr


///**************************************************************************************************/
_coreinit:
	//---- Initialise the MSR -----
	//   e_lis	r3, STARTUP_MSR@ha;
	//   e_or2i	r3, STARTUP_MSR@l;
	// mtmsr	r3
	// e_b _startiiii
	//---------  Initialise Registers ---------------------

	//Initialise all core GPRs
	//Set the MSR[SPE] bit so code can use "evmergelo" instruction.
	 .equ     MSR_Mask, 0x02000000
	 e_lis	r5, 0
	 mfmsr	r5
	 e_lis	r6, MSR_Mask@h
	 e_or2i r6, MSR_Mask@l
	 or	r5, r5,r6
	 mtmsr 	r5
	 se_isync

	// 1.  32 64-bit GPR0-31

	 e_lis     r0, 0        // Initialize the lower 32-bits of GPR0 to 0
	 evmergelo r0,r0,r0   	// Initialize the 64-bits of GPR0 to 0
	// evmergelo r1,r0,r0   	//skip r1 which is stack pointer - Done by debugger or _start
	 evmergelo r2,r0,r0   	//Continue initializing the other 64-bit GPRs
	 evmergelo r3,r0,r0   	// ...
	 evmergelo r4,r0,r0
	 evmergelo r5,r0,r0
	 evmergelo r6,r0,r0
	 evmergelo r7,r0,r0
	 evmergelo r8,r0,r0
	 evmergelo r9,r0,r0
	 evmergelo r10,r0,r0
	 evmergelo r11,r0,r0
	 evmergelo r12,r0,r0
	// evmergelo r13,r0,r0  ; skip r13 which is used for SDA addressing - Done by debugger or _start
	 evmergelo r14,r0,r0
	 evmergelo r15,r0,r0
	 evmergelo r16,r0,r0
	 evmergelo r17,r0,r0
	 evmergelo r18,r0,r0
	 evmergelo r19,r0,r0
	 evmergelo r20,r0,r0
	 evmergelo r21,r0,r0
	 evmergelo r22,r0,r0
	 evmergelo r23,r0,r0
	 evmergelo r24,r0,r0
	 evmergelo r25,r0,r0
	 evmergelo r26,r0,r0
	 evmergelo r27,r0,r0
	 evmergelo r28,r0,r0
	 evmergelo r29,r0,r0
	 evmergelo r30,r0,r0
	 evmergelo r31,r0,r0  // Initialize the 64-bit GPR31 to 0

	// 2.  32-bit DEAR (spr 61)

	 mtspr 61,r31         //DEAR

	// 3.  32-bit SPRG0-9 (spr 272-279, 604 & 605)

	 mtspr 272,r31        //SPRG0-7
	 mtspr 273,r31
	 mtspr 274,r31
	 mtspr 275,r31
	 mtspr 276,r31
	 mtspr 277,r31
	 mtspr 278,r31
	 mtspr 279,r31

	 mtspr 604,r31         //SPRG8-9
	 mtspr 605,r31

	// 4.  32-bit USPRG0 (spr 256)

	 mtspr 256,r31         //USPRG0

	// 5.  32-bit SRR0 (spr 26), SRR1 (spr 27), CSRR0 (spr58), CSRR1 (spr59),
	//    DSRR0 (spr 574), DSRR1 (spr 575), MCSRR0 (spr570), MCSRR1 (spr571)

	 mtspr 26,r31          //SRR0-1
	 mtspr 27,r31
	 mtspr 58,r31          //CSRR0-1
	 mtspr 59,r31
	 mtspr 570,r31         //MCSRR0-1
	 mtspr 571,r31
	 mtspr 574,r31         //DSSRR0-1
	 mtspr 575,r31

	//32-bit MCAR (spr 573)
	mtspr 573,r31         //MCAR

	//32-bit TBL, TBU (spr 284, 285)
	mtspr 284,r31         //TBL
	mtspr 285,r31         //TBU

	//32-bit DEC, DECAR (spr 22, 54)
	mtspr 22,r31          //DEC
	mtspr 54,r31          //DECAR

	//64-bit DVC1, DVC2 (spr 318, 319)
	//Note most debug registers are reset by POR so initialization is not required.
	mtspr 318,r31         //DVC1
	mtspr 319,r31         //DVC2

	//12. 32-bit DBCNT (spr 562)
	mtspr 562,r31         //DBCNT

	//13. 32-bit MAS0-4 (spr 624-628), MAS6 (spr 630)
//	/*MAS0-3 are initialized below when doing MMU setup.
//	 need valid value to write to MAS4 and MAS6 ????
//	You also need to look at the spec.
//	executing these instructions crashes the part when doing
//	msync below. August 11, 2010 */
//	mtMAS4 r31            //MAS4
//	mtMAS6 r31            //MAS6

	//16. SPE ACC register.
	evmra r31,r31           // Initialize the 64-bit SPE ACC to 0
	evmra r31,r31           // It was required to use the "evmra" command twice in
	                         // simulation. Verify on silicon ??????

	//17. Condition Registers
	mtcrf 0xFF,r31
	//18. Counter/Decrementer/Link Register
	mtspr 9,r31            //CTR
//	mtspr 8,r31            //LR
//----------------------------- SET UP MMU (begin) -------------------------------------------------

	//table 0
	e_lis r5, 0x10000000@ha
	e_add16i r5, r5, 0x10000000@l
        mtspr mas0,r5            	// mtspr MAS0,r5
	e_lis r5, 0xC0000580@ha
	e_add16i r5, r5, 0xC0000580@l
         mtspr mas1,r5				// mtspr MAS1,r5
	e_lis r5, 0x00000020@ha
	e_add16i r5, r5, 0x00000020@l
	mtspr mas2,r5            	// mtspr MAS2,r5
	e_lis r5, 0x0000003F@ha
	e_add16i r5, r5, 0x0000003F@l
	mtspr mas3,r5            	// mtspr MAS3,r5
	  tlbwe                    	// Write the entry to the TLB

							//table 1
	e_lis r5, 0x10010000@ha
	e_add16i r5, r5, 0x10010000@l
	mtspr mas0,r5            	// mtspr MAS0,r5
	e_lis r5, 0xC0000380@ha
	e_add16i r5, r5, 0xC0000400@l
	mtspr mas1,r5            	// mtspr MAS1,r5
	e_lis r5, 0x40000020@ha
	e_add16i r5, r5, 0x40000020@l

	mtspr mas2,r5            	// mtspr MAS2,r5
	e_lis r5, 0x4000003F@ha
	e_add16i r5, r5, 0x4000003F@l
	mtspr mas3,r5            	// mtspr MAS3,r5
	  tlbwe                    	// Write the entry to the TLB

							//table 2
	e_lis r5, 0x10020000@ha
	e_add16i r5, r5, 0x10020000@l
	mtspr mas0,r5            	// mtspr MAS0,r5
	e_lis r5, 0xC0000500@ha
	e_add16i r5, r5, 0xC0000500@l
	mtspr mas1,r5            	// mtspr MAS1,r5
	e_lis r5, 0xFFF0000A@ha
	e_add16i r5, r5, 0xFFF0000A@l
	mtspr mas2,r5            	// mtspr MAS2,r5
	e_lis r5, 0xFFF0003F@ha
	e_add16i r5, r5, 0xFFF0003F@l
	mtspr mas3,r5           	// mtspr MAS3,r5
	  tlbwe                   	// Write the entry to the TLB

							//table 3
	e_lis r5, 0x10030000@ha
	e_add16i r5, r5, 0x10030000@l
	mtspr mas0,r5            	// mtspr MAS0,r5
	e_lis r5, 0xC0000500@ha
	e_add16i r5, r5, 0xC0000500@l
	mtspr mas1,r5            	// mtspr MAS1,r5
	e_lis r5, 0xFFE0000A@ha
	e_add16i r5, r5, 0xFFE0000A@l
	mtspr mas2,r5            	// mtspr MAS2,r5
	e_lis r5, 0xFFE0003F@ha
	e_add16i r5, r5, 0xFFE0003F@l
	mtspr mas3,r5            	// mtspr MAS3,r5
	tlbwe                    	// Write the entry to the TLB

							//table 4
	e_lis r5, 0x10040000@ha
	e_add16i r5, r5, 0x10040000@l
	mtspr mas0,r5            	// mtspr MAS0,r5
	e_lis r5, 0xC0000500@ha
	e_add16i r5, r5, 0xC0000500@l
	mtspr mas1,r5            	// mtspr MAS1,r5
	e_lis r5, 0x8FF0000A@ha
	e_add16i r5, r5, 0x8FF0000A@l
	mtspr mas2,r5            	// mtspr MAS2,r5
	e_lis r5, 0x8FF0003F@ha
	e_add16i r5, r5, 0x8FF0003F@l
	mtspr mas3,r5            	// mtspr MAS3,r5
	tlbwe                    	// Write the entry to the TLB

							//table 5
	e_lis r5, 0x10050000@ha
	e_add16i r5, r5, 0x10050000@l
	mtspr mas0,r5            	// mtspr MAS0,r5
	e_lis r5, 0xC0000500@ha
	e_add16i r5, r5, 0xC0000500@l
	mtspr mas1,r5            	// mtspr MAS1,r5
	e_lis r5, 0xC3F0000A@ha
	e_add16i r5, r5, 0xC3F0000A@l
	mtspr mas2,r5            	// mtspr MAS2,r5
	e_lis r5, 0xC3F0003F@ha
	e_add16i r5, r5, 0xC3F0003F@l
	mtspr mas3,r5            	// mtspr MAS3,r5
	tlbwe                    	// Write the entry to the TLB
    se_isync

//----------------------------- SET UP MMU (END) --------------------------------------------------


	//*****************************************************************
	// Autosar Guidance 4 - If the MCU supports context save          *
	// operation, the start-up code shall initialize the memory which *
	// is used for context save operation. The maximum amount of      *
	// consecutive context save operations is provided as             *
	// configuration parameter or linker/locator setting.             *
	//*****************************************************************

	//*****************************************************************
	// Autosar Guidance 5 - The start-up code shall ensure that the   *
	// MCU internal watchdog shall not be serviced until the watchdog *
	// is initialized from the MCAL watchdog driver. This can be      *
	// done for example by increasing the watchdog service time.      *
	//*****************************************************************
/////*	e_lis     r6, 0xfff4
////	e_sub16i  r6, r6, 0x7ff0
////	e_li      r7, 0xc520 ;   //unlock peripheral I
////	se_stw    r7, 0(r6)
////	e_li      r7, 0xd928
////	se_stw    r7, 0(r6) ;    //unlock peripheral II
////	// disable SWT
////	e_lis     r7, 0xfff4
////	e_sub16i  r7, r7, 0x8000
////	se_lwz    r6, 0(r7)
////	se_bclri  r6, 31
////	se_stw    r6, 0(r7)
////*/
////
////	/* Invalidating all TLBs except TLB0.      */
        lis         %r3, 0
        mtspr       625, %r3       // /* MAS1 */
        mtspr       626, %r3       // /* MAS2 */
        mtspr       627, %r3      //  /* MAS3 */
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(1))@h
        mtspr       624, %r3      //  /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(2))@h
        mtspr       624, %r3      //  /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(3))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(4))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(5))@h
        mtspr       624, %r3      //  /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(6))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(7))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(8))@h
        mtspr       624, %r3      //  /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(9))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(10))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(11))@h
        mtspr       624, %r3        ///* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(12))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(13))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(14))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe
        lis         %r3, (MAS0_TBLMAS_TBL | MAS0_ESEL(15))@h
        mtspr       624, %r3       // /* MAS0 */
        tlbwe

//        /*
//         * TLB1 allocated to internal RAM.
//         */
        lis         %r3, TLB1_MAS0@h
        mtspr       624, %r3       // /* MAS0 */
        lis         %r3, TLB1_MAS1@h
        ori         %r3, %r3, TLB1_MAS1@l
        mtspr       625, %r3       // /* MAS1 */
        lis         %r3, TLB1_MAS2@h
        ori         %r3, %r3, TLB1_MAS2@l
        mtspr       626, %r3       // /* MAS2 */
        lis         %r3, TLB1_MAS3@h
        ori         %r3, %r3, TLB1_MAS3@l
        mtspr       627, %r3      //  /* MAS3 */
        tlbwe

//        /*
//         * TLB2 allocated to internal Peripherals Bridge A.
//         */
        lis         %r3, TLB2_MAS0@h
        mtspr       624, %r3       // /* MAS0 */
        lis         %r3, TLB2_MAS1@h
        ori         %r3, %r3, TLB2_MAS1@l
        mtspr       625, %r3       // /* MAS1 */
        lis         %r3, TLB2_MAS2@h
        ori         %r3, %r3, TLB2_MAS2@l
        mtspr       626, %r3      //  /* MAS2 */
        lis         %r3, TLB2_MAS3@h
        ori         %r3, %r3, TLB2_MAS3@l
        mtspr       627, %r3      //  /* MAS3 */
        tlbwe

//        /*
//         * TLB3 allocated to internal Peripherals Bridge B.
//         */
        lis         %r3, TLB3_MAS0@h
        mtspr       624, %r3    //    /* MAS0 */
        lis         %r3, TLB3_MAS1@h
        ori         %r3, %r3, TLB3_MAS1@l
        mtspr       625, %r3    //    /* MAS1 */
        lis         %r3, TLB3_MAS2@h
        ori         %r3, %r3, TLB3_MAS2@l
        mtspr       626, %r3     //   /* MAS2 */
        lis         %r3, TLB3_MAS3@h
        ori         %r3, %r3, TLB3_MAS3@l
        mtspr       627, %r3     //   /* MAS3 */
        tlbwe
//
//        /*
//         * TLB4 allocated to on-platform peripherals.
//         */
        lis         %r3, TLB4_MAS0@h
        mtspr       624, %r3       // /* MAS0 */
        lis         %r3, TLB4_MAS1@h
        ori         %r3, %r3, TLB4_MAS1@l
        mtspr       625, %r3       // /* MAS1 */
        lis         %r3, TLB4_MAS2@h
        ori         %r3, %r3, TLB4_MAS2@l
        mtspr       626, %r3       // /* MAS2 */
        lis         %r3, TLB4_MAS3@h
        ori         %r3, %r3, TLB4_MAS3@l
        mtspr       627, %r3       // /* MAS3 */
        tlbwe

//        /*
//         * TLB5 allocated to on-platform peripherals.
//         */
        lis         %r3, TLB5_MAS0@h
        mtspr       624, %r3     //   /* MAS0 */
        lis         %r3, TLB5_MAS1@h
        ori         %r3, %r3, TLB5_MAS1@l
        mtspr       625, %r3      //  /* MAS1 */
        lis         %r3, TLB5_MAS2@h
        ori         %r3, %r3, TLB5_MAS2@l
        mtspr       626, %r3      //  /* MAS2 */
        lis         %r3, TLB5_MAS3@h
        ori         %r3, %r3, TLB5_MAS3@l
        mtspr       627, %r3      //  /* MAS3 */
        tlbwe
//
//        /*
//         * RAM clearing, this device requires a write to all RAM location in
//         * order to initialize the ECC detection hardware, this is going to
//         * slow down the startup but there is no way around.
//         */
        xor         %r0, %r0, %r0
        xor         %r1, %r1, %r1
        xor         %r2, %r2, %r2
        xor         %r3, %r3, %r3
        xor         %r4, %r4, %r4
        xor         %r5, %r5, %r5
        xor         %r6, %r6, %r6
        xor         %r7, %r7, %r7
        xor         %r8, %r8, %r8
        xor         %r9, %r9, %r9
        xor         %r10, %r10, %r10
        xor         %r11, %r11, %r11
        xor         %r12, %r12, %r12
        xor         %r13, %r13, %r13
        xor         %r14, %r14, %r14
        xor         %r15, %r15, %r15
        xor         %r16, %r16, %r16
        xor         %r17, %r17, %r17
        xor         %r18, %r18, %r18
        xor         %r19, %r19, %r19
        xor         %r20, %r20, %r20
        xor         %r21, %r21, %r21
        xor         %r22, %r22, %r22
        xor         %r23, %r23, %r23
        xor         %r24, %r24, %r24
        xor         %r25, %r25, %r25
        xor         %r26, %r26, %r26
        xor         %r27, %r27, %r27
        xor         %r28, %r28, %r28
        xor         %r29, %r29, %r29
        xor         %r30, %r30, %r30
        xor         %r31, %r31, %r31
        lis         %r4, __ram_start__@h
        ori         %r4, %r4, __ram_start__@l
        lis         %r5, __ram_end__@h
        ori         %r5, %r5, __ram_end__@l
.cleareccloop:
        cmpl        %cr0, %r4, %r5
        bge         %cr0, .cleareccend
        stmw        %r16, 0(%r4)
        addi        %r4, %r4, 64
        b           .cleareccloop
.cleareccend:


//        /*
//         * Special function registers clearing, required in order to avoid
//         * possible problems with lockstep mode.
//         */
        mtcrf       0xFF, %r31
        mtspr       9, %r31       //  /* CTR     */
        mtspr       22, %r31       // /* DEC     */
        mtspr       26, %r31      //  /* SRR0-1  */
        mtspr       27, %r31
        mtspr       54, %r31       // /* DECAR   */
        mtspr       58, %r31       // /* CSRR0-1 */
        mtspr       59, %r31
        mtspr       61, %r31      //  /* DEAR    */
        mtspr       256, %r31     //  /* USPRG0  */
        mtspr       272, %r31     //  /* SPRG1-7 */
        mtspr       273, %r31
        mtspr       274, %r31
        mtspr       275, %r31
        mtspr       276, %r31
        mtspr       277, %r31
        mtspr       278, %r31
        mtspr       279, %r31
        mtspr       285, %r31      // /* TBU     */
        mtspr       284, %r31      // /* TBL     */
#if 0
        mtspr       318, %r31      // /* DVC1-2  */
        mtspr       319, %r31
#endif
        mtspr       562, %r31     //  /* DBCNT */
        mtspr       570, %r31     //  /* MCSRR0  */
        mtspr       571, %r31     //  /* MCSRR1  */
        mtspr       604, %r31      // /* SPRG8-9 */
        mtspr       605, %r31


//        /*
//         * *Finally* the TLB0 is re-allocated to flash, note, the final phase
//         * is executed from RAM.
//         */
        lis         %r3, TLB0_MAS0@h
        mtspr       624, %r3      //  /* MAS0 */
        lis         %r3, TLB0_MAS1@h
        ori         %r3, %r3, TLB0_MAS1@l
        mtspr       625, %r3       // /* MAS1 */
        lis         %r3, TLB0_MAS2@h
        ori         %r3, %r3, TLB0_MAS2@l
        mtspr       626, %r3      //  /* MAS2 */
        lis         %r3, TLB0_MAS3@h
        ori         %r3, %r3, TLB0_MAS3@l
        mtspr       627, %r3      //  /* MAS3 */
        mflr        %r4
        lis         %r6, _ramcode@h
        ori         %r6, %r6, _ramcode@l
        lis         %r7, 0x40010000@h
        mtctr       %r7
        lwz         %r3, 0(%r6)
        stw         %r3, 0(%r7)
        lwz         %r3, 4(%r6)
        stw         %r3, 4(%r7)
        lwz         %r3, 8(%r6)
        stw         %r3, 8(%r7)
        bctrl
        mtlr        %r4
//
//
//    /*****************************************
//    *FCCU - to store status and Fault handling
//    *****************************************/
    // Base address of FCCU module to r7
    e_lis   %r7, FCCU_BASE@h
    e_or2i  %r7, FCCU_BASE@l

    // Read Status
    e_li %r0, FCCU_OPR_STATUS     //prepare command
    stw    %r0, FCCU_REG_CTRL (%r7)    // issue command
    .read_status:
    lwz    %r0, FCCU_REG_CTRL (%r7)    // read FCCU_CTRL register
    rlwinm   %r0,%r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  %r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.read_status    // wait to finish the command
    lwz    %r5, FCCU_REG_STATUS (%r7)  // read Status
    se_cmpi  %r5,0        // Status == NORMAL?
    se_bc   1,2,fccu_no_fault    // no fault in fccu > skip fault handling

    // Read CF_0 faults
    e_li     r0, FCCU_OPR_CF_READ    // prepare command
    e_stw    r0, FCCU_REG_CTRL (r7)    // issue command
    .read_cf0:
    e_lwz    r0, FCCU_REG_CTRL (r7)    // read FCCU_CTRL register
    e_rlwinm   r0,r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.read_cf0      // wait to finish the command
    e_lwz    r3, FCCU_REG_CF0 (r7)    // read CF register to r3 register
    mtsprg0  r3        // save them to Core SPRG0 register

    // Read CF_1 faults
    e_li     r0, FCCU_OPR_CF_READ    // prepare command
    e_stw    r0, FCCU_REG_CTRL (r7)    // issue command
    .read_cf1:
    e_lwz    r0, FCCU_REG_CTRL (r7)    // read FCCU_CTRL register
    e_rlwinm   r0,r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.read_cf1      // wait to finish the command
    e_lwz    r3, FCCU_REG_CF1 (r7)    // read CF register to r3 register
    mtsprg1  r3        // save them to Core SPRG1 register

    // Read NCF faults
    e_li     r0, FCCU_OPR_NCF_READ    // prepare command
    e_stw    r0, FCCU_REG_CTRL (r7)    // issue command
    .read_ncf:
    e_lwz    r0, FCCU_REG_CTRL (r7)    // read FCCU_CTRL register
    e_rlwinm   r0,r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.read_ncf      // wait to finish the command
    e_lwz    r4, FCCU_REG_NCF (r7)    // read NCF register to r4 register
    mtsprg2  r4        // save them to Core SPRG2 register

    // Check STCU faults
    se_mr   r0,r3        // take copy of CF faults
    e_and2is.  r0,0x0850      // mask bits CF[27,22,20]
    se_cmpi  r0,0        // is one of them '1' ?
    se_bc   00,02,fccu_stcu_error     // if yes - jump to error handler
    se_btsti  r4, FCCU_NCF12      // check bit NCF[12]
    se_bc   1,2,fccu_analyze     // jump if all STCU bits are '0'

    fccu_stcu_error:
    // user code - handler of STCU errors
    se_b    .         // break due to STCU faults

    fccu_analyze:
    // user code - analyze FCCU faults, if there are any
    // ...
    se_b    fccu_clear      // continue with clear operation

    fccu_clear:

    // clear FCCU Critical faults CF0
    e_lis   r0, FCCU_CFK_KEY@h
    e_or2i  r0, FCCU_CFK_KEY@l
    e_stw   r0, FCCU_REG_CFK (r7)    // write Key to clear CF faults
    e_stw   r3, FCCU_REG_CF0 (r7)    // clear known CF faults
    .wait_cf0_clear:
    e_lwz    r0, FCCU_REG_CTRL (r7)    // read FCCU_CTRL register
    e_rlwinm   r0,r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.wait_cf0_clear    // wait to finish the command

    // clear FCCU Critical faults CF1
    e_lis   r0, FCCU_CFK_KEY@h
    e_or2i  r0, FCCU_CFK_KEY@l
    e_stw   r0, FCCU_REG_CFK (r7)    // write Key to clear CF faults
    e_stw   r3, FCCU_REG_CF1 (r7)    // clear known CF faults
    .wait_cf1_clear:
    e_lwz    r0, FCCU_REG_CTRL (r7)    // read FCCU_CTRL register
    e_rlwinm   r0,r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.wait_cf1_clear    // wait to finish the command

    // clear FCCU Non-Critical faults (NCF)
    e_lis   r0, FCCU_NCFK_KEY@h
    e_or2i  r0, FCCU_NCFK_KEY@l
    e_stw   r0, FCCU_REG_NCFK (r7)    // write Key to clear CF faults
    e_stw   r4, FCCU_REG_NCF (r7)    // clear known NCF faults
    .wait_ncf_clear:
    e_lwz    r0, FCCU_REG_CTRL (r7)    // read FCCU_CTRL register
    e_rlwinm   r0,r0,26,30,31      // rotate OPS field and mask it
    se_cmpi  r0, FCCU_OPS_SUCCESS    // look for OPS = SUCCESS
    se_bc    00,02,.wait_ncf_clear    // wait to finish the command

    // continue with next block
    se_b    fccu_end

    // no FCCU faults
    fccu_no_fault:
    e_lis   r0,0
    mtsprg0  r0        // save no CF fault to Core register
    mtsprg1  r0        // save no CF fault to Core register
    mtsprg2  r0        // save no CF fault to Core register

    fccu_end:


//    /**********************
//     * RGM  to store status
//     *********************/

    // Base address of RGM module to r7
      e_lis   r7, RGM_BASE@h
      e_or2i  r7, RGM_BASE@l

      // Read all RGM flags (FES+DES)
      e_lwz   r0, RGM_REG_FESDES (r7)
      mtsprg3  r0        // save reset flags to Core SPRG3 register

      // destructive reset ?
      e_lis   r1, RGM_DES_MASK@h
      e_or2i  r1, RGM_DES_MASK@l
      se_and  r0, r1        // look for destructive resets
      se_cmpi  r0,0        // is one of them '1' ?
      se_bc   01,02,rgm_fes_handler     // if no - jump to Functional handler
    rgm_des_handler:
    // do what is needed for destructive path
      // ....
      se_b  rgm_clear        // go to flag reset operation

    rgm_fes_handler:
      // analyze if the reset was expected or not
      // ...

    rgm_clear:
      e_lis   r1, 0xFFFF
      e_or2i  r1, 0xFFFF      // prepare value for clear-write-1 oper.
      e_stw   r1, RGM_REG_FESDES (r7)   // write '1' to clear all flags

    rgm_end:

//        /* Branch prediction enabled.  */
        li          %r3, BUCSR_DEFAULT
        mtspr       1013, %r3      // /* BUCSR */

//        /* Cache invalidated and then enabled. */
        li          %r3, LICSR1_ICINV
        mtspr       1011, %r3     //  /* LICSR1 */
.inv:   mfspr       %r3, 1011     //  /* LICSR1 */
        andi.       %r3, %r3, LICSR1_ICINV
        bne         .inv
        lis         %r3, LICSR1_DEFAULT@h
        ori         %r3, %r3, LICSR1_DEFAULT@l
        mtspr       1011, %r3     //  /* LICSR1 */
        blr
///**************************************************************************************************/
_ivinit:				// 32-bit IVPR (spr 63)

	//32-bit IVOR0-15 (spr 400 - 415), IVOR 32-35 (spr 528 - 531)
//	/* MSR initialization.*/
	lis         %r3, MSR_DEFAULT@h
	ori         %r3, %r3, MSR_DEFAULT@l
	mtMSR       %r3
	evmergelo r31,r0,r0  // Initialize the 64-bit GPR31 to 0
	mtspr 63,r31          //IVPR
	mtspr 62,r31          //ESR
	mtspr 340,r31         //TCR
	mtspr 512,r31         //SPEFSCR
	mtspr 1,r31           //XER
	mtspr 256,r31         //USPRG0


//	/* IVPR initialization.*/
	lis         %r3, __IVPR_BASE_@h
	ori         %r3, %r3, __IVPR_BASE_@l
	mtIVPR      %r3

//	/* IVORs initialization.*/
	lis         %r3, unhandled_IVOR@h
	ori         %r3, %r3, unhandled_IVOR@l

	mtspr       400, %r3        ///* IVOR0-15 */
	mtspr       401, %r3
	mtspr       402, %r3
	mtspr       403, %r3
	mtspr       404, %r3
	mtspr       405, %r3
	mtspr       406, %r3
	mtspr       407, %r3
	mtspr       408, %r3
	mtspr       409, %r3
	mtspr       410, %r3
	mtspr       411, %r3
	mtspr       412, %r3
	mtspr       413, %r3
	mtspr       414, %r3
	mtspr       415, %r3
	mtspr       528, %r3        ///* IVOR32-34 */
	mtspr       529, %r3
	mtspr       530, %r3


//		/* IVORs initialization.*/
	lis         %r3, Interrupt_SW@h
	ori         %r3, %r3, Interrupt_SW@l
	mtspr       404, %r3

	blr
///**************************************************************************************************/
_boot_address:
//        /*
//         * Stack setup.
//         */
        lis         %r1, __process_stack_end__@h
        ori         %r1, %r1, __process_stack_end__@l
        li          %r0, 0
        stwu        %r0, -8(%r1)
//        /*
//         * Small sections registers initialization.
//         */
        lis         %r2, __sdata2_start__@h
        ori         %r2, %r2, __sdata2_start__@l
        lis         %r13, __sdata_start__@h
        ori         %r13, %r13, __sdata_start__@l
//        /*
//         * Early initialization.
//         */
        bl          __early_init
//        /*
//         * BSS clearing.
//         */
        lis         %r4, __bss_start__@h
        ori         %r4, %r4, __bss_start__@l
        lis         %r5, __bss_end__@h
        ori         %r5, %r5, __bss_end__@l
        li          %r7, 0
.bssloop:
        cmpl        cr0, %r4, %r5
        bge         cr0, .bssend
        stw         %r7, 0(%r4)
        addi        %r4, %r4, 4
        b           .bssloop
.bssend:
//        /*
//         * DATA initialization.
//         */
        lis         %r4, __romdata_start__@h
        ori         %r4, %r4, __romdata_start__@l
        lis         %r5, __data_start__@h
        ori         %r5, %r5, __data_start__@l
        lis         %r6, __data_end__@h
        ori         %r6, %r6, __data_end__@l
.dataloop:
        cmpl        cr0, %r5, %r6
        bge         cr0, .dataend
        lwz         %r7, 0(%r4)
        addi        %r4, %r4, 4
        stw         %r7, 0(%r5)
        addi        %r5, %r5, 4
        b           .dataloop
.dataend:
//        /*
//         * Late initialization.
//         */
        bl          __late_init
//        /*
//         * Main program invocation.
//         */
        bl          main
        b           _main_exit_handler

//        /*
//         * Default main exit code, infinite loop.
//         */
        .weak       _main_exit_handler
        .globl      _main_exit_handler
        .type       _main_exit_handler, @function
_main_exit_handler:
        b           _main_exit_handler

//        /*
//         * Default early initialization code, none.
//         */
        .weak       __early_init
        .globl      __early_init
        .type       __early_init, @function
__early_init:
        blr

//        /*
//         * Default late initialization code, none.
//         */
        .weak       __late_init
        .globl      __late_init
        .type       __late_init, @function
__late_init:
        blr

///** @} */
