/*====================================================================
* Project:  Board Support Package (BSP) examples
* Function: empty main function
*
* Copyright HighTec EDV-Systeme GmbH 1982-2013
*====================================================================*/
#include <stdlib.h>
#include "common.h"
#include "me.h"
#include "interrupts56xx.h"
#include "flexcan.h"



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

void main(void);
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

void main(void)
{
	int i;

	AIPS_Init();			// Initialize AIPS bridge
	ME_Init();				// Initialize all basic modules - ME, CGM, ...
	//INTC_Init();			// Initialize interrupt controller
	PIT_Init();



	PORT_PIN_SET2OUTPUT(PORT_PIN_B6); // clkout

	// Initialize GPIO pin D[4] ID 9 (LQFP144) as output
	PORT_PIN_SET2OUTPUT(PORT_PIN_D4);
	PORT_PIN_SET2OUTPUT(PORT_PIN_C13);
	PORT_PIN_SET2OUTPUT(PORT_PIN_C14);
	while(1)
	{
		// toggle pin 129
		SIU.GPDO[PORT_PIN_D4].R = ~SIU.GPDO[PORT_PIN_D4].R;
		SIU.GPDO[PORT_PIN_C13].R = ~SIU.GPDO[PORT_PIN_C13].R;
		for (i = 0; i < 1000000;i++)
		{
			asm("nop");
		}
	}
}


