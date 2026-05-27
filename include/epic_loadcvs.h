/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_loadcvs.h $
 * $Revision: 1.2 $  $Date: 8/27/98 10:07:14 $
 *  
 * Interface for the epic_loadcvs.c file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */
/* do not edit anything above this line */

#ifndef epicloadcvs_h
#define epicloadcvs_h

int do_read( int fd, char *addr, int nbytes );
int epic_loadcvs( char *file );

#endif /* epicloadcvs_h */

