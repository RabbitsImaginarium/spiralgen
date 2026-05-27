/*
 * GE Medical Systems
 * Copyright (C) 1997 The General Electric Company
 *  
 * $Source: FastCINE.host.h $
 * $Revision: 1.7 $  $Date: 7/10/98 17:03:24 $
 * 
 * Interface code for the FastCINE.e file.
 * 
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14-OCT-1998
 */
/* do not edit anything above this line */

#ifndef FastCINE_host_h
#define FastCINE_host_h

/*
 * @host section
 */
STATUS fcine_cvinit( void );
STATUS fcine_cveval_init( INT *Minisidelay, INT *Timessi, const INT
                          f_flag );
STATUS fcine_cvcheck( const INT f_flag, const INT e_flag );
STATUS fcine_calcPulseParams( void );
STATUS fcine_predownload( const INT f_flag );
STATUS fcine_retrospective_init( INT *copy_flag, const INT f_flag );
STATUS fcine_piait_adjust( INT *ait, INT *viewcopyfactor, const INT f_flag );
STATUS fcine_setrawheader( const INT actual_tr, const INT flag );
STATUS fcine_setphases( INT *adv_maxphases, const INT f_flag );

#endif /* FastCINE_host_h */

