/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: Fmpvas.host.h $
 * $Revision: 1.2 $  $Date: 4/25/98 02:38:31 $
 *  
 * Interface for the Fmpvas.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

#ifndef Fmpvas_host_h
#define Fmpvas_host_h

/*
 * @host section
 */
STATUS fmpvas_cvinit( PULSE_TABLE *pulse_table );
STATUS fmpvas_cveval_init( INT *Gating, INT *SeedDef,
                           INT *Spsatxkiller_flag, INT flag );
STATUS fmpvas_cveval( INT actTR, INT *Phorder, INT *Viewoffs,
                      INT views_per_seg, INT *Dda, INT flag );
STATUS set_fmpvas_ccsat( INT flag );
STATUS set_fmpvas_minph_limit( FLOAT *minphase_limit, FLOAT *Overlap,
                               INT flag );
STATUS set_fmpvas_times( FLOAT *usetr, FLOAT *extraTime, FLOAT *numTimes,
                         INT actTR, FLOAT *advmintscan, INT *tslice,
                         INT NFrames[], INT Nframe_entries, DOUBLE truenex,
                         INT dis_dex, INT views_per_seg, INT *Piviews,
                         INT Passtime, FLOAT *Extra_Acqtime, INT Tseq_Prep,
                         INT flag );
STATUS fmpvas_setacqparams( INT *Acqs, INT *p_advmintr, INT *avail_imagetime,
                            INT *advmaxphases, INT *slcs_per_trig,
                            INT *slquant_1, INT *Pidmode, INT flag,
                            INT e_flag );
STATUS fmpvas_calcPulseParams( void );
STATUS fmpvas_predownload( INT actTR, INT pi_tslice, INT slquant_1,
                           DOUBLE truenex, INT Gating, INT copy_flag,
                           INT cs_flag, INT numPulses, RF_PULSE rfpulse[],
                           INT maxB1, ENTRY_POINT_TABLE *entryPoint, INT entry,
                           INT Phorder, INT flag, INT e_flag );
STATUS fmpvas_cvcheck( INT Avail_image_time, INT Tmin_total, INT actTR,
                       INT advmintr, INT maxphases, INT Viewoffs, INT flag,
                       INT Phorder, INT e_flag );
STATUS pass_minwait( INT *Minwait, INT flag );
STATUS pass_prep_dda( INT *prepdda, INT flag );

#endif /* Fmpvas_host_h */
