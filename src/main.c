/*====================================================================
* Project:  Board Support Package (BSP) examples
* Function: empty main function
*
* Copyright HighTec EDV-Systeme GmbH 1982-2013
*====================================================================*/
#include <stdlib.h>
#include "common.h"
#include "me.h"
#include "pit.h"
#include "intc.h"
#include "flexcan.h"
#include "interrupts56xx.h"

/********************************************************************
 *                     			                            *
 *								    *
 *                                                                  *
 *                               				    *
                                  NOTE
 ********************************************************************/  
/*
  For adding any module following steps must be done
  1. Enable the interrupts in the INTC module file by setting priority
  2. Provide clock to the the module in the ME module by setting PCTL to zero
  3. Now configure the module by calling its init(function)
  */

// FCCU module constants
#define FCCU_BASE           0xFFE6C000  // FCCU module base address
#define FCCU_REG_CTRL       0x0000    // registers offset
#define FCCU_REG_CF0        0x006C
#define FCCU_REG_CF1        0x0070
#define FCCU_REG_CFK        0x007C
#define FCCU_REG_NCF        0x0080
#define FCCU_REG_NCFK       0x0090
#define FCCU_REG_STATUS     0x00C0
#define FCCU_OPR_STATUS     0x3    // command to read Status
#define FCCU_OPR_CF_READ    0x9    // command to read CF
#define FCCU_OPR_NCF_READ   0xA    // command to read NCF
#define FCCU_CFK_KEY        0x618B7A50  // key for CF faults clear operation
#define FCCU_NCFK_KEY       0xAB3498FE  // key for NCF faults clear operation
#define FCCU_OPS_SUCCESS    3    // command successful status to wait for
#define FCCU_NCF12          19    // BSTI instr has inverse bit numbering

// RGM module constants
#define RGM_BASE            0xC3FE4000  // Reset module base address
#define RGM_REG_FESDES      0x0000    // register offset from RGM_BASE
#define RGM_DES_MASK        0x8000FFFF  // Destructive resets status bit mask

int main(void);
void AIPS_Init(void);


//***********************************************************************
// Name:        AIPS_Init
// Parameters:  none
// Returns:     none
// Description:
//
//************************************************************************
void AIPS_Init(void)
{

// All Master Can go through AIPS and all peripheral have no protection

	AIPS.MPROT.R      = 0x77777777;
	AIPS.PACR0_7.R    = 0x0;
	AIPS.PACR8_15.R   = 0x0;
	AIPS.PACR16_23.R  = 0x0;
	AIPS.PACR24_31.R  = 0x0;

	AIPS.OPACR0_7.R   = 0x0;
	AIPS.OPACR8_15.R  = 0x0;
	AIPS.OPACR16_23.R = 0x0;
	AIPS.OPACR24_31.R = 0x0;
	AIPS.OPACR32_39.R = 0x0;
	AIPS.OPACR40_47.R = 0x0;
	AIPS.OPACR48_55.R = 0x0;
	AIPS.OPACR56_63.R = 0x0;
	AIPS.OPACR64_71.R = 0x0;
	AIPS.OPACR72_79.R = 0x0;
	AIPS.OPACR80_87.R = 0x0;
	AIPS.OPACR88_95.R = 0x0;
}



//***********************************************************************
// Name:        main
// Parameters:  none
// Returns:     none
// Description:

int main(void)
{

	AIPS_Init();				// Initialize AIPS bridge
	ME_Init();				// Initialize all basic modules - ME, CGM, ...
	INTC_Init();				// Initialize interrupt controller

        SIU.PCR[PORT_PIN_C15].R=0x0200;
	SIU.PCR[PORT_PIN_C14].R=0x0200;
	SIU.PCR[PORT_PIN_C13].R=0x0200;
	SIU.GPDO[PORT_PIN_C13].R = 1;
	SIU.GPDO[PORT_PIN_C14].R = 1;
	SIU.GPDO[PORT_PIN_C15].R = 1;
	
	CAN_Init(MODULE_A,40);
    	PIT_Init(5000);
	
	while(1)
	{
	    uint32_t i =0;
	    for(i=0;i<1000000;i++){
		asm volatile ("nop");
	    }
	    CAN_Tx(MODULE_A, 0xFF,0xF, 2, 9);
	}
}


/******************************************************************************
* FUNCTION: 	PIT0_ISR
* PARAMETERS:	void
* DESCRIPTION:	Service routine for PIT IRQ
* RETURNS:		void
*******************************************************************************/
void PIT_ISR(void)
{
	PIT.CH[0].TFLG.B.TIF = 1;    	
}


//double underscore denotes that it is not a normal function and must not be called otherwise
void __external_input_exception() {
    switch(INTC.IACKR.B.INTVEC){
        case 59:
	
	    SIU.GPDO[PORT_PIN_C13].R = ~SIU.GPDO[PORT_PIN_C13].R;    	   

            /* Timer Interrupt */

	    PIT.CH[0].TFLG.B.TIF = 1; 
            break;
	case 60:
            /* Timer Interrupt */
            //PIT_ISR();
  	SIU.GPDO[PORT_PIN_C14].R = ~SIU.GPDO[PORT_PIN_C14].R;	
	    PIT.CH[1].TFLG.B.TIF = 1;    	
            break;
/*	case 65:
 -             @/@*$ CAN_0 ERR_INT $*@/@
 - 
 -     	    SIU.GPDO[PORT_PIN_C15].R = ~SIU.GPDO[PORT_PIN_C15].R;
 - 	
 -             break;*/
	case 68:

	    CAN_0.IFRL.B.BUF00I=1;
	    CAN_0.IFRL.B.BUF01I=1;
	    CAN_0.IFRL.B.BUF02I=1;
	    CAN_0.IFRL.B.BUF03I=1;
	    break;
	case 69:
	    CAN_0.IFRL.B.BUF04I=1;
	    CAN_0.IFRL.B.BUF05I=1;
	    CAN_0.IFRL.B.BUF06I=1;
	    CAN_0.IFRL.B.BUF07I=1;
	    break;
	case 70:
	    CAN_0.IFRL.B.BUF08I=1;
	    CAN_0.IFRL.B.BUF09I=1;
	    CAN_0.IFRL.B.BUF10I=1;
	    CAN_0.IFRL.B.BUF11I=1;
	    break;
	case 71:
	    CAN_0.IFRL.B.BUF12I=1;
	    CAN_0.IFRL.B.BUF13I=1;
	    CAN_0.IFRL.B.BUF14I=1;
	    CAN_0.IFRL.B.BUF15I=1;
	    break;
	case 72:
	    CAN_0.IFRL.B.BUF16I=1;
	    CAN_0.IFRL.B.BUF17I=1;
	    CAN_0.IFRL.B.BUF18I=1;
	    CAN_0.IFRL.B.BUF19I=1;
	    CAN_0.IFRL.B.BUF20I=1;
	    CAN_0.IFRL.B.BUF21I=1;
	    CAN_0.IFRL.B.BUF22I=1;
	    CAN_0.IFRL.B.BUF23I=1;
	    CAN_0.IFRL.B.BUF24I=1;
	    CAN_0.IFRL.B.BUF25I=1;
	    CAN_0.IFRL.B.BUF26I=1;
	    CAN_0.IFRL.B.BUF27I=1;
	    CAN_0.IFRL.B.BUF28I=1;
	    CAN_0.IFRL.B.BUF29I=1;
	    CAN_0.IFRL.B.BUF30I=1;
	    CAN_0.IFRL.B.BUF31I=1;
	    break;
	case 88:
	    CAN_1.IFRL.B.BUF00I=1;
	    CAN_1.IFRL.B.BUF01I=1;
	    CAN_1.IFRL.B.BUF02I=1;
	    CAN_1.IFRL.B.BUF03I=1;
	    break;
	case 89:
	    CAN_1.IFRL.B.BUF04I=1;
	    CAN_1.IFRL.B.BUF05I=1;
	    CAN_1.IFRL.B.BUF06I=1;
	    CAN_1.IFRL.B.BUF07I=1;
	    break;
	case 90:
	    CAN_1.IFRL.B.BUF08I=1;
	    CAN_1.IFRL.B.BUF09I=1;
	    CAN_1.IFRL.B.BUF10I=1;
	    CAN_1.IFRL.B.BUF11I=1;
	    break;
	case 91:
	    CAN_1.IFRL.B.BUF12I=1;
	    CAN_1.IFRL.B.BUF13I=1;
	    CAN_1.IFRL.B.BUF14I=1;
	    CAN_1.IFRL.B.BUF15I=1;
	    break;
	case 92:
	    CAN_1.IFRL.B.BUF16I=1;
	    CAN_1.IFRL.B.BUF17I=1;
	    CAN_1.IFRL.B.BUF18I=1;
	    CAN_1.IFRL.B.BUF19I=1;
	    CAN_1.IFRL.B.BUF20I=1;
	    CAN_1.IFRL.B.BUF21I=1;
	    CAN_1.IFRL.B.BUF22I=1;
	    CAN_1.IFRL.B.BUF23I=1;
	    CAN_1.IFRL.B.BUF24I=1;
	    CAN_1.IFRL.B.BUF25I=1;
	    CAN_1.IFRL.B.BUF26I=1;
	    CAN_1.IFRL.B.BUF27I=1;
	    CAN_1.IFRL.B.BUF28I=1;
	    CAN_1.IFRL.B.BUF29I=1;
	    CAN_1.IFRL.B.BUF30I=1;
	    CAN_1.IFRL.B.BUF31I=1;
	    break;
    }

}
