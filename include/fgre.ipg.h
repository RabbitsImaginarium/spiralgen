/*
 *  fgre.h
 *  
 *  This file contains the prototype declarations of the callback
 *  functions for IPG side, defined in fgre.e.
 *
 *  Language : EPIC/ANSI C
 *  Author   : Roshy James Francis 
 *  Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

/*
  Version    		Author     Date       Comment
----------------------------------------------------------------------
 /main/mr_main/1	RJF	 14/Oct/1998	Initial version from fgre.h

 /main/mr_main/2  	PRA	 10/Mar/1999	Changed return type for
                                                get_pos_isi6()

                        GFN      06/Apr/1999    Removed prototypes already
                                                provided by psd_proto.h.

 */

#ifndef fgre_ipg_h
#define fgre_ipg_h

/*
 * @rsp section
 */
void psdisiupdate( void );
STATUS normscan( void );
STATUS ps2core( INT numdda, INT numvus, INT numnex );
STATUS scancore( INT num_rspslq );
STATUS get_spgr_phase( INT *seq, INT *phase );
STATUS get_spgr_defphase( INT *seq, INT *phase );
STATUS scanlock( void );
STATUS SetRspslices( void );
STATUS SatPrep( INT psdindex );
STATUS offset_to_seqcore( void );
STATUS offset_to_seqpass( void );
STATUS offset_to_seqmps2( void );
STATUS offset_to_seqcopy( void );
STATUS offset_to_eta_seqpause( void );
STATUS syncoff_seqmps2( void );
STATUS syncoff_seqcore( void );
STATUS set_rf1frequency( INT freq, LONG n_inst );
STATUS set_echo1frequency( INT freq, INT n_inst );
STATUS set_rf1phase( INT phase, INT n_inst );
STATUS set_echo1phase( INT phase, INT n_inst );
STATUS set_rf1amp( INT amp, LONG n_inst );
STATUS set_ps2_rf1amp( INT rf1amp );
STATUS set_gy1_amp( INT ph_encode_amp, LONG waveform_index );
STATUS set_gy1_amp2( INT ph_encode_amp, INT ph_rewind_amp,
                     LONG waveform_index );
STATUS set_gy1_ampimm( INT ph_encode_amp, LONG waveform_index );
STATUS set_gyb_amp( INT blip_amp, INT Etl );
STATUS load_ps2echo1dab( INT slice_num, INT echo_num, INT dabOP,
                         INT dab_view, TYPDAB_PACKETS acq_echo, INT load_ctrl );
STATUS set_ps2_gy1amp( INT ph_encode_amp, LONG waveform_index );
STATUS calc_yres_phase( INT *receiver_phase, INT index, INT view_num,
                        INT exciter_phase, INT rc_phase_chop );
STATUS set_yres_phase( INT index, INT view_num, INT exciter_phase,
                       INT rc_phase_chop );
STATUS set_dummy_phase( INT index, INT view_num, INT exciter_phase,
                        INT rc_phase_chop );
STATUS turn_rho_board( INT state );
STATUS set_seqcore_period( INT period, INT offset );
STATUS set_ps2frequencies( INT Psd_index );
STATUS set_seqps2_period( INT period, INT offset );
STATUS set_ps2_phase( INT Exphase );
STATUS copy_frame( INT source_pass, INT source_slice, INT source_echo,
                   INT source_view, INT dest_pass, INT dest_slice,
                   INT dest_echo, INT dest_view, INT num_copies,
                   TYPDAB_PACKETS op_ctrl );
STATUS copy_frame2( INT source_pass, INT source_slice, INT source_echo,
                    INT source_view, INT dest_pass, INT dest_slice,
                    INT dest_echo, INT dest_view, INT num_copies,
                    TYPDAB_PACKETS op_ctrl );
STATUS set_gyfe1_amp( INT flow_encode_amp, LONG waveform_index );
STATUS set_gyfe2_amp( INT flow_encode_amp, LONG waveform_index );
STATUS set_gz1_amp( INT flow_encode_amp, LONG waveform_index );
STATUS set_gzfc_amp( INT flow_encode_amp, LONG waveform_index );
STATUS set_gx1_amp( INT flow_encode_amp, LONG waveform_index );
STATUS set_gxfc_amp( INT flow_encode_amp, LONG waveform_index );
STATUS turnoff_isi6( void );
LONG get_pos_isi6( void );
STATUS fgre_loaddab_echo1b( LONG slice, LONG echo, LONG oper, LONG view,
                            TYPDAB_PACKETS acqon_flag, INT load_ctrl );
STATUS fgre_copyframe2( WF_PULSE_ADDR pulse, LONG frame_control,
                        LONG pass_src, LONG slice_src, LONG echo_src, 
                        LONG view_src, LONG pass_des, LONG slice_des,
                        LONG echo_des, LONG view_des, LONG nframes,  
                        TYPDAB_PACKETS acqon_flag );
STATUS fgre_copyframe3( WF_PULSE_ADDR pulse, LONG frame_control,
                        LONG pass_src, LONG slice_src, LONG echo_src, 
                        LONG view_src, LONG pass_des, LONG slice_des,
                        LONG echo_des, LONG view_des, LONG nframes,  
                        TYPDAB_PACKETS acqon_flag );
STATUS fgre_loaddab_echo1( LONG slice, LONG echo, LONG oper, LONG view,
                           TYPDAB_PACKETS acqon_flag, INT load_ctrl );
STATUS settriggerarray_dmy( INT number_of_triggers, LONG *trigger_array );
STATUS fgre_copyframe( WF_PULSE_ADDR pulse, LONG frame_control,
                       LONG pass_src, LONG slice_src, LONG echo_src,
                       LONG view_src, LONG pass_des, LONG slice_des,
                       LONG echo_des, LONG view_des, LONG nframes,
                       TYPDAB_PACKETS acqon_flag );
/*
 * @pg section
 */
void ssiupdates( void );
void ssisat( void );
STATUS pulsegen( void );

#endif /* fgre_ipg_h */

