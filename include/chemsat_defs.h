/*@Start***********************************************************/
/* GEMSBG C source File
 * Copyright (C) 1990 The General Electric Company
 *
 *      File Name:  chemsat_defs.h
 *      Developer:  Thomas Foo
 *
 * $Source: chemsat_defs $
 * $Revision: 1.0 $  $Date: 8/19/94 13:09:33 $
 */

/*@Synopsis
   chemsat_defs.h contains the necessary definitions of for 
   ChemSatFGRE.e and ChemSatFastcard.e.

*/

/*@Description
    **********************************************************
   Include File: chemsat_defs.h
   Author:  Thomas Foo
   Date:    7-Sept-94

   Revisions:
   
   Feb 14 1995   JDM  Include ChemSat.global.h so no duplication.

sccs1.4  9-Sep-98  Thayer  Removed ChemSat_global.h because it caused
                           conflicts during ANSI conversion.  Will insert
                           it explicitly where it is needed.

         17-Sep-98 Thayer  Copy of lx3 version from CM.

*************************************************************/


/* define possible pulseType list */
#define CSMIN_INV16_PULSE CSMAX8_PULSE+1    /* 16 ms spectrally selective inversion pulse */
#define CSMIN_INV12_PULSE CSMAX8_PULSE+2    /* 12 ms spectrally selective inversion pulse */
#define CSMIN_INV12_1_PULSE CSMAX8_PULSE+3  /* 12 ms spectrally selective 120-degree pulse */

/* attributes of chem sat inversion pulse */
 
#define RES_cinv16 320

#define SAR_EFFWIDTH_cinv16 0.1531  /* Effective width of cinv16.rf1 */
#define SAR_AREA_cinv16 0.1512      /* Integrated area */
#define SAR_ABS_cinv16 0.2606
#define SAR_MAXPW_cinv16 0.3931
#define SAR_DTYCYC_cinv16 0.4057
#define SAR_MAX_B1_cinv16_180 0.048249  /* max B1 for a 178 degree flip */
#define SAR_MAX_INT_B1_SQ_cinv16_180 .005643
#define SAR_MAX_RMS_B1_cinv16_180 .01878
#define SAR_NOM_BW_cinv16 217.0         /* FWHM bandwidth of cinv16 */
#define ISO_DEL_cinv16 4325      /* iso delay time */
#define SAR_NOM_PW_cinv16 16000.0
#define SAR_NOM_FA_cinv16 178.0

/* attributes of 12 ms chem inversion pulse */


#define RES_rf12inv 300

#define SAR_EFFWIDTH_rf12inv 0.2309   /* Effective width of rf12inv.rho */
#define SAR_AREA_rf12inv 0.2537       /* Integrated area */
#define SAR_ABS_rf12inv 0.3591
#define SAR_MAXPW_rf12inv 0.5886
#define SAR_DTYCYC_rf12inv 0.5886
#define SAR_MAX_B1_rf12inv 0.03764        /* max B1 for a 175 degree flip */
#define SAR_MAX_INT_B1_SQ_rf12inv .00389739
#define SAR_MAX_RMS_B1_rf12inv .0180217
#define SAR_NOM_BW_rf12inv 184.0          /* FWHM bandwidth of rf12inv */
#define SAR_NOM_FA_rf12inv 175.0          /* nominal flip angle of pulse */
#define SAR_NOM_PW_rf12inv 12000.0       /* nominal pulse width in usec */



#define SAR_EFFWIDTH_rf12inv1 0.2835  /* Effective width of rf12inv1.rho */
#define SAR_AREA_rf12inv1 0.3388      /* Integrated area */
#define SAR_ABS_rf12inv1 0.4109
#define SAR_MAXPW_rf12inv1 0.6689
#define SAR_DTYCYC_rf12inv1 0.66891
#define SAR_MAX_B1_rf12inv1 0.01928       /* max B1 for a 120 degree flip */
#define SAR_MAX_INT_B1_SQ_rf12inv1 .00126123   
#define SAR_MAX_RMS_B1_rf12inv1 .0102519
#define SAR_NOM_BW_rf12inv1 184.0         /* FWHM bandwidth of rf12inv1 */
#define SAR_NOM_FA_rf12inv1 120.0         /* nominal flip angle of pulse */
#define SAR_NOM_PW_rf12inv1 12000.0       /* nominal pulse width in usec */

