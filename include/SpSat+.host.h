/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: SpSat+.host.h $
 * $Revision: 1.2 $  $Date: 8/18/98 20:14:24 $
 * 
 * 
 * 
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 05/27/98
 */


/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------

sccs1.??   18-Aug-98   Dale Thayer  Corrections to ANSI conversion errors.

 */

/* Local header files */

#ifndef SpSat_plus_host_h
#define SpSat_plus_host_h

/* @host section */

STATUS create_sp_pulses( PULSE_TABLE *pulse_table);
STATUS  set_spsat_targets(PULSE_TABLE *pulse_table);

STATUS sp_predownload(void);
STATUS  set_satgapzpos( float value);
STATUS set_satgapzneg (float value);

STATUS sp_init_rf( INT *pw_ptr, FLOAT *amp_ptr, FLOAT *flip_ptr,
                   INT type, RF_PULSE *rfstruct );

/* RJF/PS changing prototype for SpSatInit - See SpSat+.e for details*/
STATUS SpSatInit(PULSE_TABLE *pulse_table,INT sat_type);

STATUS sp_set_num_pulses( RF_PULSE *rf_struct, GRAD_PULSE *grad_struct );

STATUS sp_set_rfpulse( INT pulse_type, RF_PULSE *rf_struct, INT *resoln,
                       INT *pw_rf, INT *bw_rf, INT sat_band_type);

STATUS sp_set_slice_select( INT *pw_slice_select, INT *pw_slice_select_a,
                            INT *pw_slice_select_d, INT pw_rf,
                            FLOAT *amp_slice_select, INT *bw_rf,
                            DOUBLE thickness, DOUBLE targetamp,
                            INT target_rt, INT pulse_type,
                            INT bd_index );

STATUS sp_initrfpulseInfo( RF_PULSE_INFO rfPulseInfo[],INT  pulse );

void sp_set_grad_scale(DOUBLE grad_scale);

STATUS sp_scalerfpulses( DOUBLE weight, INT gcoiltype,
                         RF_PULSE rfpulse[], INT numentry,
                         RF_PULSE_INFO rfPulseInfo[], INT pulse );

STATUS sp_get_rot_matrix( long *dest, long *source);

STATUS sp_get_scaninfo_matrix( long *source, SCAN_INFO *dest );

STATUS sp_init_satloggrd( LOG_GRAD *sloggrd );

STATUS SpSatEval( INT *time_spsat,INT vrgsat, INT bd_index, INT f_flag );

/* RJF/PS - Changing prototypes for 'check' to take latest 
   changes from cardiac for the function definiton. 15/Oct/1998 */
STATUS SpSatCheck( void );

STATUS SatGetZOffset( DOUBLE locpos, DOUBLE locneg,
                      INT *offset1, INT *offset2 );

STATUS SatCatRelaxtime(INT acqs,INT seq_time,INT seq_type,INT *relaxers);

STATUS SatPlacement( INT numPasses , INT f_flag );

void SpSatIAmp(void );

/* Begin RTIA addition */
STATUS activate_rtia_spsat_pulses (GRAD_PULSE *gradxlist,
                            GRAD_PULSE *gradylist,
                            GRAD_PULSE *gradzlist,
                            RF_PULSE *rfpulselist,
                            int use_flowcomp_list);

STATUS deactivate_rtia_spsat_pulses (GRAD_PULSE *gradxlist,
                            GRAD_PULSE *gradylist,
                            GRAD_PULSE *gradzlist,
                            RF_PULSE *rfpulselist,
                            int use_flowcomp_list);

STATUS deactivate_spsat_in_prescan (RF_PULSE *rfpulselist);
/* End RTIA addition */

#endif /* SpSat_plus_host_h */

