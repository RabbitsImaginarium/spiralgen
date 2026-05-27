/*
 * GE Medical Systems
 * Copyright (C) 1997 The General Electric Company
 *
 * FastcardPC.h
 * 
 * Interface for FastcardPC.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 7 July 1997
 */
/* do not edit anything above this line */

/*
  Version   Author     Date       Comment
--------------------------------------------------------------
  CDP0.1     GFN    07-Jul-1997   Created file.

  CDP0.2     GFN    14-Aug-1997   Added Jason's performance enhancements.

  CDP0.3     GFN    25-Sep-1997   Removed unsafe datatypes from interface.

  CDP0.4     GFN    24-Oct-1997   Changed fastcardPC_resetscale() arguments
                                  from INT * to FLOAT *. BUG!

************************* Initial CV-1 Version ***********************

 sccs1.7     GFN    22-Dec-1997   Activated Maxwell PC additional arguments
                                  for fastcardPC_predownload.

 sccs1.8     GFN    19-Feb-1998   Removed prototype code for Fast CINE.
                                  Removed K&R declarations.

 sccs1.9     GFN    07-Mar-1998   Removed conditional code for
                                  Performance Enhancements.

 sccs1.10    GFN    24-Apr-1998   Removed unused arguments in
                                  fastcardPC_cvcheck().

 sccs1.12    GFN    18-May-1998   Changed Rsprot from 'INT *' to 'long *'.

 */

#ifndef FastcardPC_ipg_h
#define FastcardPC_ipg_h

/*
 * @rsp section
 */
STATUS set_flow_encodes( INT flow_echo );
STATUS fastcardPC_psdinit( INT flag );
STATUS reset_for_first_phase( void );
STATUS execute_flow_expts( INT *k_index, INT segment, INT copy_flag,
                           INT *first_phase, INT Dabstate, INT *complete );

#endif /* FastcardPC_ipg_h */
