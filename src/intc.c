
#include "common.h"
#include "intc.h"

void dummy (void);
//defined in main.c but made visible here
extern void __external_input_exception(void);


void unhandled_IVOR(uint32 no)
{
    while(TRUE);
}

void unhandled_ISR(void)
{
	while(TRUE);
}

void Interrupt_SW(void)
{
	__asm__ volatile ("" \
	".equ  INTC_IACKR2, 0xFFF48010  	# Interrupt Acknowledge Register address			\n\t" \

	"IVOR4Handler:																			\n\t" \
	"prolog:                     		# PROLOGUE 											\n\t" \
		"e_stwu      r1,-(4*20)(r1)	# Create stack frame and store back chain			\n\t" \
		"e_stmvsrrw  12(r1)           	# Store SRRs (SRR0, SRR1) (must be done before enabling EE)^	\n\t" \
		"e_stmvsprw  (12+(2*4))(r1)	# Store SRRs (CR,LR,CTR,XER)				  	\n\t" \
		"e_stmvgprw  (12+(6*4))(r1)	# Store volatile GPRs (R0, R3-R12)			 	\n\t" \

	    "");
	__asm__ volatile ("bl   __external_input_exception");
	__asm__ volatile ("" \

	".equ  INTC_EOIR2,  0xFFF48018  	# End Of Interrupt Register address				\n\t" \
	"epilog:                    		# EPILOGUE											\n\t" \
        	"mbar																		\n\t" \
	        "se_li   r4,0																		\n\t" \
		"e_lis   r3, INTC_EOIR2@ha      # Load upper half of EIOR address to r4				\n\t" \
		"e_stw   r4, INTC_EOIR2@l(r3)	# Write 0 to INTC_EOIR, address 0xFFF4 8018			\n\t" \
	
		"e_lmvgprw  (12+(6*4))(r1)  														\n\t" \
		"e_lmvsprw  (12+(2*4))(r1)  														\n\t" \
		"e_lmvsrrw  12(r1)	 	# Restore SRR0 and SRR1 				        \n\t" \
		"e_addi       r1,r1,(4*20)   	# Restore space on stack					\n\t" \
		"se_rfi                         # End of Interrupt - re-enables interrupts.			\n\t" \
	    "");

}

/**************************************************************************/
/* branch table for the 16 MPC56xx core interrupts/traps */
/**************************************************************************/
__attribute__((section(".isrTrapTable"))) // removed naked
void IVOR_table(void)
{
	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR0ex:    li  r3,0");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR1ex:    li  r3,1");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR2ex:    li  r3,2");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR3ex:    li  r3,3");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR4ex:    li  r3,4");
	__asm__ volatile ("b   Interrupt_SW");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR5ex:    li  r3,5");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR6ex:    li  r3,6");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR7ex:    li  r3,7");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR8ex:    li  r3,8");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR9ex:    li  r3,9");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR10ex:    li  r3,10");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR11ex:    li  r3,11");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR12ex:    li  r3,12");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR13ex:    li  r3,13");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR14ex:    li  r3,14");
	__asm__ volatile ("b   unhandled_IVOR");

	__asm__ volatile (".align 4");
	__asm__ volatile ("IVOR15ex:    li  r3,15");
	__asm__ volatile ("b   unhandled_IVOR");

}


void initSwIrq4(void)
{
	//INTC.PSR4_5.R = 0x2;							/* Software interrupt 4 IRQ priority = 2 */
}
void SwIrq4Handler(void)
{
/*
  SWirq4Ctr++;		 		 Increment interrupt counter

  LED1_DR = (SWirq4Ctr & 1) != 0;
  LED2_DR = (SWirq4Ctr & 2) != 0;
  LED3_DR = (SWirq4Ctr & 4) != 0;
  LED4_DR = (SWirq4Ctr & 8) != 0;

  byTimeFlag = 1;

  INTC.SSCIR4.B.CLR4 = 1;		 Clear channel's flag
*/
}
void enableIrq(void)
{
  __asm__ volatile("wrteei 1");	    	   /* Enable external interrupts */
}


void dummy (void)
{
   while (1); 					/* Wait forever or for watchdog timeout */
}


#define __mfspr(SprNo)       ({ uint32 ret; __asm__ volatile("mfspr %0, %1":"=r" (ret): "i" (SprNo)); ret;} )
#define __mtspr(SprNo,value) __asm__ volatile("mtspr %0, %1":: "i" (SprNo), "r" (value))



//***********************************************************************
// Name:        INTC_Init
// Parameters:  none
// Returns:     none
// Description:	Configure interrupts handling
//				SW vector mode is used
//
//************************************************************************
void INTC_Init(void)
{

    asm volatile("mtivpr %0":: "r" (IVOR_table));	// Initialize exceptions: only need to load IVPR
    asm volatile("mtivor0 %0":: "r" (0x00));
    asm volatile("mtivor1 %0":: "r" (0x10));
    asm volatile("mtivor2 %0":: "r" (0x20));
    asm volatile("mtivor3 %0":: "r" (0x30));
    asm volatile("mtivor4 %0":: "r" (0x40));		// specifiy the offset from the IVOR_table
    asm volatile("mtivor5 %0":: "r" (0x50));
    asm volatile("mtivor6 %0":: "r" (0x60));
    asm volatile("mtivor7 %0":: "r" (0x70));
    asm volatile("mtivor8 %0":: "r" (0x80));
    asm volatile("mtivor9 %0":: "r" (0x90));
    asm volatile("mtivor10 %0":: "r" (0xA0));
    asm volatile("mtivor11 %0":: "r" (0xb0));
    asm volatile("mtivor12 %0":: "r" (0xc0));
    asm volatile("mtivor13 %0":: "r" (0xd0));
    asm volatile("mtivor14 %0":: "r" (0xe0));
    asm volatile("mtivor15 %0":: "r" (0xf0));
    asm volatile("mtivor32 %0":: "r" (0x00));
    asm volatile("mtivor33 %0":: "r" (0x00));
    asm volatile("mtivor34 %0":: "r" (0x00));


    INTC.MCR.R = 0;    					// Initialize INTC for software vector mode

    INTC.PSR[59].R = 0x05; 				// PIT Channel 0 - Priority register
    INTC.PSR[60].R = 0x05; 				// PIT Channel 0 - Priority register
    INTC.PSR[65].R = 0x06; 
    INTC.PSR[68].R = 0x06;
    INTC.PSR[69].R = 0x06;
    INTC.PSR[70].R = 0x06;
    INTC.PSR[71].R = 0x06;
    INTC.PSR[72].R = 0x06;
    INTC.PSR[88].R = 0x06;
    INTC.PSR[89].R = 0x06;
    INTC.PSR[90].R = 0x06;
    INTC.PSR[91].R = 0x06;
    INTC.PSR[92].R = 0x06;
    

    //set the enable bits or clear the maske bits
    INTC.CPR.R = 0; 		//INTC Current Priority Register for Processor is made 0x00 the lowest

    //enable global interrupts
    enableIrq();
}
