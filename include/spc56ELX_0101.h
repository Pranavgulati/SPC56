/*****************************************************************
* PROJECT : 	LEOPARD
* FILE : 		spc56ELX_0101.h
*
* DESCRIPTION : spc56ELx header file
*
* COPYRIGHT :(c) year, Freescale & STMicroelectronics
*
* VERSION : 1.4
* DATE :    13.11.2009
* AUTHOR :  Giovanni D'Aquino (giovanni.daquino@st.com)
* HISTORY : Andrea Re has removed unused tag
* NOTE: All described <modules>_tag, register and so on have name
*		that derived from original IP. Final Name is equal to Pictus
*		naming
*		CTU may be not fully compatible with Pictus.
******************************************************************/
#include "typedefs.h"

#ifndef _JDP_H_
#define _JDP_H_
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
* Example instantiation and use:            
*                                           
*  <MODULE>.<REGISTER>.B.<BIT> = 1;         
*  <MODULE>.<REGISTER>.R       = 0x10000000;
*                                           
****************************************************************************/



/****************************************************************/
/*                                                              */
/* Module: CFLASH_SHADOW  										*/
/*                                                              */
/****************************************************************/

	/* Register layout for all registers NVPWD... */

	typedef union {   /* NVPWD0-1 - Non Volatile Private Censorship PassWorD Register */
		vuint32_t R;
		struct {
			vuint32_t  PWD:32;            /* PassWorD */
		} B;
	} CFLASH_SHADOW_NVPWD_32B_tag;


   /* Register layout for all registers NVSCI... */

   typedef union {   /* NVSCI - Non Volatile System Censoring Information Register */
      vuint32_t R;
      struct {
         vuint32_t  SC:16;             /* Serial Censorship Control Word */
         vuint32_t  CW:16;             /* Censorship Control Word */
      } B;
   } CFLASH_SHADOW_NVSCI_32B_tag;

   typedef union {   /* Non Volatile LML Default Value */
      vuint32_t R;
   } CFLASH_SHADOW_NVLML_32B_tag;

   typedef union {   /* Non Volatile HBL Default Value */
      vuint32_t R;
   } CFLASH_SHADOW_NVHBL_32B_tag;

   typedef union {   /* Non Volatile SLL Default Value */
      vuint32_t R;
   } CFLASH_SHADOW_NVSLL_32B_tag;


   /* Register layout for all registers NVBIU... */

   typedef union {   /* Non Volatile Bus Interface Unit Register */
      vuint32_t R;
      struct {
         vuint32_t  BI:32;             /* Bus interface Unit */
      } B;
   } CFLASH_SHADOW_NVBIU_32B_tag;

   typedef union {   /* NVUSRO - Non Volatile USeR Options Register */
      vuint32_t R;
      struct {
         vuint32_t  UO:32;             /* User Options */
      } B;
   } CFLASH_SHADOW_NVUSRO_32B_tag;

   typedef struct CFLASH_SHADOW_BIU_DEFAULTS_struct_tag {

	   /* Non Volatile Bus Interface Unit Register */
      CFLASH_SHADOW_NVBIU_32B_tag NVBIU;  /* relative offset: 0x0000 */
      int8_t CFLASH_SHADOW_BIU_DEFAULTS_reserved_0004[4];

   } CFLASH_SHADOW_BIU_DEFAULTS_tag;

   typedef struct CFLASH_SHADOW_struct_tag { /* start of CFLASH_SHADOW_tag */
      int8_t CFLASH_SHADOW_reserved_0000_C[15832];

	  /* NVPWD0-1 - Non Volatile Private Censorship PassWorD Register */
	  CFLASH_SHADOW_NVPWD_32B_tag NVPWD[2];  /* offset: 0x3DD8  (0x0004 x 2) */

	  /* NVSCI - Non Volatile System Censoring Information Register */
	  CFLASH_SHADOW_NVSCI_32B_tag NVSCI[2];  /* offset: 0x3DE0  (0x0004 x 2) */

	  /* Non Volatile LML Default Value */
      CFLASH_SHADOW_NVLML_32B_tag NVLML;   /* offset: 0x3DE8 size: 32 bit */
      int8_t CFLASH_SHADOW_reserved_3DEC[4];

	  /* Non Volatile HBL Default Value */
      CFLASH_SHADOW_NVHBL_32B_tag NVHBL;   /* offset: 0x3DF0 size: 32 bit */
      int8_t CFLASH_SHADOW_reserved_3DF4[4];

	  /* Non Volatile SLL Default Value */
      CFLASH_SHADOW_NVSLL_32B_tag NVSLL;   /* offset: 0x3DF8 size: 32 bit */
      int8_t CFLASH_SHADOW_reserved_3DFC_C[4];

	  /*  Register set BIU_DEFAULTS */
      CFLASH_SHADOW_BIU_DEFAULTS_tag BIU_DEFAULTS[3];  /* offset: 0x3E00  (0x0008 x 3) */

	  /* NVUSRO - Non Volatile USeR Options Register */
      CFLASH_SHADOW_NVUSRO_32B_tag NVUSRO;  /* offset: 0x3E18 size: 32 bit */

   } CFLASH_SHADOW_tag;


/****************************************************************/
/*                                                              */
/* Module: CFLASH  */
/*                                                              */
/****************************************************************/

   typedef union {   /* MCR - Module Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:5;
         vuint32_t  SIZE:3;            /* Array Space Size */
         vuint32_t:1;
         vuint32_t  LAS:3;             /* Low Address Space */
         vuint32_t:3;
         vuint32_t  MAS:1;             /* Mid Address Space Configuration */
         vuint32_t  EER:1;             /* ECC Event Error */
         vuint32_t  RWE:1;             /* Read-while-Write Event Error */
         vuint32_t  SBC:1;             /* Single Bit Correction */
         vuint32_t:1;
         vuint32_t  PEAS:1;            /* Program/Erase Access Space */
         vuint32_t  DONE:1;            /* modify operation DONE */
         vuint32_t  PEG:1;             /* Program/Erase Good */
         vuint32_t:4;
         vuint32_t  PGM:1;             /* Program Bit */
         vuint32_t  PSUS:1;            /* Program Suspend */
         vuint32_t  ERS:1;             /* Erase Bit */
         vuint32_t  ESUS:1;            /* Erase Suspend */
         vuint32_t  EHV:1;             /* Enable High Voltage */
      } B;
   } CFLASH_MCR_32B_tag;

   typedef union {   /* LML - Low/Mid Address Space Block Locking Register */
      vuint32_t R;
      struct {
         vuint32_t  LME:1;             /* Low/Mid Address Space Block Enable */
         vuint32_t:10;
         vuint32_t  TSLK:1;            /* Shadow Address Space Block Lock */
         vuint32_t:2;
         vuint32_t  MLK:2;             /* Mid Address Space Block Lock */
         vuint32_t:6;
         vuint32_t  LLOCK:10;          /* Low Address Space Block Lock */
      } B;
   } CFLASH_LML_32B_tag;

   typedef union {   /* HBL - High Address Space Block Locking Register */
      vuint32_t R;
      struct {
         vuint32_t  HBE:1;             /* High Address Space Block Enable */
         vuint32_t:25;
         vuint32_t  HLOCK:6;           /* High Address Space Block Lock */
      } B;
   } CFLASH_HBL_32B_tag;

   typedef union {   /* SLL - Secondary Low/Mid Address Space Block Locking Register */
      vuint32_t R;
      struct {
         vuint32_t  SLE:1;             /* Secondary Low/Mid Address Space Block Enable */
         vuint32_t:10;
         vuint32_t  STSLK:1;           /* Secondary Shadow Address Space Block Lock */
         vuint32_t:2;
         vuint32_t  SMK:2;             /* Secondary Mid Address Space Block Lock */
         vuint32_t:6;
         vuint32_t  SLLOCK:10;         /* Secondary Low Address Space Block Lock */
      } B;
   } CFLASH_SLL_32B_tag;

   typedef union {   /* LMS - Low/Mid Address Space Block Select Register */
      vuint32_t R;
      struct {
         vuint32_t:14;
         vuint32_t  MSL:2;             /* Mid Address Space Block Select */
         vuint32_t:6;
         vuint32_t  LSL:10;            /* Low Address Space Block Select */
      } B;
   } CFLASH_LMS_32B_tag;

   typedef union {   /* HBS - High Address Space Block Select Register */
      vuint32_t R;
      struct {
         vuint32_t:26;
         vuint32_t  HSL:6;             /* High Address Space Block Select */
      } B;
   } CFLASH_HBS_32B_tag;

   typedef union {   /* ADR - Address Register */
      vuint32_t R;
      struct {
         vuint32_t  SAD:1;             /* Shadow Address */
         vuint32_t:10;
         vuint32_t  ADDR:18;           /* Address */
         vuint32_t:3;
      } B;
   } CFLASH_ADR_32B_tag;

   typedef union {   /* PFLASH2P_LCA_PFCR0 - Platform Flash Configuration Register 0 */
      vuint32_t R;
      struct {
         vuint32_t  BK0_APC:5;         /* Bank0+2 Address Pipelining Control */
         vuint32_t  BK0_WWSC:5;        /* Bank0+2 Write Wait State Control */
         vuint32_t  BK0_RWSC:5;        /* Bank0+2 Read Wait State Control */
         vuint32_t  BK0_RWWC2:1;       /* Bank 0+2 Read While Write Control, bit 2 */
         vuint32_t  BK0_RWWC1:1;       /* Bank 0+2 Read While Write Control, bit 1 */
         vuint32_t  B0_P1_BCFG:2;      /* Bank0+2 Port 1 Page Buffer Configuration */
         vuint32_t  B0_P1_DPFE:1;      /* Bank0+2 Port 1 Data Prefetch Enable */
         vuint32_t  B0_P1_IPFE:1;      /* Bank0+2 Port 1 Inst Prefetch Enable */
         vuint32_t  B0_P1_PFLM:2;      /* Bank0+2 Port 1 Prefetch Limit */
         vuint32_t  B0_P1_BFE:1;       /* Bank0+2 Port 1 Buffer Enable */
         vuint32_t  BK0_RWWC0:1;       /* Bank 0+2 Read While Write Control, bit 0 */
         vuint32_t  B0_P0_BCFG:2;      /* Bank0+2 Port 0 Page Buffer Configuration */
         vuint32_t  B0_P0_DPFE:1;      /* Bank0+2 Port 0 Data Prefetch Enable */
         vuint32_t  B0_P0_IPFE:1;      /* Bank0+2 Port 0 Inst Prefetch Enable */
         vuint32_t  B0_P0_PFLM:2;      /* Bank0+2 Port 0 Prefetch Limit */
         vuint32_t  B0_P0_BFE:1;       /* Bank0+2 Port 0 Buffer Enable */
      } B;
   } CFLASH_PFCR0_32B_tag;


   /* Register layout for all registers BIU... */

   typedef union {   /* Bus Interface Unit Register */
      vuint32_t R;
   } CFLASH_BIU_32B_tag;

   typedef union {   /* PFLASH2P_LCA_PFCR1 - Platform Flash Configuration Register 1 */
      vuint32_t R;
      struct {
         vuint32_t BK1_APC:5;			/* Bank 1 Address Pipelining Control */
         vuint32_t BK1_WWSC:5;			/* Bank 1 Write Wait State Control */
         vuint32_t BK1_RWSC:5;			/* Bank 1 Read Wait State Control */ 
         vuint32_t BK1_RWWC2:1;			/* Bank1 Read While Write Control, bit 2 */
         vuint32_t BK1_RWWC1:1;			/* Bank1 Read While Write Control, bit 1 */      
         vuint32_t:6;
         vuint32_t B0_P1_BFE:1;			/* Bank 1 Port 1 Buffer Enable */
         vuint32_t BK1_RWWC0:1;			/* Bank1 Read While Write Control, bit 0 */
         vuint32_t:6;
         vuint32_t B1_P0_BFE:1;         /* Bank 1 Port 0 Buffer Enable */      
      } B;
   } CFLASH_PFCR1_32B_tag;

   typedef union {   /* PFLASH2P_LCA_PFAPR - Platform Flash Access Protection Register */
      vuint32_t R;
      struct {
         vuint32_t:6;
         vuint32_t  ARBM:2;            /* Arbitration Mode */
         vuint32_t  M7PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M6PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M5PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M4PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M3PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M2PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M1PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M0PFD:1;           /* Master x Prefetch Disable */
         vuint32_t  M7AP:2;            /* Master 7 Access Protection */
         vuint32_t  M6AP:2;            /* Master 6 Access Protection */
         vuint32_t  M5AP:2;            /* Master 5 Access Protection */
         vuint32_t  M4AP:2;            /* Master 4 Access Protection */
         vuint32_t  M3AP:2;            /* Master 3 Access Protection */
         vuint32_t  M2AP:2;            /* Master 2 Access Protection */
         vuint32_t  M1AP:2;            /* Master 1 Access Protection */
         vuint32_t  M0AP:2;            /* Master 0 Access Protection */
      } B;
   } CFLASH_PFAPR_32B_tag;

   typedef union {   /* UT0 - User Test Register */
      vuint32_t R;
      struct {
         vuint32_t  UTE:1;             /* User Test Enable */
         vuint32_t  SBCE:1;            /* Single Bit Correction Enable */
         vuint32_t:6;
         vuint32_t  DSI:8;             /* Data Syndrome Input */
         vuint32_t:10;
         vuint32_t  MRE:1;             /* Margin Read Enable */
         vuint32_t  MRV:1;             /* Margin Read Value */
         vuint32_t  EIE:1;             /* ECC Data Input Enable */
         vuint32_t  AIS:1;             /* Array Integrity Sequence */
         vuint32_t  AIE:1;             /* Array Integrity Enable */
         vuint32_t  AID:1;             /* Array Integrity Done */
      } B;
   } CFLASH_UT0_32B_tag;

   typedef union {   /* UT1 - User Test Register */
      vuint32_t R;
   } CFLASH_UT1_32B_tag;

   typedef union {   /* UT2 - User Test Register */
      vuint32_t R;
   } CFLASH_UT2_32B_tag;

   /* Register layout for all registers UM... */

   typedef union {   /* UM - User Multiple Input Signature Register */
      vuint32_t R;
      struct {
		  vuint32_t  MS:32;         /* Multiple Input Signature */
      } B;
   } CFLASH_UM_32B_tag;

   /* Register layout for generated register(s) UT... */

   typedef union {   /*  */
      vuint32_t R;
   } CFLASH_UT_32B_tag;

   /* Register layout for generated register(s) PFCR... */

   typedef union {   /*  */
      vuint32_t R;
   } CFLASH_PFCR_32B_tag;



   typedef struct CFLASH_struct_tag { /* start of CFLASH_tag */
	  /* MCR - Module Configuration Register */
      CFLASH_MCR_32B_tag MCR;              /* offset: 0x0000 size: 32 bit */
	  /* LML - Low/Mid Address Space Block Locking Register */
      CFLASH_LML_32B_tag LML;              /* offset: 0x0004 size: 32 bit */
	  /* HBL - High Address Space Block Locking Register */
      CFLASH_HBL_32B_tag HBL;              /* offset: 0x0008 size: 32 bit */
	  /* SLL - Secondary Low/Mid Address Space Block Locking Register */
      CFLASH_SLL_32B_tag SLL;              /* offset: 0x000C size: 32 bit */
	  /* LMS - Low/Mid Address Space Block Select Register */
      CFLASH_LMS_32B_tag LMS;              /* offset: 0x0010 size: 32 bit */
	  /* HBS - High Address Space Block Select Register */
      CFLASH_HBS_32B_tag HBS;              /* offset: 0x0014 size: 32 bit */
	  /* ADR - Address Register */
      CFLASH_ADR_32B_tag ADR;              /* offset: 0x0018 size: 32 bit */
        
	  /* PFLASH2P_LCA_PFCR0 - Platform Flash Configuration Register 0 */
	  CFLASH_PFCR0_32B_tag PFCR0;    /* offset: 0x001C size: 32 bit */
	  /* PFLASH2P_LCA_PFCR1 - Platform Flash Configuration Register 1 */
	  CFLASH_PFCR1_32B_tag PFCR1;    /* offset: 0x0020 size: 32 bit */
	  /* PFLASH2P_LCA_PFAPR - Platform Flash Access Protection Register */
	  CFLASH_PFAPR_32B_tag PFAPR;    /* offset: 0x0024 size: 32 bit */
	  int8_t CFLASH_reserved_0028_E4[8];

	  int8_t CFLASH_reserved_0030_C[12];

	  /* UT0 - User Test Register */
	  CFLASH_UT0_32B_tag UT0;        /* offset: 0x003C size: 32 bit */
	  /* UT1 - User Test Register */
	  CFLASH_UT1_32B_tag UT1;        /* offset: 0x0040 size: 32 bit */
	  /* UT2 - User Test Register */
	  CFLASH_UT2_32B_tag UT2;        /* offset: 0x0044 size: 32 bit */

	  CFLASH_UM_32B_tag UMISR[5];       /* offset: 0x0048  (0x0004 x 5) */

   } CFLASH_tag;


/****************************************************************/
/*                                                              */
/* Module: SIU  */
/*                                                              */
/****************************************************************/

   typedef union {   /* MIDR1 - MCU ID Register #1 */
      vuint32_t R;
      struct {
         vuint32_t  PARTNUM:16;        /* MCU Part Number */
         vuint32_t  CSP:1;             /* CSP Package */
         vuint32_t  PKG:5;             /* Package Settings */
         vuint32_t:2;
         vuint32_t  MAJORMASK:4;       /* Major Mask Revision */
         vuint32_t  MINORMASK:4;       /* Minor Mask Revision */
      } B;
   } SIUL_MIDR1_32B_tag;

   typedef union {   /* MIDR2 - MCU ID Register #2 */
      vuint32_t R;
      struct {
         vuint32_t  SF:1;              /* Manufacturer */
         vuint32_t  FLASH_SIZE_1:4;    /* Coarse Flash Memory Size */
         vuint32_t  FLASH_SIZE_2:4;    /* Fine Flash Memory Size */
         vuint32_t:7;
         vuint32_t  PARTNUM:8;         /* MCU Part Number */
         vuint32_t  TBD:1;             /* Optional Bit */
         vuint32_t:2;
         vuint32_t  EE:1;              /* Data Flash Present */
         vuint32_t:3;
         vuint32_t  FR:1;              /* Flexray Present */
      } B;
   } SIUL_MIDR2_32B_tag;

   typedef union {   /* ISR - Interrupt Status Flag Register */
      vuint32_t R;
      struct {
         vuint32_t  EIF31:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF30:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF29:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF28:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF27:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF26:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF25:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF24:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF23:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF22:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF21:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF20:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF19:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF18:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF17:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF16:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF15:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF14:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF13:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF12:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF11:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF10:1;           /* External Interrupt Status Flag */
         vuint32_t  EIF9:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF8:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF7:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF6:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF5:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF4:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF3:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF2:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF1:1;            /* External Interrupt Status Flag */
         vuint32_t  EIF0:1;            /* External Interrupt Status Flag */
      } B;
   } SIUL_ISR_32B_tag;

   typedef union {   /* IRER - Interrupt Request Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  EIRE31:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE30:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE29:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE28:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE27:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE26:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE25:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE24:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE23:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE22:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE21:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE20:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE19:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE18:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE17:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE16:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE15:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE14:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE13:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE12:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE11:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE10:1;          /* Enable External Interrupt Requests */
         vuint32_t  EIRE9:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE8:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE7:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE6:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE5:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE4:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE3:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE2:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE1:1;           /* Enable External Interrupt Requests */
         vuint32_t  EIRE0:1;           /* Enable External Interrupt Requests */
      } B;
   } SIUL_IRER_32B_tag;

   typedef union {   /* IREER - Interrupt Rising Edge Event Enable */
      vuint32_t R;
      struct {
         vuint32_t  IREE31:1;          /* Enable rising-edge events */
         vuint32_t  IREE30:1;          /* Enable rising-edge events */
         vuint32_t  IREE29:1;          /* Enable rising-edge events */
         vuint32_t  IREE28:1;          /* Enable rising-edge events */
         vuint32_t  IREE27:1;          /* Enable rising-edge events */
         vuint32_t  IREE26:1;          /* Enable rising-edge events */
         vuint32_t  IREE25:1;          /* Enable rising-edge events */
         vuint32_t  IREE24:1;          /* Enable rising-edge events */
         vuint32_t  IREE23:1;          /* Enable rising-edge events */
         vuint32_t  IREE22:1;          /* Enable rising-edge events */
         vuint32_t  IREE21:1;          /* Enable rising-edge events */
         vuint32_t  IREE20:1;          /* Enable rising-edge events */
         vuint32_t  IREE19:1;          /* Enable rising-edge events */
         vuint32_t  IREE18:1;          /* Enable rising-edge events */
         vuint32_t  IREE17:1;          /* Enable rising-edge events */
         vuint32_t  IREE16:1;          /* Enable rising-edge events */
         vuint32_t  IREE15:1;          /* Enable rising-edge events */
         vuint32_t  IREE14:1;          /* Enable rising-edge events */
         vuint32_t  IREE13:1;          /* Enable rising-edge events */
         vuint32_t  IREE12:1;          /* Enable rising-edge events */
         vuint32_t  IREE11:1;          /* Enable rising-edge events */
         vuint32_t  IREE10:1;          /* Enable rising-edge events */
         vuint32_t  IREE9:1;           /* Enable rising-edge events */
         vuint32_t  IREE8:1;           /* Enable rising-edge events */
         vuint32_t  IREE7:1;           /* Enable rising-edge events */
         vuint32_t  IREE6:1;           /* Enable rising-edge events */
         vuint32_t  IREE5:1;           /* Enable rising-edge events */
         vuint32_t  IREE4:1;           /* Enable rising-edge events */
         vuint32_t  IREE3:1;           /* Enable rising-edge events */
         vuint32_t  IREE2:1;           /* Enable rising-edge events */
         vuint32_t  IREE1:1;           /* Enable rising-edge events */
         vuint32_t  IREE0:1;           /* Enable rising-edge events */
      } B;
   } SIUL_IREER_32B_tag;

   typedef union {   /* IFEER - Interrupt Falling-Edge Event Enable */
      vuint32_t R;
      struct {
         vuint32_t  IFEE31:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE30:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE29:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE28:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE27:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE26:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE25:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE24:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE23:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE22:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE21:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE20:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE19:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE18:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE17:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE16:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE15:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE14:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE13:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE12:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE11:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE10:1;          /* Enable Falling Edge Events */
         vuint32_t  IFEE9:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE8:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE7:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE6:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE5:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE4:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE3:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE2:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE1:1;           /* Enable Falling Edge Events */
         vuint32_t  IFEE0:1;           /* Enable Falling Edge Events */
      } B;
   } SIUL_IFEER_32B_tag;

   typedef union {   /* IFER Interrupt Filter Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  IFE31:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE30:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE29:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE28:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE27:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE26:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE25:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE24:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE23:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE22:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE21:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE20:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE19:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE18:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE17:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE16:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE15:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE14:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE13:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE12:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE11:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE10:1;           /* Enable Digital Glitch Filter */
         vuint32_t  IFE9:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE8:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE7:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE6:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE5:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE4:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE3:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE2:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE1:1;            /* Enable Digital Glitch Filter */
         vuint32_t  IFE0:1;            /* Enable Digital Glitch Filter */
      } B;
   } SIUL_IFER_32B_tag;

   /* Register layout for all registers PCR... */

   typedef union {   /* PCR - Pad Configuration Register */
      vuint16_t R;
      struct {
         vuint16_t:1;
         vuint16_t  SME:1;             /* Safe Mode Control */
         vuint16_t  APC:1;             /* Analog Pad Control */
         vuint16_t:1;
         vuint16_t  PA:2;              /* Pad Output Assignment */
         vuint16_t  OBE:1;             /* Output Buffer Enable */
         vuint16_t  IBE:1;             /* Input Buffer Enable */
         vuint16_t  DCS:2;             /* Drive Strength Control */
         vuint16_t  ODE:1;             /* Open Drain Output Enable */
         vuint16_t  HYS:1;             /* Input Hysteresis */
         vuint16_t  SRC:2;             /* Slew Rate Control */
         vuint16_t  WPE:1;             /* Weak Pull Up/Down Enable */
         vuint16_t  WPS:1;             /* Weak Pull Up/Down Select */
      } B;
   } SIUL_PCR_16B_tag;

   /* Register layout for all registers PSMI... */

   typedef union {   /* PSMI - Pad Selection for Multiplexed Inputs */
      vuint8_t R;
      struct {
         vuint8_t:4;
         vuint8_t   PADSEL:4;          /* Pad selection for pin */
      } B;
   } SIUL_PSMI_8B_tag;

   /* Register layout for all registers PSMI... */

   typedef union {   /* PSMI - Pad Selection for Multiplexed Inputs */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  PADSEL0:4;         /* Pad selection for pin */
         vuint32_t:4;
         vuint32_t  PADSEL1:4;         /* Pad selection for pin */
         vuint32_t:4;
         vuint32_t  PADSEL2:4;         /* Pad selection for pin */
         vuint32_t:4;
         vuint32_t  PADSEL3:4;         /* Pad selection for pin */
      } B;
   } SIUL_PSMI_32B_tag;

   /* Register layout for all registers GPDO... */

   typedef union {   /* GPDO - GPIO Pad Data Output Register */
      vuint8_t R;
      struct {
         vuint8_t:7;
         vuint8_t   PDO:1;             /* Pad Data Out */
      } B;
   } SIUL_GPDO_8B_tag;

   /* Register layout for all registers GPDO... */

   typedef union {   /* GPDO - GPIO Pad Data Output Register */
      vuint32_t R;
      struct {
         vuint32_t:7;
         vuint32_t  PDO0:1;            /* Pad Data Out */
         vuint32_t:7;
         vuint32_t  PDO1:1;            /* Pad Data Out */
         vuint32_t:7;
         vuint32_t  PDO2:1;            /* Pad Data Out */
         vuint32_t:7;
         vuint32_t  PDO3:1;            /* Pad Data Out */
      } B;
   } SIUL_GPDO_32B_tag;

   /* Register layout for all registers GPDI... */

   typedef union {   /* GPDI - GPIO Pad Data Input Register */
      vuint8_t R;
      struct {
         vuint8_t:7;
         vuint8_t   PDI:1;             /* Pad Data In */
      } B;
   } SIUL_GPDI_8B_tag;

   /* Register layout for all registers GPDI... */

   typedef union {   /* GPDI - GPIO Pad Data Input Register */
      vuint32_t R;
      struct {
         vuint32_t:7;
         vuint32_t  PDI0:1;            /* Pad Data In */
         vuint32_t:7;
         vuint32_t  PDI1:1;            /* Pad Data In */
         vuint32_t:7;
         vuint32_t  PDI2:1;            /* Pad Data In */
         vuint32_t:7;
         vuint32_t  PDI3:1;            /* Pad Data In */
      } B;
   } SIUL_GPDI_32B_tag;

   /* Register layout for all registers PGPDO... */

   typedef union {   /* PGPDO - Parallel GPIO Pad Data Out Register */
	vuint32_t R;
	struct {
		vuint32_t PPD0:32;
	} B;
       
   } SIUL_PGPDO_32B_tag;

   /* Register layout for all registers PGPDI... */

   typedef union {   /* PGPDI - Parallel GPIO Pad Data In Register */
    vuint32_t R;
    struct {
        vuint32_t PPDI:32;
    } B;
   } SIUL_PGPDI_32B_tag;

   /* Register layout for all registers MPGPDO... */

   typedef union {   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
      vuint32_t R;
      struct {
         vuint32_t  MASK:16;           /* Mask Field */
         vuint32_t  MPPDO:16;          /* Masked Parallel Pad Data Out */
      } B;
   } SIUL_MPGPDO_32B_tag;


   /* Register layout for all registers IFMC... */

   typedef union {   /* IFMC - Interrupt Filter Maximum Counter Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  MAXCNT:4;          /* Maximum Interrupt Filter Counter Setting */
      } B;
   } SIUL_IFMC_32B_tag;

   typedef union {   /* IFCPR - Inerrupt Filter Clock Prescaler Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  IFCP:4;            /* Interrupt Filter Clock Prescaler Setting */
      } B;
   } SIUL_IFCPR_32B_tag;


   typedef struct SIUL_struct_tag { /* start of SIUL_tag */
	   int8_t SIUL_reserved_0000_C[4];

	   /* MIDR1 - MCU ID Register #1 */
	   SIUL_MIDR1_32B_tag MIDR;         		/* offset: 0x0004 size: 32 bit */

	   /* MIDR2 - MCU ID Register #2 */
	   SIUL_MIDR2_32B_tag MIDR2;				/* offset: 0x0008 size: 32 bit */

	   int8_t SIUL_reserved_000C[8];

	   /* ISR - Interrupt Status Flag Register */
	   SIUL_ISR_32B_tag ISR;                	/* offset: 0x0014 size: 32 bit */

	   /* IRER - Interrupt Request Enable Register */
	   SIUL_IRER_32B_tag IRER;              	/* offset: 0x0018 size: 32 bit */

	   int8_t SIUL_reserved_001C[12];

	   /* IREER - Interrupt Rising Edge Event Enable */
	   SIUL_IREER_32B_tag IREER;            	/* offset: 0x0028 size: 32 bit */

	   /* IFEER - Interrupt Falling-Edge Event Enable */
	   SIUL_IFEER_32B_tag IFEER;            	/* offset: 0x002C size: 32 bit */

	   /* IFER Interrupt Filter Enable Register */
	   SIUL_IFER_32B_tag IFER;              	/* offset: 0x0030 size: 32 bit */

	   int8_t SIUL_reserved_0034_C[12];

	   /* PCR - Pad Configuration Register */
	   SIUL_PCR_16B_tag PCR[512];       	 /* offset: 0x0040  (0x0002 x 512) */

	   int8_t SIUL_reserved_0440_C[192];

	   /* PSMI - Pad Selection for Multiplexed Inputs */
	   SIUL_PSMI_8B_tag PSMI[256];       /* offset: 0x0500  (0x0001 x 256) */


	   /* GPDO - GPIO Pad Data Output Register */
	   SIUL_GPDO_8B_tag GPDO[512];       /* offset: 0x0600  (0x0001 x 512) */

	   /* GPDI - GPIO Pad Data Input Register */
	   SIUL_GPDI_8B_tag GPDI[512];       /* offset: 0x0800  (0x0001 x 512) */

	   int8_t SIUL_reserved_0A00_C[512];

	   /* PGPDO - Parallel GPIO Pad Data Out Register */
	   SIUL_PGPDO_32B_tag PGPDO[16];     /* offset: 0x0C00  (0x0002 x 32) */

	   /* PGPDI - Parallel GPIO Pad Data In Register */
	   SIUL_PGPDI_32B_tag PGPDI[16];     /* offset: 0x0C40  (0x0002 x 32) */

	   /* MPGPDO - Masked Parallel GPIO Pad Data Out Register */
	   SIUL_MPGPDO_32B_tag MPGPDO[32];   /* offset: 0x0C80  (0x0004 x 32) */

	   int8_t SIUL_reserved_0D00_C[768];

	   /* IFMC - Interrupt Filter Maximum Counter Register */
	   SIUL_IFMC_32B_tag IFMC[32];       /* offset: 0x1000  (0x0004 x 32) */


	   /* IFCPR - Inerrupt Filter Clock Prescaler Register */
	   SIUL_IFCPR_32B_tag IFCPR;            /* offset: 0x1080 size: 32 bit */
	   
   } SIUL_tag;


/****************************************************************/
/*                                                              */
/* Module: WKUP  */
/*                                                              */
/****************************************************************/

   typedef union {   /* WKPU_NSR - NMI Status Flag Register */
      vuint32_t R;
      struct {
         vuint32_t  NIF0:1;            /* NMI Status Flag 0 */
         vuint32_t  NOVF0:1;           /* NMI Overrun Status Flag 0 */
         vuint32_t:6;
         vuint32_t  NIF1:1;            /* NMI Status Flag 1 */
         vuint32_t  NOVF1:1;           /* NMI Overrun Status Flag 1 */
         vuint32_t:6;
         vuint32_t  NIF2:1;            /* NMI Status Flag 2 */
         vuint32_t  NOVF2:1;           /* NMI Overrun Status Flag 2 */
         vuint32_t:6;
         vuint32_t  NIF3:1;            /* NMI Status Flag 3 */
         vuint32_t  NOVF3:1;           /* NMI Overrun Status Flag 3 */
         vuint32_t:6;
      } B;
   } WKPU_NSR_32B_tag;

   typedef union {   /* WKPU_NCR - NMI Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t  NLOCK0:1;          /* NMI Configuration Lock Register 0 */
         vuint32_t  NDSS0:2;           /* NMI Desination Source Select 0 */
         vuint32_t  NWRE0:1;           /* NMI Wakeup Request Enable 0 */
         vuint32_t:1;
         vuint32_t  NREE0:1;           /* NMI Rising Edge Events Enable 0 */
         vuint32_t  NFEE0:1;           /* NMI Falling Edge Events Enable 0 */
         vuint32_t  NFE0:1;            /* NMI Filter Enable 0 */
         vuint32_t  NLOCK1:1;          /* NMI Configuration Lock Register 1 */
         vuint32_t  NDSS1:2;           /* NMI Desination Source Select 1 */
         vuint32_t  NWRE1:1;           /* NMI Wakeup Request Enable 1 */
         vuint32_t:1;
         vuint32_t  NREE1:1;           /* NMI Rising Edge Events Enable 1 */
         vuint32_t  NFEE1:1;           /* NMI Falling Edge Events Enable 1 */
         vuint32_t  NFE1:1;            /* NMI Filter Enable 1 */
         vuint32_t  NLOCK2:1;          /* NMI Configuration Lock Register 2 */
         vuint32_t  NDSS2:2;           /* NMI Desination Source Select 2 */
         vuint32_t  NWRE2:1;           /* NMI Wakeup Request Enable 2 */
         vuint32_t:1;
         vuint32_t  NREE2:1;           /* NMI Rising Edge Events Enable 2 */
         vuint32_t  NFEE2:1;           /* NMI Falling Edge Events Enable 2 */
         vuint32_t  NFE2:1;            /* NMI Filter Enable 2 */
         vuint32_t  NLOCK3:1;          /* NMI Configuration Lock Register 3 */
         vuint32_t  NDSS3:2;           /* NMI Desination Source Select 3 */
         vuint32_t  NWRE3:1;           /* NMI Wakeup Request Enable 3 */
         vuint32_t:1;
         vuint32_t  NREE3:1;           /* NMI Rising Edge Events Enable 3 */
         vuint32_t  NFEE3:1;           /* NMI Falling Edge Events Enable 3 */
         vuint32_t  NFE3:1;            /* NMI Filter Enable 3 */
      } B;
   } WKPU_NCR_32B_tag;

   typedef union {   /* WKPU_WISR - Wakeup/Interrupt Status Flag Register */
      vuint32_t R;
      struct {
         vuint32_t  EIF:32;            /* External Wakeup/Interrupt Status Flag */
      } B;
   } WKPU_WISR_32B_tag;

   typedef union {   /* WKPU_IRER - Interrupt Request Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  EIRE:32;           /* Enable External Interrupt Requests */
      } B;
   } WKPU_IRER_32B_tag;

   typedef union {   /* WKPU_WRER - Wakeup Request Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  WRE:32;            /* Enable Wakeup requests to the mode entry module */
      } B;
   } WKPU_WRER_32B_tag;

   typedef union {   /* WKPU_WIREER - Wakeup/Interrupt Rising-Edge Event Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  IREE:32;           /* Enable rising-edge events to cause EIF[x] to be set */
      } B;
   } WKPU_WIREER_32B_tag;

   typedef union {   /* WKPU_WIFEER - Wakeup/Interrupt Falling-Edge Event Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  IFEE:32;           /* Enable Falling-edge events to cause EIF[x] to be set */
      } B;
   } WKPU_WIFEER_32B_tag;

   typedef union {   /* WKPU_WIFER - Wakeup/Interrupt Filter Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  IFE:32;            /* Enable Digital glitch filter on the interrupt pad input */
      } B;
   } WKPU_WIFER_32B_tag;

   typedef union {   /* WKPU_WIPUER - Wakeup/Interrupt Pullup Enable Register */
      vuint32_t R;
      struct {
         vuint32_t  IPUE:32;           /* Enable a pullup on the interrupt pad input */
      } B;
   } WKPU_WIPUER_32B_tag;



   typedef struct WKPU_struct_tag { /* start of WKPU_tag */
	  /* WKPU_NSR - NMI Status Flag Register */
      WKPU_NSR_32B_tag NSR;                /* offset: 0x0000 size: 32 bit */

	  int8_t WKPU_reserved_0004[4];

	  /* WKPU_NCR - NMI Configuration Register */
      WKPU_NCR_32B_tag NCR;                /* offset: 0x0008 size: 32 bit */

	  int8_t WKPU_reserved_000C[8];
	  /* WKPU_WISR - Wakeup/Interrupt Status Flag Register */
      WKPU_WISR_32B_tag WISR;              /* offset: 0x0014 size: 32 bit */
	  /* WKPU_IRER - Interrupt Request Enable Register */
      WKPU_IRER_32B_tag IRER;              /* offset: 0x0018 size: 32 bit */
	  /* WKPU_WRER - Wakeup Request Enable Register */
      WKPU_WRER_32B_tag WRER;              /* offset: 0x001C size: 32 bit */

	  int8_t WKPU_reserved_0020[8];

	  /* WKPU_WIREER - Wakeup/Interrupt Rising-Edge Event Enable Register */
      WKPU_WIREER_32B_tag WIREER;          /* offset: 0x0028 size: 32 bit */
	  /* WKPU_WIFEER - Wakeup/Interrupt Falling-Edge Event Enable Register */
      WKPU_WIFEER_32B_tag WIFEER;          /* offset: 0x002C size: 32 bit */
	  /* WKPU_WIFER - Wakeup/Interrupt Filter Enable Register */
      WKPU_WIFER_32B_tag WIFER;            /* offset: 0x0030 size: 32 bit */
	  /* WKPU_WIPUER - Wakeup/Interrupt Pullup Enable Register */
      WKPU_WIPUER_32B_tag WIPUER;          /* offset: 0x0034 size: 32 bit */
   } WKPU_tag;


/****************************************************************/
/*                                                              */
/* Module: SSCM  */
/*                                                              */
/****************************************************************/

   typedef union {   /* SSCM_STATUS - System Status Register */
      vuint16_t R;
      struct {
         vuint16_t  LSM:1;             /* Lock Step Mode */
         vuint16_t:2;
         vuint16_t  NXEN1:1;           /* Processor 1 Nexus enabled */
         vuint16_t  NXEN:1;            /* Processor 0 Nexus enabled */
         vuint16_t  PUB:1;             /* Public Serial Access Status */
         vuint16_t  SEC:1;             /* Security Status */
         vuint16_t:1;
         vuint16_t  BMODE:3;           /* Device Boot Mode */
         vuint16_t  VLE:1;             /* Variable Length Instruction Mode */
         vuint16_t  ABD:1;             /* Autobaud detection */
         vuint16_t:3;
      } B;
   } SSCM_STATUS_16B_tag;

   typedef union {   /* SSCM_MEMCONFIG - System Memory Configuration Register */
      vuint16_t R;
      struct {
         vuint16_t  JPIN:10;           /* JTAG Part ID Number */
         vuint16_t  IVLD:1;            /* Instruction Flash Valid */
         vuint16_t  MREV:4;            /* Minor Mask Revision */
         vuint16_t  DVLD:1;            /* Data Flash Valid */
      } B;
   } SSCM_MEMCONFIG_16B_tag;

   typedef union {   /* SSCM_ERROR - Error Configuration */
      vuint16_t R;
      struct {
         vuint16_t:14;
         vuint16_t  PAE:1;             /* Peripheral Bus Abort Enable */
         vuint16_t  RAE:1;             /* Register Bus Abort Enable */
      } B;
   } SSCM_ERROR_16B_tag;

   typedef union {   /* SSCM_DEBUGPORT - Debug Status Port Register */
      vuint16_t R;
      struct {
         vuint16_t:13;
         vuint16_t  DEBUG_MODE:3;      /* Debug Status Port Mode */
      } B;
   } SSCM_DEBUGPORT_16B_tag;

   typedef union {   /* SSCM_PWCMPH - Password Comparison Register High */
      vuint32_t R;
      struct {
         vuint32_t  PWD_HI:32;         /* Password High */
      } B;
   } SSCM_PWCMPH_32B_tag;

   typedef union {   /* SSCM_PWCMPL - Password Comparison Register Low */
      vuint32_t R;
      struct {
         vuint32_t  PWD_LO:32;         /* Password Low */
      } B;
   } SSCM_PWCMPL_32B_tag;

   typedef union {   /* SSCM_DPMBOOT - Decoupled Parallel Boot Register */
      vuint32_t R;
      struct {
         vuint32_t  P2BOOT:30;         /* boot location 2nd processor */
         vuint32_t  DVLE:1;            /* VLE mode for 2nd processor */
         vuint32_t:1;
      } B;
   } SSCM_DPMBOOT_32B_tag;

   typedef union {   /* SSCM_DPMKEY - Boot Key Register */
      vuint32_t R;
      struct {
         vuint32_t  KEY:32;            /* Boot Control Key */
      } B;
   } SSCM_DPMKEY_32B_tag;

   typedef union {   /* SSCM_UOPS - User Option Status Register */
      vuint32_t R;
      struct {
         vuint32_t  UOPT:32;           /* User Option Bits */
      } B;
   } SSCM_UOPS_32B_tag;

   typedef union {   /* SSCM_SCTR - SSCM Control Register */
      vuint32_t R;
      struct {
         vuint32_t:29;
         vuint32_t  TFE:1;             /* Test Flash Enable */
         vuint32_t  DSL:1;             /* Disable Software-Controlled MBIST */
         vuint32_t  DSM:1;             /* Disable Software-Controlled LBIST */
      } B;
   } SSCM_SCTR_32B_tag;

   typedef union {   /* SSCM_TF_INFO0 - TestFlash Information Register 0 */
      vuint32_t R;
      struct {
         vuint32_t  TINFO0:32;         /* General purpose TestFlash word 0 */
      } B;
   } SSCM_TF_INFO0_32B_tag;

   typedef union {   /* SSCM_TF_INFO1 - TestFlash Information Register 1 */
      vuint32_t R;
      struct {
         vuint32_t  TINFO1:32;         /* General purpose TestFlash word 1 */
      } B;
   } SSCM_TF_INFO1_32B_tag;

   typedef union {   /* SSCM_TF_INFO2 - TestFlash Information Register 2 */
      vuint32_t R;
      struct {
         vuint32_t  TINFO2:32;         /* General purpose TestFlash word 2 */
      } B;
   } SSCM_TF_INFO2_32B_tag;

   typedef union {   /* SSCM_TF_INFO3 - TestFlash Information Register 3 */
      vuint32_t R;
      struct {
         vuint32_t  TINFO3:32;         /* General purpose TestFlash word */
      } B;
   } SSCM_TF_INFO3_32B_tag;



   typedef struct SSCM_struct_tag { /* start of SSCM_tag */
	  /* SSCM_STATUS - System Status Register */
      SSCM_STATUS_16B_tag STATUS;          /* offset: 0x0000 size: 16 bit */
	  /* SSCM_MEMCONFIG - System Memory Configuration Register */
      SSCM_MEMCONFIG_16B_tag MEMCONFIG;    /* offset: 0x0002 size: 16 bit */
      int8_t SSCM_reserved_0004[2];
	  /* SSCM_ERROR - Error Configuration */
      SSCM_ERROR_16B_tag ERROR;            /* offset: 0x0006 size: 16 bit */
	  /* SSCM_DEBUGPORT - Debug Status Port Register */
      SSCM_DEBUGPORT_16B_tag DEBUGPORT;    /* offset: 0x0008 size: 16 bit */
      int8_t SSCM_reserved_000A[2];
	  /* SSCM_PWCMPH - Password Comparison Register High */
      SSCM_PWCMPH_32B_tag PWCMPH;          /* offset: 0x000C size: 32 bit */
	  /* SSCM_PWCMPL - Password Comparison Register Low */
      SSCM_PWCMPL_32B_tag PWCMPL;          /* offset: 0x0010 size: 32 bit */
      int8_t SSCM_reserved_0014[4];
	  /* SSCM_DPMBOOT - Decoupled Parallel Boot Register */
      SSCM_DPMBOOT_32B_tag DPMBOOT;        /* offset: 0x0018 size: 32 bit */
	  /* SSCM_DPMKEY - Boot Key Register */
      SSCM_DPMKEY_32B_tag DPMKEY;          /* offset: 0x001C size: 32 bit */
	  /* SSCM_UOPS - User Option Status Register */
      SSCM_UOPS_32B_tag UOPS;              /* offset: 0x0020 size: 32 bit */
	  /* SSCM_SCTR - SSCM Control Register */
      SSCM_SCTR_32B_tag SCTR;              /* offset: 0x0024 size: 32 bit */
	  /* SSCM_TF_INFO0 - TestFlash Information Register 0 */
      SSCM_TF_INFO0_32B_tag TF_INFO0;      /* offset: 0x0028 size: 32 bit */
	  /* SSCM_TF_INFO1 - TestFlash Information Register 1 */
      SSCM_TF_INFO1_32B_tag TF_INFO1;      /* offset: 0x002C size: 32 bit */
	  /* SSCM_TF_INFO2 - TestFlash Information Register 2 */
      SSCM_TF_INFO2_32B_tag TF_INFO2;      /* offset: 0x0030 size: 32 bit */
	  /* SSCM_TF_INFO3 - TestFlash Information Register 3 */
      SSCM_TF_INFO3_32B_tag TF_INFO3;      /* offset: 0x0034 size: 32 bit */
   } SSCM_tag;


/****************************************************************/
/*                                                              */
/* Module: ME  */
/*                                                              */
/****************************************************************/

   typedef union {   /* ME_GS - Global Status Register */
      vuint32_t R;
      struct {
         vuint32_t  S_CURRENTMODE:4;   /* Current device mode status */
         vuint32_t  S_MTRANS:1;        /* Mode transition status */
         vuint32_t:3;
         vuint32_t  S_PDO:1;           /* Output power-down status */
         vuint32_t:2;
         vuint32_t  S_MVR:1;           /* Main voltage regulator status */
         vuint32_t:2;
         vuint32_t  S_CFLA:2;            /* Flash availability status */
         vuint32_t:8;
         vuint32_t  S_PLL1:1;          /* Secondary PLL status */
         vuint32_t  S_PLL0:1;          /* System PLL status */
         vuint32_t  S_OSC:1;             /* System crystal oscillator status */
         vuint32_t  S_RC:1;              /* System RC oscillator status */
         vuint32_t  S_SYSCLK:4;        /* System clock switch status */
      } B;
   } ME_GS_32B_tag;

   typedef union {   /* ME_MCTL - Mode Control Register */
      vuint32_t R;
      struct {
         vuint32_t  TARGET_MODE:4;     /* Target device mode */
         vuint32_t:12;
         vuint32_t  KEY:16;            /* Control key */
      } B;
   } ME_MCTL_32B_tag;

   typedef union {   /* ME_MEN - Mode Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:21;
         vuint32_t  STOP0:1;           /* STOP0 mode enable */
         vuint32_t:1;
         vuint32_t  HALT0:1;           /* HALT0 mode enable */
         vuint32_t  RUN3:1;            /* RUN3 mode enable */
         vuint32_t  RUN2:1;            /* RUN2 mode enable */
         vuint32_t  RUN1:1;            /* RUN1 mode enable */
         vuint32_t  RUN0:1;            /* RUN0 mode enable */
         vuint32_t  DRUN:1;            /* DRUN mode enable */
         vuint32_t  SAFE:1;            /* SAFE mode enable */
         vuint32_t:1;
         vuint32_t  RESET:1;           /* RESET mode enable */
      } B;
   } ME_MEN_32B_tag;

   typedef union {   /* ME_IS - Interrupt Status Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  I_CONF:1;            /* Invalid mode config interrupt */
         vuint32_t  I_MODE:1;            /* Invalid mode interrupt */
         vuint32_t  I_SAFE:1;             /* SAFE mode interrupt */
         vuint32_t  I_TC:1;              /* Mode transition complete interrupt */
      } B;
   } ME_IS_32B_tag;

   typedef union {   /* ME_IM - Interrupt Mask Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  M_CONF:1;          /* Invalid mode config interrupt mask */
         vuint32_t  M_MODE:1;          /* Invalid mode interrupt mask */
         vuint32_t  M_SAFE:1;          /* SAFE mode interrupt mask */
         vuint32_t  M_TC:1;            /* Mode transition complete interrupt mask  */
      } B;
   } ME_IM_32B_tag;

   typedef union {   /* ME_IMTS - Invalid Mode Transition Status Register */
      vuint32_t R;
      struct {
         vuint32_t:27;
         vuint32_t  S_MTI:1;           /* Mode Transition Illegal status */
         vuint32_t  S_MRI:1;           /* Mode Request Illegal status */
         vuint32_t  S_DMA:1;           /* Disabled Mode Access status */
         vuint32_t  S_NMA:1;           /* Non-existing Mode Access status */
         vuint32_t  S_SEA:1;           /* Safe Event Active status */
      } B;
   } ME_IMTS_32B_tag;

   typedef union {   /* ME_DMTS - Debug Mode Transition Status Register */
      vuint32_t R;
      struct {
         vuint32_t  PREVIOUS_MODE:4;   /* Previous Device Mode */
         vuint32_t:4;
         vuint32_t  MPH_BUSY:1;        /* MC_ME/MC_PCU Handshake Busy Indicator */
         vuint32_t:2;
         vuint32_t  PMC_PROG:1;        /* MC_PCU Mode Change in Process Indicator */
         vuint32_t  CORE_DBG:1;        /* Processor is in Debug Mode Indicator */
         vuint32_t:2;
         vuint32_t  SMR:1;             /* SAFE Mode Request */
         vuint32_t:1;
         vuint32_t  VREG_CSRC_SC:1;    /* Main VREG Clock Source State Change Indicator */
         vuint32_t  CSRC_CSRC_SC:1;    /* Other Clock Source State Change Indicator */
         vuint32_t  IRCOSC_SC:1;       /* IRCOSC State Change Indicator */
         vuint32_t  SCSRC_SC:1;        /* Secondary System Clock Sources State Change Indicator */
         vuint32_t  SYSCLK_SW:1;       /* System Clock Switching pending Status Indicator */
         vuint32_t:1;
         vuint32_t  FLASH_SC:1;        /* FLASH State Change Indicator */
         vuint32_t  CDP_PRPH_0_143:1;  /* Clock Disable Process Pending Status for Periph. 0-143 */
         vuint32_t:4;
         vuint32_t  CDP_PRPH_64_95:1;  /* Clock Disable Process Pending Status for Periph. 64-95 */
         vuint32_t  CDP_PRPH_32_63:1;  /* Clock Disable Process Pending Status for Periph. 32-63 */
         vuint32_t  CDP_PRPH_0_31:1;   /* Clock Disable Process Pending Status for Periph. 0-31 */
      } B;
   } ME_DMTS_32B_tag;

   typedef union {   /* ME_RESET_MC - RESET Mode Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;
         vuint32_t  CFLAON:2;          /* Code flash power-down control */
         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;          /* System PLL control */
         vuint32_t  XOSC0ON:1;         /* System crystal oscillator control */
         vuint32_t  IRCON:1;           /* System RC oscillator control */
         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_RESET_MC_32B_tag;

   typedef union {   /* ME_SAFE_MC - Mode Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;
         vuint32_t  CFLAON:2;          /* Code flash power-down control */
         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;          /* System PLL control */
         vuint32_t  XOSC0ON:1;         /* System crystal oscillator control */
         vuint32_t  IRCON:1;           /* System RC oscillator control */
         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_SAFE_MC_32B_tag;

   typedef union {   /* ME_DRUN_MC - DRUN Mode Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;

         vuint32_t  CFLAON:2;          /* Code flash power-down control */

         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;           /* System PLL control */
         vuint32_t  XOSC0ON:1;         /* System crystal oscillator control */
         vuint32_t  IRCON:1;            /* System RC oscillator control */

         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_DRUN_MC_32B_tag;


   /* Register layout for all registers RUN_MC... */

   typedef union {   /* ME_RUN[0..3]_MC - RUN[0..3] Mode Configuration Registers */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;
         vuint32_t  CFLAON:2;           /* Code flash power-down control */
         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;          /* System PLL control */
         vuint32_t  XOSC0ON:1;          /* System crystal oscillator control */
         vuint32_t  IRCON:1; 	       /* System RC oscillator control */
         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_RUN_MC_32B_tag;

   typedef union {   /* ME_HALT0_MC - HALT0 Mode Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;
         vuint32_t  CFLAON:2;          /* Code flash power-down control */
         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;          /* System PLL control */
         vuint32_t  XOSC0ON:1;         /* System crystal oscillator control */
         vuint32_t  IRCON:1;           /* System RC oscillator control */
         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_HALT0_MC_32B_tag;

   typedef union {   /* ME_STOP0_MC - STOP0 Mode Configration Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;
         vuint32_t  CFLAON:2;          /* Code flash power-down control */
         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;          /* deprecated name - please avoid */
         vuint32_t  XOSC0ON:1;         /* deprecated name - please avoid */
         vuint32_t  IRCON:1;           /* deprecated name - please avoid */
         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_STOP0_MC_32B_tag;

   typedef union {   /* ME_STANDBY0_MC - STANDBY0 Mode Configration Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  PDO:1;             /* IOs output power-down control */
         vuint32_t:2;
         vuint32_t  MVRON:1;           /* Main voltage regulator control */
         vuint32_t:2;
         vuint32_t  CFLAON:2;          /* Code flash power-down control */
         vuint32_t:8;
         vuint32_t  PLL2ON:1;          /* Secondary system clock source [8..0] control */
         vuint32_t  PLL1ON:1;          /* System PLL control */
         vuint32_t  XOSC0ON:1;         /* System crystal oscillator control */
         vuint32_t  IRCON:1;           /* System RC oscillator control */
         vuint32_t  SYSCLK:4;          /* System clock switch control */
      } B;
   } ME_STANDBY0_MC_32B_tag;

   typedef union {   /* ME_PS0 - Peripheral Status Register 0 */
      vuint32_t R;
      struct {
         vuint32_t:7;
         vuint32_t  S_FLEXRAY:1;       /* FlexRay status */
         vuint32_t:6;
         vuint32_t  S_FLEXCAN1:1;      /* FlexCAN1 status */
         vuint32_t  S_FLEXCAN0:1;      /* FlexCAN0 status */
         vuint32_t:9;
         vuint32_t  S_DSPI2:1;         /* DSPI2 status */
         vuint32_t  S_DSPI1:1;         /* DSPI1 status */
         vuint32_t  S_DSPI0:1;         /* DSPI0 status */
         vuint32_t:4;
      } B;
   } ME_PS0_32B_tag;

   typedef union {   /* ME_PS1 - Peripheral Status Register 1 */
      vuint32_t R;
      struct {
         vuint32_t:1;
         vuint32_t  S_SWG:1;           /* SWG status */
         vuint32_t:3;
         vuint32_t  S_CRC:1;           /* CRC status */
         vuint32_t:8;
         vuint32_t  S_LIN_FLEX1:1;     /* LinFlex1 status */
         vuint32_t  S_LIN_FLEX0:1;     /* LinFlex0 status */
         vuint32_t:5;
         vuint32_t  S_FLEXPWM1:1;      /* FlexPWM1 status */
         vuint32_t  S_FLEXPWM0:1;      /* FlexPWM0 status */
         vuint32_t  S_ETIMER2:1;       /* eTimer2 status */
         vuint32_t  S_ETIMER1:1;       /* eTimer1 status */
         vuint32_t  S_ETIMER0:1;       /* eTimer0 status */
         vuint32_t:2;
         vuint32_t  S_CTU:1;           /* CTU status */
         vuint32_t:1;
         vuint32_t  S_ADC1:1;          /* ADC1 status */
         vuint32_t  S_ADC0:1;          /* ADC0 status */
      } B;
   } ME_PS1_32B_tag;

   typedef union {   /* ME_PS2 - Peripheral Status Register 2 */
      vuint32_t R;
      struct {
         vuint32_t:3;
         vuint32_t  S_PIT:1;           /* PIT status */
         vuint32_t:28;
      } B;
   } ME_PS2_32B_tag;

   /* Register layout for all registers RUN_PC... */

   typedef union {   /* ME_RUN_PC[0...7] - RUN Peripheral Configuration Registers */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  RUN3:1;            /* Peripheral control during RUN3 */
         vuint32_t  RUN2:1;            /* Peripheral control during RUN2 */
         vuint32_t  RUN1:1;            /* Peripheral control during RUN1 */
         vuint32_t  RUN0:1;            /* Peripheral control during RUN0 */
         vuint32_t  DRUN:1;            /* Peripheral control during DRUN */
         vuint32_t  SAFE:1;            /* Peripheral control during SAFE */
         vuint32_t  TEST:1;            /* Peripheral control during TEST */
         vuint32_t  RESET:1;           /* Peripheral control during RESET */
      } B;
   } ME_RUN_PC_32B_tag;

   /* Register layout for all registers LP_PC... */

   typedef union {   /* ME_LP_PC[0...7] - Low Power Peripheral Configuration Registers */
      vuint32_t R;
      struct {
         vuint32_t:21;
         vuint32_t  STOP0:1;           /* Peripheral control during STOP0 */
         vuint32_t:1;
         vuint32_t  HALT0:1;           /* Peripheral control during HALT0 */
         vuint32_t:8;
      } B;
   } ME_LP_PC_32B_tag;

   /* Register layout for all registers PCTL... */

   typedef union {   /* ME_PCTL[0...143] - Peripheral Control Registers */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   DBG_F:1;           /* Peripheral control in debug mode */
         vuint8_t   LP_CFG:3;          /* Peripheral configuration select for non-RUN modes */
         vuint8_t   RUN_CFG:3;         /* Peripheral configuration select for RUN modes */
      } B;
   } ME_PCTL_8B_tag;

   /* Register layout for generated register(s) PS... */

   typedef union {   /*  */
      vuint32_t R;
   } ME_PS_32B_tag;


   typedef struct ME_struct_tag { /* start of ME_tag */
	  /* ME_GS - Global Status Register */
      ME_GS_32B_tag GS;                 /* offset: 0x0000 size: 32 bit */
	  /* ME_MCTL - Mode Control Register */
      ME_MCTL_32B_tag MCTL;             /* offset: 0x0004 size: 32 bit */
      /* ME_MEN - Mode Enable Register */
	  ME_MEN_32B_tag MER;             	/* offset: 0x0008 size: 32 bit */

	  /* ME_IS - Interrupt Status Register */
      ME_IS_32B_tag IS;                 /* offset: 0x000C size: 32 bit */
	  /* ME_IM - Interrupt Mask Register */
      ME_IM_32B_tag IM;                 /* offset: 0x0010 size: 32 bit */
	  /* ME_IMTS - Invalid Mode Transition Status Register */
      ME_IMTS_32B_tag IMTS;             /* offset: 0x0014 size: 32 bit */
	  /* ME_DMTS - Debug Mode Transition Status Register */
      ME_DMTS_32B_tag DMTS;             /* offset: 0x0018 size: 32 bit */
      int8_t ME_reserved_001C_C[4];

      /* ME_RESET_MC - RESET Mode Configuration Register */
      ME_RESET_MC_32B_tag RESET;        /* offset: 0x0020 size: 32 bit */

      int8_t ME_reserved_0024_C[4];

      /* ME_SAFE_MC - Mode Configuration Register */
      ME_SAFE_MC_32B_tag SAFE;          /* offset: 0x0028 size: 32 bit */

      /* ME_DRUN_MC - DRUN Mode Configuration Register */
      ME_DRUN_MC_32B_tag DRUN;          /* offset: 0x002C size: 32 bit */

      /* ME_RUN[0..3]_MC - RUN[0..3] Mode Configuration Registers */
	  ME_RUN_MC_32B_tag RUN[4];         /* offset: 0x0030  (0x0004 x 4) */ 

      /* ME_HALT0_MC - HALT0 Mode Configuration Register */
      ME_HALT0_MC_32B_tag HALT0;       /* offset: 0x0040 size: 32 bit */

      int8_t ME_reserved_0044_C[4];

      /* ME_STOP0_MC - STOP0 Mode Configration Register */
      ME_STOP0_MC_32B_tag STOP0;       /* offset: 0x0048 size: 32 bit */

      int8_t ME_reserved_004C_C[8];

	  /* ME_STANDBY0_MC - STANDBY0 Mode Configration Register */
      ME_STANDBY0_MC_32B_tag STANDBY0; /* offset: 0x0054 size: 32 bit */

      int8_t ME_reserved_0058_C[8];

	  ME_PS_32B_tag PS[3];             /* offset: 0x0060  (0x0004 x 3) */

      int8_t ME_reserved_006C_C[20];

	  ME_RUN_PC_32B_tag RUNPC[8];      /* offset: 0x0080  (0x0004 x 8) */

	  ME_LP_PC_32B_tag LPPC[8];        /* offset: 0x00A0  (0x0004 x 8) */

	  /* ME_PCTL[0...143] - Peripheral Control Registers */
	  ME_PCTL_8B_tag PCTL[144];        /* offset: 0x00C0  (0x0001 x 144) */

   } ME_tag;



/****************************************************************/
/*                                                              */
/* Module: OSC  */
/*                                                              */
/****************************************************************/

   typedef union {   /* OSC_CTL - Control Register */
      vuint32_t R;
      struct {
         vuint32_t  OSCBYP:1;          /* High Frequency Oscillator Bypass */
         vuint32_t:7;
         vuint32_t  EOCV:8;            /* End of Count Value */
         vuint32_t  M_OSC:1;           /* High Frequency Oscillator Clock Interrupt Mask */
         vuint32_t:2;
         vuint32_t  OSCDIV:5;          /* High Frequency Oscillator Division Factor */
         vuint32_t  I_OSC:1;           /* High Frequency Oscillator Clock Interrupt */
         vuint32_t:5;
         vuint32_t S_OSC:1;
         vuint32_t OSCON:1;      } B;
   } OSC_CTL_32B_tag;



   typedef struct OSC_struct_tag { /* start of OSC_tag */
	   /* OSC_CTL - Control Register */
      OSC_CTL_32B_tag CTL;              /* offset: 0x0000 size: 32 bit */
   } OSC_tag;


/****************************************************************/
/*                                                              */
/* Module: RC  */
/*                                                              */
/****************************************************************/

   typedef union {   /* RC_CTL - Control Register */
      vuint32_t R;
      struct {
         vuint32_t:10;
         vuint32_t  RCTRIM:6;          /* Main RC Trimming Bits */
         vuint32_t:3;
         vuint32_t  RCDIV:5;           /* Main RC Clock Division Factor */
         vuint32_t:2;
         vuint32_t  S_RC_STDBY:1;      /* MRC Oscillator Powerdown Status */
         vuint32_t:5;
      } B;
   } RC_CTL_32B_tag;



   typedef struct RC_struct_tag { /* start of RC_tag */
                                       /* RC_CTL - Control Register */
      RC_CTL_32B_tag CTL;              /* offset: 0x0000 size: 32 bit */
   } RC_tag;


/****************************************************************/
/*                                                              */
/* Module: PLLD  */
/*                                                              */
/****************************************************************/

   typedef union {   /* PLLD_CR - Control Register */
      vuint32_t R;
      struct {
         vuint32_t:2;
         vuint32_t  IDF:4;             /* PLL Input Division Factor */
         vuint32_t  ODF:2;             /* PLL Output Division Factor */
         vuint32_t:1;
         vuint32_t  NDIV:7;            /* PLL Loop Division Factor */
         vuint32_t:7;
         vuint32_t  EN_PLL_SW:1;       /* Enable Progressive Clock Switching */
         vuint32_t  MODE:1;            /* Activate 1:1 Mode */
         vuint32_t  UNLOCK_ONCE:1;     /* PLL Loss of Lock */
         vuint32_t  M_LOCK:1;          /* Mask for the i_lock Output Interrupt */
         vuint32_t  I_LOCK:1;          /* PLL Lock Signal Toggle Indicator */
         vuint32_t  S_LOCK:1;          /* PLL has Aquired Lock */
         vuint32_t  PLL_FAIL_MASK:1;   /* PLL Fail Mask */
         vuint32_t  PLL_FAIL_FLAG:1;   /* PLL Fail Flag */
         vuint32_t  PLL_ON:1;          /* PLL ON Bit */
      } B;
   } PLLD_CR_32B_tag;

   typedef union {   /* PLLD_MR - PLLD Modulation Register */
      vuint32_t R;
      struct {
         vuint32_t  STRB_BYPASS:1;     /* Strobe Bypass */
         vuint32_t:1;
         vuint32_t  SPRD_SEL:1;        /* Spread Type Selection */
         vuint32_t  MOD_PERIOD:13;     /* Modulation Period */
         vuint32_t  SSCG_EN:1;         /* Spread Spectrum Clock Generation Enable */
         vuint32_t  INC_STEP:15;       /* Increment Step */
      } B;
   } PLLD_MR_32B_tag;



   typedef struct PLLD_struct_tag { /* start of PLLD_tag */
                                       /* PLLD_CR - Control Register */
      PLLD_CR_32B_tag CR;              /* offset: 0x0000 size: 32 bit */
									   /* PLLD_MR - PLLD Modulation Register */
      PLLD_MR_32B_tag MR;              /* offset: 0x0004 size: 32 bit */
	  
	  vuint32_t plld_reserved[6];
   } PLLD_tag;


/****************************************************************/
/*                                                              */
/* Module: CMU 				  */
/*                                                              */
/****************************************************************/

   typedef union {   /* CMU_CSR - Control Status Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  SFM:1;             /* Start Frequency Measure */
         vuint32_t:13;
         vuint32_t  CKSEL1:2;          /* RC Oscillator(s) Selection Bit */
         vuint32_t:5;
         vuint32_t  RCDIV:2;           /* RCfast Clock Division Factor */
         vuint32_t  CME_A:1;           /* PLL_A Clock Monitor Enable */
      } B;
   } CMU_CSR_32B_tag;

   typedef union {   /* CMU_FDR - Frequency Display Register */
      vuint32_t R;
      struct {
         vuint32_t:12;
         vuint32_t  FD:20;             /* Measured Frequency Bits */
      } B;
   } CMU_FDR_32B_tag;

   typedef union {   /* CMU_HFREFR_A - High Frequency Reference Register */
      vuint32_t R;
      struct {
         vuint32_t:20;
         vuint32_t  HFREF_A:12;        /* High Frequency Reference Value */
      } B;
   } CMU_HFREFR_A_32B_tag;

   typedef union {   /* CMU_LFREFR_A - Low Frequency Reference Register */
      vuint32_t R;
      struct {
         vuint32_t:20;
         vuint32_t  LFREF_A:12;        /* Low Frequency Reference Value */
      } B;
   } CMU_LFREFR_A_32B_tag;

   typedef union {   /* CMU_ISR - Interrupt Status Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  FLCI_A:1;          /* PLL_A Clock Frequency less than Reference Clock Interrupt */
         vuint32_t  FHH_AI:1;          /* PLL_A Clock Frequency higher than high Reference Interrupt */
         vuint32_t  FLLI_A:1;          /* PLL_A Clock Frequency less than low Reference Interrupt */
         vuint32_t  OLRI:1;            /* Oscillator Frequency less than RC Frequency Interrupt */
      } B;
   } CMU_ISR_32B_tag;

   typedef union {   /* CMU_IMR - Interrupt Mask Register */
      vuint32_t R;
   } CMU_IMR_32B_tag;

   typedef union {   /* CMU_MDR - Measurement Duration Register */
      vuint32_t R;
      struct {
         vuint32_t:12;
         vuint32_t  MD:20;                /* Measurment Duration Bits */
      } B;
   } CMU_MDR_32B_tag;



   typedef struct CMU_struct_tag { /* start of CMU_tag */
	  /* CMU_CSR - Control Status Register */
      CMU_CSR_32B_tag CSR;                 /* offset: 0x0000 size: 32 bit */
	  /* CMU_FDR - Frequency Display Register */
      CMU_FDR_32B_tag FDR;                 /* offset: 0x0004 size: 32 bit */
	  /* CMU_HFREFR_A - High Frequency Reference Register */
      CMU_HFREFR_A_32B_tag HFREFR_A;       /* offset: 0x0008 size: 32 bit */
	  /* CMU_LFREFR_A - Low Frequency Reference Register */
      CMU_LFREFR_A_32B_tag LFREFR_A;       /* offset: 0x000C size: 32 bit */
	  /* CMU_ISR - Interrupt Status Register */
      CMU_ISR_32B_tag ISR;                 /* offset: 0x0010 size: 32 bit */
	  /* CMU_IMR - Interrupt Mask Register */
      CMU_IMR_32B_tag IMR;                 /* offset: 0x0014 size: 32 bit */
	  /* CMU_MDR - Measurement Duration Register */
      CMU_MDR_32B_tag MDR;                 /* offset: 0x0018 size: 32 bit */
   } CMU_tag;


/****************************************************************/
/*                                                              */
/* Module: CGM  				 */
/*                                                              */
/****************************************************************/

   typedef union {   /* Output Clock Enable Register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
      struct {
         vuint32_t:31;
         vuint32_t  EN:1;              /* Clock Enable Bit */
      } B;
   } CGM_OC_EN_32B_tag;

   typedef union {   /* Output Clock Division Select Register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
      struct {
         vuint32_t:2;
         vuint32_t  SELDIV:2;          /* Output Clock Division Select */
         vuint32_t  SELCTL:4;          /* Output Clock Source Selection Control */
         vuint32_t:24;
      } B;
   } CGM_OCDS_SC_32B_tag;

   typedef union {   /* System Clock Select Status Register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
      struct {
         vuint32_t:4;
         vuint32_t  SELSTAT:4;         /* System Clock Source Selection Status */
         vuint32_t:24;
      } B;
   } CGM_SC_SS_32B_tag;

   typedef union {   /* System Clock Divider Configuration Register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
      struct {
         vuint32_t  DE0:1;             /* Divider 0 Enable */
         vuint32_t:3;
         vuint32_t  DIV0:4;            /* Divider 0 Value */
         vuint32_t:24;
      } B;
   } CGM_SC_DC0_3_32B_tag;

   /* Register layout for all registers SC_DC... */

   typedef union {   /* System Clock Divider Configuration Register */
      vuint8_t R;
      struct {
         vuint8_t   DE:1;              /* Divider Enable */
         vuint8_t:3;
         vuint8_t   DIV:4;             /* Divider Division Value */
      } B;
   } CGM_SC_DC_8B_tag;

   /* Register layout for all registers AC_SC... */

   typedef union {   /* Auxiliary Clock Select Control Registers */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
      struct {
         vuint32_t:4;
         vuint32_t  SELCTL:4;          /* Auxliary Clock Source Selection Control */
         vuint32_t:24;
      } B;
   } CGM_AC_SC_32B_tag;

   /* Register layout for all registers AC_DC0_3... */

   typedef union {   /* Auxiliary Clock Divider Configuration Registers */
      vuint32_t R;
      struct {
         vuint32_t  DE0:1;             /* Divider 0 Enable */
         vuint32_t:3;
         vuint32_t  DIV0:4;            /* Divider 0 Value */
         vuint32_t  DE1:1;             /* Divider 1 Enable */
         vuint32_t:3;
         vuint32_t  DIV1:4;            /* Divider 1 Value */
         vuint32_t:16;
      } B;
   } CGM_AC_DC0_3_32B_tag;

   typedef struct CGM_AUXCLK_struct_tag {

	  /* Auxiliary Clock Select Control Registers */
      CGM_AC_SC_32B_tag AC_SC;            /* relative offset: 0x0000 */
	  /* Auxiliary Clock Divider Configuration Registers */
      CGM_AC_DC0_3_32B_tag AC_DC0_3;      /* relative offset: 0x0004 */

   } CGM_AUXCLK_tag;


   typedef struct CGM_struct_tag { /* start of CGM_tag */
      OSC_CTL_32B_tag OSC_CTL;             /* offset: 0x0000 size: 32 bit */
      int8_t CGM_reserved_0004[92];
      RC_CTL_32B_tag RC_CTL;               /* offset: 0x0060 size: 32 bit */
      int8_t CGM_reserved_0064[60];
      PLLD_tag FMPLL[2];                   /* offset: 0x00A0  (0x0020 x 2) */
      int8_t CGM_reserved_00E0[32];
      CMU_CSR_32B_tag CMU_0_CSR;           /* offset: 0x0100 size: 32 bit */
      CMU_FDR_32B_tag CMU_0_FDR;           /* offset: 0x0104 size: 32 bit */
      CMU_HFREFR_A_32B_tag CMU_0_HFREFR_A;  /* offset: 0x0108 size: 32 bit */
      CMU_LFREFR_A_32B_tag CMU_0_LFREFR_A;  /* offset: 0x010C size: 32 bit */
      CMU_ISR_32B_tag CMU_0_ISR;           /* offset: 0x0110 size: 32 bit */
      CMU_IMR_32B_tag CMU_0_IMR;           /* offset: 0x0114 size: 32 bit */
      CMU_MDR_32B_tag CMU_0_MDR;           /* offset: 0x0118 size: 32 bit */
      int8_t CGM_reserved_011C[4];
      CMU_CSR_32B_tag CMU_1_CSR;           /* offset: 0x0120 size: 32 bit */
      int8_t CGM_reserved_0124[4];
      CMU_HFREFR_A_32B_tag CMU_1_HFREFR_A; /* offset: 0x0128 size: 32 bit */
      CMU_LFREFR_A_32B_tag CMU_1_LFREFR_A; /* offset: 0x012C size: 32 bit */
      CMU_ISR_32B_tag CMU_1_ISR;           /* offset: 0x0130 size: 32 bit */
      int8_t CGM_reserved_0134[572];
                                           /* Output Clock Enable Register */
      CGM_OC_EN_32B_tag OCEN;              /* offset: 0x0370 size: 32 bit */
      /* Output Clock Division Select Register */
      CGM_OCDS_SC_32B_tag OCDSSC;         /* offset: 0x0374 size: 32 bit */
      /* System Clock Select Status Register */
      CGM_SC_SS_32B_tag SCSS;             /* offset: 0x0378 size: 32 bit */

	  /* System Clock Divider Configuration Register */
	  CGM_SC_DC0_3_32B_tag SCDC0;    /* offset: 0x037C size: 32 bit */

	  /* Auxiliary Clock Select Control Registers */
	  CGM_AC_SC_32B_tag AC0SC;      /* offset: 0x0380 size: 32 bit */
	  /* Auxiliary Clock Divider Configuration Registers */
	  CGM_AC_DC0_3_32B_tag AC0DC;  /* offset: 0x0384 size: 32 bit */
	  /* Auxiliary Clock Select Control Registers */
	  CGM_AC_SC_32B_tag AC1SC;      /* offset: 0x0388 size: 32 bit */
	  /* Auxiliary Clock Divider Configuration Registers */
	  CGM_AC_DC0_3_32B_tag AC1DC;  /* offset: 0x038C size: 32 bit */
	  /* Auxiliary Clock Select Control Registers */
	  CGM_AC_SC_32B_tag AC2SC;      /* offset: 0x0390 size: 32 bit */
	  /* Auxiliary Clock Divider Configuration Registers */
	  CGM_AC_DC0_3_32B_tag AC2DC;  /* offset: 0x0394 size: 32 bit */
	  /* Auxiliary Clock Select Control Registers */
	  CGM_AC_SC_32B_tag AC3SC;      /* offset: 0x0398 size: 32 bit */
	  /* Auxiliary Clock Divider Configuration Registers */
	  CGM_AC_DC0_3_32B_tag AC3DC;  /* offset: 0x039C size: 32 bit */
	  /* Auxiliary Clock Select Control Registers */
	  CGM_AC_SC_32B_tag AC4SC;      /* offset: 0x03A0 size: 32 bit */
	  /* Auxiliary Clock Divider Configuration Registers */
	  CGM_AC_DC0_3_32B_tag AC4DC;  /* offset: 0x03A4 size: 32 bit */
	  /* Auxiliary Clock Select Control Registers */
	  CGM_AC_SC_32B_tag AC5SC;      /* offset: 0x03A8 size: 32 bit */
	  /* Auxiliary Clock Divider Configuration Registers */
	  CGM_AC_DC0_3_32B_tag AC5DC;  /* offset: 0x03AC size: 32 bit */

   } CGM_tag;

/****************************************************************/
/*                                                              */
/* Module: RGM 				 */
/*                                                              */
/****************************************************************/

   typedef union {   /* Functional Event Status Register */
      vuint16_t R;
      struct {
         vuint16_t  F_EXR:1;           /* Flag for External Reset */
         vuint16_t  F_FCCU_HARD:1;     /* Flag for FCCU hard reaction request */
         vuint16_t  F_FCCU_SOFT:1;     /* Flag for FCCU soft reaction request */
         vuint16_t  F_ST_DONE:1;       /* Flag for self-test completed */
         vuint16_t  F_CMU1_FHL:1;      /* Flag for CMU 1/2 clock freq. too high/low */
         vuint16_t  F_FL_ECC_RCC:1;    /* Flag for Flash, ECC, or lock-step error */
         vuint16_t  F_PLL1:1;          /* Flag for PLL1 fail */
         vuint16_t  F_SWT:1;           /* Flag for Software Watchdog Timer */
         vuint16_t  F_FCCU_SAFE:1;     /* Flag for FCCU SAFE mode request */
         vuint16_t  F_CMU0_FHL:1;      /* Flag for CMU 0 clock freq. too high/low */
         vuint16_t  F_CMU0_OLR:1;      /* Flag for oscillator freq. too low */
         vuint16_t  F_PLL0:1;          /* Flag for PLL0 fail */
         vuint16_t  F_CWD:1;           /* Flag for Core Watchdog Reset */
         vuint16_t  F_SOFT:1;          /* Flag for software reset */
         vuint16_t  F_CORE:1;          /* Flag for core reset */
         vuint16_t  F_JTAG:1;          /* Flag for JTAG initiated reset */
      } B;
   } RGM_FES_16B_tag;

   typedef union {   /* Destructive Event Status Register */
      vuint16_t R;
      struct {
         vuint16_t  POR:1;             /* Flag for Power on Reset */
         vuint16_t:7;
         vuint16_t  F_COMP:1;          /* Flag for comparator error */
         vuint16_t  F_LVD27_IO:1;      /* Flag for 2.7V low-voltage detected (I/O) */
         vuint16_t  F_LVD27_FLASH:1;   /* Flag for 2.7V low-voltage detected (Flash) */
         vuint16_t  F_LVD27_VREG:1;    /* Flag for 2.7V low-voltage detected (VREG) */
         vuint16_t:2;
         vuint16_t  F_HVD12:1;         /* Flag for 1.2V high-voltage detected */
         vuint16_t  F_LVD12_PD0:1;     /* Flag for 1.2V low-voltage detected */

      } B;
   } RGM_DES_16B_tag;

   typedef union {   /* Functional Event Reset Disable Register */
      vuint16_t R;
      struct {
         vuint16_t  D_EXR:1;           /* Disable External Pad Event Reset */
         vuint16_t  D_FCCU_HARD:1;     /* Disable FCCU hard reaction request */
         vuint16_t  D_FCCU_SOFT:1;     /* Disable FCCU soft reaction request */
         vuint16_t  D_ST_DONE:1;       /* Disable self-test completed */
         vuint16_t  D_CMU1_FHL:1;      /* Disable CMU 1/2 clock freq. too high/low */
         vuint16_t  D_FL_ECC_RCC:1;    /* Disable Flash, ECC, or lock-step error */
         vuint16_t  D_PLL1:1;          /* Disable PLL1 fail */
         vuint16_t  D_SWT:1;           /* Disable Software Watchdog Timer */
         vuint16_t  D_FCCU_SAFE:1;     /* Disable FCCU SAFE mode request */
         vuint16_t  D_CMU0_FHL:1;      /* Disable CMU 0 clock freq. too high/low */
         vuint16_t  D_CMU0_OLR:1;      /* Disable oscillator freq. too low */
         vuint16_t  D_PLL0:1;          /* Disable PLL0 fail */
         vuint16_t  D_CWD:1;           /* Disable Core Watchdog Reset */
         vuint16_t  D_SOFT:1;          /* Disable software reset */
         vuint16_t  D_CORE:1;          /* Disable core reset */
         vuint16_t  D_JTAG:1;          /* Disable JTAG initiated reset */
      } B;
   } RGM_FERD_16B_tag;

   typedef union {   /* Destructive Event Reset Disable Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  D_COMP:1;          /* Disable comparator error */
         vuint16_t  D_LVD27_IO:1;      /* Disable 2.7V low-voltage detected (I/O) */
         vuint16_t  D_LVD27_FLASH:1;   /* Disable 2.7V low-voltage detected (Flash) */
         vuint16_t  D_LVD27_VREG:1;    /* Disable 2.7V low-voltage detected (VREG) */
         vuint16_t:2;
         vuint16_t  D_HVD12:1;         /* Disable 1.2V high-voltage detected */
         vuint16_t  D_LVD12_PD0:1;     /* Disable 1.2V low-voltage detected */
      } B;
   } RGM_DERD_16B_tag;

   typedef union {   /* Functional Event Alternate Request Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  AR_CMU1_FHL:1;     /* Alternate Request for CMU1/2 clock freq. too high/low */
         vuint16_t:1;
         vuint16_t  AR_PLL1:1;         /* Alternate Request for PLL1 fail */
         vuint16_t:1;
         vuint16_t  AR_FCCU_SAVE:1;    /* Alternate Request for FCCU SAFE mode request */
         vuint16_t  AR_CMU0_FHL:1;     /* Alternate Request for CMU0 clock freq. too high/low */
         vuint16_t  AR_CMU0_OLR:1;     /* Alternate Request for oscillator freq. too low */
         vuint16_t  AR_PLL0:1;         /* Alternate Request for PLL0 fail */
         vuint16_t  AR_CWD:1;          /* Alternate Request for core watchdog reset */
         vuint16_t:3;
      } B;
   } RGM_FEAR_16B_tag;

   typedef union {   /* Functional Event Short Sequence Register */
      vuint16_t R;
      struct {
         vuint16_t  SS_EXR:1;          /* Short Sequence for External Reset */
         vuint16_t  SS_FCCU_HARD:1;    /* Short Sequence for FCCU hard reaction request */
         vuint16_t  SS_FCCU_SOFT:1;    /* Short Sequence for FCCU soft reaction request */
         vuint16_t  SS_ST_DONE:1;      /* Short Sequence for self-test completed */
         vuint16_t  SS_CMU1_FHL:1;     /* Short Sequence for CMU 1/2 clock freq. too high/low */
         vuint16_t  SS_FL_ECC_RCC:1;   /* Short Sequence for Flash, ECC, or lock-step error */
         vuint16_t  SS_PLL1:1;         /* Short Sequence for PLL1 fail */
         vuint16_t  SS_SWT:1;          /* Short Sequence for Software Watchdog Timer */
         vuint16_t:1;
         vuint16_t  SS_CMU0_FHL:1;     /* Short Sequence for CMU 0 clock freq. too high/low */
         vuint16_t  SS_CMU0_OLR:1;     /* Short Sequence for oscillator freq. too low */
         vuint16_t  SS_PLL0:1;         /* Short Sequence for PLL0 fail */
         vuint16_t  SS_CWD:1;          /* Short Sequence for Core Watchdog Reset */
         vuint16_t  SS_SOFT:1;         /* Short Sequence for software reset */
         vuint16_t  SS_CORE:1;         /* Short Sequence for core reset */
         vuint16_t  SS_JTAG:1;         /* Short Sequence for JTAG initiated reset */
      } B;
   } RGM_FESS_16B_tag;

   typedef union {   /* Functional Bidirectional Reset Enable Register */
      vuint16_t R;
      struct {
         vuint16_t  BE_EXR:1;          /* Bidirectional Reset Enable for External Reset */
         vuint16_t  BE_FCCU_HARD:1;    /* Bidirectional Reset Enable for FCCU hard reaction request */
         vuint16_t  BE_FCCU_SOFT:1;    /* Bidirectional Reset Enable for FCCU soft reaction request */
         vuint16_t  BE_ST_DONE:1;      /* Bidirectional Reset Enable for self-test completed */
         vuint16_t  BE_CMU1_FHL:1;     /* Bidirectional Reset Enable for CMU 1/2 clock freq. too high/low */
         vuint16_t  BE_FL_ECC_RCC:1;   /* Bidirectional Reset Enable for Flash, ECC, or lock-step error */
         vuint16_t  BE_PLL1:1;         /* Bidirectional Reset Enable for PLL1 fail */
         vuint16_t  BE_SWT:1;          /* Bidirectional Reset Enable for Software Watchdog Timer */
         vuint16_t:1;
         vuint16_t  BE_CMU0_FHL:1;     /* Bidirectional Reset Enable for CMU 0 clock freq. too high/low */
         vuint16_t  BE_CMU0_OLR:1;     /* Bidirectional Reset Enable for oscillator freq. too low */
         vuint16_t  BE_PLL0:1;         /* Bidirectional Reset Enable for PLL0 fail */
         vuint16_t  BE_CWD:1;          /* Bidirectional Reset Enable for Core Watchdog Reset */
         vuint16_t  BE_SOFT:1;         /* Bidirectional Reset Enable for software reset */
         vuint16_t  BE_CORE:1;         /* Bidirectional Reset Enable for core reset */
         vuint16_t  BE_JTAG:1;         /* Bidirectional Reset Enable for JTAG initiated reset */
      } B;
   } RGM_FBRE_16B_tag;



   typedef struct RGM_struct_tag { /* start of RGM_tag */
	  /* Functional Event Status Register */
      RGM_FES_16B_tag FES;                 /* offset: 0x0000 size: 16 bit */
	  /* Destructive Event Status Register */
      RGM_DES_16B_tag DES;                 /* offset: 0x0002 size: 16 bit */
	  /* Functional Event Reset Disable Register */
      RGM_FERD_16B_tag FERD;               /* offset: 0x0004 size: 16 bit */
	  /* Destructive Event Reset Disable Register */
      RGM_DERD_16B_tag DERD;               /* offset: 0x0006 size: 16 bit */
      int8_t RGM_reserved_0008[8];
	  /* Functional Event Alternate Request Register */
      RGM_FEAR_16B_tag FEAR;               /* offset: 0x0010 size: 16 bit */
      int8_t RGM_reserved_0012[6];
	  /* Functional Event Short Sequence Register */
      RGM_FESS_16B_tag FESS;               /* offset: 0x0018 size: 16 bit */
      int8_t RGM_reserved_001A[2];
	  /* Functional Bidirectional Reset Enable Register */
      RGM_FBRE_16B_tag FBRE;               /* offset: 0x001C size: 16 bit */
   } RGM_tag;


/****************************************************************/
/*                                                              */
/* Module: PCU  */
/*                                                              */
/****************************************************************/


   /* Register layout for all registers PCONF... */

   typedef union {   /* PCU_PCONF[0..15] -  Power Domain #0..#15 Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:18;
         vuint32_t  STBY0:1;           /* Power domain control during STBY0 */
         vuint32_t:2;
         vuint32_t  STOP0:1;           /* Power domain control during STOP0 */
         vuint32_t:1;
         vuint32_t  HALT0:1;           /* Power domain control during HALT0 */
         vuint32_t  RUN3:1;            /* Power domain control during RUN3 */
         vuint32_t  RUN2:1;            /* Power domain control during RUN2 */
         vuint32_t  RUN1:1;            /* Power domain control during RUN1 */
         vuint32_t  RUN0:1;            /* Power domain control during RUN0 */
         vuint32_t  DRUN:1;            /* Power domain control during DRUN */
         vuint32_t  SAFE:1;            /* Power domain control during SAFE */
         vuint32_t  TEST:1;            /* Power domain control during TEST */
         vuint32_t  RST:1;             /* Power domain control during RST */
      } B;
   } PCU_PCONF_32B_tag;

   typedef union {   /* PCU_PSTAT - Power Domain Status Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  PD15:1;            /* Power Status for Power Domain 15 */
         vuint32_t  PD14:1;            /* Power Status for Power Domain 14 */
         vuint32_t  PD13:1;            /* Power Status for Power Domain 13 */
         vuint32_t  PD12:1;            /* Power Status for Power Domain 12 */
         vuint32_t  PD11:1;            /* Power Status for Power Domain 11 */
         vuint32_t  PD10:1;            /* Power Status for Power Domain 10 */
         vuint32_t  PD9:1;             /* Power Status for Power Domain 9 */
         vuint32_t  PD8:1;             /* Power Status for Power Domain 8 */
         vuint32_t  PD7:1;             /* Power Status for Power Domain 7 */
         vuint32_t  PD6:1;             /* Power Status for Power Domain 6 */
         vuint32_t  PD5:1;             /* Power Status for Power Domain 5 */
         vuint32_t  PD4:1;             /* Power Status for Power Domain 4 */
         vuint32_t  PD3:1;             /* Power Status for Power Domain 3 */
         vuint32_t  PD2:1;             /* Power Status for Power Domain 2 */
         vuint32_t  PD1:1;             /* Power Status for Power Domain 1 */
         vuint32_t  PD0:1;             /* Power Status for Power Domain 0 */
      } B;
   } PCU_PSTAT_32B_tag;



   typedef struct PCU_struct_tag { /* start of PCU_tag */

       /* PCU_PCONF[0..15] -  Power Domain #0..#15 Configuration Register */
	   PCU_PCONF_32B_tag PCONF[16];      /* offset: 0x0000  (0x0004 x 16) */

	   /* PCU_PSTAT - Power Domain Status Register */
	   PCU_PSTAT_32B_tag PSTAT;          /* offset: 0x0040 size: 32 bit */
   } PCU_tag;


/****************************************************************/
/*                                                              */
/* Module: PMUCTRL  */
/*                                                              */
/****************************************************************/

   typedef union {   /* PMUCTRL_STATHVD - PMU Status Register HVD */
      vuint32_t R;
      struct {
         vuint32_t:11;
         vuint32_t  HVDT_LPB:5;        /* High Voltage Detector trimming bits LPB bus */
         vuint32_t:6;
         vuint32_t  HVD_M:1;           /* High Voltage Detector Main */
         vuint32_t  HVD_B:1;           /* High Voltage Detector Backup */
         vuint32_t:4;
         vuint32_t  HVD_LP:4;          /* High Voltage Detector trimming bits LP bus */
      } B;
   } PMUCTRL_STATHVD_32B_tag;

   typedef union {   /* PMUCTRL_STATLVD - PMU Status Register LVD */
      vuint32_t R;
      struct {
         vuint32_t:11;
         vuint32_t  LVDT_LPB:5;        /* Ligh Voltage Detector trimming bits LPB bus */
         vuint32_t:6;
         vuint32_t  LVD_M:1;           /* Ligh Voltage Detector Main */
         vuint32_t  LVD_B:1;           /* Ligh Voltage Detector Backup */
         vuint32_t:4;
         vuint32_t  LVD_LP:4;          /* Ligh Voltage Detector trimming bits LP bus */
      } B;
   } PMUCTRL_STATLVD_32B_tag;

   typedef union {   /* PMUCTRL_STATIREG - PMU Status Register IREG */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  IIREG_HP:4;        /* Internal ballast REGulator hpreg1 trimming bits */
      } B;
   } PMUCTRL_STATIREG_32B_tag;

   typedef union {   /* PMUCTRL_STATEREG - PMU Status Register EREG */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  EEREG_HP:4;        /* Internal ballast REGulator hpreg1 trimming bits */
      } B;
   } PMUCTRL_STATEREG_32B_tag;

   typedef union {   /* PMUCTRL_STATUS - PMU Status Register STATUS */
      vuint32_t R;
      struct {
         vuint32_t  EBMM:1;            /* External Ballast Management Mode */
         vuint32_t  AEBD:1;            /* Automatic External Ballast Detection */
         vuint32_t  ENPN:1;            /* External NPN status flag */
         vuint32_t:13;
         vuint32_t  CTB:2;             /* Configuration Trace Bits */
         vuint32_t:6;
         vuint32_t  CBS:4;             /* Current BIST Status */
         vuint32_t  CPCS:4;            /* Current Pmu Configuration Status */
      } B;
   } PMUCTRL_STATUS_32B_tag;

   typedef union {   /* PMUCTRL_CTRL - PMU Control Register */
      vuint32_t R;
      struct {
         vuint32_t:30;
         vuint32_t  SILHT:2;           /* Start Idle or LVD or HVD BIST Test */
      } B;
   } PMUCTRL_CTRL_32B_tag;

   typedef union {   /* PMUCTRL_MASKF - PMU Mask Fault Register */
      vuint32_t R;
      struct {
         vuint32_t  MF_BB:4;           /* Mask Fault Bypass Balast */
         vuint32_t:28;
      } B;
   } PMUCTRL_MASKF_32B_tag;

   typedef union {   /* PMUCTRL_FAULT - PMU Fault Monitor Register */
      vuint32_t R;
      struct {
         vuint32_t  BB_LV:4;           /* Bypass Ballast Low Voltage */
         vuint32_t:9;
         vuint32_t  FLNCF:1;           /* FLash voltage monitor Non Critical Fault */
         vuint32_t  IONCF:1;           /* IO voltage monitor Non Critical Fault */
         vuint32_t  RENCF:1;           /* REgulator voltage monitor Non Critical Fault */
         vuint32_t:13;
         vuint32_t  LHCF:1;            /* Low High voltage detector Critical Fault */
         vuint32_t  LNCF:1;            /* Low  voltage detector Non Critical Fault */
         vuint32_t  HNCF:1;            /* High voltage detector Non Critical Fault */
      } B;
   } PMUCTRL_FAULT_32B_tag;

   typedef union {   /* PMUCTRL_IRQS - PMU Interrupt Request Status Register */
      vuint32_t R;
      struct {
         vuint32_t:10;
         vuint32_t  MFVMP:1;           /* Main   Flash     Voltage Monitor interrupt Pending */
         vuint32_t  BFVMP:1;           /* Backup Flash     Voltage Monitor interrupt Pending */
         vuint32_t  MIVMP:1;           /* MAin   IO        Voltage Monitor interrupt Pending */
         vuint32_t  BIVMP:1;           /* Backup IO        Voltage Monitor interrupt Pending */
         vuint32_t  MRVMP:1;           /* Main   Regulator Voltage Monitor interrupt Pending */
         vuint32_t  BRVMP:1;           /* Backup Regulator Voltage Monitor interrupt Pending */
         vuint32_t:12;
         vuint32_t  MLVDP:1;           /* Main   Low  Voltage Detector error interrupt Pending */
         vuint32_t  BLVDP:1;           /* Backup Low  Voltage Detector error interrupt Pending */
         vuint32_t  MHVDP:1;           /* Main   High Voltage Detector error interrupt Pending */
         vuint32_t  BHVDP:1;           /* Backup High Voltage Detector error interrupt Pending */
      } B;
   } PMUCTRL_IRQS_32B_tag;

   typedef union {   /* PMUCTRL_IRQE - PMU Interrupt Request Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:10;
         vuint32_t  MFVME:1;           /* Main   Flash     Voltage Monitor interrupt Enable */
         vuint32_t  BFVME:1;           /* Backup Flash     Voltage Monitor interrupt Enable */
         vuint32_t  MIVME:1;           /* MAin   IO        Voltage Monitor interrupt Enable */
         vuint32_t  BIVME:1;           /* Backup IO        Voltage Monitor interrupt Enable */
         vuint32_t  MRVME:1;           /* Main   Regulator Voltage Monitor interrupt Enable */
         vuint32_t  BRVME:1;           /* Backup Regulator Voltage Monitor interrupt Enable */
         vuint32_t:12;
         vuint32_t  MLVDE:1;           /* Main   Low  Voltage Detector error interrupt Enable */
         vuint32_t  BLVDE:1;           /* Backup Low  Voltage Detector error interrupt Enable */
         vuint32_t  MHVDE:1;           /* Main   High Voltage Detector error interrupt Enable */
         vuint32_t  BHVDE:1;           /* Backup High Voltage Detector error interrupt Enable */
      } B;
   } PMUCTRL_IRQE_32B_tag;



   typedef struct PMUCTRL_struct_tag { /* start of PMUCTRL_tag */
      int8_t PMUCTRL_reserved_0000[4];
	  /* PMUCTRL_STATHVD - PMU Status Register HVD */
      PMUCTRL_STATHVD_32B_tag STATHVD;     /* offset: 0x0004 size: 32 bit */
	  /* PMUCTRL_STATLVD - PMU Status Register LVD */
      PMUCTRL_STATLVD_32B_tag STATLVD;     /* offset: 0x0008 size: 32 bit */
      int8_t PMUCTRL_reserved_000C[20];
	  /* PMUCTRL_STATIREG - PMU Status Register IREG */
      PMUCTRL_STATIREG_32B_tag STATIREG;   /* offset: 0x0020 size: 32 bit */
	  /* PMUCTRL_STATEREG - PMU Status Register EREG */
      PMUCTRL_STATEREG_32B_tag STATEREG;   /* offset: 0x0024 size: 32 bit */
      int8_t PMUCTRL_reserved_0028[24];
	  /* PMUCTRL_STATUS - PMU Status Register STATUS */
      PMUCTRL_STATUS_32B_tag STATUS;       /* offset: 0x0040 size: 32 bit */
	  /* PMUCTRL_CTRL - PMU Control Register */
      PMUCTRL_CTRL_32B_tag CTRL;           /* offset: 0x0044 size: 32 bit */
      int8_t PMUCTRL_reserved_0048[40];
	  /* PMUCTRL_MASKF - PMU Mask Fault Register */
      PMUCTRL_MASKF_32B_tag MASKF;         /* offset: 0x0070 size: 32 bit */
	  /* PMUCTRL_FAULT - PMU Fault Monitor Register */
      PMUCTRL_FAULT_32B_tag FAULT;         /* offset: 0x0074 size: 32 bit */
	  /* PMUCTRL_IRQS - PMU Interrupt Request Status Register */
      PMUCTRL_IRQS_32B_tag IRQS;           /* offset: 0x0078 size: 32 bit */
	  /* PMUCTRL_IRQE - PMU Interrupt Request Enable Register */
      PMUCTRL_IRQE_32B_tag IRQE;           /* offset: 0x007C size: 32 bit */
   } PMUCTRL_tag;


/****************************************************************/
/*                                                              */
/* Module: PIT 				 */
/*                                                              */
/****************************************************************/

   typedef union {   /* PIT_RTI_PITMCR - PIT Module Control Register */
      vuint32_t R;
      struct {
         vuint32_t:30;
         vuint32_t  MDIS:1;            /* Module Disable. Disable the module clock */
         vuint32_t  FRZ:1;             /* Freeze. Allows the timers to be stoppedwhen the device enters debug mode */
      } B;
   } PIT_RTI_PITMCR_32B_tag;

   /* Register layout for all registers LDVAL... */

   typedef union {   /* PIT_RTI_LDVAL - Timer Load Value Register */
      vuint32_t R;
      struct {
         vuint32_t  TSV:32;            /* Time Start Value Bits */
      } B;
   } PIT_RTI_LDVAL_32B_tag;

   /* Register layout for all registers CVAL... */

   typedef union {   /* PIT_RTI_CVAL - Current Timer Value Register */
      vuint32_t R;
      struct {
         vuint32_t  TVL:32;            /* Current Timer Value Bits */
      } B;
   } PIT_RTI_CVAL_32B_tag;

   /* Register layout for all registers TCTRL... */

   typedef union {   /* PIT_RTI_TCTRL - Timer Control Register */
      vuint32_t R;
      struct {
         vuint32_t:30;
         vuint32_t  TIE:1;             /* Timer Interrupt Enable Bit */
         vuint32_t  TEN:1;             /* Timer Enable Bit */
      } B;
   } PIT_RTI_TCTRL_32B_tag;

   /* Register layout for all registers TFLG... */

   typedef union {   /* PIT_RTI_TFLG - Timer Flag Register */
      vuint32_t R;
      struct {
         vuint32_t:31;
         vuint32_t  TIF:1;             /* Timer Interrupt Flag Bit */
      } B;
   } PIT_RTI_TFLG_32B_tag;


   typedef struct PIT_RTI_CHANNEL_struct_tag {

	  /* PIT_RTI_LDVAL - Timer Load Value Register */
      PIT_RTI_LDVAL_32B_tag LDVAL;        /* relative offset: 0x0000 */
	  /* PIT_RTI_CVAL - Current Timer Value Register */
      PIT_RTI_CVAL_32B_tag CVAL;          /* relative offset: 0x0004 */
	  /* PIT_RTI_TCTRL - Timer Control Register */
      PIT_RTI_TCTRL_32B_tag TCTRL;        /* relative offset: 0x0008 */
	  /* PIT_RTI_TFLG - Timer Flag Register */
      PIT_RTI_TFLG_32B_tag TFLG;          /* relative offset: 0x000C */

   } PIT_RTI_CHANNEL_tag;

   typedef struct PIT_RTI_struct_tag { /* start of PIT_RTI_tag */
	   /* PIT_RTI_PITMCR - PIT Module Control Register */
	   PIT_RTI_PITMCR_32B_tag PITMCR;       /* offset: 0x0000 size: 32 bit */

	   int8_t PIT_RTI_reserved_0004_C[252];

	   /*  Register set CHANNEL */
	   PIT_RTI_CHANNEL_tag CH[4];   /* offset: 0x0100  (0x0010 x 4) */

   } PIT_RTI_tag;


/****************************************************************/
/*                                                              */
/* Module: ADC  */
/*                                                              */
/****************************************************************/

   typedef union {   /* module configuration register */
      vuint32_t R;
      struct {
         vuint32_t  OWREN:1;           /* Overwrite enable */
         vuint32_t  WLSIDE:1;          /* Write Left/right Alligned */
         vuint32_t  MODE:1;            /* One Shot/Scan Mode Selectiom */
         vuint32_t  EDGLEV:1;          /* edge or level selection for external start trigger */
         vuint32_t  TRGEN:1;           /* external trigger enable */
         vuint32_t  EDGE:1;            /* start trigger egde /level detection */
         vuint32_t  XSTRTEN:1;         /* EXTERNAL START ENABLE */
         vuint32_t  NSTART:1;          /* start normal conversion */
         vuint32_t:1;
         vuint32_t  JTRGEN:1;          /* Injectin External Trigger Enable */
         vuint32_t  JEDGE:1;           /* start trigger egde /level detection for injected */
         vuint32_t  JSTART:1;          /* injected conversion start */
         vuint32_t:2;
         vuint32_t  CTUEN:1;           /* CTU enabaled */
         vuint32_t:8;
         vuint32_t  ADCLKSEL:1;        /* Select which clock for device */
         vuint32_t  ABORTCHAIN:1;      /* abort chain conversion */
         vuint32_t  ABORT:1;           /* abort current conversion */
         vuint32_t  ACK0:1;            /* Auto Clock Off Enable */
         vuint32_t  OFFREFRESH:1;      /* offset phase selection */
         vuint32_t  OFFCANC:1;         /* offset phase cancellation selection */
         vuint32_t:2;
         vuint32_t  PWDN:1;            /* Power Down Enable */
      } B;
   } ADC_MCR_32B_tag;

   typedef union {   /* module status register */
      vuint32_t R;
      struct {
         vuint32_t:7;
         vuint32_t  NSTART:1;          /* normal conversion status */
         vuint32_t  JABORT:1;          /* Injection chain abort status */
         vuint32_t:2;
         vuint32_t  JSTART:1;          /* Injection Start status */
         vuint32_t:3;
         vuint32_t  CTUSTART:1;        /* ctu start status */
         vuint32_t  CHADDR:7;          /* which address conv is goin on */
         vuint32_t:3;
         vuint32_t  ACK0:1;            /* Auto Clock Off Enable status */
         vuint32_t  OFFREFRESH:1;      /* offset refresh status */
         vuint32_t  OFFCANC:1;         /* offset phase cancellation status */
         vuint32_t  ADCSTATUS:3;       /* status of ADC FSM */
      } B;
   } ADC_MSR_32B_tag;

   typedef union {   /* Interrupt status register */
      vuint32_t R;
      struct {
         vuint32_t:25;
         vuint32_t  OFFCANCOVR:1;      /* Offset cancellation phase over */
         vuint32_t  EOFFSET:1;         /* error in offset refresh */
         vuint32_t  EOCTU:1;           /* end of CTU channel conversion */
         vuint32_t  JEOC:1;            /* end of injected channel conversion */
         vuint32_t  JECH:1;            /* end ofinjected chain conversion */
         vuint32_t  EOC:1;             /* end of channel conversion */
         vuint32_t  ECH:1;             /* end of chain conversion */
      } B;
   } ADC_ISR_32B_tag;

   typedef union {   /* CHANNEL PENDING REGISTER 0 */
      vuint32_t R;
      struct {
         vuint32_t  EOC31:1;           /* Channel 31 conversion over */
         vuint32_t  EOC30:1;           /* Channel 30 conversion over */
         vuint32_t  EOC29:1;           /* Channel 29 conversion over */
         vuint32_t  EOC28:1;           /* Channel 28 conversion over */
         vuint32_t  EOC27:1;           /* Channel 27 conversion over */
         vuint32_t  EOC26:1;           /* Channel 26 conversion over */
         vuint32_t  EOC25:1;           /* Channel 25 conversion over */
         vuint32_t  EOC24:1;           /* Channel 24 conversion over */
         vuint32_t  EOC23:1;           /* Channel 23 conversion over */
         vuint32_t  EOC22:1;           /* Channel 22 conversion over */
         vuint32_t  EOC21:1;           /* Channel 21 conversion over */
         vuint32_t  EOC20:1;           /* Channel 20 conversion over */
         vuint32_t  EOC19:1;           /* Channel 19 conversion over */
         vuint32_t  EOC18:1;           /* Channel 18 conversion over */
         vuint32_t  EOC17:1;           /* Channel 17 conversion over */
         vuint32_t  EOC16:1;           /* Channel 16 conversion over */
         vuint32_t  EOC15:1;           /* Channel 15 conversion over */
         vuint32_t  EOC14:1;           /* Channel 14 conversion over */
         vuint32_t  EOC13:1;           /* Channel 13 conversion over */
         vuint32_t  EOC12:1;           /* Channel 12 conversion over */
         vuint32_t  EOC11:1;           /* Channel 11 conversion over */
         vuint32_t  EOC10:1;           /* Channel 10 conversion over */
         vuint32_t  EOC9:1;            /* Channel 9 conversion over */
         vuint32_t  EOC8:1;            /* Channel 8 conversion over */
         vuint32_t  EOC7:1;            /* Channel 7 conversion over */
         vuint32_t  EOC6:1;            /* Channel 6 conversion over */
         vuint32_t  EOC5:1;            /* Channel 5 conversion over */
         vuint32_t  EOC4:1;            /* Channel 4 conversion over */
         vuint32_t  EOC3:1;            /* Channel 3 conversion over */
         vuint32_t  EOC2:1;            /* Channel 2 conversion over */
		 vuint32_t  EOC1:1;            /* Channel 1 conversion over */
         vuint32_t  EOC0:1;            /* Channel 0 conversion over */
      } B;
   } ADC_CEOCFR0_32B_tag;

   typedef union {   /* interrupt mask register */
      vuint32_t R;
      struct {
         vuint32_t:25;
         vuint32_t  MSKOFFCANCOVR:1;   /* mask bit for Calibration over */
         vuint32_t  MSKEOFFSET:1;      /* mask bit for Error in offset refresh */
         vuint32_t  MSKEOCTU:1;        /* mask bit for EOCTU */
         vuint32_t  MSKJEOC:1;         /* mask bit for JEOC */
         vuint32_t  MSKJECH:1;         /* mask bit for JECH */
         vuint32_t  MSKEOC:1;          /* mask bit for EOC */
         vuint32_t  MSKECH:1;          /* mask bit for ECH */
      } B;
   } ADC_IMR_32B_tag;

   typedef union {   /* CHANNEL INTERRUPT MASK REGISTER 0 */
      vuint32_t R;
      struct {
         vuint32_t  CIM31:1;           /* Channel 31 mask register */
         vuint32_t  CIM30:1;           /* Channel 30 mask register */
         vuint32_t  CIM29:1;           /* Channel 29 mask register */
         vuint32_t  CIM28:1;           /* Channel 28 mask register */
         vuint32_t  CIM27:1;           /* Channel 27 mask register */
         vuint32_t  CIM26:1;           /* Channel 26 mask register */
         vuint32_t  CIM25:1;           /* Channel 25 mask register */
         vuint32_t  CIM24:1;           /* Channel 24 mask register */
         vuint32_t  CIM23:1;           /* Channel 23 mask register */
         vuint32_t  CIM22:1;           /* Channel 22 mask register */
         vuint32_t  CIM21:1;           /* Channel 21 mask register */
         vuint32_t  CIM20:1;           /* Channel 20 mask register */
         vuint32_t  CIM19:1;           /* Channel 19 mask register */
         vuint32_t  CIM18:1;           /* Channel 18 mask register */
         vuint32_t  CIM17:1;           /* Channel 17 mask register */
         vuint32_t  CIM16:1;           /* Channel 16 mask register */
         vuint32_t  CIM15:1;           /* Channel 15 mask register */
         vuint32_t  CIM14:1;           /* Channel 14 mask register */
         vuint32_t  CIM13:1;           /* Channel 13 mask register */
         vuint32_t  CIM12:1;           /* Channel 12 mask register */
         vuint32_t  CIM11:1;           /* Channel 11 mask register */
         vuint32_t  CIM10:1;           /* Channel 10 mask register */
         vuint32_t  CIM9:1;            /* Channel 9  mask register */
         vuint32_t  CIM8:1;            /* Channel 8  mask register */
         vuint32_t  CIM7:1;            /* Channel 7  mask register */
         vuint32_t  CIM6:1;            /* Channel 6  mask register */
         vuint32_t  CIM5:1;            /* Channel 5  mask register */
         vuint32_t  CIM4:1;            /* Channel 4  mask register */
         vuint32_t  CIM3:1;            /* Channel 3  mask register */
         vuint32_t  CIM2:1;            /* Channel 2  mask register */
         vuint32_t  CIM1:1;            /* Channel 1  mask register */
         vuint32_t  CIM0:1;            /* Channel 0  mask register */
      } B;
   } ADC_CIMR0_32B_tag;


   typedef union {   /* Watchdog Threshold interrupt status register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  WDG3H:1;           /* Interrupt generated on the value being higher than the HTHV 3 */
         vuint32_t  WDG2H:1;           /* Interrupt generated on the value being higher than the HTHV 2 */
         vuint32_t  WDG1H:1;           /* Interrupt generated on the value being higher than the HTHV 1 */
         vuint32_t  WDG0H:1;           /* Interrupt generated on the value being higher than the HTHV 0 */
         vuint32_t  WDG3L:1;           /* Interrupt generated on the value being lower than the LTHV 3 */
         vuint32_t  WDG2L:1;           /* Interrupt generated on the value being lower than the LTHV 2 */
         vuint32_t  WDG1L:1;           /* Interrupt generated on the value being lower than the LTHV 1 */
         vuint32_t  WDG0L:1;           /* Interrupt generated on the value being lower than the LTHV 0 */
      } B;
   } ADC_WTISR_32B_tag;

   typedef union {   /* Watchdog interrupt MASK register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  MSKWDG3H:1;        /* Mask enable for Interrupt generated on the value being higher than the HTHV 3 */
         vuint32_t  MSKWDG2H:1;        /* Mask enable for  Interrupt generated on the value being higher than the HTHV 2 */
         vuint32_t  MSKWDG1H:1;        /* Mask enable for Interrupt generated on the value being higher than the HTHV 1 */
         vuint32_t  MSKWDG0H:1;        /* Mask enable for Interrupt generated on the value being higher than the HTHV 0 */
         vuint32_t  MSKWDG3L:1;        /* Mask enable for Interrupt generated on the value being lower than the LTHV 3 */
         vuint32_t  MSKWDG2L:1;        /* Mask enable for Interrupt generated on the value being lower than the LTHV 2 */
         vuint32_t  MSKWDG1L:1;        /* MAsk enable for Interrupt generated on the value being lower than the LTHV 1 */
         vuint32_t  MSKWDG0L:1;        /* Mask enable for Interrupt generated on the value being lower than the LTHV 0 */
      } B;
   } ADC_WTIMR_32B_tag;

   typedef union {   /* DMAE register */
      vuint32_t R;
      struct {
         vuint32_t:30;
         vuint32_t  DCLR:1;            /* DMA clear sequence enable */
         vuint32_t  DMAEN:1;           /* DMA global enable */
      } B;
   } ADC_DMAE_32B_tag;

   typedef union {   /* DMA  REGISTER 0 */
      vuint32_t R;
      struct {
         vuint32_t  DMA31:1;           /* Channel 31 DMA Enable */
         vuint32_t  DMA30:1;           /* Channel 30 DMA Enable */
         vuint32_t  DMA29:1;           /* Channel 29 DMA Enable */
         vuint32_t  DMA28:1;           /* Channel 28 DMA Enable */
         vuint32_t  DMA27:1;           /* Channel 27 DMA Enable */
         vuint32_t  DMA26:1;           /* Channel 26 DMA Enable */
         vuint32_t  DMA25:1;           /* Channel 25 DMA Enable */
         vuint32_t  DMA24:1;           /* Channel 24 DMA Enable */
         vuint32_t  DMA23:1;           /* Channel 23 DMA Enable */
         vuint32_t  DMA22:1;           /* Channel 22 DMA Enable */
         vuint32_t  DMA21:1;           /* Channel 21 DMA Enable */
         vuint32_t  DMA20:1;           /* Channel 20 DMA Enable */
         vuint32_t  DMA19:1;           /* Channel 19 DMA Enable */
         vuint32_t  DMA18:1;           /* Channel 18 DMA Enable */
         vuint32_t  DMA17:1;           /* Channel 17 DMA Enable */
         vuint32_t  DMA16:1;           /* Channel 16 DMA Enable */
         vuint32_t  DMA15:1;           /* Channel 15 DMA Enable */
         vuint32_t  DMA14:1;           /* Channel 14 DMA Enable */
         vuint32_t  DMA13:1;           /* Channel 13 DMA Enable */
         vuint32_t  DMA12:1;           /* Channel 12 DMA Enable */
         vuint32_t  DMA11:1;           /* Channel 11 DMA Enable */
         vuint32_t  DMA10:1;           /* Channel 10 DMA Enable */
         vuint32_t  DMA9:1;            /* Channel 9 DMA Enable */
         vuint32_t  DMA8:1;            /* Channel 8 DMA Enable */
         vuint32_t  DMA7:1;            /* Channel 7 DMA Enable */
         vuint32_t  DMA6:1;            /* Channel 6 DMA Enable */
         vuint32_t  DMA5:1;            /* Channel 5 DMA Enable */
         vuint32_t  DMA4:1;            /* Channel 4 DMA Enable */
         vuint32_t  DMA3:1;            /* Channel 3 DMA Enable */
         vuint32_t  DMA2:1;            /* Channel 2 DMA Enable */
         vuint32_t  DMA1:1;            /* Channel 1 DMA Enable */
         vuint32_t  DMA0:1;            /* Channel 0 DMA Enable */
      } B;
   } ADC_DMAR0_32B_tag;


   /* Register layout for all registers TRC... */

   typedef union {   /* Threshold Control register C */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  THREN:1;           /* Threshold enable */
         vuint32_t  THRINV:1;          /* invert the output pin */
         vuint32_t  THROP:1;           /* output pin register */
         vuint32_t:6;
         vuint32_t  THRCH:7;           /* Choose channel for threshold register */
      } B;
   } ADC_TRC_32B_tag;


   /* Register layout for all registers THRHLR... */

   typedef union {   /* Upper Threshold register */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR_32B_tag;


   /* Register layout for all registers THRALT... */

   typedef union {   /* alternate Upper Threshold register */
      vuint32_t R;
      struct {
         vuint32_t:6;
         vuint32_t  THRH:10;           /* high threshold value s */
         vuint32_t:6;
         vuint32_t  THRL:10;           /* low threshold value s */
      } B;
   } ADC_THRALT_32B_tag;

   typedef union {   /* PRESAMPLING CONTROL REGISTER */
      vuint32_t R;
      struct {
         vuint32_t:25;
         vuint32_t  PREVAL2:2;         /* INternal Voltage selection for Presampling */
         vuint32_t  PREVAL1:2;         /* INternal Voltage selection for Presampling */
         vuint32_t  PREVAL0:2;         /* INternal Voltage selection for Presampling */
         vuint32_t  PREONCE:1;         /* Presampled value */
      } B;
   } ADC_PSCR_32B_tag;

   typedef union {   /* Presampling  Register 0 */
      vuint32_t R;
      struct {
         vuint32_t  PRES31:1;          /* Channel 31 Presampling  Enable */
         vuint32_t  PRES30:1;          /* Channel 30 Presampling  Enable */
         vuint32_t  PRES29:1;          /* Channel 29 Presampling  Enable */
         vuint32_t  PRES28:1;          /* Channel 28 Presampling  Enable */
         vuint32_t  PRES27:1;          /* Channel 27 Presampling  Enable */
         vuint32_t  PRES26:1;          /* Channel 26 Presampling  Enable */
         vuint32_t  PRES25:1;          /* Channel 25 Presampling  Enable */
         vuint32_t  PRES24:1;          /* Channel 24 Presampling  Enable */
         vuint32_t  PRES23:1;          /* Channel 23 Presampling  Enable */
         vuint32_t  PRES22:1;          /* Channel 22 Presampling  Enable */
         vuint32_t  PRES21:1;          /* Channel 21 Presampling  Enable */
         vuint32_t  PRES20:1;          /* Channel 20 Presampling  Enable */
         vuint32_t  PRES19:1;          /* Channel 19 Presampling  Enable */
         vuint32_t  PRES18:1;          /* Channel 18 Presampling  Enable */
         vuint32_t  PRES17:1;          /* Channel 17 Presampling  Enable */
         vuint32_t  PRES16:1;          /* Channel 16 Presampling  Enable */
         vuint32_t  PRES15:1;          /* Channel 15 Presampling  Enable */
         vuint32_t  PRES14:1;          /* Channel 14 Presampling  Enable */
         vuint32_t  PRES13:1;          /* Channel 13 Presampling   Enable */
         vuint32_t  PRES12:1;          /* Channel 12 Presampling  Enable */
         vuint32_t  PRES11:1;          /* Channel 11 Presampling  Enable */
         vuint32_t  PRES10:1;          /* Channel 10 Presampling   Enable */
         vuint32_t  PRES9:1;           /* Channel 9 Presampling   Enable */
         vuint32_t  PRES8:1;           /* Channel 8 Presampling  Enable */
         vuint32_t  PRES7:1;           /* Channel 7 Presampling    Enable */
         vuint32_t  PRES6:1;           /* Channel 6 Presampling   Enable */
         vuint32_t  PRES5:1;           /* Channel 5 Presampling  Enable */
         vuint32_t  PRES4:1;           /* Channel 4 Presampling  Enable */
         vuint32_t  PRES3:1;           /* Channel 3 Presampling  Enable */
         vuint32_t  PRES2:1;           /* Channel 2 Presampling  Enable */
         vuint32_t  PRES1:1;           /* Channel 1 Presampling  Enable */
         vuint32_t  PRES0:1;           /* Channel 0 Presampling  Enable */
      } B;
   } ADC_PSR0_32B_tag;


   /* Register layout for all registers CTR... */

   typedef union {   /* conversion timing register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  INPLATCH:1;        /* configuration bits for the LATCHING PHASE duration */
         vuint32_t:1;
         vuint32_t  OFFSHIFT:2;        /* configuration for offset shift characteristics */
         vuint32_t:1;
         vuint32_t  INPCMP:2;          /* configuration bits for the COMPARISON duration */
         vuint32_t:1;
         vuint32_t  INPSAMP:8;			/* configuration bits for the SAMPLING PHASE duration */
      } B;
   } ADC_CTR_32B_tag;

   typedef union {   /* NORMAL CONVERSION MASK REGISTER 0 */
      vuint32_t R;
      struct {
         vuint32_t  CH31:1;            /* Channel 31 Normal Sampling Enable */
         vuint32_t  CH30:1;            /* Channel 30 Normal Sampling Enable */
         vuint32_t  CH29:1;            /* Channel 29 Normal Sampling Enable */
         vuint32_t  CH28:1;            /* Channel 28 Normal Sampling Enable */
         vuint32_t  CH27:1;            /* Channel 27 Normal Sampling Enable */
         vuint32_t  CH26:1;            /* Channel 26 Normal Sampling Enable */
         vuint32_t  CH25:1;            /* Channel 25 Normal Sampling Enable */
         vuint32_t  CH24:1;            /* Channel 24 Normal Sampling Enable */
         vuint32_t  CH23:1;            /* Channel 23 Normal Sampling Enable */
         vuint32_t  CH22:1;            /* Channel 22 Normal Sampling Enable */
         vuint32_t  CH21:1;            /* Channel 21 Normal Sampling Enable */
         vuint32_t  CH20:1;            /* Channel 20 Normal Sampling Enable */
         vuint32_t  CH19:1;            /* Channel 19 Normal Sampling Enable */
         vuint32_t  CH18:1;            /* Channel 18 Normal Sampling Enable */
         vuint32_t  CH17:1;            /* Channel 17 Normal Sampling Enable */
         vuint32_t  CH16:1;            /* Channel 16 Normal Sampling Enable */
         vuint32_t  CH15:1;            /* Channel 15 Normal Sampling Enable */
         vuint32_t  CH14:1;            /* Channel 14 Normal Sampling Enable */
         vuint32_t  CH13:1;            /* Channel 13 Normal Sampling Enable */
         vuint32_t  CH12:1;            /* Channel 12 Normal Sampling Enable */
         vuint32_t  CH11:1;            /* Channel 11 Normal Sampling Enable */
         vuint32_t  CH10:1;            /* Channel 10 Normal Sampling Enable */
         vuint32_t  CH9:1;             /* Channel 9 Normal Sampling Enable */
         vuint32_t  CH8:1;             /* Channel 8 Normal Sampling Enable */
         vuint32_t  CH7:1;             /* Channel 7 Normal Sampling Enable */
         vuint32_t  CH6:1;             /* Channel 6 Normal Sampling Enable */
         vuint32_t  CH5:1;             /* Channel 5 Normal Sampling Enable */
         vuint32_t  CH4:1;             /* Channel 4 Normal Sampling Enable */
         vuint32_t  CH3:1;             /* Channel 3 Normal Sampling Enable */
         vuint32_t  CH2:1;             /* Channel 2 Normal Sampling Enable */
         vuint32_t  CH1:1;             /* Channel 1 Normal Sampling Enable */
         vuint32_t  CH0:1;             /* Channel 0 Normal Sampling Enable */
      } B;
   } ADC_NCMR0_32B_tag;


   typedef union {   /* Injected Conversion Mask Register 0 */
      vuint32_t R;
      struct {
         vuint32_t  CH31:1;            /* Channel 31 Injected Sampling Enable */
         vuint32_t  CH30:1;            /* Channel 30 Injected Sampling Enable */
         vuint32_t  CH29:1;            /* Channel 29 Injected Sampling Enable */
         vuint32_t  CH28:1;            /* Channel 28 Injected Sampling Enable */
         vuint32_t  CH27:1;            /* Channel 27 Injected Sampling Enable */
         vuint32_t  CH26:1;            /* Channel 26 Injected Sampling Enable */
         vuint32_t  CH25:1;            /* Channel 25 Injected Sampling Enable */
         vuint32_t  CH24:1;            /* Channel 24 Injected Sampling Enable */
         vuint32_t  CH23:1;            /* Channel 23 Injected Sampling Enable */
         vuint32_t  CH22:1;            /* Channel 22 Injected Sampling Enable */
         vuint32_t  CH21:1;            /* Channel 21 Injected Sampling Enable */
         vuint32_t  CH20:1;            /* Channel 20 Injected Sampling Enable */
         vuint32_t  CH19:1;            /* Channel 19 Injected Sampling Enable */
         vuint32_t  CH18:1;            /* Channel 18 Injected Sampling Enable */
         vuint32_t  CH17:1;            /* Channel 17 Injected Sampling Enable */
         vuint32_t  CH16:1;            /* Channel 16 Injected Sampling Enable */
         vuint32_t  CH15:1;            /* Channel 15 Injected Sampling Enable */
         vuint32_t  CH14:1;            /* Channel 14 Injected Sampling Enable */
         vuint32_t  CH13:1;            /* Channel 13 Injected Sampling Enable */
         vuint32_t  CH12:1;            /* Channel 12 Injected Sampling Enable */
         vuint32_t  CH11:1;            /* Channel 11 Injected Sampling Enable */
         vuint32_t  CH10:1;            /* Channel 10 Injected Sampling Enable */
         vuint32_t  CH9:1;             /* Channel 9 Injected Sampling Enable */
         vuint32_t  CH8:1;             /* Channel 8 Injected Sampling Enable */
         vuint32_t  CH7:1;             /* Channel 7 Injected Sampling Enable */
         vuint32_t  CH6:1;             /* Channel 6 Injected Sampling Enable */
         vuint32_t  CH5:1;             /* Channel 5 Injected Sampling Enable */
         vuint32_t  CH4:1;             /* Channel 4 Injected Sampling Enable */
         vuint32_t  CH3:1;             /* Channel 3 Injected Sampling Enable */
         vuint32_t  CH2:1;             /* Channel 2 Injected Sampling Enable */
         vuint32_t  CH1:1;             /* Channel 1 injected Sampling Enable */
         vuint32_t  CH0:1;             /* Channel 0 injected Sampling Enable */
      } B;
   } ADC_JCMR0_32B_tag;


   typedef union {   /* Offset Word Regsiter */
      vuint32_t R;
      struct {
         vuint32_t:15;
         vuint32_t  OFFSETLOAD:1;      /* load_offset */
         vuint32_t:8;
         vuint32_t  OFFSETWORD:8;  		/* OFFSET word coeff.generated at the end of offset cancellation is lathed int o this register */
      } B;
   } ADC_OFFWR_32B_tag;

   typedef union {   /* Decode Signal Delay Register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  DSD:8;             /* take into account the settling time of the external mux */
      } B;
   } ADC_DSDR_32B_tag;

   typedef union {   /* Power Down Dealy Register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  PDED:8;            /* The delay between the power down bit reset and the starting of conversion */
      } B;
   } ADC_PDEDR_32B_tag;

   /* Register layout for all registers CDR... */

   typedef union {   /* CHANNEL DATA REGS */
      vuint32_t R;
      struct {
         vuint32_t:12;
         vuint32_t  VALID:1;           /* validity of data */
         vuint32_t  OVERW:1;           /* overwrite data */
         vuint32_t  RESULT:2;          /* reflects mode conversion */
         vuint32_t:6;
         vuint32_t  CDATA:10;          /* Channel 0 converted data */
      } B;
   } ADC_CDR_32B_tag;

   typedef union {   /* Upper Threshold register 4 is not contiguous to 3 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR4_32B_tag;

   typedef union {   /* Upper Threshold register 5 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR5_32B_tag;

   typedef union {   /* Upper Threshold register 6 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR6_32B_tag;

   typedef union {   /* Upper Threshold register 7 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR7_32B_tag;

   typedef union {   /* Upper Threshold register 8 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR8_32B_tag;

   typedef union {   /* Upper Threshold register 9 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR9_32B_tag;

   typedef union {   /* Upper Threshold register 10 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR10_32B_tag;

   typedef union {   /* Upper Threshold register 11 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR11_32B_tag;

   typedef union {   /* Upper Threshold register 12 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR12_32B_tag;

   typedef union {   /* Upper Threshold register 13 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR13_32B_tag;

   typedef union {   /* Upper Threshold register 14 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR14_32B_tag;

   typedef union {   /* Upper Threshold register 15 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* high threshold value s */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* low threshold value s */
      } B;
   } ADC_THRHLR15_32B_tag;


   /* Register layout for all registers CWSELR... */

   typedef union {   /* Channel Watchdog Select register */
      vuint32_t R;
      struct {
         vuint32_t  WSEL_CH7:4;        /* Channel Watchdog select for channel 7+R*8 */
         vuint32_t  WSEL_CH6:4;        /* Channel Watchdog select for channel 6+R*8 */
         vuint32_t  WSEL_CH5:4;        /* Channel Watchdog select for channel 5+R*8 */
         vuint32_t  WSEL_CH4:4;        /* Channel Watchdog select for channel 4+R*8 */
         vuint32_t  WSEL_CH3:4;        /* Channel Watchdog select for channel 3+R*8 */
         vuint32_t  WSEL_CH2:4;        /* Channel Watchdog select for channel 2+R*8 */
         vuint32_t  WSEL_CH1:4;        /* Channel Watchdog select for channel 1+R*8 */
         vuint32_t  WSEL_CH0:4;        /* Channel Watchdog select for channel 0+R*8 */
      } B;
   } ADC_CWSELR_32B_tag;


   /* Register layout for all registers CWENR... */

   typedef union {   /* Channel Watchdog Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  CWEN15PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN14PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN13PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN12PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN11PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN10PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN09PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN08PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN07PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN06PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN05PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN04PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN03PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN02PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN01PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
         vuint32_t  CWEN00PRT32:1;     /* Channel Watchdog Enable 0+R*32 */
      } B;
   } ADC_CWENR_32B_tag;


   /* Register layout for all registers AWORR... */

   typedef union {   /* Analog Watchdog Out of Range Register */
      vuint32_t R;
      struct {
         vuint32_t  AWOR_CH31:1;       /* Channel 31+R*32 converted data out of range */
         vuint32_t  AWOR_CH30:1;       /* Channel 30+R*32 converted data out of range */
         vuint32_t  AWOR_CH29:1;       /* Channel 29+R*32 converted data out of range */
         vuint32_t  AWOR_CH28:1;       /* Channel 28+R*32 converted data out of range */
         vuint32_t  AWOR_CH27:1;       /* Channel 27+R*32 converted data out of range */
         vuint32_t  AWOR_CH26:1;       /* Channel 26+R*32 converted data out of range */
         vuint32_t  AWOR_CH25:1;       /* Channel 25+R*32 converted data out of range */
         vuint32_t  AWOR_CH24:1;       /* Channel 24+R*32 converted data out of range */
         vuint32_t  AWOR_CH23:1;       /* Channel 23+R*32 converted data out of range */
         vuint32_t  AWOR_CH22:1;       /* Channel 22+R*32 converted data out of range */
         vuint32_t  AWOR_CH21:1;       /* Channel 21+R*32 converted data out of range */
         vuint32_t  AWOR_CH20:1;       /* Channel 20+R*32 converted data out of range */
         vuint32_t  AWOR_CH19:1;       /* Channel 19+R*32 converted data out of range */
         vuint32_t  AWOR_CH18:1;       /* Channel 18+R*32 converted data out of range */
         vuint32_t  AWOR_CH17:1;       /* Channel 17+R*32 converted data out of range */
         vuint32_t  AWOR_CH16:1;       /* Channel 16+R*32 converted data out of range */
         vuint32_t  AWOR_CH15:1;       /* Channel 15+R*32 converted data out of range */
         vuint32_t  AWOR_CH14:1;       /* Channel 14+R*32 converted data out of range */
         vuint32_t  AWOR_CH13:1;       /* Channel 13+R*32 converted data out of range */
         vuint32_t  AWOR_CH12:1;       /* Channel 12+R*32 converted data out of range */
         vuint32_t  AWOR_CH11:1;       /* Channel 11+R*32 converted data out of range */
         vuint32_t  AWOR_CH10:1;       /* Channel 10+R*32 converted data out of range */
         vuint32_t  AWOR_CH9:1;        /* Channel 9+R*32 converted data out of range */
         vuint32_t  AWOR_CH8:1;        /* Channel 8+R*32 converted data out of range */
         vuint32_t  AWOR_CH7:1;        /* Channel 7+R*32 converted data out of range */
         vuint32_t  AWOR_CH6:1;        /* Channel 6+R*32 converted data out of range */
         vuint32_t  AWOR_CH5:1;        /* Channel 5+R*32 converted data out of range */
         vuint32_t  AWOR_CH4:1;        /* Channel 4+R*32 converted data out of range */
         vuint32_t  AWOR_CH3:1;        /* Channel 3+R*32 converted data out of range */
         vuint32_t  AWOR_CH2:1;        /* Channel 2+R*32 converted data out of range */
         vuint32_t  AWOR_CH1:1;        /* Channel 1+R*32 converted data out of range */
         vuint32_t  AWOR_CH0:1;        /* Channel 0+R*32 converted data out of range */
      } B;
   } ADC_AWORR_32B_tag;

   typedef union {   /* SELF TEST CONFIGURATION REGISTER 1 */
      vuint32_t R;
      struct {
         vuint32_t  INPSAMP_C:8;       /* Sampling phase duration for the test conversions - algorithm C */
         vuint32_t  INPSAMP_RC:8;      /* Sampling phase duration for the test conversions - algorithm RC */
         vuint32_t  INPSAMP_S:8;       /* Sampling phase duration for the test conversions - algorithm S */
         vuint32_t:5;
         vuint32_t  ST_INPCMP:2;       /* Configuration bit for comparison phase duration for self test channel */
         vuint32_t  ST_INPLATCH:1;     /* Configuration bit for Latching phase duration for self test channel */
      } B;
   } ADC_STCR1_32B_tag;

   typedef union {   /* SELF TEST CONFIGURATION REGISTER 2 */
      vuint32_t R;
      struct {
         vuint32_t:5;
         vuint32_t  SERR:1;            /* Error fault injection bit (write only) */
         vuint32_t  MSKSTWDTERR:1;     /* Interrupt enable (STSR2.WDTERR status bit) */
         vuint32_t:1;
         vuint32_t  MSKST_EOC:1;       /* Interrupt enable bit for STSR2.ST_EOC */
         vuint32_t:4;
         vuint32_t  MSKWDG_EOA_C:1;    /* Interrupt enable (WDG_EOA_C status bit) */
         vuint32_t  MSKWDG_EOA_RC:1;   /* Interrupt enable (WDG_EOA_RC status bit) */
         vuint32_t  MSKWDG_EOA_S:1;    /* Interrupt enable (WDG_EOA_S status bit) */
         vuint32_t  MSKERR_C:1;        /* Interrupt enable (ERR_C status bit) */
         vuint32_t  MSKERR_RC:1;       /* Interrupt enable (ERR_RC status bit) */
         vuint32_t  MSKERR_S2:1;       /* Interrupt enable (ERR_S2 status bit) */
         vuint32_t  MSKERR_S1:1;       /* Interrupt enable (ERR_S1 status bit) */
         vuint32_t  MSKERR_S0:1;       /* Interrupt enable (ERR_S0 status bit) */
         vuint32_t:3;
         vuint32_t  EN:1;              /* Self testing channel enable */
         vuint32_t:4;
         vuint32_t  FMA_C:1;           /* Fault mapping for the algorithm C */
         vuint32_t  FMAR_C:1;          /* Fault mapping for the algorithm RC */
         vuint32_t  FMA_S:1;           /* Fault mapping for the algorithm BGAP */
      } B;
   } ADC_STCR2_32B_tag;

   typedef union {   /* SELF TEST CONFIGURATION REGISTER 3 */
      vuint32_t R;
      struct {
         vuint32_t:22;
         vuint32_t  ALG:2;             /* Algorithm scheduling */
         vuint32_t:8;
      } B;
   } ADC_STCR3_32B_tag;

   typedef union {   /* SELF TEST BAUD RATE REGISTER */
      vuint32_t R;
      struct {
         vuint32_t:13;
         vuint32_t  WDT:3;             /* Watchdog timer value */
         vuint32_t:8;
         vuint32_t  BR:8;              /* Baud rate for the selected algorithm in SCAN mode */
      } B;
   } ADC_STBRR_32B_tag;

   typedef union {   /* SELF TEST STATUS REGISTER 1 */
      vuint32_t R;
      struct {
         vuint32_t:6;
         vuint32_t  WDTERR:1;          /* Watchdog timer error */
         vuint32_t  OVERWR:1;          /* Overwrite error */
         vuint32_t  ST_EOC:1;          /* Self test EOC bit */
         vuint32_t:4;
         vuint32_t  WDG_EOA_C:1;       /* Algorithm  C completed without error */
         vuint32_t  WDG_EOA_RC:1;      /* Algorithm RC completed without error */
         vuint32_t  WDG_EOA_S:1;       /* Algorithm  S completed without error */
         vuint32_t  ERR_C:1;           /* Error on the self testing channel (algorithm  C) */
         vuint32_t  ERR_RC:1;          /* Error on the self testing channel (algorithm RC) */
         vuint32_t  ERR_S2:1;          /* Error on the self testing channel (algorithm SUPPLY, step 2) */
         vuint32_t  ERR_S1:1;          /* Error on the self testing channel (algorithm SUPPLY, step 1) */
         vuint32_t  ERR_S0:1;          /* Error on the self testing channel (algorithm SUPPLY, step 0) */
         vuint32_t:1;
         vuint32_t  STEP_C:5;          /* Step of algorithm  C when ERR_C  has occurred */
         vuint32_t  STEP_RC:5;         /* Step of algorithm RC when ERR_RC has occurred */
      } B;
   } ADC_STSR1_32B_tag;

   typedef union {   /* SELF TEST STATUS REGISTER 2 */
      vuint32_t R;
      struct {
         vuint32_t  OVFL:1;            /* Overflow bit */
         vuint32_t:3;
         vuint32_t  DATA1:12;          /* Test channel converted data when ERR_S1 has occurred */
         vuint32_t:4;
         vuint32_t  DATA0:12;          /* Test channel converted data when ERR_S1 has occurred */
      } B;
   } ADC_STSR2_32B_tag;

   typedef union {   /* SELF TEST STATUS REGISTER 3 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  DATA1:12;          /* Test channel converted data when ERR_S0 has occurred */
         vuint32_t:4;
         vuint32_t  DATA0:12;          /* Test channel converted data when ERR_S0 has occurred */
      } B;
   } ADC_STSR3_32B_tag;

   typedef union {   /* SELF TEST STATUS REGISTER 4 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  DATA1:12;          /* Test channel converted data when ERR_C has occurred */
         vuint32_t:4;
         vuint32_t  DATA0:12;          /* Test channel converted data when ERR_C has occurred */
      } B;
   } ADC_STSR4_32B_tag;

   typedef union {   /* SELF TEST DATA REGISTER 1 */
      vuint32_t R;
      struct {
         vuint32_t:12;
         vuint32_t  VALID:1;           /* Valid data */
         vuint32_t  OVERWR:1;          /* Overwrite data */
         vuint32_t:6;
         vuint32_t  TCDATA:12;         /* Test channel converted data */
      } B;
   } ADC_STDR1_32B_tag;

   typedef union {   /* SELF TEST DATA REGISTER 2 */
      vuint32_t R;
      struct {
         vuint32_t  FDATA:12;          /* Fractional part of the ratio TEST for algorithm S */
         vuint32_t  VALID:1;           /* Valid data */
         vuint32_t  OVERWR:1;          /* Overwrite data */
         vuint32_t:6;
         vuint32_t  IDATA:12;          /* Integer part of the ratio TEST for algorithm S */
      } B;
   } ADC_STDR2_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 0 */
      vuint32_t R;
      struct {
         vuint32_t  AWDE:1;            /* Analog WatchDog Enable - algorithm S */
         vuint32_t  WDTE:1;            /* WatchDog Timer Enable - algorithm S */
         vuint32_t:2;
         vuint32_t  THRH:12;           /* High threshold value for channel 0 */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* Low threshold value for channel 0 */
      } B;
   } ADC_STAW0R_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 1A */
      vuint32_t R;
      struct {
         vuint32_t  AWDE:1;            /* Analog WatchDog Enable - algorithm S */
         vuint32_t:3;
         vuint32_t  THRH:12;           /* High threshold value for test channel - algorithm S */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* Low threshold value for test channel - algorithm S */
      } B;
   } ADC_STAW1AR_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 1B */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* High threshold value for test channel - algorithm S */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* Low threshold value for test channel - algorithm S */
      } B;
   } ADC_STAW1BR_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 2 */
      vuint32_t R;
      struct {
         vuint32_t  AWDE:1;            /* Analog WatchDog Enable - algorithm S */
         vuint32_t:19;
         vuint32_t  THRL:12;           /* Low threshold value for channel */
      } B;
   } ADC_STAW2R_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 3 */
      vuint32_t R;
      struct {
         vuint32_t  AWDE:1;            /* Analog WatchDog Enable - algorithm RC */
         vuint32_t  WDTE:1;            /* WatchDog Timer Enable - algorithm RC */
         vuint32_t:2;
         vuint32_t  THRH:12;           /* High threshold value for channel 3 */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* Low threshold value for channel 3 */
      } B;
   } ADC_STAW3R_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 4 */
      vuint32_t R;
      struct {
         vuint32_t  AWDE:1;            /* Analog WatchDog Enable - algorithm C */
         vuint32_t  WDTE:1;            /* WatchDog Timer Enable - algorithm C */
         vuint32_t:2;
         vuint32_t  THRH:12;           /* High threshold value for channel 4 */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* Low threshold value for channel 4 */
      } B;
   } ADC_STAW4R_32B_tag;

   typedef union {   /* SELF TEST ANALOG WATCHDOG REGISTER 5 */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  THRH:12;           /* High threshold value for algorithm C */
         vuint32_t:4;
         vuint32_t  THRL:12;           /* Low threshold value for algorithm C */
      } B;
   } ADC_STAW5R_32B_tag;



   typedef struct ADC_struct_tag { /* start of ADC_tag */
	  /* module configuration register */
      ADC_MCR_32B_tag MCR;                 /* offset: 0x0000 size: 32 bit */
	  /* module status register */
      ADC_MSR_32B_tag MSR;                 /* offset: 0x0004 size: 32 bit */
      int8_t ADC_reserved_0008[8];
	  /* Interrupt status register */
      ADC_ISR_32B_tag ISR;                 /* offset: 0x0010 size: 32 bit */

	  ADC_CEOCFR0_32B_tag CEOCFR[3];       /* offset: 0x0014  (0x0004 x 3) */

	  /* interrupt mask register */
      ADC_IMR_32B_tag IMR;                 /* offset: 0x0020 size: 32 bit */

	  ADC_CIMR0_32B_tag CIMR[3];           /* offset: 0x0024  (0x0004 x 3) */

	  /* Watchdog Threshold interrupt status register */
      ADC_WTISR_32B_tag WTISR;             /* offset: 0x0030 size: 32 bit */
	  /* Watchdog interrupt MASK register */
      ADC_WTIMR_32B_tag WTIMR;             /* offset: 0x0034 size: 32 bit */
      int8_t ADC_reserved_0038[8];
	  /* DMAE register */
      ADC_DMAE_32B_tag DMAE;               /* offset: 0x0040 size: 32 bit */

	  ADC_DMAR0_32B_tag DMAR[3];           /* offset: 0x0044  (0x0004 x 3) */

	  /* Threshold Control register C */
	  ADC_TRC_32B_tag TRC[4];              /* offset: 0x0050  (0x0004 x 4) */

	  /* Upper Threshold register */
	  ADC_THRHLR_32B_tag THRHLR[4];        /* offset: 0x0060  (0x0004 x 4) */

	  /* alternate Upper Threshold register */
	  ADC_THRALT_32B_tag THRALT[4];        /* offset: 0x0070  (0x0004 x 4) */

	  /* PRESAMPLING CONTROL REGISTER */
      ADC_PSCR_32B_tag PSCR;               /* offset: 0x0080 size: 32 bit */
    
	  ADC_PSR0_32B_tag PSR[3];             /* offset: 0x0084  (0x0004 x 3) */

      int8_t ADC_reserved_0090_C[4];

	  /* conversion timing register */
	  ADC_CTR_32B_tag CTR[3];           /* offset: 0x0094  (0x0004 x 3) */

      int8_t ADC_reserved_00A0_C[4];

	  ADC_NCMR0_32B_tag NCMR[3];        /* offset: 0x00A4  (0x0004 x 3) */

      int8_t ADC_reserved_00B0_C[4];

	  ADC_JCMR0_32B_tag JCMR[3];        /* offset: 0x00B4  (0x0004 x 3) */
      /* Offset Word Regsiter */
      ADC_OFFWR_32B_tag OFFWR;             /* offset: 0x00C0 size: 32 bit */
      /* Decode Signal Delay Register */
      ADC_DSDR_32B_tag DSDR;               /* offset: 0x00C4 size: 32 bit */
      /* Power Down Dealy Register */
      ADC_PDEDR_32B_tag PDEDR;             /* offset: 0x00C8 size: 32 bit */
      int8_t ADC_reserved_00CC_C[52];

	  /* CHANNEL DATA REGS */
	  ADC_CDR_32B_tag CDR[96];          /* offset: 0x0100  (0x0004 x 96) */

	  /* Upper Threshold register 4 is not contiguous to 3 */
      ADC_THRHLR4_32B_tag THRHLR4;         /* offset: 0x0280 size: 32 bit */
                                           /* Upper Threshold register 5 */
      ADC_THRHLR5_32B_tag THRHLR5;         /* offset: 0x0284 size: 32 bit */
                                           /* Upper Threshold register 6 */
      ADC_THRHLR6_32B_tag THRHLR6;         /* offset: 0x0288 size: 32 bit */
                                           /* Upper Threshold register 7 */
      ADC_THRHLR7_32B_tag THRHLR7;         /* offset: 0x028C size: 32 bit */
                                           /* Upper Threshold register 8 */
      ADC_THRHLR8_32B_tag THRHLR8;         /* offset: 0x0290 size: 32 bit */
                                           /* Upper Threshold register 9 */
      ADC_THRHLR9_32B_tag THRHLR9;         /* offset: 0x0294 size: 32 bit */
                                           /* Upper Threshold register 10 */
      ADC_THRHLR10_32B_tag THRHLR10;       /* offset: 0x0298 size: 32 bit */
                                           /* Upper Threshold register 11 */
      ADC_THRHLR11_32B_tag THRHLR11;       /* offset: 0x029C size: 32 bit */
                                           /* Upper Threshold register 12 */
      ADC_THRHLR12_32B_tag THRHLR12;       /* offset: 0x02A0 size: 32 bit */
                                           /* Upper Threshold register 13 */
      ADC_THRHLR13_32B_tag THRHLR13;       /* offset: 0x02A4 size: 32 bit */
                                           /* Upper Threshold register 14 */
      ADC_THRHLR14_32B_tag THRHLR14;       /* offset: 0x02A8 size: 32 bit */
                                           /* Upper Threshold register 15 */
      ADC_THRHLR15_32B_tag THRHLR15;       /* offset: 0x02AC size: 32 bit */

	  /* Channel Watchdog Select register */
	  ADC_CWSELR_32B_tag CWSELR[12];       /* offset: 0x02B0  (0x0004 x 12) */

	  /* Channel Watchdog Enable Register */
	  ADC_CWENR_32B_tag CWENR[3];          /* offset: 0x02E0  (0x0004 x 3) */

      int8_t ADC_reserved_02EC_C[4];

	  /* Analog Watchdog Out of Range Register */
	  ADC_AWORR_32B_tag AWORR[3];          /* offset: 0x02F0  (0x0004 x 3) */

      int8_t ADC_reserved_02FC[68];
	  /* SELF TEST CONFIGURATION REGISTER 1 */
      ADC_STCR1_32B_tag STCR1;             /* offset: 0x0340 size: 32 bit */
	  /* SELF TEST CONFIGURATION REGISTER 2 */
      ADC_STCR2_32B_tag STCR2;             /* offset: 0x0344 size: 32 bit */
	  /* SELF TEST CONFIGURATION REGISTER 3 */
      ADC_STCR3_32B_tag STCR3;             /* offset: 0x0348 size: 32 bit */
	  /* SELF TEST BAUD RATE REGISTER */
      ADC_STBRR_32B_tag STBRR;             /* offset: 0x034C size: 32 bit */
	  /* SELF TEST STATUS REGISTER 1 */
      ADC_STSR1_32B_tag STSR1;             /* offset: 0x0350 size: 32 bit */
	  /* SELF TEST STATUS REGISTER 2 */
      ADC_STSR2_32B_tag STSR2;             /* offset: 0x0354 size: 32 bit */
	  /* SELF TEST STATUS REGISTER 3 */
      ADC_STSR3_32B_tag STSR3;             /* offset: 0x0358 size: 32 bit */
	  /* SELF TEST STATUS REGISTER 4 */
      ADC_STSR4_32B_tag STSR4;             /* offset: 0x035C size: 32 bit */
      int8_t ADC_reserved_0360[16];
	  /* SELF TEST DATA REGISTER 1 */
      ADC_STDR1_32B_tag STDR1;             /* offset: 0x0370 size: 32 bit */
	  /* SELF TEST DATA REGISTER 2 */
      ADC_STDR2_32B_tag STDR2;             /* offset: 0x0374 size: 32 bit */
      int8_t ADC_reserved_0378[8];
	  /* SELF TEST ANALOG WATCHDOG REGISTER 0 */
      ADC_STAW0R_32B_tag STAW0R;           /* offset: 0x0380 size: 32 bit */
	  /* SELF TEST ANALOG WATCHDOG REGISTER 1A */
      ADC_STAW1AR_32B_tag STAW1AR;         /* offset: 0x0384 size: 32 bit */
	  /* SELF TEST ANALOG WATCHDOG REGISTER 1B */
      ADC_STAW1BR_32B_tag STAW1BR;         /* offset: 0x0388 size: 32 bit */
	  /* SELF TEST ANALOG WATCHDOG REGISTER 2 */
      ADC_STAW2R_32B_tag STAW2R;           /* offset: 0x038C size: 32 bit */
	  /* SELF TEST ANALOG WATCHDOG REGISTER 3 */
      ADC_STAW3R_32B_tag STAW3R;           /* offset: 0x0390 size: 32 bit */
	  /* SELF TEST ANALOG WATCHDOG REGISTER 4 */
      ADC_STAW4R_32B_tag STAW4R;           /* offset: 0x0394 size: 32 bit */
	  /* SELF TEST ANALOG WATCHDOG REGISTER 5 */
      ADC_STAW5R_32B_tag STAW5R;           /* offset: 0x0398 size: 32 bit */
   } ADC_tag;



/****************************************************************/
/*                                                              */
/* Module: CTU  */
/*                                                              */
/****************************************************************/

   typedef union {   /* Trigger Generator Subunit Input Selection register */
      vuint32_t R;
      struct {
         vuint32_t  I15_FE:1;          /* ext_signal Falling Edge */
         vuint32_t  I15_RE:1;          /* ext_signal Rising  Edge */
         vuint32_t  I14_FE:1;          /* eTimer2 Falling Edge Enable */
         vuint32_t  I14_RE:1;          /* eTimer2 Rising  Edge Enable */
         vuint32_t  I13_FE:1;          /* eTimer1 Falling Edge Enable */
         vuint32_t  I13_RE:1;          /* eTimer1 Rising  Edge Enable */
         vuint32_t  I12_FE:1;          /* RPWM ch3 Falling Edge Enable */
         vuint32_t  I12_RE:1;          /* RPWM ch3 Rising  Edge Enable */
         vuint32_t  I11_FE:1;          /* RPWM ch2 Falling Edge Enable */
         vuint32_t  I11_RE:1;          /* RPWM ch2 Rising  Edge Enable */
         vuint32_t  I10_FE:1;          /* RPWM ch1 Falling Edge Enable */
         vuint32_t  I10_RE:1;          /* RPWM ch1 Rising  Edge Enable */
         vuint32_t  I9_FE:1;           /* RPWM ch0 Falling Edge Enable */
         vuint32_t  I9_RE:1;           /* RPWM ch0 Rising  Edge Enable */
         vuint32_t  I8_FE:1;           /* PWM ch3 even trig Falling edge Enable */
         vuint32_t  I8_RE:1;           /* PWM ch3 even trig Rising  edge Enable */
         vuint32_t  I7_FE:1;           /* PWM ch2 even trig Falling edge Enable */
         vuint32_t  I7_RE:1;           /* PWM ch2 even trig Rising  edge Enable */
         vuint32_t  I6_FE:1;           /* PWM ch1 even trig Falling edge Enable */
         vuint32_t  I6_RE:1;           /* PWM ch1 even trig Rising  edge Enable */
         vuint32_t  I5_FE:1;           /* PWM ch0 even trig Falling edge Enable */
         vuint32_t  I5_RE:1;           /* PWM ch0 even trig Rising edge Enable */
         vuint32_t  I4_FE:1;           /* PWM ch3 odd trig Falling edge Enable */
         vuint32_t  I4_RE:1;           /* PWM ch3 odd trig Rising  edge Enable */
         vuint32_t  I3_FE:1;           /* PWM ch2 odd trig Falling edge Enable */
         vuint32_t  I3_RE:1;           /* PWM ch2 odd trig Rising  edge Enable */
         vuint32_t  I2_FE:1;           /* PWM ch1 odd trig Falling edge Enable */
         vuint32_t  I2_RE:1;           /* PWM ch1 odd trig Rising  edge Enable */
         vuint32_t  I1_FE:1;           /* PWM ch0 odd trig Falling edge Enable */
         vuint32_t  I1_RE:1;           /* PWM ch0 odd trig Rising  edge Enable */
         vuint32_t  I0_FE:1;           /* PWM Reload Falling Edge Enable */
         vuint32_t  I0_RE:1;           /* PWM Reload Rising  Edge Enable */
      } B;
   } CTU_TGSISR_32B_tag;

   typedef union {   /* Trigger Generator Subunit Control Register */
      vuint16_t R;
      struct {
         vuint16_t:7;
         vuint16_t  ETTM:1;            /* Toggle Mode Enable */
         vuint16_t  PRES:2;            /* TGS Prescaler Selection */
         vuint16_t  MRSSM:5;           /* MRS Selection in Sequential Mode */
         vuint16_t  TGSM:1;            /* Trigger Generator Subunit Mode */
      } B;
   } CTU_TGSCR_16B_tag;

   typedef union {   /*  */
      vuint16_t R;
	  struct {
		  vuint16_t TCRV:16;
	  } B;
   } CTU_TCR_16B_tag;

   typedef union {   /* TGS Counter Compare Register */
      vuint16_t R;
      struct {
         vuint16_t  TGSCCV:16;         
      } B;
   } CTU_TGSCCR_16B_tag;

   typedef union {   /* TGS Counter Reload Register */
      vuint16_t R;
      struct {
         vuint16_t  TGSCRV:16;         
      } B;
   } CTU_TGSCRR_16B_tag;

   typedef union {   /* Commands List Control Register 1 */
      vuint32_t R;
      struct {
         vuint32_t:3;
         vuint32_t  T3INDEX:5;         /* Trigger 3 First Command address */
         vuint32_t:3;
         vuint32_t  T2INDEX:5;         /* Trigger 2 First Command address */
         vuint32_t:3;
         vuint32_t  T1INDEX:5;         /* Trigger 1 First Command address */
         vuint32_t:3;
         vuint32_t  T0INDEX:5;         /* Trigger 0 First Command address */
      } B;
   } CTU_CLCR1_32B_tag;

   typedef union {   /* Commands List Control Register 2 */
      vuint32_t R;
      struct {
         vuint32_t:3;
         vuint32_t  T7INDEX:5;         /* Trigger 7 First Command address */
         vuint32_t:3;
         vuint32_t  T6INDEX:5;         /* Trigger 6 First Command address */
         vuint32_t:3;
         vuint32_t  T5INDEX:5;         /* Trigger 5 First Command address */
         vuint32_t:3;
         vuint32_t  T4INDEX:5;         /* Trigger 4 First Command address */
      } B;
   } CTU_CLCR2_32B_tag;

   typedef union {   /* Trigger Handler Control Register 1 */
      vuint32_t R;
      struct {
         vuint32_t:1;
         vuint32_t  T3E:1;            /* Trigger 3 enable */
         vuint32_t  T3ETE:1;          /* Trigger 3 Ext Trigger output enable */
         vuint32_t  T3T3E:1;          /* Trigger 3 Timer3 output enable */
         vuint32_t  T3T2E:1;          /* Trigger 3 Timer2 output enable */
         vuint32_t  T3T1E:1;          /* Trigger 3 Timer1 output enable */
         vuint32_t  T3T0E:1;          /* Trigger 3 Timer0 output enable */
         vuint32_t  T3ADCE:1;         /* Trigger 3 ADC Command output enable */
         vuint32_t:1;
         vuint32_t  T2E:1;            /* Trigger 2 enable */
         vuint32_t  T2ETE:1;          /* Trigger 2 Ext Trigger output enable */
         vuint32_t  T2T3E:1;          /* Trigger 2 Timer3 output enable */
         vuint32_t  T2T2E:1;          /* Trigger 2 Timer2 output enable */
         vuint32_t  T2T1E:1;          /* Trigger 2 Timer1 output enable */
         vuint32_t  T2T0E:1;          /* Trigger 2 Timer0 output enable */		 
         vuint32_t  T2ADCE:1;         /* Trigger 2 ADC Command output enable */
         vuint32_t:1;
         vuint32_t  T1E:1;            /* Trigger 1 enable */
         vuint32_t  T1ETE:1;          /* Trigger 1 Ext Trigger output enable */
         vuint32_t  T1T3E:1;          /* Trigger 1 Timer3 output enable */
         vuint32_t  T1T2E:1;          /* Trigger 1 Timer2 output enable */
         vuint32_t  T1T1E:1;          /* Trigger 1 Timer1 output enable */
         vuint32_t  T1T0E:1;          /* Trigger 1 Timer0 output enable */
		 vuint32_t  T1ADCE:1;         /* Trigger 1 ADC Command output enable */
         vuint32_t:1;
         vuint32_t  T0E:1;            /* Trigger 0 enable */
         vuint32_t  T0ETE:1;          /* Trigger 0 Ext Trigger output enable */
         vuint32_t  T0T3E:1;          /* Trigger 0 Timer3 output enable */
         vuint32_t  T0T2E:1;          /* Trigger 0 Timer2 output enable */
         vuint32_t  T0T1E:1;          /* Trigger 0 Timer1 output enable */
         vuint32_t  T0T0E:1;          /* Trigger 0 Timer0 output enable */
         vuint32_t  T0ADCE:1;         /* Trigger 0 ADC Command output enable */
      } B;
   } CTU_THCR1_32B_tag;

   typedef union {   /* Trigger Handler Control Register 2 */
      vuint32_t R;
      struct {
         vuint32_t:1;
         vuint32_t  T7E:1;            /* Trigger 7 enable */
         vuint32_t  T7ETE:1;          /* Trigger 7 Ext Trigger output enable */
         vuint32_t  T7T3E:1;          /* Trigger 7 Timer3 output enable */
         vuint32_t  T7T2E:1;          /* Trigger 7 Timer2 output enable */
         vuint32_t  T7T1E:1;          /* Trigger 7 Timer1 output enable */
         vuint32_t  T7T0E:1;          /* Trigger 7 Timer0 output enable */
		 vuint32_t  T7ADCE:1;         /* Trigger 7 ADC Command output enable */
         vuint32_t:1;
         vuint32_t  T6E:1;            /* Trigger 6 enable */
         vuint32_t  T6ETE:1;          /* Trigger 6 Ext Trigger output enable */
         vuint32_t  T6T3E:1;          /* Trigger 6 Timer3 output enable */
         vuint32_t  T6T2E:1;          /* Trigger 6 Timer2 output enable */
         vuint32_t  T6T1E:1;          /* Trigger 6 Timer1 output enable */
         vuint32_t  T6T0E:1;          /* Trigger 6 Timer0 output enable */
		 vuint32_t  T6ADCE:1;         /* Trigger 6 ADC Command output enable */
         vuint32_t:1;
         vuint32_t  T5E:1;            /* Trigger 5 enable */
         vuint32_t  T5ETE:1;          /* Trigger 5 Ext Trigger output enable */
         vuint32_t  T5T3E:1;          /* Trigger 5 Timer3 output enable */
         vuint32_t  T5T2E:1;          /* Trigger 5 Timer2 output enable */
         vuint32_t  T5T1E:1;          /* Trigger 5 Timer1 output enable */
         vuint32_t  T5T0E:1;          /* Trigger 5 Timer0 output enable */
		 vuint32_t  T5ADCE:1;         /* Trigger 5 ADC Command output enable */
         vuint32_t:1;
         vuint32_t  T4E:1;            /* Trigger 4 enable */
         vuint32_t  T4ETE:1;          /* Trigger 4 Ext Trigger output enable */
         vuint32_t  T4T3E:1;          /* Trigger 4 Timer3 output enable */
         vuint32_t  T4T2E:1;          /* Trigger 4 Timer2 output enable */
         vuint32_t  T4T1E:1;          /* Trigger 4 Timer1 output enable */
         vuint32_t  T4T0E:1;          /* Trigger 4 Timer0 output enable */
		 vuint32_t  T4ADCE:1;         /* Trigger 4 ADC Command output enable */
      } B;
   } CTU_THCR2_32B_tag;


   /* Register layout for all registers CLR_DCM... */

   typedef union {   /* Command List Register. View: (CMS=BIT13=)ST1 = 1, (BIT9=)ST0 = DONT CARE */
      vuint16_t R;
      struct {
         vuint16_t  CIR:1;             /* Command Interrupt Request */
         vuint16_t  FC:1;              /* Last Command */
         vuint16_t  CMS:1;             /* Conversion Mode Selection */
         vuint16_t  FIFO:3;            /* FIFO for ADC A/B */
         vuint16_t:1;
         vuint16_t  CHB:4;             /* ADC unit B channel number */
         vuint16_t:1;
         vuint16_t  CHA:4;             /* ADC unit A channel number */
      } B;
   } CTU_CLR_DCM_16B_tag;


   /* Register layout for all registers CLR_SCM... */

   typedef union {   /* Command List Register. View: (CMS=BIT13=)ST1 = 0, (BIT9=)ST0 = 0 */
      vuint16_t R;
      struct {
         vuint16_t  CIR:1;             /* Command Interrupt Request */
         vuint16_t  FC:1;              /* Last Command */
         vuint16_t  CMS:1;             /* Conversion Mode Selection */
         vuint16_t  FIFO:3;            /* FIFO for ADC A/B */
         vuint16_t:4;
         vuint16_t  SU:1;              /* Selection ADC Unit */
         vuint16_t:1;
         vuint16_t  CH:4;              /* ADC unit channel number */
      } B;
   } CTU_CLR_SCM_16B_tag;


   /* Register layout for all registers CLR... */


   typedef union {   /* Control Register */
      vuint16_t R;
      struct {
         vuint16_t  EMPTY_CLR7:1;      /* Empty Clear 7 */
         vuint16_t  EMPTY_CLR6:1;      /* Empty Clear 6 */
         vuint16_t  EMPTY_CLR5:1;      /* Empty Clear 5 */
         vuint16_t  EMPTY_CLR4:1;      /* Empty Clear 4 */
         vuint16_t  EMPTY_CLR3:1;      /* Empty Clear 3 */
         vuint16_t  EMPTY_CLR2:1;      /* Empty Clear 2 */
         vuint16_t  EMPTY_CLR1:1;      /* Empty Clear 1 */
         vuint16_t  EMPTY_CLR0:1;      /* Empty Clear 0 */
         vuint16_t  DMAEN7:1;         /* Enable DMA interface for FIFO 7 */	
         vuint16_t  DMAEN6:1;         /* Enable DMA interface for FIFO 6 */	
         vuint16_t  DMAEN5:1;         /* Enable DMA interface for FIFO 5 */	
         vuint16_t  DMAEN4:1;         /* Enable DMA interface for FIFO 4 */	
         vuint16_t  DMAEN3:1;         /* Enable DMA interface for FIFO 3 */	
         vuint16_t  DMAEN2:1;         /* Enable DMA interface for FIFO 2 */	
         vuint16_t  DMAEN1:1;         /* Enable DMA interface for FIFO 1 */	
         vuint16_t  DMAEN0:1;         /* Enable DMA interface for FIFO 0 */	
      } B;
   } CTU_CR_16B_tag;

   typedef union {   /* Control Register FIFO */
      vuint32_t R;
      struct {
         vuint32_t  FIFO_OVERRUN_EN7:1;   /* FIFO 7 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN7:1;  /* FIFO 7 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN7:1;     /* FIFO 7 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN7:1;      /* FIFO 7 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN6:1;   /* FIFO 6 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN6:1;  /* FIFO 6 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN6:1;     /* FIFO 6 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN6:1;      /* FIFO 6 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN5:1;   /* FIFO 5 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN5:1;  /* FIFO 5 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN5:1;     /* FIFO 5 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN5:1;      /* FIFO 5 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN4:1;   /* FIFO 4 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN4:1;  /* FIFO 4 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN4:1;     /* FIFO 4 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN4:1;      /* FIFO 4 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN3:1;   /* FIFO 3 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN3:1;  /* FIFO 3 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN3:1;     /* FIFO 3 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN3:1;      /* FIFO 3 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN2:1;   /* FIFO 2 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN2:1;  /* FIFO 2 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN2:1;     /* FIFO 2 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN2:1;      /* FIFO 2 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN1:1;   /* FIFO 1 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN1:1;  /* FIFO 1 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN1:1;     /* FIFO 1 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN1:1;      /* FIFO 1 FULL Enable Interrupt */
         vuint32_t  FIFO_OVERRUN_EN0:1;   /* FIFO 0 OVERRUN  Enable Interrupt */
         vuint32_t  FIFO_OVERFLOW_EN0:1;  /* FIFO 0 OVERFLOW Enable Interrupt */
         vuint32_t  FIFO_EMPTY_EN0:1;     /* FIFO 0 EMPTY Enable Interrupt */
         vuint32_t  FIFO_FULL_EN0:1;      /* FIFO 0 FULL Enable Interrupt */
      } B;
   } CTU_FCR_32B_tag;

   typedef union {   /* Threshold 1 Register */
      vuint32_t R;
      struct {
         vuint32_t  THRESHOLD3:8;       /* Threshlod FIFO 3 */
         vuint32_t  THRESHOLD2:8;       /* Threshlod FIFO 2 */
         vuint32_t  THRESHOLD1:8;       /* Threshlod FIFO 1 */
         vuint32_t  THRESHOLD0:8;       /* Threshlod FIFO 0 */
      } B;
   } CTU_TH1_32B_tag;

   typedef union {   /* Threshold 2 Register */
      vuint32_t R;
      struct {
         vuint32_t  THRESHOLD7:8;       /* Threshlod FIFO 7 */
         vuint32_t  THRESHOLD6:8;       /* Threshlod FIFO 6 */
         vuint32_t  THRESHOLD5:8;       /* Threshlod FIFO 5 */
         vuint32_t  THRESHOLD4:8;       /* Threshlod FIFO 4 */
      } B;
   } CTU_TH2_32B_tag;

   typedef union {   /* Status Register */
      vuint32_t R;
      struct {
         vuint32_t  FIFO_OVERRUN7:1;   /* FIFO 7 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW7:1;  /* FIFO 7 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY7:1;     /* FIFO 7 EMPTY Flag */
         vuint32_t  FIFO_FULL7:1;      /* FIFO 7 FULL Flag */
         vuint32_t  FIFO_OVERRUN6:1;   /* FIFO 6 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW6:1;  /* FIFO 6 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY6:1;     /* FIFO 6 EMPTY Flag */
         vuint32_t  FIFO_FULL6:1;      /* FIFO 6 FULL Flag */
         vuint32_t  FIFO_OVERRUN5:1;   /* FIFO 5 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW5:1;  /* FIFO 5 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY5:1;     /* FIFO 5 EMPTY Flag */
         vuint32_t  FIFO_FULL5:1;      /* FIFO 5 FULL Flag */
         vuint32_t  FIFO_OVERRUN4:1;   /* FIFO 4 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW4:1;  /* FIFO 4 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY4:1;     /* FIFO 4 EMPTY Flag */
         vuint32_t  FIFO_FULL4:1;      /* FIFO 4 FULL Flag */
         vuint32_t  FIFO_OVERRUN3:1;   /* FIFO 3 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW3:1;  /* FIFO 3 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY3:1;     /* FIFO 3 EMPTY Flag */
         vuint32_t  FIFO_FULL3:1;      /* FIFO 3 FULL Flag */
         vuint32_t  FIFO_OVERRUN2:1;   /* FIFO 2 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW2:1;  /* FIFO 2 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY2:1;     /* FIFO 2 EMPTY Flag */
         vuint32_t  FIFO_FULL2:1;      /* FIFO 2 FULL Flag */
         vuint32_t  FIFO_OVERRUN1:1;   /* FIFO 1 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW1:1;  /* FIFO 1 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY1:1;     /* FIFO 1 EMPTY Flag */
         vuint32_t  FIFO_FULL1:1;      /* FIFO 1 FULL Flag */
         vuint32_t  FIFO_OVERRUN0:1;   /* FIFO 0 OVERRUN  Flag */
         vuint32_t  FIFO_OVERFLOW0:1;  /* FIFO 0 OVERFLOW Flag */
         vuint32_t  FIFO_EMPTY0:1;     /* FIFO 0 EMPTY Flag */
         vuint32_t  FIFO_FULL0:1;      /* FIFO 0 FULL Flag */
      } B;
   } CTU_STS_32B_tag;


   /* Register layout for all registers FR... */

   typedef union {   /* FIFO Right Aligned register */
      vuint32_t R;
      struct {
         vuint32_t:11;
		 vuint32_t NCH:5;
//         vuint32_t  ADC:1;             /* ADC Unit */
//         vuint32_t  N_CH:4;            /* Number Channel */
         vuint32_t:4;
         vuint32_t  DATA:12;           /* Data Fifo */
      } B;
   } CTU_FR_32B_tag;


   /* Register layout for all registers FL... */

   typedef union {   /* FIFO Left Aligned register */
      vuint32_t R;
      struct {
         vuint32_t:11;
		 vuint32_t NCH:5;
/*         vuint32_t  ADC:1; */            /* ADC Unit */
/*         vuint32_t  N_CH:4;  */          /* Number Channel */
         vuint32_t:1;
         vuint32_t  DATA:12;           /* Data Fifo */
         vuint32_t:3;
      } B;
   } CTU_FL_32B_tag;

   typedef union {   /* CTU Error Flag Register */
      vuint16_t R;
      struct {
         vuint16_t:3;
         vuint16_t  CS:1;             /* Counter Status */
         vuint16_t  ET_E:1;           /* ExtTrigger Generation Overrun */
         vuint16_t  ERR_CMP:1;        /* Set if counter reaches TGSCCR register */
         vuint16_t  T3OE:1;           /* Timer4 Generation Overrun */
         vuint16_t  T2OE:1;           /* Timer3 Generation Overrun */
         vuint16_t  T1OE:1;           /* Timer2 Generation Overrun */
         vuint16_t  T0OE:1;           /* Timer1 Generation Overrun */
         vuint16_t  ADCOE:1;          /* ADC Command Generation Overrun */
         vuint16_t  TGSOSM:1;         /* TGS Overrun */
         vuint16_t  MRSO:1;           /* TGS Overrun */
         vuint16_t  ICE:1;            /* Invalid Command Error */
         vuint16_t  SMTO:1;           /* Trigger Overrun */
         vuint16_t  MRSRE:1;          /* MRS Reload Error */

      } B;
   } CTU_CTUEFR_16B_tag;

   typedef union {   /* CTU Interrupt Flag Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  S_E_B:1;           /* Slice time OK */
         vuint16_t  S_E_A:1;           /* Slice time OK */
         vuint16_t  ADC:1;        
         vuint16_t  T7:1;        
         vuint16_t  T6:1;        
         vuint16_t  T5:1;        
         vuint16_t  T4:1;        
         vuint16_t  T3:1;        
         vuint16_t  T2:1;        
         vuint16_t  T1:1;        
         vuint16_t  T0:1;        
         vuint16_t  MRS:1;        
      } B;
   } CTU_CTUIFR_16B_tag;

   typedef union {   /* CTU Interrupt/DMA Register */
      vuint16_t R;
      struct {       
         vuint16_t  T7IE:1;        
         vuint16_t  T6IE:1;        
         vuint16_t  T5IE:1;        
         vuint16_t  T4IE:1;        
         vuint16_t  T3IE:1;        
         vuint16_t  T2IE:1;        
         vuint16_t  T1IE:1;        
         vuint16_t  T0IE:1;        
         vuint16_t:2;
         vuint16_t  SAF_CNT_B_EN:1;    /* Conversion time counter enabled */
         vuint16_t  SAF_CNT_A_EN:1;    /* Conversion time counter enabled */
         vuint16_t  DMA_DE:1;          /* DMA and gre bit */
         vuint16_t  MRSDMAE:1;        
         vuint16_t  MRSIE:1;        
         vuint16_t  IEE:1;             /* Interrupt Error Enable */
      } B;
   } CTU_CTUIR_16B_tag;

   typedef union {   /* Control On-Time Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  COTR:8;        
      } B;
   } CTU_COTR_16B_tag;

   typedef union {   /* CTU Control Register */
      vuint16_t R;
      struct {
         vuint16_t  T7SG:1;        
         vuint16_t  T6SG:1;        
         vuint16_t  T5SG:1;        
         vuint16_t  T4SG:1;        
         vuint16_t  T3SG:1;        
         vuint16_t  T2SG:1;        
         vuint16_t  T1SG:1;        
         vuint16_t  T0SG:1;        
         vuint16_t  CTUADCRESET:1;        
         vuint16_t  CTUODIS:1;        
         vuint16_t  FILTERENABLE:1;        
         vuint16_t  CGRE:1;            /* Clear GRE */
         vuint16_t  FGRE:1;            /* GRE Flag */
         vuint16_t  MRSSG:1;        
         vuint16_t  GRE:1;             /* General Reload Enable */
         vuint16_t  TGSISRRE:1;        
      } B;
   } CTU_CTUCR_16B_tag;

   typedef union {   /* CTU Digital Filter Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  FILTERVALUE:8;       /* deprecated name - please avoid */
      } B;
   } CTU_FILTER_16B_tag;

   typedef union {   /* CTU Expected A Value Register */
      vuint16_t R;
      struct {
         vuint16_t  EXPECTED_A_VALUE:16;   /* Expected A Value */
      } B;
   } CTU_EXPECTED_A_16B_tag;

   typedef union {   /* CTU Expected B Value Register */
      vuint16_t R;
      struct {
         vuint16_t  EXPECTED_B_VALUE:16;   /* Expected B Value */
      } B;
   } CTU_EXPECTED_B_16B_tag;

   typedef union {   /* CTU Counter Range Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  CNT_RANGE_VALUE:8;   /* Counter Range Value */
      } B;
   } CTU_CNT_RANGE_16B_tag;


   /* Register layout for generated register(s) FRA... */

   typedef union {   /*  */
      vuint32_t R;
   } CTU_FRA_32B_tag;


   /* Register layout for generated register(s) FLA... */

   typedef union {   /*  */
      vuint32_t R;
   } CTU_FLA_32B_tag;



   typedef struct CTU_struct_tag { /* start of CTU_tag */
	   /* Trigger Generator Subunit Input Selection register */
	   CTU_TGSISR_32B_tag TGSISR;           /* offset: 0x0000 size: 32 bit */
	   /* Trigger Generator Subunit Control Register */
	   CTU_TGSCR_16B_tag TGSCR;             /* offset: 0x0004 size: 16 bit */

	   CTU_TCR_16B_tag TCR[8];              /* offset: 0x0006  (0x0002 x 8) */
	   /* TGS Counter Compare Register */
	   CTU_TGSCCR_16B_tag TGSCCR;           /* offset: 0x0016 size: 16 bit */
	   /* TGS Counter Reload Register */
	   CTU_TGSCRR_16B_tag TGSCRR;           /* offset: 0x0018 size: 16 bit */
	   int8_t CTU_reserved_001A[2];
	   /* Commands List Control Register 1 */
	   CTU_CLCR1_32B_tag CLCR1;             /* offset: 0x001C size: 32 bit */
	   /* Commands List Control Register 2 */
	   CTU_CLCR2_32B_tag CLCR2;             /* offset: 0x0020 size: 32 bit */
	   /* Trigger Handler Control Register 1 */
	   CTU_THCR1_32B_tag THCR1;             /* offset: 0x0024 size: 32 bit */
	   /* Trigger Handler Control Register 2 */
	   CTU_THCR2_32B_tag THCR2;             /* offset: 0x0028 size: 32 bit */

	   /* Command List Register */ 
	   /* offset: 0x002C  (0x0002 x 24) */ 
	   CTU_CLR_SCM_16B_tag CLR[24];         /* Single COMMAND */    
       /*  CTU_CLR_DCM_16B_tag CLR[24];*/  /* Dual COMMAND */ 


	   int8_t CTU_reserved_005C[16];
	   /* Control Register */
	   CTU_CR_16B_tag CR;                   /* offset: 0x006C size: 16 bit */
	   int8_t CTU_reserved_006E[2];
	   /* Control Register FIFO */
	   CTU_FCR_32B_tag FCR;                 /* offset: 0x0070 size: 32 bit */
	   /* Threshold 1 Register */
	   CTU_TH1_32B_tag TH1;                 /* offset: 0x0074 size: 32 bit */
	   /* Threshold 2 Register */
	   CTU_TH2_32B_tag TH2;                 /* offset: 0x0078 size: 32 bit */

	   /* Status Register */
	   CTU_STS_32B_tag STATUS;              /* offset: 0x007C size: 32 bit */

	   CTU_FRA_32B_tag FRA[8];              /* offset: 0x0080  (0x0004 x 8) */

	   CTU_FLA_32B_tag FLA[8];              /* offset: 0x00A0  (0x0004 x 8) */
	   /* CTU Error Flag Register */
	   CTU_CTUEFR_16B_tag CTUEFR;           /* offset: 0x00C0 size: 16 bit */
	   /* CTU Interrupt Flag Register */
	   CTU_CTUIFR_16B_tag CTUIFR;           /* offset: 0x00C2 size: 16 bit */
	   /* CTU Interrupt/DMA Register */
	   CTU_CTUIR_16B_tag CTUIR;             /* offset: 0x00C4 size: 16 bit */
	   /* Control On-Time Register */
	   CTU_COTR_16B_tag COTR;               /* offset: 0x00C6 size: 16 bit */
	   /* CTU Control Register */
	   CTU_CTUCR_16B_tag CTUCR;             /* offset: 0x00C8 size: 16 bit */

	   /* CTU Digital Filter Register */
	   CTU_FILTER_16B_tag CTUFILTER;        /* offset: 0x00CA size: 16 bit */

	   /* CTU Expected A Value Register */
	   CTU_EXPECTED_A_16B_tag EXPECTED_A;   /* offset: 0x00CC size: 16 bit */

	   /* CTU Expected B Value Register */
	   CTU_EXPECTED_B_16B_tag EXPECTED_B;   /* offset: 0x00CE size: 16 bit */
	   /* CTU Counter Range Register */
	   CTU_CNT_RANGE_16B_tag CNT_RANGE;     /* offset: 0x00D0 size: 16 bit */
   } CTU_tag;

   
/****************************************************************/
/*                                                              */
/* Module: ETIMER  */
/*                                                              */
/****************************************************************/
   /* Register layout for all registers COMP1... */

   typedef union {   /* Compare Register 1 */
      vuint16_t R;
      struct {
      vuint16_t COMP1:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_COMP1_16B_tag;


   /* Register layout for all registers COMP2... */

   typedef union {   /* Compare Register 2 */
      vuint16_t R;
      struct {
      vuint16_t COMP2:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_COMP2_16B_tag;


   /* Register layout for all registers CAPT1... */

   typedef union {   /* Capture Register 1 */
      vuint16_t R;
      struct {
      vuint16_t CAPT1:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_CAPT1_16B_tag;


   /* Register layout for all registers CAPT2... */

   typedef union {   /* Capture Register 2 */
      vuint16_t R;
      struct {
      vuint16_t CAPT2:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_CAPT2_16B_tag;


   /* Register layout for all registers LOAD... */

   typedef union {   /* Load Register */
      vuint16_t R;
      struct {
       vuint16_t LOAD:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_LOAD_16B_tag;


   /* Register layout for all registers HOLD... */

   typedef union {   /* Hold Register */
      vuint16_t R;
      struct {
       vuint16_t HOLD:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_HOLD_16B_tag;


   /* Register layout for all registers CNTR... */

   typedef union {   /* Counter Register */
      vuint16_t R;
      struct {
       vuint16_t CNTR:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_CNTR_16B_tag;


   /* Register layout for all registers CTRL1... */

   typedef union {   /* Control Register */
      vuint16_t R;
      struct {
         vuint16_t  CNTMODE:3;         /* Count Mode */
         vuint16_t  PRISRC:5;          /* Primary Count Source */
         vuint16_t  ONCE:1;            /* Count Once */
         vuint16_t  LENGTH:1;          /* Count Length */
         vuint16_t  DIR:1;             /* Count Direction */
         vuint16_t  SECSRC:5;          /* Secondary Count Source */
      } B;
   } mcTIMER_CTRL1_16B_tag;


   /* Register layout for all registers CTRL2... */

   typedef union {   /* Control Register 2 */
      vuint16_t R;
      struct {
         vuint16_t  OEN:1;             /* Output Enable */
         vuint16_t  RDNT:1;            /* Redundant Channel Enable */
         vuint16_t  INPUT:1;           /* External Input Signal */
         vuint16_t  VAL:1;             /* Forced OFLAG Value */
         vuint16_t  FORCE:1;           /* Force the OFLAG output */
         vuint16_t  COFRC:1;           /* Co-channel OFLAG Force */
         vuint16_t  COINIT:2;          /* Co-channel Initialization */
         vuint16_t  SIPS:1;            /* Secondary Source Input Polarity Select */
         vuint16_t  PIPS:1;            /* Primary Source Input Polarity Select */
         vuint16_t  OPS:1;             /* Output Polarity Select */
         vuint16_t  MSTR:1;            /* Master Mode */
         vuint16_t  OUTMODE:4;         /* Output Mode */
      } B;
   } mcTIMER_CTRL2_16B_tag;


   /* Register layout for all registers CTRL3... */

   typedef union {   /* Control Register 3 */
      vuint16_t R;
      struct {
         vuint16_t  STPEN:1;           /* Stop Action Enable */
         vuint16_t  ROC:2;             /* Reload On Capture */
         vuint16_t  FMODE:1;           /* Fault Safing Mode */
         vuint16_t  FDIS:4;            /* Fault Disable Mask */
         vuint16_t  C2FCNT:3;          /* CAPT2 FIFO Word Count */
         vuint16_t  C1FCNT:3;          /* CAPT1 FIFO Word Count */
         vuint16_t  DBGEN:2;           /* Debug Actions Enable */
      } B;
   } mcTIMER_CTRL3_16B_tag;


   /* Register layout for all registers STS... */

   typedef union {   /* Status Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  WDF:1;             /* Watchdog Time-out Flag */
         vuint16_t  RCF:1;             /* Redundant Channel Flag */
         vuint16_t  ICF2:1;            /* Input Capture 2 Flag */
         vuint16_t  ICF1:1;            /* Input Capture 1 Flag */
         vuint16_t  IEHF:1;            /* Input Edge High Flag */
         vuint16_t  IELF:1;            /* Input Edge Low Flag */
         vuint16_t  TOF:1;             /* Timer Overflow Flag */
         vuint16_t  TCF2:1;            /* Timer Compare 2 Flag */
         vuint16_t  TCF1:1;            /* Timer Compare 1 Flag */
         vuint16_t  TCF:1;             /* Timer Compare Flag */
      } B;
   } mcTIMER_STS_16B_tag;


   /* Register layout for all registers INTDMA... */

   typedef union {   /* Interrupt and DMA Enable Register */
      vuint16_t R;
      struct {
         vuint16_t  ICF2DE:1;          /* Input Capture 2 Flag DMA Enable */
         vuint16_t  ICF1DE:1;          /* Input Capture 1 Flag DMA Enable */
         vuint16_t  CMPLD2DE:1;        /* Comparator Load Register 2 Flag DMA Enable */
         vuint16_t  CMPLD1DE:1;        /* Comparator Load Register 1 Flag DMA Enable */
         vuint16_t:2;
         vuint16_t  WDFIE:1;           /* Watchdog Flag Interrupt Enable */
         vuint16_t  RCFIE:1;           /* Redundant Channel Flag Interrupt Enable */
         vuint16_t  ICF2IE:1;          /* Input Capture 2 Flag Interrupt Enable */
         vuint16_t  ICF1IE:1;          /* Input Capture 1 Flag Interrupt Enable */
         vuint16_t  IEHFIE:1;          /* Input Edge High Flag Interrupt Enable */
         vuint16_t  IELFIE:1;          /* Input Edge Low Flag Interrupt Enable */
         vuint16_t  TOFIE:1;           /* Timer Overflow Flag Interrupt Enable */
         vuint16_t  TCF2IE:1;          /* Timer Compare 2 Flag Interrupt Enable */
         vuint16_t  TCF1IE:1;          /* Timer Compare 1 Flag Interrupt Enable */
         vuint16_t  TCFIE:1;           /* Timer Compare Flag Interrupt Enable */
      } B;
   } mcTIMER_INTDMA_16B_tag;


   /* Register layout for all registers CMPLD1... */

   typedef union {   /* Comparator Load Register 1 */
      vuint16_t R;
      struct {
     vuint16_t CMPLD1:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_CMPLD1_16B_tag;


   /* Register layout for all registers CMPLD2... */

   typedef union {   /* Comparator Load Register 2 */
      vuint16_t R;
      struct {
     vuint16_t CMPLD2:16;  /* deprecated definition -- do not use */
      } B;
   } mcTIMER_CMPLD2_16B_tag;


   /* Register layout for all registers CCCTRL... */

   typedef union {   /* Compare and Capture Control Register */
      vuint16_t R;
      struct {
         vuint16_t  CLC2:3;            /* Compare Load Control 2 */
         vuint16_t  CLC1:3;            /* Compare Load Control 1 */
         vuint16_t  CMPMODE:2;         /* Compare Mode */
         vuint16_t  CPT2MODE:2;        /* Capture 2 Mode Control */
         vuint16_t  CPT1MODE:2;        /* Capture 1 Mode Control */
         vuint16_t  CFWM:2;            /* Capture FIFO Water Mark */
         vuint16_t  ONESHOT:1;         /* One Shot Capture Mode */
         vuint16_t  ARM:1;             /* Arm Capture */
      } B;
   } mcTIMER_CCCTRL_16B_tag;


   /* Register layout for all registers FILT... */

   typedef union {   /* Input Filter Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  FILTCNT:3;         /* Input Filter Sample Count */
         vuint16_t  FILTPER:8;         /* Input Filter Sample Period */
      } B;
   } mcTIMER_FILT_16B_tag;

   typedef union {   /* Watchdog Time-out Register */
      vuint16_t R;
      struct {
      vuint16_t WDTOL:16;  
      } B;
   } mcTIMER_WDTOL_16B_tag;

   typedef union {   /* Watchdog Time-out Register */
      vuint16_t R;
      struct {
      vuint16_t WDTOH:16;  
      } B;
   } mcTIMER_WDTOH_16B_tag;

   typedef union {   /* Fault Control Register */
      vuint16_t R;
      struct {
         vuint16_t:3;
         vuint16_t  FTEST:1;           /* Fault Test */
         vuint16_t  FIE:4;             /* Fault Interrupt Enable */
         vuint16_t:4;
         vuint16_t  FLVL:4;            /* Fault Active Logic Level */
      } B;
   } mcTIMER_FCTRL_16B_tag;

   typedef union {   /* Fault Status Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  FFPIN:4;           /* Filtered Fault Pin */
         vuint16_t:4;
         vuint16_t  FFLAG:4;           /* Fault Flag */
      } B;
   } mcTIMER_FSTS_16B_tag;

   typedef union {   /* Fault Filter Registers */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  FFILTCNT:3;        /* Fault Filter Sample Count */
         vuint16_t  FFILTPER:8;        /* Fault Filter Sample Period */
      } B;
   } mcTIMER_FFILT_16B_tag;

   typedef union {   /* Channel Enable Registers */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  ENBL:8;            /* Timer Channel Enable */
      } B;
   } mcTIMER_ENBL_16B_tag;


   /* Register layout for generated register(s) DREQ... */

   typedef union {   /*  */
      vuint16_t R;
	  struct {
		  vuint16_t:11;
		  vuint16_t DREQ:5;
	  } B;	  
   } mcTIMER_DREQ_16B_tag;


   typedef struct mcTIMER_CHANNEL_struct_tag {

	   /* Compare Register 1 */
      mcTIMER_COMP1_16B_tag COMP1;        /* relative offset: 0x0000 */
	  /* Compare Register 2 */
      mcTIMER_COMP2_16B_tag COMP2;        /* relative offset: 0x0002 */
	  /* Capture Register 1 */
      mcTIMER_CAPT1_16B_tag CAPT1;        /* relative offset: 0x0004 */
	  /* Capture Register 2 */
      mcTIMER_CAPT2_16B_tag CAPT2;        /* relative offset: 0x0006 */
	  /* Load Register */
      mcTIMER_LOAD_16B_tag LOAD;          /* relative offset: 0x0008 */
	  /* Hold Register */
      mcTIMER_HOLD_16B_tag HOLD;          /* relative offset: 0x000A */
	  /* Counter Register */
      mcTIMER_CNTR_16B_tag CNTR;          /* relative offset: 0x000C */

	  /* Control Register */
      mcTIMER_CTRL1_16B_tag CTRL;     /* relative offset: 0x000E */
	  /* Control Register 2 */
      mcTIMER_CTRL2_16B_tag CTRL2;        /* relative offset: 0x0010 */
	  /* Control Register 3 */
      mcTIMER_CTRL3_16B_tag CTRL3;        /* relative offset: 0x0012 */
	  /* Status Register */
      mcTIMER_STS_16B_tag STS;            /* relative offset: 0x0014 */
	  /* Interrupt and DMA Enable Register */
      mcTIMER_INTDMA_16B_tag INTDMA;      /* relative offset: 0x0016 */
	  /* Comparator Load Register 1 */
      mcTIMER_CMPLD1_16B_tag CMPLD1;      /* relative offset: 0x0018 */
	  /* Comparator Load Register 2 */
      mcTIMER_CMPLD2_16B_tag CMPLD2;      /* relative offset: 0x001A */
	  /* Compare and Capture Control Register */
      mcTIMER_CCCTRL_16B_tag CCCTRL;      /* relative offset: 0x001C */
	  /* Input Filter Register */
      mcTIMER_FILT_16B_tag FILT;          /* relative offset: 0x001E */

   } mcTIMER_CHANNEL_tag;


   typedef struct mcTIMER_struct_tag { /* start of mcTIMER_tag */

	   /*  Register set CHANNEL */
	   mcTIMER_CHANNEL_tag CHANNEL[6];   /* offset: 0x0000  (0x0020 x 6) */

	   int8_t mcTIMER_reserved_00C0[64];
	   /* Watchdog Time-out Register */
	   mcTIMER_WDTOL_16B_tag WDTOL;         /* offset: 0x0100 size: 16 bit */
	   /* Watchdog Time-out Register */
	   mcTIMER_WDTOH_16B_tag WDTOH;         /* offset: 0x0102 size: 16 bit */
	   /* Fault Control Register */
	   mcTIMER_FCTRL_16B_tag FCTRL;         /* offset: 0x0104 size: 16 bit */
	   /* Fault Status Register */
	   mcTIMER_FSTS_16B_tag FSTS;           /* offset: 0x0106 size: 16 bit */
	   /* Fault Filter Registers */
	   mcTIMER_FFILT_16B_tag FFILT;         /* offset: 0x0108 size: 16 bit */
	   int8_t mcTIMER_reserved_010A[2];
	   /* Channel Enable Registers */
	   mcTIMER_ENBL_16B_tag ENBL;           /* offset: 0x010C size: 16 bit */
	   int8_t mcTIMER_reserved_010E_C[2];

	   mcTIMER_DREQ_16B_tag DREQ[4];     /* offset: 0x0110  (0x0002 x 4) */

   } mcTIMER_tag;


/****************************************************************/
/*                                                              */
/* Module: mcPWM  */
/*                                                              */
/****************************************************************/
   /* Register layout for all registers CNT... */

   typedef union {   /* Counter Register */
      vuint16_t R;
   } mcPWM_CNT_16B_tag;


   /* Register layout for all registers INIT... */

   typedef union {   /* Initial Counter Register */
      vuint16_t R;
   } mcPWM_INIT_16B_tag;


   /* Register layout for all registers CTRL2... */

   typedef union {   /* Control 2 Register */
      vuint16_t R;
      struct {
         vuint16_t  DBGEN:1;           /* Debug Enable */
         vuint16_t  WAITEN:1;          /* Wait Enable */
         vuint16_t  INDEP:1;           /* Independent or Complementary Pair Operation */
         vuint16_t  PWMA_INIT:1;       
         vuint16_t  PWMB_INIT:1;       
         vuint16_t  PWMX_INIT:1;       /* PWMX Initial Value */
         vuint16_t  INIT_SEL:2;        /* Initialization Control Select */
         vuint16_t  FRCEN:1;           /* Force Initialization enable */
         vuint16_t  FORCE:1;           /* Force Initialization */
         vuint16_t  FORCE_SEL:3;       /* Force Source Select */
         vuint16_t  RELOAD_SEL:1;      /* Reload Source Select */
         vuint16_t  CLK_SEL:2;         /* Clock Source Select */
      } B;
   } mcPWM_CTRL2_16B_tag;


   /* Register layout for all registers CTRL1... */

   typedef union {   /* Control Register */
      vuint16_t R;
      struct {
         vuint16_t  LDFQ:4;            /* Load Frequency */
         vuint16_t  HALF:1;            /* Half Cycle Reload */
         vuint16_t  FULL:1;            /* Full Cycle Reload */
         vuint16_t  DT:2;              /* Deadtime */
         vuint16_t:1;
         vuint16_t  PRSC:3;            /* Prescaler */
         vuint16_t:1;
         vuint16_t  LDMOD:1;           /* Load Mode Select */
         vuint16_t:1;
         vuint16_t  DBLEN:1;           /* Double Switching Enable */
      } B;
   } mcPWM_CTRL1_16B_tag;

   /* Register layout for all registers VAL_0... */

   typedef union {   /* Value Register 0 */
      vuint16_t R;
   } mcPWM_VAL_0_16B_tag;


   /* Register layout for all registers FRACA... */

   typedef union {   /* Fractional Delay Register A */
      vuint16_t R;
      struct {
         vuint16_t  FRACAEN:1;        /* Fractional Delay Enable */
         vuint16_t:10;
         vuint16_t  FRACADLY:5;       /* Fractional Delay Value */
      } B;
   } mcPWM_FRACA_16B_tag;


   /* Register layout for all registers FRACB... */

   typedef union {   /* Fractional Delay Register B */
      vuint16_t R;
      struct {
         vuint16_t  FRACAEN:1;        /* Fractional Delay Enable */
         vuint16_t:10;
         vuint16_t  FRACADLY:5;       /* Fractional Delay Value */
      } B;
   } mcPWM_FRACB_16B_tag;


   /* Register layout for all registers OCTRL... */

   typedef union {   /* Output Control Register */
      vuint16_t R;
      struct {
         vuint16_t  PWMA_IN:1;         /* PWMA Input */
         vuint16_t  PWMB_IN:1;         /* PWMB Input */
         vuint16_t  PWMX_IN:1;         /* PWMX Input */
         vuint16_t:2;
         vuint16_t  POLA:1;            /* PWMA Output Polarity */
         vuint16_t  POLB:1;            /* PWMB Output Polarity */
         vuint16_t  POLX:1;            /* PWMX Output Polarity */
         vuint16_t:2;
         vuint16_t  PWMAFS:2;          /* PWMA Fault State */
         vuint16_t  PWMBFS:2;          /* PWMB Fault State */
         vuint16_t  PWMXFS:2;          /* PWMX Fault State */
      } B;
   } mcPWM_OCTRL_16B_tag;


   /* Register layout for all registers STS... */

   typedef union {   /* Status Register */
      vuint16_t R;
      struct {
         vuint16_t:1;
         vuint16_t  RUF:1;             /* Registers Updated Flag */
         vuint16_t  REF:1;             /* Reload Error Flag */
         vuint16_t  RF:1;              /* Reload Flag */
         vuint16_t  CFA1:1;            /* Capture Flag A1 */
         vuint16_t  CFA0:1;            /* Capture Flag A0 */
         vuint16_t  CFB1:1;            /* Capture Flag B1 */
         vuint16_t  CFB0:1;            /* Capture Flag B0 */
         vuint16_t  CFX1:1;            /* Capture Flag X1 */
         vuint16_t  CFX0:1;            /* Capture Flag X0 */
         vuint16_t  CMPF:6;            /* Compare Flags */
      } B;
   } mcPWM_STS_16B_tag;


   /* Register layout for all registers INTEN... */

   typedef union {   /* Interrupt Enable Registers */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  REIE:1;            /* Reload Error Interrupt Enable */
         vuint16_t  RIE:1;             /* Reload Interrupt Enable */
         vuint16_t  CA1IE:1;           /* Capture A1 Interrupt Enable */
         vuint16_t  CA0IE:1;           /* Capture A0 Interrupt Enable */
         vuint16_t  CB1IE:1;           /* Capture B1 Interrupt Enable */
         vuint16_t  CB0IE:1;           /* Capture B0 Interrupt Enable */
         vuint16_t  CX1IE:1;           /* Capture X1 Interrupt Enable */
         vuint16_t  CX0IE:1;           /* Capture X0 Interrupt Enable */
         vuint16_t  CMPIE:6;           /* Compare Interrupt Enables */
      } B;
   } mcPWM_INTEN_16B_tag;


   /* Register layout for all registers DMAEN... */

   typedef union {   /* DMA Enable Registers */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  VALDE:1;           /* Value Register DMA Enable */
         vuint16_t  FAND:1;            /* FIFO Watermark AND Control */
         vuint16_t  CAPTDE:2;          /* Capture DMA Enable Source Select */
         vuint16_t  CA1DE:1;           /* Capture A1 FIFO DMA Enable */
         vuint16_t  CA0DE:1;           /* Capture A0 FIFO DMA Enable */
         vuint16_t  CB1DE:1;           /* Capture B1 FIFO DMA Enable */
         vuint16_t  CB0DE:1;           /* Capture B0 FIFO DMA Enable */
         vuint16_t  CX1DE:1;           /* Capture X1 FIFO DMA Enable */
         vuint16_t  CX0DE:1;           /* Capture X0 FIFO DMA Enable */
      } B;
   } mcPWM_DMAEN_16B_tag;


   /* Register layout for all registers TCTRL... */

   typedef union {   /* Output Trigger Control  Registers */
      vuint16_t R;
      struct {
         vuint16_t:10;
         vuint16_t  OUT_TRIG_EN:6;     /* Output Trigger Enables */
      } B;
   } mcPWM_TCTRL_16B_tag;


   /* Register layout for all registers DISMAP... */

   typedef union {   /* Fault Disable Mapping   Registers */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  DISX:4;            /* PWMX Fault Disable Mask */
         vuint16_t  DISB:4;            /* PWMB Fault Disable Mask */
         vuint16_t  DISA:4;            /* PWMA Fault Disable Mask */
      } B;
   } mcPWM_DISMAP_16B_tag;


   /* Register layout for all registers DTCNT0... */

   typedef union {   /* Deadtime Count Register 0 */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  DTCNT0:11;         /* Deadtime Count Register 0 */
      } B;
   } mcPWM_DTCNT0_16B_tag;


   /* Register layout for all registers DTCNT1... */

   typedef union {   /* Deadtime Count Register 1 */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  DTCNT1:11;         /* Deadtime Count Register 1 */
      } B;
   } mcPWM_DTCNT1_16B_tag;


   /* Register layout for all registers CAPTCTRLA... */

   typedef union {   /* Capture Control A Register */
      vuint16_t R;
      struct {
         vuint16_t  CA1CNT:3;          /* Capture A1 FIFO Word Count */
         vuint16_t  CA0CNT:3;          /* Capture A0 FIFO Word Count */
         vuint16_t  CFAWM:2;           /* Capture A FIFOs Water Mark */
         vuint16_t  EDGCNTAEN:1;       /* Edge Counter A Enable */
         vuint16_t  INPSELA:1;         /* Input Select A */
         vuint16_t  EDGA1:2;           /* Edge A 1 */
         vuint16_t  EDGA0:2;           /* Edge A 0 */
         vuint16_t  ONESHOTA:1;        /* One Shot Mode A */
         vuint16_t  ARMA:1;            /* Arm A */
      } B;
   } mcPWM_CAPTCTRLA_16B_tag;


   /* Register layout for all registers CAPTCMPA... */

   typedef union {   /* Capture Compare A Register */
      vuint16_t R;
      struct {
         vuint16_t  EDGCNTA:8;         /* Edge Counter A */
         vuint16_t  EDGCMPA:8;         /* Edge Compare A */
      } B;
   } mcPWM_CAPTCMPA_16B_tag;


   /* Register layout for all registers CAPTCTRLB... */

   typedef union {   /* Capture Control B Register */
      vuint16_t R;
      struct {
         vuint16_t  CB1CNT:3;          /* Capture B1 FIFO Word Count */
         vuint16_t  CB0CNT:3;          /* Capture B0 FIFO Word Count */
         vuint16_t  CFBWM:2;           /* Capture B FIFOs Water Mark */
         vuint16_t  EDGCNTBEN:1;       /* Edge Counter B Enable */
         vuint16_t  INPSELB:1;         /* Input Select B */
         vuint16_t  EDGB1:2;           /* Edge B 1 */
         vuint16_t  EDGB0:2;           /* Edge B 0 */
         vuint16_t  ONESHOTB:1;        /* One Shot Mode B */
         vuint16_t  ARMB:1;            /* Arm B */
      } B;
   } mcPWM_CAPTCTRLB_16B_tag;


   /* Register layout for all registers CAPTCMPB... */

   typedef union {   /* Capture Compare B Register */
      vuint16_t R;
      struct {
         vuint16_t  EDGCNTB:8;         /* Edge Counter B */
         vuint16_t  EDGCMPB:8;         /* Edge Compare B */
      } B;
   } mcPWM_CAPTCMPB_16B_tag;


   /* Register layout for all registers CAPTCTRLX... */

   typedef union {   /* Capture Control X Register */
      vuint16_t R;
      struct {
         vuint16_t  CX1CNT:3;          /* Capture X1 FIFO Word Count */
         vuint16_t  CX0CNT:3;          /* Capture X0 FIFO Word Count */
         vuint16_t  CFXWM:2;           /* Capture X FIFOs Water Mark */
         vuint16_t  EDGCNTX_EN:1;      /* Edge Counter X Enable */
         vuint16_t  INP_SELX:1;        /* Input Select X */
         vuint16_t  EDGX1:2;           /* Edge X 1 */
         vuint16_t  EDGX0:2;           /* Edge X 0 */
         vuint16_t  ONESHOTX:1;        /* One Shot Mode X */
         vuint16_t  ARMX:1;            /* Arm X */
      } B;
   } mcPWM_CAPTCTRLX_16B_tag;


   /* Register layout for all registers CAPTCMPX... */

   typedef union {   /* Capture Compare X Register */
      vuint16_t R;
      struct {
         vuint16_t  EDGCNTX:8;         /* Edge Counter X */
         vuint16_t  EDGCMPX:8;         /* Edge Compare X */
      } B;
   } mcPWM_CAPTCMPX_16B_tag;


   /* Register layout for all registers CVAL0... */

   typedef union {   /* Capture Value 0 Register */
      vuint16_t R;
      struct {
         vuint16_t  CAPTVAL0:16;       /* Captured value from submodule counter */
      } B;
   } mcPWM_CVAL0_16B_tag;


   /* Register layout for all registers CVAL0CYC... */

   typedef union {   /* Capture Value 0 Cycle Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  CVAL0CYC:4;        /* Capture Value 0 Cycle */
      } B;
   } mcPWM_CVAL0CYC_16B_tag;


   /* Register layout for all registers CVAL1... */

   typedef union {   /* Capture Value 1 Register */
      vuint16_t R;
      struct {
         vuint16_t  CAPTVAL1:16;       /* Captured value from submodule counter */
      } B;
   } mcPWM_CVAL1_16B_tag;


   /* Register layout for all registers CVAL1CYC... */

   typedef union {   /* Capture Value 1 Cycle Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  CVAL1CYC:4;        /* Capture Value 1 Cycle */
      } B;
   } mcPWM_CVAL1CYC_16B_tag;


   /* Register layout for all registers CVAL2... */

   typedef union {   /* Capture Value 2 Register */
      vuint16_t R;
      struct {
         vuint16_t  CAPTVAL2:16;       /* Captured value from submodule counter */
      } B;
   } mcPWM_CVAL2_16B_tag;


   /* Register layout for all registers CVAL2CYC... */

   typedef union {   /* Capture Value 2 Cycle Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  CVAL2CYC:4;        /* Capture Value 2 Cycle */
      } B;
   } mcPWM_CVAL2CYC_16B_tag;


   /* Register layout for all registers CVAL3... */

   typedef union {   /* Capture Value 3 Register */
      vuint16_t R;
      struct {
         vuint16_t  CAPTVAL3:16;       /* Captured value from submodule counter */
      } B;
   } mcPWM_CVAL3_16B_tag;


   /* Register layout for all registers CVAL3CYC... */

   typedef union {   /* Capture Value 3 Cycle Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  CVAL3CYC:4;        /* Capture Value 3 Cycle */
      } B;
   } mcPWM_CVAL3CYC_16B_tag;


   /* Register layout for all registers CVAL4... */

   typedef union {   /* Capture Value 4 Register */
      vuint16_t R;
      struct {
         vuint16_t  CAPTVAL4:16;       /* Captured value from submodule counter */
      } B;
   } mcPWM_CVAL4_16B_tag;


   /* Register layout for all registers CVAL4CYC... */

   typedef union {   /* Capture Value 4 Cycle Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  CVAL4CYC:4;        /* Capture Value 4 Cycle */
      } B;
   } mcPWM_CVAL4CYC_16B_tag;


   /* Register layout for all registers CVAL5... */

   typedef union {   /* Capture Value 5 Register */
      vuint16_t R;
      struct {
         vuint16_t  CAPTVAL5:16;       /* Captured value from submodule counter */
      } B;
   } mcPWM_CVAL5_16B_tag;


   /* Register layout for all registers CVAL5CYC... */

   typedef union {   /* Capture Value 5 Cycle Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  CVAL5CYC:4;        /* Capture Value 5 Cycle */
      } B;
   } mcPWM_CVAL5CYC_16B_tag;

   typedef union {   /* Output Enable Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  PWMA_EN:4;         /* PWMA Output Enables */
         vuint16_t  PWMB_EN:4;         /* PWMB Output Enables */
         vuint16_t  PWMX_EN:4;         /* PWMX Output Enables */
      } B;
   } mcPWM_OUTEN_16B_tag;

   typedef union {   /* Mask Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  MASKA:4;           /* PWMA Masks */
         vuint16_t  MASKB:4;           /* PWMB Masks */
         vuint16_t  MASKX:4;           /* PWMX Masks */
      } B;
   } mcPWM_MASK_16B_tag;

   typedef union {   /* Software Controlled Output Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  OUTA_3:1;            
         vuint16_t  OUTB_3:1;            
         vuint16_t  OUTA_2:1;            
         vuint16_t  OUTB_2:1;            
         vuint16_t  OUTA_1:1;            
         vuint16_t  OUTB_1:1;            
         vuint16_t  OUTA_0:1;            
         vuint16_t  OUTB_0:1;            
      } B;
   } mcPWM_SWCOUT_16B_tag;

   typedef union {   /* Deadtime Source Select Register */
      vuint16_t R;
      struct {
         vuint16_t  SELA_3:2;          
         vuint16_t  SELB_3:2;          
         vuint16_t  SELA_2:2;          
         vuint16_t  SELB_2:2;          
         vuint16_t  SELA_1:2;          
         vuint16_t  SELB_1:2;          
         vuint16_t  SELA_0:2;          
         vuint16_t  SELB_0:2;            
      } B;
   } mcPWM_DTSRCSEL_16B_tag;

   typedef union {   /* Master Control Register */
      vuint16_t R;
      struct {
         vuint16_t  IPOL:4;            /* Current Polarity */
         vuint16_t  RUN:4;             /* Run */
         vuint16_t  CLDOK:4;           /* Clear Load Okay */
         vuint16_t  LDOK:4;            /* Load Okay */
      } B;
   } mcPWM_MCTRL_16B_tag;

   typedef union {   /* Fault Control Register */
      vuint16_t R;
      struct {
         vuint16_t  FLVL:4;            /* Fault Level */
         vuint16_t  FAUTO:4;           /* Automatic Fault Clearing */
         vuint16_t  FSAFE:4;           /* Fault Safety Mode */
         vuint16_t  FIE:4;             /* Fault Interrupt Enables */
      } B;
   } mcPWM_FCTRL_16B_tag;

   typedef union {   /* Fault Status Register */
      vuint16_t R;
      struct {
         vuint16_t:3;
         vuint16_t  FTEST:1;           /* Fault Test */
         vuint16_t  FFPIN:4;           /* Filtered Fault Pins */
         vuint16_t:4;
         vuint16_t  FFLAG:4;           /* Fault Flags */
      } B;
   } mcPWM_FSTS_16B_tag;

   typedef union {   /* Fault Filter Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  FILT_CNT:3;        /* Fault Filter Count */
         vuint16_t  FILT_PER:8;        /* Fault Filter Period */
      } B;
   } mcPWM_FFILT_16B_tag;


   /* Register layout for generated register(s) VAL... */

   typedef union {   /*  */
      vuint16_t R;
   } mcPWM_VAL_16B_tag;


   typedef struct mcPWM_SUBMOD_struct_tag {

	   /* Counter Register */
	   mcPWM_CNT_16B_tag CNT;              /* relative offset: 0x0000 */
	   /* Initial Counter Register */
	   mcPWM_INIT_16B_tag INIT;            /* relative offset: 0x0002 */
	   /* Control 2 Register */
	   mcPWM_CTRL2_16B_tag CTRL2;          /* relative offset: 0x0004 */

	   /* Control Register */
	   mcPWM_CTRL1_16B_tag CTRL;       /* relative offset: 0x0006 */


	   mcPWM_VAL_0_16B_tag VAL[6];    /* offset: 0x0008 size: 16 bit */

	   /* Fractional Delay Register A */
	   mcPWM_FRACA_16B_tag FRACA;          /* relative offset: 0x0014 */
	   /* Fractional Delay Register B */
	   mcPWM_FRACB_16B_tag FRACB;          /* relative offset: 0x0016 */
	   /* Output Control Register */
	   mcPWM_OCTRL_16B_tag OCTRL;          /* relative offset: 0x0018 */
	   /* Status Register */
	   mcPWM_STS_16B_tag STS;              /* relative offset: 0x001A */
	   /* Interrupt Enable Registers */
	   mcPWM_INTEN_16B_tag INTEN;          /* relative offset: 0x001C */
	   /* DMA Enable Registers */
	   mcPWM_DMAEN_16B_tag DMAEN;          /* relative offset: 0x001E */
	   /* Output Trigger Control  Registers */
	   mcPWM_TCTRL_16B_tag TCTRL;          /* relative offset: 0x0020 */
	   /* Fault Disable Mapping   Registers */
	   mcPWM_DISMAP_16B_tag DISMAP;        /* relative offset: 0x0022 */
	   /* Deadtime Count Register 0 */
	   mcPWM_DTCNT0_16B_tag DTCNT0;        /* relative offset: 0x0024 */
	   /* Deadtime Count Register 1 */
	   mcPWM_DTCNT1_16B_tag DTCNT1;        /* relative offset: 0x0026 */

	   /* Capture Control A Register */
	   mcPWM_CAPTCTRLA_16B_tag CAPTCTRLA;  /* relative offset: 0x0028 */
	   /* Capture Compare A Register */
	   mcPWM_CAPTCMPA_16B_tag CAPTCOMPA;  /* relative offset: 0x002A */
	   /* Capture Control B Register */
	   mcPWM_CAPTCTRLB_16B_tag CAPTCTRLB;  /* relative offset: 0x002C */
	   /* Capture Compare B Register */
	   mcPWM_CAPTCMPB_16B_tag CAPTCOMPB;  /* relative offset: 0x002E */
	   /* Capture Control X Register */
	   mcPWM_CAPTCTRLX_16B_tag CAPTCTRLX;  /* relative offset: 0x0030 */
	   /* Capture Compare X Register */
	   mcPWM_CAPTCMPX_16B_tag CAPTCOMPX;  /* relative offset: 0x0032 */

	   /* Capture Value 0 Register */
	   mcPWM_CVAL0_16B_tag CVAL0;          /* relative offset: 0x0034 */
	   /* Capture Value 0 Cycle Register */
	   mcPWM_CVAL0CYC_16B_tag CVAL0C;  /* relative offset: 0x0036 */

	   /* Capture Value 1 Register */
	   mcPWM_CVAL1_16B_tag CVAL1;          /* relative offset: 0x0038 */
	   /* Capture Value 1 Cycle Register */
	   mcPWM_CVAL1CYC_16B_tag CVAL1C;  /* relative offset: 0x003A */
	   /* Capture Value 2 Register */
	   mcPWM_CVAL2_16B_tag CVAL2;          /* relative offset: 0x003C */
	   /* Capture Value 2 Cycle Register */
	   mcPWM_CVAL2CYC_16B_tag CVAL2C;  /* relative offset: 0x003E */
	   /* Capture Value 3 Register */
	   mcPWM_CVAL3_16B_tag CVAL3;          /* relative offset: 0x0040 */
	   /* Capture Value 3 Cycle Register */
	   mcPWM_CVAL3CYC_16B_tag CVAL3C;  /* relative offset: 0x0042 */
	   /* Capture Value 4 Register */
	   mcPWM_CVAL4_16B_tag CVAL4;          /* relative offset: 0x0044 */
	   /* Capture Value 4 Cycle Register */
	   mcPWM_CVAL4CYC_16B_tag CVAL4C;  /* relative offset: 0x0046 */
	   /* Capture Value 5 Register */
	   mcPWM_CVAL5_16B_tag CVAL5;          /* relative offset: 0x0048 */
	   /* Capture Value 5 Cycle Register */
	   mcPWM_CVAL5CYC_16B_tag CVAL5C;  /* relative offset: 0x004A */
            
	   int8_t mcPWM_SUBMOD_reserved_004C[4];

   } mcPWM_SUBMOD_tag;


   typedef struct mcPWM_struct_tag { /* start of mcPWM_tag */

	   /*  Register set SUB */
	   mcPWM_SUBMOD_tag SUB[4];       /* offset: 0x0000  (0x0050 x 4) */


	   /* Output Enable Register */
	   mcPWM_OUTEN_16B_tag OUTEN;           /* offset: 0x0140 size: 16 bit */
	   /* Mask Register */
	   mcPWM_MASK_16B_tag MASK;             /* offset: 0x0142 size: 16 bit */
	   /* Software Controlled Output Register */
	   mcPWM_SWCOUT_16B_tag SWCOUT;         /* offset: 0x0144 size: 16 bit */
	   /* Deadtime Source Select Register */
	   mcPWM_DTSRCSEL_16B_tag DTSRCSEL;     /* offset: 0x0146 size: 16 bit */
	   /* Master Control Register */
	   mcPWM_MCTRL_16B_tag MCTRL;           /* offset: 0x0148 size: 16 bit */

	   int8_t mcPWM_reserved_014A[2];
	   /* Fault Control Register */
	   mcPWM_FCTRL_16B_tag FCTRL;           /* offset: 0x014C size: 16 bit */
	   /* Fault Status Register */
	   mcPWM_FSTS_16B_tag FSTS;             /* offset: 0x014E size: 16 bit */
	   /* Fault Filter Register */
	   mcPWM_FFILT_16B_tag FFILT;           /* offset: 0x0150 size: 16 bit */
   } mcPWM_tag;



/****************************************************************/
/*                                                              */
/* Module: LINFLEX  */
/*                                                              */
/****************************************************************/

   typedef union {   /* LIN Control Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  CCD:1;             /* Checksum Calculation Disable */
         vuint32_t  CFD:1;             /* Checksum Field Disable */
         vuint32_t  LASE:1;            /* LIN Auto Synchronization Enable */
         vuint32_t  AWUM:1;            /* Auto Wake Up */
         vuint32_t  MBL:4;             /* Master Break Length */
         vuint32_t  BF:1;              /* By-Pass Filter */
         vuint32_t  SFTM:1;            /* Selftest Mode */
         vuint32_t  LBKM:1;            /* Loopback Mode */
         vuint32_t  MME:1;             /* Master Mode Enable */
         vuint32_t  SSDT:1;            /* Slave Mode Synch Break Length */
         vuint32_t  RBLM:1;            /* Receiver Buffer Locked Mode */
         vuint32_t  SLEEP:1;           /* Sleep Mode Request */
         vuint32_t  INIT:1;            /* Initialization Mode Request */
      } B;
   } LINFLEX_LINCR1_32B_tag;

   typedef union {   /* LIN Interrupt Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  SZIE:1;            /* Stuck at Zero Interrupt Enable */
         vuint32_t  OCIE:1;            /* Output Compare Interrupt Enable */
         vuint32_t  BEIE:1;            /* Bit Error Interrupt Enable */
         vuint32_t  CEIE:1;            /* Checksum Error Interrupt Enable */
         vuint32_t  HEIE:1;            /* Header Error Interrupt Enable */
         vuint32_t:2;
         vuint32_t  FEIE:1;            /* Frame Error Interrupt Enable */
         vuint32_t  BOIE:1;            /* Buffer Overrun Error Interrupt Enable */
         vuint32_t  LSIE:1;            /* LIN State Interrupt Enable */
         vuint32_t  WUIE:1;            /* Wakeup Interrupt Enable */
         vuint32_t  DBFIE:1;           /* Data Buffer Full Interrupt Enable */
         vuint32_t  DBEIE:1;           /* Data Buffer Empty Interrupt Enable */
         vuint32_t  DRIE:1;            /* Data Reception complete Interrupt Enable */
         vuint32_t  DTIE:1;            /* Data Transmitted Interrupt Enable */
         vuint32_t  HRIE:1;            /* Header Received Interrupt Enable */
      } B;
   } LINFLEX_LINIER_32B_tag;

   typedef union {   /* LIN Status Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  LINS:4;            /* LIN State */
         vuint32_t:2;
         vuint32_t  RMB:1;             /* Release Message Buffer */
         vuint32_t:1;
         vuint32_t  RBSY:1;            /* Receiver Busy Flag */
         vuint32_t  RPS:1;             /* LIN Receive Signal */
         vuint32_t  WUF:1;             /* Wake Up Flag */
         vuint32_t  DBFF:1;            /* Data Buffer Full Flag */
         vuint32_t  DBEF:1;            /* Data Buffer Empty Flag */
         vuint32_t  DRF:1;             /* Data Reception Completed Flag */
         vuint32_t  DTF:1;             /* Data Transmission Completed Flag */
         vuint32_t  HRF:1;             /* Header Received Flag */
      } B;
   } LINFLEX_LINSR_32B_tag;

   typedef union {   /* LIN Error Status Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  SZF:1;             /* Stuck at Zero Flag */
         vuint32_t  OCF:1;             /* Output Compare Flag */
         vuint32_t  BEF:1;             /* Bit Error Flag */
         vuint32_t  CEF:1;             /* Checksum Error Flag */
         vuint32_t  SFEF:1;            /* Sync Field Error Flag */
         vuint32_t  BDEF:1;            /* Sync Delimiter Error Flag */
         vuint32_t  IDPEF:1;           /* ID Parity Error Flag */
         vuint32_t  FEF:1;             /* Framing Error Flag */
         vuint32_t  BOF:1;             /* Buffer Overrun Flag */
         vuint32_t:6;
         vuint32_t  NF:1;              /* Noise Flag */
      } B;
   } LINFLEX_LINESR_32B_tag;

   typedef union {   /* UART Mode Control Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  TDFL:3;        		/* Transmitter Data Field Length/TX FIFO Counter */
         vuint32_t  RDFL:3;       		/* Reception Data Field Length/RX FIFO Counter */
         vuint32_t  RFBM:1;            /* RX FIFO/ Buffer Mode */
         vuint32_t  TFBM:1;            /* TX FIFO/ Buffer Mode */
         vuint32_t  WL1:1;             /* Word Length in UART mode - bit 1 */
         vuint32_t  PC1:1;             /* Parity Check - bit 1 */
         vuint32_t  RXEN:1;            /* Receiver Enable */
         vuint32_t  TXEN:1;            /* Transmitter Enable */
         vuint32_t  OP:1;              /* Parity Check - bit 0 */
         vuint32_t  PCE:1;             /* Parity Control Enable */
         vuint32_t  WL:1;              /* Word Length in UART Mode - bit 0 */
         vuint32_t  UART:1;            /* UART Mode */
      } B;
   } LINFLEX_UARTCR_32B_tag;

   typedef union {   /* UART Mode Status Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  SZF:1;             /* Stuck at Zero Flag */
         vuint32_t  OCF:1;             /* Output Compare Flag */
         vuint32_t  PE:4;              /* Parity Error Flag */
         vuint32_t  RMB:1;             /* Release Message Buffer */
         vuint32_t  FEF:1;             /* Framing Error Flag */
         vuint32_t  BOF:1;             /* Buffer Overrun Flag */
         vuint32_t  RDI:1;             /* Receiver Data Input Signal */
         vuint32_t  WUF:1;             /* Wakeup Flag */
         vuint32_t:1;
         vuint32_t  TO:1;              /* Time Out */
         vuint32_t  DRF:1;             /* Data Reception Completed Flag/RX FIFO Empty Flag */
         vuint32_t  DTF:1;             /* Data Transmission Completed Flag/TX FIFO Full Flag */
         vuint32_t  NF:1;              /* Noise Flag */
      } B;
   } LINFLEX_UARTSR_32B_tag;

   typedef union {   /* LIN Time-Out Control Status Register */
      vuint32_t R;
      struct {
         vuint32_t:21;
         vuint32_t  LTOM:1;            /* Time-out Counter Mode */
         vuint32_t  IOT:1;             /* Idle on Timeout */
         vuint32_t  TOCE:1;            /* Time-Out Counter Enable */
         vuint32_t  CNT:8;             /* Counter Value */
      } B;
   } LINFLEX_LINTCSR_32B_tag;

   typedef union {   /* LIN Output Compare Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  OC2:8;             /* Output Compare Value 2 */
         vuint32_t  OC1:8;             /* Output Compare Value 1 */
      } B;
   } LINFLEX_LINOCR_32B_tag;

   typedef union {   /* LIN Time-Out Control Register */
      vuint32_t R;
      struct {
         vuint32_t:20;
         vuint32_t  RTO:4;             /* Response Time-Out Value */
         vuint32_t:1;
         vuint32_t  HTO:7;             /* Header Time-Out Value */
      } B;
   } LINFLEX_LINTOCR_32B_tag;

   typedef union {   /* LIN Fractional Baud Rate Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  DIV_F:4;           /* Fractional Baud Rates */
      } B;
   } LINFLEX_LINFBRR_32B_tag;

   typedef union {   /* LIN Integer Baud Rate Register */
      vuint32_t R;
      struct {
         vuint32_t:13;
         vuint32_t  DIV_M:19;          /* Integer Baud Rates */
      } B;
   } LINFLEX_LINIBRR_32B_tag;

   typedef union {   /* LIN Checksum Field Register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  CF:8;              /* Checksum Bits */
      } B;
   } LINFLEX_LINCFR_32B_tag;

   typedef union {   /* LIN Control Register 2 */
      vuint32_t R;
      struct {
         vuint32_t:17;
         vuint32_t  IOBE:1;            /* Idle on Bit Error */
         vuint32_t  IOPE:1;            /* Idle on Identifier Parity Error */
         vuint32_t  WURQ:1;            /* Wakeup Generate Request */
         vuint32_t  DDRQ:1;            /* Data Discard Request */
         vuint32_t  DTRQ:1;            /* Data Transmission Request */
         vuint32_t  ABRQ:1;            /* Abort Request */
         vuint32_t  HTRQ:1;            /* Header Transmission Request */
         vuint32_t:8;
      } B;
   } LINFLEX_LINCR2_32B_tag;

   typedef union {   /* Buffer Identifier Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  DFL:6;             /* Data Field Length */
         vuint32_t  DIR:1;             /* Direction */
         vuint32_t  CCS:1;             /* Classic Checksum */
         vuint32_t:2;
         vuint32_t  ID:6;              /* Identifier */
      } B;
   } LINFLEX_BIDR_32B_tag;

   typedef union {   /* Buffer Data Register Least Significant */
      vuint32_t R;
      struct {
         vuint32_t  DATA3:8;           /* Data3 */
         vuint32_t  DATA2:8;           /* Data2 */
         vuint32_t  DATA1:8;           /* Data1 */
         vuint32_t  DATA0:8;           /* Data0 */
      } B;
   } LINFLEX_BDRL_32B_tag;

   typedef union {   /* Buffer Data Register Most Significant */
      vuint32_t R;
      struct {
         vuint32_t  DATA7:8;           /* Data7 */
         vuint32_t  DATA6:8;           /* Data6 */
         vuint32_t  DATA5:8;           /* Data5 */
         vuint32_t  DATA4:8;           /* Data4 */
      } B;
   } LINFLEX_BDRM_32B_tag;

   typedef union {   /* Identifier Filter Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  FACT:8;            /* Filter Active */
      } B;
   } LINFLEX_IFER_32B_tag;

   typedef union {   /* Identifier Filter Match Index */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  IFMI_IFMI:4;       /* Filter Match Index */
      } B;
   } LINFLEX_IFMI_32B_tag;

   typedef union {   /* Identifier Filter Mode Register */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  IFM:4;             /* Filter Mode */
      } B;
   } LINFLEX_IFMR_32B_tag;


   /* Register layout for all registers IFCR... */

   typedef union {   /* Identifier Filter Control Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  DFL:6;             /* Data Field Length */
         vuint32_t  DIR:1;             /* Direction */
         vuint32_t  CCS:1;             /* Classic Checksum */
         vuint32_t:2;
         vuint32_t  ID:6;              /* Identifier */
      } B;
   } LINFLEX_IFCR_32B_tag;

   typedef union {   /* Global Control Register */
      vuint32_t R;
      struct {
         vuint32_t:26;
         vuint32_t  TDFBM:1;           /* Transmit Data First Bit MSB */
         vuint32_t  RDFBM:1;           /* Received Data First Bit MSB */
         vuint32_t  TDLIS:1;           /* Transmit Data Level Inversion Selection */
         vuint32_t  RDLIS:1;           /* Received Data Level Inversion Selection */
         vuint32_t  STOP:1;            /* 1/2 stop bit configuration */
         vuint32_t  SR:1;              /* Soft Reset */
      } B;
   } LINFLEX_GCR_32B_tag;

   typedef union {   /* UART Preset Time Out Register */
      vuint32_t R;
      struct {
         vuint32_t:20;
         vuint32_t  PTO:12;            /* Preset Time Out */
      } B;
   } LINFLEX_UARTPTO_32B_tag;

   typedef union {   /* UART Current Time Out Register */
      vuint32_t R;
      struct {
         vuint32_t:20;
         vuint32_t  CTO:12;            /* Current Time Out */
      } B;
   } LINFLEX_UARTCTO_32B_tag;

   typedef union {   /* DMA TX Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:17;
         vuint32_t  DTE:15;            /* DMA Tx channel Enable */
      } B;
   } LINFLEX_DMATXE_32B_tag;

   typedef union {   /* DMA RX Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:17;
         vuint32_t  DRE:15;            /* DMA Rx channel Enable */
      } B;
   } LINFLEX_DMARXE_32B_tag;



   typedef struct LINFLEX_struct_tag { /* start of LINFLEX_tag */
	   /* LIN Control Register */
	   LINFLEX_LINCR1_32B_tag LINCR1;       /* offset: 0x0000 size: 32 bit */
	   /* LIN Interrupt Enable Register */
	   LINFLEX_LINIER_32B_tag LINIER;       /* offset: 0x0004 size: 32 bit */
	   /* LIN Status Register */
	   LINFLEX_LINSR_32B_tag LINSR;         /* offset: 0x0008 size: 32 bit */
	   /* LIN Error Status Register */
	   LINFLEX_LINESR_32B_tag LINESR;       /* offset: 0x000C size: 32 bit */
	   /* UART Mode Control Register */
	   LINFLEX_UARTCR_32B_tag UARTCR;       /* offset: 0x0010 size: 32 bit */
	   /* UART Mode Status Register */
      LINFLEX_UARTSR_32B_tag UARTSR;       /* offset: 0x0014 size: 32 bit */
	  /* LIN Time-Out Control Status Register */
      LINFLEX_LINTCSR_32B_tag LINTCSR;     /* offset: 0x0018 size: 32 bit */
	  /* LIN Output Compare Register */
      LINFLEX_LINOCR_32B_tag LINOCR;       /* offset: 0x001C size: 32 bit */
	  /* LIN Time-Out Control Register */
      LINFLEX_LINTOCR_32B_tag LINTOCR;     /* offset: 0x0020 size: 32 bit */
	  /* LIN Fractional Baud Rate Register */
      LINFLEX_LINFBRR_32B_tag LINFBRR;     /* offset: 0x0024 size: 32 bit */
	  /* LIN Integer Baud Rate Register */
      LINFLEX_LINIBRR_32B_tag LINIBRR;     /* offset: 0x0028 size: 32 bit */
	  /* LIN Checksum Field Register */
      LINFLEX_LINCFR_32B_tag LINCFR;       /* offset: 0x002C size: 32 bit */
	  /* LIN Control Register 2 */
      LINFLEX_LINCR2_32B_tag LINCR2;       /* offset: 0x0030 size: 32 bit */
	  /* Buffer Identifier Register */
      LINFLEX_BIDR_32B_tag BIDR;           /* offset: 0x0034 size: 32 bit */
	  /* Buffer Data Register Least Significant */
      LINFLEX_BDRL_32B_tag BDRL;           /* offset: 0x0038 size: 32 bit */
	  /* Buffer Data Register Most Significant */
      LINFLEX_BDRM_32B_tag BDRM;           /* offset: 0x003C size: 32 bit */
	  /* Identifier Filter Enable Register */
      LINFLEX_IFER_32B_tag IFER;           /* offset: 0x0040 size: 32 bit */
	  /* Identifier Filter Match Index */
      LINFLEX_IFMI_32B_tag IFMI;           /* offset: 0x0044 size: 32 bit */
	  /* Identifier Filter Mode Register */
      LINFLEX_IFMR_32B_tag IFMR;           /* offset: 0x0048 size: 32 bit */

	  /* Identifier Filter Control Register */
	  LINFLEX_IFCR_32B_tag IFCR0;    /* offset: 0x004C size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR1;    /* offset: 0x0050 size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR2;    /* offset: 0x0054 size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR3;    /* offset: 0x0058 size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR4;    /* offset: 0x005C size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR5;    /* offset: 0x0060 size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR6;    /* offset: 0x0064 size: 32 bit */
	  LINFLEX_IFCR_32B_tag IFCR7;    /* offset: 0x0068 size: 32 bit */

      int8_t LINFLEX_reserved_006C[32];
	  /* Global Control Register */
      LINFLEX_GCR_32B_tag GCR;             /* offset: 0x008C size: 32 bit */
	  /* UART Preset Time Out Register */
      LINFLEX_UARTPTO_32B_tag UARTPTO;     /* offset: 0x0090 size: 32 bit */
	  /* UART Current Time Out Register */
      LINFLEX_UARTCTO_32B_tag UARTCTO;     /* offset: 0x0094 size: 32 bit */
	  /* DMA TX Enable Register */
      LINFLEX_DMATXE_32B_tag DMATXE;       /* offset: 0x0098 size: 32 bit */
	  /* DMA RX Enable Register */
      LINFLEX_DMARXE_32B_tag DMARXE;       /* offset: 0x009C size: 32 bit */
	  
   } LINFLEX_tag;


/****************************************************************/
/*                                                              */
/* Module: CRC  */
/*                                                              */
/****************************************************************/
   /* Register layout for all registers CFG... */

   typedef union {   /* CRC_CFG - CRC Configuration register */
      vuint32_t R;
      vuint8_t   B[4];    /* individual bytes can be accessed */
      vuint16_t  H[2];    /* individual halfwords can be accessed */
      vuint32_t  W;       /* individual words can be accessed */
      struct {
         vuint32_t:29;
         vuint32_t  POLYG:1;           /* Polynomal selection 0- CRC-CCITT, 1- CRC-CRC-32 INV selection */
         vuint32_t  SWAP:1;            /* SWAP selection */
         vuint32_t  INV:1;             /* INV selection */
      } BIT;
   } CRC_CFG_32B_tag;


   /* Register layout for all registers INP... */

   typedef union {   /* CRC_INP - CRC Input register */
      vuint32_t R;
      vuint8_t   B[4];    /* individual bytes can be accessed */
      vuint16_t  H[2];    /* individual halfwords can be accessed */
      vuint32_t  W;       /* individual words can be accessed */
   } CRC_INP_32B_tag;


   /* Register layout for all registers CSTAT... */

   typedef union {   /* CRC_STATUS - CRC Status register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
   } CRC_CSTAT_32B_tag;


   /* Register layout for all registers OUTP... */

   typedef union {   /* CRC_STATUS - CRC OUTPUT register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint16_t  HALF[2];    /* individual halfwords can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
   } CRC_OUTP_32B_tag;


   typedef struct CRC_CNTX_struct_tag {

	   /* CRC_CFG - CRC Configuration register */
	   CRC_CFG_32B_tag CFG;                /* relative offset: 0x0000 */
	   /* CRC_INP - CRC Input register */
	   CRC_INP_32B_tag INP;                /* relative offset: 0x0004 */
	   /* CRC_STATUS - CRC Status register */
	   CRC_CSTAT_32B_tag CSTAT;            /* relative offset: 0x0008 */
	   /* CRC_STATUS - CRC OUTPUT register */
	   CRC_OUTP_32B_tag OUTP;              /* relative offset: 0x000C */

   } CRC_CNTX_tag;


   typedef struct CRC_struct_tag { /* start of CRC_tag */
                                                   /*  Register set CNTX */
         CRC_CNTX_tag CNTX[3];             /* offset: 0x0000  (0x0010 x 3) */

   } CRC_tag;


/****************************************************************/
/*                                                              */
/* Module: FCCU  */
/*                                                              */
/****************************************************************/

   typedef union {   /* FCCU Control Register */
      vuint32_t R;
      struct {
         vuint32_t:23;
         vuint32_t  NVML:1;            /* NVM configuration loaded */
         vuint32_t  OPS:2;             /* Operation status */
         vuint32_t:1;
         vuint32_t  OPR:5;             /* Operation run */
      } B;
   } FCCU_CTRL_32B_tag;

   typedef union {   /* FCCU CTRL Key Register */
      vuint32_t R;
   } FCCU_CTRLK_32B_tag;

   typedef union {   /* FCCU Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:10;
         vuint32_t  RCCE1:1;           /* RCC1 enable */
         vuint32_t  RCCE0:1;           /* RCC0 enable */
         vuint32_t  SMRT:4;            /* Safe Mode Request Timer */
         vuint32_t:4;
         vuint32_t  CM:1;              /* Config mode */
         vuint32_t  SM:1;              /* Switching mode */
         vuint32_t  PS:1;              /* Polarity Selection */
         vuint32_t  FOM:3;             /* Fault Output Mode Selection */
         vuint32_t  FOP:6;             /* Fault Output Prescaler */
      } B;
   } FCCU_CFG_32B_tag;

   typedef union {   /* FCCU_CFK - FCCU CF Key Register */
      vuint32_t R;
   } FCCU_CFK_32B_tag;

   typedef union {   /* FCCU_NCFK - FCCU NCF Key Register */
      vuint32_t R;
   } FCCU_NCFK_32B_tag;

   typedef union {   /* FCCU_NCF_TO - FCCU NCF Time-out Register */
      vuint32_t R;
   } FCCU_NCF_TO_32B_tag;

   typedef union {   /* FCCU_CFG_TO - FCCU CFG Timeout Register */
      vuint32_t R;
      struct {
         vuint32_t:29;
         vuint32_t  TO:3;              /* Configuration time-out */
      } B;
   } FCCU_CFG_TO_32B_tag;

   typedef union {   /* FCCU_EINOUT - FCCU IO Control Register */
      vuint32_t R;
      struct {
         vuint32_t:26;
         vuint32_t  EIN1:1;            /* Error input 1 */
         vuint32_t  EIN0:1;            /* Error input 0 */
         vuint32_t:2;
         vuint32_t  EOUT1:1;           /* Error out 1 */
         vuint32_t  EOUT0:1;           /* Error out 0 */
      } B;
   } FCCU_EINOUT_32B_tag;

   typedef union {   /* FCCU_STAT - FCCU Status Register */
      vuint32_t R;
      struct {
         vuint32_t:29;
         vuint32_t  STATUS:3;          /* FCCU status */
      } B;
   } FCCU_STAT_32B_tag;

   typedef union {   /* FCCU_NAFS - FCCU NA Freeze Status Register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  N2AFSTATUS:8;      /* Normal to Alarm Frozen Status */
      } B;
   } FCCU_NAFS_32B_tag;

   typedef union {   /* FCCU_AFFS - FCCU AF Freeze Status Register */
      vuint32_t R;
      struct {
         vuint32_t:22;
         vuint32_t  AFFS_SRC:2;        /* Fault source */
         vuint32_t  A2AFSTATUS:8;      /* Alarm to Fault Frozen Status */
      } B;
   } FCCU_AFFS_32B_tag;

   typedef union {   /* FCCU_NFFS - FCCU NF Freeze Status Register */
      vuint32_t R;
      struct {
         vuint32_t:22;
         vuint32_t  NFFS_SRC:2;        /* Fault source */
         vuint32_t  NFFS_NFFS:8;       /* Normal to Fault Frozen Status */
      } B;
   } FCCU_NFFS_32B_tag;

   typedef union {   /* FCCU_FAFS - FCCU FA Freeze Status Register */
      vuint32_t R;
      struct {
         vuint32_t:24;
         vuint32_t  FAFS_FAFS:8;       /* Fault to Normal Frozen Status */
      } B;
   } FCCU_FAFS_32B_tag;

   typedef union {   /* FCCU_SCFS - FCCU SC Freeze Status Register */
      vuint32_t R;
      struct {
         vuint32_t:30;
         vuint32_t  RCCS1:1;           /* RCC1 Status */
         vuint32_t  RCCS0:1;           /* RCC0 Status */
      } B;
   } FCCU_SCFS_32B_tag;

   typedef union {   /* FCCU_CFF - FCCU CF Fake Register */
      vuint32_t R;
      struct {
         vuint32_t:25;
         vuint32_t  FCFC:7;            /* Fake critical fault code */
      } B;
   } FCCU_CFF_32B_tag;

   typedef union {   /* FCCU_NCFF - FCCU NCF Fake Register */
      vuint32_t R;
      struct {
         vuint32_t:25;
         vuint32_t  FNCFC:7;           /* Fake non-critical fault code */
      } B;
   } FCCU_NCFF_32B_tag;

   typedef union {   /* FCCU_IRQ_STAT - FCCU IRQ Status Register */
      vuint32_t R;
      struct {
         vuint32_t:29;
         vuint32_t  NMI_STAT:1;        /* NMI Interrupt Status */
         vuint32_t  ALRM_STAT:1;       /* Alarm Interrupt Status */
         vuint32_t  CFG_TO_STAT:1;     /* Configuration Time-out Status */
      } B;
   } FCCU_IRQ_STAT_32B_tag;

   typedef union {   /* FCCU_IRQ_EN - FCCU IRQ Enable Register */
      vuint32_t R;
      struct {
         vuint32_t:31;
         vuint32_t  CFG_TO_IEN:1;      /* Configuration Time-out Interrupt Enable */
      } B;
   } FCCU_IRQ_EN_32B_tag;

   typedef union {   /* FCCU_XTMR - FCCU XTMR Register */
      vuint32_t R;
      struct {
         vuint32_t  XTMR_XTMR:32;      /* Alarm/Watchdog/safe request timer */
      } B;
   } FCCU_XTMR_32B_tag;

   typedef union {   /* FCCU_MCS - FCCU MCS Register */
      vuint32_t R;
      struct {
         vuint32_t  VL3:1;             /* Valid */
         vuint32_t  FS3:1;             /* Fault Status */
         vuint32_t:2;
         vuint32_t  MCS3:4;            /* Magic Carpet oldest state */
         vuint32_t  VL2:1;             /* Valid */
         vuint32_t  FS2:1;             /* Fault Status */
         vuint32_t:2;
         vuint32_t  MCS2:4;            /* Magic Carpet previous-previous state */
         vuint32_t  VL1:1;             /* Valid */
         vuint32_t  FS1:1;             /* Fault Status */
         vuint32_t:2;
         vuint32_t  MCS1:4;            /* Magic Carpet previous state */
         vuint32_t  VL0:1;             /* Valid */
         vuint32_t  FS0:1;             /* Fault Status */
         vuint32_t:2;
         vuint32_t  MCS0:4;            /* Magic Carpet latest state */
      } B;
   } FCCU_MCS_32B_tag;

   /* Register layout for generated register(s) CF_CFG... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_CF_CFG_32B_tag;


   /* Register layout for generated register(s) NCF_CFG... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_NCF_CFG_32B_tag;


   /* Register layout for generated register(s) CFS_CFG... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_CFS_CFG_32B_tag;


   /* Register layout for generated register(s) NCFS_CFG... */

   typedef union {   /*  */
      vuint32_t R;
   } FCCU_NCFS_CFG_32B_tag;

   /* Register layout for generated register(s) CFS... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_CFS_32B_tag;

   /* Register layout for generated register(s) NCFS... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_NCFS_32B_tag;

   /* Register layout for generated register(s) NCFE... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_NCFE_32B_tag;

   /* Register layout for generated register(s) NCF_TOE... */
   typedef union {   /*  */
      vuint32_t R;
   } FCCU_NCF_TOE_32B_tag;

   typedef struct FCCU_struct_tag { /* start of FCCU_tag */
	   /* FCCU Control Register */
	   FCCU_CTRL_32B_tag CTRL;              /* offset: 0x0000 size: 32 bit */
	   /* FCCU CTRL Key Register */
	   FCCU_CTRLK_32B_tag CTRLK;            /* offset: 0x0004 size: 32 bit */
	   /* FCCU Configuration Register */
	   FCCU_CFG_32B_tag CFG;                /* offset: 0x0008 size: 32 bit */

	   FCCU_CF_CFG_32B_tag CF_CFG[4];    /* offset: 0x000C  (0x0004 x 4) */

	   FCCU_NCF_CFG_32B_tag NCF_CFG[4];  /* offset: 0x001C  (0x0004 x 4) */

	   FCCU_CFS_CFG_32B_tag CFS_CFG[8];  /* offset: 0x002C  (0x0004 x 8) */

	   FCCU_NCFS_CFG_32B_tag NCFS_CFG[8];  /* offset: 0x004C  (0x0004 x 8) */

	   FCCU_CFS_32B_tag CFS[4];          /* offset: 0x006C  (0x0004 x 4) */

	   /* FCCU_CFK - FCCU CF Key Register */
	   FCCU_CFK_32B_tag CFK;                /* offset: 0x007C size: 32 bit */

	   FCCU_NCFS_32B_tag NCFS[4];        /* offset: 0x0080  (0x0004 x 4) */

	   /* FCCU_NCFK - FCCU NCF Key Register */
	   FCCU_NCFK_32B_tag NCFK;              /* offset: 0x0090 size: 32 bit */

	   FCCU_NCFE_32B_tag NCFE[4];        /* offset: 0x0094  (0x0004 x 4) */

	   FCCU_NCF_TOE_32B_tag NCF_TOE[4];  /* offset: 0x00A4  (0x0004 x 4) */

	   /* FCCU_NCF_TO - FCCU NCF Time-out Register */
	   FCCU_NCF_TO_32B_tag NCF_TO;          /* offset: 0x00B4 size: 32 bit */
	   /* FCCU_CFG_TO - FCCU CFG Timeout Register */
	   FCCU_CFG_TO_32B_tag CFG_TO;          /* offset: 0x00B8 size: 32 bit */
	   /* FCCU_EINOUT - FCCU IO Control Register */
	   FCCU_EINOUT_32B_tag EINOUT;          /* offset: 0x00BC size: 32 bit */
	   /* FCCU_STAT - FCCU Status Register */
	   FCCU_STAT_32B_tag STAT;              /* offset: 0x00C0 size: 32 bit */
	   /* FCCU_NAFS - FCCU NA Freeze Status Register */
	   FCCU_NAFS_32B_tag NAFS;              /* offset: 0x00C4 size: 32 bit */
	   /* FCCU_AFFS - FCCU AF Freeze Status Register */
	   FCCU_AFFS_32B_tag AFFS;              /* offset: 0x00C8 size: 32 bit */
	   /* FCCU_NFFS - FCCU NF Freeze Status Register */
	   FCCU_NFFS_32B_tag NFFS;              /* offset: 0x00CC size: 32 bit */
	   /* FCCU_FAFS - FCCU FA Freeze Status Register */
	   FCCU_FAFS_32B_tag FAFS;              /* offset: 0x00D0 size: 32 bit */
	   /* FCCU_SCFS - FCCU SC Freeze Status Register */
	   FCCU_SCFS_32B_tag SCFS;              /* offset: 0x00D4 size: 32 bit */
	   /* FCCU_CFF - FCCU CF Fake Register */
	   FCCU_CFF_32B_tag CFF;                /* offset: 0x00D8 size: 32 bit */
	   /* FCCU_NCFF - FCCU NCF Fake Register */
	   FCCU_NCFF_32B_tag NCFF;              /* offset: 0x00DC size: 32 bit */
	   /* FCCU_IRQ_STAT - FCCU IRQ Status Register */
	   FCCU_IRQ_STAT_32B_tag IRQ_STAT;      /* offset: 0x00E0 size: 32 bit */
	   /* FCCU_IRQ_EN - FCCU IRQ Enable Register */
	   FCCU_IRQ_EN_32B_tag IRQ_EN;          /* offset: 0x00E4 size: 32 bit */
	   /* FCCU_XTMR - FCCU XTMR Register */
	   FCCU_XTMR_32B_tag XTMR;              /* offset: 0x00E8 size: 32 bit */
	   /* FCCU_MCS - FCCU MCS Register */
	   FCCU_MCS_32B_tag MCS;                /* offset: 0x00EC size: 32 bit */
   } FCCU_tag;


/****************************************************************/
/*                                                              */
/* Module: SGENDIG  											*/
/*                                                              */
/****************************************************************/
   typedef union {   /* SGENDIG_CTRL - SGENDIG Control Register */
      vuint32_t R;
      struct {
         vuint32_t  LDOS:1;            /* Operation Status */
         vuint32_t  IOAMPL:5;          /* Define the AMPLitude value on I/O pad */
         vuint32_t:2;
         vuint32_t  SEMASK:1;          /* Sine wave generator Error MASK interrupt register */
         vuint32_t:5;
         vuint32_t  S0H1:1;            /* Operation Status */
         vuint32_t  PDS:1;             /* Operation Status */
         vuint32_t  IOFREQ:16;         /* Define the FREQuency value on I/O pad */
      } B;
   } SGENDIG_CTRL_32B_tag;

   typedef union {   /* SGENDIG_IRQE - SGENDIG Interrupt Request Enable  Register */
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t  SERR:1;            /* Sine wave generator Error bit */
         vuint32_t:3;
         vuint32_t  FERR:1;            /* Sine wave generator Force Error bit */
         vuint32_t:19;
      } B;
   } SGENDIG_IRQE_32B_tag;

   typedef struct SGENDIG_struct_tag { /* start of SGENDIG_tag */
	   /* SGENDIG_CTRL - SGENDIG Control Register */
	   SGENDIG_CTRL_32B_tag CTRL;           /* offset: 0x0000 size: 32 bit */
	   /* SGENDIG_IRQE - SGENDIG Interrupt Request Enable  Register */
	   SGENDIG_IRQE_32B_tag IRQE;           /* offset: 0x0004 size: 32 bit */
   } SGENDIG_tag;




/****************************************************************/
/*                                                              */
/* Module: AIPS  */
/*                                                              */
/****************************************************************/

   typedef union {   /* MPROT - Master Privilege Registers */
      vuint32_t R;
      struct {
         vuint32_t  MPROT0_MBW:1;      /* Master 0 Buffer Writes */
         vuint32_t  MPROT0_MTR:1;      /* Master 0 Trusted for Reads */
         vuint32_t  MPROT0_MTW:1;      /* Master 0 Trusted for Writes */
         vuint32_t  MPROT0_MPL:1;      /* Master 0 Priviledge Level */
         vuint32_t  MPROT1_MBW:1;      /* Master 1 Buffer Writes */
         vuint32_t  MPROT1_MTR:1;      /* Master 1 Trusted for Reads */
         vuint32_t  MPROT1_MTW:1;      /* Master 1 Trusted for Writes */
         vuint32_t  MPROT1_MPL:1;      /* Master 1 Priviledge Level */
         vuint32_t  MPROT2_MBW:1;      /* Master 2 Buffer Writes */
         vuint32_t  MPROT2_MTR:1;      /* Master 2 Trusted for Reads */
         vuint32_t  MPROT2_MTW:1;      /* Master 2 Trusted for Writes */
         vuint32_t  MPROT2_MPL:1;      /* Master 2 Priviledge Level */
         vuint32_t  MPROT3_MBW:1;      /* Master 3 Buffer Writes */
         vuint32_t  MPROT3_MTR:1;      /* Master 3 Trusted for Reads */
         vuint32_t  MPROT3_MTW:1;      /* Master 3 Trusted for Writes */
         vuint32_t  MPROT3_MPL:1;      /* Master 3 Priviledge Level */
         vuint32_t  MPROT4_MBW:1;      /* Master 4 Buffer Writes */
         vuint32_t  MPROT4_MTR:1;      /* Master 4 Trusted for Reads */
         vuint32_t  MPROT4_MTW:1;      /* Master 4 Trusted for Writes */
         vuint32_t  MPROT4_MPL:1;      /* Master 4 Priviledge Level */
         vuint32_t  MPROT5_MBW:1;      /* Master 5 Buffer Writes */
         vuint32_t  MPROT5_MTR:1;      /* Master 5 Trusted for Reads */
         vuint32_t  MPROT5_MTW:1;      /* Master 5 Trusted for Writes */
         vuint32_t  MPROT5_MPL:1;      /* Master 5 Priviledge Level */
         vuint32_t  MPROT6_MBW:1;      /* Master 6 Buffer Writes */
         vuint32_t  MPROT6_MTR:1;      /* Master 6 Trusted for Reads */
         vuint32_t  MPROT6_MTW:1;      /* Master 6 Trusted for Writes */
         vuint32_t  MPROT6_MPL:1;      /* Master 6 Priviledge Level */
         vuint32_t  MPROT7_MBW:1;      /* Master 7 Buffer Writes */
         vuint32_t  MPROT7_MTR:1;      /* Master 7 Trusted for Reads */
         vuint32_t  MPROT7_MTW:1;      /* Master 7 Trusted for Writes */
         vuint32_t  MPROT7_MPL:1;      /* Master 7 Priviledge Level */
      } B;
   } AIPS_MPROT_32B_tag;

   typedef union {   /* PACR0_7 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR0_BW:1;        /* Buffer Writes */
         vuint32_t  PACR0_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR0_WP:1;        /* Write Protect */
         vuint32_t  PACR0_TP:1;        /* Trusted Protect */
         vuint32_t  PACR1_BW:1;        /* Buffer Writes */
         vuint32_t  PACR1_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR1_WP:1;        /* Write Protect */
         vuint32_t  PACR1_TP:1;        /* Trusted Protect */
         vuint32_t  PACR2_BW:1;        /* Buffer Writes */
         vuint32_t  PACR2_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR2_WP:1;        /* Write Protect */
         vuint32_t  PACR2_TP:1;        /* Trusted Protect */
         vuint32_t  PACR3_BW:1;        /* Buffer Writes */
         vuint32_t  PACR3_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR3_WP:1;        /* Write Protect */
         vuint32_t  PACR3_TP:1;        /* Trusted Protect */
         vuint32_t  PACR4_BW:1;        /* Buffer Writes */
         vuint32_t  PACR4_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR4_WP:1;        /* Write Protect */
         vuint32_t  PACR4_TP:1;        /* Trusted Protect */
         vuint32_t  PACR5_BW:1;        /* Buffer Writes */
         vuint32_t  PACR5_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR5_WP:1;        /* Write Protect */
         vuint32_t  PACR5_TP:1;        /* Trusted Protect */
         vuint32_t  PACR6_BW:1;        /* Buffer Writes */
         vuint32_t  PACR6_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR6_WP:1;        /* Write Protect */
         vuint32_t  PACR6_TP:1;        /* Trusted Protect */
         vuint32_t  PACR7_BW:1;        /* Buffer Writes */
         vuint32_t  PACR7_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR7_WP:1;        /* Write Protect */
         vuint32_t  PACR7_TP:1;        /* Trusted Protect */
      } B;
   } AIPS_PACR0_7_32B_tag;

   typedef union {   /* PACR8_15 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR8_BW:1;        /* Buffer Writes */
         vuint32_t  PACR8_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR8_WP:1;        /* Write Protect */
         vuint32_t  PACR8_TP:1;        /* Trusted Protect */
         vuint32_t  PACR9_BW:1;        /* Buffer Writes */
         vuint32_t  PACR9_SP:1;        /* Supervisor Protect */
         vuint32_t  PACR9_WP:1;        /* Write Protect */
         vuint32_t  PACR9_TP:1;        /* Trusted Protect */
         vuint32_t  PACR10_BW:1;       /* Buffer Writes */
         vuint32_t  PACR10_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR10_WP:1;       /* Write Protect */
         vuint32_t  PACR10_TP:1;       /* Trusted Protect */
         vuint32_t  PACR11_BW:1;       /* Buffer Writes */
         vuint32_t  PACR11_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR11_WP:1;       /* Write Protect */
         vuint32_t  PACR11_TP:1;       /* Trusted Protect */
         vuint32_t  PACR12_BW:1;       /* Buffer Writes */
         vuint32_t  PACR12_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR12_WP:1;       /* Write Protect */
         vuint32_t  PACR12_TP:1;       /* Trusted Protect */
         vuint32_t  PACR13_BW:1;       /* Buffer Writes */
         vuint32_t  PACR13_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR13_WP:1;       /* Write Protect */
         vuint32_t  PACR13_TP:1;       /* Trusted Protect */
         vuint32_t  PACR14_BW:1;       /* Buffer Writes */
         vuint32_t  PACR14_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR14_WP:1;       /* Write Protect */
         vuint32_t  PACR14_TP:1;       /* Trusted Protect */
         vuint32_t  PACR15_BW:1;       /* Buffer Writes */
         vuint32_t  PACR15_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR15_WP:1;       /* Write Protect */
         vuint32_t  PACR15_TP:1;       /* Trusted Protect */
      } B;
   } AIPS_PACR8_15_32B_tag;

   typedef union {   /* PACR16_23 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR16_BW:1;       /* Buffer Writes */
         vuint32_t  PACR16_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR16_WP:1;       /* Write Protect */
         vuint32_t  PACR16_TP:1;       /* Trusted Protect */
         vuint32_t  PACR17_BW:1;       /* Buffer Writes */
         vuint32_t  PACR17_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR17_WP:1;       /* Write Protect */
         vuint32_t  PACR17_TP:1;       /* Trusted Protect */
         vuint32_t  PACR18_BW:1;       /* Buffer Writes */
         vuint32_t  PACR18_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR18_WP:1;       /* Write Protect */
         vuint32_t  PACR18_TP:1;       /* Trusted Protect */
         vuint32_t  PACR19_BW:1;       /* Buffer Writes */
         vuint32_t  PACR19_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR19_WP:1;       /* Write Protect */
         vuint32_t  PACR19_TP:1;       /* Trusted Protect */
         vuint32_t  PACR20_BW:1;       /* Buffer Writes */
         vuint32_t  PACR20_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR20_WP:1;       /* Write Protect */
         vuint32_t  PACR20_TP:1;       /* Trusted Protect */
         vuint32_t  PACR21_BW:1;       /* Buffer Writes */
         vuint32_t  PACR21_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR21_WP:1;       /* Write Protect */
         vuint32_t  PACR21_TP:1;       /* Trusted Protect */
         vuint32_t  PACR22_BW:1;       /* Buffer Writes */
         vuint32_t  PACR22_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR22_WP:1;       /* Write Protect */
         vuint32_t  PACR22_TP:1;       /* Trusted Protect */
         vuint32_t  PACR23_BW:1;       /* Buffer Writes */
         vuint32_t  PACR23_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR23_WP:1;       /* Write Protect */
         vuint32_t  PACR23_TP:1;       /* Trusted Protect */
      } B;
   } AIPS_PACR16_23_32B_tag;

   typedef union {   /* PACR24_31 - Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  PACR24_BW:1;       /* Buffer Writes */
         vuint32_t  PACR24_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR24_WP:1;       /* Write Protect */
         vuint32_t  PACR24_TP:1;       /* Trusted Protect */
         vuint32_t  PACR25_BW:1;       /* Buffer Writes */
         vuint32_t  PACR25_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR25_WP:1;       /* Write Protect */
         vuint32_t  PACR25_TP:1;       /* Trusted Protect */
         vuint32_t  PACR26_BW:1;       /* Buffer Writes */
         vuint32_t  PACR26_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR26_WP:1;       /* Write Protect */
         vuint32_t  PACR26_TP:1;       /* Trusted Protect */
         vuint32_t  PACR27_BW:1;       /* Buffer Writes */
         vuint32_t  PACR27_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR27_WP:1;       /* Write Protect */
         vuint32_t  PACR27_TP:1;       /* Trusted Protect */
         vuint32_t  PACR28_BW:1;       /* Buffer Writes */
         vuint32_t  PACR28_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR28_WP:1;       /* Write Protect */
         vuint32_t  PACR28_TP:1;       /* Trusted Protect */
         vuint32_t  PACR29_BW:1;       /* Buffer Writes */
         vuint32_t  PACR29_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR29_WP:1;       /* Write Protect */
         vuint32_t  PACR29_TP:1;       /* Trusted Protect */
         vuint32_t  PACR30_BW:1;       /* Buffer Writes */
         vuint32_t  PACR30_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR30_WP:1;       /* Write Protect */
         vuint32_t  PACR30_TP:1;       /* Trusted Protect */
         vuint32_t  PACR31_BW:1;       /* Buffer Writes */
         vuint32_t  PACR31_SP:1;       /* Supervisor Protect */
         vuint32_t  PACR31_WP:1;       /* Write Protect */
         vuint32_t  PACR31_TP:1;       /* Trusted Protect */
      } B;
   } AIPS_PACR24_31_32B_tag;

   typedef union {   /* OPACR0_7 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR0_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR0_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR0_WP:1;       /* Write Protect */
         vuint32_t  OPACR0_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR1_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR1_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR1_WP:1;       /* Write Protect */
         vuint32_t  OPACR1_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR2_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR2_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR2_WP:1;       /* Write Protect */
         vuint32_t  OPACR2_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR3_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR3_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR3_WP:1;       /* Write Protect */
         vuint32_t  OPACR3_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR4_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR4_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR4_WP:1;       /* Write Protect */
         vuint32_t  OPACR4_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR5_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR5_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR5_WP:1;       /* Write Protect */
         vuint32_t  OPACR5_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR6_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR6_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR6_WP:1;       /* Write Protect */
         vuint32_t  OPACR6_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR7_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR7_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR7_WP:1;       /* Write Protect */
         vuint32_t  OPACR7_TP:1;       /* Trusted Protect */
      } B;
   } AIPS_OPACR0_7_32B_tag;

   typedef union {   /* OPACR8_15 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR8_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR8_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR8_WP:1;       /* Write Protect */
         vuint32_t  OPACR8_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR9_BW:1;       /* Buffer Writes */
         vuint32_t  OPACR9_SP:1;       /* Supervisor Protect */
         vuint32_t  OPACR9_WP:1;       /* Write Protect */
         vuint32_t  OPACR9_TP:1;       /* Trusted Protect */
         vuint32_t  OPACR10_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR10_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR10_WP:1;      /* Write Protect */
         vuint32_t  OPACR10_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR11_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR11_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR11_WP:1;      /* Write Protect */
         vuint32_t  OPACR11_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR12_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR12_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR12_WP:1;      /* Write Protect */
         vuint32_t  OPACR12_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR13_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR13_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR13_WP:1;      /* Write Protect */
         vuint32_t  OPACR13_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR14_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR14_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR14_WP:1;      /* Write Protect */
         vuint32_t  OPACR14_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR15_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR15_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR15_WP:1;      /* Write Protect */
         vuint32_t  OPACR15_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR8_15_32B_tag;

   typedef union {   /* OPACR16_23 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR16_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR16_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR16_WP:1;      /* Write Protect */
         vuint32_t  OPACR16_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR17_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR17_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR17_WP:1;      /* Write Protect */
         vuint32_t  OPACR17_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR18_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR18_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR18_WP:1;      /* Write Protect */
         vuint32_t  OPACR18_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR19_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR19_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR19_WP:1;      /* Write Protect */
         vuint32_t  OPACR19_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR20_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR20_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR20_WP:1;      /* Write Protect */
         vuint32_t  OPACR20_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR21_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR21_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR21_WP:1;      /* Write Protect */
         vuint32_t  OPACR21_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR22_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR22_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR22_WP:1;      /* Write Protect */
         vuint32_t  OPACR22_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR23_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR23_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR23_WP:1;      /* Write Protect */
         vuint32_t  OPACR23_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR16_23_32B_tag;

   typedef union {   /* OPACR24_31 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR24_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR24_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR24_WP:1;      /* Write Protect */
         vuint32_t  OPACR24_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR25_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR25_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR25_WP:1;      /* Write Protect */
         vuint32_t  OPACR25_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR26_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR26_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR26_WP:1;      /* Write Protect */
         vuint32_t  OPACR26_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR27_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR27_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR27_WP:1;      /* Write Protect */
         vuint32_t  OPACR27_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR28_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR28_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR28_WP:1;      /* Write Protect */
         vuint32_t  OPACR28_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR29_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR29_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR29_WP:1;      /* Write Protect */
         vuint32_t  OPACR29_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR30_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR30_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR30_WP:1;      /* Write Protect */
         vuint32_t  OPACR30_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR31_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR31_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR31_WP:1;      /* Write Protect */
         vuint32_t  OPACR31_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR24_31_32B_tag;

   typedef union {   /* OPACR32_39 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR32_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR32_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR32_WP:1;      /* Write Protect */
         vuint32_t  OPACR32_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR33_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR33_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR33_WP:1;      /* Write Protect */
         vuint32_t  OPACR33_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR34_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR34_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR34_WP:1;      /* Write Protect */
         vuint32_t  OPACR34_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR35_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR35_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR35_WP:1;      /* Write Protect */
         vuint32_t  OPACR35_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR36_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR36_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR36_WP:1;      /* Write Protect */
         vuint32_t  OPACR36_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR37_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR37_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR37_WP:1;      /* Write Protect */
         vuint32_t  OPACR37_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR38_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR38_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR38_WP:1;      /* Write Protect */
         vuint32_t  OPACR38_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR39_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR39_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR39_WP:1;      /* Write Protect */
         vuint32_t  OPACR39_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR32_39_32B_tag;

   typedef union {   /* OPACR40_47 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR40_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR40_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR40_WP:1;      /* Write Protect */
         vuint32_t  OPACR40_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR41_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR41_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR41_WP:1;      /* Write Protect */
         vuint32_t  OPACR41_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR42_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR42_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR42_WP:1;      /* Write Protect */
         vuint32_t  OPACR42_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR43_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR43_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR43_WP:1;      /* Write Protect */
         vuint32_t  OPACR43_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR44_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR44_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR44_WP:1;      /* Write Protect */
         vuint32_t  OPACR44_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR45_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR45_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR45_WP:1;      /* Write Protect */
         vuint32_t  OPACR45_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR46_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR46_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR46_WP:1;      /* Write Protect */
         vuint32_t  OPACR46_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR47_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR47_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR47_WP:1;      /* Write Protect */
         vuint32_t  OPACR47_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR40_47_32B_tag;

   typedef union {   /* OPACR48_55 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR48_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR48_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR48_WP:1;      /* Write Protect */
         vuint32_t  OPACR48_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR49_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR49_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR49_WP:1;      /* Write Protect */
         vuint32_t  OPACR49_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR50_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR50_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR50_WP:1;      /* Write Protect */
         vuint32_t  OPACR50_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR51_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR51_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR51_WP:1;      /* Write Protect */
         vuint32_t  OPACR51_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR52_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR52_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR52_WP:1;      /* Write Protect */
         vuint32_t  OPACR52_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR53_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR53_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR53_WP:1;      /* Write Protect */
         vuint32_t  OPACR53_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR54_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR54_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR54_WP:1;      /* Write Protect */
         vuint32_t  OPACR54_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR55_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR55_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR55_WP:1;      /* Write Protect */
         vuint32_t  OPACR55_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR48_55_32B_tag;

   typedef union {   /* OPACR56_63 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR56_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR56_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR56_WP:1;      /* Write Protect */
         vuint32_t  OPACR56_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR57_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR57_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR57_WP:1;      /* Write Protect */
         vuint32_t  OPACR57_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR58_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR58_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR58_WP:1;      /* Write Protect */
         vuint32_t  OPACR58_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR59_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR59_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR59_WP:1;      /* Write Protect */
         vuint32_t  OPACR59_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR60_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR60_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR60_WP:1;      /* Write Protect */
         vuint32_t  OPACR60_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR61_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR61_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR61_WP:1;      /* Write Protect */
         vuint32_t  OPACR61_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR62_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR62_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR62_WP:1;      /* Write Protect */
         vuint32_t  OPACR62_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR63_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR63_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR63_WP:1;      /* Write Protect */
         vuint32_t  OPACR63_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR56_63_32B_tag;

   typedef union {   /* OPACR64_71 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR64_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR64_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR64_WP:1;      /* Write Protect */
         vuint32_t  OPACR64_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR65_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR65_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR65_WP:1;      /* Write Protect */
         vuint32_t  OPACR65_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR66_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR66_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR66_WP:1;      /* Write Protect */
         vuint32_t  OPACR66_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR67_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR67_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR67_WP:1;      /* Write Protect */
         vuint32_t  OPACR67_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR68_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR68_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR68_WP:1;      /* Write Protect */
         vuint32_t  OPACR68_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR69_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR69_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR69_WP:1;      /* Write Protect */
         vuint32_t  OPACR69_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR70_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR70_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR70_WP:1;      /* Write Protect */
         vuint32_t  OPACR70_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR71_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR71_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR71_WP:1;      /* Write Protect */
         vuint32_t  OPACR71_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR64_71_32B_tag;

   typedef union {   /* OPACR72_79 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR72_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR72_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR72_WP:1;      /* Write Protect */
         vuint32_t  OPACR72_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR73_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR73_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR73_WP:1;      /* Write Protect */
         vuint32_t  OPACR73_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR74_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR74_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR74_WP:1;      /* Write Protect */
         vuint32_t  OPACR74_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR75_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR75_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR75_WP:1;      /* Write Protect */
         vuint32_t  OPACR75_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR76_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR76_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR76_WP:1;      /* Write Protect */
         vuint32_t  OPACR76_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR77_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR77_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR77_WP:1;      /* Write Protect */
         vuint32_t  OPACR77_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR78_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR78_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR78_WP:1;      /* Write Protect */
         vuint32_t  OPACR78_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR79_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR79_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR79_WP:1;      /* Write Protect */
         vuint32_t  OPACR79_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR72_79_32B_tag;

   typedef union {   /* OPACR80_87 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR80_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR80_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR80_WP:1;      /* Write Protect */
         vuint32_t  OPACR80_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR81_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR81_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR81_WP:1;      /* Write Protect */
         vuint32_t  OPACR81_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR82_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR82_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR82_WP:1;      /* Write Protect */
         vuint32_t  OPACR82_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR83_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR83_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR83_WP:1;      /* Write Protect */
         vuint32_t  OPACR83_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR84_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR84_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR84_WP:1;      /* Write Protect */
         vuint32_t  OPACR84_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR85_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR85_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR85_WP:1;      /* Write Protect */
         vuint32_t  OPACR85_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR86_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR86_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR86_WP:1;      /* Write Protect */
         vuint32_t  OPACR86_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR87_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR87_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR87_WP:1;      /* Write Protect */
         vuint32_t  OPACR87_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR80_87_32B_tag;

   typedef union {   /* OPACR88_95 - Off-Platform Peripheral Access Control Registers */
      vuint32_t R;
      struct {
         vuint32_t  OPACR88_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR88_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR88_WP:1;      /* Write Protect */
         vuint32_t  OPACR88_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR89_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR89_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR89_WP:1;      /* Write Protect */
         vuint32_t  OPACR89_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR90_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR90_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR90_WP:1;      /* Write Protect */
         vuint32_t  OPACR90_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR91_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR91_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR91_WP:1;      /* Write Protect */
         vuint32_t  OPACR91_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR92_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR92_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR92_WP:1;      /* Write Protect */
         vuint32_t  OPACR92_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR93_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR93_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR93_WP:1;      /* Write Protect */
         vuint32_t  OPACR93_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR94_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR94_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR94_WP:1;      /* Write Protect */
         vuint32_t  OPACR94_TP:1;      /* Trusted Protect */
         vuint32_t  OPACR95_BW:1;      /* Buffer Writes */
         vuint32_t  OPACR95_SP:1;      /* Supervisor Protect */
         vuint32_t  OPACR95_WP:1;      /* Write Protect */
         vuint32_t  OPACR95_TP:1;      /* Trusted Protect */
      } B;
   } AIPS_OPACR88_95_32B_tag;



   typedef struct AIPS_struct_tag { /* start of AIPS_tag */
                                   /* MPROT - Master Privilege Registers */
      AIPS_MPROT_32B_tag MPROT;            /* offset: 0x0000 size: 32 bit */
      int8_t AIPS_reserved_0004[28];
	  /* PACR0_7 - Peripheral Access Control Registers */
      AIPS_PACR0_7_32B_tag PACR0_7;        /* offset: 0x0020 size: 32 bit */
	  /* PACR8_15 - Peripheral Access Control Registers */
      AIPS_PACR8_15_32B_tag PACR8_15;      /* offset: 0x0024 size: 32 bit */
	  /* PACR16_23 - Peripheral Access Control Registers */
      AIPS_PACR16_23_32B_tag PACR16_23;    /* offset: 0x0028 size: 32 bit */
	  /* PACR24_31 - Peripheral Access Control Registers */
      AIPS_PACR24_31_32B_tag PACR24_31;    /* offset: 0x002C size: 32 bit */
      int8_t AIPS_reserved_0030[16];
	  /* OPACR0_7 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR0_7_32B_tag OPACR0_7;      /* offset: 0x0040 size: 32 bit */
	  /* OPACR8_15 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR8_15_32B_tag OPACR8_15;    /* offset: 0x0044 size: 32 bit */
	  /* OPACR16_23 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR16_23_32B_tag OPACR16_23;  /* offset: 0x0048 size: 32 bit */
	  /* OPACR24_31 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR24_31_32B_tag OPACR24_31;  /* offset: 0x004C size: 32 bit */
	  /* OPACR32_39 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR32_39_32B_tag OPACR32_39;  /* offset: 0x0050 size: 32 bit */
	  /* OPACR40_47 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR40_47_32B_tag OPACR40_47;  /* offset: 0x0054 size: 32 bit */
	  /* OPACR48_55 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR48_55_32B_tag OPACR48_55;  /* offset: 0x0058 size: 32 bit */
	  /* OPACR56_63 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR56_63_32B_tag OPACR56_63;  /* offset: 0x005C size: 32 bit */
	  /* OPACR64_71 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR64_71_32B_tag OPACR64_71;  /* offset: 0x0060 size: 32 bit */
	  /* OPACR72_79 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR72_79_32B_tag OPACR72_79;  /* offset: 0x0064 size: 32 bit */
	  /* OPACR80_87 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR80_87_32B_tag OPACR80_87;  /* offset: 0x0068 size: 32 bit */
	  /* OPACR88_95 - Off-Platform Peripheral Access Control Registers */
      AIPS_OPACR88_95_32B_tag OPACR88_95;  /* offset: 0x006C size: 32 bit */
   } AIPS_tag;


/****************************************************************/
/*                                                              */
/* Module: MAX  */
/*                                                              */
/****************************************************************/

   /* Register layout for all registers MPR... */

   typedef union {   /* Master Priority Register for slave port n */
      vuint32_t R;
      struct {
         vuint32_t:1;
         vuint32_t  MSTR_7:3;          /* Master 7 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_6:3;          /* Master 6 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_5:3;          /* Master 5 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_4:3;          /* Master 4 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_3:3;          /* Master 3 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_2:3;          /* Master 2 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_1:3;          /* Master 1 Priority */
         vuint32_t:1;
         vuint32_t  MSTR_0:3;          /* Master 0 Priority */
      } B;
   } MAX_MPR_32B_tag;


   /* Register layout for all registers AMPR matches xxx */


   /* Register layout for all registers SGPCR... */

   typedef union {   /* MAX_SGPCRn - MAX General Purpose Control Register for Slave Port n */
      vuint32_t R;
      struct {
         vuint32_t  RO:1;              /* Read Only */
         vuint32_t  HLP:1;             /* Halt Low Priority */
         vuint32_t:6;
         vuint32_t  HPE7:1;            /* High Priority Enable */
         vuint32_t  HPE6:1;            /* High Priority Enable */
         vuint32_t  HPE5:1;            /* High Priority Enable */
         vuint32_t  HPE4:1;            /* High Priority Enable */
         vuint32_t  HPE3:1;            /* High Priority Enable */
         vuint32_t  HPE2:1;            /* High Priority Enable */
         vuint32_t  HPE1:1;            /* High Priority Enable */
         vuint32_t  HPE0:1;            /* High Priority Enable */
         vuint32_t:6;
         vuint32_t  ARB:2;             /* Arbitration Mode */
         vuint32_t:2;
         vuint32_t  PCTL:2;            /* Parking Control */
         vuint32_t:1;
         vuint32_t  PARK:3;            /* Park */
      } B;
   } MAX_SGPCR_32B_tag;


   /* Register layout for all registers ASGPCR... */

   typedef union {   /* MAX_ASGPCRn - MAX Alternate General Purpose Control Register n */
      vuint32_t R;
      struct {
         vuint32_t:1;
         vuint32_t  HLP:1;             /* Halt Low Priority */
         vuint32_t:6;
         vuint32_t  HPE7:1;            /* High Priority Enable */
         vuint32_t  HPE6:1;            /* High Priority Enable */
         vuint32_t  HPE5:1;            /* High Priority Enable */
         vuint32_t  HPE4:1;            /* High Priority Enable */
         vuint32_t  HPE3:1;            /* High Priority Enable */
         vuint32_t  HPE2:1;            /* High Priority Enable */
         vuint32_t  HPE1:1;            /* High Priority Enable */
         vuint32_t  HPE0:1;            /* High Priority Enable */
         vuint32_t:6;
         vuint32_t  ARB:2;             /* Arbitration Mode */
         vuint32_t:2;
         vuint32_t  PCTL:2;            /* Parking Control */
         vuint32_t:1;
         vuint32_t  PARK:3;            /* Park */
      } B;
   } MAX_ASGPCR_32B_tag;


   /* Register layout for all registers MGPCR... */

   typedef union {   /* MAX_MGPCRn - Master General Purpose Control Register n */
      vuint32_t R;
      struct {
         vuint32_t:29;
         vuint32_t  AULB:3;            /* Arbitrate on Undefined Length Bursts */
      } B;
   } MAX_MGPCR_32B_tag;


   typedef struct MAX_SLAVE_PORT_struct_tag {

	   /* Master Priority Register for slave port n */
	   MAX_MPR_32B_tag MPR;                /* relative offset: 0x0000 */
	   /* Alternate Master Priority Register for slave port n */
	   MAX_MPR_32B_tag AMPR;               /* relative offset: 0x0004 */
	   int8_t MAX_SLAVE_PORT_reserved_0008[8];
	   /* MAX_SGPCRn - MAX General Purpose Control Register for Slave Port n */
	   MAX_SGPCR_32B_tag SGPCR;            /* relative offset: 0x0010 */
       /* MAX_ASGPCRn - MAX Alternate General Purpose Control Register n */
	   MAX_ASGPCR_32B_tag ASGPCR;          /* relative offset: 0x0014 */
	   int8_t MAX_SLAVE_PORT_reserved_0018[232];

   } MAX_SLAVE_PORT_tag;

   typedef struct MAX_MASTER_PORT_struct_tag {

	   /* MAX_MGPCRn - Master General Purpose Control Register n */
	   MAX_MGPCR_32B_tag MGPCR;            /* relative offset: 0x0000 */
	   int8_t MAX_MASTER_PORT_reserved_0004[252];

   } MAX_MASTER_PORT_tag;


   typedef struct MAX_struct_tag { /* start of MAX_tag */
 
	   /*  Register set SLAVE_PORT */
	   MAX_SLAVE_PORT_tag SLAVE_PORT[8];  /* offset: 0x0000  (0x0100 x 8) */

	   /*  Register set MASTER_PORT */
	   MAX_MASTER_PORT_tag MASTER_PORT[8];  /* offset: 0x0800  (0x0100 x 8) */

   } MAX_tag;


/****************************************************************/
/*                                                              */
/* Module: MPU  */
/*                                                              */
/****************************************************************/

   typedef union {   /* MPU_CESR - MPU Control/Error Status Register */
      vuint32_t R;
      struct {
         vuint32_t  SPERR:8;           /* Slave Port n Error */
         vuint32_t:4;
         vuint32_t  HRL:4;             /* Hardware Revision Level */
         vuint32_t  NSP:4;             /* Number of Slave Ports */
         vuint32_t  NRGD:4;            /* Number of Region Descriptors */
         vuint32_t:7;
         vuint32_t  VLD:1;             /* Valid bit */
      } B;
   } MPU_CESR_32B_tag;


   /* Register layout for all registers EAR... */

   typedef union {   /* MPU_EARn - MPU Error Address Register, Slave Port n */
      vuint32_t R;
      struct {
         vuint32_t  EADDR:32;          /* Error Address */
      } B;
   } MPU_EAR_32B_tag;


   /* Register layout for all registers EDR... */

   typedef union {   /* MPU_EDRn - MPU Error Detail Register, Slave Port n */
      vuint32_t R;
      struct {
         vuint32_t  EACD:16;           /* Error Access Control Detail */
         vuint32_t  EPID:8;            /* Error Process Identification */
         vuint32_t  EMN:4;             /* Error Master Number */
         vuint32_t  EATTR:3;           /* Error Attributes */
         vuint32_t  ERW:1;             /* Error Read/Write */
      } B;
   } MPU_EDR_32B_tag;


   /* Register layout for all registers RGD_WORD0... */

   typedef union {   /* MPU_RGDn_Word0 - MPU Region Descriptor */
      vuint32_t R;
      struct {
         vuint32_t  SRTADDR:27;        /* Start Address */
         vuint32_t:5;
      } B;
   } MPU_RGD_WORD0_32B_tag;


   /* Register layout for all registers RGD_WORD1... */

   typedef union {   /* MPU_RGDn_Word1 - MPU Region Descriptor */
      vuint32_t R;
      struct {
         vuint32_t  ENDADDR:27;        /* End Address */
         vuint32_t:5;
      } B;
   } MPU_RGD_WORD1_32B_tag;


   /* Register layout for all registers RGD_WORD2... */

   typedef union {   /* MPU_RGDn_Word2 - MPU Region Descriptor */
      vuint32_t R;
      struct {
         vuint32_t  M7RE:1;            /* Bus Master 7 Read Enable */
         vuint32_t  M7WE:1;            /* Bus Master 7 Write Enable */
         vuint32_t  M6RE:1;            /* Bus Master 6 Read Enable */
         vuint32_t  M6WE:1;            /* Bus Master 7 Write Enable */
         vuint32_t  M5RE:1;            /* Bus Master 5 Read Enable */
         vuint32_t  M5WE:1;            /* Bus Master 5 Write Enable */
         vuint32_t  M4RE:1;            /* Bus Master 4 Read Enable */
         vuint32_t  M4WE:1;            /* Bus Master 4 Write Enable */
         vuint32_t  M3PE:1;            /* Bus Master 3 Process Identifier Enable */
         vuint32_t  M3SM:2;            /* Bus Master 3 Supervisor Mode Access Control */
         vuint32_t  M3UM:3;            /* Bus Master 3 User Mode Access Control */
         vuint32_t  M2PE:1;            /* Bus Master 2 Process Identifier Enable */
         vuint32_t  M2SM:2;            /* Bus Master 2 Supervisor Mode Access Control */
         vuint32_t  M2UM:3;            /* Bus Master 2 User Mode Access Control */
         vuint32_t  M1PE:1;            /* Bus Master 1 Process Identifier Enable */
         vuint32_t  M1SM:2;            /* Bus Master 1 Supervisor Mode Access Control */
         vuint32_t  M1UM:3;            /* Bus Master 1 User Mode Access Control */
         vuint32_t  M0PE:1;            /* Bus Master 0 Process Identifier Enable */
         vuint32_t  M0SM:2;            /* Bus Master 0 Supervisor Mode Access Control */
         vuint32_t  M0UM:3;            /* Bus Master 0 User Mode Access Control */
      } B;
   } MPU_RGD_WORD2_32B_tag;


   /* Register layout for all registers RGD_WORD3... */

   typedef union {   /* MPU_RGDn_Word3 - MPU Region Descriptor */
      vuint32_t R;
      struct {
         vuint32_t  PID:8;             /* Process Identifier */
         vuint32_t  PIDMASK:8;         /* Process Identifier Mask */
         vuint32_t:15;
         vuint32_t  VLD:1;             /* Valid */
      } B;
   } MPU_RGD_WORD3_32B_tag;


   /* Register layout for all registers RGDAAC... */

   typedef union {   /* MPU_RGDAACn -  MPU Region Descriptor Alternate Access Control */
      vuint32_t R;
      struct {
         vuint32_t  M7RE:1;            /* Bus Master 7 Read Enable */
         vuint32_t  M7WE:1;            /* Bus Master 7 Write Enable */
         vuint32_t  M6RE:1;            /* Bus Master 6 Read Enable */
         vuint32_t  M6WE:1;            /* Bus Master 7 Write Enable */
         vuint32_t  M5RE:1;            /* Bus Master 5 Read Enable */
         vuint32_t  M5WE:1;            /* Bus Master 5 Write Enable */
         vuint32_t  M4RE:1;            /* Bus Master 4 Read Enable */
         vuint32_t  M4WE:1;            /* Bus Master 4 Write Enable */
         vuint32_t  M3PE:1;            /* Bus Master 3 Process Identifier Enable */
         vuint32_t  M3SM:2;            /* Bus Master 3 Supervisor Mode Access Control */
         vuint32_t  M3UM:3;            /* Bus Master 3 User Mode Access Control */
         vuint32_t  M2PE:1;            /* Bus Master 2 Process Identifier Enable */
         vuint32_t  M2SM:2;            /* Bus Master 2 Supervisor Mode Access Control */
         vuint32_t  M2UM:3;            /* Bus Master 2 User Mode Access Control */
         vuint32_t  M1PE:1;            /* Bus Master 1 Process Identifier Enable */
         vuint32_t  M1SM:2;            /* Bus Master 1 Supervisor Mode Access Control */
         vuint32_t  M1UM:3;            /* Bus Master 1 User Mode Access Control */
         vuint32_t  M0PE:1;            /* Bus Master 0 Process Identifier Enable */
         vuint32_t  M0SM:2;            /* Bus Master 0 Supervisor Mode Access Control */
         vuint32_t  M0UM:3;            /* Bus Master 0 User Mode Access Control */
      } B;
   } MPU_RGDAAC_32B_tag;


   typedef struct MPU_SLAVE_PORT_struct_tag {

	   /* MPU_EARn - MPU Error Address Register, Slave Port n */
	   MPU_EAR_32B_tag EAR;                /* relative offset: 0x0000 */
	   /* MPU_EDRn - MPU Error Detail Register, Slave Port n */
	   MPU_EDR_32B_tag EDR;                /* relative offset: 0x0004 */

   } MPU_SLAVE_PORT_tag;

   typedef struct MPU_REGION_struct_tag {

	   /* MPU_RGDn_Word0 - MPU Region Descriptor */
	   MPU_RGD_WORD0_32B_tag RGD_WORD0;    /* relative offset: 0x0000 */
	   /* MPU_RGDn_Word1 - MPU Region Descriptor */
	   MPU_RGD_WORD1_32B_tag RGD_WORD1;    /* relative offset: 0x0004 */
	   /* MPU_RGDn_Word2 - MPU Region Descriptor */
	   MPU_RGD_WORD2_32B_tag RGD_WORD2;    /* relative offset: 0x0008 */
	   /* MPU_RGDn_Word3 - MPU Region Descriptor */
	   MPU_RGD_WORD3_32B_tag RGD_WORD3;    /* relative offset: 0x000C */

   } MPU_REGION_tag;


   typedef struct MPU_struct_tag { /* start of MPU_tag */
	   /* MPU_CESR - MPU Control/Error Status Register */
	   MPU_CESR_32B_tag CESR;               /* offset: 0x0000 size: 32 bit */
	   int8_t MPU_reserved_0004_C[12];
	   /*  Register set SLAVE_PORT */
	   MPU_SLAVE_PORT_tag SLAVE_PORT[4];  /* offset: 0x0010  (0x0008 x 4) */

	   int8_t MPU_reserved_0030_C[976];

	   /*  Register set REGION */
	   MPU_REGION_tag REGION[16];        /* offset: 0x0400  (0x0010 x 16) */

	   int8_t MPU_reserved_0500_C[768];

	   /* MPU_RGDAACn -  MPU Region Descriptor Alternate Access Control */
	   MPU_RGDAAC_32B_tag RGDAAC[16];    /* offset: 0x0800  (0x0004 x 16) */

   } MPU_tag;

/****************************************************************/
/*                                                              */
/* Module: SEMA4  */
/*                                                              */
/****************************************************************/

   /* Register layout for all registers GATE... */

   typedef union {   /* SEMA4_GATEn - Semephores Gate Register */
      vuint8_t R;
      struct {
         vuint8_t:6;
         vuint8_t   GTFSM:2;           /* Gate Finite State machine */
      } B;
   } SEMA4_GATE_8B_tag;

   typedef union {   /* SEMA4_CP0INE - Semaphores Processor IRQ Notification Enable */
      vuint16_t R;
      struct {
         vuint16_t  INE:16;            /* Interrupt Request Notification Enable */
      } B;
   } SEMA4_CP0INE_16B_tag;

   typedef union {   /* SEMA4_CP1INE - Semaphores Processor IRQ Notification Enable */
      vuint16_t R;
      struct {
         vuint16_t  INE:16;            /* Interrupt Request Notification Enable */
      } B;
   } SEMA4_CP1INE_16B_tag;

   typedef union {   /* SEMA4_CP0NTF - Semaphores Processor IRQ Notification */
      vuint16_t R;
      struct {
         vuint16_t  GN:16;             /* Gate 0 Notification */
      } B;
   } SEMA4_CP0NTF_16B_tag;

   typedef union {   /* SEMA4_CP1NTF - Semaphores Processor IRQ Notification */
      vuint16_t R;
      struct {
         vuint16_t  GN:16;             /* Gate 1 Notification */
      } B;
   } SEMA4_CP1NTF_16B_tag;

   typedef union {   /* SEMA4_RSTGT -  Semaphores Reset Gate */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  RSTGSM:2;          /* Reset Gate Finite State Machine */
         vuint16_t  RSTGDP:7;          /* Reset Gate Data Pattern */
         vuint16_t  RSTGMS:3;          /* Reset Gate Bus Master */
         vuint16_t  RSTGTN:8;          /* Reset Gate Number */
      } B;
   } SEMA4_RSTGT_16B_tag;

   typedef union {   /* SEMA4_RSTNTF - Semaphores Reset Reset IRQ Notification */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  RSTNSM:2;          /* Reset Gate Finite State Machine */
         vuint16_t  RSTNDP:7;          /* Reset Gate Data Pattern */
         vuint16_t  RSTNMS:3;          /* Reset Gate Bus Master */
         vuint16_t  RSTNTN:8;          /* Reset Gate Number */
      } B;
   } SEMA4_RSTNTF_16B_tag;



   typedef struct SEMA4_struct_tag { /* start of SEMA4_tag */
	   /* SEMA4_GATEn - Semephores Gate Register */
	   SEMA4_GATE_8B_tag GATE[16];       /* offset: 0x0000  (0x0001 x 16) */
	   int8_t SEMA4_reserved_0010[48];
	   /* SEMA4_CP0INE - Semaphores Processor IRQ Notification Enable */
	   SEMA4_CP0INE_16B_tag CP0INE;         /* offset: 0x0040 size: 16 bit */
	   int8_t SEMA4_reserved_0042[6];
	   /* SEMA4_CP1INE - Semaphores Processor IRQ Notification Enable */
	   SEMA4_CP1INE_16B_tag CP1INE;         /* offset: 0x0048 size: 16 bit */
	   int8_t SEMA4_reserved_004A[54];
	   /* SEMA4_CP0NTF - Semaphores Processor IRQ Notification */
	   SEMA4_CP0NTF_16B_tag CP0NTF;         /* offset: 0x0080 size: 16 bit */
	   int8_t SEMA4_reserved_0082[6];
	   /* SEMA4_CP1NTF - Semaphores Processor IRQ Notification */
	   SEMA4_CP1NTF_16B_tag CP1NTF;         /* offset: 0x0088 size: 16 bit */
	   int8_t SEMA4_reserved_008A[118];
	   /* SEMA4_RSTGT -  Semaphores Reset Gate */
	   SEMA4_RSTGT_16B_tag RSTGT;           /* offset: 0x0100 size: 16 bit */
	   int8_t SEMA4_reserved_0102[2];
	   /* SEMA4_RSTNTF - Semaphores Reset Reset IRQ Notification */
	   SEMA4_RSTNTF_16B_tag RSTNTF;         /* offset: 0x0104 size: 16 bit */
   } SEMA4_tag;


/****************************************************************/
/*                                                              */
/* Module: SWT  */
/*                                                              */
/****************************************************************/
   typedef union {   /* SWT_CR - Control Register */
      vuint32_t R;
      struct {
         vuint32_t  MAP0:1;            /* Master Acces Protection for Master 0 */
         vuint32_t  MAP1:1;            /* Master Acces Protection for Master 1 */
         vuint32_t  MAP2:1;            /* Master Acces Protection for Master 2 */
         vuint32_t  MAP3:1;            /* Master Acces Protection for Master 3 */
         vuint32_t  MAP4:1;            /* Master Acces Protection for Master 4 */
         vuint32_t  MAP5:1;            /* Master Acces Protection for Master 5 */
         vuint32_t  MAP6:1;            /* Master Acces Protection for Master 6 */
         vuint32_t  MAP7:1;            /* Master Acces Protection for Master 7 */
         vuint32_t:14;
         vuint32_t  KEY:1;             /* Keyed Service Mode */
         vuint32_t  RIA:1;             /* Reset on Invalid Access */
         vuint32_t  WND:1;             /* Window Mode */
         vuint32_t  ITR:1;             /* Interrupt Then Reset */
         vuint32_t  HLK:1;             /* Hard Lock */
         vuint32_t  SLK:1;             /* Soft Lock */
         vuint32_t  CSL:1;             /* Clock Selection */
         vuint32_t  STP:1;             /* Stop Mode Control */
         vuint32_t  FRZ:1;             /* Debug Mode Control */
         vuint32_t  WEN:1;             /* Watchdog Enabled */
      } B;
   } SWT_CR_32B_tag;

   typedef union {   /* SWT_IR - SWT Interrupt Register */
      vuint32_t R;
      struct {
         vuint32_t:31;
         vuint32_t  TIF:1;             /* Time Out Interrupt Flag */
      } B;
   } SWT_IR_32B_tag;

   typedef union {   /* SWT_TO - SWT Time-Out Register */
      vuint32_t R;
      struct {
         vuint32_t  WTO:32;            /* Watchdog Time Out Period */
      } B;
   } SWT_TO_32B_tag;

   typedef union {   /* SWT_WN - SWT Window Register */
      vuint32_t R;
      struct {
         vuint32_t  WST:32;            /* Watchdog Time Out Period */
      } B;
   } SWT_WN_32B_tag;

   typedef union {   /* SWT_SR - SWT Service Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  WSC:16;            /* Watchdog Service Code */
      } B;
   } SWT_SR_32B_tag;

   typedef union {   /* SWT_CO - SWT Counter Output Register */
      vuint32_t R;
      struct {
         vuint32_t  CNT:32;            /* Watchdog Count */
      } B;
   } SWT_CO_32B_tag;

   typedef union {   /* SWT_SK - SWT Service Key Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  SERVICEKEY:16;     /* Service Key */
      } B;
   } SWT_SK_32B_tag;



   typedef struct SWT_struct_tag { /* start of SWT_tag */
	   /* SWT_CR - Control Register */
	   SWT_CR_32B_tag CR;                   /* offset: 0x0000 size: 32 bit */
	   /* SWT_IR - SWT Interrupt Register */
	   SWT_IR_32B_tag IR;                   /* offset: 0x0004 size: 32 bit */
	   /* SWT_TO - SWT Time-Out Register */
	   SWT_TO_32B_tag TO;                   /* offset: 0x0008 size: 32 bit */
	   /* SWT_WN - SWT Window Register */
	   SWT_WN_32B_tag WN;                   /* offset: 0x000C size: 32 bit */
	   /* SWT_SR - SWT Service Register */
	   SWT_SR_32B_tag SR;                   /* offset: 0x0010 size: 32 bit */
	   /* SWT_CO - SWT Counter Output Register */
	   SWT_CO_32B_tag CO;                   /* offset: 0x0014 size: 32 bit */
	   /* SWT_SK - SWT Service Key Register */
	   SWT_SK_32B_tag SK;                   /* offset: 0x0018 size: 32 bit */
   } SWT_tag;


/****************************************************************/
/*                                                              */
/* Module: STM  */
/*                                                              */
/****************************************************************/

   typedef union {   /* STM_CR - Control Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  CPS:8;             /* Counter Prescaler */
         vuint32_t:6;
         vuint32_t  FRZ:1;             /* Freeze Control */
         vuint32_t  TEN:1;             /* Timer Counter Enabled */
      } B;
   } STM_CR_32B_tag;

   typedef union {   /* STM_CNT - STM Count Register */
      vuint32_t R;
   } STM_CNT_32B_tag;


   /* Register layout for all registers CCR... */

   typedef union {   /* STM_CCRn - STM Channel Control Register */
      vuint32_t R;
      struct {
         vuint32_t:31;
         vuint32_t  CEN:1;             /* Channel Enable */
      } B;
   } STM_CCR_32B_tag;


   /* Register layout for all registers CIR... */

   typedef union {   /* STM_CIRn - STM Channel Interrupt Register */
      vuint32_t R;
      struct {
         vuint32_t:31;
         vuint32_t  CIF:1;             /* Channel Interrupt Flag */
      } B;
   } STM_CIR_32B_tag;


   /* Register layout for all registers CMP... */

   typedef union {   /* STM_CMPn - STM Channel Compare Register */
      vuint32_t R;
   } STM_CMP_32B_tag;


   typedef struct STM_CHANNEL_struct_tag {

	   /* STM_CCRn - STM Channel Control Register */
	   STM_CCR_32B_tag CCR;                /* relative offset: 0x0000 */
	   /* STM_CIRn - STM Channel Interrupt Register */
	   STM_CIR_32B_tag CIR;                /* relative offset: 0x0004 */
	   /* STM_CMPn - STM Channel Compare Register */
	   STM_CMP_32B_tag CMP;                /* relative offset: 0x0008 */
	   int8_t STM_CHANNEL_reserved_000C[4];

   } STM_CHANNEL_tag;


   typedef struct STM_struct_tag { /* start of STM_tag */
	
	   /* STM_CR - Control Register */
	   STM_CR_32B_tag CR0;            /* offset: 0x0000 size: 32 bit */

	   /* STM_CNT - STM Count Register */
	   STM_CNT_32B_tag CNT0;    /* offset: 0x0004 size: 32 bit */


	   int8_t STM_reserved_0008_C[8];

	   /* STM_CCRn - STM Channel Control Register */
	   STM_CCR_32B_tag CCR0;          /* offset: 0x0010 size: 32 bit */
	   /* STM_CIRn - STM Channel Interrupt Register */
	   STM_CIR_32B_tag CIR0;          /* offset: 0x0014 size: 32 bit */
	   /* STM_CMPn - STM Channel Compare Register */
	   STM_CMP_32B_tag CMP0;          /* offset: 0x0018 size: 32 bit */
	   int8_t STM_reserved_001C_I1[4];
	   /* STM_CCRn - STM Channel Control Register */
	   STM_CCR_32B_tag CCR1;          /* offset: 0x0020 size: 32 bit */
	   /* STM_CIRn - STM Channel Interrupt Register */
	   STM_CIR_32B_tag CIR1;          /* offset: 0x0024 size: 32 bit */
	   /* STM_CMPn - STM Channel Compare Register */
	   STM_CMP_32B_tag CMP1;          /* offset: 0x0028 size: 32 bit */
	   int8_t STM_reserved_002C_I1[4];
	   /* STM_CCRn - STM Channel Control Register */
	   STM_CCR_32B_tag CCR2;          /* offset: 0x0030 size: 32 bit */
	   /* STM_CIRn - STM Channel Interrupt Register */
	   STM_CIR_32B_tag CIR2;          /* offset: 0x0034 size: 32 bit */
	   /* STM_CMPn - STM Channel Compare Register */
	   STM_CMP_32B_tag CMP2;          /* offset: 0x0038 size: 32 bit */
	   int8_t STM_reserved_003C_I1[4];
	   /* STM_CCRn - STM Channel Control Register */
	   STM_CCR_32B_tag CCR3;          /* offset: 0x0040 size: 32 bit */
	   /* STM_CIRn - STM Channel Interrupt Register */
	   STM_CIR_32B_tag CIR3;          /* offset: 0x0044 size: 32 bit */
	   /* STM_CMPn - STM Channel Compare Register */
	   STM_CMP_32B_tag CMP3;          /* offset: 0x0048 size: 32 bit */
	   int8_t STM_reserved_004C_E1[4];
   } STM_tag;


/****************************************************************/
/*                                                              */
/* Module: MCM  */
/*                                                              */
/****************************************************************/

   typedef union {   /* SPP_MCM_PCT - Processor Core Type */
      vuint16_t R;
      struct {
         vuint16_t  PCTYPE:16;         /* Processor Core Type */
      } B;
   } SPP_MCM_PCT_16B_tag;

   typedef union {   /* SPP_MCM_PLREV - SOC-Defined Platform Revision */
      vuint16_t R;
      struct {
         vuint16_t  PLREVISION:16;     /* Platform Revision */
      } B;
   } SPP_MCM_PLREV_16B_tag;

   typedef union {   /* SPP_MCM_IOPMC - IPS On-Platform Module Configuration */
      vuint32_t R;
      struct {
         vuint32_t  PMC:32;            /* IPS Module Configuration */
      } B;
   } SPP_MCM_IOPMC_32B_tag;

   typedef union {   /* SPP_MCM_MRSR - Miscellaneous Reset Status Register */
      vuint8_t R;
      struct {
         vuint8_t   POR:1;             /* Power on Reset */
         vuint8_t   DIR:1;             /* Off-Platform Reset */
         vuint8_t:6;
      } B;
   } SPP_MCM_MRSR_8B_tag;

   typedef union {   /* SPP_MCM_MWCR - Miscellaneous Wakeup Control Register */
      vuint8_t R;
      struct {
         vuint8_t   ENBWCR:1;          /* Enable WCR */
         vuint8_t:3;
         vuint8_t   PRILVL:4;          /* Interrupt Priority Level */
      } B;
   } SPP_MCM_MWCR_8B_tag;

   typedef union {   /* SPP_MCM_MIR - Miscellaneous Interrupt Register */
      vuint8_t R;
      struct {
         vuint8_t   FB0AI:1;           /* Flash Bank 0 Abort Interrupt */
         vuint8_t   FB0SI:1;           /* Flash Bank 0 Stall Interrupt */
         vuint8_t   FB1AI:1;           /* Flash Bank 1 Abort Interrupt */
         vuint8_t   FB1SI:1;           /* Flash Bank 1 Stall Interrupt */
         vuint8_t   FB2AI:1;           /* Flash Bank 2 Abort Interrupt */
         vuint8_t   FB2SI:1;           /* Flash Bank 2 Stall Interrupt */
         vuint8_t:2;
      } B;
   } SPP_MCM_MIR_8B_tag;

   typedef union {   /* SPP_MCM_MUDCR - Miscellaneous User Defined Control Register */
      vuint32_t R;
      struct {
         vuint32_t  MUSERDCR:32;       /* User Defined Control Register */
      } B;
   } SPP_MCM_MUDCR_32B_tag;

   typedef union {   /* SPP_MCM_ECR - ECC Configuration Register */
      vuint8_t R;
      struct {
         vuint8_t:2;
         vuint8_t   ER1BR:1;           /* Enable Platform RAM 1-bit Reporting */
         vuint8_t   EF1BR:1;           /* Enable Platform FLASH 1-bit Reporting */
         vuint8_t:2;
         vuint8_t   ERNCR:1;           /* Enable Platform RAM Non-Correctable Reporting */
         vuint8_t   EFNCR:1;           /* Enable Platform FLASH Non-Correctable Reporting */
      } B;
   } SPP_MCM_ECR_8B_tag;

   typedef union {   /* SPP_MCM_ESR - ECC Status Register */
      vuint8_t R;
      struct {
         vuint8_t:2;
         vuint8_t   R1BC:1;            /* Platform RAM 1-bit Correction */
         vuint8_t   F1BC:1;            /* Platform FLASH 1-bit Correction */
         vuint8_t:2;
         vuint8_t   RNCE:1;            /* Platform RAM Non-Correctable Error */
         vuint8_t   FNCE:1;            /* Platform FLASH Non-Correctable Error */
      } B;
   } SPP_MCM_ESR_8B_tag;

   typedef union {   /* SPP_MCM_EEGR - ECC Error Generation Register */
      vuint16_t R;
      struct {
         vuint16_t  FRCAP:1;           /* Force Platform RAM Error Injection Access Protection */
         vuint16_t:1;
         vuint16_t  FRC1BI:1;          /* Force Platform RAM Continuous 1-Bit Data Inversions */
         vuint16_t  FR11BI:1;          /* Force Platform RAM One 1-Bit Data Inversion */
         vuint16_t:2;
         vuint16_t  FRCNCI:1;          /* Force Platform RAM Continuous Noncorrectable Data Inversions */
         vuint16_t  FR1NCI:1;          /* Force Platform RAM One Noncorrectable Data Inversions */
         vuint16_t:1;
         vuint16_t  ERRBIT:7;          /* Error Bit Position */
      } B;
   } SPP_MCM_EEGR_16B_tag;

   typedef union {   /* SPP_MCM_PFEAR - Platform Flash ECC Error Address Register */
      vuint32_t R;
   } SPP_MCM_PFEAR_32B_tag;

   typedef union {   /* SPP_MCM_PFEMR - Platform Flash ECC Master Number Register */
      vuint8_t R;
   } SPP_MCM_PFEMR_8B_tag;

   typedef union {   /* SPP_MCM_PFEAT - Platform Flash ECC Attributes Register */
      vuint8_t R;
      struct {
         vuint8_t   WRITE:1;           /* AMBA-AHBH Write */
         vuint8_t   SIZE:3;            /* AMBA-AHBH Size */
         vuint8_t   PROTECTION:4;      /* AMBA-AHBH PROT */
      } B;
   } SPP_MCM_PFEAT_8B_tag;

   typedef union {   /* SPP_MCM_PFEDRH - Platform Flash ECC Data Register High Word */
      vuint32_t R;
   } SPP_MCM_PFEDRH_32B_tag;

   typedef union {   /* SPP_MCM_PFEDR - Platform Flash ECC Data Register */
      vuint32_t R;
   } SPP_MCM_PFEDR_32B_tag;

   typedef union {   /* SPP_MCM_PREAR - Platform RAM ECC Address Register */
      vuint32_t R;
   } SPP_MCM_PREAR_32B_tag;

   typedef union {   /* SPP_MCM_PRESR - Platform RAM ECC Syndrome Register */
      vuint8_t R;
   } SPP_MCM_PRESR_8B_tag;

   typedef union {   /* SPP_MCM_PREMR - Platform RAM ECC Master Number Register */
      vuint8_t R;
      struct {
         vuint8_t:4;
         vuint8_t   REMR:4;            /* Platform RAM ECC Master Number */
      } B;
   } SPP_MCM_PREMR_8B_tag;

   typedef union {   /* SPP_MCM_PREAT - Platform RAM ECC Attributes Register */
      vuint8_t R;
      struct {
         vuint8_t   WRITE:1;           /* AMBA-AHBH Write */
         vuint8_t   SIZE:3;            /* AMBA-AHBH Size */
         vuint8_t   PROTECTION:4;      /* AMBA-AHBH PROT */
      } B;
   } SPP_MCM_PREAT_8B_tag;

   typedef union {   /* SPP_MCM_PREDR - Platform RAM ECC Data Register High Word */
      vuint32_t R;
   } SPP_MCM_PREDRH_32B_tag;

   typedef union {   /* SPP_MCM_PREDR - Platform RAM ECC Data Register */
      vuint32_t R;
   } SPP_MCM_PREDR_32B_tag;



   typedef struct SPP_MCM_struct_tag { /* start of SPP_MCM_tag */
	   /* SPP_MCM_PCT - Processor Core Type */
	   SPP_MCM_PCT_16B_tag PCT;             /* offset: 0x0000 size: 16 bit */

	   /* SPP_MCM_PLREV - SOC-Defined Platform Revision */
	   SPP_MCM_PLREV_16B_tag REV;      /* offset: 0x0002 size: 16 bit */

	   int8_t SPP_MCM_reserved_0004_C[4];

	   /* SPP_MCM_IOPMC - IPS On-Platform Module Configuration */
	   SPP_MCM_IOPMC_32B_tag MC;      /* offset: 0x0008 size: 32 bit */

	   int8_t SPP_MCM_reserved_000C[3];

	   /* SPP_MCM_MRSR - Miscellaneous Reset Status Register */
	   SPP_MCM_MRSR_8B_tag MRSR;            /* offset: 0x000F size: 8 bit */

	   int8_t SPP_MCM_reserved_0010[3];

	   /* SPP_MCM_MWCR - Miscellaneous Wakeup Control Register */
	   SPP_MCM_MWCR_8B_tag MWCR;            /* offset: 0x0013 size: 8 bit */

	   int8_t SPP_MCM_reserved_0014[11];

	   /* SPP_MCM_MIR - Miscellaneous Interrupt Register */
	   SPP_MCM_MIR_8B_tag MIR;              /* offset: 0x001F size: 8 bit */

	   int8_t SPP_MCM_reserved_0020[4];

	   /* SPP_MCM_MUDCR - Miscellaneous User Defined Control Register */
	   SPP_MCM_MUDCR_32B_tag MUDCR;         /* offset: 0x0024 size: 32 bit */

	   int8_t SPP_MCM_reserved_0028[27];

	   /* SPP_MCM_ECR - ECC Configuration Register */
	   SPP_MCM_ECR_8B_tag ECR;              /* offset: 0x0043 size: 8 bit */

	   int8_t SPP_MCM_reserved_0044[3];

	   /* SPP_MCM_ESR - ECC Status Register */
	   SPP_MCM_ESR_8B_tag ESR;              /* offset: 0x0047 size: 8 bit */

	   int8_t SPP_MCM_reserved_0048[2];

	   /* SPP_MCM_EEGR - ECC Error Generation Register */
	   SPP_MCM_EEGR_16B_tag EEGR;           /* offset: 0x004A size: 16 bit */

	   int8_t SPP_MCM_reserved_004C_C[4];

	   /* SPP_MCM_PFEAR - Platform Flash ECC Error Address Register */
	   SPP_MCM_PFEAR_32B_tag FEAR;      /* offset: 0x0050 size: 32 bit */

	   int8_t SPP_MCM_reserved_0054_C[2];

	   /* SPP_MCM_PFEMR - Platform Flash ECC Master Number Register */
	   SPP_MCM_PFEMR_8B_tag FEMR;       /* offset: 0x0056 size: 8 bit */

	   /* SPP_MCM_PFEAT - Platform Flash ECC Attributes Register */
	   SPP_MCM_PFEAT_8B_tag FEAT;       /* offset: 0x0057 size: 8 bit */

	   /* SPP_MCM_PFEDRH - Platform Flash ECC Data Register High Word */
	   SPP_MCM_PFEDRH_32B_tag PFEDRH;       /* offset: 0x0058 size: 32 bit */

	   /* SPP_MCM_PFEDR - Platform Flash ECC Data Register */
	   SPP_MCM_PFEDR_32B_tag FEDR;      /* offset: 0x005C size: 32 bit */

	   /* SPP_MCM_PREAR - Platform RAM ECC Address Register */
	   SPP_MCM_PREAR_32B_tag REAR;      /* offset: 0x0060 size: 32 bit */

	   int8_t SPP_MCM_reserved_0064_C;

	   /* SPP_MCM_PRESR - Platform RAM ECC Syndrome Register */
	   SPP_MCM_PRESR_8B_tag RESR;       /* offset: 0x0065 size: 8 bit */

	   /* SPP_MCM_PREMR - Platform RAM ECC Master Number Register */
	   SPP_MCM_PREMR_8B_tag REMR;       /* offset: 0x0066 size: 8 bit */

	   /* SPP_MCM_PREAT - Platform RAM ECC Attributes Register */
	   SPP_MCM_PREAT_8B_tag REAT;       /* offset: 0x0067 size: 8 bit */

	   /* SPP_MCM_PREDR - Platform RAM ECC Data Register High Word */

	   SPP_MCM_PREDRH_32B_tag PREDRH;       /* offset: 0x0068 size: 32 bit */

	   /* SPP_MCM_PREDR - Platform RAM ECC Data Register */
	   SPP_MCM_PREDR_32B_tag REDR;      /* offset: 0x006C size: 32 bit */

} SPP_MCM_tag;


/****************************************************************/
/*                                                              */
/* Module: EDMA  */
/*                                                              */
/****************************************************************/

   typedef union {   /* SPP_DMA2_DMACR - DMA Control Register */
      vuint32_t R;
      struct {
         vuint32_t:14;
         vuint32_t  CX:1;              /* Cancel Transfer */
         vuint32_t  ECX:1;             /* Error Cancel Transfer */
         vuint32_t  GRP3PRI:2;         /* Channel Group 3 Priority */
         vuint32_t  GRP2PRI:2;         /* Channel Group 2 Priority */
         vuint32_t  GRP1PRI:2;         /* Channel Group 1 Priority */
         vuint32_t  GRP0PRI:2;         /* Channel Group 0 Priority */
         vuint32_t  EMLM:1;            /* Enable Minor Loop Mapping */
         vuint32_t  CLM:1;             /* Continuous Link Mode */
         vuint32_t  HALT:1;            /* Halt DMA Operations */
         vuint32_t  HOE:1;             /* Halt on Error */
         vuint32_t  ERGA:1;            /* Enable Round Robin Group Arbitration */
         vuint32_t  ERCA:1;            /* Enable Round Robin Channel Arbitration */
         vuint32_t  EDBG:1;            /* Enable Debug */
         vuint32_t  EBW:1;             /* Enable Buffered Writes */
      } B;
   } SPP_DMA2_DMACR_32B_tag;

   typedef union {   /* SPP_DMA2_DMAES - DMA Error Status Register */
      vuint32_t R;
      struct {
         vuint32_t  VLD:1;             /* Logical OR of DMAERRH and DMAERRL status bits */
         vuint32_t:14;
         vuint32_t  ECX:1;             /* Transfer Cancelled */
         vuint32_t  GPE:1;             /* Group Priority Error */
         vuint32_t  CPE:1;             /* Channel Priority Error */
         vuint32_t  ERRCHN:6;          /* Error Channel Number or Cancelled Channel Number */
         vuint32_t  SAE:1;             /* Source Address Error */
         vuint32_t  SOE:1;             /* Source Offset Error */
         vuint32_t  DAE:1;             /* Destination Address Error */
         vuint32_t  DOE:1;             /* Destination Offset Error */
         vuint32_t  NCE:1;             /* Nbytes/Citer Configuration Error */
         vuint32_t  SGE:1;             /* Scatter/Gather Configuration Error */
         vuint32_t  SBE:1;             /* Source Bus Error */
         vuint32_t  DBE:1;             /* Destination Bus Error */
      } B;
   } SPP_DMA2_DMAES_32B_tag;

   typedef union {   /* SPP_DMA2_DMAERQH - DMA Enable Request Register */
      vuint32_t R;
      struct {
         vuint32_t  ERQ:32;            /* DMA Enable Request */
      } B;
   } SPP_DMA2_DMAERQH_32B_tag;

   typedef union {   /* SPP_DMA2_DMAERQL - DMA Enable Request Register */
      vuint32_t R;
	  vuint32_t  ERQ;
      struct {
		  vuint32_t:16;
		  vuint32_t ERQ15:1;
		  vuint32_t ERQ14:1;
		  vuint32_t ERQ13:1;
		  vuint32_t ERQ12:1;
		  vuint32_t ERQ11:1;
		  vuint32_t ERQ10:1;
		  vuint32_t ERQ09:1;
		  vuint32_t ERQ08:1;
		  vuint32_t ERQ07:1;
		  vuint32_t ERQ06:1;
		  vuint32_t ERQ05:1;
		  vuint32_t ERQ04:1;
		  vuint32_t ERQ03:1;
		  vuint32_t ERQ02:1;
		  vuint32_t ERQ01:1;
		  vuint32_t ERQ00:1;
      } B;
   } SPP_DMA2_DMAERQL_32B_tag;

   typedef union {   /* SPP_DMA2_DMAEEIH - DMA Enable Error Interrupt Register */
      vuint32_t R;
      struct {
         vuint32_t  EEI:32;            /* DMA Enable Error Interrupt */
      } B;
   } SPP_DMA2_DMAEEIH_32B_tag;

   typedef union {   /* SPP_DMA2_DMAEEIL - DMA Enable Error Interrupt Register */
      vuint32_t R;
	  vuint32_t  EEI;            /* DMA Enable Error Interrupt */
      struct {
		  vuint32_t :16;
		  vuint32_t EEI15:1;
		  vuint32_t EEI14:1;
		  vuint32_t EEI13:1;
		  vuint32_t EEI12:1;
		  vuint32_t EEI11:1;
		  vuint32_t EEI10:1;
		  vuint32_t EEI09:1;
		  vuint32_t EEI08:1;
		  vuint32_t EEI07:1;
		  vuint32_t EEI06:1;
		  vuint32_t EEI05:1;
		  vuint32_t EEI04:1;
		  vuint32_t EEI03:1;
		  vuint32_t EEI02:1;
		  vuint32_t EEI01:1;
		  vuint32_t EEI00:1;
      } B;
   } SPP_DMA2_DMAEEIL_32B_tag;

   typedef union {   /* SPP_DMA2_DMASERQ - DMA Set Enable Request Register */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   SERQ:7;            /* Set Enable Request */
      } B;
   } SPP_DMA2_DMASERQ_8B_tag;

   typedef union {   /* SPP_DMA2_DMACERQ - DMA Clear Enable Request Register */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   CERQ:7;            /* Clear Enable Request */
      } B;
   } SPP_DMA2_DMACERQ_8B_tag;

   typedef union {   /* SPP_DMA2_DMASEEI - DMA Set Enable Error Interrupt Register */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   SEEI:7;            /* Set Enable Error Interrupt */
      } B;
   } SPP_DMA2_DMASEEI_8B_tag;

   typedef union {   /* SPP_DMA2_DMACEEI - DMA Clear Enable Error Interrupt Register */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   CEEI:7;            /* Clear Enable Error Interrupt */
      } B;
   } SPP_DMA2_DMACEEI_8B_tag;

   typedef union {   /* SPP_DMA2_DMACINT - DMA Clear Interrupt Request */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   CINT:7;            /* Clear Interrupt Request */
      } B;
   } SPP_DMA2_DMACINT_8B_tag;

   typedef union {   /* SPP_DMA2_DMACERR - DMA Clear Error */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   CER:7;            /* Clear Error Indicator */
      } B;
   } SPP_DMA2_DMACERR_8B_tag;

   typedef union {   /* SPP_DMA2_DMASSRT - DMA Set START Bit */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   SSB:7;            /* Set START Bit */
      } B;
   } SPP_DMA2_DMASSRT_8B_tag;

   typedef union {   /* SPP_DMA2_DMACDNE - DMA Clear DONE Status */
      vuint8_t R;
      struct {
         vuint8_t:1;
         vuint8_t   CDSB:7;            /* Clear DONE Status Bit */
      } B;
   } SPP_DMA2_DMACDNE_8B_tag;

   typedef union {   /* SPP_DMA2_DMAINTH - DMA Interrupt Request Register */
      vuint32_t R;
	  vuint32_t  INT:32;            /* DMA Interrupt Request */
      struct {
         vuint32_t :16;            /* DMA Interrupt Request */
	 vuint32_t INT15:1;
	 vuint32_t INT14:1;
	 vuint32_t INT13:1;
	 vuint32_t INT12:1;
	 vuint32_t INT11:1;
	 vuint32_t INT10:1;
	 vuint32_t INT09:1;
	 vuint32_t INT08:1;
	 vuint32_t INT07:1;
	 vuint32_t INT06:1;
	 vuint32_t INT05:1;
	 vuint32_t INT04:1;
	 vuint32_t INT03:1;
	 vuint32_t INT02:1;
	 vuint32_t INT01:1;
	 vuint32_t INT00:1;
      } B;
   } SPP_DMA2_DMAINTH_32B_tag;

   typedef union {   /* SPP_DMA2_DMAINTL - DMA Interrupt Request Register */
      vuint32_t R;
      struct {
         vuint32_t  INT:32;            /* DMA Interrupt Request */
      } B;
   } SPP_DMA2_DMAINTL_32B_tag;

   typedef union {   /* SPP_DMA2_DMAERRH - DMA Error Register */
      vuint32_t R;
      struct {
         vuint32_t  ERR:32;            /* DMA Error n */
      } B;
   } SPP_DMA2_DMAERRH_32B_tag;

   typedef union {   /* SPP_DMA2_DMAERRL - DMA Error Register */
      vuint32_t R;
	  vuint32_t  ERR:32;            /* DMA Error n */
      struct {
		  vuint32_t:16;
		  vuint32_t ERR15:1;
		  vuint32_t ERR14:1;
		  vuint32_t ERR13:1;
		  vuint32_t ERR12:1;
		  vuint32_t ERR11:1;
		  vuint32_t ERR10:1;
		  vuint32_t ERR09:1;
		  vuint32_t ERR08:1;
		  vuint32_t ERR07:1;
		  vuint32_t ERR06:1;
		  vuint32_t ERR05:1;
		  vuint32_t ERR04:1;
		  vuint32_t ERR03:1;
		  vuint32_t ERR02:1;
		  vuint32_t ERR01:1;
		  vuint32_t ERR00:1;
      } B;
   } SPP_DMA2_DMAERRL_32B_tag;

   typedef union {   /* SPP_DMA2_DMAHRSH - DMA Hardware Request Status Register */
      vuint32_t R;
      struct {
         vuint32_t  HRS:32;            /* DMA Hardware Request Status */
      } B;
   } SPP_DMA2_DMAHRSH_32B_tag;

   typedef union {   /* SPP_DMA2_DMAHRSL - DMA Hardware Request Status Register */
      vuint32_t R;
	  vuint32_t  HRS:32;            /* DMA Hardware Request Status */

	  struct {
         vuint32_t :16;
		 vuint32_t HRS15:1;
		 vuint32_t HRS14:1;
		 vuint32_t HRS13:1;
		 vuint32_t HRS12:1;
		 vuint32_t HRS11:1;
		 vuint32_t HRS10:1;
		 vuint32_t HRS09:1;
		 vuint32_t HRS08:1;
		 vuint32_t HRS07:1;
		 vuint32_t HRS06:1;
		 vuint32_t HRS05:1;
		 vuint32_t HRS04:1;
		 vuint32_t HRS03:1;
		 vuint32_t HRS02:1;
		 vuint32_t HRS01:1;
		 vuint32_t HRS00:1;/* DMA Hardware Request Status */
      } B;
   } SPP_DMA2_DMAHRSL_32B_tag;

   typedef union {   /* SPP_DMA2_DMAGPOR - DMA General Purpose Output Register */
      vuint32_t R;
      struct {
         vuint32_t  GPOR:32;           /* DMA General Purpose Output */
      } B;
   } SPP_DMA2_DMAGPOR_32B_tag;


   /* Register layout for all registers DCHPRI... */

   typedef union {   /* SPP_DMA2_DCHPRIn - DMA Channel n Priority */
      vuint8_t R;
      struct {
         vuint8_t   ECP:1;             /* Enable Channel Preemption */
         vuint8_t   DPA:1;             /* Disable Preempt Ability */
         vuint8_t   GRPPRI:2;          /* Channel n Current Group Priority */
         vuint8_t   CHPRI:4;           /* Channel n Arbitration Priority */
      } B;
   } SPP_DMA2_DCHPRI_8B_tag;


   /* Register layout for all registers TCDWORD0_... */
 typedef struct{
	vuint32_t  SADDR;          /* Source Address */
	vuint16_t  SMOD:5;            /* Source Address Modulo */
	vuint16_t  SSIZE:3;           /* Source Data Transfer Size */
	vuint16_t  DMOD:5;            /* Destination Address Module */
	vuint16_t  DSIZE:3;           /* Destination Data Transfer Size */
	vint16_t   SOFF;           /* Source Address Signed Offset */

        //vuint32_t  SMLOE:1;           /* Source Minor Loop Offset Enable */
	//vuint32_t  DMLOE:1;           /* Destination Minor Loop Offset Enable */
	//vuint32_t  MLOFF:20;          /* Minor Loop Offset */
	//vuint32_t  NBYTES:10;         /* Inner Minor byte transfer Count */
	vuint32_t  NBYTES;         /* Inner Minor byte transfer Count */ 

	vuint32_t  SLAST;          /* Last Source Address Adjustment */
	vuint32_t  DADDR;          /* Destination Address */
	vuint16_t  CITERE_LINK:1;    /* Enable Channel to channel linking on minor loop complete */
	vuint16_t  CITERLINKCH:6;    /* Link Channel Number */
	vuint16_t  CITER:9;           /* Current Major Iteration Count */
	vuint16_t  DOFF;           /* Destination
	Address Signed Offset */
	vuint32_t  DLAST_SGA;      /* Last destination address adjustment */
        /*vuint32_t  BITER:16;*/          /* Enable Channel to Channel linking on minor loop complete */
	vuint16_t BITERE_LINK:1;        /* beginning ("major") iteration count */
		vuint16_t BITERLINKCH:6; 
		vuint16_t BITER:9;
        vuint16_t  BWC:2;             /* Bandwidth Control */
        vuint16_t  MAJORLINKCH:6;    /* Link Channel Number */
        vuint16_t  DONE:1;            /* channel done */
        vuint16_t  ACTIVE:1;          /* Channel Active */
        vuint16_t  MAJORE_LINK:1;    /* Enable Channel to Channel Linking on major loop complete */
        vuint16_t  E_SG:1;            /* Enable Scatter/Gather Processing */
        vuint16_t  D_REQ:1;           /* Disable Request */
        vuint16_t  INT_HALF:1;        /* Enable an Interrupt when Major Counter is half complete */
        vuint16_t  INT_MAJ:1;         /* Enable an Interrupt when Major Iteration count completes */
        vuint16_t  START:1;           /* Channel Start */		  
	} EDMA_TCD_STD_tag;


   typedef struct SPP_DMA2_struct_tag { /* start of SPP_DMA2_tag */
	   /* SPP_DMA2_DMACR - DMA Control Register */
	   SPP_DMA2_DMACR_32B_tag CR;        /* offset: 0x0000 size: 32 bit */
	   /* SPP_DMA2_DMAES - DMA Error Status Register */
	   SPP_DMA2_DMAES_32B_tag ESR;        /* offset: 0x0004 size: 32 bit */
	   /* SPP_DMA2_DMAERQH - DMA Enable Request Register */
	   SPP_DMA2_DMAERQH_32B_tag DMAERQH;    /* offset: 0x0008 size: 32 bit */
	   /* SPP_DMA2_DMAERQL - DMA Enable Request Register */
	   SPP_DMA2_DMAERQL_32B_tag ERQRL;    /* offset: 0x000C size: 32 bit */
	   /* SPP_DMA2_DMAEEIH - DMA Enable Error Interrupt Register */
	   SPP_DMA2_DMAEEIH_32B_tag DMAEEIH;    /* offset: 0x0010 size: 32 bit */
	   /* SPP_DMA2_DMAEEIL - DMA Enable Error Interrupt Register */
	   SPP_DMA2_DMAEEIL_32B_tag EEIRL;    /* offset: 0x0014 size: 32 bit */
	   /* SPP_DMA2_DMASERQ - DMA Set Enable Request Register */
	   SPP_DMA2_DMASERQ_8B_tag SERQR;     /* offset: 0x0018 size: 8 bit */
	   /* SPP_DMA2_DMACERQ - DMA Clear Enable Request Register */
	   SPP_DMA2_DMACERQ_8B_tag CERQR;     /* offset: 0x0019 size: 8 bit */
	   /* SPP_DMA2_DMASEEI - DMA Set Enable Error Interrupt Register */
	   SPP_DMA2_DMASEEI_8B_tag SEEIR;     /* offset: 0x001A size: 8 bit */
	   /* SPP_DMA2_DMACEEI - DMA Clear Enable Error Interrupt Register */
	   SPP_DMA2_DMACEEI_8B_tag CEEIR;     /* offset: 0x001B size: 8 bit */
	   /* SPP_DMA2_DMACINT - DMA Clear Interrupt Request */
	   SPP_DMA2_DMACINT_8B_tag CIRQR;     /* offset: 0x001C size: 8 bit */
	   /* SPP_DMA2_DMACERR - DMA Clear Error */
	   SPP_DMA2_DMACERR_8B_tag CERR;     /* offset: 0x001D size: 8 bit */
	   /* SPP_DMA2_DMASSRT - DMA Set START Bit */
	   SPP_DMA2_DMASSRT_8B_tag SSBR;     /* offset: 0x001E size: 8 bit */
	   /* SPP_DMA2_DMACDNE - DMA Clear DONE Status */
	   SPP_DMA2_DMACDNE_8B_tag CDSBR;     /* offset: 0x001F size: 8 bit */
	   /* SPP_DMA2_DMAINTH - DMA Interrupt Request Register */
	   SPP_DMA2_DMAINTH_32B_tag DMAINTH;    /* offset: 0x0020 size: 32 bit */
	   /* SPP_DMA2_DMAINTL - DMA Interrupt Request Register */
	   SPP_DMA2_DMAINTL_32B_tag IRQRL;    /* offset: 0x0024 size: 32 bit */
	   /* SPP_DMA2_DMAERRH - DMA Error Register */
	   SPP_DMA2_DMAERRH_32B_tag DMAERRH;    /* offset: 0x0028 size: 32 bit */
	   /* SPP_DMA2_DMAERRL - DMA Error Register */
	   SPP_DMA2_DMAERRL_32B_tag ERL;    /* offset: 0x002C size: 32 bit */
	   /* SPP_DMA2_DMAHRSH - DMA Hardware Request Status Register */
	   SPP_DMA2_DMAHRSH_32B_tag DMAHRSH;    /* offset: 0x0030 size: 32 bit */
	   /* SPP_DMA2_DMAHRSL - DMA Hardware Request Status Register */
	   SPP_DMA2_DMAHRSL_32B_tag HRSL;    /* offset: 0x0034 size: 32 bit */
	   /* SPP_DMA2_DMAGPOR - DMA General Purpose Output Register */
	   SPP_DMA2_DMAGPOR_32B_tag DMAGPOR;    /* offset: 0x0038 size: 32 bit */
	   int8_t SPP_DMA2_reserved_003C_C[196];

	   /* SPP_DMA2_DCHPRIn - DMA Channel n Priority */
	   SPP_DMA2_DCHPRI_8B_tag CPR[16];  /* offset: 0x0100  (0x0001 x 64) */

	   int8_t SPP_DMA2_reserved_0140_C[3824];

	   /*  Register set CHANNEL */
	   EDMA_TCD_STD_tag TCD[16];  /* offset: 0x1000  (0x0020 x 64) */

     
   } SPP_DMA2_tag;


/****************************************************************/
/*                                                              */
/* Module: INTC  */
/*                                                              */
/****************************************************************/

   typedef union {   /* BCR - Block Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t:18;
         vuint32_t  VTES_PRC1:1;       /* Vector Table Entry Size - Processor 1 */
         vuint32_t:4;
         vuint32_t  HVEN_PRC1:1;       /* Hardware Vector Enable - Processor 1 */
         vuint32_t:2;
         vuint32_t  VTES:1;            /* Vector Table Entry Size - Processor 0 */
         vuint32_t:4;
         vuint32_t  HVEN:1;            /* Hardware Vector Enable - Processor 0 */
      } B;
   } INTC_BCR_32B_tag;

   typedef union {   /* CPR - Current Priority Register - Processor 0 */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  PRI:4;             /* Priority Bits */
      } B;
   } INTC_CPR_PRC0_32B_tag;

   typedef union {   /* CPR - Current Priority Register - Processor 1 */
      vuint32_t R;
      struct {
         vuint32_t:28;
         vuint32_t  PRI:4;             /* Priority Bits */
      } B;
   } INTC_CPR_PRC1_32B_tag;

   typedef union {   /* IACKR- Interrupt Acknowledge Register - Processor 0 */
      vuint32_t R;
      struct {
         vuint32_t  VTBA:21;           /* Vector Table Base Address - Processor 0 */
         vuint32_t  INTVEC:9;          /* Interrupt Vector - Processor 0 */
         vuint32_t:2;
      } B;
   } INTC_IACKR_PRC0_32B_tag;

   typedef union {   /* IACKR- Interrupt Acknowledge Register - Processor 1 */
      vuint32_t R;
      struct {
         vuint32_t  VTBA_PRC1:21;      /* Vector Table Base Address - Processor 1 */
         vuint32_t  INTEC_PRC1:9;      /* Interrupt Vector - Processor 1 */
         vuint32_t:2;
      } B;
   } INTC_IACKR_PRC1_32B_tag;

   typedef union {   /* EOIR- End of Interrupt Register - Processor 0 */
      vuint32_t R;
   } INTC_EOIR_PRC0_32B_tag;

   typedef union {   /* EOIR- End of Interrupt Register - Processor 1 */
      vuint32_t R;
   } INTC_EOIR_PRC1_32B_tag;


   /* Register layout for all registers SSCIR... */

   typedef union {   /* SSCIR0-7 INTC Software Set/Clear Interrupt Registers */
      vuint8_t R;
      struct {
         vuint8_t:6;
         vuint8_t   SET:1;             /* Set Flag bit */
         vuint8_t   CLR:1;             /* Clear Flag bit */
      } B;
   } INTC_SSCIR_8B_tag;

   typedef union {   /* SSCIR0_3 - Software Set/Clear Interrupt Registers */
      vuint32_t R;
      struct {
         vuint32_t:6;
         vuint32_t  SET0:1;            /* Set Flag 0 bit */
         vuint32_t  CLR0:1;            /* Clear Flag 0 bit */
         vuint32_t:6;
         vuint32_t  SET1:1;            /* Set Flag 1 bit */
         vuint32_t  CLR1:1;            /* Clear Flag 1 bit */
         vuint32_t:6;
         vuint32_t  SET2:1;            /* Set Flag 2 bit */
         vuint32_t  CLR2:1;            /* Clear Flag 2 bit */
         vuint32_t:6;
         vuint32_t  SET3:1;            /* Set Flag 3 bit */
         vuint32_t  CLR3:1;            /* Clear Flag 3 bit */
      } B;
   } INTC_SSCIR0_3_32B_tag;

   typedef union {   /* SSCIR4_7 - Software Set/Clear Interrupt Registers */
      vuint32_t R;
      struct {
         vuint32_t:6;
         vuint32_t  SET4:1;            /* Set Flag 4 bit */
         vuint32_t  CLR4:1;            /* Clear Flag 4 bit */
         vuint32_t:6;
         vuint32_t  SET5:1;            /* Set Flag 5 bit */
         vuint32_t  CLR5:1;            /* Clear Flag 5 bit */
         vuint32_t:6;
         vuint32_t  SET6:1;            /* Set Flag 6 bit */
         vuint32_t  CLR6:1;            /* Clear Flag 6 bit */
         vuint32_t:6;
         vuint32_t  SET7:1;            /* Set Flag 7 bit */
         vuint32_t  CLR7:1;            /* Clear Flag 7 bit */
      } B;
   } INTC_SSCIR4_7_32B_tag;


   /* Register layout for all registers PSR... */

   typedef union {   /* PSR0-511 - Priority Select Registers */
      vuint8_t R;
      struct {
         vuint8_t   PRC_SEL:2;         /* Processor Select */
         vuint8_t:2;
         vuint8_t   PRI:4;             /* Priority Select */
      } B;
   } INTC_PSR_8B_tag;


   /* Register layout for all registers PSR... */

   typedef union {   /* PSR0_3 - 508_511 - Priority Select Registers */
      vuint32_t R;
      struct {
         vuint32_t  PRC_SEL0:2;        /* Processor Select - Entry 0 */
         vuint32_t:2;
         vuint32_t  PRI0:4;            /* Priority Select - Entry 0 */
         vuint32_t  PRC_SEL1:2;        /* Processor Select - Entry 1 */
         vuint32_t:2;
         vuint32_t  PRI1:4;            /* Priority Select - Entry 1 */
         vuint32_t  PRC_SEL2:2;        /* Processor Select - Entry 2 */
         vuint32_t:2;
         vuint32_t  PRI2:4;            /* Priority Select - Entry 2 */
         vuint32_t  PRC_SEL3:2;        /* Processor Select - Entry 3 */
         vuint32_t:2;
         vuint32_t  PRI3:4;            /* Priority Select - Entry 3 */
      } B;
   } INTC_PSR_32B_tag;

   typedef struct INTC_struct_tag { /* start of INTC_tag */

	   /* BCR - Block Configuration Register */
	   INTC_BCR_32B_tag MCR;             /* offset: 0x0000 size: 32 bit */

	   int8_t INTC_reserved_0004_C[4];

	   /* CPR - Current Priority Register - Processor 0 */
       INTC_CPR_PRC0_32B_tag CPR;   /* offset: 0x0008 size: 32 bit */

	   /* CPR - Current Priority Register - Processor 1 */
	   INTC_CPR_PRC1_32B_tag CPR_PRC1;      /* offset: 0x000C size: 32 bit */

       /* IACKR- Interrupt Acknowledge Register - Processor 0 */
	   INTC_IACKR_PRC0_32B_tag IACKR;  /* offset: 0x0010 size: 32 bit */


       /* IACKR- Interrupt Acknowledge Register - Processor 1 */
	   INTC_IACKR_PRC1_32B_tag IACKR_PRC1;  /* offset: 0x0014 size: 32 bit */

       /* EOIR- End of Interrupt Register - Processor 0 */
	   INTC_EOIR_PRC0_32B_tag EOIR;  /* offset: 0x0018 size: 32 bit */

       /* EOIR- End of Interrupt Register - Processor 1 */
	   INTC_EOIR_PRC1_32B_tag EOIR_PRC1;    /* offset: 0x001C size: 32 bit */


	   /* SSCIR0-7 INTC Software Set/Clear Interrupt Registers */
	   INTC_SSCIR_8B_tag SSCIR[8];       /* offset: 0x0020  (0x0001 x 8) */

	   int8_t INTC_reserved_0028_C[24];

	   /* PSR0-511 - Priority Select Registers */
       INTC_PSR_8B_tag PSR[512];         /* offset: 0x0040  (0x0001 x 512) */
       
   } INTC_tag;

/****************************************************************/
/*                                                              */
/* Module: DSPI  */
/*                                                              */
/****************************************************************/

   typedef union {   /* MCR - Module Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t  MSTR:1;            /* Master/Slave mode select */
         vuint32_t  CONT_SCKE:1;       /* Continuous SCK Enable */
         vuint32_t  DCONF:2;           /* DSPI Configuration */
         vuint32_t  FRZ:1;             /* Freeze */
         vuint32_t  MTFE:1;            /* Modified Timing Format Enable */
         vuint32_t  PCSSE:1;           /* Peripheral Chip Select Strobe Enable */
         vuint32_t  ROOE:1;            /* Receive FIFO Overflow Overwrite Enable */
         vuint32_t  PCSIS7:1;          /* Peripheral Chip Select 7 Inactive State */
         vuint32_t  PCSIS6:1;          /* Peripheral Chip Select 6 Inactive State */
         vuint32_t  PCSIS5:1;          /* Peripheral Chip Select 5 Inactive State */
         vuint32_t  PCSIS4:1;          /* Peripheral Chip Select 4 Inactive State */
         vuint32_t  PCSIS3:1;          /* Peripheral Chip Select 3 Inactive State */
         vuint32_t  PCSIS2:1;          /* Peripheral Chip Select 2 Inactive State */
         vuint32_t  PCSIS1:1;          /* Peripheral Chip Select 1 Inactive State */
         vuint32_t  PCSIS0:1;          /* Peripheral Chip Select 0 Inactive State */
         vuint32_t  DOZE:1;            /* Doze Enable */
         vuint32_t  MDIS:1;            /* Module Disable */
         vuint32_t  DIS_TXF:1;         /* Disable Transmit FIFO */
         vuint32_t  DIS_RXF:1;         /* Disable Receive FIFO */
         vuint32_t  CLR_TXF:1;         /* Clear TX FIFO */
         vuint32_t  CLR_RXF:1;         /* Clear RX FIFO */
         vuint32_t  SMPL_PT:2;         /* Sample Point */
         vuint32_t:7;
         vuint32_t  HALT:1;            /* Halt */
      } B;
   } DSPI_MCR_32B_tag;

   typedef union {   /* TCR - Transfer Count Register */
      vuint32_t R;
      struct {
         vuint32_t  TCNT:16;           /* SPI Transfer Counter */
         vuint32_t:16;
      } B;
   } DSPI_TCR_32B_tag;


   /* Register layout for all registers CTAR... */

   typedef union {   /* CTAR0-7 - Clock and Transfer Attribute Registers */
      vuint32_t R;
      struct {
         vuint32_t  DBR:1;             /* Double Baud Rate */
         vuint32_t  FMSZ:4;            /* Frame Size */
         vuint32_t  CPOL:1;            /* Clock Polarity */
         vuint32_t  CPHA:1;            /* Clock Phase */
         vuint32_t  LSBFE:1;           /* LSB First Enable */
         vuint32_t  PCSSCK:2;          /* PCS to SCK Delay Prescaler */
         vuint32_t  PASC:2;            /* After SCK Delay Prescaler */
         vuint32_t  PDT:2;             /* Delay after Transfer Prescaler */
         vuint32_t  PBR:2;             /* Baud Rate Prescaler */
         vuint32_t  CSSCK:4;           /* PCS to SCK Delay Scaler */
         vuint32_t  ASC:4;             /* After SCK Delay Scaler */
         vuint32_t  DT:4;              /* Delay after Transfer Scaler */
         vuint32_t  BR:4;              /* Baud Rate Scaler */
      } B;
   } DSPI_CTAR_32B_tag;

   typedef union {   /* SR - Status Register */
      vuint32_t R;
      struct {
         vuint32_t  TCF:1;             /* Transfer Complete Flag */
         vuint32_t  TXRXS:1;           /* TX & RX Status */
         vuint32_t:1;
         vuint32_t  EOQF:1;            /* End of queue Flag */
         vuint32_t  TFUF:1;            /* Transmit FIFO Underflow Flag */
         vuint32_t:1;
         vuint32_t  TFFF:1;            /* Transmit FIFO FIll Flag */
         vuint32_t:5;
         vuint32_t  RFOF:1;            /* Receive FIFO Overflow Flag */
         vuint32_t:1;
         vuint32_t  RFDF:1;            /* Receive FIFO Drain Flag */
         vuint32_t:1;
         vuint32_t  TXCTR:4;           /* TX FIFO Counter */
         vuint32_t  TXNXTPTR:4;        /* Transmit Next Pointer */
         vuint32_t  RXCTR:4;           /* RX FIFO Counter */
         vuint32_t  POPNXTPTR:4;       /* Pop Next Pointer */
      } B;
   } DSPI_SR_32B_tag;

   typedef union {   /* RSER - DMA/Interrupt Request Register */
      vuint32_t R;
      struct {
         vuint32_t  TCFRE:1;           /* Transmission Complete Request Enable */
         vuint32_t:2;
         vuint32_t  EOQFRE:1;          /* DSPI Finished Request Enable */
         vuint32_t  TFUFRE:1;          /* Transmit FIFO Underflow Request Enable */
         vuint32_t:1;
         vuint32_t  TFFFRE:1;          /* Transmit FIFO Fill Request Enable */
         vuint32_t  TFFFDIRS:1;        /* Transmit FIFO Fill DMA or Interrupt Request Select */
         vuint32_t:4;
         vuint32_t  RFOFRE:1;          /* Receive FIFO overflow Request Enable */
         vuint32_t:1;
         vuint32_t  RFDFRE:1;          /* Receive FIFO Drain Request Enable */
         vuint32_t  RFDFDIRS:1;        /* Receive FIFO Drain DMA or Interrupt Request Select */
         vuint32_t:16;
      } B;
   } DSPI_RSER_32B_tag;

   typedef union {   /* PUSHR - PUSH TX FIFO Register */
      vuint32_t R;
      struct {
         vuint32_t  CONT:1;            /* Continuous Peripheral Chip Select Enable */
         vuint32_t  CTAS:3;            /* Clock and Transfer Attributes Select */
         vuint32_t  EOQ:1;             /* End of Queue */
         vuint32_t  CTCNT:1;           /* Clear SPI_TCNT */
         vuint32_t:2;
         vuint32_t  PCS7:1;            /* Peripheral Chip Select 7 */
         vuint32_t  PCS6:1;            /* Peripheral Chip Select 6 */
         vuint32_t  PCS5:1;            /* Peripheral Chip Select 5 */
         vuint32_t  PCS4:1;            /* Peripheral Chip Select 4 */
         vuint32_t  PCS3:1;            /* Peripheral Chip Select 3 */
         vuint32_t  PCS2:1;            /* Peripheral Chip Select 2 */
         vuint32_t  PCS1:1;            /* Peripheral Chip Select 1 */
         vuint32_t  PCS0:1;            /* Peripheral Chip Select 0 */
         vuint32_t  TXDATA:16;         /* Transmit Data */
      } B;
   } DSPI_PUSHR_32B_tag;

   typedef union {   /* POPR - POP RX FIFO Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  RXDATA:16;         /* Receive Data */
      } B;
   } DSPI_POPR_32B_tag;


   /* Register layout for all registers TXFR... */

   typedef union {   /* Transmit FIFO Registers */
      vuint32_t R;
      struct {
         vuint32_t  TXCMD:16;          /* Transmit Command */
         vuint32_t  TXDATA:16;         /* Transmit Data */
      } B;
   } DSPI_TXFR_32B_tag;


   /* Register layout for all registers RXFR... */

   typedef union {   /* Receive FIFO Registers */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  RXDATA:16;           /* deprecated name - please avoid */
      } B;
   } DSPI_RXFR_32B_tag;

   typedef union {   /* DSICR - DSI Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t  MTOE:1;            /* Multiple Transfer Operation Enable */
         vuint32_t:1;
         vuint32_t  MTOCNT:6;          /* Multiple Transfer Operation Count */
         vuint32_t:4;
         vuint32_t  TXSS:1;            /* Transmit Data Source Select */
         vuint32_t  TPOL:1;            /* Trigger Polarity */
         vuint32_t  TRRE:1;            /* Trigger Reception Enable */
         vuint32_t  CID:1;             /* Change in Data Transfer Enable */
         vuint32_t  DCONT:1;           /* DSI Continuous Peripheral Chip Select Enable */
         vuint32_t  DSICTAS:3;         /* DSI CLock and Transfer Attributes Select */
         vuint32_t:4;
         vuint32_t  DPCS7:1;           /* DSI Peripheral Chip Select 7 */
         vuint32_t  DPCS6:1;           /* DSI Peripheral Chip Select 6 */
         vuint32_t  DPCS5:1;           /* DSI Peripheral Chip Select 5 */
         vuint32_t  DPCS4:1;           /* DSI Peripheral Chip Select 4 */
         vuint32_t  DPCS3:1;           /* DSI Peripheral Chip Select 3 */
         vuint32_t  DPCS2:1;           /* DSI Peripheral Chip Select 2 */
         vuint32_t  DPCS1:1;           /* DSI Peripheral Chip Select 1 */
         vuint32_t  DPCS0:1;           /* DSI Peripheral Chip Select 0 */
      } B;
   } DSPI_DSICR_32B_tag;

   typedef union {   /* SDR - DSI Serialization Data Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  SER_DATA:16;       /* Serialized Data */
      } B;
   } DSPI_SDR_32B_tag;

   typedef union {   /* ASDR - DSI Alternate Serialization Data Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  ASER_DATA:16;      /* Alternate Serialized Data */
      } B;
   } DSPI_ASDR_32B_tag;

   typedef union {   /* COMPR - DSI Transmit Comparison Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  COMP_DATA:16;      /* Compare Data */
      } B;
   } DSPI_COMPR_32B_tag;

   typedef union {   /* DDR - DSI Deserialization Data Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  DESER_DATA:16;     /* Deserialized Data */
      } B;
   } DSPI_DDR_32B_tag;

   typedef union {   /* DSICR1 - DSI Configuration Register 1 */
      vuint32_t R;
   } DSPI_DSICR1_32B_tag;



   typedef struct DSPI_struct_tag { /* start of DSPI_tag */
	   /* MCR - Module Configuration Register */
	   DSPI_MCR_32B_tag MCR;                /* offset: 0x0000 size: 32 bit */
	   int8_t DSPI_reserved_0004[4];
	   /* TCR - Transfer Count Register */
	   DSPI_TCR_32B_tag TCR;                /* offset: 0x0008 size: 32 bit */

	   /* CTAR0-7 - Clock and Transfer Attribute Registers */
	   DSPI_CTAR_32B_tag CTAR[8];        /* offset: 0x000C  (0x0004 x 8) */

	   /* SR - Status Register */
	   DSPI_SR_32B_tag SR;                  /* offset: 0x002C size: 32 bit */
	   /* RSER - DMA/Interrupt Request Register */
	   DSPI_RSER_32B_tag RSER;              /* offset: 0x0030 size: 32 bit */
	   /* PUSHR - PUSH TX FIFO Register */
	   DSPI_PUSHR_32B_tag PUSHR;            /* offset: 0x0034 size: 32 bit */
	   /* POPR - POP RX FIFO Register */
	   DSPI_POPR_32B_tag POPR;              /* offset: 0x0038 size: 32 bit */

	   /* Transmit FIFO Registers */
	   DSPI_TXFR_32B_tag TXFR[5];        /* offset: 0x003C  (0x0004 x 5) */


	   int8_t DSPI_reserved_0050_C[44];

	   /* Receive FIFO Registers */
	   DSPI_RXFR_32B_tag RXFR[5];        /* offset: 0x007C  (0x0004 x 5) */

	   int8_t DSPI_reserved_0090[44];
	   /* DSICR - DSI Configuration Register */
	   DSPI_DSICR_32B_tag DSICR;            /* offset: 0x00BC size: 32 bit */
	   /* SDR - DSI Serialization Data Register */
	   DSPI_SDR_32B_tag SDR;                /* offset: 0x00C0 size: 32 bit */
	   /* ASDR - DSI Alternate Serialization Data Register */
	   DSPI_ASDR_32B_tag ASDR;              /* offset: 0x00C4 size: 32 bit */
	   /* COMPR - DSI Transmit Comparison Register */
	   DSPI_COMPR_32B_tag COMPR;            /* offset: 0x00C8 size: 32 bit */
	   /* DDR - DSI Deserialization Data Register */
	   DSPI_DDR_32B_tag DDR;                /* offset: 0x00CC size: 32 bit */
	   /* DSICR1 - DSI Configuration Register 1 */
	   DSPI_DSICR1_32B_tag DSICR1;          /* offset: 0x00D0 size: 32 bit */
   } DSPI_tag;


/****************************************************************/
/*                                                              */
/* Module: FLEXCAN  */
/*                                                              */
/****************************************************************/

   typedef union {   /* MCR - Module Configuration Register */
      vuint32_t R;
      struct {
         vuint32_t  MDIS:1;            /* Module Disable */
         vuint32_t  FRZ:1;             /* Freeze Enable */
         vuint32_t  FEN:1;             /* FIFO Enable */
         vuint32_t  HALT:1;            /* Halt Flexcan */
         vuint32_t  NOTRDY:1;          /* Flexcan Not Ready */
         vuint32_t  WAKMSK:1;          /* Wake Up Interrupt Mask */
         vuint32_t  SOFTRST:1;         /* Soft Reset */
         vuint32_t  FRZACK:1;          /* Freeze Mode Acknowledge */
         vuint32_t  SUPV:1;            /* Supervisor Mode */
         vuint32_t  SLFWAK:1;          /* Self Wake Up */
         vuint32_t  WRNEN:1;           /* Warning Interrupt Enable */
         vuint32_t  LPMACK:1;          /* Low Power Mode Acknowledge */
         vuint32_t  WAKSRC:1;          /* Wake Up Source */
         vuint32_t  DOZE:1;            /* Doze Mode Enable */
         vuint32_t  SRXDIS:1;          /* Self Reception Disable */
         vuint32_t  BCC:1;             /* Backwards Compatibility Configuration */
         vuint32_t:2;
         vuint32_t  LPRIO_EN:1;        /* Local Priority Enable */
         vuint32_t  AEN:1;             /* Abort Enable */
         vuint32_t:2;
         vuint32_t  IDAM:2;            /* ID Acceptance Mode */
         vuint32_t:2;
         vuint32_t  MAXMB:6;           /* Maximum Number of Message Buffers */
      } B;
   } FLEXCAN_MCR_32B_tag;

   typedef union {   /* CTRL -  Control Register */
      vuint32_t R;
      struct {
         vuint32_t  PRESDIV:8;         /* Prescaler Divsion Factor */
         vuint32_t  RJW:2;             /* Resync Jump Width */
         vuint32_t  PSEG1:3;           /* Phase Segment 1 */
         vuint32_t  PSEG2:3;           /* Phase Segment 2 */
         vuint32_t  BOFFMSK:1;         /* Bus Off Mask */
         vuint32_t  ERRMSK:1;          /* Error Mask */
         vuint32_t  CLKSRC:1;          /* CAN Engine Clock Source */
         vuint32_t  LPB:1;             /* Loop Back */
         vuint32_t  TWRNMSK:1;         /* Tx Warning Interrupt Mask */
         vuint32_t  RWRNMSK:1;         /* Rx Warning Interrupt Mask */
         vuint32_t:2;
         vuint32_t  SMP:1;             /* Sampling Mode */
         vuint32_t  BOFFREC:1;         /* Bus Off Recovery Mode */
         vuint32_t  TSYN:1;            /* Timer Sync Mode */
         vuint32_t  LBUF:1;            /* Lowest Buffer Transmitted First */
         vuint32_t  LOM:1;             /* Listen-Only Mode */
         vuint32_t  PROPSEG:3;         /* Propagation Segment */
      } B;
   } FLEXCAN_CTRL_32B_tag;

   typedef union {   /* TIMER - Free Running Timer */
      vuint32_t R;
   } FLEXCAN_TIMER_32B_tag;

   typedef union {   /* RXGMASK - Rx Global Mask Register */
      vuint32_t R;
      struct {
         vuint32_t  MI:32;             
      } B;
   } FLEXCAN_RXGMASK_32B_tag;

   typedef union {   /* RX14MASK - Rx 14 Mask Register */
      vuint32_t R;
      struct {
         vuint32_t  MI:32;             
      } B;
   } FLEXCAN_RX14MASK_32B_tag;

   typedef union {   /* RX15MASK - Rx 15 Mask Register */
      vuint32_t R;
      struct {
         vuint32_t  MI:32;            
      } B;
   } FLEXCAN_RX15MASK_32B_tag;

   typedef union {   /* ECR - Error Counter Register */
      vuint32_t R;
      struct {
         vuint32_t:16;
         vuint32_t  RXECNT:8;           /* Rx Error Counter */
         vuint32_t  TXECNT:8;           /* Tx Error Counter */
      } B;
   } FLEXCAN_ECR_32B_tag;

   typedef union {   /* ESR - Error and Status Register */
      vuint32_t R;
      struct {
         vuint32_t:14;
         vuint32_t  TWRNINT:1;         /* Tx Warning Interrupt Flag */
         vuint32_t  RWRNINT:1;         /* Rx Warning Interrupt Flag */
         vuint32_t  BIT1ERR:1;         /* Bit 1 Error */
         vuint32_t  BIT0ERR:1;         /* Bit 0 Error */
         vuint32_t  ACKERR:1;          /* Acknowledge Error */
         vuint32_t  CRCERR:1;          /* Cyclic Redundancy Check Error */
         vuint32_t  FRMERR:1;          /* Form Error */
         vuint32_t  STFERR:1;          /* Stuffing Error */
         vuint32_t  TXWRN:1;           /* Tx Error Counter */
         vuint32_t  RXWRN:1;           /* Rx Error Counter */
         vuint32_t  IDLE:1;            /* CAN bus Idle State */
         vuint32_t  TXRX:1;            /* Current Flexcan Status */
         vuint32_t  FLTCONF:2;         /* Fault Confinement State */
         vuint32_t:1;
         vuint32_t  BOFFINT:1;         /* Bus Off Interrupt */
         vuint32_t  ERRINT:1;          /* Error Interrupt */
         vuint32_t  WAKINT:1;          /* Wake-Up Interrupt */
      } B;
   } FLEXCAN_ESR_32B_tag;

   typedef union {   /* IMASK2 - Interrupt Masks 2 Register */
      vuint32_t R;
      struct {
         vuint32_t  BUF63M:1;          /* Buffer MB Mask 63 Bit */
         vuint32_t  BUF62M:1;          /* Buffer MB Mask 62 Bit */
         vuint32_t  BUF61M:1;          /* Buffer MB Mask 61 Bit */
         vuint32_t  BUF60M:1;          /* Buffer MB Mask 60 Bit */
         vuint32_t  BUF59M:1;          /* Buffer MB Mask 59 Bit */
         vuint32_t  BUF58M:1;          /* Buffer MB Mask 58 Bit */
         vuint32_t  BUF57M:1;          /* Buffer MB Mask 57 Bit */
         vuint32_t  BUF56M:1;          /* Buffer MB Mask 56 Bit */
         vuint32_t  BUF55M:1;          /* Buffer MB Mask 55 Bit */
         vuint32_t  BUF54M:1;          /* Buffer MB Mask 54 Bit */
         vuint32_t  BUF53M:1;          /* Buffer MB Mask 53 Bit */
         vuint32_t  BUF52M:1;          /* Buffer MB Mask 52 Bit */
         vuint32_t  BUF51M:1;          /* Buffer MB Mask 51 Bit */
         vuint32_t  BUF50M:1;          /* Buffer MB Mask 50 Bit */
         vuint32_t  BUF49M:1;          /* Buffer MB Mask 49 Bit */
         vuint32_t  BUF48M:1;          /* Buffer MB Mask 48 Bit */
         vuint32_t  BUF47M:1;          /* Buffer MB Mask 47 Bit */
         vuint32_t  BUF46M:1;          /* Buffer MB Mask 46 Bit */
         vuint32_t  BUF45M:1;          /* Buffer MB Mask 45 Bit */
         vuint32_t  BUF44M:1;          /* Buffer MB Mask 44 Bit */
         vuint32_t  BUF43M:1;          /* Buffer MB Mask 43 Bit */
         vuint32_t  BUF42M:1;          /* Buffer MB Mask 42 Bit */
         vuint32_t  BUF41M:1;          /* Buffer MB Mask 41 Bit */
         vuint32_t  BUF40M:1;          /* Buffer MB Mask 40 Bit */
         vuint32_t  BUF39M:1;          /* Buffer MB Mask 39 Bit */
         vuint32_t  BUF38M:1;          /* Buffer MB Mask 38 Bit */
         vuint32_t  BUF37M:1;          /* Buffer MB Mask 37 Bit */
         vuint32_t  BUF36M:1;          /* Buffer MB Mask 36 Bit */
         vuint32_t  BUF35M:1;          /* Buffer MB Mask 35 Bit */
         vuint32_t  BUF34M:1;          /* Buffer MB Mask 34 Bit */
         vuint32_t  BUF33M:1;          /* Buffer MB Mask 33 Bit */
         vuint32_t  BUF32M:1;          /* Buffer MB Mask 32 Bit */
      } B;
   } FLEXCAN_IMASK2_32B_tag;

   typedef union {   /* IMASK1 - Interrupt Masks 1 Register */
      vuint32_t R;
      struct {
         vuint32_t  BUF31M:1;          /* Buffer MB Mask 31 Bit */
         vuint32_t  BUF30M:1;          /* Buffer MB Mask 30 Bit */
         vuint32_t  BUF29M:1;          /* Buffer MB Mask 29 Bit */
         vuint32_t  BUF28M:1;          /* Buffer MB Mask 28 Bit */
         vuint32_t  BUF27M:1;          /* Buffer MB Mask 27 Bit */
         vuint32_t  BUF26M:1;          /* Buffer MB Mask 26 Bit */
         vuint32_t  BUF25M:1;          /* Buffer MB Mask 25 Bit */
         vuint32_t  BUF24M:1;          /* Buffer MB Mask 24 Bit */
         vuint32_t  BUF23M:1;          /* Buffer MB Mask 23 Bit */
         vuint32_t  BUF22M:1;          /* Buffer MB Mask 22 Bit */
         vuint32_t  BUF21M:1;          /* Buffer MB Mask 21 Bit */
         vuint32_t  BUF20M:1;          /* Buffer MB Mask 20 Bit */
         vuint32_t  BUF19M:1;          /* Buffer MB Mask 19 Bit */
         vuint32_t  BUF18M:1;          /* Buffer MB Mask 18 Bit */
         vuint32_t  BUF17M:1;          /* Buffer MB Mask 17 Bit */
         vuint32_t  BUF16M:1;          /* Buffer MB Mask 16 Bit */
         vuint32_t  BUF15M:1;          /* Buffer MB Mask 15 Bit */
         vuint32_t  BUF14M:1;          /* Buffer MB Mask 14 Bit */
         vuint32_t  BUF13M:1;          /* Buffer MB Mask 13 Bit */
         vuint32_t  BUF12M:1;          /* Buffer MB Mask 12 Bit */
         vuint32_t  BUF11M:1;          /* Buffer MB Mask 11 Bit */
         vuint32_t  BUF10M:1;          /* Buffer MB Mask 10 Bit */
         vuint32_t  BUF09M:1;          /* Buffer MB Mask 9 Bit */
         vuint32_t  BUF08M:1;          /* Buffer MB Mask 8 Bit */
         vuint32_t  BUF07M:1;          /* Buffer MB Mask 7 Bit */
         vuint32_t  BUF06M:1;          /* Buffer MB Mask 6 Bit */
         vuint32_t  BUF05M:1;          /* Buffer MB Mask 5 Bit */
         vuint32_t  BUF04M:1;          /* Buffer MB Mask 4 Bit */
         vuint32_t  BUF03M:1;          /* Buffer MB Mask 3 Bit */
         vuint32_t  BUF02M:1;          /* Buffer MB Mask 2 Bit */
         vuint32_t  BUF01M:1;          /* Buffer MB Mask 1 Bit */
         vuint32_t  BUF00M:1;          /* Buffer MB Mask 0 Bit */
      } B;
   } FLEXCAN_IMASK1_32B_tag;

   typedef union {   /* IFLAG2 - Interrupt Flags 2 Register */
      vuint32_t R;
      struct {
         vuint32_t  BUF63I:1;          /* Buffer MB Interrupt 63 Bit */
         vuint32_t  BUF62I:1;          /* Buffer MB Interrupt 62 Bit */
         vuint32_t  BUF61I:1;          /* Buffer MB Interrupt 61 Bit */
         vuint32_t  BUF60I:1;          /* Buffer MB Interrupt 60 Bit */
         vuint32_t  BUF59I:1;          /* Buffer MB Interrupt 59 Bit */
         vuint32_t  BUF58I:1;          /* Buffer MB Interrupt 58 Bit */
         vuint32_t  BUF57I:1;          /* Buffer MB Interrupt 57 Bit */
         vuint32_t  BUF56I:1;          /* Buffer MB Interrupt 56 Bit */
         vuint32_t  BUF55I:1;          /* Buffer MB Interrupt 55 Bit */
         vuint32_t  BUF54I:1;          /* Buffer MB Interrupt 54 Bit */
         vuint32_t  BUF53I:1;          /* Buffer MB Interrupt 53 Bit */
         vuint32_t  BUF52I:1;          /* Buffer MB Interrupt 52 Bit */
         vuint32_t  BUF51I:1;          /* Buffer MB Interrupt 51 Bit */
         vuint32_t  BUF50I:1;          /* Buffer MB Interrupt 50 Bit */
         vuint32_t  BUF49I:1;          /* Buffer MB Interrupt 49 Bit */
         vuint32_t  BUF48I:1;          /* Buffer MB Interrupt 48 Bit */
         vuint32_t  BUF47I:1;          /* Buffer MB Interrupt 47 Bit */
         vuint32_t  BUF46I:1;          /* Buffer MB Interrupt 46 Bit */
         vuint32_t  BUF45I:1;          /* Buffer MB Interrupt 45 Bit */
         vuint32_t  BUF44I:1;          /* Buffer MB Interrupt 44 Bit */
         vuint32_t  BUF43I:1;          /* Buffer MB Interrupt 43 Bit */
         vuint32_t  BUF42I:1;          /* Buffer MB Interrupt 42 Bit */
         vuint32_t  BUF41I:1;          /* Buffer MB Interrupt 41 Bit */
         vuint32_t  BUF40I:1;          /* Buffer MB Interrupt 40 Bit */
         vuint32_t  BUF39I:1;          /* Buffer MB Interrupt 39 Bit */
         vuint32_t  BUF38I:1;          /* Buffer MB Interrupt 38 Bit */
         vuint32_t  BUF37I:1;          /* Buffer MB Interrupt 37 Bit */
         vuint32_t  BUF36I:1;          /* Buffer MB Interrupt 36 Bit */
         vuint32_t  BUF35I:1;          /* Buffer MB Interrupt 35 Bit */
         vuint32_t  BUF34I:1;          /* Buffer MB Interrupt 34 Bit */
         vuint32_t  BUF33I:1;          /* Buffer MB Interrupt 33 Bit */
         vuint32_t  BUF32I:1;          /* Buffer MB Interrupt 32 Bit */
      } B;
   } FLEXCAN_IFLAG2_32B_tag;

   typedef union {   /* IFLAG1 - Interrupt Flags 1 Register */
      vuint32_t R;
      struct {
         vuint32_t  BUF31I:1;          /* Buffer MB Interrupt 31 Bit */
         vuint32_t  BUF30I:1;          /* Buffer MB Interrupt 30 Bit */
         vuint32_t  BUF29I:1;          /* Buffer MB Interrupt 29 Bit */
         vuint32_t  BUF28I:1;          /* Buffer MB Interrupt 28 Bit */
         vuint32_t  BUF27I:1;          /* Buffer MB Interrupt 27 Bit */
         vuint32_t  BUF26I:1;          /* Buffer MB Interrupt 26 Bit */
         vuint32_t  BUF25I:1;          /* Buffer MB Interrupt 25 Bit */
         vuint32_t  BUF24I:1;          /* Buffer MB Interrupt 24 Bit */
         vuint32_t  BUF23I:1;          /* Buffer MB Interrupt 23 Bit */
         vuint32_t  BUF22I:1;          /* Buffer MB Interrupt 22 Bit */
         vuint32_t  BUF21I:1;          /* Buffer MB Interrupt 21 Bit */
         vuint32_t  BUF20I:1;          /* Buffer MB Interrupt 20 Bit */
         vuint32_t  BUF19I:1;          /* Buffer MB Interrupt 19 Bit */
         vuint32_t  BUF18I:1;          /* Buffer MB Interrupt 18 Bit */
         vuint32_t  BUF17I:1;          /* Buffer MB Interrupt 17 Bit */
         vuint32_t  BUF16I:1;          /* Buffer MB Interrupt 16 Bit */
         vuint32_t  BUF15I:1;          /* Buffer MB Interrupt 15 Bit */
         vuint32_t  BUF14I:1;          /* Buffer MB Interrupt 14 Bit */
         vuint32_t  BUF13I:1;          /* Buffer MB Interrupt 13 Bit */
         vuint32_t  BUF12I:1;          /* Buffer MB Interrupt 12 Bit */
         vuint32_t  BUF11I:1;          /* Buffer MB Interrupt 11 Bit */
         vuint32_t  BUF10I:1;          /* Buffer MB Interrupt 10 Bit */
         vuint32_t  BUF09I:1;          /* Buffer MB Interrupt 9 Bit */
         vuint32_t  BUF08I:1;          /* Buffer MB Interrupt 8 Bit */
         vuint32_t  BUF07I:1;          /* Buffer MB Interrupt 7 Bit */
         vuint32_t  BUF06I:1;          /* Buffer MB Interrupt 6 Bit */
         vuint32_t  BUF05I:1;          /* Buffer MB Interrupt 5 Bit */
         vuint32_t  BUF04I:1;          /* Buffer MB Interrupt 4 Bit */
         vuint32_t  BUF03I:1;          /* Buffer MB Interrupt 3 Bit */
         vuint32_t  BUF02I:1;          /* Buffer MB Interrupt 2 Bit */
         vuint32_t  BUF01I:1;          /* Buffer MB Interrupt 1 Bit */
         vuint32_t  BUF00I:1;          /* Buffer MB Interrupt 0 Bit */
      } B;
   } FLEXCAN_IFLAG1_32B_tag;


   /* Register layout for all registers MSG_CS... */

   typedef union {   /* Message Buffer Control and Status */
      vuint32_t R;
      struct {
         vuint32_t:4;
         vuint32_t  CODE:4;            /* Message Buffer Code */
         vuint32_t:1;
         vuint32_t  SRR:1;             /* Substitute Remote Request */
         vuint32_t  IDE:1;             /* ID Extended Bit */
         vuint32_t  RTR:1;             /* Remote Transmission Request */
         vuint32_t  LENGTH:4;          /* Length of Data in Bytes */
         vuint32_t  TIMESTAMP:16;      /* Free-Running Counter Time Stamp */
      } B;
   } FLEXCAN_MSG_CS_32B_tag;


   /* Register layout for all registers MSG_ID... */

   typedef union {   /* Message Buffer Identifier Field */
      vuint32_t R;
      struct {
         vuint32_t  PRIO:3;            /* Local Priority */
         vuint32_t STD_ID:11;
         vuint32_t EXT_ID:18;
      } B;
   } FLEXCAN_MSG_ID_32B_tag;


   /* Register layout for all registers MSG_BYTE0_3... */

   typedef union {   /* Message Buffer Data Register */
      vuint32_t R;
      vuint8_t   BYTE[4];    /* individual bytes can be accessed */
      vuint32_t  WORD;       /* individual words can be accessed */
   } FLEXCAN_MSG_DATA_32B_tag;

    typedef union {
            vuint8_t  B[8]; /* Data buffer in Bytes (8 bits) */
            vuint16_t H[4]; /* Data buffer in Half-words (16 bits) */
            vuint32_t W[2]; /* Data buffer in words (32 bits) */
            vuint32_t R[2]; /* Data buffer in words (32 bits) */
   } FLEXCAN_MSG_DATA2_32B_tag;

   /* Register layout for all registers MSG_BYTE4_7 matches xxx */


   /* Register layout for all registers RXIMR... */

   typedef union {   /* FLEXCAN_RXIMR0 - FLEXCAN_RXIMR63 - RX Individual Mask Registers */
      vuint32_t R;
   } FLEXCAN_RXIMR_32B_tag;


   typedef struct FLEXCAN_MB_struct_tag {

	   /* Message Buffer Control and Status */
       FLEXCAN_MSG_CS_32B_tag CS;   /* relative offset: 0x0000 */

	   /* Message Buffer Identifier Field */
	   FLEXCAN_MSG_ID_32B_tag ID;   /* relative offset: 0x0004 */

	   /* Message Buffer Data Register */
	   FLEXCAN_MSG_DATA2_32B_tag DATA;  /* relative offset: 0x000C */

   } FLEXCAN_MB_tag;


   typedef struct FLEXCAN_struct_tag { /* start of FLEXCAN_tag */
	   /* MCR - Module Configuration Register */
	   FLEXCAN_MCR_32B_tag MCR;             /* offset: 0x0000 size: 32 bit */

	   /* CTRL -  Control Register */
	   FLEXCAN_CTRL_32B_tag CR;        /* offset: 0x0004 size: 32 bit */

	   /* TIMER - Free Running Timer */
	   FLEXCAN_TIMER_32B_tag TIMER;         /* offset: 0x0008 size: 32 bit */

	   int8_t FLEXCAN_reserved_000C[4];

	   /* RXGMASK - Rx Global Mask Register */
	   FLEXCAN_RXGMASK_32B_tag RXGMASK;     /* offset: 0x0010 size: 32 bit */
	   /* RX14MASK - Rx 14 Mask Register */
	   FLEXCAN_RX14MASK_32B_tag RX14MASK;   /* offset: 0x0014 size: 32 bit */
	   /* RX15MASK - Rx 15 Mask Register */
	   FLEXCAN_RX15MASK_32B_tag RX15MASK;   /* offset: 0x0018 size: 32 bit */
	   /* ECR - Error Counter Register */
	   FLEXCAN_ECR_32B_tag ECR;             /* offset: 0x001C size: 32 bit */
	   /* ESR - Error and Status Register */
	   FLEXCAN_ESR_32B_tag ESR;             /* offset: 0x0020 size: 32 bit */

	   /* IMASK2 - Interrupt Masks 2 Register */
	   FLEXCAN_IMASK2_32B_tag IMRH;    /* offset: 0x0024 size: 32 bit */

	   /* IMASK1 - Interrupt Masks 1 Register */
	   FLEXCAN_IMASK1_32B_tag IMRL;    /* offset: 0x0028 size: 32 bit */

	   /* IFLAG2 - Interrupt Flags 2 Register */
	   FLEXCAN_IFLAG2_32B_tag IFRH;    /* offset: 0x002C size: 32 bit */

	   /* IFLAG1 - Interrupt Flags 1 Register */
	   FLEXCAN_IFLAG1_32B_tag IFRL;    /* offset: 0x0030 size: 32 bit */

	   int8_t FLEXCAN_reserved_0034_C[76];

	   /*  Alias name for MB */
	   FLEXCAN_MB_tag BUF[64];           /* offset: 0x0080  (0x0010 x 64) */

	   int8_t FLEXCAN_reserved_0480_C[1024];

       /* FLEXCAN_RXIMR0 - FLEXCAN_RXIMR63 - RX Individual Mask Registers */
	   FLEXCAN_RXIMR_32B_tag RXIMR[64];  /* offset: 0x0880  (0x0004 x 64) */

   } FLEXCAN_tag;


/****************************************************************/
/*                                                              */
/* Module: DMA_CH_MUX  */
/*                                                              */
/****************************************************************/


   /* Register layout for all registers CHCONFIG... */

   typedef union {   /* CHCONFIG[0-15] - Channel Configuration Registers */
      vuint8_t R;
      struct {
         vuint8_t   ENBL:1;            /* DMA Channel Enable */
         vuint8_t   TRIG:1;            /* DMA Channel Trigger Enable */
         vuint8_t   SOURCE:6;          /* DMA Channel Source */
      } B;
   } DMA_CH_MUX_CHCONFIG_8B_tag;

   typedef struct DMA_CH_MUX_struct_tag { /* start of DMA_CH_MUX_tag */
 
	   /* CHCONFIG[0-15] - Channel Configuration Registers */
	   DMA_CH_MUX_CHCONFIG_8B_tag CHCONFIG[16];  /* offset: 0x0000  (0x0001 x 16) */

   } DMA_CH_MUX_tag;


/****************************************************************/
/*                                                              */
/* Module: FR  */
/*                                                              */
/****************************************************************/

   typedef union {   /* Module Version Number */
      vuint16_t R;
      struct {
         vuint16_t  CHIVER:8;          /* VERSION NUMBER OF CHI */
         vuint16_t  PEVER:8;           /* VERSION NUMBER OF PE */
      } B;
   } FR_MVR_16B_tag;

   typedef union {   /* Module Configuration Register */
      vuint16_t R;
      struct {
         vuint16_t  MEN:1;             /* Module Enable */
         vuint16_t  SBFF:1;            /* System Bus Failure Freeze */
         vuint16_t  SCMD:1;            /* single channel device mode */
         vuint16_t  CHB:1;             /* Channel B enable */
         vuint16_t  CHA:1;             /* channel A enable */
         vuint16_t  SFFE:1;            /* Sync. frame filter Enable */
         vuint16_t  ECCE:1;            /* ECC Functionlity Enable */
         vuint16_t  TMODER:1;          /* Functional Test mode */
         vuint16_t  FUM:1;             /* FIFO Update Mode */
         vuint16_t  FAM:1;             /* FIFO Address Mode */
         vuint16_t:1;
         vuint16_t  CLKSEL:1;          /* Protocol Engine clock source select */
         vuint16_t  BITRATE:3;        /* Bus bit rate */
         vuint16_t:1;
      } B;
   } FR_MCR_16B_tag;

   typedef union {   /* SYSTEM MEMORY BASE ADD HIGH REG */
      vuint16_t R;
      struct {
         vuint16_t  SMBA_31_16:16;     /* SYS_MEM_BASE_ADDR[31:16] */
      } B;
   } FR_SYMBADHR_16B_tag;

   typedef union {   /* SYSTEM MEMORY BASE ADD LOW  REG */
      vuint16_t R;
      struct {
         vuint16_t  SMBA_15_4:12;      /* SYS_MEM_BASE_ADDR[15:4] */
         vuint16_t:4;
      } B;
   } FR_SYMBADLR_16B_tag;

   typedef union {   /* STROBE SIGNAL CONTROL REGISTER */
      vuint16_t R;
      struct {
         vuint16_t  WMD:1;             /* DEFINES WRITE MODE OF REG */
         vuint16_t:3;
         vuint16_t  SEL:4;             /* STROBE SIGNSL SELECT */
         vuint16_t:3;
         vuint16_t  ENB:1;             /* STROBE SIGNAL ENABLE */
         vuint16_t:2;
         vuint16_t  STBPSEL:2;         /* STROBE PORT SELECT */
      } B;
   } FR_STBSCR_16B_tag;

   typedef union {   /* MESSAGE BUFFER DATA SIZE REGISTER */
      vuint16_t R;
      struct {
         vuint16_t:1;
         vuint16_t  MBSEG2DS:7;        /* MESSAGE BUFFER SEGMENT 2 DATA SIZE */
         vuint16_t:1;
         vuint16_t  MBSEG1DS:7;        /* MESSAGE BUFFER SEGMENT 1 DATA SIZE */
      } B;
   } FR_MBDSR_16B_tag;

   typedef union {   /* MESS. BUFFER SEG. SIZE & UTILISATION REG */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  LAST_MB_SEG1:6;    /* LAST MESS BUFFER IN SEG 1 */
         vuint16_t:2;
         vuint16_t  LAST_MB_UTIL:6;    /* LAST MESSAGE BUFFER UTILISED */
      } B;
   } FR_MBSSUTR_16B_tag;

   typedef union {   /* PE DRAM ACCESS REGISTER */
      vuint16_t R;
      struct {
         vuint16_t  INST:4;            /* PE DRAM ACCESS INSTRUCTION */
         vuint16_t  ADDR:11;           /* PE DRAM ACCESS ADDRESS */
         vuint16_t  DAD:1;             /* PE DRAM ACCESS DONE */
      } B;
   } FR_PEDRAR_16B_tag;

   typedef union {   /* PE DRAM DATA REGISTER */
      vuint16_t R;
      struct {
         vuint16_t  DATA:16;           /* DATA TO BE READ OR WRITTEN */
      } B;
   } FR_PEDRDR_16B_tag;

   typedef union {   /* PROTOCOL OPERATION CONTROL REG */
      vuint16_t R;
      struct {
         vuint16_t  WME:1;             /* WRITE MODE EXTERNAL CORRECTION */
         vuint16_t:3;
         vuint16_t  EOC_AP:2;          /* EXTERNAL OFFSET CORRECTION APPLICATION */
         vuint16_t  ERC_AP:2;          /* EXTERNAL RATE CORRECTION APPLICATION */
         vuint16_t  BSY:1;             /* PROTOCOL CONTROL COMMAND WRITE BUSY */
         vuint16_t:3;
         vuint16_t  POCCMD:4;          /* PROTOCOL CONTROL COMMAND */
      } B;
   } FR_POCR_16B_tag;

   typedef union {   /* GLOBAL INTERRUPT FLAG & ENABLE REG */
      vuint16_t R;
      struct {
         vuint16_t  MIF:1;             /* MODULE INTERRUPT FLAG */
         vuint16_t  PRIF:1;            /* PROTOCOL INTERRUPT FLAG */
         vuint16_t  CHIF:1;            /* CHI INTERRUPT FLAG */
         vuint16_t  WKUPIF:1;          /* WAKEUP INTERRUPT FLAG */
         vuint16_t  FNEBIF:1;          /* RECEIVE FIFO CHANNEL B ALMOST FULL INTERRUPT FLAG */
         vuint16_t  FNEAIF:1;          /* RECEIVE FIFO CHANNEL A ALMOST FULL INTERRUPT FLAG */
         vuint16_t  RBIF:1;            /* RECEIVE MESSAGE BUFFER INTERRUPT FLAG */
         vuint16_t  TBIF:1;            /* TRANSMIT BUFFER INTERRUPT FLAG */
         vuint16_t  MIE:1;             /* MODULE INTERRUPT ENABLE */
         vuint16_t  PRIE:1;            /* PROTOCOL INTERRUPT ENABLE */
         vuint16_t  CHIE:1;            /* CHI INTERRUPT ENABLE */
         vuint16_t  WKUPIE:1;          /* WAKEUP INTERRUPT ENABLE */
         vuint16_t  FNEBIE:1;          /* RECEIVE FIFO CHANNEL B NOT EMPTY INTERRUPT ENABLE */
         vuint16_t  FNEAIE:1;          /* RECEIVE FIFO CHANNEL A NOT EMPTY INTERRUPT ENABLE */
         vuint16_t  RBIE:1;            /* RECEIVE BUFFER INTERRUPT ENABLE */
         vuint16_t  TBIE:1;            /* TRANSMIT BUFFER INTERRUPT ENABLE */
      } B;
   } FR_GIFER_16B_tag;

   typedef union {   /* PROTOCOL INTERRUPT FLAG REGISTER 0 */
      vuint16_t R;
      struct {
         vuint16_t  FATLIF:1;          /* FATAL PROTOCOL ERROR INTERRUPT FLAG */
         vuint16_t  INTLIF:1;          /* INTERNAL PROTOCOL ERROR INTERRUPT FLAG */
         vuint16_t  ILCFIF:1;          /* ILLEGAL PROTOCOL CONFIGURATION INTERRUPT FLAG */
         vuint16_t  CSAIF:1;           /* COLDSTART ABORT INTERRUPT FLAG */
         vuint16_t  MRCIF:1;           /* MISSING RATE CORRECTION INTERRUPT FLAG */
         vuint16_t  MOCIF:1;           /* MISSING OFFSET CORRECTION INTERRUPT FLAG */
         vuint16_t  CCLIF:1;           /* CLOCK CORRECTION LIMIT REACHED INTERRUPT FLAG */
         vuint16_t  MXSIF:1;           /* MAX SYNC FRAMES DETECTED INTERRUPT FLAG */
         vuint16_t  MTXIF:1;           /* MEDIA ACCESS TEST SYMBOL RECEIVED INTERRUPT FLAG */
         vuint16_t  LTXBIF:1;          /* pLATESTTX VIOLATION ON CHANNEL B INTERRUPT FLAG */
         vuint16_t  LTXAIF:1;          /* pLATESTTX VIOLATION ON CHANNEL A INTERRUPT FLAG */
         vuint16_t  TBVBIF:1;          /* TRANSMISSION ACROSS BOUNDARY ON CHANNEL B INTERRUPT FLAG */
         vuint16_t  TBVAIF:1;          /* TRANSMISSION ACROSS BOUNDARY ON CHANNEL A INTERRUPT FLAG */
         vuint16_t  TI2IF:1;           /* TIMER 2 EXPIRED INTERRUPT FLAG */
         vuint16_t  TI1IF:1;           /* TIMER 1 EXPIRED INTERRUPT FLAG */
         vuint16_t  CYSIF:1;           /* CYCLE START INTERRUPT FLAG */
      } B;
   } FR_PIFR0_16B_tag;

   typedef union {   /* PROTOCOL INTERRUPT FLAG REGISTER 1 */
      vuint16_t R;
      struct {
         vuint16_t  EMCIF:1;           /* ERROR MODE CHANGED INTERRUPT FLAG */
         vuint16_t  IPCIF:1;           /* ILLEGAL PROTOCOL CONTROL COMMAND INTERRUPT FLAG */
         vuint16_t  PECFIF:1;          /* PROTOCOL ENGINE COMMUNICATION FAILURE INTERRUPT FLAG */
         vuint16_t  PSCIF:1;           /* PROTOCOL STATE CHANGED INTERRUPT FLAG */
         vuint16_t  SSI3IF:1;          /* SLOT STATUS COUNTER 3 INCREMENTED INTERRUPT FLAG */
         vuint16_t  SSI2IF:1;          /* SLOT STATUS COUNTER 2 INCREMENTED INTERRUPT FLAG */
         vuint16_t  SSI1IF:1;          /* SLOT STATUS COUNTER 1 INCREMENTED INTERRUPT FLAG */
         vuint16_t  SSI0IF:1;          /* SLOT STATUS COUNTER 0 INCREMENTED INTERRUPT FLAG */
         vuint16_t:2;
         vuint16_t  EVTIF:1;           /* EVEN CYCLE TABLE WRITTEN INTERRUPT FLAG */
         vuint16_t  ODTIF:1;           /* ODD CYCLE TABLE WRITTEN INTERRUPT FLAG */
         vuint16_t:4;
      } B;
   } FR_PIFR1_16B_tag;

   typedef union {   /* PROTOCOL INTERRUPT ENABLE REGISTER 0 */
      vuint16_t R;
      struct {
         vuint16_t  FATLIE:1;          /* FATAL PROTOCOL ERROR INTERRUPT ENABLE */
         vuint16_t  INTLIE:1;          /* INTERNAL PROTOCOL ERROR INTERRUPT ENABLE */
         vuint16_t  ILCFIE:1;          /* ILLEGAL PROTOCOL CONFIGURATION INTERRUPT ENABLE */
         vuint16_t  CSAIE:1;           /* COLDSTART ABORT INTERRUPT ENABLE */
         vuint16_t  MRCIE:1;           /* MISSING RATE CORRECTION INTERRUPT ENABLE */
         vuint16_t  MOCIE:1;           /* MISSING OFFSET CORRECTION INTERRUPT ENABLE */
         vuint16_t  CCLIE:1;           /* CLOCK CORRECTION LIMIT REACHED */
         vuint16_t  MXSIE:1;           /* MAX SYNC FRAMES DETECTED INTERRUPT ENABLE */
         vuint16_t  MTXIE:1;           /* MEDIA ACCESS TEST SYMBOL RECEIVED INTERRUPT ENABLE */
         vuint16_t  LTXBIE:1;          /* pLATESTTX VIOLATION ON CHANNEL B INTERRUPT ENABLE */
         vuint16_t  LTXAIE:1;          /* pLATESTTX VIOLATION ON CHANNEL A INTERRUPT ENABLE */
         vuint16_t  TBVBIE:1;          /* TRANSMISSION ACROSS BOUNDARY ON CHANNEL B INTERRUPT ENABLE */
         vuint16_t  TBVAIE:1;          /* TRANS
										  MISSION ACROSS BOUNDARY ON CHANNEL A INTERRUPT ENABLE */
         vuint16_t  TI2IE:1;           /* TIMER 2 EXPIRED INTERRUPT ENABLE */
         vuint16_t  TI1IE:1;           /* TIMER 1 EXPIRED INTERRUPT ENABLE */
         vuint16_t  CYSIE:1;           /* CYCLE START INTERRUPT ENABLE */
      } B;
   } FR_PIER0_16B_tag;

   typedef union {   /* PROTOCOL INTERRUPT ENABLE REGISTER 1 */
      vuint16_t R;
      struct {
         vuint16_t  EMCIE:1;           /* ERROR MODE CHANGED INTERRUPT Enable */
         vuint16_t  IPCIE:1;           /* ILLEGAL PROTOCOL CONTROL COMMAND INTERRUPT Enable */
         vuint16_t  PECFIE:1;          /* PROTOCOL ENGINE COMMUNICATION FAILURE INTERRUPT Enable */
         vuint16_t  PSCIE:1;           /* PROTOCOL STATE CHANGED INTERRUPT Enable */
         vuint16_t  SSI3IE:1;
         vuint16_t  SSI2IE:1;
         vuint16_t  SSI1IE:1;
         vuint16_t  SSI0IE:1;
         vuint16_t:2;
         vuint16_t  EVTIE:1;           /* EVEN CYCLE TABLE WRITTEN INTERRUPT Enable */
         vuint16_t  ODTIE:1;           /* ODD CYCLE TABLE WRITTEN INTERRUPT Enable */
         vuint16_t:4;
      } B;
   } FR_PIER1_16B_tag;

   typedef union {   /* CHI ERROR FLAG REGISTER */
      vuint16_t R;
      struct {
         vuint16_t  FRLBEF:1;          /* FRAME LOST CHANNEL B ERROR FLAG */
         vuint16_t  FRLAEF:1;          /* FRAME LOST CHANNEL A ERROR FLAG */
         vuint16_t  PCMIEF:1;          /* PROTOCOL COMMAND IGNORED ERROR FLAG */
         vuint16_t  FOVBEF:1;          /* RECEIVE FIFO OVERRUN CHANNEL B ERROR FLAG */
         vuint16_t  FOVAEF:1;          /* RECEIVE FIFO OVERRUN CHANNEL A ERROR FLAG */
         vuint16_t  MSBEF:1;           /* MESSAGE BUFFER SEARCH ERROR FLAG */
         vuint16_t  MBUEF:1;           /* MESSAGE BUFFER UTILIZATION ERROR FLAG */
         vuint16_t  LCKEF:1;           /* LOCK ERROR FLAG */
         vuint16_t  DBLEF:1;           /* DOUBLE TRANSMIT MESSAGE BUFFER LOCK ERROR FLAG */
         vuint16_t  SBCFEF:1;          /* SYSTEM BUS COMMUNICATION FAILURE ERROR FLAG */
         vuint16_t  FIDEF:1;           /* FRAME ID ERROR FLAG */
         vuint16_t  DPLEF:1;           /* DYNAMIC PAYLOAD LENGTH ERROR FLAG */
         vuint16_t  SPLEF:1;           /* STATIC PAYLOAD LENGTH ERROR FLAG */
         vuint16_t  NMLEF:1;           /* NETWORK MANAGEMENT LENGTH ERROR FLAG */
         vuint16_t  NMFEF:1;           /* NETWORK MANAGEMENT FRAME ERROR FLAG */
         vuint16_t  ILSAEF:1;          /* ILLEGAL SYSTEM MEMORY ACCESS ERROR FLAG */
      } B;
   } FR_CHIERFR_16B_tag;

   typedef union {   /* Message Buffer Interrupt Vector Register */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  TBIVEC:6;          /* Transmit Buffer Interrupt Vector */
         vuint16_t:2;
         vuint16_t  RBIVEC:6;          /* Receive Buffer Interrupt Vector */
      } B;
   } FR_MBIVEC_16B_tag;

   typedef union {   /* Channel A Status Error Counter Register */
      vuint16_t R;
      struct {
         vuint16_t  STATUS_ERR_CNT:16;   /* Channel Status Error Counter */
      } B;
   } FR_CASERCR_16B_tag;

   typedef union {   /* Channel B Status Error Counter Register */
      vuint16_t R;
      struct {
         vuint16_t  STATUS_ERR_CNT:16;   /* Channel Status Error Counter */
      } B;
   } FR_CBSERCR_16B_tag;

   typedef union {   /* Protocol Status Register 0 */
      vuint16_t R;
      struct {
         vuint16_t  ERRMODE:2;         /* Error Mode */
         vuint16_t  SLOTMODE:2;        /* Slot Mode */
         vuint16_t:1;
         vuint16_t  PROTSTATE:3;       /* Protocol State */
         vuint16_t  SUBSTATE:4;        /* Startup State */
         vuint16_t  WAKEUPSTATE:4;     /* Wakeup Status */
      } B;
   } FR_PSR0_16B_tag;

   typedef union {   /* Protocol Status Register 1 */
      vuint16_t R;
      struct {
         vuint16_t  CSAA:1;            /* Coldstart Attempt Aborted Flag */
         vuint16_t  CSP:1;             /* Leading Coldstart Path */
         vuint16_t:1;
         vuint16_t  REMCSAT:5;         /* Remaining Coldstart Attempts */
         vuint16_t  CPN:1;             /* Leading Coldstart Path Noise */
         vuint16_t  HHR:1;             /* Host Halt Request Pending */
         vuint16_t  FRZ:1;             /* Freeze Occurred */
         vuint16_t  APTAC:5;           /* Allow Passive to Active Counter */
      } B;
   } FR_PSR1_16B_tag;

   typedef union {   /* Protocol Status Register 2 */
      vuint16_t R;
      struct {
         vuint16_t  NBVB:1;            /* NIT Boundary Violation on Channel B */
         vuint16_t  NSEB:1;            /* NIT Syntax Error on Channel B */
         vuint16_t  STCB:1;            /* Symbol Window Transmit Conflict on Channel B */
         vuint16_t  SBVB:1;            /* Symbol Window Boundary Violation on Channel B */
         vuint16_t  SSEB:1;            /* Symbol Window Syntax Error on Channel B */
         vuint16_t  MTB:1;             /* Media Access Test Symbol MTS Received on Channel B */
         vuint16_t  NBVA:1;            /* NIT Boundary Violation on Channel A */
         vuint16_t  NSEA:1;            /* NIT Syntax Error on Channel A */
         vuint16_t  STCA:1;            /* Symbol Window Transmit Conflict on Channel A */
         vuint16_t  SBVA:1;            /* Symbol Window Boundary Violation on Channel A */
         vuint16_t  SSEA:1;            /* Symbol Window Syntax Error on Channel A */
         vuint16_t  MTA:1;             /* Media Access Test Symbol MTS Received on Channel A */
         vuint16_t  CLKCORRFAILCNT:4;   /* Clock Correction Failed Counter */
      } B;
   } FR_PSR2_16B_tag;

   typedef union {   /* Protocol Status Register 3 */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  WUB:1;             /* Wakeup Symbol Received on Channel B */
         vuint16_t  ABVB:1;            /* Aggregated Boundary Violation on Channel B */
         vuint16_t  AACB:1;            /* Aggregated Additional Communication on Channel B */
         vuint16_t  ACEB:1;            /* Aggregated Content Error on Channel B */
         vuint16_t  ASEB:1;            /* Aggregated Syntax Error on Channel B */
         vuint16_t  AVFB:1;            /* Aggregated Valid Frame on Channel B */
         vuint16_t:2;
         vuint16_t  WUA:1;             /* Wakeup Symbol Received on Channel A */
         vuint16_t  ABVA:1;            /* Aggregated Boundary Violation on Channel A */
         vuint16_t  AACA:1;            /* Aggregated Additional Communication on Channel A */
         vuint16_t  ACEA:1;            /* Aggregated Content Error on Channel A */
         vuint16_t  ASEA:1;            /* Aggregated Syntax Error on Channel A */
         vuint16_t  AVFA:1;            /* Aggregated Valid Frame on Channel A */
      } B;
   } FR_PSR3_16B_tag;

   typedef union {   /* Macrotick Counter Register */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  MTCT:14;           /* Macrotick Counter */
      } B;
   } FR_MTCTR_16B_tag;

   typedef union {   /* Cycle Counter Register */
      vuint16_t R;
      struct {
         vuint16_t:10;
         vuint16_t  CYCCNT:6;          /* Cycle Counter */
      } B;
   } FR_CYCTR_16B_tag;

   typedef union {   /* Slot Counter Channel A Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  SLOTCNTA:11;       /* Slot Counter Value for Channel A */
      } B;
   } FR_SLTCTAR_16B_tag;

   typedef union {   /* Slot Counter Channel B Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  SLOTCNTB:11;       /* Slot Counter Value for Channel B */
      } B;
   } FR_SLTCTBR_16B_tag;

   typedef union {   /* Rate Correction Value Register */
      vuint16_t R;
      struct {
         vuint16_t  RATECORR:16;       /* Rate Correction Value */
      } B;
   } FR_RTCORVR_16B_tag;

   typedef union {   /* Offset Correction Value Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  OFFSETCORR:10;     /* Offset Correction Value */
      } B;
   } FR_OFCORVR_16B_tag;

   typedef union {   /* Combined Interrupt Flag Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  MIFR:1;             /* Module Interrupt Flag */
         vuint16_t  PRIFR:1;            /* Protocol Interrupt Flag */
         vuint16_t  CHIFR:1;           /* CHI Interrupt Flag */
         vuint16_t  WUPIFR:1;          /* Wakeup Interrupt Flag */
         vuint16_t  FNEBIFR:1;         /* Receive FIFO channel B Almost Full Interrupt Flag */
         vuint16_t  FNEAIFR:1;          /* Receive FIFO channel A Almost Full Interrupt Flag */
         vuint16_t  RBIFR:1;           /* Receive Message Buffer Interrupt Flag */
         vuint16_t  TBIFR:1;           /* Transmit Message Buffer Interrupt Flag */
      } B;
   } FR_CIFR_16B_tag;

   typedef union {   /* System Memory Access Time-Out Register */
      vuint16_t R;
      struct {
         vuint16_t:8;
         vuint16_t  TIMEOUT:8;         /* Time-Out */
      } B;
   } FR_SYMATOR_16B_tag;

   typedef union {   /* Sync Frame Counter Register */
      vuint16_t R;
      struct {
         vuint16_t  SFEVB:4;           /* Sync Frames Channel B, even cycle */
         vuint16_t  SFEVA:4;           /* Sync Frames Channel A, even cycle */
         vuint16_t  SFODB:4;           /* Sync Frames Channel B, odd cycle */
         vuint16_t  SFODA:4;           /* Sync Frames Channel A, odd cycle */
      } B;
   } FR_SFCNTR_16B_tag;

   typedef union {   /* Sync Frame Table Offset Register */
      vuint16_t R;
      struct {
         vuint16_t  SFT_OFFSET_15_1:15;   /* Sync Frame Table Offset */
         vuint16_t:1;
      } B;
   } FR_SFTOR_16B_tag;

   typedef union {   /* Sync Frame Table Configuration, Control, Status Register */
      vuint16_t R;
      struct {
         vuint16_t  ELKT:1;            /* Even Cycle Tables Lock/Unlock Trigger */
         vuint16_t  OLKT:1;            /* Odd Cycle Tables Lock/Unlock Trigger */
         vuint16_t  CYCNUM:6;          /* Cycle Number */
         vuint16_t  ELKS:1;            /* Even Cycle Tables Lock Status */
         vuint16_t  OLKS:1;            /* Odd Cycle Tables Lock Status */
         vuint16_t  EVAL:1;            /* Even Cycle Tables Valid */
         vuint16_t  OVAL:1;            /* Odd Cycle Tables Valid */
         vuint16_t:1;
         vuint16_t  OPT:1;             /* One Pair Trigger */
         vuint16_t  SDVEN:1;           /* Sync Frame Deviation Table Enable */
         vuint16_t  SIDEN:1;           /* Sync Frame ID Table Enable */
      } B;
   } FR_SFTCCSR_16B_tag;

   typedef union {   /* Sync Frame ID Rejection Filter */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  SYNFRID:10;        /* Sync Frame Rejection ID */
      } B;
   } FR_SFIDRFR_16B_tag;

   typedef union {   /* Sync Frame ID Acceptance Filter Value Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  FVAL:10;           /* Filter Value */
      } B;
   } FR_SFIDAFVR_16B_tag;

   typedef union {   /* Sync Frame ID Acceptance Filter Mask Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  FMSK:10;           /* Filter Mask */
      } B;
   } FR_SFIDAFMR_16B_tag;


   typedef union {   /* Network Management Vector Length Register */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  NMVL:4;            /* Network Management Vector Length */
      } B;
   } FR_NMVLR_16B_tag;

   typedef union {   /* Timer Configuration and Control Register */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  T2CFG:1;          /* Timer T2 Configuration */
         vuint16_t  T2REP:1;          /* Timer T2 Configuration */
         vuint16_t:1;
         vuint16_t  T2SP:1;            /* Timer T2 Stop */
         vuint16_t  T2TR:1;            /* Timer T2 Trigger */
         vuint16_t  T2ST:1;            /* Timer T2 State */
         vuint16_t:3;
         vuint16_t  T1REP:1;          /* Timer T1 Repetitive Mode */
         vuint16_t:1;
         vuint16_t  T1SP:1;            /* Timer T1 Stop */
         vuint16_t  T1TR:1;            /* Timer T1 Trigger */
         vuint16_t  T1ST:1;            /* Timer T1 State */
      } B;
   } FR_TICCR_16B_tag;

   typedef union {   /* Timer 1 Cycle Set Register */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  TI1CYCVAL:1;        /* Timer T1 Cycle Filter Value */       
         vuint16_t:2;
         vuint16_t  TI1CYCMSK:1;      /* Timer T1 Cycle Filter Mask */
      } B;
   } FR_TI1CYSR_16B_tag;

   typedef union {   /* Timer 1 Macrotick Offset Register */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  T1_MTOFFSET:14;    /* Timer 1 Macrotick Offset */
      } B;
   } FR_TI1MTOR_16B_tag;

   typedef union {   /* Timer 2 Configuration Register 0 */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  T2_CYC_VAL:6;      /* Timer T2 Cycle Filter Value */
         vuint16_t:2;
         vuint16_t  T2_CYC_MSK:6;      /* Timer T2 Cycle Filter Mask */
      } B;
   } FR_TI2CR0_16B_tag;

   typedef union {   /* Timer 2 Configuration Register 1 */
      vuint16_t R;
      struct {
         vuint16_t  T2_MTCNT:16;       /* Timer T2 Macrotick Offset */
      } B;
   } FR_TI2CR1_16B_tag;

   typedef union {   /* Slot Status Selection Register */
      vuint16_t R;
      struct {
         vuint16_t  WMD:1;             /* Write Mode */
         vuint16_t:1;
         vuint16_t  SEL:2;             /* Selector */
         vuint16_t:1;
         vuint16_t  SLOTNUMBER:11;     /* Slot Number */
      } B;
   } FR_SSSR_16B_tag;

   typedef union {   /* Slot Status Counter Condition Register */
      vuint16_t R;
      struct {
         vuint16_t  WMD:1;             /* Write Mode */
         vuint16_t:1;
         vuint16_t  SEL:2;             /* Selector */
         vuint16_t:1;
         vuint16_t  CNTCFG:2;          /* Counter Configuration */
         vuint16_t  MCY:1;             /* Multi Cycle Selection */
         vuint16_t  VFR:1;             /* Valid Frame Restriction */
         vuint16_t  SYF:1;             /* Sync Frame Restriction */
         vuint16_t  NUF:1;             /* Null Frame Restriction */
         vuint16_t  SUF:1;             /* Startup Frame Restriction */
         vuint16_t  STATUSMASK:4;      /* Slot Status Mask */
      } B;
   } FR_SSCCR_16B_tag;

   typedef union {   /* Slot Status Register0 */
      vuint16_t R;
      struct {
         vuint16_t  VFB:1;             /* Valid Frame on Channel B */
         vuint16_t  SYB:1;             /* Sync Frame Indicator Channel B */
         vuint16_t  NFB:1;             /* Null Frame Indicator Channel B */
         vuint16_t  SUB:1;             /* Startup Frame Indicator Channel B */
         vuint16_t  SEB:1;             /* Syntax Error on Channel B */
         vuint16_t  CEB:1;             /* Content Error on Channel B */
         vuint16_t  BVB:1;             /* Boundary Violation on Channel B */
         vuint16_t  TCB:1;             /* Transmission Conflict on Channel B */
         vuint16_t  VFA:1;             /* Valid Frame on Channel A */
         vuint16_t  SYA:1;             /* Sync Frame Indicator Channel A */
         vuint16_t  NFA:1;             /* Null Frame Indicator Channel A */
         vuint16_t  SUA:1;             /* Startup Frame Indicator Channel A */
         vuint16_t  SEA:1;             /* Syntax Error on Channel A */
         vuint16_t  CEA:1;             /* Content Error on Channel A */
         vuint16_t  BVA:1;             /* Boundary Violation on Channel A */
         vuint16_t  TCA:1;             /* Transmission Conflict on Channel A */
      } B;
   } FR_SSR_16B_tag;

   
   typedef union {   /* MTS A Configuration Register */
      vuint16_t R;
      struct {
         vuint16_t  MTE:1;             /* Media Access Test Symbol Transmission Enable */
         vuint16_t:1;
         vuint16_t  CYCCNTMSK:6;       /* Cycle Counter Mask */
         vuint16_t:2;
         vuint16_t  CYCCNTVAL:6;       /* Cycle Counter Value */
      } B;
   } FR_MTSACFR_16B_tag;

   typedef union {   /* MTS B Configuration Register */
      vuint16_t R;
      struct {
         vuint16_t  MTE:1;             /* Media Access Test Symbol Transmission Enable */
         vuint16_t:1;
         vuint16_t  CYCCNTMSK:6;       /* Cycle Counter Mask */
         vuint16_t:2;
         vuint16_t  CYCCNTVAL:6;       /* Cycle Counter Value */
      } B;
   } FR_MTSBCFR_16B_tag;

   typedef union {   /* Receive Shadow Buffer Index Register */
      vuint16_t R;
      struct {
         vuint16_t  WMD:1;             /* Write Mode */
         vuint16_t:1;
         vuint16_t  SEL:2;             /* Selector */
         vuint16_t:5;
         vuint16_t  RSBIDX:7;          /* Receive Shadow Buffer Index */
      } B;
   } FR_RSBIR_16B_tag;

   typedef union {   /* Receive FIFO Watermark and Selection Register */
      vuint16_t R;
      struct {
         vuint16_t  WM:8;              /* Watermark Value */
         vuint16_t:7;
         vuint16_t  SEL:1;             /* Select */
      } B;
   } FR_RFWMSR_16B_tag;

   typedef union {   /* Receive FIFO Start Index Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  SIDX:10;           /* Start Index */
      } B;
   } FR_RF_RFSIR_16B_tag;

   typedef union {   /* Receive FIFO Depth and Size Register */
      vuint16_t R;
      struct {
         vuint16_t  FIFODEPTH:8;       /* FIFO Depth */
         vuint16_t:1;
         vuint16_t  ENTRYSIZE:7;       /* Entry Size */
      } B;
   } FR_RFDSR_16B_tag;

   typedef union {   /* Receive FIFO A Read Index Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  RDIDX:10;          /* Read Index */
      } B;
   } FR_RFARIR_16B_tag;

   typedef union {   /* Receive FIFO B Read Index Register */
      vuint16_t R;
      struct {
         vuint16_t:6;
         vuint16_t  RDIDX:10;          /* Read Index */
      } B;
   } FR_RFBRIR_16B_tag;

   typedef union {   /* Receive FIFO Message ID Acceptance Filter Value Register */
      vuint16_t R;
      struct {
         vuint16_t  MIDAFVAL:16;       /* Message ID Acceptance Filter Value */
      } B;
   } FR_RFMIDAFVR_16B_tag;

   typedef union {   /* Receive FIFO Message ID Acceptance Filter Mask Register */
      vuint16_t R;
      struct {
         vuint16_t  MIDAFMSK:16;       /* Message ID Acceptance Filter Mask */
      } B;
   } FR_RFMIDAFMR_16B_tag;

   typedef union {   /* Receive FIFO Frame ID Rejection Filter Value Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  FIDRFVAL:11;       /* Frame ID Rejection Filter Value */
      } B;
   } FR_RFFIDRFVR_16B_tag;

   typedef union {   /* Receive FIFO Frame ID Rejection Filter Mask Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  FIDRFMSK:11;       /* Frame ID Rejection Filter Mask */
      } B;
   } FR_RFFIDRFMR_16B_tag;

   typedef union {   /* Receive FIFO Range Filter Configuration Register */
      vuint16_t R;
      struct {
         vuint16_t  WMD:1;             /* Write Mode */
         vuint16_t  IBD:1;             /* Interval Boundary */
         vuint16_t  SEL:2;             /* Filter Selector */
         vuint16_t:1;
         vuint16_t  SID:11;            /* Slot ID */
      } B;
   } FR_RFRFCFR_16B_tag;

   typedef union {   /* Receive FIFO Range Filter Control Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  F3MD:1;            /* Range Filter 3 Mode */
         vuint16_t  F2MD:1;            /* Range Filter 2 Mode */
         vuint16_t  F1MD:1;            /* Range Filter 1 Mode */
         vuint16_t  F0MD:1;            /* Range Filter 0 Mode */
         vuint16_t:4;
         vuint16_t  F3EN:1;            /* Range Filter 3 Enable */
         vuint16_t  F2EN:1;            /* Range Filter 2 Enable */
         vuint16_t  F1EN:1;            /* Range Filter 1 Enable */
         vuint16_t  F0EN:1;            /* Range Filter 0 Enable */
      } B;
   } FR_RFRFCTR_16B_tag;

   typedef union {   /* Last Dynamic Transmit Slot Channel A Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  LASTDYNTXSLOTA:11;   /* Last Dynamic Transmission Slot Channel A */
      } B;
   } FR_LDTXSLAR_16B_tag;

   typedef union {   /* Last Dynamic Transmit Slot Channel B Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  LASTDYNTXSLOTB:11;   /* Last Dynamic Transmission Slot Channel B */
      } B;
   } FR_LDTXSLBR_16B_tag;

   typedef union {   /* Protocol Configuration Register 0 */
      vuint16_t R;
      struct {
         vuint16_t  ACTION_POINT_OFFSET:6;   /* gdActionPointOffset - 1 */
         vuint16_t  STATIC_SLOT_LENGTH:10;   /* gdStaticSlot */
      } B;
   } FR_PCR0_16B_tag;

   typedef union {   /* Protocol Configuration Register 1 */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  MACRO_AFTER_FIRST_STATIC_SLOT:14;   /* gMacroPerCycle - gdStaticSlot */
      } B;
   } FR_PCR1_16B_tag;

   typedef union {   /* Protocol Configuration Register 2 */
      vuint16_t R;
      struct {
         vuint16_t  MINISLOT_AFTER_ACTION_POINT:6;   /* gdMinislot - gdMinislotActionPointOffset - 1 */
         vuint16_t  NUMBER_OF_STATIC_SLOTS:10;   /* gNumberOfStaticSlots */
      } B;
   } FR_PCR2_16B_tag;

   typedef union {   /* Protocol Configuration Register 3 */
      vuint16_t R;
      struct {
         vuint16_t  WAKEUP_SYMBOL_RX_LOW:6;   /* gdWakeupSymbolRxLow */
         vuint16_t  MINISLOT_ACTION_POINT_OFFSET:5;     /* gdMinislotActionPointOffset - 1 */
         vuint16_t  COLDSTART_ATTEMPTS:5;   /* gColdstartAttempts */
      } B;
   } FR_PCR3_16B_tag;

   typedef union {   /* Protocol Configuration Register 4 */
      vuint16_t R;
      struct {
         vuint16_t  CAS_RX_LOW_MAX:7;   /* gdCASRxLowMax - 1 */
         vuint16_t  WAKEUP_SYMBOL_RX_WINDOW:9;   /* gdWakeupSymbolRxWindow */
      } B;
   } FR_PCR4_16B_tag;

   typedef union {   /* Protocol Configuration Register 5 */
      vuint16_t R;
      struct {
         vuint16_t  TSS_TRANSMITTER:4;   /* gdTSSTransmitter */
         vuint16_t  WAKEUP_SYMBOL_TX_LOW:6;   /* gdWakeupSymbolTxLow */
         vuint16_t  WAKEUP_SYMBOL_RX_IDLE:6;   /* gdWakeupSymbolRxIdle */
      } B;
   } FR_PCR5_16B_tag;

   typedef union {   /* Protocol Configuration Register 6 */
      vuint16_t R;
      struct {
         vuint16_t:1;
         vuint16_t  SYMBOL_WINDOW_AFTER_ACTION_POINT:8;   /* gdSymbolWindow - gdActionPointOffset - 1 */
         vuint16_t  MICRO_INITIAL_OFFSET_A:7;     /* pMacroInitialOffset[A] */
      } B;
   } FR_PCR6_16B_tag;

   typedef union {   /* Protocol Configuration Register 7 */
      vuint16_t R;
      struct {
         vuint16_t  DECODING_CORRECTION_B:9;   /* pDecodingCorrection + pDelayCompensation[B] + 2 */
         vuint16_t  MICRO_PER_MACRO_NOM_HALF:7;   /* round(pMicroPerMacroNom / 2) */
      } B;
   } FR_PCR7_16B_tag;

   typedef union {   /* Protocol Configuration Register 8 */
      vuint16_t R;
      struct {
         vuint16_t  MAX_WITHOUT_CLOCK_CORRECTION_FATAL:4;   /* gMaxWithoutClockCorrectionFatal */
         vuint16_t  MAX_WITHOUT_CLOCK_CORRECTION_PASSIVE:4;   /* gMaxWithoutClockCorrectionPassive */
         vuint16_t  WAKEUP_SYMBOL_TX_IDLE:8;   /* gdWakeupSymbolTxIdle */
      } B;
   } FR_PCR8_16B_tag;

   typedef union {   /* Protocol Configuration Register 9 */
      vuint16_t R;
      struct {
         vuint16_t  MINISLOT_EXISTS:1;   /* gNumberOfMinislots!=0 */
         vuint16_t  SYMBOL_WINDOW_EXISTS:1;   /* gdSymbolWindow!=0 */
         vuint16_t  OFFSET_CORRECTION_OUT:14;   /* pOffsetCorrectionOut */
      } B;
   } FR_PCR9_16B_tag;

   typedef union {   /* Protocol Configuration Register 10 */
      vuint16_t R;
      struct {
         vuint16_t  SINGLE_SLOT_ENABLED:1;   		/* pSingleSlotEnabled */
         vuint16_t  WAKEUP_CHANNEL:1;   			/* pWakeupChannel */
         vuint16_t  MACRO_PER_CYCLE:14;   			/* pMicroPerCycle */
      } B;
   } FR_PCR10_16B_tag;

   typedef union {   /* Protocol Configuration Register 11 */
      vuint16_t R;
      struct {
         vuint16_t  KEY_SLOT_USED_FOR_STARTUP:1;   	/* pKeySlotUsedForStartup */
         vuint16_t  KEY_SLOT_USED_FOR_SYNC:1;   	/* pKeySlotUsedForSync */
         vuint16_t  OFFSET_CORRECTION_START:14;   	/* gOffsetCorrectionStart */
      } B;
   } FR_PCR11_16B_tag;

   typedef union {   /* Protocol Configuration Register 12 */
      vuint16_t R;
      struct {
         vuint16_t  ALLOW_PASSIVE_TO_ACTIVE:5;   	/* pAllowPassiveToActive */
         vuint16_t  KEY_SLOT_HEADER_CRC:11;   		/* header CRC for key slot */
      } B;
   } FR_PCR12_16B_tag;

   typedef union {   /* Protocol Configuration Register 13 */
      vuint16_t R;
      struct {
         vuint16_t  FIRST_MINISLOT_ACTION_POINT_OFFSET:6;   /* max(gdActionPointOffset,gdMinislotActionPointOffset) - 1 */
         vuint16_t  STATIC_SLOT_AFTER_ACTION_POINT:10;   /* gdStaticSlot - gdActionPointOffset - 1 */
      } B;
   } FR_PCR13_16B_tag;

   typedef union {   /* Protocol Configuration Register 14 */
      vuint16_t R;
      struct {
         vuint16_t  RATE_CORRECTION_OUT:11;   /* pRateCorrectionOut */
         vuint16_t  LISTEN_TIMEOUT_H:5;     /* pdListenTimeout - 1 */
      } B;
   } FR_PCR14_16B_tag;

   typedef union {   /* Protocol Configuration Register 15 */
      vuint16_t R;
      struct {
         vuint16_t  LISTEN_TIMEOUT_L:16;     /* pdListenTimeout - 1 */
      } B;
   } FR_PCR15_16B_tag;

   typedef union {   /* Protocol Configuration Register 16 */
      vuint16_t R;
      struct {
         vuint16_t  MICRO_INITIAL_OFFSET_B:7;    /* pMacroInitialOffset[B] */
         vuint16_t  NOISE_LISTEN_TIMEOUT_H:9;     /* (gListenNoise * pdListenTimeout) - 1 */
      } B;
   } FR_PCR16_16B_tag;

   typedef union {   /* Protocol Configuration Register 17 */
      vuint16_t R;
      struct {
         vuint16_t  NOISE_LISTEN_TIMEOUT_L:16;     /* (gListenNoise * pdListenTimeout) - 1 */
      } B;
   } FR_PCR17_16B_tag;

   typedef union {   /* Protocol Configuration Register 18 */
      vuint16_t R;
      struct {
         vuint16_t  WAKEUP_PATTERN:6;   /* pWakeupPattern */
         vuint16_t  KEY_SLOT_ID:10;    /* pKeySlotId */
      } B;
   } FR_PCR18_16B_tag;

   typedef union {   /* Protocol Configuration Register 19 */
      vuint16_t R;
      struct {
         vuint16_t  DECODING_CORRECTION_A:9;   /* pDecodingCorrection + pDelayCompensation[A] + 2 */
         vuint16_t  PAYLOAD_LENGTH_STATIC:7;   /* gPayloadLengthStatic */
      } B;
   } FR_PCR19_16B_tag;

   typedef union {   /* Protocol Configuration Register 20 */
      vuint16_t R;
      struct {
         vuint16_t  MICRO_INITIAL_OFFSET_B:8;   /* pMicroInitialOffset[B] */
         vuint16_t  MICRO_INITIAL_OFFSET_A:8;   /* pMicroInitialOffset[A] */
      } B;
   } FR_PCR20_16B_tag;

   typedef union {   /* Protocol Configuration Register 21 */
      vuint16_t R;
      struct {
         vuint16_t  EXTERN_RATE_CORRECTION:3;   /* pExternRateCorrection */
         vuint16_t  LATEST_TX:13;      /* gNumberOfMinislots - pLatestTx */
      } B;
   } FR_PCR21_16B_tag;

   typedef union {   /* Protocol Configuration Register 22 */
      vuint16_t R;
      struct {
         vuint16_t  R:1;               /* Reserved bit */
         vuint16_t  COMP_ACCEPTED_STARTUP_RANGE_A:11;   /* pdAcceptedStartupRange - pDelayCompensationChA */
         vuint16_t  MICRO_PER_CYCLE_H:4;     /* gMicroPerCycle */
      } B;
   } FR_PCR22_16B_tag;

   typedef union {   /* Protocol Configuration Register 23 */
      vuint16_t R;
      struct {
         vuint16_t  micro_per_cycle_l:16;     /* pMicroPerCycle */
      } B;
   } FR_PCR23_16B_tag;

   typedef union {   /* Protocol Configuration Register 24 */
      vuint16_t R;
      struct {
         vuint16_t  CLUSTER_DRIFT_DAMPING:5;   /* pClusterDriftDamping */
         vuint16_t  MAX_PAYLOAD_LENGTH_DYNAMIC:7;   /* pPayloadLengthDynMax */
         vuint16_t  MICRO_PER_CYCLE_MIN_H:4;     /* pMicroPerCycle - pdMaxDrift */
      } B;
   } FR_PCR24_16B_tag;

   typedef union {   /* Protocol Configuration Register 25 */
      vuint16_t R;
      struct {
         vuint16_t  MICRO_PER_CYCLE_MIN_L:16;      /* pMicroPerCycle - pdMaxDrift */
      } B;
   } FR_PCR25_16B_tag;

   typedef union {   /* Protocol Configuration Register 26 */
      vuint16_t R;
      struct {
         vuint16_t  ALLOW_HALT_DUE_TO_CLOCK:1;   /* pAllowHaltDueToClock */
         vuint16_t  COMP_ACCEPTED_STARTUP_RANGE_B:11;   /* pdAcceptedStartupRange - pDelayCompensationChB */
         vuint16_t  MICRO_PER_CYCLE_MAX_H:4;     /* pMicroPerCycle + pdMaxDrift */
      } B;
   } FR_PCR26_16B_tag;

   typedef union {   /* Protocol Configuration Register 27 */
      vuint16_t R;
      struct {
         vuint16_t  MICRO_PER_CYCLE_MAX_L:16;     /* pMicroPerCycle + pdMaxDrift */
      } B;
   } FR_PCR27_16B_tag;

   typedef union {   /* Protocol Configuration Register 28 */
      vuint16_t R;
      struct {
         vuint16_t  DYNAMIC_SLOT_IDLE_PHASE:2;   /* gdDynamicSlotIdlePhase */
         vuint16_t  MACRO_AFTER_OFFSET_CORRECTION:14;   /* gMacroPerCycle - gOffsetCorrectionStart */
      } B;
   } FR_PCR28_16B_tag;

   typedef union {   /* Protocol Configuration Register 29 */
      vuint16_t R;
      struct {
         vuint16_t  EXTERN_OFFSET_CORRECTION:3;   /* pExternOffsetCorrection */
         vuint16_t  MINISLOTS_MAX:13;   /* gNumberOfMinislots - 1 */
      } B;
   } FR_PCR29_16B_tag;

   typedef union {   /* Protocol Configuration Register 30 */
      vuint16_t R;
      struct {
         vuint16_t:12;
         vuint16_t  SYNC_NODE_MAX:4;   /* gSyncNodeMax */
      } B;
   } FR_PCR30_16B_tag;

   typedef union {   /* Receive FIFO System Memory Base Address High Register */
      vuint16_t R;
      struct {
         vuint16_t  SMBA_31_16:16;     /* System Memory Base Address */
      } B;
   } FR_RFSYMBHADR_16B_tag;

   typedef union {   /* Receive FIFO System Memory Base Address Low Register */
      vuint16_t R;
      struct {
         vuint16_t:4;
         vuint16_t  SMBA_15_4:12;      /* System Memory Base Address */
      } B;
   } FR_RFSYMBLADR_16B_tag;

   typedef union {   /* Receive FIFO Periodic Timer Register */
      vuint16_t R;
      struct {
         vuint16_t:2;
         vuint16_t  PTD:14;            /* Periodic Timer Duration */
      } B;
   } FR_RFPTR_16B_tag;

   typedef union {   /* Receive FIFO Fill Level and Pop Count Register */
      vuint16_t R;
      struct {
         vuint16_t  FLPCB:8;           /* Fill Level and Pop Count Channel B */
         vuint16_t  FLPCA:8;           /* Fill Level and Pop Count Channel A */
      } B;
   } FR_RFFLPCR_16B_tag;

   typedef union {   /* ECC Error Interrupt Flag and Enable Register */
      vuint16_t R;
      struct {
         vuint16_t  LRNE_OF:1;         /* LRAM Non-Corrected Error Overflow Flag */
         vuint16_t  LRCE_OF:1;         /* LRAM Corrected Error Overflow Flag */
         vuint16_t  DRNE_OF:1;         /* DRAM Non-Corrected Error Overflow Flag */
         vuint16_t  DRCE_OF:1;         /* DRAM Corrected Error Overflow Flag */
         vuint16_t  LRNE_IF:1;         /* LRAM Non-Corrected Error Interrupt Flag */
         vuint16_t  LRCE_IF:1;         /* LRAM Corrected Error Interrupt Flag */
         vuint16_t  DRNE_IF:1;         /* DRAM Non-Corrected Error Interrupt Flag */
         vuint16_t  DRCE_IF:1;         /* DRAM Corrected Error Interrupt Flag */
         vuint16_t:4;
         vuint16_t  LRNE_IE:1;         /* LRAM Non-Corrected Error Interrupt Enable */
         vuint16_t  LRCE_IE:1;         /* LRAM Corrected Error Interrupt Enable */
         vuint16_t  DRNE_IE:1;         /* DRAM Non-Corrected Error Interrupt Enable */
         vuint16_t  DRCE_IE:1;         /* DRAM Corrected Error Interrupt Enable */
      } B;
   } FR_EEIFER_16B_tag;

   typedef union {   /* ECC Error Report and Injection Control Register */
      vuint16_t R;
      struct {
         vuint16_t  BSY:1;             /* Register Update Busy */
         vuint16_t:5;
         vuint16_t  ERS:2;             /* Error Report Select */
         vuint16_t:3;
         vuint16_t  ERM:1;             /* Error Report Mode */
         vuint16_t:2;
         vuint16_t  EIM:1;             /* Error Injection Mode */
         vuint16_t  EIE:1;             /* Error Injection Enable */
      } B;
   } FR_EERICR_16B_tag;

   typedef union {   /* ECC Error Report Adress Register */
      vuint16_t R;
      struct {
         vuint16_t  MID:1;             /* Memory Identifier */
         vuint16_t  BANK:3;            /* Memory Bank */
         vuint16_t  ADDR:12;           /* Memory Address */
      } B;
   } FR_EERAR_16B_tag;

   typedef union {   /* ECC Error Report Data Register */
      vuint16_t R;
      struct {
         vuint16_t  DATA:16;           /* Data */
      } B;
   } FR_EERDR_16B_tag;

   typedef union {   /* ECC Error Report Code Register */
      vuint16_t R;
      struct {
         vuint16_t:11;
         vuint16_t  CODE:5;            /* Code */
      } B;
   } FR_EERCR_16B_tag;

   typedef union {   /* ECC Error Injection Address Register */
      vuint16_t R;
      struct {
         vuint16_t  MID:1;             /* Memory Identifier */
         vuint16_t  BANK:3;            /* Memory Bank */
         vuint16_t  ADDR:12;           /* Memory Address */
      } B;
   } FR_EEIAR_16B_tag;

   typedef union {   /* ECC Error Injection Data Register */
      vuint16_t R;
      struct {
         vuint16_t  DATA:16;           /* Data */
      } B;
   } FR_EEIDR_16B_tag;

   typedef union {   /* ECC Error Injection Code Register */
      vuint16_t R;
      struct {
         vuint16_t:11;
         vuint16_t  CODE:5;            /* Code */
      } B;
   } FR_EEICR_16B_tag;


   /* Register layout for all registers MBCCSR... */

   typedef union {   /* Message Buffer Configuration Control Status Register */
      vuint16_t R;
      struct {
         vuint16_t:1;
         vuint16_t  MCM:1;             /* Message Buffer Commit Mode */
		 vuint16_t  MBT:1;             /* Message Buffer Type */
         vuint16_t  MTD:1;             /* Message Buffer Transfer Direction */
         vuint16_t  CMT:1;             /* Commit for Transmission */
         vuint16_t  EDT:1;             /* Enable/Disable Trigger */
         vuint16_t  LCKT:1;            /* Lock/Unlock Trigger */
         vuint16_t  MBIE:1;            /* Message Buffer Interrupt Enable */
         vuint16_t:3;
         vuint16_t  DUP:1;             /* Data Updated */
         vuint16_t  DVAL:1;            /* DataValid */
         vuint16_t  EDS:1;             /* Enable/Disable Status */
         vuint16_t  LCKS:1;            /* LockStatus */
         vuint16_t  MBIF:1;            /* Message Buffer Interrupt Flag */
      } B;
   } FR_MBCCSR_16B_tag;


   /* Register layout for all registers MBCCFR... */

   typedef union {   /* Message Buffer Cycle Counter Filter Register */
      vuint16_t R;
      struct {
         vuint16_t  MTM:1;             /* Message Buffer Transmission Mode */
         vuint16_t  CHNLA:1;           /* Channel Assignment */
         vuint16_t  CHNLB:1;           /* Channel Assignment */
         vuint16_t  CCFE:1;            /* Cycle Counter Filtering Enable */
         vuint16_t  CCFMSK:6;          /* Cycle Counter Filtering Mask */
         vuint16_t  CCFVAL:6;          /* Cycle Counter Filtering Value */
      } B;
   } FR_MBCCFR_16B_tag;


   /* Register layout for all registers MBFIDR... */

   typedef union {   /* Message Buffer Frame ID Register */
      vuint16_t R;
      struct {
         vuint16_t:5;
         vuint16_t  FID:11;            /* Frame ID */
      } B;
   } FR_MBFIDR_16B_tag;


   /* Register layout for all registers MBIDXR... */

   typedef union {   /* Message Buffer Index Register */
      vuint16_t R;
      struct {
         vuint16_t:9;
         vuint16_t  MBIDX:7;           /* Message Buffer Index */
      } B;
   } FR_MBIDXR_16B_tag;


   /* Register layout for generated register(s) NMVR... */

   typedef union {   /*  */
      vuint16_t R;
   } FR_NMVR_16B_tag;

   /* Register layout for generated register(s) SSCR... */

   typedef union {   /*  */
      vuint16_t R;
   } FR_SSCR_16B_tag;


   typedef struct FR_MB_struct_tag {

	   /* Message Buffer Configuration Control Status Register */
	   FR_MBCCSR_16B_tag MBCCSR;           /* relative offset: 0x0000 */
	   /* Message Buffer Cycle Counter Filter Register */
	   FR_MBCCFR_16B_tag MBCCFR;           /* relative offset: 0x0002 */
	   /* Message Buffer Frame ID Register */
	   FR_MBFIDR_16B_tag MBFIDR;           /* relative offset: 0x0004 */
	   /* Message Buffer Index Register */
	   FR_MBIDXR_16B_tag MBIDXR;           /* relative offset: 0x0006 */

   } FR_MB_tag;


   typedef struct FR_struct_tag { /* start of FR_tag */
	   /* Module Version Number */
	   FR_MVR_16B_tag MVR;                  /* offset: 0x0000 size: 16 bit */
	   /* Module Configuration Register */
	   FR_MCR_16B_tag MCR;                  /* offset: 0x0002 size: 16 bit */

	   /* SYSTEM MEMORY BASE ADD HIGH REG */
	   FR_SYMBADHR_16B_tag SYSBADHR;     /* offset: 0x0004 size: 16 bit */

	   /* SYSTEM MEMORY BASE ADD LOW  REG */
	   FR_SYMBADLR_16B_tag SYSBADLR;     /* offset: 0x0006 size: 16 bit */

	   /* STROBE SIGNAL CONTROL REGISTER */
	   FR_STBSCR_16B_tag STBSCR;            /* offset: 0x0008 size: 16 bit */

	   int8_t FR_reserved_000A[2];

	   /* MESSAGE BUFFER DATA SIZE REGISTER */
	   FR_MBDSR_16B_tag MBDSR;              /* offset: 0x000C size: 16 bit */
	   /* MESS. BUFFER SEG. SIZE & UTILISATION REG */
	   FR_MBSSUTR_16B_tag MBSSUTR;          /* offset: 0x000E size: 16 bit */
	   /* PE DRAM ACCESS REGISTER */
	   FR_PEDRAR_16B_tag PADR;         /* offset: 0x0010 size: 16 bit */
	   /* PE DRAM DATA REGISTER */
	   FR_PEDRDR_16B_tag PDAR;         /* offset: 0x0012 size: 16 bit */
	   /* PROTOCOL OPERATION CONTROL REG */
	   FR_POCR_16B_tag POCR;                /* offset: 0x0014 size: 16 bit */
	   /* GLOBAL INTERRUPT FLAG & ENABLE REG */
	   FR_GIFER_16B_tag GIFER;              /* offset: 0x0016 size: 16 bit */
	   /* PROTOCOL INTERRUPT FLAG REGISTER 0 */
	   FR_PIFR0_16B_tag PIFR0;              /* offset: 0x0018 size: 16 bit */
	   /* PROTOCOL INTERRUPT FLAG REGISTER 1 */
	   FR_PIFR1_16B_tag PIFR1;              /* offset: 0x001A size: 16 bit */
	   /* PROTOCOL INTERRUPT ENABLE REGISTER 0 */
	   FR_PIER0_16B_tag PIER0;              /* offset: 0x001C size: 16 bit */
	   /* PROTOCOL INTERRUPT ENABLE REGISTER 1 */
	   FR_PIER1_16B_tag PIER1;              /* offset: 0x001E size: 16 bit */
	   /* CHI ERROR FLAG REGISTER */
	   FR_CHIERFR_16B_tag CHIERFR;          /* offset: 0x0020 size: 16 bit */
	   /* Message Buffer Interrupt Vector Register */
	   FR_MBIVEC_16B_tag MBIVEC;            /* offset: 0x0022 size: 16 bit */
	   /* Channel A Status Error Counter Register */
	   FR_CASERCR_16B_tag CASERCR;          /* offset: 0x0024 size: 16 bit */
	   /* Channel B Status Error Counter Register */
	   FR_CBSERCR_16B_tag CBSERCR;          /* offset: 0x0026 size: 16 bit */
	   /* Protocol Status Register 0 */
	   FR_PSR0_16B_tag PSR0;                /* offset: 0x0028 size: 16 bit */
	   /* Protocol Status Register 1 */
	   FR_PSR1_16B_tag PSR1;                /* offset: 0x002A size: 16 bit */
	   /* Protocol Status Register 2 */
	   FR_PSR2_16B_tag PSR2;                /* offset: 0x002C size: 16 bit */
	   /* Protocol Status Register 3 */
	   FR_PSR3_16B_tag PSR3;                /* offset: 0x002E size: 16 bit */
	   /* Macrotick Counter Register */
	   FR_MTCTR_16B_tag MTCTR;              /* offset: 0x0030 size: 16 bit */
	   /* Cycle Counter Register */
	   FR_CYCTR_16B_tag CYCTR;              /* offset: 0x0032 size: 16 bit */
	   /* Slot Counter Channel A Register */
	   FR_SLTCTAR_16B_tag SLTCTAR;          /* offset: 0x0034 size: 16 bit */
	   /* Slot Counter Channel B Register */
	   FR_SLTCTBR_16B_tag SLTCTBR;          /* offset: 0x0036 size: 16 bit */
	   /* Rate Correction Value Register */
	   FR_RTCORVR_16B_tag RTCORVR;          /* offset: 0x0038 size: 16 bit */
	   /* Offset Correction Value Register */
	   FR_OFCORVR_16B_tag OFCORVR;          /* offset: 0x003A size: 16 bit */
	   /* Combined Interrupt Flag Register */
	   FR_CIFR_16B_tag CIFRR;             /* offset: 0x003C size: 16 bit */

	   /* System Memory Access Time-Out Register */
	   FR_SYMATOR_16B_tag SYMATOR;          /* offset: 0x003E size: 16 bit */
	   /* Sync Frame Counter Register */
	   FR_SFCNTR_16B_tag SFCNTR;            /* offset: 0x0040 size: 16 bit */
	   /* Sync Frame Table Offset Register */
	   FR_SFTOR_16B_tag SFTOR;              /* offset: 0x0042 size: 16 bit */
	   /* Sync Frame Table Configuration, Control, Status Register */
	   FR_SFTCCSR_16B_tag SFTCCSR;          /* offset: 0x0044 size: 16 bit */
	   /* Sync Frame ID Rejection Filter */
	   FR_SFIDRFR_16B_tag SFIDRFR;          /* offset: 0x0046 size: 16 bit */
	   /* Sync Frame ID Acceptance Filter Value Register */
	   FR_SFIDAFVR_16B_tag SFIDAFVR;        /* offset: 0x0048 size: 16 bit */
	   /* Sync Frame ID Acceptance Filter Mask Register */
	   FR_SFIDAFMR_16B_tag SFIDAFMR;        /* offset: 0x004A size: 16 bit */


	   FR_NMVR_16B_tag NMVR[6];          /* offset: 0x004C  (0x0002 x 6) */

	   /* Network Management Vector Length Register */
	   FR_NMVLR_16B_tag NMVLR;              /* offset: 0x0058 size: 16 bit */
	   /* Timer Configuration and Control Register */
	   FR_TICCR_16B_tag TICCR;              /* offset: 0x005A size: 16 bit */
	   /* Timer 1 Cycle Set Register */
	   FR_TI1CYSR_16B_tag TI1CYSR;          /* offset: 0x005C size: 16 bit */
	   /* Timer 1 Macrotick Offset Register */
	   FR_TI1MTOR_16B_tag T1MTOR;       /* offset: 0x005E size: 16 bit */

	   /* Timer 2 Configuration Register 0 */
	   FR_TI2CR0_16B_tag TI2CR0;            /* offset: 0x0060 size: 16 bit */
	   /* Timer 2 Configuration Register 1 */
	   FR_TI2CR1_16B_tag TI2CR1;            /* offset: 0x0062 size: 16 bit */
	   /* Slot Status Selection Register */
	   FR_SSSR_16B_tag SSSR;                /* offset: 0x0064 size: 16 bit */
	   /* Slot Status Counter Condition Register */
	   FR_SSCCR_16B_tag SSCCR;              /* offset: 0x0066 size: 16 bit */


	   FR_SSR_16B_tag SSR[8];            /* offset: 0x0068  (0x0002 x 8) */


	   FR_SSCR_16B_tag SSCR[4];          /* offset: 0x0078  (0x0002 x 4) */


	   /* MTS A Configuration Register */
	   FR_MTSACFR_16B_tag MTSACFR;          /* offset: 0x0080 size: 16 bit */
	   /* MTS B Configuration Register */
	   FR_MTSBCFR_16B_tag MTSBCFR;          /* offset: 0x0082 size: 16 bit */
	   /* Receive Shadow Buffer Index Register */
	   FR_RSBIR_16B_tag RSBIR;              /* offset: 0x0084 size: 16 bit */

	   /* Receive FIFO Watermark and Selection Register */
	   FR_RFWMSR_16B_tag RFSR;         /* offset: 0x0086 size: 16 bit */

	   /* Receive FIFO Start Index Register */
	   FR_RF_RFSIR_16B_tag RFSIR;     /* offset: 0x0088 size: 16 bit */

	   /* Receive FIFO Depth and Size Register */
	   FR_RFDSR_16B_tag RFDSR;              /* offset: 0x008A size: 16 bit */
	   /* Receive FIFO A Read Index Register */
	   FR_RFARIR_16B_tag RFARIR;            /* offset: 0x008C size: 16 bit */
	   /* Receive FIFO B Read Index Register */
	   FR_RFBRIR_16B_tag RFBRIR;            /* offset: 0x008E size: 16 bit */
	   /* Receive FIFO Message ID Acceptance Filter Value Register */
	   FR_RFMIDAFVR_16B_tag RFMIDAFVR;      /* offset: 0x0090 size: 16 bit */

	   /* Receive FIFO Message ID Acceptance Filter Mask Register */
	   FR_RFMIDAFMR_16B_tag RFMIAFMR;   /* offset: 0x0092 size: 16 bit */

	   /* Receive FIFO Frame ID Rejection Filter Value Register */
	   FR_RFFIDRFVR_16B_tag RFFIDRFVR;      /* offset: 0x0094 size: 16 bit */
	   /* Receive FIFO Frame ID Rejection Filter Mask Register */
	   FR_RFFIDRFMR_16B_tag RFFIDRFMR;      /* offset: 0x0096 size: 16 bit */
	   /* Receive FIFO Range Filter Configuration Register */
	   FR_RFRFCFR_16B_tag RFRFCFR;          /* offset: 0x0098 size: 16 bit */
	   /* Receive FIFO Range Filter Control Register */
	   FR_RFRFCTR_16B_tag RFRFCTR;          /* offset: 0x009A size: 16 bit */
	   /* Last Dynamic Transmit Slot Channel A Register */
	   FR_LDTXSLAR_16B_tag LDTXSLAR;        /* offset: 0x009C size: 16 bit */
	   /* Last Dynamic Transmit Slot Channel B Register */
	   FR_LDTXSLBR_16B_tag LDTXSLBR;        /* offset: 0x009E size: 16 bit */
	   /* Protocol Configuration Register 0 */
	   FR_PCR0_16B_tag PCR0;                /* offset: 0x00A0 size: 16 bit */
	   /* Protocol Configuration Register 1 */
	   FR_PCR1_16B_tag PCR1;                /* offset: 0x00A2 size: 16 bit */
	   /* Protocol Configuration Register 2 */
	   FR_PCR2_16B_tag PCR2;                /* offset: 0x00A4 size: 16 bit */
	   /* Protocol Configuration Register 3 */
	   FR_PCR3_16B_tag PCR3;                /* offset: 0x00A6 size: 16 bit */
	   /* Protocol Configuration Register 4 */
	   FR_PCR4_16B_tag PCR4;                /* offset: 0x00A8 size: 16 bit */
	   /* Protocol Configuration Register 5 */
	   FR_PCR5_16B_tag PCR5;                /* offset: 0x00AA size: 16 bit */
	   /* Protocol Configuration Register 6 */
	   FR_PCR6_16B_tag PCR6;                /* offset: 0x00AC size: 16 bit */
	   /* Protocol Configuration Register 7 */
	   FR_PCR7_16B_tag PCR7;                /* offset: 0x00AE size: 16 bit */
	   /* Protocol Configuration Register 8 */
	   FR_PCR8_16B_tag PCR8;                /* offset: 0x00B0 size: 16 bit */
	   /* Protocol Configuration Register 9 */
	   FR_PCR9_16B_tag PCR9;                /* offset: 0x00B2 size: 16 bit */
	   /* Protocol Configuration Register 10 */
	   FR_PCR10_16B_tag PCR10;              /* offset: 0x00B4 size: 16 bit */
	   /* Protocol Configuration Register 11 */
	   FR_PCR11_16B_tag PCR11;              /* offset: 0x00B6 size: 16 bit */
	   /* Protocol Configuration Register 12 */
	   FR_PCR12_16B_tag PCR12;              /* offset: 0x00B8 size: 16 bit */
	   /* Protocol Configuration Register 13 */
	   FR_PCR13_16B_tag PCR13;              /* offset: 0x00BA size: 16 bit */
	   /* Protocol Configuration Register 14 */
	   FR_PCR14_16B_tag PCR14;              /* offset: 0x00BC size: 16 bit */
	   /* Protocol Configuration Register 15 */
	   FR_PCR15_16B_tag PCR15;              /* offset: 0x00BE size: 16 bit */
	   /* Protocol Configuration Register 16 */
	   FR_PCR16_16B_tag PCR16;              /* offset: 0x00C0 size: 16 bit */
	   /* Protocol Configuration Register 17 */
	   FR_PCR17_16B_tag PCR17;              /* offset: 0x00C2 size: 16 bit */
	   /* Protocol Configuration Register 18 */
	   FR_PCR18_16B_tag PCR18;              /* offset: 0x00C4 size: 16 bit */
	   /* Protocol Configuration Register 19 */
	   FR_PCR19_16B_tag PCR19;              /* offset: 0x00C6 size: 16 bit */
	   /* Protocol Configuration Register 20 */
	   FR_PCR20_16B_tag PCR20;              /* offset: 0x00C8 size: 16 bit */
	   /* Protocol Configuration Register 21 */
	   FR_PCR21_16B_tag PCR21;              /* offset: 0x00CA size: 16 bit */
	   /* Protocol Configuration Register 22 */
	   FR_PCR22_16B_tag PCR22;              /* offset: 0x00CC size: 16 bit */
	   /* Protocol Configuration Register 23 */
	   FR_PCR23_16B_tag PCR23;              /* offset: 0x00CE size: 16 bit */
	   /* Protocol Configuration Register 24 */
	   FR_PCR24_16B_tag PCR24;              /* offset: 0x00D0 size: 16 bit */
	   /* Protocol Configuration Register 25 */
	   FR_PCR25_16B_tag PCR25;              /* offset: 0x00D2 size: 16 bit */
	   /* Protocol Configuration Register 26 */
	   FR_PCR26_16B_tag PCR26;              /* offset: 0x00D4 size: 16 bit */
	   /* Protocol Configuration Register 27 */
	   FR_PCR27_16B_tag PCR27;              /* offset: 0x00D6 size: 16 bit */
	   /* Protocol Configuration Register 28 */
	   FR_PCR28_16B_tag PCR28;              /* offset: 0x00D8 size: 16 bit */
	   /* Protocol Configuration Register 29 */
	   FR_PCR29_16B_tag PCR29;              /* offset: 0x00DA size: 16 bit */
	   /* Protocol Configuration Register 30 */
	   FR_PCR30_16B_tag PCR30;              /* offset: 0x00DC size: 16 bit */

	   int8_t FR_reserved_00DE[10];

	   /* Receive FIFO System Memory Base Address High Register */
	   FR_RFSYMBHADR_16B_tag RFSYMBHADR;    /* offset: 0x00E8 size: 16 bit */
	   /* Receive FIFO System Memory Base Address Low Register */
	   FR_RFSYMBLADR_16B_tag RFSYMBLADR;    /* offset: 0x00EA size: 16 bit */
	   /* Receive FIFO Periodic Timer Register */
	   FR_RFPTR_16B_tag RFPTR;              /* offset: 0x00EC size: 16 bit */
	   /* Receive FIFO Fill Level and Pop Count Register */
	   FR_RFFLPCR_16B_tag RFFLPCR;          /* offset: 0x00EE size: 16 bit */
	   /* ECC Error Interrupt Flag and Enable Register */
	   FR_EEIFER_16B_tag EEIFER;            /* offset: 0x00F0 size: 16 bit */
	   /* ECC Error Report and Injection Control Register */
	   FR_EERICR_16B_tag EERICR;            /* offset: 0x00F2 size: 16 bit */
	   /* ECC Error Report Adress Register */
	   FR_EERAR_16B_tag EERAR;              /* offset: 0x00F4 size: 16 bit */
	   /* ECC Error Report Data Register */
	   FR_EERDR_16B_tag EERDR;              /* offset: 0x00F6 size: 16 bit */
	   /* ECC Error Report Code Register */
	   FR_EERCR_16B_tag EERCR;              /* offset: 0x00F8 size: 16 bit */
	   /* ECC Error Injection Address Register */
	   FR_EEIAR_16B_tag EEIAR;              /* offset: 0x00FA size: 16 bit */
	   /* ECC Error Injection Data Register */
	   FR_EEIDR_16B_tag EEIDR;              /* offset: 0x00FC size: 16 bit */
	   /* ECC Error Injection Code Register */
	   FR_EEICR_16B_tag EEICR;              /* offset: 0x00FE size: 16 bit */

	   /*  Register set MB */
	   FR_MB_tag MBCCS[64];                 /* offset: 0x0100  (0x0008 x 64) */

   } FR_tag;

#define CFLASH_SHADOW 	(*(volatile CFLASH_SHADOW_tag *)			0x00F00000UL)
#define CFLASH 			(*(volatile CFLASH_tag *) 			0xC3F88000UL)
#define PMUCTRL 		(*(volatile PMUCTRL_tag *) 			0xC3FE8080UL)
#define ADC0  			(*(volatile ADC_tag *) 				0xFFE00000UL)
#define ADC1  			(*(volatile ADC_tag *) 				0xFFE04000UL)
#define CAN_0 			(*(volatile FLEXCAN_tag *) 			0xFFFC0000UL)
#define CAN_1 			(*(volatile FLEXCAN_tag *) 			0xFFFC4000UL)
#define CGM   			(*(volatile CGM_tag *) 				0xC3FE0000UL)
#define OSC   			(*(volatile OSC_tag *) 				0xC3FE0000UL)
#define RC    			(*(volatile RC_tag *) 				0xC3FE0060UL)
#define CMU0  			(*(volatile CMU_tag *) 				0xC3FE0100UL)
#define CMU1  			(*(volatile CMU_tag *) 				0xC3FE0120UL)
#define CMU2  			(*(volatile CMU_tag *) 				0xC3FE0140UL)
#define PLLD0 			(*(volatile PLLD_tag *) 			0xC3FE00A0UL)
#define PLLD1 			(*(volatile PLLD_tag *)				0xC3FE00C0UL)
#define CTU   			(*(volatile CTU_tag *) 				0xFFE0C000UL) 
#define DMAMUX 			(*(volatile DMA_CH_MUX_tag *) 			0xFFFDC000UL)
#define DSPI_0 			(*(volatile DSPI_tag *) 			0xFFF90000UL)
#define DSPI_1 			(*(volatile DSPI_tag *) 			0xFFF94000UL)
#define DSPI_2 			(*(volatile DSPI_tag *) 			0xFFF98000UL)
#define EDMA      		(*(volatile SPP_DMA2_tag *)  			0xFFF44000UL)
#define ETIMER_0 		(*(volatile mcTIMER_tag *) 			0xFFE18000UL)
#define ETIMER_1 		(*(volatile mcTIMER_tag *) 			0xFFE1C000UL)
#define ETIMER_2 		(*(volatile mcTIMER_tag *) 			0xFFE20000UL)
#define FCCU			(*(volatile FCCU_tag *) 			0xFFE6C000UL)
#define FLEXPWM_0 		(*(volatile mcPWM_tag *) 			0xFFE24000UL)
#define FLEXPWM_1 		(*(volatile mcPWM_tag *) 			0xFFE28000UL)
#define FR    			(*(volatile FR_tag *) 				0xFFFE0000UL) 
#define INTC  			(*(volatile INTC_tag *) 			0xFFF48000UL)   
#define LINFLEX_0 		(*(volatile LINFLEX_tag *) 			0xFFE40000UL)
#define LINFLEX_1 		(*(volatile LINFLEX_tag *) 			0xFFE44000UL)
#define MCM 			(*(volatile SPP_MCM_tag *) 			0xFFF40000UL)   
#define ME    			(*(volatile ME_tag *) 				0xC3FDC000UL)
#define MPU   			(*(volatile MPU_tag *) 				0xFFF10000UL)
#define PCU   			(*(volatile PCU_tag *) 				0xC3FE8000UL)   
#define PIT 			(*(volatile PIT_RTI_tag *) 			0xC3FF0000UL)
#define RGM   			(*(volatile RGM_tag *) 				0xC3FE4000UL)
#define SIU  			(*(volatile SIUL_tag *) 			0xC3F90000UL)   
#define SSCM  			(*(volatile SSCM_tag *)				0xC3FD8000UL)   
#define STM   			(*(volatile STM_tag *) 				0xFFF3C000UL)
#define SWT   			(*(volatile SWT_tag *) 				0xFFF38000UL)
#define WKUP  			(*(volatile WKPU_tag *) 			0xC3F94000UL)
#define CRC   			(*(volatile CRC_tag *) 				0xFFE68000UL)   
#define SEMA4 			(*(volatile SEMA4_tag *) 			0xFFF24000UL)
#define MAX   			(*(volatile MAX_tag *) 				0xFFF04000UL)
#define AIPS  			(*(volatile AIPS_tag *) 			0xFFF00000UL)
#define SGENDIG 		(*(volatile SGENDIG_tag *) 			0xFFE78000UL)

   
/*
   Platform blocks that are only accessible by the second core (core 1) when
    the device is in DPM mode. The block definition is equivalent to the one
    for the first core (core 0) and reuses the related block structure.

   NOTE: the <block_name>_1 defines are the preferred method for programming
 */
#define  AIPS_1			(*(volatile AIPS_tag*)     	0x8FF00000UL)
#define  MAX_1         	(*(volatile MAX_tag*)      	0x8FF04000UL)
#define  MPU_1         	(*(volatile MPU_tag*)      	0x8FF10000UL)
#define  SEMA4_1       	(*(volatile SEMA4_tag*)    	0x8FF24000UL)
#define  SWT_1         	(*(volatile SWT_tag*)      	0x8FF38000UL)
#define  STM_1         	(*(volatile STM_tag*)      	0x8FF3C000UL)
#define  MCM_1		   	(*(volatile SPP_MCM_tag*)  	0x8FF40000UL)
#define  EDMA_1    	    (*(volatile SPP_DMA2_tag*) 	0x8FF44000UL)
#define  INTC_1        	(*(volatile INTC_tag*)     	0x8FF48000UL)  

/*
   Platform blocks that are only accessible by the second core (core 1) when
    the device is in DPM mode. The block definition is equivalent to the one
    for the first core (core 0) and reuses the related block structure.

   NOTE: the <block_name>_DPM defines are deprecated, use <block_name>_1 for
         programming the corresponding blocks for new code instead.
 */
#define  AIPS_DPM      	AIPS_1
#define  MAX_DPM       	MAX_1
#define  MPU_DPM       	MPU_1
#define  SEMA4_DPM     	SEMA4_1
#define  SWT_DPM       	SWT_1
#define  STM_DPM       	STM_1
#define  MCM_DPM      	MCM_1
#define  EDMA_DPM  		EDMA_1
#define  INTC_DPM      	INTC_1


#ifdef __cplusplus
}
#endif
#endif /* _INIT_H_ */
/* End of file */

