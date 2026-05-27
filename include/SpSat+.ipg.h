/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: SpSat+.ipg.h $
 * $Revision: 1.2 $  $Date: 8/18/98 20:14:24 $
 * 
 * 
 * 
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 14/Oct/98
 */


/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------

sccs1.??   18-Aug-98   Dale Thayer  Corrections to ANSI conversion errors.

 */

/* Local header files */

#ifndef SpSat_plus_ipg_h
#define SpSat_plus_ipg_h


/* @pg section */

STATUS SpSatPG( INT sat_type,INT start_time,
                INT *sat_index,INT cardiacsat_pos );
INT  get_sat_rot_ex_num(void);
INT get_sat_rot_df_num(void);

STATUS SpSatPG_fgre( INT sat_type,INT start_time,
                     INT *sat_index,INT cardiacsat_pos,
                     INT seq_time );

STATUS SpSatCatRelaxPG( INT ssi_time);
STATUS SpSatCatRelaxOffsets( SEQUENCE_ENTRIES sequence_offsets);
STATUS sp_dump_rsp_rot( INT ir_mode, long **rsprot, long **rsprot_orig,
                        INT slquant, INT phases );
STATUS  sp_dump_sat_rot( void );

void sp_set_rot_matrix( void );
void sp_set_rot_matrix_card( void );
void sp_set_rot_matrix_seqir123( void );
void sp_set_rot_matrix_seqir12( void );
void sp_set_rot_matrix_seqir13( void );
STATUS sp_update_rot_matrix( long *slice_rot_matrix, long *sat_rot_array[],
                             const INT num_explicit_sats, const INT num_default_sats );

STATUS SpSat_set_sat1_matrix( long **orig_rot_matrix, long **new_rot_matrix,
                              INT entries, long **sat_array,
                              INT num_explicit_sats, INT num_default_sats,
                              INT cardiacsat_pos, INT sequence_flag,
                              INT f_flag );
STATUS SpSatInitRsp(INT sat_type, INT num_sat_grps,INT  cardiacsat_pos, INT ir_sattype, int rspent);
STATUS SpSatUpdateRsp( INT num_sat_grps,INT pass,INT cat_seq_type );
STATUS SpSatPlayRelaxers( void );
STATUS SpSatChop( void );
STATUS SpSatChopKiller( void );
STATUS SpSatSPGR( INT phase);
STATUS SpSat_Satoff(INT sat_index);
STATUS SpSat_Saton( INT sat_index);
STATUS SpSat_Satrfoff( INT sat_index);
STATUS SpSat_Satrfon( INT sat_index);
STATUS offset_to_Spsat_fgre( void );

/* Begin RTIA */
void rtia_replace_satzbands( RSP_INFO *rspinfo, DOUBLE SatGapZPos,
                             DOUBLE SatGapZNeg );
/* End RTIA */
/* Begin RTIA */
STATUS RTIASatSPGR ( int phase );
/* End RTIA */
#endif /* SpSat_plus_ipg_h */

