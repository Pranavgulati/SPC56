/******************** (C) COPYRIGHT 2013 MCAS *******************
* Project		: K2_LED
* File Name   	: pit.c
* Author      	: Radek Pulpan
* Version		: 1.0
* Date			: 10.12.2013
* Procesor		: SPC570K
* Compilator	: HighTec 4.3
* Description 	: PIT Handler
********************************************************************************
* History:
* 10.12.2013: Version 1.0
*******************************************************************************/

#include "pit.h"



/******************************************************************************
* FUNCTION: 	PIT_Init
* PARAMETERS:	Reload value
* DESCRIPTION:	Set and enable PIT timer
* RETURNS:		void
*******************************************************************************/
void PIT_Init(uint32 reload)
{
	PIT.PITMCR.R = 0x0;
	PIT.CH[0].LDVAL.R = reload*16000;
	PIT.CH[0].TCTRL.B.TEN = 0x1;
	PIT.CH[0].TCTRL.B.TIE = 0x1;
	PIT.CH[1].LDVAL.R = reload*1600;
	PIT.CH[1].TCTRL.B.TEN = 0x1;
	PIT.CH[1].TCTRL.B.TIE = 0x1;
}
