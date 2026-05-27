/* 	GE Medical Systems
 *	Copyright (C) 1998- The General Electric Company
 *  RTFgre.h
 *  
 *  Type definitions used for RTIA	
 *
 *  Language : EPIC/ANSI C
 *  Author   : Roshy J. Francis. 
 *  Date     : 16-Sep-1998 
 */
/* do not edit anything above this line */

/*
   Version    				Author     Date       Comment
----------------------------------------------------------------------
*/


#ifndef RTIA_defs_h 
#define RTIA_defs_h

#define ACTIVATE_IR 4
#define ACTIVATE_CHEMSAT 2
#define ACTIVATE_SPSAT 1
#define MINPH_RF_2DTF26 1
#define MINPH_RF_RTIA 2
#define RTIA_FOV_ZOOM_FACTOR 0.75 

typedef struct { 
        int tmin;
        int tmin_total ; 
        int min_seqrfamp ; 
        int minseqgram_t ; 
        int minseqgrddrv_t ; 
        int minseqcoil_t ; 
        int max_seqsar; 
        int max_slicesar; 
} RTIA_SAFE_TIMES ;

typedef struct {
                FLOAT pw; 
                FLOAT dc ; 
                FLOAT amp; 
                FLOAT peaksar; 
                FLOAT avesar ; 
} RTIA_POWERMON_VALUES ; 


#endif /* fgre_host_h */

