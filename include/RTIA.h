/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * Filename: RTIA.h 
 * 
 * Interface file for RTIA.e.
 * 
 * Language : ANSI C
 * Author   : Roshy James Francis. 
 * Date     : 16/Sep/1998
 */
/* do not edit anything above this line */

/*
 Date		Author	Comments	
--------------------------------------------------
 16/Sep/1998	   RJF	Initial version.

 28/Jun/1999    RJF     Adding recon/tps interface 
                       	function prototypes to get rid of
                        compilation warnings.

 28/Jul/1999    GFN     Removed previous changes because those prototypes
                        are provided through TPS header files.
 
 07/Oct/1999    RJF     Accomodating re-design of RTIA module
                        Added feature flags for extensibility.
                        addition/removal/changes to function prototypes
 06/March/2000  NDG     RTCA (Real-Time Coronary Artery) feature definitions.
 */

#ifndef RTIA_h
#define RTIA_h

/* These are for setting the bitmasks in the image header in
   realtime. Refer project AnnoMRChanges file : MRGETable
   RJF, 03, December 1998. Moved from RTIA.e to here - 
   RJF, 1 Sep 1999  */

#define FLOWCOMP_BITMASK 8
/* SAT is annotated if the 5th bit in the IOPT bits is set */
#define SAT_BITMASK 32 
#define FAST_GRE 20 
#define FAST_SPGR 22 
#define SUPERIOR_DEFAULT_SAT 1
#define INFERIOR_DEFAULT_SAT 2
#define RIGHT_DEFAULT_SAT 4
#define LEFT_DEFAULT_SAT 8
#define ANTERIOR_DEFAULT_SAT 16
#define POSTERIOR_DEFAULT_SAT 32
#define RTIA_TI_ANNOTATE_LIMIT 2500000 /* From Dick Prorock */

/* Definitions for bitmask based feature flags for visibility and 
   availability */

#define FLOWCOMP_REALTIME 0x01
#define SPGR_REALTIME 0x2
#define FATSAT_REALTIME 0x4
#define SPATIAL_SAT_REALTIME 0x8
#define IR_REALTIME 0x10
#define FOV_REALTIME 0x20
#define SWAP_PF_REALTIME 0x40
#define AUTO_NEX_REALTIME 0x80
#define ROTATE_REALTIME 0x100
#define TRANSLATE_REALTIME 0x200
#define FOV_ADDINFO_REALTIME 0x400
#define SLTHICK_REALTIME 0x800
#define FLIP_REALTIME 0x1000
#define SPECTRAL_SPATIAL_REALTIME 0x2000

/* This file will provide prototypes for general realtime functions. */
void init_realtime_rsps ( void );
void init_realtime_processing (void );
void init_id_addr_lkup_table (int  *table);
STATUS realtime_rsp_update ( unsigned long *inputbuffer, int *status);
STATUS generate_recon_id_value_pkt (unsigned long *recon_id_value_buffer);

#endif


