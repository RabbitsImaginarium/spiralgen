/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      Include File Name: rt_rsp_ids.h
 *      Author :Roshy James Francis
 *
 * Source: rt_rsp_ids.h 
 */
 /*@Synopsis
 *		RSP ID definition file for RTIA 98.
 */

 /*@Description
 */

 /* Author     Date        Description of changes

    RJF                    Initial version.
    
    RJF        07/Oct/99   Adding avialability and visibility for 
                           extensibility as part of Pulsar Realtime echotrain.
    NDG        24/Dec/99   New entries in table for RTCA spirals
    NDG        06/March/00  Additional entries for RTCA spirals.
*@End*********************************************************/

/* Include this only once in any given compilation.*/

#ifndef RT_RSP_IDS_INCL
#define RT_RSP_IDS_INCL

/* PSD/TPS RSP interface return values */
/* This should be in sync with the definitions in tps_rsp.h  */
/* in tps_rsp project */

#define NEW_DATA 1 
#define NO_NEW_DATA 2 

/* Contrast control operator RSP IDs */

#define CONT_FOV 1 
#define CONT_FLOWCOMP 2 
#define CONT_SPSAT 3 
#define CONT_CHEMSAT 4 
#define CONT_SPGR 5 
#define CONT_IR 6 

/* IDs for individual entries for the Rotation matrix */


#define CONT_ROT00 7
#define CONT_ROT01 8
#define CONT_ROT02 9
#define CONT_ROT10 10
#define CONT_ROT11 11 
#define CONT_ROT12 12 
#define CONT_ROT20 13
#define CONT_ROT21 14
#define CONT_ROT22 15

/* This is used in the PSD to set the transmit and receive frequencies */
/* Reverse Gradwarp corrected RSPs 					*/

#define CONT_GWTLOC 16 
#define CONT_GWRLOC 17 
#define CONT_GWPLOC 18 

/* These is the prescribed location - Used in annotation */

#define CONT_TLOC 19 
#define CONT_RLOC 20 
#define CONT_PLOC 21 


/* More Operator Control RSP IDs */
/* This will be used to pass these RSPs to Recon too */

#define CONT_RX_UID 22 
#define CONT_AUTO_NEX 23 

/* Additional PSD/Recon Interface RSP IDs */

#define CONT_PSEQ_BITS 24 
#define CONT_IOPT_AND_BITMASK 25 
#define CONT_SAT_BITS 26 
#define CONT_SUPP_TECH 27 
#define CONT_TR 28 
#define CONT_TE 29 
#define CONT_TI 30 
#define CONT_IPG_UID 31 

/* RTIA wake up RSPs - We need them ID'ed because PSD provides the 
  ID/address translation and the lkup/updation is done through 
  rsp_id_add_lkup_table. */

#define CONT_FOV_STATE 32

/* CONT_FOV_STATE is provided by PSD but is not used. PSD will always 
   start with the Initial LX FOV value, and hence UI can show this 
   as supported and in the unselected mode. */
  
#define CONT_SPSAT_STATE 33
#define CONT_CHEMSAT_STATE 34
#define CONT_SPGR_STATE 35
#define CONT_FLOWCOMP_STATE 36
#define CONT_IR_STATE 37

#define CONT_CORE_TIME 38
#define CONT_FCCORE_TIME 39
#define CONT_SPSAT_TIME 40 
#define CONT_CHEMSAT_TIME 41
#define CONT_IR_TIME 42 

#define CONT_SCAN_TIME 43  /* For, recon - change header */
#define CONT_IOPT_OR_BITMASK 44 
#define CONT_SWAP_PF 45 /* Operator RSP for Swapping phase/Freq */

/* The following RSPs are for Recon to transpose/Rotate the images 
   in Realtime. PSD just passes this info down to recon */
#define CONT_IMAGE_ROTATE_ANGLE 46 
#define CONT_TRANSPOSE_IMAGE_FLAG 47
#define CONT_CHRONO 48 
#define CONT_RECON_QUEUE 49

/* Following are added to pass the image/gw corner point 
   information from the application to Recon. Corresponding RSPs 
   are defined in RealTime.e */

/* Recon nolonger needs cont_*loc or Cont_Rot* information as these 
   corner points are readily available. */

#define CONT_IMAGE_P0X 50
#define CONT_IMAGE_P0Y 51
#define CONT_IMAGE_P0Z 52
#define CONT_IMAGE_P1X 53
#define CONT_IMAGE_P1Y 54
#define CONT_IMAGE_P1Z 55
#define CONT_IMAGE_P2X 56
#define CONT_IMAGE_P2Y 57
#define CONT_IMAGE_P2Z 58
#define CONT_GW_P0X 59
#define CONT_GW_P0Y 60
#define CONT_GW_P0Z 61
#define CONT_GW_P1X 62
#define CONT_GW_P1Y 63
#define CONT_GW_P1Z 64
#define CONT_GW_P2X 65
#define CONT_GW_P2Y 66
#define CONT_GW_P2Z 67

#define CONT_CONCAT_SAT 68 /* To annotate spatial SAT as concat */
#define CONT_FREQ_DIR 69 /* To annotate Frequency direction - sent from host */

/* RTIA extensibility bfeature flags */
#define CONT_AVAIL_FLAG 70 
#define CONT_VISIBLE_FLAG 71 

/* RTCA feature flags */
#define CONT_FOV_MIN 72
#define CONT_FOV_MAX 73
#define CONT_FOV_STEP 74
#define CONT_SLTHICK 75
#define CONT_SLTHICK_MIN 76
#define CONT_SLTHICK_MAX 77
#define CONT_SLTHICK_STEP 78
#define CONT_FLIP 79
#define CONT_FLIP_MIN 80
#define CONT_FLIP_MAX 81
#define CONT_FLIP_STEP 82
#define CONT_SPECTRAL_SPATIAL 83
#define CONT_RSCALEF 84
#define CONT_B0_CALC_MAP 85

/*----------------End of ID Definitions. ------ */
#define CS_MAX_NUM_RSPS 256

#endif 
