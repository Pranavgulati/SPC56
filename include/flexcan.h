/*******************************************************************************
| File Name    : flexcan.h
| Description  : This file contains all functions prototypes for flexcan.c
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _H_FLEXCAN_H
#define _H_FLEXCAN_H

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
//#define FLEXCAN_A_TX_PCR *((VUINT16 *)(0xFFFE80A0))
//#define FLEXCAN_B_TX_PCR *((VUINT16 *)(0xFFFE80A6))
//#define FLEXCAN_C_TX_PCR *((VUINT16 *)(0xFFFE80A8))
//
//#define FLEXCAN_A_RX_PCR *((VUINT16 *)(0xFFFE80A2))
//#define FLEXCAN_B_RX_PCR *((VUINT16 *)(0xFFFE80A4))
//#define FLEXCAN_C_RX_PCR *((VUINT16 *)(0xFFFE80AA))

#define PASS 0
#define FAIL 1

#define TX 1
#define RX 0

#define EXT 1
#define STD 0
#define MASK_CONFIG 3
#define LOOPBACK 4 
#define LISTEN_ONLY 5
#define MASK_ID 6
#define EXT_MASK 7
#define MASK_ALL_EXT 8 
#define SYSCLK_SLOW 9
#define REMOTE 0xA
#define RTR_EXT 0xB
#define RTR_TX 0xC // TX only in response to remote frame
#define RTR_TX_EXT 0xD // TX only in response to remote frame

#define YES 1
#define NO 0

#define MODULE_A 1
#define MODULE_B 2
#define MODULE_C 3

#define MAILBOX 0
#define FIFO 1

//#define LOCK_TIMEOUT	100000
//#define REMOTE_DELAY  60000

/**************************************************
Global variables
**************************************************/
//typedef struct {
//	UINT8 BUF;
//	UINT32 ID;
//	union {
//            UINT8 B[8];  /* Data buffer in Bytes (8 bits) */
//            UINT16 H[4]; /* Data buffer in Half-words (16 bits) */
//            UINT32 W[2]; /* Data buffer in words (32 bits) */
//           } DATA;
//	UINT32 DATAINC;
//	UINT8 LENGTH;
//	UINT8 LENGTHINC;
//	UINT8 NUM_MSGS;
//} can_config;
//
//typedef struct {
//	UINT16 NumMsgs;	/* number of CAN frames or SCI bytes - any 16-bit value */
//	UINT8 Data0;		/* First data byte */
//	UINT8 DataInc;		/* Data byte incrementer */
//	UINT32 ID;			/* CAN ID */
//	UINT8 Type;			/* SCI_RX, SCI_TX, CAN_RX, CAN_TX, CAN_IDLE */
//	UINT8 IDInc;		/* CAN ID incrementor */
//	UINT8 MsgLen;		/* CAN message length - 0 through 8 */
//	UINT8 LengthInc;	/* CAN message length incrementer - 0 through 8 */
//}	PORT_MSG_Cuhead;
//
//
//typedef struct {
//	UINT32 Abaud;		/* baud rate */
//	PORT_MSG_Cuhead ATX;		/* module A transmitter */
//	PORT_MSG_Cuhead ARX;		/* module A receiver */
//	UINT32 Bbaud;		/* baud rate */
//	PORT_MSG_Cuhead BTX;		/* module B transmitter */
//	PORT_MSG_Cuhead BRX;		/* module B receiver */
//	UINT32 Cbaud;		/* baud rate */
//	PORT_MSG_Cuhead CTX;		/* module C transmitter */
//	PORT_MSG_Cuhead CRX;		/* module C receiver */
//}	CUHEAD_CMD_STRING;


/**************************************************
Function Prototypes
**************************************************/
void CAN_SetupPads(void);
void CAN_Init(uint8_t module, uint8_t sysclk);
void CanRxStart(uint8_t module, uint8_t buffer);
void CAN_Tx(uint8_t module, uint32_t data, uint8_t data_inc, uint8_t length, uint8_t buf);
//UINT8 RX_check (UINT8 module, UINT8 buffer, UINT8 data, UINT8 data_inc, UINT8 length);
//UINT8 TX_check (UINT8 module, UINT8 buffer);
//UINT8 check_iflag (UINT8 module, UINT8 buffer, UINT8 type);
//UINT8 msg_loop (void);
//void CANBitRate (UINT8 module, UINT32 baud, UINT8 samp_point, UINT32 sysclk_freq);
void SetBaudRate(uint8_t module, uint32_t baud, uint8_t sysclock);
void SetIdMaskFiltering(uint8_t, uint8_t);
//void set_baud_rate2 (UINT8 module, UINT32 baud, UINT8 sysclock);
//UINT16 SetPLL5 (UINT8 multiply);

#endif //_H_FLEXCAN_H
