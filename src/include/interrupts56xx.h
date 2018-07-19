// ****************************************************************************
// Project Name:      interrupt - constants definition
//
//! @file             interrupts56xx.h
//! @version          $Revision: 182 $
//! @date             $Date: 2004-10-05 15:59:58 +0200 (Tue, 05 Oct 2004) $
//! @author           Tom Rejhon
//! @brief            SPC560x interrupt sources definition
// Company:           STMicroelectronics
//                    Pobrezni 3
//                    186 00 Praha 8, Czech Republic
//
// Processor:         SPC560x, SPC56ELx
// Compiler:          GHS ver. 4.0 >
//
// ***************************** Revision History *****************************
//
// Date:          Name            Description
// 14.12.2009     Zdenek Koza     Adapted for Leopard
// 29.04.2008     Tom Rejhon      Original Issue
//
// ****************************************************************************

#ifndef _INTERRUPT_
#define _INTERRUPT_

// ****************************************************************************
// ************************** Configuration Constants *************************
// ****************************************************************************
   

// ****************************************************************************
// ********************** External Constants and Variables ********************
// ****************************************************************************
//*** Exceptions and Conditions ***
#define INT_IVOR0                0 //Critical input
#define INT_IVOR1                1 //Machine check
#define INT_IVOR2                2 //Data storage
#define INT_IVOR3                3 //Instruction storage
#define INT_IVOR4                4 //External input
#define INT_IVOR5                5 //Alignment
#define INT_IVOR6                6 //Program
#define INT_IVOR8                8 //System call
#define INT_IVOR15              15 //Debug

//*** Interrupts Vector Number Definition ***
#define INT_INTC_SSCIR0          0 //INTC software settable Clear flag 0
#define INT_INTC_SSCIR1          1 //INTC software settable Clear flag 1
#define INT_INTC_SSCIR2          2 //INTC software settable Clear flag 2
#define INT_INTC_SSCIR3          3 //INTC software settable Clear flag 3
#define INT_INTC_SSCIR4          4 //INTC software settable Clear flag 4
#define INT_INTC_SSCIR5          5 //INTC software settable Clear flag 5
#define INT_INTC_SSCIR6          6 //INTC software settable Clear flag 6
#define INT_INTC_SSCIR7          7 //INTC software settable Clear flag 7

//Watchdog / ECC                 
#define INT_ECSM_SWTIR           8 //ECSM Software Watchdog Interrupt flag
#define INT_ECSM_ESR             9 //ECSM combined interrupt requests:
                                   //Internal SRAM Non-Correctable Error and Flash
                                   //Non-Correctable Error
//DMAC                        
#define INT_EDMA_ERL            10 //eDMA channel Error flags 31–0
#define INT_EDMA_IRQRL0         11 //eDMA channel Interrupt 0
#define INT_EDMA_IRQRL1         12 //eDMA channel Interrupt 1
#define INT_EDMA_IRQRL2         13 //eDMA channel Interrupt 2
#define INT_EDMA_IRQRL3         14 //eDMA channel Interrupt 3
#define INT_EDMA_IRQRL4         15 //eDMA channel Interrupt 4
#define INT_EDMA_IRQRL5         16 //eDMA channel Interrupt 5
#define INT_EDMA_IRQRL6         17 //eDMA channel Interrupt 6
#define INT_EDMA_IRQRL7         18 //eDMA channel Interrupt 7
#define INT_EDMA_IRQRL8         19 //eDMA channel Interrupt 8
#define INT_EDMA_IRQRL9         20 //eDMA channel Interrupt 9
#define INT_EDMA_IRQRL10        21 //eDMA channel Interrupt 10
#define INT_EDMA_IRQRL11        22 //eDMA channel Interrupt 11
#define INT_EDMA_IRQRL12        23 //eDMA channel Interrupt 12
#define INT_EDMA_IRQRL13        24 //eDMA channel Interrupt 13
#define INT_EDMA_IRQRL14        25 //eDMA channel Interrupt 14
#define INT_EDMA_IRQRL15        26 //eDMA channel Interrupt 15

//FCCU
#define INT_FCCU_ALARM          27 //FCCU Alarm

//SWT 0
#define INT_SWT                 28 //Software watchdog timeout 0

//SWT 1
#define INT_SWT1                29 //Software watchdog timeout 1

//STM
#define INT_STM0                30 //match on channel 0
#define INT_STM1                31 //match on channel 1
#define INT_STM2                32 //match on channel 2
#define INT_STM3                33 //match on channel 3

//ECC
#define INT_ECC_DBD             35 //Double Bit Detection
#define INT_ECC_SBC             36 //Single bit Correction

//RTC
#define INT_RTC                 38 //RTC
#define INT_RTC_API             39 //API

//SIU lite                           
#define INT_SIU_EIRQ0           41 //SIU External Interrupt Flag 0
#define INT_SIU_EIRQ1           42 //SIU External Interrupt Flag 1
#define INT_SIU_EIRQ2           43 //SIU External Interrupt Flag 2
#define INT_SIU_EIRQ3           44 //SIU External Interrupt Flag 3

//WAKEUP unit
#define INT_WAKEUP0             46 //Wakeup IRQ 0
#define INT_WAKEUP1             47 //Wakeup IRQ 1
#define INT_WAKEUP2             48 //Wakeup IRQ 2

//Mode Entry (ME)                         
#define INT_ME_SMI              51 //safe Mode Interrupt
#define INT_ME_MTI              52 //mode transition interrupt
#define INT_ME_IMI              53 //invalid mode interrupt
#define INT_ME_IMC              54 //invalid mode config

#define INT_ME_RGM              56 //functional and destructive alternate event interrupt

//XOSC
#define INT_XOSC                57 //XOSC counter expired

//Periodic interrupt timer (PIT)
#define INT_PIT0                59 //PI timer channel 0
#define INT_PIT1                60 //PI timer channel 1
#define INT_PIT2                61 //PI timer channel 2

//ADC0
#define INT_ADC0_EOC            62 //End of conversion
#define INT_ADC0_ER             63 //ADC0 ER
#define INT_ADC0_WD             64 //ADC0 WD

//FlexCAN0
#define INT_FLEXCAN0_ERR        65 //FlaxCAN0 ERR
#define INT_FLEXCAN0_ESR_BOFF   66 //FlaxCAN0 ESR_BOFF
#define INT_FLEXCAN0_ESR_WAK    67 //FlaxCAN0 ESR_WAK
#define INT_FLEXCAN0_BUFF00_03  68 //FlaxCAN0 BUFF 00-03
#define INT_FLEXCAN0_BUFF04_07  69 //FlaxCAN0 BUFF 04-07
#define INT_FLEXCAN0_BUFF08_11  70 //FlaxCAN0 BUFF 08-11
#define INT_FLEXCAN0_BUFF12_15  71 //FlaxCAN0 BUFF 12-15
#define INT_FLEXCAN0_BUFF16_31  72 //FlaxCAN0 BUFF 16-31

//DSPI0
#define INT_DSPI0_TFUF          74 //Transmit FIFO underflow
#define INT_DSPI0_EOQF          75 //End of Queue
#define INT_DSPI0_TFFF          76 //Transmit FIFO Fill
#define INT_DSPI0_TCF           77 //Transfer Complete
#define INT_DSPI0_RFDF          78 //Receive FIFO Drain

//LinFlex0
#define INT_LINFLEX0_RXI        79 //LINFlex0_RXI
#define INT_LINFLEX0_TXI        80 //LINFlex0_TXI
#define INT_LINFLEX0_ERR        81 //LINFlex0_ERR

//ADC1
#define INT_ADC1_EOC            82 //ADC1 EOC
#define INT_ADC1_ER             83 //ADC1 ER
#define INT_ADC1_WD             84 //ADC1 WD

//FlexCAN1
#define INT_FLEXCAN1_ERR        85 //FlexCAN1 ERR
#define INT_FLEXCAN1_ESR_BOFF   86 //FlexCAN1 ESR_BOFF
#define INT_FLEXCAN1_ESR_WAK    87 //FlexCAN1 ESR_WAK
#define INT_FLEXCAN1_BUFF00_03  88 //FlexCAN1 BUFF 00-03
#define INT_FLEXCAN1_BUFF04_07  89 //FlexCAN1 BUFF 04-07
#define INT_FLEXCAN1_BUFF08_11  90 //FlexCAN1 BUFF 08-11
#define INT_FLEXCAN1_BUFF12_15  91 //FlexCAN1 BUFF 12-15
#define INT_FLEXCAN1_BUFF16_31  92 //FlexCAN1 BUFF 16-31

//DSPI1
#define INT_DSPI1_TFUF          94 //Transmit FIFO underflow
#define INT_DSPI1_EOQF          95 //End of Queue
#define INT_DSPI1_TFFF          96 //Transmit FIFO Fill
#define INT_DSPI1_TCF           97 //Transfer Complete
#define INT_DSPI1_RFDF          98 //Receive FIFO Drain

//LinFlex1
#define INT_LINFLEX1_RXI        99 //LINFlex1 RXI
#define INT_LINFLEX1_TXI       100 //LINFlex1_TXI
#define INT_LINFLEX1_ERR       101 //LINFlex1_ERR

//DSPI2
#define INT_DSPI2_TFUF         114 //Transmit FIFO underflow
#define INT_DSPI2_EOQF         115 //End of Queue
#define INT_DSPI2_TFFF         116 //Transmit FIFO Fill
#define INT_DSPI2_TCF          117 //Transfer Complete
#define INT_DSPI2_RFDF         118 //Receive FIFO Drain

//PIT
#define INT_PIT3               127 //PIT Channel 3

//FlexRay
#define INT_FLEXRAY_LRNEIF     131 //LRNEIF | DRNEIF
#define INT_FLEXRAY_LRCEIF     132 //LRCEIF | DRCEIF
#define INT_FLEXRAY_FNEAIF     133 //FNEAIF
#define INT_FLEXRAY_FNEBIF     134 //FNEBIF
#define INT_FLEXRAY_WUPIF      135 //WUPIF
#define INT_FLEXRAY_PRIF       136 //PRIF
#define INT_FLEXRAY_CHIF       137 //CHIF
#define INT_FLEXRAY_TBIF       138 //TBIF
#define INT_FLEXRAY_RBIF       139 //RBIF
#define INT_FLEXRAY_MIF        140 //MIF

//eMIOS 0
#define INT_EMIOS0_CH0_1       141 //EMIOS0 channel 0 and 1
#define INT_EMIOS0_CH2_3       142 //EMIOS0 channel 2 and 3
#define INT_EMIOS0_CH4_5       143 //EMIOS0 channel 4 and 5
#define INT_EMIOS0_CH6_7       144 //EMIOS0 channel 6 and 7
#define INT_EMIOS0_CH8_9       145 //EMIOS0 channel 8 and 9
#define INT_EMIOS0_CH10_11     146 //EMIOS0 channel 10 and 11
#define INT_EMIOS0_CH12_13     147 //EMIOS0 channel 12 and 13
#define INT_EMIOS0_CH14_15     148 //EMIOS0 channel 14 and 15
#define INT_EMIOS0_CH16_17     149 //EMIOS0 channel 16 and 17
#define INT_EMIOS0_CH18_19     150 //EMIOS0 channel 18 and 19
#define INT_EMIOS0_CH20_21     151 //EMIOS0 channel 20 and 21
#define INT_EMIOS0_CH22_23     152 //EMIOS0 channel 22 and 23
#define INT_EMIOS0_CH24_25     153 //EMIOS0 channel 24 and 25
#define INT_EMIOS0_CH26_27     154 //EMIOS0 channel 26 and 27

#if ( PROCESSOR == CPU_SPC560B )

//eMIOS 1
#define INT_EMIOS1_CH0_1       157 //EMIOS1 channel 0 and 1
#define INT_EMIOS1_CH2_3       158 //EMIOS1 channel 2 and 3
#define INT_EMIOS1_CH4_5       159 //EMIOS1 channel 4 and 5
#define INT_EMIOS1_CH6_7       160 //EMIOS1 channel 6 and 7
#define INT_EMIOS1_CH8_9       161 //EMIOS1 channel 8 and 9
#define INT_EMIOS1_CH10_11     162 //EMIOS1 channel 10 and 11
#define INT_EMIOS1_CH12_13     163 //EMIOS1 channel 12 and 13
#define INT_EMIOS1_CH14_15     164 //EMIOS1 channel 14 and 15
#define INT_EMIOS1_CH16_17     165 //EMIOS1 channel 16 and 17
#define INT_EMIOS1_CH18_19     166 //EMIOS1 channel 18 and 19
#define INT_EMIOS1_CH20_21     167 //EMIOS1 channel 20 and 21
#define INT_EMIOS1_CH22_23     168 //EMIOS1 channel 22 and 23
#define INT_EMIOS1_CH24_25     169 //EMIOS1 channel 24 and 25
#define INT_EMIOS1_CH26_27     170 //EMIOS1 channel 26 and 27

#else

//eTIMER 0
#define INT_ETIMER0_TC0IR      157 //ETIMER0 TC0IR
#define INT_ETIMER0_TC1IR      158 //ETIMER0 TC1IR
#define INT_ETIMER0_TC2IR      159 //ETIMER0 TC2IR
#define INT_ETIMER0_TC3IR      160 //ETIMER0 TC3IR
#define INT_ETIMER0_TC4IR      161 //ETIMER0 TC4IR
#define INT_ETIMER0_TC5IR      162 //ETIMER0 TC5IR
#define INT_ETIMER0_WTIF       165 //ETIMER0 WTIF
#define INT_ETIMER0_RCF        167 //ETIMER0 RCF

//eTIMER 1
#define INT_ETIMER1_TC0IR      168 //ETIMER1 TC0IR
#define INT_ETIMER1_TC1IR      169 //ETIMER1 TC1IR
#define INT_ETIMER1_TC2IR      170 //ETIMER1 TC2IR
#define INT_ETIMER1_TC3IR      171 //ETIMER1 TC3IR
#define INT_ETIMER1_TC4IR      172 //ETIMER1 TC4IR
#define INT_ETIMER1_TC5IR      173 //ETIMER1 TC5IR
#define INT_ETIMER1_RCF        178 //ETIMER1 RCF

#endif

//FlexPWM 0
#define INT_FLEXPWM0_RF0       179 //FLEXPWM_RF0
#define INT_FLEXPWM0_COMP0     180 //FLEXPWM_COMP0
#define INT_FLEXPWM0_CAPT0     181 //FLEXPWM_CAPT0
#define INT_FLEXPWM0_RF1       182 //FLEXPWM_RF1
#define INT_FLEXPWM0_COMP1     183 //FLEXPWM_COMP1
#define INT_FLEXPWM0_CAPT1     184 //FLEXPWM_CAPT1
#define INT_FLEXPWM0_RF2       185 //FLEXPWM_RF2
#define INT_FLEXPWM0_COMP2     186 //FLEXPWM_COMP2
#define INT_FLEXPWM0_CAPT2     187 //FLEXPWM_CAPT2
#define INT_FLEXPWM0_RF3       188 //FLEXPWM_RF3
#define INT_FLEXPWM0_COMP3     189 //FLEXPWM_COMP3
#define INT_FLEXPWM0_CAPT3     190 //FLEXPWM_CAPT3
#define INT_FLEXPWM0_FAULT     191 //FLEXPWM_FAULT
#define INT_FLEXPWM0_RLD_ERROR 192 //FLEXPWM_RELOAD_ERROR

//CTU 0
#define INT_CTU0_MRS_I         193 //CTU0 MRS_I
#define INT_CTU0_T0_I          194 //CTU0 T0_I
#define INT_CTU0_T1_I          195 //CTU0 T1_I
#define INT_CTU0_T2_I          196 //CTU0 T2_I
#define INT_CTU0_T3_I          197 //CTU0 T3_I
#define INT_CTU0_T4_I          198 //CTU0 T4_I
#define INT_CTU0_T5_I          199 //CTU0 T5_I
#define INT_CTU0_T6_I          200 //CTU0 T6_I
#define INT_CTU0_T7_I          201 //CTU0 T7_I
#define INT_CTU0_FIFO0_I       202 //CTU0 FIFO0_I
#define INT_CTU0_FIFO1_I       203 //CTU0 FIFO1_I
#define INT_CTU0_FIFO2_I       204 //CTU0 FIFO2_I
#define INT_CTU0_FIFO3_I       205 //CTU0 FIFO3_I
#define INT_CTU0_ADC_I         206 //CTU0 ADC_I
#define INT_CTU0_ERR_I         207 //CTU0 ERR_I

//Safety Port
#define INT_SAFETYP_ERR        208 //SAFETY PORT

//DSPI3
#define INT_DSPI3_TFUF         217 //Transmit FIFO underflow
#define INT_DSPI3_EOQF         218 //End of Queue
#define INT_DSPI3_TFFF         219 //Transmit FIFO Fill
#define INT_DSPI3_TCF          220 //Transfer Complete
#define INT_DSPI3_RFDF         221 //Receive FIFO Drain

//eTIMER 2
#define INT_ETIMER2_TC0IR      222 //ETIMER2 TC0IR
#define INT_ETIMER2_TC1IR      223 //ETIMER2 TC1IR
#define INT_ETIMER2_TC2IR      224 //ETIMER2 TC2IR
#define INT_ETIMER2_TC3IR      225 //ETIMER2 TC3IR
#define INT_ETIMER2_TC4IR      226 //ETIMER2 TC4IR
#define INT_ETIMER2_TC5IR      227 //ETIMER2 TC5IR
#define INT_ETIMER2_RCF        232 //ETIMER2 RCF

//FlexPWM 1
#define INT_FLEXPWM1_RF0       233 //FLEXPWM_RF0
#define INT_FLEXPWM1_COMP0     234 //FLEXPWM_COMP0
#define INT_FLEXPWM1_CAPT0     235 //FLEXPWM_CAPT0
#define INT_FLEXPWM1_RF1       236 //FLEXPWM_RF1
#define INT_FLEXPWM1_COMP1     237 //FLEXPWM_COMP1
#define INT_FLEXPWM1_CAPT1     238 //FLEXPWM_CAPT1
#define INT_FLEXPWM1_RF2       239 //FLEXPWM_RF2
#define INT_FLEXPWM1_COMP2     240 //FLEXPWM_COMP2
#define INT_FLEXPWM1_CAPT2     241 //FLEXPWM_CAPT2
#define INT_FLEXPWM1_RF3       242 //FLEXPWM_RF3
#define INT_FLEXPWM1_COMP3     243 //FLEXPWM_COMP3
#define INT_FLEXPWM1_CAPT3     244 //FLEXPWM_CAPT3
#define INT_FLEXPWM1_FAULT     245 //FLEXPWM_FAULT
#define INT_FLEXPWM1_RLD_ERROR 246 //FLEXPWM_RELOAD_ERROR

//SEMA4 0
#define INT_SEMA40_CP0CP1      247 //SEMA4 0 CP0 | CP1

//SEMA4 1
#define INT_SEMA41_CP0CP1      248 //SEMA4 1 CP0 | CP1

//FCCU
#define INT_FCCU_ALARM_B       250 //FCCU CP0 | CP1
#define INT_FCCU_MISC          251 //FCCU MISC
#define INT_FCCU_RCCS_B0       252 //FCCU RCCS_B0
#define INT_FCCU_RCCS_B1       253 //FCCU RCCS_B1

//SWG
#define INT_SWG_SGEN_ERR       255 //SWG

#endif 

// ************************* End of interrupts56xx.h **************************
