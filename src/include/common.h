// ****************************************************************************
// Project Name:      PPCframework
//
//! @file             common.h
//! @version          $Revision: 182 $
//! @date             $Date: 2004-10-05 15:59:58 +0200 (Tue, 05 Oct 2004) $
//! @author           Tom Rejhon
//! @brief            General constant definition
//
// Company:             STMicroelectronics
//                      Pobrezni 3
//                      186 00 Praha 8, Czech Republic
//
// Processor:           PowerPC
// Compiler:            GHS
//
// ***************************** Revision History *****************************
//
// Date           Name         Description
// 01.12.2009     Zdenek Koza  Preliminary support for SPC56EL
// 13.03.2008     Tom Rejhon   Preliminary support for SPC560B/S/P
// 18.02.2008     Tom Rejhon   Added macros ORDERING_LITTLE2BIG_32() and 
//                             ORDERING_LITTLE2BIG_16() for endiannes conversion
// 14.02.2008     Tom Rejhon   Modified to support SPC563M
// 11.05.2007     Tom Rejhon   Original Issue - based on common.h for ST10 from 14.11.2006
//
// ****************************************************************************

#ifndef _COMMON_
#define _COMMON_

    #include "types.h"



// ****************************************************************************
// ************************** Constants and Variables *************************
// ****************************************************************************

    //general error codes
    #define OK              0
    #define FAIL            0xFFFF
    //added _ due to name conflict with Leopard header file
    #define _TIMEOUT        0xFF

    //boolean constants
    #define TRUE     1
    #define FALSE    0

    //Single bit masks
    #define MASK_BIT0   0x0001
    #define MASK_BIT1   0x0002
    #define MASK_BIT2   0x0004
    #define MASK_BIT3   0x0008
    #define MASK_BIT4   0x0010
    #define MASK_BIT5   0x0020
    #define MASK_BIT6   0x0040
    #define MASK_BIT7   0x0080
    #define MASK_BIT8   0x0100
    #define MASK_BIT9   0x0200
    #define MASK_BIT10  0x0400
    #define MASK_BIT11  0x0800
    #define MASK_BIT12  0x1000
    #define MASK_BIT13  0x2000
    #define MASK_BIT14  0x4000
    #define MASK_BIT15  0x8000
    
    #define MASK_BIT16  0x00010000
    #define MASK_BIT17  0x00020000
    #define MASK_BIT18  0x00040000
    #define MASK_BIT19  0x00080000
    #define MASK_BIT20  0x00100000
    #define MASK_BIT21  0x00200000
    #define MASK_BIT22  0x00400000
    #define MASK_BIT23  0x00800000
    #define MASK_BIT24  0x01000000
    #define MASK_BIT25  0x02000000
    #define MASK_BIT26  0x04000000
    #define MASK_BIT27  0x08000000
    #define MASK_BIT28  0x10000000
    #define MASK_BIT29  0x20000000
    #define MASK_BIT30  0x40000000
    #define MASK_BIT31  0x80000000

    //simple utility functions
    #define MIN(a,b) (((a) > (b))?(b):(a))
    //added _ due to name conflict with Leopard header file
    #define _MAX(a,b) (((a) > (b))?(a):(b))

	/* NOP example, revised */
	#define NOP asm("nop");
	#define MSYNC asm volatile("msync");


    //frequency of CPU clock [Hz]
    #define CPU_CLOCK       64000000
    #define CRYSTAL_CLOCK   40000000

#include "ports.h"
#include "spc56ELX_0101.h"
    

#endif

// ***************************** End of common.h *******************************
