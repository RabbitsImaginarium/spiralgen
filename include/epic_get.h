/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_get.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:38:23 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)epic_get.h	1.1 6/29/98 15:38:23 Copyr 1998 GE";
#endif

/* do not edit anything above this line */



#ifndef epicget_h
#define epicget_h


void save_orig_cvs(save_cv *valarray);

int epic_get_cvs(int cvnums[],valstruct dest[]);

LOCAL int  fill_data(int cvnum,cvstruct *dest,int *offset,
                        char ss[MAXSTRSPACE]);


LOCAL int  fill_name(int cvnum,cvnamestruct *dest, int *offset,
                        char ss[MAXNAMESPACE]);


LOCAL BOOLEAN visible(int cvnum);


BOOLEAN match(char *expr,char *str);

LOCAL int   find_startvalues(int place, int pagesize,char *matchstr,
                        int pagestart,int *currentloc);


int epic_get_cvdata_many(varchoice *whichcvs,cvstruct dest[],
                                char ss[MAXSTRSPACE], short *ncvs,
                                short *position);


int epic_get_cvname_many(varchoice *whichcvs,cvnamestruct  dest[],
                                char ss[MAXNAMESPACE],
                                short *ncvs, short *position);


int epic_get_cvdata_one(char* name,cvstruct *dest,
                                char ss[MAXSTRSPACE]);


int epic_get_cvdata_num(int cvindex,cvstruct *dest,
                                char  ss[MAXSTRSPACE]);



int epic_get_sharedvar(int varnum,int  maxbytes,
			int *nbytes, char *dest,
 			BOOLEAN  do_checksum,int *checksum);

int epic_get_header(headerstruct *hdr);

int epic_get_cvrev(int *cvrev, long *srcrev,
                        BOOLEAN  emulate_mode);
int epic_getrsp(char *name,int  subscript,
                         int *dest);
LOCAL int   find_startrsp(int  place,int  pagesize,
                        char *matchstr,int pagestart,
                         int * currentloc);

int epic_getrspnames(varchoice *whichrsps, rspdata  buf[],
                        short *nrsps,short *position);

#endif  /* epicget_h */
