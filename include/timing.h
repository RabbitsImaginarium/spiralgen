/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: timing.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:55:01 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)timing.h	1.1 6/29/98 15:55:01 Copyr 1998 GE";
#endif

/* do not edit anything above this line */

#ifndef timing_h
#define  timing_h


void time_start(char *s);
void time_start2(char *s);
void time_done(void);
void time_init(void);
void usage_print(void);
void CV_print(int cn, char *cstr);
void time_print(char *s);


#endif /* timing_h */

