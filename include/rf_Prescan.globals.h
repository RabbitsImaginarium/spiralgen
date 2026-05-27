/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1995 The General Electric Company
 *
 *      Include File Name:  @FILENAME_WITHOUT_H_SUFFIX@   
 *      Developer: Robert J. Laferriere
 *
 * $Source: rf_Prescan.globals.h $
 * $Revision: 1.2 $  $Date: 2/28/95 08:41:59 $
 */

/*@Synopsis 
 To support system safety, all rfpulse and gradient pulse structure constants
 need to be available to all segments of a PSD. This file should be included
 in grad_rf_<psd>.globals.h in a manner similar to rf_Prescan.h in grad_rf_<psd>.h
*/     

/*@Description
     N/A
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  rf_Prescan_globals_INCL
#define  rf_Prescan_globals_INCL

/* rf_Prescan globals */
#define RF1_APS1_SLOT RF_FREE1+0
#define RF2_APS1_SLOT RF_FREE1+1
#define RF1_CFL_SLOT RF_FREE1+2
#define RF1_CFH_SLOT RF_FREE1+3
#define RF2_CFH_SLOT RF_FREE1+4
#define RFCSSAT_CFH_SLOT RF_FREE1+5
#define RFMT_CFH_SLOT RF_FREE1+6
#define RF0_CFH_SLOT RF_FREE1+7
#define RF1_AUTOSHIM RF_FREE1+8
#define RF1_FTG_SLOT RF_FREE1+9
#define RF2_FTG_SLOT RF_FREE1+10
#define RF3_FTG_SLOT RF_FREE1+11
#define RF_FREE RF_FREE1+12


#endif /* rf_Prescan_globals_INCL */

