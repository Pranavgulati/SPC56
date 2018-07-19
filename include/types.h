// ****************************************************************************
// Project Name:        PPCframework
//
//! @file               types.h
//! @version            $Revision: 182 $
//! @date               $Date: 2004-10-05 15:59:58 +0200 (Tue, 05 Oct 2004) $
//! @author             Tom Rejhon
//! @brief              Definitions of the standard types
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
// 14.05.2007     Tom Rejhon   Original Issue
//
// ****************************************************************************

#ifndef _TYPES_
#define _TYPES_
    
    #include "typedefs.h"
    
    //#define UINT1       bit                //1 bit wide - NOT DEFINED!
    #define UINT8       unsigned char      //8 bit wide unsigned number
    #define UINT16      unsigned short     //16 bit wide unsigned number
    #define uint32      unsigned int       //32 bit wide unsigned number

    #define SINT8       signed char        //8 bit wide signed number
    #define SINT16      signed short       //16 bit wide signed number
    #define SINT32      signed int         //32 bit wide signed number

#endif

// ***************************** End of types.h *******************************
