/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * Interface for the Mpl.e file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 03/Aug/1998
 */

/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.1   03-Aug-1998  GFN         Initial version.
 */

#ifndef Mpl_h
#define Mpl_h

/*
 * @host section
 */
STATUS mpl_cvinit( void );
STATUS mpl_cveval_init( INT flag, INT *isi_delay );
STATUS mpl_sat_scale( INT flag, INT *Dda );
STATUS mpl_rfscale( INT flag, INT *min_seqrfamp, INT *maxslicesar,
                    INT RF_FREE, RF_PULSE *rfpulselist);
STATUS mpl_setacqparams( INT tmintotal, INT cssattime, INT spsattime,
                         INT cssat, INT tminsatoff, INT otherslicelimit,
                         INT *slquantpertrig, INT *slquant_1,
                         INT avail_imagetime, INT *Maxslquant, INT *Acqs,
                         INT *Avmintr, INT flag );
STATUS set_mpl_times( DOUBLE tr, INT reps, INT pass_time,
                      INT ccsrelax_time, DOUBLE extraTime, INT Acqs,
                      DOUBLE Truenex, INT sat_times, float *advmintscan,
                      INT *pi_tslice, float *numTimes, INT flag );
STATUS mpl_predownload( INT flag, float *MaxB1, float *avesar, float *peaksar,
                        INT actTR, INT slquant_1, INT RF_FREE,
                        RF_PULSE *rfpulselist );
STATUS mpl_cvcheck( INT flag );

/*
 * @pg section
 */
STATUS mpl_get_seqtime( INT actTR, INT cssattime, INT spsattime, INT slquant_1,
                        INT sc_deadtime, INT ps2_deadtime, INT flag );

/*
 * @rsp section
 */
STATUS mpl_satrotate( INT flag );
STATUS mpl_settriggers( INT flag );
STATUS mplcore( void );
STATUS ps2mplcore( INT numvus, INT rsp_nex );

#endif /* Mpl_h */

