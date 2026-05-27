/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: Fastcard.host.h $
 * $Revision: 1.11 $  $Date: 4/25/98 01:08:28 $
 *  
 * Function prototypes for the Fastcard functions defined in Fastcard.e.
 *  
 * Language : ANSI C
 * Author   : Pradeep S
 * Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

/*
  Version   Author     Date       Comment
--------------------------------------------------------------
  CDP0.1     GFN    25-Sep-1997   Removed unsafe datatypes from interface.

  CDP0.2     GFN    24-Oct-1997   Changed vvs_init() for fcine_cvinit().

  ******************** Initial CV-1 Version ************************

  sccs1.7    GFN    21-Jan-1998   Added fcine_passviewtab() and 
                                  fcine_setrawheader().
                                  Added ermes_flag argument to
                                  fastcard_setacqparams().
                                  Made set_qrskiller() a static function.

  sccs1.8    GFN    22-Jan-1998   Made set_qrskiller() a public function again.
                                  Notice that is has a new argument (e_flag).

  sccs1.9    GFN    26-Jan-1998   Moved Fast CINE code to a different module
                                  (FastCINE.h).
                                  Added e_flag argument to
                                  fastcard_predownload().
                                  Removed K&R declarations.

  sccs1.10   GFN    07-Mar-1998   Added Fast CINE flag argument to
                                  fastcard_setacqparams().

  sccs1.11   GFN    24-Apr-1998   Added ermes flag to set_fastcard_targets().
                                  Removed errno and errstr from
                                  fastcard_setacqparams() and
                                  fastcard_cvcheck().

        Dale Thayer 28-Aug-1998   Made routine fccoredda a void return.

             GFN    06-Apr-1999   Added fastcard_calcPulseParams().
             AKG    01-May-2000   Added advminslquant arg to 
                                  fastcard_setacqparams().

 */

#ifndef Fastcard_host_h
#define Fastcard_host_h

/*
 * @host section
 */
STATUS set_qrskiller( INT e_flag, INT f_flag );
STATUS create_fastcard_pulses( PULSE_TABLE *pulse_table );
STATUS fastcard_cvinit( PULSE_TABLE *pulse_table );
STATUS fastcard_cveval_init( INT *Gating, INT *Phorder, INT f_flag );
STATUS set_fastcard_targets( PULSE_TABLE *pulse_table, const LOG_GRAD *p_loggrd,
                             INT e_flag );
STATUS set_fastcard_minph_limit( FLOAT *minphase_limit, INT f_flag );
STATUS set_fastcard_times( FLOAT *usetr, FLOAT *extraTime, FLOAT *numTimes,
                           INT *reps, FLOAT *advmintscan, INT *tslice,
                           INT *NFrames, INT Nframe_entries, INT dis_daqs,
                           INT dis_dex, INT views_per_seg, FLOAT *extraAcqTime,
                           INT *Piviews, INT f_flag );
STATUS fastcard_retrospective_init( INT *copy_flag, INT f_flag );
STATUS fastcard_setacqparams( INT *Acqs, INT tminTotal, INT actTR,
                              INT *avail_imagetime, INT *advmaxphases,
                              INT *advmaxslquant, INT *advminslquant,
                              INT *slcs_per_trig,
                              INT *slquant_1, INT Other_slice_limit,
                              INT copy_flag, INT *Pidmode, INT cs_flag,
                              INT cssattime, INT feature_flag, INT ermes_flag,
                              INT fcine_flag );
STATUS fastcard_calcPulseParams( void );
STATUS fastcard_predownload( INT actTR, INT pi_tslice, INT slquant_1,
                             DOUBLE truenex, INT Gating, INT copy_flag,
                             INT cs_flag, INT numPulses,
                             RF_PULSE *rfpulse, DOUBLE maxB1,
                             ENTRY_POINT_TABLE *entryPoint, INT entry,
                             FLOAT *flip_RF1, INT f_flag, INT e_flag );
STATUS fastcard_cvcheck( INT Avail_image_time, INT Tmin_total, INT min_delay,
                         INT maxphases, INT f_flag, INT e_flag );

#endif /* Fastcard_host_h */

