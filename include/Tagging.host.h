/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: Tagging.host.h $
 * $Revision: 1.10 $  $Date: 5/11/98 13:16:38 $
 *  
 * Interface code for the Tagging.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

/*
    Delta       Date      Author      Comments
  -----------------------------------------------------------
  sccs1.1    28/Jul/1997  GFN         Initial CV-1 version.
 
  sccs1.6    21/Jan/1998  GFN         Added flag arg. to tagging_cvinit.
                                      Added ermes_flag, ssi_time and 
                                      rfpulseInfo args. to tagging_cveval(). 
                                      Added ssi_time arg. to
                                      tagging_pulsegen().

  sccs1.7    29/Jan/1998  GFN         Changed prototype for tagging_cvcheck().
                                      Removed K&R declarations.

  sccs1.8    03/Mar/1998  GFN         Removed f_flag argument from
                                      tagging_cvinit().

  sccs1.9    19/Mar/1998  GFN         Added prototype for
                                      tagging_cveval_init().

  sccs1.10   11/May/1998  GFN         Updated tagging_cveval(),
                                      tagging_cvinit(),
                                      create_tagging_pulses(), and
                                      set_tagging_targets().

             08/Dec/1998  GFN         Removed seq_len argument from
                                      tagging_cveval().

             06/Apr/1999  GFN         Added tagging_calcPulseParams().

 */

#ifndef Tagging_host_h
#define Tagging_host_h

/*
 * @host section
 */
STATUS tagging_cvinit( PULSE_TABLE *pulse_table, const INT e_flag );
STATUS tagging_cveval_init( void );
STATUS tagging_cveval( INT *phase_order, const INT seq_len, const INT bd_idx,
                       const INT f_flag, const INT e_flag, const INT ssi_time,
                       RF_PULSE_INFO *rfpulse_info );
STATUS tagging_cvcheck( const INT f_flag, const INT e_flag );
STATUS tagging_calcPulseParams( void );
STATUS tagging_predownload( RF_PULSE *rfpulse, ENTRY_POINT_TABLE *entryPoint,
                            const INT entry, const INT numPulses,
                            const INT actTR, const DOUBLE maxB1,
                            const INT f_flag );
STATUS create_tagging_pulses( PULSE_TABLE *pulse_table, const INT e_flag );
STATUS set_tagging_targets( PULSE_TABLE *pulse_table, const LOG_GRAD *loggrd,
                            const INT e_flag );
STATUS tagging_cveval_rfinit( const INT f_flag );
STATUS tagging_grad_scale( const INT f_flag);
STATUS tagging_setpulsenum( RF_PULSE *rfpulse, const INT f_flag );
STATUS tagging_piait_adjust( INT *Piait, const INT f_flag );

#endif /* Tagging_host_h */

