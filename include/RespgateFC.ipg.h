/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: RespgateFC.ipg.h $
 * $Revision: 1.4 $  $Date: 3/20/98 17:33:08 $
 *  
 * Interface code for the RespgateFC.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

#ifndef RespgateFC_ipg_h
#define RespgateFC_ipg_h

/*
 * @rsp section
 */
STATUS respgate_fc_psdinit( const INT f_flag );
STATUS respgate_fc_wait_for_valid_phase( const INT mp_flag );
STATUS respgate_fc_check_phase( const INT mp_flag );
/*
 * @pg section
 */
STATUS respgate_fc_pulsegen( const INT f_flag );

#endif /* RespgateFC_ipg_h */

