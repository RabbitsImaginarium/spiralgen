/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * Interface for the Mph.e file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 13/Oct/1998
 */
/* do not edit anything above this line */

#ifndef Mph_h
#define Mph_h

/*
 * @host section
 */
STATUS mph_cvinit( void );
STATUS mph_cveval_init( INT flag );
STATUS mph_params( INT *sl_deltime, INT flag );
STATUS mph_annotation( INT act_TR, INT sl_deltime, INT reps, INT slop_time,
                       INT Gating, INT flag );
STATUS mph_cvcheck( INT flag );
STATUS mph_predownload( INT flag );

/*
 * @pg
 */
STATUS mph_long_delay( INT sl_deltime, INT flag );
STATUS mph_passtime( INT *passtime, INT sl_deltime, INT flag );
STATUS mph_pass_ptrs( INT flag, SHORT *slice_in_acq, SHORT *acq_pointer,
                      INT pass_index );

/*
 * @rsp section
 */
STATUS scandelay1( void );

#endif /* Mph_h */
