/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_dload.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:38:20 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)epic_dload.h	1.1 6/29/98 15:38:20 Copyr 1998 GE";
#endif

/* do not edit anything above this line */

#ifndef epicloadcvs_h
#define epicloadcvs_h


int epic_dload_cvs( unsigned int addr,int ipg_cvlen,
                        BOOLEAN *  needrangecheck,BOOLEAN *  emulate);

/*void epic_rangecheck( BOOLEAN *  needrangecheck);  */


#endif  /* epicloadcvs_h */

