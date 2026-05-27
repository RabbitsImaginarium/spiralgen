/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  Mpl.host.h
 *      Developer:  Pradeep S.
 *
 * $Source: Mpl.host.h $
 * $Revision: 1.1 $  $Date: 8/12/98  13:45:30  $
 *
 *@Description
 *
 * Prototype file for the Mpl.e EPIC+ file.
 *
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version      Date         Author
              Description
 ------------------------------------------------------------------
 sccs1.1      11-Aug-98    Dale Thayer
              ANSI C corrections made to original ANSI Mpl_incl.h file.
              File was changed to Mpl.h name.

              19-Oct-98    Roshy J. Francis
              Changed declarations for mpl_cveval_init and mpl_sat_scale.

              06-Apr-1999  Gabriel Fernandez
              Added mpl_calcPulseParams().

 *@End*************************************************************/

#ifndef MPL_HOST_H
#define MPL_HOST_H


/*
 * @host section
 */
STATUS mpl_cvinit( void );
STATUS mpl_cveval_init( int flag, int *isi_delay, int *Dda );
STATUS mpl_cvcheck( int flag);
STATUS mpl_calcPulseParams( void );
STATUS mpl_predownload( int flag, float MaxB1[], float *avesar,
                        float *peaksar, int actTR, int slquant_1,
                        int RF_FREE, RF_PULSE *rfpulselist );
STATUS mpl_sat_scale( int flag );
STATUS mpl_rfscale( int flag,int *min_seqrfamp, int *maxslicesar,
                 int RF_FREE, RF_PULSE *rfpulselist);
STATUS mpl_setacqparams( int tmintotal, int cssattime, int spsattime,
                         int cssat, int tminsatoff, int otherslicelimit,
                         int *slquantpertrig, int *slquant_1,
                         int avail_imagetime, int *Maxslquant, int *Acqs,
                         int *Avmintr, int flag );
STATUS set_mpl_times( double tr, int reps, int pass_time, int ccsrelax_time,
                      double extraTime, int Acqs, double Truenex,
                      int sat_times, float *advmintscan, int *pi_tslice, 
                      float *numTimes, int flag );

#endif /* MPL_HOST_H */

