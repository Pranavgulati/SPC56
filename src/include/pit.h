/******************** (C) COPYRIGHT 2013 MCAS *******************
* Project		: xxx
* File Name   	: pit.h
* Author      	: Radek Pulpan
* Version		: 1.0
* Date			: 15.12.2013
* Procesor		: SPC574K
* Compilator	: HighTec 4.3
* Description 	: Header file for PIT timer
********************************************************************************
* History:
* 15.12.2013: Version 1.0
*******************************************************************************/

#ifndef PIT_H_
#define PIT_H_

	#include "common.h"

	void PIT_Init(uint32 reload);
#endif /* PIT_H_ */
