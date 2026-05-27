/*
 * GE Medical Systems
 * Copyright (C) 1989-1999 The General Electric Company
 *  
 * pulsegen.h
 * 
 * This file contains the typdefs and defines for the pulsegen routines.
 *  
 * Language : ANSI C
 * Author   : B. L. Mazin
 * Date     : 22/Jun/1989
 */
/* do not edit anything above this line */

/*
Rev     Author  Date            Comment
------  ------  --------          --------------------
6.0     
1.	BLM     05/24/93        Added 4 new enum to WF_PGMTAG
				Added WF_UNKOWN constant
2.	BLM	05/27/93	Added psd_board_type and psd_id_count

12/8/93  PJG   Cerd change. Added array of opcodes to support different
               transceivers. Added defines for offsets into ssp packets.
3/3/94   PJG   Added TARDIS_FREQ_OFFSET.

3/15/94 PJG    Removed TARDIS_FREQ_OFFSET.

3/16/94 PJG    PSD_PHASE_OFFSET2 = 6

3/29/94 LP     Added ERHODDS
6/10/94 YS     Change "const" to "constext" to support solaris.  
10/14/94 YH    merged 55 and vmx context into vmx.  SSPDABXRCV to SSPXTR
03/13/95 YI    added changes of psdinc:55 95fw10.5.
04/20/95 YI    55 merged(5.1.1  04/09/95  QT Added DAB 3D plane w/ echo Opcode)

05/05/95 JDM   Changed HSDAB_LENGTH to 15 for CERD.

06/20/95 JDM   Changed static int EDC, etc. to externs.

07/24/95 JDM   change #define MAX_XCVR_VALUES 60->63

12/21/95 JDM   Change COPY_DAB_LENGTH to 17 for CERD.

09/02/96 LP/YPD  Changed FAST_RBA_OFFSET back to 3 (MRIge34926).

09/21/1997 GFN   Changed (long) casts in #define's.

11/11/1997 GFN   Changed extern int EDC, etc. to extern INT to be consistent
                 with epicconf.h.

10/06/1998 GFN   Moved definition of opcode_xcvr[] to EpicConf.c.

07/22/1999 GFN   MRIge53830 - Changed XTRSETLNG from 100us to 130us per
                 CERD spec.

08/12/1999 BJM   Changed XTRSETLNG back to 100 us

*/


/* Only do this once in any given compilation.*/
#ifndef pulsegen_h
#define pulsegen_h

#include  "stddef_ep.h"


/* Units */ 
#define mSEC(x) (x * 1000) 
#define uSEC(x) (x)

/** EOS Bits **/
#define WEOS_BIT_SSP 0x8000
#define WEOS_BIT     0x0001
#define IEOS_BIT     0x0100

/*******************************************************/

typedef enum {
	TYPINSTRMEM,
	TYPWAVEMEM
} WF_HARDWARE_TYPE;

/*******************************************************/
/*******************************************************/

/****** SSP PARAMETERS ********/
/*********************/
/** Direction Attrb **/
/*********************/
typedef enum {
	TOHARDWARE,
	FROMHARDWARE
} HW_DIRECTION;

/*****************/
/** SSP S Attrb **/
/*****************/
typedef enum {
	SSPS1,  
	SSPS2,
	SSPS3,
	SSPS4
} SSP_S_ATTRIB;

/*** DAB PACKETS ****/
typedef enum {
	DABNORM,
	DABCINE,
        DABON,
        DABOFF
} TYPDAB_PACKETS;

/*** ACQ PASS TYPE ***/
typedef enum {
        NOPASS,
        PASSTHROUGH
} TYPACQ_PASS; 

/* Receiver Numbers */
#define TYPRECV0 0L
#define TYPRECV1 1L
#define TYPRECV2 2L
#define TYPRECV3 3L
#define TYPRECV4 4L
#define TYPRECV5 5L
#define TYPRECV6 6L
#define TYPRECV7 7L
#define TYPRECVALL -1L

/* Receiver Filter Slot Number */
#define TYPFSLOT0 0L
#define TYPFSLOT1 1L
#define TYPFSLOT2 2L
#define TYPFSLOT3 3L
#define TYPFSLOT4 4L
#define TYPFSLOT5 5L
#define TYPFSLOT6 6L
#define TYPFSLOT7 7L

/*******************************************************/

/*****************************/
/** Waveform Processor List **/
/*****************************/

#define WF_MAX_PROCESSORS 9
/*  There is a one to one corresponsdence between waveform generators and its
 *   bridged name.  If a new generator is added a bridged one should also be
 *   added.
*/
typedef enum {
        TYPXGRAD,
        TYPYGRAD,
        TYPZGRAD,
        TYPRHO1,
        TYPRHO2,
        TYPTHETA,
        TYPOMEGA,
        TYPSSP,
        TYPAUX,
        TYPBXGRAD,
        TYPBYGRAD,
        TYPBZGRAD,
        TYPBRHO1,
        TYPBRHO2,
        TYPBTHETA,
        TYPBOMEGA,
        TYPBSSP,
        TYPBAUX
} WF_PROCESSOR;



/*******************************************************/

#define CTRL_MASK 0x00FFFFFF  /* CTRL Bits On The SSP Board */

/*******************************************************/

/* Will contain the pointers to the Hardware Data and Instructions */

typedef long WF_HW_WAVEFORM_PTR;
typedef long WF_HW_INSTR_PTR;


/*******************************************************/

/* Pulse Address */
typedef ADDRESS WF_PULSE_FORWARD_ADDR;

/*******************************************************/

#define INSTRALL -1  /* All instructions */

typedef ADDRESS WF_INSTR_PTR;

typedef struct INST_NODE {
	struct INST_NODE *next;         /* Pointer to next instr structure */
        WF_HW_INSTR_PTR wf_instr_ptr;   /* Hardware address of instruction */
        long amplitude;
        long period;
        long start;
        long end;
        long entry_group;               
        WF_PULSE_FORWARD_ADDR pulse_hdr;/* Pointer to its pulse structure */
} WF_INSTR_HDR;

/*******************************************************/
#define RESOL_MIN 0
#define NSINC_CYCLES_MIN 0
#define SLICE_MIN 0


/**********************/
/** Pulse Extensions **/
/**********************/

/* Const Ext. */
typedef struct {
	short amplitude;
} CONST_EXT;

/* Hadamard Wave */
typedef struct {
        short amplitude;
        float separation;
        float nsinc_cycles;
        float alpha;
} HADAMARD_EXT;

/* Ramp Wave */
typedef struct {
	short start_amplitude;
	short end_amplitude;
} RAMP_EXT;

/* Sinc Wave */
typedef struct {
	short amplitude;
        float nsinc_cycles;
        float alpha;
} SINC_EXT;

/* Sinusoid Wave */
typedef struct {
	short  amplitude;
	float start_phase;
	float phase_length;
	short offset;
} SINUSOID_EXT;

typedef union {
        CONST_EXT     constext;
        HADAMARD_EXT  hadamard;
	RAMP_EXT      ramp;
        SINC_EXT      sinc;
        SINUSOID_EXT  sinusoid;
} WF_PULSE_EXT;
        
/*******************************************************/

/*****************/
/** Pulse Types **/
/*****************/

typedef enum {
	TYPBITS,
	TYPBRIDGED_CONST,
	TYPBRIDGED_RAMP,
	TYPCONSTANT,
	TYPEXTERNAL,
   	TYPHADAMARD,
	TYPRAMP,
	TYPRESERVE,
   	TYPSINC,
	TYPSINUSOID
} WF_PULSE_TYPES; 

typedef enum {	/* Create by */
   SSPUNKN,
   SSPDAB,		/* acqq - Dab initialization 		*/
   SSPRBA,		/* acqq - Receiver Begin Acquisition 	*/
   SSPXTR,		/* acqq - Xmit, Receiver Initialization */
   SSPSYNC,		/*createseq	, sync packet 		*/
   SSPFREQ,		/* addrfbits - Frequency Xmit		*/
   SSPUBR,		/* addrfbits - Unblank RF		*/
   SSPPA,		/* addrfbits	 - Power Amp		*/
   SSPPD,		/* addrfbits - Power Amp Down 		*/
   SSPPM,		/* addrfbits - Power Amp, RF Modulator 	*/
   SSPPMD,		/* addrfbits - Power Amp, RF Modulator Down 	*/
   SSPPEA,		/* addrfbits - Power Amp, Envelope Feedback	*/
   SSPPED,		/* addrfbits - Power Amp, Envelope Feedback Down */
   SSPPEM,		/* addrfbits - Power Amp, Envelope Feedback, 
			                RF Modulator 		*/
   SSPRFBITS,		/* createrf - Programable RF Bits 	*/
   SSPSEQ,		/* createseq - Seq Constant */
   SSPSCP,		/* createseq - Scope */
   SSPPASS,		/* createpass - pass pack */
   SSPATTEN,		/* createatten - attenuator pack */
   SSP3DIM		/* create3dim - 3 DIM */
} WF_PGMTAG;

#define WF_UNKNOWN -1

typedef enum {
   PSDREUSEP,	/* Instructions are linked in a chain off one pulse */
   PSDNEWP		/* A new pulse is created for each instruction. */
} WF_PGMREUSE;
/*******************************************************/

/**********************/
/** Pulse Structure ***/
/**********************/
typedef struct PULSE {
        char *pulsename;                  /* Pulse Name                      */
	long ninsts;                      /* Number of inst structures       */
	WF_HW_WAVEFORM_PTR  wave_addr;    /* Hardware Addr of waveform       */
	int board_type;	  /* Hardware configuration          */
	WF_PGMREUSE  reusep;		  /* Reuse wav mem, or create new    */
	WF_PGMTAG    tag;		  /* SSP Programable tag             */
	long	     addtag;		  /* Additional tag                  */
        int	     id;		  /* Pulse identification            */
	long	     ctrlfield;		  /* Ctrl field for SSP tags         */
        WF_INSTR_HDR   *inst_hdr_tail;    /* Pointer to instr structure list */
        WF_INSTR_HDR   *inst_hdr_head;    /*        Head And Tail            */
        WF_PROCESSOR   wavegen_type;      /* Waveform generator type         */
        WF_PULSE_TYPES type;              /* Pulse Type                      */
	short resolution;                 /* Resolution                      */
        struct PULSE *assoc_pulse;        /* Pointer to linked Pulse         */
     	WF_PULSE_EXT *ext;                /* Pulse Extensions                */
} WF_PULSE;

typedef WF_PULSE * WF_PULSE_ADDR;

/*******************************************************/
/**** Pulse Initialization *****/
/* Pulsegen structure initialization */
#define INITPULSE {0,0,-1, PSDCERD, PSDREUSEP, SSPUNKN, 0, 0, 0}
/*******************************/

/*******************************************************/

/***********************/
/** Instruction queue **/
/***********************/

typedef struct INST_QUEUE_NODE {
	WF_INSTR_HDR *instr;
        struct INST_QUEUE_NODE *next;
	struct INST_QUEUE_NODE *new_queue;
	struct INST_QUEUE_NODE *last_queue;
} WF_INSTR_QUEUE;

/*******************************************************/

/***********************/
/**** Sequence List ****/
/***********************/

#define MAX_SEQUENCE_DUR 0x7FFFFFFF
typedef long SEQUENCE_ENTRIES[WF_MAX_PROCESSORS];

typedef struct ENTRY_PT_NODE{
        WF_PULSE_ADDR ssp_pulse;
	long *entry_addresses;
	long time;
	struct ENTRY_PT_NODE *next;
} SEQUENCE_LIST;
/*******************************************************/

/***** SSP Bits Constants *****/
#define SSPDS      0x0100	/* SSP Device Select */
#define SSPOC      0x0200	/* SSP Opcode	     */
#define SSPD       0x0300	/* SSP Data	     */

#define MAX_XCVR_VALUES 63

 
/* Changed 'extern int' to 'extern INT' - GFN - 11/11/1997 */
extern INT EDC;
extern INT RDC;
extern INT ECF;
extern INT EMISC;
extern INT ESSL;
extern INT ESYNC;
extern INT ETHETA;
extern INT EUBL;
extern INT EXTATTEN;
extern INT ERFREQ;
extern INT ERPHASE;
extern INT RFLTRS;
extern INT RFLTRC;
extern INT RFUBL;
extern INT RSYNC;
extern INT RATTEN;
extern INT RRFSEL;
extern INT ESEL0;
extern INT ESEL1;
extern INT ESEL_ALL;
extern INT RSEL0;
extern INT RSEL1;
extern INT RSEL_ALL;
extern INT RATTEN_ALL;
extern INT RATTEN_1;
extern INT RATTEN_2;
extern INT RATTEN_3;
extern INT RATTEN_4;
extern INT RLOOP; 
extern INT RHEADI;
extern INT RFAUX;
extern INT RFBODYI;
extern INT ECCF;
extern INT EDSYNC;
extern INT EMRST;
extern INT EMSSS1;
extern INT EMSSS2;
extern INT EMSSS3;
extern INT ESSP;
extern INT EXUBL;
extern INT EDDSP;
extern INT EATTEN_TEST;
extern INT ETHETA_L;
extern INT EOMEGA_L;
extern INT RBA;
extern INT RBL;
extern INT RFF; 
extern INT RDSYNC;
extern INT RSAD;
extern INT RSUF;
extern INT RUBL;
extern INT RUBL_1;
extern INT RUBL_2;
extern INT RUBL_3;
extern INT RUBL_4;
extern INT RATTEN_FSEL;
extern INT RATTEN_3DB;
extern INT RATTEN_6DB;
extern INT RATTEN_12DB;
extern INT RATTEN_23DB;
extern INT FAST_EDC;
extern INT FAST_RDC;
extern INT FAST_RFLTRS;

/* Organization of values
     First 60 are for XCVR52
     Second 60        CERD
     Third  60        SPECTRO
     Fourth 60        EPI

    EDC       Exciter device code
    RDC       Receiver device code
    ECF       Center freq select
    EMISC     Misc control - will become obsolete
    ESSL      Slice select freq high
    ESYNC     Exciter sync register
    ETHETA    Theta shift register
    EUBL      Unblank control
    EXTATTEN  Transmit attenuator (2 bytes)
    ERFREQ    RHO DDS freq (3 bytes)
    ERPHASE   RHO DDS Phase (2 bytes)
    RFLTRS    Receiver filter select register
    RFLTRC     Receiver filter command register
    RFUBL     Receiver unblank register
    RSYNC     Receiver sync register
    RATTEN    Reciever attenuator
    RRFSEL    RF input select
    ESEL0     Exciter select 0
    ESEL1     Exciter select 1
    ESEL_ALL  Exciter select all
    RSEL0     Receiver select 0
    RSEL1     Receiver select 1 
    RSEL_ALL  Receiver select all
    RATTEN_ALL Atten/narrow select all
    RATTEN_1  Atten/narrow select RX1
    RATTEN_2  Atten/narrow select RX2
    RATTEN_3  Atten/narrow select RX3
    RATTEN_4  Atten/narrow select RX4
    RLOOP     Loopback mode (4 channels)
    RHEADI    RF Head Input (4 channels)
    RFAUX     RF Aux
    RFBODYI   Rf body input (4 channels)
    ECCF      Reset CF phase to 0 (only)
    EDSYNC    Synchronize the exicter to SSP bus
    EMRST     Reset SS phase to 0 (only)
    EMSSS1    No theta to freq or phase
    EMSSS2    Theta to phase
    EMSSS3    Theta to freq
    ESSP      Exciter SSP flag
    EXUBL     RF mod unblank
    EDDSP     Reset RHO DDS phase to 0
    EATTEN_TEST  Test attenuation
    ETHETA_L  IPG theta latch (no action)
    EOMEGA_L  IPG omega latch (no action)
    RBA       Begin ACQ
    RBL       Blank rcvr
    RFF       Flush filter
    RDSYNC    Synchronize receiver to SSP bus
    RSAD      Synchronize A/D
    RSUF      Set up filter
    RUBL      Unblank rcvr
    RUBL_1    Unblank RX1
    RUBL_2    Unblank RX2
    RUBL_3    Unblank RX3
    RUBL_4    Unblank RX4
    RATTEN_FSEL Narrowband filter select
    RATTEN_3DB  3db atten/narrowband & select
    RATTEN_6DB  6db atten/narrowband & select
    RATTEN_12DB 12db atten/narrowband & select
    RATTEN_23DB 24db atten/narrowband & select 
    FAST_EDC       Fast Exciter device code
    FAST_RDC       Fast Receiver device code
    FAST_RFLTRS    Fast Receiver filter select register
*/

/* Moved definitions to EpicConf.c - GFN - 06/Oct/1998 */
extern const INT opcode_xcvr[4][63];

#define PSD_SSP_52  0
#define PSD_SSP_CERD 1
#define PSD_SSP_SPECTRO 2
#define PSD_SSP_EPI 3

#define EUBC       0x0000	/* Clear the Unblank	         */
#define EUBTR      0x0001	/* Unblank the TR switch and amp */
#define EUBRF      0x0002	/* Unblank the RF Modulator      */ 
#define EHALFPI    0x00C0	/* Shift Data PI/2            */
#define ERHODDS    0x0010	/* Reset the rho dds phase            */

#define DABDC      0x0001 	/* DAB Device Code	*/
#define DPASS      0x0000	/* DAB Pass Opcode 	*/
#define SSPDDA     0x0002	/* Disdaq Mode bit	*/
#define DABPASS    0x0004	/* Pass Complete Bit 	*/
#define DABSCAN    0x0008	/* Scan COmplete Bit 	*/
#define DXCT       0x0001	/* DAB Excitation */

#define DABIE      0x00FE	/* DAB Increment echo by 1		 */
#define DABIS      0x0001	/* DAB Increment Sequence # by 1	 */
#define D3DOC      0x0002	/* DAB 3D plane Opcode			 */
#define D3DEOC     0x0008       /* DAB 3D plane w/ echo Opcode           */
#define DCINEOC    0x0003	/* DAB CINE Opcode			 */
#define DUNL       0x0005	/* DAB Unlock Opcode			 */
#define DHYPER     0x0006       /* DAB Hyperscan packet Opcode   *//* 5.5 */
#define DCOPY      0x0007       /* DAB Copy packet Opcode        *//* 5.5 */
#define DREG       0x00FF	/* DAB REGISTERS Opcode			 */
#define EFC        0x0001	/* Extra line for envelope feedback control */
#define DCBL       0x0002	/* Cardiac blank line 			*/
#define DCINE      0x0004	/* CINE BLANK LINE (Cine filter) 	*/
/*
#define DLO        0x0200
*/
#define DSPEC      0x0008	/* SPECTR Unblank Line 			*/
#define DSCP       0x0010	/* Scope Line 				*/
#define DSSPD4     0x0020	/* Grafidy Line A 			*/
#define DQTEN      0x0080	/* QTUNE Enable line (latches data )	*/
#define DQTCLK     0x0020	/* QTUNE Clock				*/
#define DQTSP      0x0040	/* QTUNE Serial Port To Set N on PLL	*/

/* Next 3 were used in SSP waveforms in 4.x.
   These commands are now set with SSP instructions */
#define IEUBC       0x0000	/* Clear the Unblank	         */
#define IEUBTR      0x0008	/* Unblank the TR switch and amp */
#define IEUBRF      0x0040	/* Unblank the RF Modulator      */
#define IEFB        0x0080	/* Envelope Feedback             */
#define IDSPEC      0x0010      /* Spectro ENI Amplifier	 */

/* following are 5.5 changes */

/* RF configuration control */
#define ENBL_RHO1 1               /* enable rho1 generator */
#define ENBL_RHO2 2               /* enable rho2 generator */
#define ENBL_THETA 4              /* enable theta generator */
#define ENBL_OMEGA 8              /* enable omega generator */
/* bit 4 & 5 are spares */
#define ENBL_THETA_FREQ_XTR2 64   /* theta producing freq on 2nd exciter */
#define ENBL_THETA_PHASE_XTR1 0   /* theta producing phase on 1st exciter */
#define ENBL_OMEGA_FREQ_XTR1 128  /* omega producing freq on 1st exciter */
#define ENBL_OMEGA_PHASE_XTR2 0   /* omega producing phase on 2nd exciter */

/* Receiver Types */
#define FAST_REC 1
#define STD_REC 0

/* Fast receiver constants */
#define AD_ENABLE              0x0004
#define AD_CONVERT             0x0002
#define AD_STROBE              0x0001
#define FAST_REC_RESET         0x0040
#define FAST_REC_FILTER_SELECT 0x0050
#define FAST_REC_RECORD        0x004D
#define FAST_REC_BEGIN_ACQ     0x004E
#define FAST_REC_ENABL_ACQ     0x004C
#define APPLICATION_MODE       0x0058
#define DIAGNOSTIC_A_MODE      0x0059
#define DIAGNOSTIC_B_MODE      0x005A
#define DIAGNOSTIC_C_MODE      0x005B
 
/* Fast Receiver initialization constants */
#define FPROG_LPF 9
#define FPROG_PTS 11
#define FPROG_PERIOD 51
#define FPROG_DELAY 67
#define MAX32BITWORD 4294967295
#define MAX16BITWORD 65535
#define MAX8BITWORD 255
#define NBITSPOINTS 20
#define NBITSPERIOD 8
#define NBITSDELAY 8
#define FAST_RECV_NUM 4  /* product fast receiver */
#define FR_MIN_XRES 2
#define FR_MAX_XRES 65536
#define FR_MIN_TSPTIC 20
#define FR_MAX_TSPTIC 256
#define FR_MIN_DELTIC 2
#define FR_MAX_DELTIC 256
#define FR_MIN_LPF 1
#define FR_MAX_LPF 5
 
#define PASS_LENGTH 7
#define ATTEN_UNLOCK_LENGTH 6

/* Copy packet support constants */
#define SSP_SOURCE_MOST_RECENT  0
#define SSP_SOURCE_CALCULATED   1
#define COPY_DAB_LENGTH 17
 
/* Definitions used in acqq.c, epiacqq.c */
#define XTRSETLNG 100       /* BJM -> 100 us (130us exciter settling time) */
#define DABSETUP 1000       /* 1ms DAB setup time */
#define DATARATE 8          /* 8us per point */
#define DEFAULTPOS 0

/* packet length constants (declared in EpicConf.h prior to 5.5) */
#define RFFREQ_LENGTH      14
#define RFUNBLANK_LENGTH    4
#define XTR_LENGTH       16    /* changed from 15 to 16. YH */
#define DAB_LENGTH       16    /* changed from 15 to 16. YH */
#define XTR_TAIL	 5       /* time from EMRST to end of XTR packet */
#define RBA_LENGTH       4 
#define DIM_LENGTH       5
#define DIM2_LENGTH      7   /* for 3DFSE ssp packet  */
#define EPSTRING_LENGTH    20
#define HSDAB_LENGTH 15
#define FAST_RBA_LENGTH 9
#define FAST_RBA_OFFSET 3    
#define FAST_PROG_LENGTH 83
#define FAST_DIAG_LENGTH 7
#define SQ_SYNC_LENGTH  8 
#define SQ_LOCKOUT_LENGTH  4

#define RF_START_UPA -250    
#define RF_START_EFA 50
#define RF_START_EFD -30
#define RF_START_UPD 50
#define RF_MIN_UBLWAIT 300
 
/* Dab load activity bitmasks */
#define PSD_LOAD_DAB_OFF 0
#define PSD_LOAD_DAB_SLICE 1
#define PSD_LOAD_DAB_ECHO 2
#define PSD_LOAD_DAB_OPER 4
#define PSD_LOAD_DAB_VIEW 8
#define PSD_LOAD_DAB_ACQON 16
#define PSD_LOAD_DAB_ACQON_RBA 32
#define PSD_LOAD_DAB_ALL 255
 
/* Hyperscan Dab load activity bitmasks */
#define PSD_LOAD_HSDAB_OFF 0
#define PSD_LOAD_HSDAB_SLICE 1
#define PSD_LOAD_HSDAB_ECHO 2
#define PSD_LOAD_HSDAB_OPER 4
#define PSD_LOAD_HSDAB_VUSTART 8
#define PSD_LOAD_HSDAB_VUSKIP 16
#define PSD_LOAD_HSDAB_VUNUM 32
#define PSD_LOAD_HSDAB_ACQON 64
#define PSD_LOAD_HSDAB_CARD_RPT 128
#define PSD_LOAD_HSDAB_K_READ 256
#define PSD_LOAD_HSDAB_ALL 511

/* end of 5.5 changes */

/**** External Variable Section - Variables are defined in EpicConf ****/

#define   PSD52      1
#define   PSDCERD   2
#define   PSDSPECTRO 3
#define   PSDEPI     4
#define   PSDCERDSPECTRO 5

extern int psd_board_type; /* Programable board - CERD, EPI, ... */
extern int psd_id_count;   /* id value in tag field */

#define PSD_CINESSP_DC_OFFSET 0
#define PSD_CINESSP_ARR_OFFSET 2
#define PSD_CINESSP_OP_OFFSET 3
#define PSD_CINESSP_PVIEW_OFFSET 4
#define PSD_CINESSP_FRAME_OFFSET 6
#define PSD_CINESSP_DELAY_OFFSET 10
#define PSD_CINESSP_FSLICE_OFFSET 12

#define PSD_DABSSP_DC_OFFSET 0
#define PSD_DABSSP_SLICE_OFFSET 8
#define PSD_DABSSP_ECHO_OFFSET 10
#define PSD_DABSSP_OP_OFFSET 11
#define PSD_DABSSP_VIEW_OFFSET 12
#define PSD_DABSSP_ON_FLAG 14

#define PSD_PHASE_OFFSET1 6
#define PSD_PHASE_OFFSET2 6

#define PSD_DABON_OFFSET1 8
#define PSD_DABON_OFFSET2 0

#define PSD_XCVR1 0
#define PSD_XCVR2 1

#include "pg_ext.h"

#endif /* pulsegen_h */

