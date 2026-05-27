/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: Prescan+.host.h $
 * $Revision: 1.1 $  $Date: 6/24/98 17:36:05 $
 * 
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 14/Oct/98
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------
           11-Dec-1998  GFN         MRIge49699 - Removed arguments to
                                    prescan_pulsegen() and FTGpulsegen().
 */


#ifndef Prescan_plus_ipg_h
#define Prescan_plus_ipg_h

/*
 * @pg section
 */
STATUS prescan_pulsegen( void );
STATUS PSpulsegen( void );
STATUS FTGpulsegen( void );
STATUS ASpulsegen( void );
STATUS PSmps1(INT mps1nex );
STATUS PScfl( void );
STATUS PScfh( void );
STATUS PSinit( void );
STATUS PSfasttg( INT pre_slice,INT  rspchp,INT  debugstate );
STATUS FastTGCore( DOUBLE slice_loc,INT slice_num,INT ftg_disdaqs,INT ftg_views,
                   INT ftg_nex,INT ftg_chop,INT ftg_debug );
STATUS ASautoshim( INT rspsct );

/*
 * @rsp section
 */
STATUS mps1( void );
STATUS aps1( void );
STATUS cfl( void );
STATUS cfh( void );
STATUS fasttg( void );
STATUS autoshim( void );

#endif  /* Prescan_plus_ipg_h */

