/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1989 The General Electric Company
 *
 *      Include File Name:  epicconf
 *      Developer:          B.L. Mazin
 *
 * $Source: epicconf.h $
 * $Revision: 1.16 $  $Date: 11/2/93 09:26:40 $
 */

/*@Synopsis 
	Local configuration variable for pulsegen
*/     

/*@Description
     
*/
/* *********************************************************************
Internal
Rel #   Date    Person 	Comments
5.3.1	10/5/92 BLM	Adding	new constant for sliding the pmd packet

5.4.1    8/11/93 PJG Added new constant for min time between unblanks

7.0      3/16/94 PJG Set DABXCVR to 16 so it is even.
7.0      5/03/94  YH merged solar2 and cerd context into vmx(7.0).
7.0.1   10/17/94  YH merged 5.5 bch and vmx into vmx context.
                  DABXRCV-->XTR
                  define **_MAX
7.0.2   04/21/95  YI 55 merged(added DIM2_*) 

8.0.0   06/20/95  JDM Added list of vars EDC, etc. declared as ints;
                      the same list is declared as extern's in 
		      pulsegen.h

8.0.1   06/30/95  JDM Added new FAST_RDC, etc. to list.

8.2.1   11/11/97  GFN   Changed int EDC, etc. to extern INT EDC and
                        moved the definitions to EpicConf.c. This file
                        should only provide interface code, not
                        implementation. This was causing a lot of multiple
                        definition warnings.
/main/mr_main/2 16/Oct/98 RJF	This file now provides the function interface.
								Moved it from pulsegen.h. epic_conf.c should 
								not include this file because this file declares
								all the variables as externs. See changes to EpicConf.c file.
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  epicconf_INCL
#define  epicconf_INCL

#include <epicconf_defs.h>

STATUS EpicConf(
#ifdef __STDC__
	void
#endif /* __STDC__ */
);

extern SHORT rffrequency_length[2];
extern SHORT rffreq_bits[2][RFFREQ_LENGTH_MAX];

extern SHORT rfunblank_length[2];
extern SHORT rfunblank_bits[2][RFUNBLANK_LENGTH_MAX];

extern SHORT DAB_length[2];
extern SHORT DAB_bits[2][DAB_LENGTH_MAX];
extern LONG  DAB_start;

extern SHORT XTR_length[2];                /* new for cerd */
extern SHORT XTR_bits[2][XTR_LENGTH_MAX];  /* new for cerd */
extern LONG  XTR_start;

extern SHORT RBA_length[2];
extern SHORT RBA_bits[2][RBA_LENGTH_MAX];
extern LONG  RBA_start;
 
/* 5.5 changes */
extern SHORT FAST_RBA_length;
extern SHORT FAST_RBA_bits[];
extern LONG  FAST_RBA_start;
 
extern SHORT FAST_PROG_length;
extern SHORT FAST_PROG_bits[];
extern LONG  FAST_PROG_start;
 
extern SHORT FAST_DIAG_length;
extern SHORT FAST_DIAG_bits[];
extern LONG  FAST_DIAG_start;
 
extern SHORT SUF_length;
extern SHORT SUF_bits[];
extern LONG  SUF_start;
 
extern SHORT HSDAB_length;
extern SHORT HSDAB_bits[];
extern SHORT HSDAB_start;
 
extern SHORT COPY_DAB_length;
extern SHORT COPY_DAB_bits[];
extern SHORT COPY_DAB_start;
/* end */
 
extern SHORT DIM_length;
extern SHORT DIM_bits[];
extern LONG  DIM_start;

extern SHORT DIM2_length;
extern SHORT DIM2_bits[];
extern LONG  DIM2_start;

extern SHORT sq_sync_length[2];
extern SHORT sq_sync_bits[2][SQ_SYNC_LENGTH_MAX];

extern SHORT sq_lockout_length;
extern SHORT sq_lockout_bits[];

extern SHORT pass_length;
extern SHORT pass_bits[];
extern LONG  pass_start;

extern SHORT ATTEN_unlock_length[2];
extern SHORT ATTEN_unlock_bits[2][ATTEN_UNLOCK_LENGTH_MAX];
extern LONG  ATTEN_start;

/* 5.5 changes */
extern INT psd_gxwcnt;
extern INT psd_pulsepos;
extern INT psd_eparity;
extern FLOAT psd_etbetax, psd_etbetay;
extern CHAR psd_epstring[];
/* end */
 
extern LONG rfupa;          /* Unblank Power Amp Attack */
extern LONG rfefa;          /* Envelope Feedback Attack */
extern LONG rfefd;          /* Envelope Feedback Decay  */
extern LONG rfupd;          /* Unblank Power Amp Decay  */
extern LONG rfublwait;      /* Wait between unblanks */
extern LONG rfstartmod_off; /* Shift the start of the mod to play 
	                     *   prior to the rf pulse*/
extern LONG rfendmod_off;  /* Shift the end of the mod to play 
	                     *   after the rf pulse*/
extern STATUS rfdisable_add; /* Disables the rf bits */

/***** Trace flags for pulsegen *****/
#ifdef SIM_IO
extern STATUS psdtrace1;
extern STATUS psdtrace2;
extern STATUS psdtrace3;
extern STATUS psdtrace4;
#endif

/* Changed definitions to extern declarations. The definitions are located
   in EpicConf.c - GFN - 11/11/1997 */
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

#endif /* epicconf_INCL */
