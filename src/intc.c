
#include "common.h"
#include "intc.h"

void dummy (void);
extern void PIT_ISR(void);
extern void __external_input_exception(void);


//__attribute__ ((naked))
void unhandled_IVOR(uint32 no)
{
    while(TRUE);
}

//__attribute__ ((naked))
void unhandled_ISR(void)
{
	while(TRUE);
}

//__attribute__ ((naked))
void Interrupt_SW(void)
{
	__asm__ volatile ("" \
	".equ  INTC_IACKR2, 0xFFF48010  # Interrupt Acknowledge Register address					\n\t" \

	"IVOR4Handler:																			\n\t" \
	"prolog:                     		# PROLOGUE 											\n\t" \
		"e_stwu      r1,-(4*20)(r1)		# Create stack frame and store back chain			\n\t" \
		"e_stmvsrrw  12(r1)           	# Store SRRs (SRR0, SRR1) (must be done before enabling EE)\n\t" \
		"e_stmvsprw  (12+(2*4))(r1)		# Store SRRs (CR,LR,CTR,XER)				  		\n\t" \
	    "e_stmvgprw  (12+(6*4))(r1)		## Store volatile GPRs (R0, R3-R12)			 		\n\t" \

/*
 - 	    "e_lis    r3, INTC_IACKR2@h     	# Store address of IACKR in r3					\n\t" \
 - 	    "e_or2i   r3, INTC_IACKR2@l															\n\t" \
 - 	    "e_lwz    r3, 0(r3)     		# Store contents of IACKR in r3 (this is vector table address) \n\t" \
 - 	    "e_lwz    r0, 0(r3)      		# Read ISR address from ISR Vector Table address	\n\t" \
 - 
 - 	    "mtLR   r0            			# Store ISR address to LR to use for branching later\n\t" \
 - 
 - 	    "wrteei 1      					# Set MSR[EE]=1 (must wait a couple clocks after reading IACKR)\n\t" \
 - 	    "se_blrl						# Branch to ISR, but return here					\n\t" \*/
	    "");
	    __asm__ volatile ("bl   __external_input_exception");
	    __asm__ volatile ("" \
   		".equ  INTC_EOIR2,  0xFFF48018  # End Of Interrupt Register address					\n\t" \
		"epilog:                    	# EPILOGUE											\n\t" \
		"                               # STEP 6 :  RESTORE CONTEXT							\n\t" \
/*		"mbar 0                         # Ensure interrupt flag has finished clearing		\n\t" \
 - 		"                               # before writing to INTC_EIOR						\n\t" \
 - 
 - 
 - 	    "mtcrf  0xff, r0																	\n\t" \
 - 	    "wrteei 0                    	# Disable interrupts								\n\t" \*/

	    "se_li   r4,0																		\n\t" \
	    "e_lis   r3, INTC_EOIR2@ha      # Load upper half of EIOR address to r4				\n\t" \
	    "e_stw   r4, INTC_EOIR2@l(r3)	# Write 0 to INTC_EOIR, address 0xFFF4 8018			\n\t" \


	    "e_lmvgprw  (12+(6*4))(r1)  														\n\t" \
		"e_lmvsprw  (12+(2*4))(r1)  														\n\t" \
		"e_lmvsrrw  12(r1)				# Restore SRR0 and SRR1 				        	\n\t" \
		"e_addi       r1,r1,(4*20)   	# Restore space on stack							\n\t" \
	    "se_rfi                         # End of Interrupt - re-enables interrupts.			\n\t" \
	    "");
	    //changed eaddi       r1,r1,(4*20) to e_addi       r1,r1,(4*20)
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


const uint32 IsrVectorTable[] __attribute__ ((section(".interrupt_table"),aligned (2048))) = {
	(uint32) &dummy,	// 0
	(uint32) &dummy,	// 1
	(uint32) &dummy,	// 2
	(uint32) &dummy,	// 3
	(uint32) &dummy,	// 4	- SwIrq4Handler
	(uint32) &dummy,	// 5
	(uint32) &dummy,	// 6
	(uint32) &dummy,	// 7
	(uint32) &dummy,	// 8
	(uint32) &dummy,	// 9
	(uint32) &dummy,	// 10
	(uint32) &dummy,	// 11
	(uint32) &dummy,	// 12
	(uint32) &dummy,	// 13
	(uint32) &dummy,	// 14
	(uint32) &dummy,	// 15
	(uint32) &dummy,	// 16
	(uint32) &dummy,	// 17
	(uint32) &dummy,	// 18
	(uint32) &dummy,	// 19
	(uint32) &dummy,	// 20
	(uint32) &dummy,	// 21
	(uint32) &dummy,	// 22
	(uint32) &dummy,	// 23
	(uint32) &dummy,	// 24
	(uint32) &dummy,	// 25
	(uint32) &dummy,	// 26
	(uint32) &dummy,	// 27
	(uint32) &dummy,	// 28
	(uint32) &dummy,	// 29
	(uint32) &dummy,	// 30
	(uint32) &dummy,	// 31
	(uint32) &dummy,	// 32
	(uint32) &dummy,	// 33
	(uint32) &dummy,	// 34
	(uint32) &dummy,	// 35
	(uint32) &dummy,	// 36
	(uint32) &dummy,	// 37
	(uint32) &dummy,	// 38
	(uint32) &dummy,	// 39
	(uint32) &dummy,	// 40
	(uint32) &dummy,	// 41
	(uint32) &dummy,	// 42
	(uint32) &dummy,	// 43
	(uint32) &dummy,	// 44
	(uint32) &dummy,	// 45
	(uint32) &dummy,	// 46
	(uint32) &dummy,	// 47
	(uint32) &dummy,	// 48
	(uint32) &dummy,	// 49
	(uint32) &dummy,	// 50
	(uint32) &dummy,	// 51
	(uint32) &dummy,	// 52
	(uint32) &dummy,	// 53
	(uint32) &dummy,	// 54
	(uint32) &dummy,	// 55
	(uint32) &dummy,	// 56
	(uint32) &dummy,	// 57
	(uint32) &dummy,	// 58
	(uint32) &PIT_ISR,	// IRQ 059, PI timer channel 0
	(uint32) &PIT_ISR,	// IRQ 060, PI timer channel 1
	(uint32) &dummy,	// IRQ 061, PI timer channel 2
	(uint32) &dummy,	// 62
	(uint32) &dummy,	// 63
	(uint32) &dummy,	// 64
	(uint32) &dummy,	// 65
	(uint32) &dummy,	// 66
	(uint32) &dummy,	// 67
	(uint32) &dummy,	// 68
	(uint32) &dummy,	// 69
	(uint32) &dummy,	// 70
	(uint32) &dummy,	// 71
	(uint32) &dummy,	// 72
	(uint32) &dummy,	// 73
	(uint32) &dummy,	// 74
	(uint32) &dummy,	// 75
	(uint32) &dummy,	// 76
	(uint32) &dummy,	// 77
	(uint32) &dummy,	// 78
	(uint32) &dummy,	// 79
	(uint32) &dummy,	// 80
	(uint32) &dummy,	// 81
	(uint32) &dummy,	// 82
	(uint32) &dummy,	// 83
	(uint32) &dummy,	// 84
	(uint32) &dummy,	// 85
	(uint32) &dummy,	// 86
	(uint32) &dummy,	// 87
	(uint32) &dummy,	// 88
	(uint32) &dummy,	// 89
	(uint32) &dummy,	// 90
	(uint32) &dummy,	// 91
	(uint32) &dummy,	// 92
	(uint32) &dummy,	// 93
	(uint32) &dummy,	// 94
	(uint32) &dummy,	// 95
	(uint32) &dummy,	// 96
	(uint32) &dummy,	// 97
	(uint32) &dummy,	// 98
	(uint32) &dummy,	// 99
	(uint32) &dummy,	// 100
	(uint32) &dummy,	// 101
	(uint32) &dummy,	// 102
	(uint32) &dummy,	// 103
	(uint32) &dummy,	// 104
	(uint32) &dummy,	// 105
	(uint32) &dummy,	// 106
	(uint32) &dummy,	// 107
	(uint32) &dummy,	// 108
	(uint32) &dummy,	// 109
	(uint32) &dummy,	// 110
	(uint32) &dummy,	// 111
	(uint32) &dummy,	// 112
	(uint32) &dummy,	// 113
	(uint32) &dummy,	// 114
	(uint32) &dummy,	// 115
	(uint32) &dummy,	// 116
	(uint32) &dummy,	// 117
	(uint32) &dummy,	// 118
	(uint32) &dummy,	// 119
	(uint32) &dummy,	// 120
	(uint32) &dummy,	// 121
	(uint32) &dummy,	// 122
	(uint32) &dummy,	// 123
	(uint32) &dummy,	// 124
	(uint32) &dummy,	// 125
	(uint32) &dummy,	// 126
	(uint32) &dummy,	// 127
	(uint32) &dummy,	// 128
	(uint32) &dummy,	// 129
	(uint32) &dummy,	// 130
	(uint32) &dummy,	// 131
	(uint32) &dummy,	// 132
	(uint32) &dummy,	// 133
	(uint32) &dummy,	// 134
	(uint32) &dummy,	// 135
	(uint32) &dummy,	// 136
	(uint32) &dummy,	// 137
	(uint32) &dummy,	// 138
	(uint32) &dummy,	// 139
	(uint32) &dummy,	// 140
	(uint32) &dummy,	// 141
	(uint32) &dummy,	// 142
	(uint32) &dummy,	// 143
	(uint32) &dummy,	// 144
	(uint32) &dummy,	// 145
	(uint32) &dummy,	// 146
	(uint32) &dummy,	// 147
	(uint32) &dummy,	// 148
	(uint32) &dummy,	// 149
	(uint32) &dummy,	// 150
	(uint32) &dummy,	// 151
	(uint32) &dummy,	// 152
	(uint32) &dummy,	// 153
	(uint32) &dummy,	// 154
	(uint32) &dummy,	// 155
	(uint32) &dummy,	// 156
	(uint32) &dummy,	// 157
	(uint32) &dummy,	// 158
	(uint32) &dummy,	// 159
	(uint32) &dummy,	// 160
	(uint32) &dummy,	// 161
	(uint32) &dummy,	// 162
	(uint32) &dummy,	// 163
	(uint32) &dummy,	// 164
	(uint32) &dummy,	// 165
	(uint32) &dummy,	// 166
	(uint32) &dummy,	// 167
	(uint32) &dummy,	// 168
	(uint32) &dummy,	// 169
	(uint32) &dummy,	// 170
	(uint32) &dummy,	// 171
	(uint32) &dummy,	// 172
	(uint32) &dummy,	// 173
	(uint32) &dummy,	// 174
	(uint32) &dummy,	// 175
	(uint32) &dummy,	// 176
	(uint32) &dummy,	// 177
	(uint32) &dummy,	// 178
	(uint32) &dummy,	// 179
	(uint32) &dummy,	// 180
	(uint32) &dummy,	// 181
	(uint32) &dummy,	// 182
	(uint32) &dummy,	// 183
	(uint32) &dummy,	// 184
	(uint32) &dummy,	// 185
	(uint32) &dummy,	// 186
	(uint32) &dummy,	// 187
	(uint32) &dummy,	// 188
	(uint32) &dummy,	// 189
	(uint32) &dummy,	// 190
	(uint32) &dummy,	// 191
	(uint32) &dummy,	// 192
	(uint32) &dummy,	// 193
	(uint32) &dummy,	// 194
	(uint32) &dummy,	// 195
	(uint32) &dummy,	// 196
	(uint32) &dummy,	// 197
	(uint32) &dummy,	// 198
	(uint32) &dummy,	// 199
	(uint32) &dummy,	// 200
	(uint32) &dummy,	// 201
	(uint32) &dummy,	// 202
	(uint32) &dummy,	// 203
	(uint32) &dummy,	// 204
	(uint32) &dummy,	// 205
	(uint32) &dummy,	// 206
	(uint32) &dummy,	// 207
	(uint32) &dummy,	// 208
	(uint32) &dummy,	// 209
	(uint32) &dummy,	// 210
	(uint32) &dummy,	// 211
	(uint32) &dummy,	// 212
	(uint32) &dummy,	// 213
	(uint32) &dummy,	// 214
	(uint32) &dummy,	// 215
	(uint32) &dummy,	// 216
	(uint32) &dummy,	// 217
	(uint32) &dummy,	// 218
	(uint32) &dummy,	// 219
	(uint32) &dummy,	// 220
	(uint32) &dummy,	// 221
	(uint32) &dummy,	// 222
	(uint32) &dummy,	// 223
	(uint32) &dummy,	// 224
	(uint32) &dummy,	// 225
	(uint32) &dummy,	// 226 PIT0 
	(uint32) &dummy,	// 227
	(uint32) &dummy,	// 228
	(uint32) &dummy,	// 229
	(uint32) &dummy,	// 230
	(uint32) &dummy,	// 231
	(uint32) &dummy,	// 232
	(uint32) &dummy,	// 233
	(uint32) &dummy,	// 234
	(uint32) &dummy,	// 235
	(uint32) &dummy,	// 236
	(uint32) &dummy,	// 237
	(uint32) &dummy,	// 238
	(uint32) &dummy,	// 239
	(uint32) &dummy,	// 240
	(uint32) &dummy,	// 241
	(uint32) &dummy,	// 242
	(uint32) &dummy,	// 243
	(uint32) &dummy,	// 244
	(uint32) &dummy,	// 245
	(uint32) &dummy,	// 246
	(uint32) &dummy,	// 247
	(uint32) &dummy,	// 248
	(uint32) &dummy,	// 249
	(uint32) &dummy,	// 250
	(uint32) &dummy,	// 251
	(uint32) &dummy,	// 252
	(uint32) &dummy,	// 253
	(uint32) &dummy,	// 254
	(uint32) &dummy,	// 255
};

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
//	uint32 coreNo;
//    coreNo=0;
//    __mtspr(63,(uint32)&__IVPR_BASE_); 						/*Movin IVPR base address to spr reg IVPR=63*/
//    coreNo = __mfspr(286);  								/*PIR for core ID*/
//	__asm__ volatile ("mtivpr  %0"::"r" (IVOR_table));

    asm volatile("mtivpr %0":: "r" (IVOR_table));			// Initialize exceptions: only need to load IVPR
    asm volatile("mtivor4 %0":: "r" (0x40));		// specifiy the offset from the IVOR_table

    INTC.MCR.R = 0;    										// Initialize INTC for software vector mode
    //VTES_PRC0 in intc bcr register
    INTC.IACKR.R = (uint32_t) &IsrVectorTable[0];
    INTC.PSR[59].R = 0x05; 	// PIT Channel 0 - Priority register
    INTC.PSR[60].R = 0x05; 	// PIT Channel 0 - Priority register
    //set the enable bits or clear the maske bits
    INTC.CPR.R = 0; 		//INTC Current Priority Register for Processor is made 0x00 the lowest
    //enable global interrupts
//    register uint16 *Prio_Reg_Pointer;
//    register uint32 i;
//    Prio_Reg_Pointer = (uint16*) & INTC.PSR0_1.R;
//
//    for(i=0;i<=856;i++)
//    {
//        *Prio_Reg_Pointer = ((i & 0x3F) | 0x2000) ; /*All Interrupts are serviced by Core_2*/
//        Prio_Reg_Pointer++;
//    }
//	_EI;
    enableIrq();
}
