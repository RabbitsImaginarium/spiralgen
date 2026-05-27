/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_main.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:38:25 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)epic_main.h	1.1 6/29/98 15:38:25 Copyr 1998 GE";
#endif

/* do not edit anything above this line */



#ifndef epicmain_h
#define epicmain_h

LOCAL  void switches(char **argv, BOOLEAN *emulate,
                        BOOLEAN *newPsd, int *src_id);
void printAdvPnlcvs(data_pkt pkt);
unsigned long int createmask(void);
LOCAL void printcvdata(cvdata cvs[]);
LOCAL void printcvnums(int cvnums[]);
LOCAL void printpkt(cmd_pkt *pkt, char *myname);
static void reapchild(void);
void epic_processcmds(char *argv[]);

#endif /* epicmain_h */

