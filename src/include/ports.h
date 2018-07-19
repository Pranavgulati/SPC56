// ****************************************************************************
// Project Name:        SPCframework 
//
//! @file               ports.h
//! @version            $Revision: 182 $
//! @date               $Date: 2004-10-05 15:59:58 +0200 (Tue, 05 Oct 2004) $
//! @author             Tom Rejhon
//! @brief              I/O port pin names definition 
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
// 01.12.2009     Zdenek Koza  Support for CPU_SPC56EL added
// 21.04.2008     Zdenek Koza  Support for CPU_SPC560B and CPU_SPC560P added
// 21.02.2008     Zdenek Koza  Next 5 pins definitions for CPU_SPC563M added 
// 18.02.2008     Zdenek Koza  Support for CPU_SPC563M added 
// 31.05.2007     Tom Rejhon   Initial version based on freescale's fs_gpio.h file 
//
// ****************************************************************************

#ifndef _PORTS_
#define _PORTS_


// ****************************************************************************
// ************************** Configuration Constants *************************
// ****************************************************************************


// ****************************************************************************
// ********************** External Constants and Variables ********************
// ****************************************************************************
    
    // Fields used for all ports 

    // SMC field - Save Mode Control
    #define PORT_PINCFG_SAVEON               0x4000
    #define PORT_PINCFG_SAVEOFF              0x0000

    // APC field - Analog Pad Control
    #define PORT_PINCFG_ANALOGON             0x2000
    #define PORT_PINCFG_ANALOGOFF            0x0000

    // PA field - port assignment 
    #define PORT_PINCFG_ALTERNATE_MODE0_IO   0x0000
    #define PORT_PINCFG_ALTERNATE_MODE1      0x0400
    #define PORT_PINCFG_ALTERNATE_MODE2      0x0800
    #define PORT_PINCFG_ALTERNATE_MODE3      0x0C00
    
    // OBE, IBE fields - output/input buffer enable
    #define PORT_PINCFG_OUTPUT_BUFFER_ENABLE 0x0200
    #define PORT_PINCFG_INPUT_BUFFER_ENABLE  0x0100
    #define PORT_PINCFG_OUTPUT_MODE          0x0200
    #define PORT_PINCFG_INPUT_MODE           0x0100
    #define PORT_PINCFG_READBACK_ENABLE      0x0100
    #define PORT_PINCFG_READBACK_DISABLE     0x0000 
    
    // Fields used for Input
    
    // WPE and WPS fields - treated as 1 field for weak pull configuration
    #define PORT_PINCFG_WEAK_PULL_UP         0x0003
    #define PORT_PINCFG_WEAK_PULL_DOWN       0x0002
    #define PORT_PINCFG_WEAK_PULL_DISABLE    0x0000
   
    // Fields used for Output
    
    // ODE field - output drain control
    #define PORT_PINCFG_OUTPUT_DRAIN_ENABLE  0x0020
    #define PORT_PINCFG_OUTPUT_DRAIN_DISABLE 0x0000
    #define PORT_PINCFG_OPEN_DRAIN_ENABLE    0x0020
    #define PORT_PINCFG_OPEN_DRAIN_DISABLE   0x0000
    
    // SRC field - slew rate control
    #define PORT_PINCFG_MINIMUM_SLEW_RATE    0x0000
    #define PORT_PINCFG_MEDIUM_SLEW_RATE     0x0004
    #define PORT_PINCFG_MAXIMUM_SLEW_RATE    0x000C  
    
    // Pin's functional name and its PCR register index mapping
    #define PORT_PIN_A0         0
    #define PORT_PIN_A1         1
    #define PORT_PIN_A2         2
    #define PORT_PIN_A3         3
    #define PORT_PIN_A4         4
    #define PORT_PIN_A5         5
    #define PORT_PIN_A6         6
    #define PORT_PIN_A7         7
    #define PORT_PIN_A8         8
    #define PORT_PIN_A9         9
    #define PORT_PIN_A10       10
    #define PORT_PIN_A11       11
    #define PORT_PIN_A12       12
    #define PORT_PIN_A13       13
    #define PORT_PIN_A14       14
    #define PORT_PIN_A15       15

    #define PORT_PIN_B0        16
    #define PORT_PIN_B1        17
    #define PORT_PIN_B2        18
    #define PORT_PIN_B3        19
    #define PORT_PIN_B4        20
    #define PORT_PIN_B5        21
    #define PORT_PIN_B6        22
    #define PORT_PIN_B7        23
    #define PORT_PIN_B8        24
    #define PORT_PIN_B9        25
    #define PORT_PIN_B10       26
    #define PORT_PIN_B11       27
    #define PORT_PIN_B12       28
    #define PORT_PIN_B13       29
    #define PORT_PIN_B14       30
    #define PORT_PIN_B15       31

    #define PORT_PIN_C0        32
    #define PORT_PIN_C1        33
    #define PORT_PIN_C2        34
    #define PORT_PIN_C3        35
    #define PORT_PIN_C4        36
    #define PORT_PIN_C5        37
    #define PORT_PIN_C6        38
    #define PORT_PIN_C7        39
    #define PORT_PIN_C8        40
    #define PORT_PIN_C9        41
    #define PORT_PIN_C10       42
    #define PORT_PIN_C11       43
    #define PORT_PIN_C12       44
    #define PORT_PIN_C13       45
    #define PORT_PIN_C14       46
    #define PORT_PIN_C15       47

    #define PORT_PIN_D0        48
    #define PORT_PIN_D1        49
    #define PORT_PIN_D2        50
    #define PORT_PIN_D3        51
    #define PORT_PIN_D4        52
    #define PORT_PIN_D5        53
    #define PORT_PIN_D6        54
    #define PORT_PIN_D7        55
    #define PORT_PIN_D8        56
    #define PORT_PIN_D9        57
    #define PORT_PIN_D10       58
    #define PORT_PIN_D11       59
    #define PORT_PIN_D12       60
    #define PORT_PIN_D13       61
    #define PORT_PIN_D14       62
    #define PORT_PIN_D15       63

    #define PORT_PIN_E0        64
    #define PORT_PIN_E1        65
    #define PORT_PIN_E2        66
    #define PORT_PIN_E3        67
    #define PORT_PIN_E4        68
    #define PORT_PIN_E5        69
    #define PORT_PIN_E6        70
    #define PORT_PIN_E7        71
    #define PORT_PIN_E8        72
    #define PORT_PIN_E9        73
    #define PORT_PIN_E10       74
    #define PORT_PIN_E11       75
    #define PORT_PIN_E12       76
    #define PORT_PIN_E13       77
    #define PORT_PIN_E14       78
    #define PORT_PIN_E15       79

    #define PORT_PIN_F0        80
    #define PORT_PIN_F1        81
    #define PORT_PIN_F2        82
    #define PORT_PIN_F3        83
    #define PORT_PIN_F4        84
    #define PORT_PIN_F5        85
    #define PORT_PIN_F6        86
    #define PORT_PIN_F7        87
    #define PORT_PIN_F8        88
    #define PORT_PIN_F9        89
    #define PORT_PIN_F10       90
    #define PORT_PIN_F11       91
    #define PORT_PIN_F12       92
    #define PORT_PIN_F13       93
    #define PORT_PIN_F14       94
    #define PORT_PIN_F15       95

    #define PORT_PIN_G0        96
    #define PORT_PIN_G1        97
    #define PORT_PIN_G2        98
    #define PORT_PIN_G3        99
    #define PORT_PIN_G4       100
    #define PORT_PIN_G5       101
    #define PORT_PIN_G6       102
    #define PORT_PIN_G7       103
    #define PORT_PIN_G8       104
    #define PORT_PIN_G9       105
    #define PORT_PIN_G10      106
    #define PORT_PIN_G11      107

#if (PROCESSOR == CPU_SPC560B)

    #define PORT_PIN_G12      108
    #define PORT_PIN_G13      109
    #define PORT_PIN_G14      110
    #define PORT_PIN_G15      111

    #define PORT_PIN_H0       112
    #define PORT_PIN_H1       113
    #define PORT_PIN_H2       114
    #define PORT_PIN_H3       115
    #define PORT_PIN_H4       116
    #define PORT_PIN_H5       117
    #define PORT_PIN_H6       118
    #define PORT_PIN_H7       119
    #define PORT_PIN_H8       120

    #define PORT_PIN_CAN0TX    16
    #define PORT_PIN_CAN0RX    17
    
    #define PORT_PIN_CAN1TX    42
    #define PORT_PIN_CAN1RX    43
    
    #define PORT_PIN_CAN2TX    88
    #define PORT_PIN_CAN2RX    89
    
    #define PORT_PIN_LIN0TX    18
    #define PORT_PIN_LIN0RX    19

    #define PORT_PIN_LIN1TX    38
    #define PORT_PIN_LIN1RX    39
   
    #define PORT_PIN_LIN2TX    40
    #define PORT_PIN_LIN2RX    41
    
    #define PORT_PIN_LIN3TX    74
    #define PORT_PIN_LIN3RX    75
    
    #define PORT_PIN_CLKOUT     0
    
    #define PORT_PIN_E0UC0      0
    #define PORT_PIN_E0UC1      1
    #define PORT_PIN_E0UC2      2
    #define PORT_PIN_E0UC3      3
    #define PORT_PIN_E0UC4      4
    #define PORT_PIN_E0UC5      5
    #define PORT_PIN_E0UC6      6
    #define PORT_PIN_E0UC7      7
    #define PORT_PIN_E0UC8      8
    #define PORT_PIN_E0UC9      9
    #define PORT_PIN_E0UC10    10
    #define PORT_PIN_E0UC11    11
    #define PORT_PIN_E0UC12    12
    #define PORT_PIN_E0UC13    13
    #define PORT_PIN_E0UC14    14
    #define PORT_PIN_E0UC15    15
    #define PORT_PIN_E0UC16    64
    #define PORT_PIN_E0UC17    65
    #define PORT_PIN_E0UC18    66
    #define PORT_PIN_E0UC19    67
    #define PORT_PIN_E0UC20    68
    #define PORT_PIN_E0UC21    69
    #define PORT_PIN_E0UC22    70
    #define PORT_PIN_E0UC23    71
    #define PORT_PIN_E0UC24   106
    #define PORT_PIN_E0UC25   107
    #define PORT_PIN_E0UC26   108
    #define PORT_PIN_E0UC27   109
    
    #define PORT_PIN_E1UC0    110
    #define PORT_PIN_E1UC1    111
    #define PORT_PIN_E1UC2    112
    #define PORT_PIN_E1UC3    113
    #define PORT_PIN_E1UC4    114
    #define PORT_PIN_E1UC5    115
    #define PORT_PIN_E1UC6    116
    #define PORT_PIN_E1UC7    117
    #define PORT_PIN_E1UC8    118
    #define PORT_PIN_E1UC9    119
    #define PORT_PIN_E1UC10   120
    #define PORT_PIN_E1UC11    98
    #define PORT_PIN_E1UC12    99
    #define PORT_PIN_E1UC13   100
    #define PORT_PIN_E1UC14   101
    #define PORT_PIN_E1UC15   102
    #define PORT_PIN_E1UC16   103
    #define PORT_PIN_E1UC17   104
    #define PORT_PIN_E1UC18   105
    #define PORT_PIN_E1UC19    76
    #define PORT_PIN_E1UC20    77
    #define PORT_PIN_E1UC21    78
    #define PORT_PIN_E1UC22    79
    #define PORT_PIN_E1UC23    96
    #define PORT_PIN_E1UC24    97
    #define PORT_PIN_E1UC25    92
    #define PORT_PIN_E1UC26    93
    #define PORT_PIN_E1UC27    94

    #define PORT_PIN_TDI       32
    #define PORT_PIN_TDO       33        

#endif            

#if (PROCESSOR == CPU_SPC560P)

    #define PORT_PIN_CAN0TX         16
    #define PORT_PIN_CAN0RX         17
    
    #define PORT_PIN_LIN0TX         18
    #define PORT_PIN_LIN0RX         19

    #define PORT_PIN_LIN1TX         35
    #define PORT_PIN_LIN1RX         29

    #define PORT_PIN_DSPI0SIN       39
    #define PORT_PIN_DSPI0SOUT      38
    #define PORT_PIN_DSPI0SCK       37
    #define PORT_PIN_DSPI0CS0       36
    #define PORT_PIN_DSPI0CS1       35
    #define PORT_PIN_DSPI0CS2       54
    #define PORT_PIN_DSPI0CS3       53
    #define PORT_PIN_DSPI0CS4       55
    #define PORT_PIN_DSPI0CS5       56
    #define PORT_PIN_DSPI0CS6       40
    #define PORT_PIN_DSPI0CS7        5

    #define PORT_PIN_DSPI1SIN        8
    #define PORT_PIN_DSPI1SOUT       7
    #define PORT_PIN_DSPI1SCK        6
    #define PORT_PIN_DSPI1CS0        5
    #define PORT_PIN_DSPI1CS1       40
    #define PORT_PIN_DSPI1CS2       56
    #define PORT_PIN_DSPI1CS3       55

    #define PORT_PIN_DSPI2SIN       13
    #define PORT_PIN_DSPI2SOUT      12
    #define PORT_PIN_DSPI2SCK       11
    #define PORT_PIN_DSPI2CS0       10
    #define PORT_PIN_DSPI2CS1        9
    #define PORT_PIN_DSPI2CS2       42
    #define PORT_PIN_DSPI2CS3       41

    #define PORT_PIN_DSPI3SIN       55
    #define PORT_PIN_DSPI3SOUT      12
    #define PORT_PIN_DSPI3SCK       11
    #define PORT_PIN_DSPI3CS0       58
    #define PORT_PIN_DSPI3CS1       59
    #define PORT_PIN_DSPI3CS2       61
    #define PORT_PIN_DSPI3CS3       62

    #define PORT_PIN_FLEXPWM0A0     11
    #define PORT_PIN_FLEXPWM0A1     47
    #define PORT_PIN_FLEXPWM0A2     12
    #define PORT_PIN_FLEXPWM0A3     51
    #define PORT_PIN_FLEXPWM0B0     10
    #define PORT_PIN_FLEXPWM0B1     48
    #define PORT_PIN_FLEXPWM0B2     13
    #define PORT_PIN_FLEXPWM0B3     52
    #define PORT_PIN_FLEXPWM0X0     57
    #define PORT_PIN_FLEXPWM0X1     36
    #define PORT_PIN_FLEXPWM0X2     98
    #define PORT_PIN_FLEXPWM0X3     41
    #define PORT_PIN_FLEXPWM0F0      9
    #define PORT_PIN_FLEXPWM0F1     42
    #define PORT_PIN_FLEXPWM0F2     40
    #define PORT_PIN_FLEXPWM0F3     37
    #define PORT_PIN_FLEXPWM0E      45
    
    #define PORT_PIN_ETIMER0ETC0     0
    #define PORT_PIN_ETIMER0ETC1     1
    #define PORT_PIN_ETIMER0ETC2     2
    #define PORT_PIN_ETIMER0ETC3     3
    #define PORT_PIN_ETIMER0ETC4    43
    #define PORT_PIN_ETIMER0ETC5    44

    #define PORT_PIN_ETIMER1ETC0     4
    #define PORT_PIN_ETIMER1ETC1    45
    #define PORT_PIN_ETIMER1ETC2    46
    #define PORT_PIN_ETIMER1ETC3    92
    #define PORT_PIN_ETIMER1ETC4    93
    #define PORT_PIN_ETIMER1ETC5     5
    
    #define PORT_PIN_FLEXRAY0CATREN 47
    #define PORT_PIN_FLEXRAY0CARX   49
    #define PORT_PIN_FLEXRAY0CATX   48
    #define PORT_PIN_FLEXRAY0CBTREN 52
    #define PORT_PIN_FLEXRAY0CBRX   50
    #define PORT_PIN_FLEXRAY0CBTX   51
    #define PORT_PIN_FLEXRAY0DBG0   80
    #define PORT_PIN_FLEXRAY0DBG1   81
    #define PORT_PIN_FLEXRAY0DBG2   82
    #define PORT_PIN_FLEXRAY0DBG3   83

    #define PORT_PIN_CLKOUT         22

    #define PORT_PIN_ADC0AN0        23
    #define PORT_PIN_ADC0AN1        24
    #define PORT_PIN_ADC0AN2        33
    #define PORT_PIN_ADC0AN3        34
    #define PORT_PIN_ADC0AN4        65
    #define PORT_PIN_ADC0AN5        66
    #define PORT_PIN_ADC0AN6        67
    #define PORT_PIN_ADC0AN7        68
    #define PORT_PIN_ADC0AN8        69
    #define PORT_PIN_ADC0AN9        70
    #define PORT_PIN_ADC0AN10       71
    #define PORT_PIN_ADC0AN11       25
    #define PORT_PIN_ADC0AN12       26
    #define PORT_PIN_ADC0AN13       27
    #define PORT_PIN_ADC0AN14       28

    #define PORT_PIN_ADC1AN0        29
    #define PORT_PIN_ADC1AN1        30
    #define PORT_PIN_ADC1AN2        31
    #define PORT_PIN_ADC1AN3        32
    #define PORT_PIN_ADC1AN4        63
    #define PORT_PIN_ADC1AN5        64
    #define PORT_PIN_ADC1AN6        72
    #define PORT_PIN_ADC1AN7        73
    #define PORT_PIN_ADC1AN8        74
    #define PORT_PIN_ADC1AN9        75
    #define PORT_PIN_ADC1AN10       76
    #define PORT_PIN_ADC1AN11       25
    #define PORT_PIN_ADC1AN12       26
    #define PORT_PIN_ADC1AN13       27
    #define PORT_PIN_ADC1AN14       28
    
    #define PORT_PIN_CTU0EXTIN      45
    #define PORT_PIN_CTU0EXTTRG     46
    
    #define PORT_PIN_FCU0F0         53
    #define PORT_PIN_FCU0F1         55

#endif

#if (PROCESSOR == CPU_SPC56EL)

    #define PORT_PIN_CAN0TX         16
    #define PORT_PIN_CAN0RX         17
    
    #define PORT_PIN_CAN1TX         14
    #define PORT_PIN_CAN1RX         15
    
    #define PORT_PIN_LIN0TX         18
    #define PORT_PIN_LIN0RX         19

    #define PORT_PIN_LIN1TX         35
    #define PORT_PIN_LIN1RX         29

    #define PORT_PIN_DSPI0SIN       39
    #define PORT_PIN_DSPI0SOUT      38
    #define PORT_PIN_DSPI0SCK       37
    #define PORT_PIN_DSPI0CS0       36
    #define PORT_PIN_DSPI0CS1       35
    #define PORT_PIN_DSPI0CS2       54
    #define PORT_PIN_DSPI0CS3       53
    #define PORT_PIN_DSPI0CS4       55
    #define PORT_PIN_DSPI0CS5       56
    #define PORT_PIN_DSPI0CS6       40
    #define PORT_PIN_DSPI0CS7        5

    #define PORT_PIN_DSPI1SIN        8
    #define PORT_PIN_DSPI1SOUT       7
    #define PORT_PIN_DSPI1SCK        6
    #define PORT_PIN_DSPI1CS0        5
    #define PORT_PIN_DSPI1CS1       40
    #define PORT_PIN_DSPI1CS2       56
    #define PORT_PIN_DSPI1CS3       55

    #define PORT_PIN_DSPI2SIN       13
    #define PORT_PIN_DSPI2SOUT      12
    #define PORT_PIN_DSPI2SCK       11
    #define PORT_PIN_DSPI2CS0       10
    #define PORT_PIN_DSPI2CS1        9
    #define PORT_PIN_DSPI2CS2       42
    #define PORT_PIN_DSPI2CS3       41

    #define PORT_PIN_DSPI3SIN       55
    #define PORT_PIN_DSPI3SOUT      12
    #define PORT_PIN_DSPI3SCK       11
    #define PORT_PIN_DSPI3CS0       58
    #define PORT_PIN_DSPI3CS1       59
    #define PORT_PIN_DSPI3CS2       61
    #define PORT_PIN_DSPI3CS3       62

    #define PORT_PIN_FLEXPWM0A0     11
    #define PORT_PIN_FLEXPWM0A1     47
    #define PORT_PIN_FLEXPWM0A2     12
    #define PORT_PIN_FLEXPWM0A3     51
    #define PORT_PIN_FLEXPWM0B0     10
    #define PORT_PIN_FLEXPWM0B1     48
    #define PORT_PIN_FLEXPWM0B2     13
    #define PORT_PIN_FLEXPWM0B3     52
    #define PORT_PIN_FLEXPWM0X0     57
    #define PORT_PIN_FLEXPWM0X1     36
    #define PORT_PIN_FLEXPWM0X2     98
    #define PORT_PIN_FLEXPWM0X3     41
    #define PORT_PIN_FLEXPWM0F0      9
    #define PORT_PIN_FLEXPWM0F1     42
    #define PORT_PIN_FLEXPWM0F2     40
    #define PORT_PIN_FLEXPWM0F3     37
    #define PORT_PIN_FLEXPWM0E      45
    
    #define PORT_PIN_ETIMER0ETC0     0
    #define PORT_PIN_ETIMER0ETC1     1
    #define PORT_PIN_ETIMER0ETC2     2
    #define PORT_PIN_ETIMER0ETC3     3
    #define PORT_PIN_ETIMER0ETC4    43
    #define PORT_PIN_ETIMER0ETC5    44

    #define PORT_PIN_ETIMER1ETC0     4
    #define PORT_PIN_ETIMER1ETC1    45
    #define PORT_PIN_ETIMER1ETC2    46
    #define PORT_PIN_ETIMER1ETC3    92
    #define PORT_PIN_ETIMER1ETC4    93
    #define PORT_PIN_ETIMER1ETC5     5
    
    #define PORT_PIN_FLEXRAY0CATREN 47
    #define PORT_PIN_FLEXRAY0CARX   49
    #define PORT_PIN_FLEXRAY0CATX   48
    #define PORT_PIN_FLEXRAY0CBTREN 52
    #define PORT_PIN_FLEXRAY0CBRX   50
    #define PORT_PIN_FLEXRAY0CBTX   51
    #define PORT_PIN_FLEXRAY0DBG0   80
    #define PORT_PIN_FLEXRAY0DBG1   81
    #define PORT_PIN_FLEXRAY0DBG2   82
    #define PORT_PIN_FLEXRAY0DBG3   83

    #define PORT_PIN_CLKOUT         22

    #define PORT_PIN_ADC0AN0        23
    #define PORT_PIN_ADC0AN1        24
    #define PORT_PIN_ADC0AN2        33
    #define PORT_PIN_ADC0AN3        34
    #define PORT_PIN_ADC0AN4        65
    #define PORT_PIN_ADC0AN5        66
    #define PORT_PIN_ADC0AN6        67
    #define PORT_PIN_ADC0AN7        68
    #define PORT_PIN_ADC0AN8        69
    #define PORT_PIN_ADC0AN9        70
    #define PORT_PIN_ADC0AN10       71
    #define PORT_PIN_ADC0AN11       25
    #define PORT_PIN_ADC0AN12       26
    #define PORT_PIN_ADC0AN13       27
    #define PORT_PIN_ADC0AN14       28

    #define PORT_PIN_ADC1AN0        29
    #define PORT_PIN_ADC1AN1        30
    #define PORT_PIN_ADC1AN2        31
    #define PORT_PIN_ADC1AN3        32
    #define PORT_PIN_ADC1AN4        63
    #define PORT_PIN_ADC1AN5        64
    #define PORT_PIN_ADC1AN6        72
    #define PORT_PIN_ADC1AN7        73
    #define PORT_PIN_ADC1AN8        74
    #define PORT_PIN_ADC1AN9        75
    #define PORT_PIN_ADC1AN10       76
    #define PORT_PIN_ADC1AN11       25
    #define PORT_PIN_ADC1AN12       26
    #define PORT_PIN_ADC1AN13       27
    #define PORT_PIN_ADC1AN14       28
    
    #define PORT_PIN_CTU0EXTIN      45
    #define PORT_PIN_CTU0EXTTRG     46
    
    #define PORT_PIN_FCCUF0         96
    #define PORT_PIN_FCCUF1         97

#endif

// ****************************************************************************
// *********************** Function Prototypes ********************************
// ****************************************************************************
   
    //sets given port pin to output
    #define PORT_PIN_SET2OUTPUT(pin) SIU.PCR[pin].R = PORT_PINCFG_ALTERNATE_MODE0_IO | PORT_PINCFG_OUTPUT_BUFFER_ENABLE | \
                                                      PORT_PINCFG_MEDIUM_SLEW_RATE;
    
    //sets given port pin to input
    #define PORT_PIN_SET2INPUT(pin)  SIU.PCR[pin].R = PORT_PINCFG_ALTERNATE_MODE0_IO | PORT_PINCFG_INPUT_BUFFER_ENABLE | \
                                                      PORT_PINCFG_MEDIUM_SLEW_RATE;

#endif

// ***************************** End of ports.h *****************************
