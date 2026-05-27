/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: feature_flag_defs.h $
 * $Revision: 1.8 $  $Date: 2/13/98 11:24:28 $
 *  
 * Definition of feature flags for the bit mask.
 *  
 * Language : ANSI C
 */
/* do not edit anything above this line */

/*
 Version   Author     Date        Description
 ________________________________________________________________

                                  Initial version.
 
 sccs1.6    GFN    29-Jul-1997    Added SPECIR, RESPGATE, CARDGATE,
                                  and TAGGING. Wrapped code in #ifndef block.
                                  Changed bit numbers to powers of two for easy
                                  update.
 
 sccs1.7    JAP    11-Feb-1998    Added ECHOTRAIN.
 
 sccs1.8    GFN    13-Feb-1998    Added FASTCINE.

            RJF    16-Sep-1998    Added RTIA and REVERSE CENTRIC support.

            JFS    06-JAN-1999    Added STRESS_* for STRESS function appl.

            RJF    31-Aug-1999    Changed RTIA to RTIA98 to differentiate RTIA98 Vs RTIA
                                  platform.
 */

#ifndef feature_flag_defs_h
#define feature_flag_defs_h

/* define bit masks for feature flag */
#define FGRE        (1<<0)    /* Generic fgre - set to 0 if engine */
#define MPH         (1<<1)    /* Multi-phase */
#define MPL         (1<<2)    /* Multi-planar */
#define IRPREP      (1<<3)    /* Inversion Recovery prep */
#define DEPREP      (1<<4)    /* Driven Equilibrium prep */
#define FASTCARD    (1<<5)    /* Fastcard cine */
#define FASTCARD_PC (1<<6)    /* Fastcard phase contrast */
#define FASTCARD_MP (1<<7)    /* Fastcard single-phase, multi-slice:
                                 multi-planar */
#define CHEMSAT     (1<<8)    /* Chem Sat  */
#define SPSAT       (1<<9)    /* Spatial Sat */
#define GATEDTOF    (1<<10)   /* FMPVAS with gating*/
#define UNGATEDTOF  (1<<11)   /* FMPVAS without gating */
#define SPECIR      (1<<12)   /* Spectrally Selective IR */
#define RESPGATE    (1<<13)   /* Respiratory gated */
#define CARDGATE    (1<<14)   /* Cardiac gated */
#define TAGGING     (1<<15)   /* Tags */
#define ECHOTRAIN   (1<<16)   /* Echotrain */
#define FASTCINE    (1<<17)   /* Full RR Fastcard CINE */
#define RTIA98 	    (1<<18)   /* Realtime Interactive */

/* define some phase acquisition order parameters */
#define SEQUENTIAL 0
#define CENTRIC 1
#define SEGMENTED_INTERLEAVED 2
#define REVERSE_CENTRIC 3 

/* Feature flags for Stress Function Spplication */
#define STRESS_PAUSE    (1<<0)   /* enable pause feature */
#define STRESS_TAGGING  (1<<1)   /* enable variable tagging */
#define STRESS_VPS      (1<<2)   /* enable variable VPS for CINE */


#endif /* feature_flag_defs_h */

