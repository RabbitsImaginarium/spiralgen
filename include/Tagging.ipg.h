/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: Tagging.ipg.h $
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
                                      tagging_cvinit(), create_tagging_pulses(),
                                      and set_tagging_targets().
 */

#ifndef Tagging_ipg_h
#define Tagging_ipg_h


/*
 * @pg section
 */
STATUS tagging_pulsegen( const INT f_flag, const INT ssi_time );
/*
 * @rsp section
 */
STATUS tagging_psdinit( const INT f_flag );
STATUS tagging_core( const INT index );
STATUS tagging_core_stress( const INT index );

#endif /* Tagging_ipg_h */



