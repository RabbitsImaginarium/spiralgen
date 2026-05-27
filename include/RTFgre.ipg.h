/* 	GE Medical Systems
 *	Copyright (C) 1998- The General Electric Company
 *  RTFgre.h
 *  
 * 	IPG/RSP Interface file for RTFgre.e 
 *
 *  Language : EPIC/ANSI C
 *  Author   : Roshy J. Francis. 
 *  Date     : 16-Sep-1998 
 */
/* do not edit anything above this line */

/*
   Version    Author     Date       	Comment
----------------------------------------------------------------------
              RJF     19/Oct/1998       Initial version.
                                        Created from RTFgre.h.

              LR      12/Feb/1999       Removed fgre_copyframe_fc() 
                                        for MRIge50710. 

              RJF     28/Jun/1999       MRIge53084- adding SPGR proto.
 */

#ifndef RTfgre_ipg_h
#define RTfgre_ipg_h

STATUS RTIA_set_seq_deadtime( int flag, int actTR, int cssattime,
                              int spsattime, int hard180time, long coretime,
                              long flowcompcoretime );

STATUS rtiacore( void );

STATUS GetSpgrPhase(INT index, INT *phase);

void RTIAExit (int featureflag);

STATUS GetSPGRPhase ( INT index, INT *phase );

STATUS InitSPGRTable(INT Seed); 

STATUS PlayWaitSequence( void );

STATUS set_seqcorefc_period( int period,int offset );

STATUS turn_rho_board_fc( int state );

STATUS set_echo1fcphase( int phase );

STATUS offset_to_seqcorefc( void );

STATUS syncoff_seqcorefc( void );

STATUS set_rf1fcfrequency( int freq );

STATUS set_echo1fcfrequency( int freq );

STATUS set_rf1fcphase( int phase );

STATUS set_rf1fcamp( short amp );

STATUS set_gy1fc_amp( short ph_encode_amp, int waveform_index,
                      int rewinder_on );

STATUS set_gy1fc_ampimm( short ph_encode_amp, int waveform_index, int rewinder_on );

STATUS set_fc_readout_amp( short amp );

STATUS set_fc_prephaser_amp( short amp );

STATUS set_fc_xkiller_amp( short amp );

STATUS get_fc_readout_amp( short *amp );

STATUS get_fc_prephaser_amp( short *amp );

STATUS get_gxfcfc_amp( short *amp ); 

STATUS set_gxfcfc_amp( short amp );

STATUS fgre_loaddab_echo1fc( LONG slice, LONG echo, LONG oper, 
                             LONG  view, TYPDAB_PACKETS acqon_flag,
                             int load_ctrl );
STATUS RTFgrePG( int PosStart, int TLead, int FlowCompTeTime,
                 int FlowCompTRTime,  int PulseIndex,
                 int cssattime, int spsattime, int hard180time,
                 long *flowcomp_deadtime, int featureflag ) ;  

STATUS rtia_dummy_sequence_PG( int reptime, int ssitime, int realtime_flag );

#endif /* fgre_ipg_h */

