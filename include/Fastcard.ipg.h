/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: Fastcard.ipg.h $
 * $Revision: 1.11 $  $Date: 4/25/98 01:08:28 $
 *  
 * Function prototypes for the Fastcard functions defined in Fastcard.e.
 *  
 * Language : ANSI C
 * Author   : Pradep S
 * Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

/*
  Version   Author     Date       Comment
--------------------------------------------------------------
  CDP0.1     GFN    25-Sep-1997   Removed unsafe datatypes from interface.

  CDP0.2     GFN    24-Oct-1997   Changed vvs_init() for fcine_cvinit().

  ******************** Initial CV-1 Version ************************

  sccs1.7    GFN    21-Jan-1998   Added fcine_passviewtab() and 
                                  fcine_setrawheader().
                                  Added ermes_flag argument to
                                  fastcard_setacqparams().
                                  Made set_qrskiller() a static function.

  sccs1.8    GFN    22-Jan-1998   Made set_qrskiller() a public function again.
                                  Notice that is has a new argument (e_flag).

  sccs1.9    GFN    26-Jan-1998   Moved Fast CINE code to a different module
                                  (FastCINE.h).
                                  Added e_flag argument to
                                  fastcard_predownload().
                                  Removed K&R declarations.

  sccs1.10   GFN    07-Mar-1998   Added Fast CINE flag argument to
                                  fastcard_setacqparams().

  sccs1.11   GFN    24-Apr-1998   Added ermes flag to set_fastcard_targets().
                                  Removed errno and errstr from
                                  fastcard_setacqparams() and
                                  fastcard_cvcheck().

------------------------------------------------------------------------------
  Version              Date          Author
                       Comment
------------------------------------------------------------------------------
  /main/mr_main/2      28-Aug-98     Dale Thayer
                       Made routine fccoredda a void return.

 */

#ifndef Fastcard_ipg_h
#define Fastcard_ipg_h

/*
 * @pg section
 */
STATUS qrskiller_PG( void );
STATUS retro_delay_PG( void );
STATUS fastcard_pulsegen( INT f_flag );
/*
 * @rsp section
 */
STATUS fastcardmp_pass_ptrs( INT f_flag, SHORT *slice_in_acq, SHORT *acq_pointer,
                             INT pass_index, INT slquant_1 );
STATUS fastcard_psdinit( INT *rf1_flip_array, const INT ia_Rf1,
                         const DOUBLE flip_Rf1, const INT actTR,
                         const INT oddnexnpw, const INT f_flag,
                         const INT copy_flag );
STATUS fccore( void );
STATUS fcscore( void );
STATUS fcmpcore( void );
STATUS ps2fcmpcore( INT rsp_nex );
STATUS fccoredda( INT idda, INT slice, INT *sequence_count, INT status );
STATUS copyview( INT k_count, INT sl_count, INT src_echo );
STATUS copy_bkwd( void );
STATUS copy_fill_endrr( void );
STATUS check_oddnexnpw_views( INT *k_index, INT seg, INT Excitation,
                              INT oddnexnpw_flag, INT *enable_breakout );
STATUS arrhythmia_check( INT eventoccured, INT *enable_breakout, INT maxBadRR,
                         INT k_index, INT *sequence_count, INT psdindex,
                         INT *Excitation, INT *Segment, INT range_check, 
                         INT isi_daq_status, INT multi_planar_mode );
STATUS get_missing_views( void );
STATUS offset_to_killqrs( void );
STATUS print_viewlist( void );
STATUS set_isi_dab( INT excitation, INT Segment );
STATUS wait_for_ecg( INT *sequence_count, const INT psdindex );
STATUS fcmp_wait_for_ecg( INT rrtriggers );
STATUS chemsat_wait_for_resp( INT trig_start, INT trig_end );
STATUS load_updates( void );

#endif /* Fastcard_ipg_h */

