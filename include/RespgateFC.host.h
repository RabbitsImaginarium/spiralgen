/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: RespgateFC.host.h $
 * $Revision: 1.4 $  $Date: 3/20/98 17:33:08 $
 *  
 * Interface code for the RespgateFC.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

#ifndef RespgateFC_host_h
#define RespgateFC_host_h

/*
 * @host section
 */
STATUS respgate_fc_cveval_init( void );
STATUS respgate_fc_time( FLOAT *advmintscan, INT tslice );
STATUS respgate_fc_cvcheck( const INT f_flag, const INT e_flag );

#endif /* RespgateFC_host_h */

