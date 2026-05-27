/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_checksum.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:38:19 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)epic_checksum.h	1.1 6/29/98 15:38:19 Copyr 1998 GE";
#endif

/* do not edit anything above this line */

#ifndef epicchecksum_h
#define epicchecksum_h

long epic_checksum(register unsigned char *addr,register  int nbytes);

#endif /* epicchecksum_h */


