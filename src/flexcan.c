/*******************************************************************************
| File Name    : flexcan.c
| Description  : This file contains all CAN functions.
| Group        : APG - JDP
|===============================================================================
|                C O P Y R I G H T
|===============================================================================
| (C) COPYRIGHT 2007 STMicroelectronics
| THE SOFTWARE INCLUDED IN THIS FILE IS FOR GUIDANCE ONLY. ST MICROELECTRONICS
| SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES
| WITH RESPECT TO ANY CLAIMS ARISING FROM USE OF THIS SOFTWARE.
|===============================================================================
|                A U T H O R    I D E N T I T Y
|===============================================================================
| Initials   Name                          Company
| --------   ----------------------------  -------------------------------------
| CA         Claude ANGUILLE               STMicroelectronics
|===============================================================================
|                R E V I S I O N    H I S T O R Y
|===============================================================================
| Date         Ver   Author  Description
| -----------  ----  ------  ---------------------------------------------------
| 10-Mar-2007  1.0   CA      Created.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "typedefs.h"
//#include "mpc5516.h"
#include   "common.h"
//#include "can_defs.h"
#include "flexcan.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define FlexCAN_0_PB0_PB1
#define FlexCAN_1_PC10_PC11
//#define FlexCAN_1_PF14_PF15
//#define FlexCAN_1_PF14_PC3
#define FlexCAN_2_PE8_PE9
//#define FlexCAN_2_PF8_PF9
//#define FlexCAN_3
//#define FlexCAN_4
//#define FlexCAN_5

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/*extern CUHEAD_CMD_STRING can; //defined in CAN_Validation.c
 - extern CAN_2onfig CAN_0TX, CAN_1TX, CAN_2TX, CAN_0RX, CAN_1RX, CAN_2RX; //defined in CAN_Validation.c
 - uint8_t FIRST_CANTxA, FIRST_CANTxB, FIRST_CANTxC;
 - extern uint8_t TEST_MASK, TEST_CLKSRC, TEST_SMP, TEST_MASK14, TEST_MASK15, TEST_MDIS; //defined in CAN_Validation.c
 - extern UINT32 fail_mode [9];
 - extern uint8_t CanB;*/


/*******************************************************************************
* Function Name : CAN_SetupPads
* Description   : This routine configures FlexCAN modules 0, 1 and 2 pins
* Input         : .
* Output        : .
* Return        : .
* Comments	: use #define FlexCAN_0, FlexCAN_1 & FlexCAN_2 in this file
*******************************************************************************/
void CAN_SetupPads(void)
{
    /* Setup FlexCAN 0 pins */
    /* TX (PB0) PA = 1 (AF1) / OBE = 1 / WPE = WPS = SRC (min value) = 0 */
 	SIU.PCR[16].R  = 0x0600;
    /* RX (PB1) IBE = 1 */
    SIU.PCR[17].B.IBE = 0x1;
    /* Setup FlexCAN 1 pins */
    /* TX (PC10) PA = 1 (AF1) / OBE = 1 / WPE = WPS = SRC (min value) = 0 */
   // SIU.PCR[42].R  = 0x0600;
    /* RX (PC11) IBE = 1 & PADSEL_0 = 1 */
    //SIU.PCR[43].B.IBE = 0x1;
    SIU.PSMI[0].B.PADSEL = 0x1;
    SIU.PSMI[33].B.PADSEL = 0x1;
}


/*******************************************************************************
* Function Name : CAN_Init
* Description   : This routine initializes CAN module (bit timing, masks, etc.
* Input         : CAN module number (MODULE_A, MODULE_B, or MODULE_C)
* Output        : .
* Return        : .
*******************************************************************************/
void CAN_Init (uint8_t module, uint8_t sysclk)
{
    uint32_t i;
    
    /** Module A *******************************/
    if (module == MODULE_A){
	CAN_0.MCR.B.MDIS = 0;	/* enable CAN peripheral */
	/* Configure CAN MCR registers */
	CAN_0.MCR.B.SOFTRST = 1; //bit 6
		
	while(CAN_0.MCR.B.SOFTRST == 1){};		
		
	CAN_0.MCR.B.FRZ = 1;  //bit 1
	CAN_0.MCR.B.HALT = 1; //bit 3		
	CAN_0.MCR.B.MAXMB = 0x3F; //bit 26 - 31
	//CAN_0.MCR.B.BCC = 0x1;	/* backwards compatibility disable */

	SetBaudRate(MODULE_A, 100000, sysclk);
		
	/* Configure Remaining Bits of CR */
	CAN_0.CR.B.BOFFMSK = 0;
	CAN_0.CR.B.ERRMSK = 0;	
	CAN_0.CR.B.LPB = 0;
	CAN_0.CR.B.SMP = 0;
	CAN_0.CR.B.BOFFREC = 0;
	CAN_0.CR.B.TSYN = 0;
	CAN_0.CR.B.LOM = 0;
	CAN_0.CR.B.LBUF = 1;	/* lowest number buffer is transmitted first */		
	CAN_0.CR.B.CLKSRC = 0;	/* clock = oscillator clock */

	/* Initialize/Clear all memory buffers */
	for (i = 0; i < 64; i++)
	{
	    /* Put MB's in inactive state */
	    CAN_0.BUF[i].CS.R = 0x00000000;
				
	    /* Clear ID */
	    CAN_0.BUF[i].ID.R = 0x00000000;
		
	    /* Clear Data fields */
	    CAN_0.BUF[i].DATA.W[0] = 0x00000000;
	    CAN_0.BUF[i].DATA.W[1] = 0x00000000;
	}
		
	/* Clear IFLAG registers */
	CAN_0.IFRL.R = 0xFFFFFFFF;
	CAN_0.IFRH.R = 0xFFFFFFFF;

	/* Configure IMASK Registers to enable interrupt requests */
	CAN_0.IMRL.R = 0xFFFFFFFF;
	CAN_0.IMRH.R = 0xFFFFFFFF;
		
	//Initialize MASK registers to check every bit
	CAN_0.RXGMASK.R = 0x1FFFFFFF;
	CAN_0.RX14MASK.R = 0x1FFFFFFF;
	CAN_0.RX15MASK.R = 0x1FFFFFFF;
		    
	CAN_0.MCR.B.FRZ = 0;  //enable the module fully
	CAN_0.MCR.B.AEN = 0;
	CAN_0.ESR.B.BOFFINT = 0;
	CAN_0.ESR.B.ERRINT = 0; 
	CAN_0.MCR.B.HALT = 0x0;   //Clear Halt Bit
    } /* end if */ 

    /** Module B *******************************/
	if (module == MODULE_B)
	{
		CAN_1.MCR.B.MDIS = 0;	/* enable CAN peripheral */
		// Configure CAN MCR registers
		CAN_1.MCR.B.SOFTRST = 1; //bit 6

		while(CAN_1.MCR.B.SOFTRST == 1){};

		CAN_1.MCR.B.FRZ = 1;  //bit 1
		CAN_1.MCR.B.HALT = 1; //bit 3
		CAN_1.MCR.B.MAXMB = 0X3F; //bit 26 -31
		//CAN_1.MCR.B.BCC = 0x1;	/* backwards compatibility disable */
	
		SetBaudRate(MODULE_B, 500000, sysclk);

		// Configure Remaining Bits of CR
		CAN_1.CR.B.BOFFMSK = 0;
		CAN_1.CR.B.ERRMSK = 0;
		CAN_1.CR.B.LPB = 0;
		CAN_1.CR.B.SMP = 0;
		CAN_1.CR.B.BOFFREC = 0;
		CAN_1.CR.B.TSYN = 0;
		CAN_1.CR.B.LOM = 0;
		CAN_1.CR.B.LBUF = 1;	/* lowest number buffer is transmitted first */
		CAN_1.CR.B.CLKSRC = 0;	/* clock = oscillator clock */
		
		/* Initialize/Clear all memory buffers */
		for (i = 0; i < 64; i++)
		{
			/* Put MB's in inactive state */
			CAN_1.BUF[i].CS.R = 0x00000000;

			/* Clear ID */
			CAN_1.BUF[i].ID.R = 0x00000000;

			/* Clear Data fields */
			CAN_1.BUF[i].DATA.W[0] = 0x00000000;
			CAN_1.BUF[i].DATA.W[1] = 0x00000000;
		}
	
		/* Clear IFLAG registers */
		CAN_1.IFRL.R = 0xFFFFFFFF;
		CAN_1.IFRH.R = 0xFFFFFFFF;
	
		/* Configure IMASK Registers to enable interrupt requests */
		CAN_1.IMRL.R = 0xFFFFFFFF;
		CAN_1.IMRH.R = 0xFFFFFFFF;

		//Initialize MASK registers to check every bit
		CAN_1.RXGMASK.R = 0x1FFFFFFF;
		CAN_1.RX14MASK.R = 0x1FFFFFFF;
		CAN_1.RX15MASK.R = 0x1FFFFFFF;

		CAN_1.MCR.B.FRZ = 0;  //enable the module fully
		CAN_1.MCR.B.AEN = 0;
		CAN_1.ESR.B.BOFFINT = 0;
		CAN_1.ESR.B.ERRINT = 0;
		CAN_1.MCR.B.HALT = 0x0;		//Clear Halt Bit
    }
}


/*******************************************************************************
* Function Name : CanRxStart
* Description   : This routine configures Rx buffer to receive data
* Input         : module (MODULE_A, MODULE_B or MODULE_C)
*		: Rx buffer number
* Output        : .
* Return        : .
*******************************************************************************/
void CanRxStart(uint8_t module, uint8_t buffer)
{
    uint16_t timer;

    // Configure Flex CAN_0 MB0, CAN_1 MB1, and CAN_2 MB2 as RECEIVER
	
    if (module == MODULE_A)
    {
	// Write MB Code Field = 0x0 to config as RX inactive	
	CAN_0.BUF[buffer].CS.B.CODE = 0;	
		
	// Write standard MB IDs
/*	if(can.ARX.Type == EXT)
 - 	{
 - 	    CAN_0.BUF[buffer].ID.R = can.ARX.ID;
 - 	}
 - 	else CAN_0.BUF[buffer].ID.B.STD_ID = can.ARX.ID;  /@/@*$Randomize	*/
		
	// Write MB Code Field = 0x4 to config as receive active and empty(Receive)	
	CAN_0.BUF[buffer].CS.B.CODE = 0x4;		
		
	//Unlock Message buffers
	timer = CAN_0.TIMER.R; 
    }

    if (module == MODULE_B)
    {
	// Write MB Code Field = 0x0 to config as RX inactive	
	CAN_1.BUF[buffer].CS.B.CODE = 0;	

	// Write standard MB IDs
/*	if(can.BRX.Type == EXT)
 - 	{
 - 	    CAN_1.BUF[buffer].ID.R = can.BRX.ID;
 - 	}
 - 	else CAN_1.BUF[buffer].ID.B.STD_ID = can.BRX.ID;  /@/@*$Randomize	*/
		
	// Write MB Code Field = 0x4 to config as receive active and empty(Receive)	
	CAN_1.BUF[buffer].CS.B.CODE = 0x4;		
		
	//Unlock Message buffers
	timer = CAN_1.TIMER.R; 
    }

/*    if (module == MODULE_C)
 -     {
 - 	// Write MB Code Field = 0x0 to config as RX inactive	
 - 	CAN_2.BUF[buffer].CS.B.CODE = 0;	
 - 		
 - 	// Write standard MB IDs
 - 	if(can.CRX.Type == EXT)
 - 	{
 - 	    CAN_2.BUF[buffer].ID.R = can.CRX.ID;
 - 	}
 - 	else CAN_2.BUF[buffer].ID.B.STD_ID = can.CRX.ID;  /@/@*$Randomize	
 - 	
 - 	// Write MB Code Field = 0x4 to config as receive active and empty(Receive)	
 - 	CAN_2.BUF[buffer].CS.B.CODE = 0x4;		
 - 		
 - 	//Unlock Message buffers
 - 	timer = CAN_2.TIMER.R; 
 -     }*/
}


/*******************************************************************************
FUNCTION        : CAN_Tx
PURPOSE         : config TX buffers and start transmissions
INPUTS NOTES    : module - MODULE_A, MODULE_B, or MODULE_C.
                  data - data to transmit
		  data_inc - data increment
		  length - length in bytes
		  buffer - transmit buffer
RETURNS NOTES   : NA
GENERAL NOTES   :  
*******************************************************************************/ 
void CAN_Tx(uint8_t module, uint32_t data, uint8_t data_inc, uint8_t length, uint8_t buf)
{	
    uint16_t i, timer;
 
	if (module == MODULE_A)
	{
	    // Clear Data fields
	    CAN_0.BUF[buf].DATA.W[0] = 0x00000000;
	    CAN_0.BUF[buf].DATA.W[1] = 0x00000000;
	    // Hold the transmit buffer inactive
	    CAN_0.BUF[buf].CS.B.CODE = 0x8;
	    CAN_0.BUF[buf].CS.B.SRR = 1;
	    CAN_0.BUF[buf].CS.B.RTR = 0x0;
	    CAN_0.BUF[buf].CS.B.IDE = 0x0;
	    // Write standard MB IDs
	    CAN_0.BUF[buf].ID.R = (uint32_t)(data << 18);
	    //Write data 
	    CAN_0.BUF[buf].DATA.W[0] = (uint32_t)data;
	    // Write length = 0x4 (4 Bytes long), Code = C (Transmit)
	    CAN_0.BUF[buf].CS.B.LENGTH = length;
	    CAN_0.BUF[buf].CS.B.CODE = 0xC;
	    while (CAN_0.BUF[buf].CS.B.CODE != 0x8);
	    
	} /* end if */

	if (module == MODULE_B) {
	    // Clear Data fields
	    CAN_1.BUF[buf].DATA.W[0] = 0x00000000;
	    CAN_1.BUF[buf].DATA.W[1] = 0x00000000;
	    // Hold the transmit buffer inactive
	    CAN_1.BUF[buf].CS.B.CODE = 0x8;
	    CAN_1.BUF[buf].CS.B.SRR = 0x1;		
	    CAN_1.BUF[buf].CS.B.RTR = 0x0;
	    CAN_1.BUF[buf].CS.B.IDE = 0x0;		
	    // Write standard MB IDs
	    CAN_1.BUF[buf].ID.R = (uint32_t)(data << 18);
	    //Write data 
	    CAN_1.BUF[buf].DATA.W[0] = (uint32_t)data;
	    // Write length = 0x4 (4 Bytes long), Code = C (Transmit)
	    CAN_1.BUF[buf].CS.B.LENGTH = length;
	    CAN_1.BUF[buf].CS.B.CODE = 0xC;
	    while (CAN_1.BUF[buf].CS.B.CODE != 0x8);
	} /* end if */
}


/*******************************************************************************
FUNCTION        : Rx_check
PURPOSE         : check to see if correct data is received
INPUTS NOTES    : module - choose MODULE_A, MODULE_B or MODULE_C.
				  buffer - RX buffer
				  data - expected data
				  data_inc - data increment
				  length - expected number of data bytes
RETURNS NOTES   : PASS if data matches expected, FAIL otherwise.
GENERAL NOTES   : 
*******************************************************************************/ 
/*uint8_tRX_check (uint8_tmodule, uint8_tbuffer, uint8_tdata, uint8_tdata_inc, uint8_tlength){
 - 
 - 
 - UINT32 i;
 - UINT16 code_value;
 - static uint8_tvalue;
 - 
 - /@/@*$******** Check for interrupts and data  ************$*@/@
 - 	
 - 	
 - 
 - 	if (module == MODULE_A){
 - 		
 - 		if ((can.ATX.Type == REMOTE) || (can.ATX.Type == RTR_EXT)){  //Delay needed to allow Code field to be updated if using Remote Frames
 - 			for (i = 0; i < REMOTE_DELAY; i++) ;
 - 		}
 - 		
 - 		code_value = CAN_0.BUF[buffer].CS.B.CODE;		
 - 		
 - 		if (code_value == 0x2){	
 - 			//Check to see if correct data
 - 			
 - 			for (i = 0; i < length; i++){
 - 
 - 				if(CAN_0.BUF[buffer].DATA.B[i] == data){
 - 					data += data_inc;					
 - 				}
 - 				else {
 - 					can.ARX.ID += can.ARX.IDInc;
 - 					// Write MB IDs
 - 					if ((can.ATX.Type == REMOTE) || (can.ATX.Type == RTR_EXT)){
 - 						CAN_Tx_start(MODULE_A, can.ATX.Data0, can.ATX.DataInc, can.ATX.MsgLen, CAN_0TX.BUF);
 - 					}
 - 					else CAN_Rx_start(MODULE_A, CAN_0RX.BUF);
 - 					fail_mode[0] += 1; @/@*$ fail_mode array used for debug.  wrong data CAN A $*@/@
 - 					return FAIL; 
 - 				}
 - 			}
 - 			
 - 			can.ARX.ID += can.ARX.IDInc;
 - 			if ((can.ATX.Type == REMOTE) || (can.ATX.Type == RTR_EXT)){
 - 				CAN_Tx_start(MODULE_A, can.ATX.Data0, can.ATX.DataInc, can.ATX.MsgLen, CAN_0TX.BUF);
 - 			}
 - 			else CAN_Rx_start(MODULE_A, CAN_0RX.BUF);
 - 			return PASS;				
 - 		}			
 - 	
 - 		else {
 - 			can.ARX.ID += can.ARX.IDInc;
 - 			if ((can.ATX.Type == REMOTE) || (can.ATX.Type == RTR_EXT)){
 - 				CAN_Tx_start(MODULE_A, can.ATX.Data0, can.ATX.DataInc, can.ATX.MsgLen, CAN_0TX.BUF);
 - 			}
 - 			else CAN_Rx_start(MODULE_A, CAN_0RX.BUF);
 - 			fail_mode[1] += 1;  @/@*$ fail_mode array used for debug.  incorrect code value CAN A $*@/@
 - 			return FAIL;
 - 		}
 - 		
 - 	
 - 	}
 - 
 - 	if (module == MODULE_B){
 - 		
 - 		if ((can.BTX.Type == REMOTE) || (can.BTX.Type == RTR_EXT)){  //Delay needed to allow Code field to be updated if using Remote Frames
 - 			for (i = 0; i < REMOTE_DELAY; i++) ;
 - 		}		
 - 		
 - 		code_value = CAN_1.BUF[buffer].CS.B.CODE;								
 - 	
 - 		if (code_value == 0x2){	
 - 			//Check to see if correct data
 - 			
 - 
 - 			
 - 			for (i = 0; i < length; i++){
 - 
 - 				if(CAN_1.BUF[buffer].DATA.B[i] == data){
 - 					data += data_inc;
 - 				}
 - 				else {
 - 					can.BRX.ID += can.BRX.IDInc;
 - 					if ((can.BTX.Type == REMOTE) || (can.BTX.Type == RTR_EXT)){
 - 						CAN_Tx_start(MODULE_B, can.BTX.Data0, can.BTX.DataInc, can.BTX.MsgLen, CAN_1TX.BUF);
 - 					}
 - 					else CAN_Rx_start(MODULE_B, CAN_1RX.BUF);
 - 					fail_mode[2] += 1;  @/@*$ fail_mode array used for debug.  wrong data CAN B $*@/@
 - 					return FAIL;
 - 				}
 - 			}
 - 			can.BRX.ID += can.BRX.IDInc;
 - 			if ((can.BTX.Type == REMOTE) || (can.BTX.Type == RTR_EXT)){
 - 				CAN_Tx_start(MODULE_B, can.BTX.Data0, can.BTX.DataInc, can.BTX.MsgLen, CAN_1TX.BUF);
 - 			}
 - 			else CAN_Rx_start(MODULE_B, CAN_1RX.BUF);
 - 			return PASS;				
 - 		}			
 - 
 - 		else {
 - 			can.BRX.ID += can.BRX.IDInc;
 - 			// Write MB IDs
 - 			if ((can.BTX.Type == REMOTE) || (can.BTX.Type == RTR_EXT)){
 - 				CAN_Tx_start(MODULE_B, can.BTX.Data0, can.BTX.DataInc, can.BTX.MsgLen, CAN_1TX.BUF);
 - 			}
 - 			else CAN_Rx_start(MODULE_B, CAN_1RX.BUF);
 - 			fail_mode[3] += 1;  @/@*$ fail_mode array used for debug.  incorrect code value CAN B $*@/@
 - 			return FAIL; 
 - 		}
 - 	}
 - 
 - 	if (module == MODULE_C){
 - 		
 - 		if ((can.CTX.Type == REMOTE) || (can.CTX.Type == RTR_EXT)){  //Delay needed to allow Code field to be updated if using Remote Frames
 - 			for (i = 0; i < REMOTE_DELAY; i++) ;
 - 		}		
 - 		
 - 		code_value = CAN_2.BUF[buffer].CS.B.CODE;								
 - 	
 - 		if (code_value == 0x2){	
 - 			
 - 			//Check to see if correct data			
 - 			for (i = 0; i < length; i++){
 - 
 - 				if(CAN_2.BUF[buffer].DATA.B[i] == data){
 - 					data += data_inc;
 - 				}
 - 				else {
 - 					can.CRX.ID += can.CRX.IDInc;
 - 					if ((can.CTX.Type == REMOTE) || (can.CTX.Type == RTR_EXT)){
 - 						CAN_Tx_start(MODULE_C, can.CTX.Data0, can.CTX.DataInc, can.CTX.MsgLen, CAN_2TX.BUF);
 - 					}
 - 					else CAN_Rx_start(MODULE_C, CAN_2RX.BUF);
 - 					fail_mode[4] += 1;  @/@*$ fail_mode array used for debug.  wrong data CAN C $*@/@
 - 					return FAIL;
 - 				}
 - 			}
 - 			can.CRX.ID += can.CRX.IDInc;
 - 			// Write MB IDs		
 - 			if ((can.CTX.Type == REMOTE) || (can.CTX.Type == RTR_EXT)){
 - 				CAN_Tx_start(MODULE_C, can.CTX.Data0, can.CTX.DataInc, can.CTX.MsgLen, CAN_2TX.BUF);
 - 			}
 - 			else CAN_Rx_start(MODULE_C, CAN_2RX.BUF);			
 - 			return PASS;				
 - 		}			
 - 
 - 		else {
 - 			can.CRX.ID += can.CRX.IDInc;
 - 			if ((can.CTX.Type == REMOTE) || (can.CTX.Type == RTR_EXT)){
 - 				CAN_Tx_start(MODULE_C, can.CTX.Data0, can.CTX.DataInc, can.CTX.MsgLen, CAN_2TX.BUF);
 - 			}
 - 			else CAN_Rx_start(MODULE_C, CAN_2RX.BUF);	
 - 			fail_mode[5] += 1; @/@*$ fail_mode array used for debug.  incorrect code value CAN C $*@/@
 - 			return FAIL;
 - 		}
 - 		
 - 	}
 - 	
 -   return FAIL;		 @/@*$ shouldn't get here $*@/@
 - 
 - }*/


/*******************************************************************************
FUNCTION        : Tx_Check
PURPOSE         : check to see if iflag bit is set for tx buffer
INPUTS NOTES    : module - choose MODULE_A, MODULE_B or MODULE_C.
                  buffer - tx buffer.
RETURNS NOTES   : PASS if flag is set, FAIL otherwise.
GENERAL NOTES   : Clears the iflag if set
*******************************************************************************/ 
/*uint8_tTX_check (uint8_tmodule, uint8_tbuffer){
 - 
 - 
 - 	/@/@*$******** Check for interrupts and data  ************$*@/@
 - 	
 - 	if (module == MODULE_A){		
 - 			
 - 		if (check_iflag(MODULE_A, buffer, TX)){
 - 			return PASS;
 - 		}				
 - 
 - 		return FAIL;
 - 	}
 - 
 - 	if (module == MODULE_B){		
 - 				
 - 		if (check_iflag(MODULE_B, buffer, TX)){
 - 			return PASS;
 - 					
 - 		}
 - 		
 - 		return FAIL;
 - 	}
 - 
 - 	if (module == MODULE_C){
 - 		
 - 		if (check_iflag(MODULE_C, buffer, TX)){
 - 			return PASS;
 - 		}			
 - 				
 - 		return FAIL;
 - 	}
 - 	
 - 	  return FAIL;		 @/@*$ shouldn't get here $*@/@
 - 
 - }*/


/*******************************************************************************
FUNCTION        : check_iflag
PURPOSE         : check to see if iflag bit is set for given buffer, and clears
				  the bit if set
INPUTS NOTES    : module - MODULE A, B or C. buffer - 0 to 64. type - RX or TX                 
RETURNS NOTES   : 0 if not set, 1 if set
GENERAL NOTES   :  
*******************************************************************************/ 
/*
 - uint8_tcheck_iflag (uint8_tmodule, uint8_tbuffer, uint8_ttype){
 - 
 - 	UINT32 buf_iflag;	
 - 
 - 
 - 	if(module == MODULE_A){
 - 		
 - 		if (type == TX){
 - 			if (FIRST_CANTxA == 1) { /@/@*$* add comment
 - 				FIRST_CANTxA = 0;
 - 				return 1;
 - 			}   		
 - 		}
 - 
 - 		if (buffer > 31){
 - 			buffer = buffer - 32;
 - 			buf_iflag = 1 << buffer;
 - 			
 - 			if (CAN_0.IFRH.R & buf_iflag){
 - 			CAN_0.IFRH.R = buf_iflag;
 - 			return 1;
 - 			}
 - 			else return 0;
 - 		}
 - 		else {
 - 			buf_iflag = 1 << buffer;
 - 			if (CAN_0.IFRL.R & buf_iflag){
 - 				CAN_0.IFRL.R = buf_iflag;
 - 				return 1;
 - 			}
 - 			else return 0;
 - 		}
 - 	}
 - 
 - 	if(module == MODULE_B){
 - 	if (CanB) {
 - 		
 - 		if (type == TX){
 - 			if (FIRST_CANTxB == 1) { /@/@*$* add comment
 - 				FIRST_CANTxB = 0;
 - 				return 1;
 - 			}
 - 		}
 - 		
 - 		if (buffer > 31){
 - 			buffer = buffer - 32;
 - 			buf_iflag = 1 << buffer;
 - 			
 - 			if (CAN_1.IFRH.R & buf_iflag){
 - 			CAN_1.IFRH.R = buf_iflag;
 - 			return 1;
 - 			}
 - 			else return 0;
 - 		}
 - 		else {
 - 			buf_iflag = 1 << buffer;
 - 			if (CAN_1.IFRL.R & buf_iflag){
 - 				CAN_1.IFRL.R = buf_iflag;
 - 				return 1;
 - 			}
 - 			else return 0;
 - 		}
 - 	}   @/@*$ end CanB $*@/@
 - 	else return 0;
 - 	}
 - 
 - 	if(module == MODULE_C){
 - 		
 - 		if (type == TX){
 - 			if (FIRST_CANTxC == 1) { /@/@*$* add comment
 - 				FIRST_CANTxC = 0;
 - 				return 1;
 - 			} 
 - 		}
 - 
 - 		if (buffer > 31){
 - 			buffer = buffer - 32;
 - 			buf_iflag = 1 << buffer;
 - 			
 - 			if (CAN_2.IFRH.R & buf_iflag){
 - 			CAN_2.IFRH.R = buf_iflag;
 - 			return 1;
 - 			}
 - 			else return 0;
 - 		}
 - 		else {
 - 			buf_iflag = 1 << buffer;
 - 			if (CAN_2.IFRL.R & buf_iflag){
 - 				CAN_2.IFRL.R = buf_iflag;
 - 				return 1;
 - 			}
 - 			else return 0;
 - 		}
 - 	}
 - 
 - 	return 0;
 - }*/
/*******************************************************************************
FUNCTION        : msg_loop
PURPOSE         : Send and Receive multiple CAN messages
				  
INPUTS NOTES    : buffer - 0 - 64                 
RETURNS NOTES   : FAIL if timeout or bad reception, PASS otherwise
GENERAL NOTES   :  
*******************************************************************************/ 
/*#define RX_TIMEOUT 100000
 - #define TX_START_DELAY 200
 - uint8_tmsg_loop (void){
 - 
 - 
 - 	UINT16 mod_num;
 - 	UINT16 aRXFails, bRXFails, cRXFails;
 - 	UINT32 timeout = 0;
 - 	UINT16 tx_delay_A, tx_delay_B, tx_delay_C;
 - 	UINT32 i;
 - 	UINT16 TxDelay = TX_START_DELAY;
 - 	UINT16 count = 0;
 - 	UINT32 dummy = 0;
 - 
 - 	mod_num = 300;
 - 	
 - 	aRXFails = bRXFails = cRXFails = 0;
 - 	
 - 	tx_delay_A = tx_delay_B = tx_delay_C = 0;
 - 	
 - 	FIRST_CANTxA = 0;
 - 	FIRST_CANTxB = 0;
 - 	FIRST_CANTxC = 0;
 - 		
 - 	while (((can.ATX.NumMsgs) || (can.ARX.NumMsgs) || (can.BTX.NumMsgs) || (can.BRX.NumMsgs) || (can.CTX.NumMsgs) || (can.CRX.NumMsgs))	@/@*$ while messages left $*@/@
 - 				&& (timeout<RX_TIMEOUT)	)											@/@*$ and not timed $*@/@
 - 									@/@*$ and no failures $*@/@
 - 		{
 - 			timeout++;
 - 			if (TxDelay)
 - 			{
 - 				TxDelay--;	@/@*$ always delay before first transmission so other device is ready $*@/@
 - 				if (TxDelay == 0) FIRST_CANTxA = FIRST_CANTxB = FIRST_CANTxC = 1;			
 - 			}		
 - 			
 - 			tx_delay_A = tx_delay_A % mod_num;
 - 			tx_delay_B = tx_delay_B % mod_num;
 - 			tx_delay_C = tx_delay_C % mod_num;
 - 
 - 			tx_delay_A += 1;
 - 			tx_delay_B += 1;
 - 			tx_delay_C += 1;
 - 			
 - 	
 - 			if ((TxDelay==0) && (tx_delay_A == 1) && (can.ATX.NumMsgs) && (check_iflag(MODULE_A, CAN_0TX.BUF, TX)))	@/@*$ Module A TX $*@/@
 - 			{
 - 				CAN_Tx_start(MODULE_A, can.ATX.Data0, can.ATX.DataInc, can.ATX.MsgLen, CAN_0TX.BUF);				
 - 				can.ATX.NumMsgs--;
 - 				can.ATX.Data0 += can.ATX.DataInc;
 - 				can.ATX.ID += can.ATX.IDInc;
 - 				can.ATX.MsgLen += can.ATX.LengthInc;
 - 				if (can.ATX.MsgLen > 8) {
 - 					can.ATX.MsgLen = can.ATX.MsgLen % 8;
 - 				}
 - 				
 - 				timeout = 0;		@/@*$ clear time out counter every time a byte is received or transmitted $*@/@
 - 			}
 - 				
 - 			if ( (can.ARX.NumMsgs) && (check_iflag(MODULE_A, CAN_0RX.BUF, RX)) )	@/@*$ Module A RX $*@/@
 - 			{
 - 				aRXFails += RX_check (MODULE_A, CAN_0RX.BUF, can.ARX.Data0, can.ARX.DataInc, can.ARX.MsgLen);				
 - 				can.ARX.NumMsgs--;
 - 				can.ARX.Data0 += can.ARX.DataInc;				
 - 				can.ARX.MsgLen += can.ARX.LengthInc;
 - 				if (can.ARX.MsgLen > 8) {
 - 					can.ARX.MsgLen = can.ARX.MsgLen % 8;
 - 				}				
 - 				
 - 				timeout = 0;		@/@*$ clear time out counter every time a byte is received or transmitted $*@/@
 - 			}
 - 				
 - 			if ((TxDelay==0) && (tx_delay_B == 1) && (can.BTX.NumMsgs) && (check_iflag(MODULE_B, CAN_1TX.BUF, TX)))	@/@*$ Module B TX $*@/@
 - 			{
 - 				CAN_Tx_start(MODULE_B, can.BTX.Data0, can.BTX.DataInc, can.BTX.MsgLen, CAN_1TX.BUF);				
 - 				can.BTX.NumMsgs--;
 - 				can.BTX.Data0 += can.BTX.DataInc;
 - 				can.BTX.ID += can.BTX.IDInc;
 - 				can.BTX.MsgLen += can.BTX.LengthInc;
 - 				if (can.BTX.MsgLen > 8) {
 - 					can.BTX.MsgLen = can.BTX.MsgLen % 8;
 - 				}
 - 				
 - 				timeout = 0;		@/@*$ clear time out counter every time a byte is received or transmitted $*@/@
 - 			}
 - 				
 - 			if ( (can.BRX.NumMsgs) && (check_iflag(MODULE_B, CAN_1RX.BUF, RX)) )	@/@*$ Module A RX $*@/@
 - 			{
 - 				bRXFails += RX_check (MODULE_B, CAN_1RX.BUF, can.BRX.Data0, can.BRX.DataInc, can.BRX.MsgLen);				
 - 				can.BRX.NumMsgs--;
 - 				can.BRX.Data0 += can.BRX.DataInc;
 - 				can.BRX.MsgLen += can.BRX.LengthInc;
 - 				if (can.BRX.MsgLen > 8) {
 - 					can.BRX.MsgLen = can.BRX.MsgLen % 8;
 - 				}
 - 				
 - 				
 - 				timeout = 0;		@/@*$ clear time out counter every time a byte is received or transmitted $*@/@
 - 			}
 - 
 - 			if ((TxDelay==0) && (tx_delay_C == 1) &&(can.CTX.NumMsgs) && (check_iflag(MODULE_C, CAN_2TX.BUF, TX)))	@/@*$ Module B TX $*@/@
 - 			{
 - 				CAN_Tx_start(MODULE_C, can.CTX.Data0, can.CTX.DataInc, can.CTX.MsgLen, CAN_2TX.BUF);				
 - 				can.CTX.NumMsgs--;
 - 				can.CTX.Data0 += can.CTX.DataInc;
 - 				can.CTX.ID += can.CTX.IDInc;
 - 				can.CTX.MsgLen += can.CTX.LengthInc;
 - 				if (can.CTX.MsgLen > 8) {
 - 					can.CTX.MsgLen = can.CTX.MsgLen % 8;
 - 				}
 - 				
 - 				timeout = 0;		@/@*$ clear time out counter every time a byte is received or transmitted $*@/@
 - 			}
 - 				
 - 			if ( (can.CRX.NumMsgs) && (check_iflag(MODULE_C, CAN_2RX.BUF, RX)) )	@/@*$ Module A RX $*@/@
 - 			{
 - 				cRXFails += RX_check (MODULE_C, CAN_2RX.BUF, can.CRX.Data0, can.CRX.DataInc, can.CRX.MsgLen);				
 - 				can.CRX.NumMsgs--;
 - 				can.CRX.Data0 += can.CRX.DataInc;
 - 				can.CRX.MsgLen += can.CRX.LengthInc;
 - 				if (can.CRX.MsgLen > 8) {
 - 					can.CRX.MsgLen = can.CRX.MsgLen % 8;
 - 				}
 - 				
 - 				
 - 				timeout = 0;		@/@*$ clear time out counter every time a byte is received or transmitted $*@/@
 - 			}
 - 
 - 		}	@/@*$ end of while - test complete or timed out $*@/@
 - 
 - 
 - @/@*$ wait for last bytes to go out $*@/@
 - 	while 	(!(check_iflag(MODULE_A, CAN_0TX.BUF, TX)) && !(check_iflag(MODULE_B, CAN_1TX.BUF, TX)) && !(check_iflag(MODULE_C, CAN_2TX.BUF, TX)) && (timeout < RX_TIMEOUT))
 - 	{
 - 	
 - 		timeout++;
 - 	
 - 	}	@/@*$ wait for TDRE $*@/@
 - 
 - /@/@*$*ad still need delay for last byte to get shifted out, or the SPI delay may handle it
 - 	for (i=0; i<100000;i++){}	@/@*$*ad $*@/@
 - 
 - 	if (timeout >= RX_TIMEOUT) fail_mode[6] += 1;  @/@*$ fail_mode array used for debug.  timeout $*@/@
 - 	
 - 	if (aRXFails || bRXFails || cRXFails || (timeout >= RX_TIMEOUT)){
 - 		return FAIL;
 - 	}					
 - 	else {
 - 		return PASS;
 - 	}
 - 	
 - }	@/@*$ end of msg_loop $*@/@*/



/*******************************************************************************
FUNCTION        : SetBaudRate
PURPOSE         : set CAN baud rate				  
INPUTS NOTES    : module - A, B or C. baud - . sysclk -                 
RETURNS NOTES   : NA
GENERAL NOTES   :  
*******************************************************************************/ 
void SetBaudRate (uint8_t module, uint32_t baud, uint8_t sysclk)
{
	uint8_t presdiv;
	uint8_t pseg1;
	uint8_t pseg2;
	uint8_t rjw;
	uint8_t propseg;

/*	if (TEST_CLKSRC == YES){  //Added to test CLK_SRC
 - 		sysclk = 8;
 - 	}*/
	
/*	if ((sysclk == 128)||(sysclk == 80)||(sysclk == 144)||(sysclk == 160)){
 - 		presdiv = ((sysclk * 1000000) / (baud * 16)) - 1;
 - 		rjw = 3;
 - 		pseg1 = 4;
 - 		pseg2 = 4;
 - 		propseg = 4;
 - 	}*/
	
/*	if ((sysclk == 152)){
 - 		presdiv = ((sysclk * 1000000) / (baud * 19)) - 1;
 - 		rjw = 3;
 - 		pseg1 = 4;
 - 		pseg2 = 4;
 - 		propseg = 7;
 - 	}
 - 	
 - 	if (sysclk == 12){
 - 		presdiv = ((sysclk * 1000000) / (baud * 12)) - 1;
 - 		rjw = 2;
 - 		pseg1 = 2;
 - 		pseg2 = 2;
 - 		propseg = 4;
 - 	}
 - 	
 - 	
 - 	if (sysclk == 48){
 - 		presdiv = ((sysclk * 1000000) / (baud * 12)) - 1;
 - 		rjw = 2;
 - 		pseg1 = 2;
 - 		pseg2 = 2;
 - 		propseg = 4;
 - 	}
 - 	
 - 	if (sysclk == 64){
 - 		presdiv = ((sysclk * 1000000) / (baud * 16)) - 1;
 - 		rjw = 2;
 - 		pseg1 = 4;
 - 		pseg2 = 4;
 - 		propseg = 4;
 - 	}*/
	

	presdiv = ((sysclk * 1000000) / (baud * 8))*5 - 1;
	rjw = 1;
	pseg1 = 1;
	pseg2 = 1;
	propseg = 2;
	
	if (module == MODULE_A)
	{
	    // Set Baud Rate by writing to CANCTL 
	    CAN_0.CR.B.PRESDIV = presdiv;
	    CAN_0.CR.B.RJW = rjw;
	    CAN_0.CR.B.PSEG1 = pseg1;
	    CAN_0.CR.B.PSEG2 = pseg2;
	    CAN_0.CR.B.PROPSEG = propseg;
	}

	if (module == MODULE_B)
	{
	    // Set Baud Rate by writing to CANCTL 
	    CAN_1.CR.B.PRESDIV = presdiv;
	    CAN_1.CR.B.RJW = rjw;
	    CAN_1.CR.B.PSEG1 = pseg1;
	    CAN_1.CR.B.PSEG2 = pseg2;
	    CAN_1.CR.B.PROPSEG = propseg;
	}
}


/*******************************************************************************
FUNCTION        : SetIdMaskFiltering
PURPOSE         : set MASK for each MB (ID1 to ID64) or FIFO (ID1 to ID6)				  
INPUTS NOTES    : module - A, B or C.
                  mode - MAILBOX or FIFO
RETURNS NOTES   : NA
GENERAL NOTES   :  
*******************************************************************************/ 
void SetIdMaskFiltering (uint8_t module, uint8_t mode)
{
    uint32_t i;
    

    
    switch (module)
    {
	case 1:
	    CAN_0.MCR.B.FRZ = 1;
	    CAN_0.MCR.B.HALT = 1;
	    if (mode == MAILBOX)
	    {
		/* set both ID and mask values for each MB */
			for (i = 1; i < 65; i++)
			{
				// Write MB Code Field = 0x0 to config as RX inactive
				CAN_0.BUF[i-1].CS.B.CODE = 0;
				CAN_0.BUF[i-1].ID.R = ((uint32_t)i << 18) & 0x1FFC0000;
				CAN_0.RXIMR[i-1].R = 0x1FFFFFFF;
				// Write MB Code Field = 0x4 to config as receive active and empty(Receive)
				CAN_0.BUF[i-1].CS.B.CODE = 0x4;
			} /* end for */
	    } /* end if */
	    CAN_0.MCR.B.FRZ = 0;
	    CAN_0.MCR.B.HALT = 0;
	    break;
	case 2:
	    CAN_1.MCR.B.FRZ = 1;
	    CAN_1.MCR.B.HALT = 1;	    
	    if (mode == MAILBOX)
	    {
		/* set both ID and mask values for each MB */
			for (i = 1; i < 65; i++)
			{
				// Write MB Code Field = 0x0 to config as RX inactive
				CAN_1.BUF[i-1].CS.B.CODE = 0;
				CAN_1.BUF[i-1].ID.R = ((uint32_t)i << 18) & 0x1FFC0000;
				CAN_1.RXIMR[i-1].R = 0x1FFFFFFF;
				// Write MB Code Field = 0x4 to config as receive active and empty(Receive)
				CAN_1.BUF[i-1].CS.B.CODE = 0x4;
			} /* end for */
	    } /* end if */
	    CAN_1.MCR.B.FRZ = 0;
	    CAN_1.MCR.B.HALT = 0;
	    break;	    
    } /* end switch */

    CAN_0.MCR.B.FRZ = 0;
    CAN_0.MCR.B.HALT = 0;
}



