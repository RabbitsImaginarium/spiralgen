/*
 * GE Medical Systems
 * Copyright (C) 1997 The General Electric Company
 *  
 * $Source: FastCINE.ipg.h $
 * $Revision: 1.7 $  $Date: 7/10/98 17:03:24 $
 * 
 * Interface code for the FastCINE.e file.
 * 
 * Language : ANSI C
 * Author   : Pradeep S
 * Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

/*

10-Mar-1999		PRA	MRIge51405. Changed prototypes for
				fcine_psdinit and fcine_pulsegen. 
*/


#ifndef FastCINE_ipg_h
#define FastCINE_ipg_h


/*
 * @rsp section
 */
STATUS fcine_psdinit( WF_PULSE *p_echo1dab,  const INT f_flag );
STATUS fcinecore( void );
STATUS fcine_pulsegen( const INT act_tr ,const INT f_flag );
STATUS fcine_checkviewcopy( INT *copyview_flag, const INT copy_flag,
                            const INT f_flag );
STATUS fcine_passviewtab( SHORT *viewtab, const INT viewtab_size );
void fcine_update( void );
STATUS fcine_initbuffer( const INT num_segs );
STATUS fcine_set_number_tr( const INT n_segment, const INT nmbr_tr );
STATUS sspload_echo1cine( short *Cinebits );
STATUS loadfcine( const INT arr,
                  const INT op,
                  const INT offset,
                  const INT n_tr, 
                  const INT tbd1, 
                  const INT tbd2,
                  const INT delay, 
                  const INT n_slice,
                  const TYPDAB_PACKETS acqon_flag );


STATUS check_arrhythmia( void );


#endif /* FastCINE_ipg_h */

