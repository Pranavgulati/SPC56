/*
    SPC5 HAL - Copyright (C) 2013 STMicroelectronics

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    boot.h
 * @brief   Boot parameters for the SPC56ELxx.
 * @{
 */

#ifndef _BOOT_H_
#define _BOOT_H_

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/


// FCCU module constants
#define FCCU_BASE           0xFFE6C000  // FCCU module base address
#define FCCU_REG_CTRL       0x0000    // registers offset
#define FCCU_REG_CF0        0x006C
#define FCCU_REG_CF1        0x0070
#define FCCU_REG_CFK        0x007C
#define FCCU_REG_NCF        0x0080
#define FCCU_REG_NCFK       0x0090
#define FCCU_REG_STATUS     0x00C0
#define FCCU_REG_IRQ        0x00E0
#define FCCU_OPR_STATUS     0x3    // command to read Status
#define FCCU_OPR_CF_READ    0x9    // command to read CF
#define FCCU_OPR_NCF_READ   0xA    // command to read NCF
#define FCCU_CFK_KEY        0x618B7A50  // key for CF faults clear operation
#define FCCU_NCFK_KEY       0xAB3498FE  // key for NCF faults clear operation
#define FCCU_OPS_SUCCESS    3    // command successful status to wait for
#define FCCU_CF_STCU        0x0850    // upper half word for compare instruction
#define FCCU_NCF12          19    // BSTI instr has inverse bit numbering

// RGM module constants
#define RGM_BASE            0xC3FE4000  // Reset module base address
#define RGM_REG_FESDES      0x0000    // register offset from RGM_BASE
#define RGM_DES_MASK        0x8000FFFF  // Destructive resets status bit mask

// MODE ENTRY module constants
#define ME_BASE             0xC3FDC000  // Mode Entry base address
#define ME_REG_GS           0x0000    // register offsets from ME_BASE
#define ME_REG_MCTL         0x0004
#define ME_REG_DRUN_MC      0x002C
#define ME_REG_RUN_PC1      0x0084
#define ME_REG_PCTL_CRC     0x00FA
#define ME_GS_MODE_SAFE     2    // current mode SAFE
#define ME_GS_MODE_DRUN     3    // current mode DRUN
#define ME_GS_MTRANS        4    // position of bit for e_btsti instr.
#define ME_GS_SYSCLK_MASK   0x000F    // mask of system clk field
#define ME_MCTL_DRUN_R1     0x30005AF0  // 1.step in mode transition request
#define ME_MCTL_DRUN_R2     0x3000A50F  // 2.step in mode transition request
#define ME_MC_XOSCON        26    // bit position for se_bseti instr.
#define ME_MC_PLL0ON        25    // bit position for se_bseti instr.
#define ME_MC_SYSCLK_PLL    0x0004    // value for e_or2i instr.
#define ME_RUNPC_DRUN       28    // bit position for se_bseti instr.
#define ME_PCTL_RUNPC1      1    // pointer to RUN_PC1 configuration

/**
 * @name   MASx registers definitions
 * @{
 */
#define MAS0_TBLMAS_TBL         0x10000000
#define MAS0_ESEL_MASK          0x000F0000
#define MAS0_ESEL(n)            ((n) << 16)

#define MAS1_VALID              0x80000000
#define MAS1_IPROT              0x40000000
#define MAS1_TID_MASK           0x00FF0000
#define MAS1_TS                 0x00001000
#define MAS1_TSISE_MASK         0x00000F80
#define MAS1_TSISE_1K           0x00000000
#define MAS1_TSISE_2K           0x00000080
#define MAS1_TSISE_4K           0x00000100
#define MAS1_TSISE_8K           0x00000180
#define MAS1_TSISE_16K          0x00000200
#define MAS1_TSISE_32K          0x00000280
#define MAS1_TSISE_64K          0x00000300
#define MAS1_TSISE_128K         0x00000380
#define MAS1_TSISE_256K         0x00000400
#define MAS1_TSISE_512K         0x00000480
#define MAS1_TSISE_1M           0x00000500
#define MAS1_TSISE_2M           0x00000580
#define MAS1_TSISE_4M           0x00000600
#define MAS1_TSISE_8M           0x00000680
#define MAS1_TSISE_16M          0x00000700
#define MAS1_TSISE_32M          0x00000780
#define MAS1_TSISE_64M          0x00000800
#define MAS1_TSISE_128M         0x00000880
#define MAS1_TSISE_256M         0x00000900
#define MAS1_TSISE_512M         0x00000980
#define MAS1_TSISE_1G           0x00000A00
#define MAS1_TSISE_2G           0x00000A80
#define MAS1_TSISE_4G           0x00000B00

#define MAS2_EPN_MASK           0xFFFFFC00
#define MAS2_EPN(n)             ((n) & MAS2_EPN_MASK)
#define MAS2_EBOOK              0x00000000
#define MAS2_VLE                0x00000020
#define MAS2_W                  0x00000010
#define MAS2_I                  0x00000008
#define MAS2_M                  0x00000004
#define MAS2_G                  0x00000002
#define MAS2_E                  0x00000001

#define MAS3_RPN_MASK           0xFFFFFC00
#define MAS3_RPN(n)             ((n) & MAS3_RPN_MASK)
#define MAS3_U0                 0x00000200
#define MAS3_U1                 0x00000100
#define MAS3_U2                 0x00000080
#define MAS3_U3                 0x00000040
#define MAS3_UX                 0x00000020
#define MAS3_SX                 0x00000010
#define MAS3_UW                 0x00000008
#define MAS3_SW                 0x00000004
#define MAS3_UR                 0x00000002
#define MAS3_SR                 0x00000001
/** @} */

/**
 * @name    BUCSR registers definitions
 * @{
 */
#define BUCSR_BPEN              0x00000001
#define BUCSR_BPRED_MASK        0x00000006
#define BUCSR_BPRED_0           0x00000000
#define BUCSR_BPRED_1           0x00000002
#define BUCSR_BPRED_2           0x00000004
#define BUCSR_BPRED_3           0x00000006
#define BUCSR_BALLOC_MASK       0x00000030
#define BUCSR_BALLOC_0          0x00000000
#define BUCSR_BALLOC_1          0x00000010
#define BUCSR_BALLOC_2          0x00000020
#define BUCSR_BALLOC_3          0x00000030
#define BUCSR_BALLOC_BFI        0x00000200
/** @} */

/**
 * @name    LICSR1 registers definitions
 * @{
 */
#define LICSR1_ICE              0x00000001
#define LICSR1_ICINV            0x00000002
#define LICSR1_ICORG            0x00000010
/** @} */

/**
 * @name   MSR register definitions
 * @{
 */
#define MSR_UCLE                0x04000000
#define MSR_SPE                 0x02000000
#define MSR_WE                  0x00040000
#define MSR_CE                  0x00020000
#define MSR_EE                  0x00008000
#define MSR_PR                  0x00004000
#define MSR_FP                  0x00002000
#define MSR_ME                  0x00001000
#define MSR_FE0                 0x00000800
#define MSR_DE                  0x00000200
#define MSR_FE1                 0x00000100
#define MSR_IS                  0x00000020
#define MSR_DS                  0x00000010
#define MSR_RI                  0x00000002
/** @} */

/*===========================================================================*/
/* Module compile time settings.                                             */
/*===========================================================================*/

/*
 * TLB default settings.
 */
#define TLB0_MAS0               (MAS0_TBLMAS_TBL | MAS0_ESEL(0))
#define TLB0_MAS1               (MAS1_VALID | MAS1_IPROT | MAS1_TSISE_2M)
#define TLB0_MAS2               (MAS2_EPN(0x00000000) | MAS2_VLE)
#define TLB0_MAS3               (MAS3_RPN(0x00000000) |                     \
                                 MAS3_UX | MAS3_SX | MAS3_UW | MAS3_SW |    \
                                 MAS3_UR | MAS3_SR)

#define TLB1_MAS0               (MAS0_TBLMAS_TBL | MAS0_ESEL(1))
#define TLB1_MAS1               (MAS1_VALID | MAS1_IPROT | MAS1_TSISE_256K)
#define TLB1_MAS2               (MAS2_EPN(0x40000000) | MAS2_VLE)
#define TLB1_MAS3               (MAS3_RPN(0x40000000) |                     \
                                 MAS3_UX | MAS3_SX | MAS3_UW | MAS3_SW |    \
                                 MAS3_UR | MAS3_SR)

#define TLB2_MAS0               (MAS0_TBLMAS_TBL | MAS0_ESEL(2))
#define TLB2_MAS1               (MAS1_VALID | MAS1_IPROT | MAS1_TSISE_1M)
#define TLB2_MAS2               (MAS2_EPN(0xC3F00000) | MAS2_I)
#define TLB2_MAS3               (MAS3_RPN(0xC3F00000) |                     \
                                 MAS3_UW | MAS3_SW | MAS3_UR | MAS3_SR)

#define TLB3_MAS0               (MAS0_TBLMAS_TBL | MAS0_ESEL(3))
#define TLB3_MAS1               (MAS1_VALID | MAS1_IPROT | MAS1_TSISE_1M)
#define TLB3_MAS2               (MAS2_EPN(0xFFE00000) | MAS2_I)
#define TLB3_MAS3               (MAS3_RPN(0xFFE00000) |                     \
                                 MAS3_UW | MAS3_SW | MAS3_UR | MAS3_SR)

#define TLB4_MAS0               (MAS0_TBLMAS_TBL | MAS0_ESEL(4))
#define TLB4_MAS1               (MAS1_VALID | MAS1_IPROT | MAS1_TSISE_1M)
#define TLB4_MAS2               (MAS2_EPN(0x8FF00000) | MAS2_I)
#define TLB4_MAS3               (MAS3_RPN(0x8FF00000) |                     \
                                 MAS3_UW | MAS3_SW | MAS3_UR | MAS3_SR)

#define TLB5_MAS0               (MAS0_TBLMAS_TBL | MAS0_ESEL(5))
#define TLB5_MAS1               (MAS1_VALID | MAS1_IPROT | MAS1_TSISE_1M)
#define TLB5_MAS2               (MAS2_EPN(0xFFF00000) | MAS2_I)
#define TLB5_MAS3               (MAS3_RPN(0xFFF00000) |                     \
                                 MAS3_UW | MAS3_SW | MAS3_UR | MAS3_SR)

/*
 * BUCSR default settings.
 */
#define BUCSR_DEFAULT           (BUCSR_BPEN | BUCSR_BPRED_0 |               \
                                 BUCSR_BALLOC_0 | BUCSR_BALLOC_BFI)

/*
 * LICSR1 default settings.
 */
#define LICSR1_DEFAULT          (LICSR1_ICE | LICSR1_ICORG)

/*
 * MSR default settings.
 */
#define MSR_DEFAULT             (MSR_SPE | MSR_WE | MSR_CE | MSR_ME)

/*
 * Boot default settings.
 */
#if ((BOOT_MODE == 0) || (BOOT_MODE == 1))
#define BOOT_PERFORM_CORE_INIT  1
#else
#define BOOT_PERFORM_CORE_INIT  0
#endif

/*
 * VLE mode default settings.
 */
#define BOOT_USE_VLE            1

/*
 * RAM relocation flag.
 */
#if (BOOT_MODE == 1)
#define BOOT_RELOCATE_IN_RAM    1
#else
#define BOOT_RELOCATE_IN_RAM    0
#endif

#endif /* _BOOT_H_ */

/** @} */
