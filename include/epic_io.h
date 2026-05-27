/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_io.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:38:23 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)epic_io.h	1.1 6/29/98 15:38:23 Copyr 1998 GE";
#endif

/* do not edit anything above this line */


#ifndef epicio_h
#define epicio_h

int epic_copypsd(int *pid, int *recid);
int epic_writecvs(char *file, char *psdpath);
LOCAL int  do_read(int fd, char *addr, int nbytes);
int epic_readcvs(char *file);

#endif /* epicio_h */


