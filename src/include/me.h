// ****************************************************************************
// Project Name:        SPCframework 
//
//! @file               mc.h
//! @version            $Revision: 182 $
//! @date               $Date: 2004-10-05 15:59:58 +0200 (Tue, 05 Oct 2004) $
//! @author             Tom Rejhon
//! @brief              Various modules (ME, CGM,...) configuration 
//!                     
//
// Company:             STMicroelectronics
//                      Pobrezni 3
//                      186 00 Praha 8, Czech Republic
//
// Processor:           SPC560x
// Compiler:            GHS
//
// ***************************** Revision History *****************************
//
// Date:          Name         Description
// 01.12.2009     Zdenek Koza  Added support for Leopard (CPU_SPC56EL)
// 07.05.2008     Tom Rejhon   Added mc_init()
// 16.04.2008     Tom Rejhon   Initial version 
//
// ****************************************************************************

#ifndef _MC_
#define _MC_


// ****************************************************************************
// ************************** Configuration Constants *************************
// ****************************************************************************


// ****************************************************************************
// ********************** External Constants and Variables ********************
// ****************************************************************************                

    //MODE constants (used by me_modeTransition())
    #define ME_MODE_RESET    0x00000000
    #define ME_MODE_TEST     0x10000000
    #define ME_MODE_SAFE     0x20000000
    #define ME_MODE_DRUN     0x30000000
    #define ME_MODE_RUN0     0x40000000
    #define ME_MODE_RUN1     0x50000000
    #define ME_MODE_RUN2     0x60000000
    #define ME_MODE_RUN3     0x70000000
    #define ME_MODE_HALT0    0x80000000
    #define ME_MODE_STOP0    0xA0000000
    #define ME_MODE_STANDBY0 0xD0000000   

    //Constants for Peripheral configuration registers
    //(provides mapping from peripheral name to PCTL register number) 
    #define ME_PCTL_DSPI0       4
    #define ME_PCTL_DSPI1       5
    #define ME_PCTL_DSPI2       6
    #define ME_PCTL_FLEXCAN0    16
    #define ME_PCTL_DMAMUX      23
    #define ME_PCTL_FLEXRAY     24
    #define ME_PCTL_ADC0        32
    #define ME_PCTL_ADC1        33
    #define ME_PCTL_CTU0        35
    #define ME_PCTL_ETIMER0     38
    #define ME_PCTL_ETIMER1     39
    
    #define ME_PCTL_FLEXPWM0    41
    #define ME_PCTL_ETIMER2     40
    #define ME_PCTL_FLEXPWM1    42
    #define ME_PCTL_LINFLEX0    48
    #define ME_PCTL_LINFLEX1    49
    #define ME_PCTL_CRC         58
    #define ME_PCTL_FCCU        59
    #define ME_PCTL_SWG         62
    #define ME_PCTL_SSCM        86    
    #define ME_PCTL_PIT         92
    #define ME_PCTL_STCU        93
        
// ****************************************************************************
// ************************** Configuration Constants *************************
// ****************************************************************************

	#if (CPU_CLOCK == 16000000)
		#define FMPLL_NDIV     0x0020
		#define FMPLL_IDF      0x0004
		#define FMPLL_ODF      0x0003
	#elif (CPU_CLOCK == 32000000)
		#define FMPLL_NDIV     0x0020
		#define FMPLL_IDF      0x0004
		#define FMPLL_ODF      0x0002
	#elif (CPU_CLOCK == 60000000)
		#define FMPLL_NDIV     0x003C
		#define FMPLL_IDF      0x0004
		#define FMPLL_ODF      0x0002
	#elif (CPU_CLOCK == 64000000)
		#define FMPLL_NDIV     0x0020
		#define FMPLL_IDF      0x0004
		#define FMPLL_ODF      0x0001
	#elif (CPU_CLOCK == 120000000)
		#define FMPLL_NDIV     0x003C
		#define FMPLL_IDF      0x0004
		#define FMPLL_ODF      0x0001
	#endif

// ****************************************************************************
// *********************** Function Prototypes ********************************
// ****************************************************************************
      
    void ME_Init(void);

#endif

// *************************** End of mc.h ***************************
