/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  Prep.h
 *      Developer:  Pradeep S.
 *
 * $Source: Prep.h $
 * $Revision: 1.3 $  $Date: 8/28/98  17:30:55  $
 *
 *@Description
 *
 * This is the prototype include file for the Prep project.
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
 sccs1.2      12-Aug-98    Dale Thayer
              ANSI C corrections made to original ANSI Prep.h file.
 
 sccs1.3      28-Aug-98    Dale Thayer 
              Made routine prep_mror_update a void return.

 /main/mr_main/3	13-Oct-1998	Roshy Francis 
					Splitting the header file into host and ipg ones.
					Deleted IPG protos and put them in Prep.ipg.h.
					Changed the filename to Prep.host.h
								
 *@End*************************************************************/

#ifndef prep_host_h
#define prep_host_h

STATUS create_prep_pulses( PULSE_TABLE *pulse_table );
STATUS prep_rfnkiller( INT flag );
STATUS prep_cvinit( PULSE_TABLE *pulse_table );
STATUS prep_cveval_rfinit( INT flag );

STATUS prep_cveval_init( INT flag, INT *Phorder, INT *Viewoffs, INT *Intsldelay,
                         INT *Seeddef, INT *Dda, INT *ps2nex );

STATUS set_prep_times( INT *advminti, INT *advmaxti, INT *advmintdel, 
                       FLOAT *ExtraTime, FLOAT *NumTimes, INT *reps,
                       FLOAT *advmintscan, INT *Pitslice, INT act_tr,
                       FLOAT *ExtraDelay, INT t_Exa, INT Time_ssi, 
                       INT Dda, INT  Dex, INT Intsldelay, INT Etl, INT flag );

STATUS set_prep_targets( PULSE_TABLE *pulse_table, const LOG_GRAD *loggrd );

STATUS prep_cvcheck( INT advminti, INT advmaxti, INT flag );

STATUS prep_slice_order( INT Gating, INT flag );
STATUS prep_predownload( INT flag );
STATUS pass_rf0( INT *pwrf0, INT *pwrf0a, INT flag );


#endif /* prep_host_h */

