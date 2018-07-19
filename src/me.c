// ****************************************************************************
// Project Name:        SPCframework
//
//! @file               mc.c
//! @version            $Revision: 182 $
//! @date               $Date: 2004-10-05 15:59:58 +0200 (Tue, 05 Oct 2004) $
//! @author             Tom Rejhon
//! @brief              Various modules (ME, CGM,...) configuration
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
// Date           Name            Description
// 01.12.2009     Zdenek Koza     Added support for Leopard
// 11.09.2008     Tom Rejhon      Striped down to support Pictus only
// 21.07.2008     Tom Rejhon      Fixed PLL switching problem when running from 
//                                Flash on Pictus
// 05.06.2008     Zdenek Koza     Fixed CLKOUT for BOLERO, SELCTL = 1 (16M IRC)
// 07.05.2008     Tom Rejhon      Added mc_init()
// 16.04.2008     Tom Rejhon      Original Issue.
//
// ****************************************************************************

#include   "common.h"
#include   "me.h"



void Clock_Init(void);
void ME_ModeTransition (uint32 modeToEnter);

// ****************************************************************************
//! @fn          void ME_ModeTransition (uint32 modeToEnter)
//! @param
//!              modeToEnter     mode to be entered (see ME_MODE_xxxx constants)
//! @return
//!              none
//! @brief
//!              Triggers mode transition and waits for its completion
//!
// ****************************************************************************
void ME_ModeTransition (uint32 modeToEnter)
{
   //Start mode transition
   //enter to mode (0 = reset, 2 = safe, 3 = drun, 4 = run0, 5 = run1)
   ME.MCTL.R = modeToEnter | 0x00005AF0;
   ME.MCTL.R = modeToEnter | 0x0000A50F;

   //wait until this mode transition is finished
   while (ME.GS.B.S_MTRANS);
   ME.IS.R   = 1;            //clear MTC (mode transition completed) bit
}//me_modeTransition


void Clock_Init(void)
{
    
    // !!! Enable all peripheral clocks - added for LEOPARD !!!
	CGM.SCDC0.R = 0x80808080; //system clock divider


	//Disable both CMUs (it disables PLL frequency check, XOSC check still works)
	CGM.CMU_0_CSR.B.CME_A = 0;
	CGM.CMU_1_CSR.B.CME_A = 0;
	CGM.CMU_0_CSR.B.RCDIV = 3; // set divider to avoid reset when XOSC is enabled (Frc/2^div < Fosc)


    //Configure all Auxiliary Clock Selectors
    CGM.AC0SC.R = 4; //source = system PLL
    CGM.AC1SC.R = 0; //source = secondary PLL			
    CGM.AC2SC.R = 4; //source = system PLL

    // !!! Clock Sources for FMPLL Modules - added for LEOPARD !!! */
    CGM.AC3SC.B.SELCTL = 1; //select crystal oscillator
    CGM.AC4SC.B.SELCTL = 1; //select crystal oscillator
	
    //enable dividers (do not divide)
    CGM.AC0DC.R	= 0x80000000; 
    CGM.AC1DC.R	= 0x80000000;
    CGM.AC2DC.R = 0x80800000;	

    //Setup system PLL (PLL0)
    CGM.FMPLL[0].CR.R = 0x03200012; //set PLL to 120Mhz for 40 MHz crystal
    CGM.AC3SC.B.SELCTL = 1; // AUX Clock selector 3
    CGM.AC4SC.B.SELCTL = 1; // AUX Clock selector 4

    //PLL0 120 MHz
    CGM.FMPLL[0].CR.B.IDF  = 0x2;       // Divide by 3
    CGM.FMPLL[0].CR.B.ODF  = 0x1;       // 0x0 Divide by 2; 0x1 Divide by 4; 0x2 Divide by 8; 0x3 Divide by 16;
    CGM.FMPLL[0].CR.B.NDIV = 36;        // LDF
    
/*
    //Configure PLL and Switch to RUN0 mode
    CGM.FMPLL[0].CR.R = (FMPLL_IDF << 26 | FMPLL_ODF << 24 | FMPLL_NDIV << 16) & 0x3F7F0000;
    CGM.OCDSSC.B.SELCTL = 2; //CLKOUT sourced from PLL


    //Configure Crystal oscillator circuit
    //( OSCBYP=0, EOCV=16, M_OSC=0, OSCDIV= 0, I_OSC=0 (I_OSC is cleared by writing 1)) 
    CGM.OSC_CTL.R = (0x0 << 31) | (0x10 << 16) | (0x0 << 15) | (0x0 << 8) | (0x1 << 7) | 1;        
    
    //Setup system PLL (PLL0)    
    CGM.FMPLL[0].CR.R = 0x11200059; //set PLL to 64Mhz for 40 MHz crystal
    
    //Disable both CMUs (it disables PLL frequency check, XOSC check still works)
    CGM.CMU_0_CSR.B.CME_A = 0;         
    CGM.CMU_1_CSR.B.CME_A = 0;

    CGM.CMU_0_CSR.B.RCDIV = 3; // set divider to avoid reset when XOSC is enabled (Frc/2^div < Fosc)    */
    
    //Turn on External Clock Output (configure the CLKOUT pad)        
    //set PA=1

    SIU.PCR[PORT_PIN_CLKOUT].R = 0x0404;  //configure CLKOUT pin (pad 22 (for PICTUS) - PB[6])
    CGM.OCDSSC.B.SELCTL = 2;              //output clock source selection (0=16M IRC, 1=4M crystal oscilator, 2=system PLL)

    CGM.OCDSSC.B.SELDIV = 2;              //divider is (2 = /4, 0 = /1, 1 = /2)    
    CGM.OCEN.B.EN = 1;                    //enable clock output (for debugging purposes)
}


//Initialize DRUN and RUN0 modes
//CLKOUT is turned on and is sourced by internal 16MHz RC oscillator
//Enter DRUN mode at the end

void ME_Init(void)
{

    //Disable SoftwareWatchdogTimer in SWT_cR
    SWT.SR.R        = 0xC520;
    SWT.SR.R        = 0xD928; //unlock peripheral
    SWT.CR.B.WEN    = 0;

    //Choose what modes should be enabled - Mode Enable register (ME_ME)
    //ME.MER.R   = 0x18; //RUN0 and DRUN modes are enabled by default

    //Configure ModeConfiguration registers, i.e. ME_RUN0_MC and ME_DRUN_MC in this case
    //(Turn on FLASH, PLL0, xosc0on, irc 16M, select System Clock source)
    ME.DRUN.R       = 0x001F0070 | 0; //SYSCLK = 0 (IRC 16M), = 2 (4MHz crystal oscilator), = 4(System PLL)
    ME.RUN[0].R     = 0x001F0070 | 4;

    //Configure RunPeripheralConfiguration registers in ME_RUN_PC1, ME_LP_PC1
    //(Specifies at what modes is peripheral enabled. Referred to by PCTL registers)
    ME.RUNPC[1].R   = 0x18; //enable only in RUN0 and DRUN modes
    ME.LPPC[1].R    = 0x00; //disable when in a low power mode
    //Configure RunPeripheralConfiguration registers in ME_RUN_PC1, ME_LP_PC1
	//Configure PeripheralControl Registers, i.e. ME_PCTLxxx
	//(select what peripherals will be turn on in which run modes)
	//(All selected peripherals will use PeripheralControlRegister[1].
    //(Specifies at what modes is peripheral enabled. Referred to by PCTL registers)
	ME.RUNPC[0].R   = 0x18; //enable only in RUN0 and DRUN modes
	ME.LPPC[0].R    = 0x00; //disable when in a low power mode

	ME.PCTL[39].B.RUN_CFG = 0;  //and use it for eTimer1(41) enable in RUN0 mode
	ME.PCTL[32].B.RUN_CFG = 0;  //and use it for ADC0(41) enable in RUN0 mode

    //The other peripheral will use PeripheralControlRegister[0] which is preconfigured to disable everything)
    //ME.PCTL[ME_PCTL_LINFLEX0].R = 0x9; //DBG_F = 0, LP_CFG = 1, RUN_CFG = 1 (use ME_RUN_PC1)
	ME.PCTL[ME_PCTL_FLEXCAN0].R = 0; //DBG_F = 0, LP_CFG = 1, RUN_CFG = 1
	ME.PCTL[ME_PCTL_PIT].R = 0; //DBG_F = 0, LP_CFG = 1, RUN_CFG = 1
    //ME.PCTL[ME_PCTL_SAFETYPORT].B.RUN_CFG = 1;       // enable Safety port needed for correct mode transition

    Clock_Init();
    ME_ModeTransition (0x40000000);     //enter DRUN to make changes above valid
    
}//mc_init()
