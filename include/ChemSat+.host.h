/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: ChemSat+.host.h $
 * $Revision: 1.1 $  $Date: 4/25/98 01:26:45 $
 *  
 * Interface for the ChemSat+.e file.
 *  
 * Language : ANSI C/EPIC+
 * Author   : Pradeep S 
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

#ifndef ChemSat_plus_host_h
#define ChemSat_plus_host_h

/*
 * @host section
 */
STATUS create_chemsat_pulses( PULSE_TABLE *pulse_table );
STATUS ChemSatInit( PULSE_TABLE *pulse_table );
STATUS ChemSat_set_params( INT *cs_flag, INT f_flag );
STATUS ChemSat_Init_pulse_fields( void );
STATUS ChemSatRFinit( const INT cs_flag );
STATUS set_chemsat_targets( PULSE_TABLE *pulse_table, const LOG_GRAD *loggrd,
                            const INT e_flag );
STATUS ChemSatEval( INT *cstime, const INT board_index, const INT cs_flag );
STATUS ChemSatPredownload( void );
STATUS ChemSatIAmp( INT cs_flag );
void cs_set_grad_scale( DOUBLE grad_scale );
STATUS ChemSatCheck( INT f_flag );

/* Begin RTIA Addition */
STATUS deactivate_chemsat_in_prescan( RF_PULSE *rfpulselist );

STATUS activate_chemsat_pulses ( GRAD_PULSE *gradxlist,
                                 GRAD_PULSE *gradylist,
                                 GRAD_PULSE *gradzlist,
                                 RF_PULSE *rfpulselist,
                                 int use_flowcomp_pulse_list );

STATUS deactivate_chemsat_pulses( GRAD_PULSE *gradxlist,
                                  GRAD_PULSE *gradylist,
                                  GRAD_PULSE *gradzlist,
                                  RF_PULSE *rfpulselist,
                                  int use_flowcomp_pulse_list );
/* End RTIA Addition */

#endif /* ChemSat_plus_host_h */

