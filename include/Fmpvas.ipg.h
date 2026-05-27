/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: Fmpvas.ipg.h $
 * $Revision: 1.2 $  $Date: 4/25/98 02:38:31 $
 *  
 * Interface for the Fmpvas.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

#ifndef Fmpvas_ipg_h
#define Fmpvas_ipg_h


/*
 * @pg section
 */
STATUS qrskiller1_PG( void );
STATUS fmpvas_pulsegen( INT Phorder, INT flag );

/*
 * @rsp section
 */
STATUS fmpvas_get_seqtime( INT actTR, INT cssattime, INT spsattime,
                           INT sc_deadtime );
STATUS fmpvas_satrotate( INT flag );
STATUS fmpvas_psdinit( INT rf1_flip_array[], INT ia_Rf1, DOUBLE flip_Rf1,
                       INT actTR, INT oddnexnpw, INT flag );
STATUS fmpvas_settriggers( INT flag );
STATUS fmpvas_core( INT flag, INT PlayWait );

#endif /* Fmpvas_ipg_h */


