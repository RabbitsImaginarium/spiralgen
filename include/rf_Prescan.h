/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1993 The General Electric Company
 *
 *	Include File Name:  @rf_Prescan@   
 *	Developer:L. Ploetz
 *
 * $Source: rf_Prescan.h $
 * $Revision: 1.8 $  $Date: 2/28/95 08:20:08 $
 */

/*@Synopsis 
     Initializes RF pulse structure for prescan
*/     

/*@Description
     
***************************************************************
   Author	Date		Comment
-------------------------------------------------------
   LP		4/29/93	        Initial file
   YS           9/08/93         Add MT CFH pulse
   YS           9/13/93         Change pointer of the MT CFH pulse to
                                allow compilation
   PL      01/12/94         Add FastTG pulse stuff
   RJL     02/20/95         Added new fields to rf initialization for
                            system safety checks
   YI      03/14/95         Changed res_* from short to int.

   VB      02/21/97         Changed inversion rf0cfh to adiabatic pulse
*/
/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  rf_Prescan_INCL
#define  rf_Prescan_INCL

  /* RFPULSE PS1 - RF1 APS1 Pulse */
  {(int *)&pw_rf1mps1,
     (FLOAT *)&a_rf1mps1, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf1mps1,
     3200.0,
     1250.0,
     PSD_APS1_ON + PSD_MPS1_ON,
     0, 0,0, (int *)&res_rf1mps1,0},

  /* RFPULSE PS2 - RF2 APS1 Pulse */
  {(int *)&pw_rf2mps1,
     (FLOAT *)&a_rf2mps1, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf2mps1,
     3200.0,
     1250.0,
     PSD_APS1_ON + PSD_MPS1_ON,
     1, 0, 0,(int *)&res_rf2mps1,0},

  /* RFPULSE PS3 - RF1 CFL Pulse */
  {(int *)&pw_rf1cfl,
     (FLOAT *)&a_rf1cfl, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf1cfl,
     3200.0,
     1250.0,
     PSD_CFL_ON,
     0, 0, 0,(int *)&res_rf1cfl,0},

  /* RFPULSE PS4 - RF1 CFH Pulse */
  {(int *)&pw_rf1cfh,
     (FLOAT *)&a_rf1cfh, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf1cfh,
     3200.0,
     1250.0,
     PSD_CFH_ON,
     0, 0, 0,(int *)&res_rf1cfh,0},

  /* RFPULSE PS5 - RF2 CFH Pulse */
  {(int *)&pw_rf2cfh,
     (FLOAT *)&a_rf2cfh, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf2cfh,
     3200.0,
     1250.0,
     PSD_CFH_ON,
     0, 0, 0,(int *)&res_rf2cfh,0},

  /* RFPULSE PS6 - ChemSat CFH Pulse 
   all information on this pulse is initialized in the
   chemsat routine, so the pointers here are incorrect
   but allow compilation */
  {(int *)&pw_rf0cfh,
     (FLOAT *)&a_rf0cfh,
     SAR_ABS_SINC1, 
     SAR_PSINC1, 
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     0,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf0cfh,
     3200.0,
     1000.0,
     PSD_PULSE_OFF,
     0, 0, 0,(int *)&res_rf0cfh,0},

  /* RFPULSE PS7 - MT CFH Pulse 
   all information on this pulse is initialized in the
   MT routine, so the pointers here are incorrect
   but allow compilation */
  {(int *)&pw_rf0cfh,
     (FLOAT *)&a_rf0cfh,
     SAR_ABS_SINC05, 
     SAR_PSINC05, 
     SAR_ASINC05,
     SAR_DTYCYC_SINC05,
     SAR_MAXPW_SINC05,
     0,
     SAR_MAXB1_SINC05,
     SAR_MAX_INT_B1_SQ_SINC05,
     SAR_MAX_RMS_B1_SINC05,
     90.0,
     &flip_rf0cfh,
     3200.0,
     1000.0,
     PSD_PULSE_OFF,
     0, 0, 0,(int *)&res_rf0cfh,0},

   /* RFPULSE PS8 - RF0 Pulse : adiabatic inversion */
   {(int *)&pw_rf0cfh,
     (FLOAT *)&a_rf0cfh, 
/*     SAR_ABS_INVI0, 
     SAR_PINVI0, 
     SAR_AINVI0,
     SAR_DTYCYC_INVI0,
     SAR_MAXPW_INVI0,
     1,
     MAX_B1_INVI0_180,
     MAX_INT_B1_SQ_INVI0_180,
     MAX_RMS_B1_INVI0_180,
     180.0,
     &flip_rf0cfh,
     5000.0,
     NOM_BW_INVI0,
*/
     SAR_ABS_ADIABATIC,
     SAR_ADIABATIC_EFF_WIDTH,
     SAR_A_ADIABATIC,
     SAR_DTYCYC_ADIABATIC,
     SAR_MAXPW_ADIABATIC,
     1,
     MAX_B1_ADIABATIC,
     MAX_INT_B1_SQ_ADIABATIC,
     MAX_RMS_B1_ADIABATIC,
     NOM_FA_ADIABATIC,
     &flip_rf0cfh,
     NOM_PW_ADIABATIC,
     1185.2,

     PSD_PULSE_OFF,
     0, 0, 0,(int *)&res_rf0cfh,0},

   /* RFPULSE PS9 - RF1 AUTOSHIM Pulse */ 
   {(int *)&pw_rf1as,
     (FLOAT *)&a_rf1as,
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf1as,
     3200.0,
     1250.0,
     PSD_AUS_ON,
     1, 0, 0,(int *)&res_rf1as,0},

  /* RFPULSE 10 - RF1 FastTG Pulse */
  {(int *)&pw_rf1ftg,
     (FLOAT *)&a_rf1ftg, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_90,
     MAX_INT_B1_SQ_SINC1_90,
     MAX_RMS_B1_SINC1_90,
     90.0,
     &flip_rf1ftg,
     3200.0,
     1250.0,
     PSD_FTG_ON,
     0, 0, 0,(int *)&res_rf1ftg,0},

  /* RFPULSE 11 - RF2 FastTG Pulse */
  {(int *)&pw_rf2ftg,
     (FLOAT *)&a_rf2ftg, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_180,
     MAX_INT_B1_SQ_SINC1_180,
     MAX_RMS_B1_SINC1_180,
     180.0,
     &flip_rf2ftg,
     3200.0,
     1250.0,
     PSD_FTG_ON,
     0, 0, 0,(int *)&res_rf2ftg,0},

  /* RFPULSE 12 - RF3 FastTG Pulse */
  {(int *)&pw_rf3ftg,
     (FLOAT *)&a_rf3ftg, 
     SAR_ABS_SINC1,
     SAR_PSINC1,
     SAR_ASINC1,
     SAR_DTYCYC_SINC1,
     SAR_MAXPW_SINC1,
     1,
     MAX_B1_SINC1_180,
     MAX_INT_B1_SQ_SINC1_180,
     MAX_RMS_B1_SINC1_180,
     180.0,
     &flip_rf3ftg,
     3200.0,
     1250.0,
     PSD_FTG_ON,
     0, 0, 0,(int *)&res_rf3ftg,0}

};

#endif /* rf_Prescan_INCL */












