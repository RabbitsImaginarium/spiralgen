/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * Interface for the Prep.e file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 13/Oct/1998
 */
/* do not edit anything above this line */

#ifndef Prep_h
#define Prep_h

/*
 * @host section
 */
STATUS create_prep_pulses( PULSE_TABLE *pulse_table );
STATUS prep_rfnkiller( INT flag );
STATUS prep_cvinit( PULSE_TABLE *pulse_table );
STATUS prep_cveval_rfinit( INT flag );
STATUS prep_cveval_init( INT flag, INT *Phorder, INT *Viewoffs,
                         INT *Intsldelay, INT *Seeddef, INT *Dda,
                         INT *ps2nex );
STATUS set_prep_times( INT *advminti, INT *advmaxti, INT *advmintdel,
                       FLOAT *ExtraTime, FLOAT *NumTimes, INT *reps,
                       FLOAT *advmintscan, INT *Pitslice, INT act_tr,
                       FLOAT *ExtraDelay, INT t_Exa, INT Time_ssi, INT Dda,
                       INT Dex, INT Intsldelay, INT flag );
STATUS set_prep_targets( PULSE_TABLE *pulse_table, LOG_GRAD *log_grad );
STATUS prep_cvcheck( INT advminti, INT advmaxti, INT flag );
STATUS prep_slice_order( INT Gating, INT flag );
STATUS prep_predownload( STATUS flag );
STATUS pass_rf0( INT *pwrf0, INT *pwrf0a, INT flag );

/*
 * @pg section
 */
STATUS prep_pulsegen( const INT Intsldelay, const INT time_ssi,
                      const INT num_scanlocs, const INT flag );

/*
 * @rsp section
 */
STATUS prep_mror_update( INT flag, DOUBLE rxslthick, DOUBLE contslthick,
                         LOG_GRAD *lgrad, INT contdebug );
STATUS ps2prepcore( INT flag );
STATUS prepcore( INT flag );
STATUS scanprep( INT flag );
STATUS scanwait( void );
STATUS perfprep( void );

#endif /* Prep_h */

