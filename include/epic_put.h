/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: epic_put.h $
 * $Revision: 1.1 $  $Date: 6/29/98 15:38:26 $
 *  
 * 
 *  
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 29/Jun/1998
 */

#ifndef lint
static char sccsid[] = "@(#)epic_put.h	1.1 6/29/98 15:38:26 Copyr 1998 GE";
#endif

/* do not edit anything above this line */

#ifndef epicput_h
#define epicput_h


void restore_orig_cvs(save_cv *valarray);

LOCAL  int  restore_vals(save_info *save_array,cvdata cvs[]);
int epic_checkRange(void);
void epic_put_cvs(cvdata cvs[], int evalmode,
                        short *  hotcv, save_info *save_array,
                        short  method);

void epic_setpage(int newpage);
int  epic_setexist(int cvnums[], BOOLEAN set_to_true);
int epic_unfix(int cvnum, int evalmode);
int epic_put_sharedvar(int varnum,int  totalbytes,
                        char *src, int recid);
int epic_rotmatrix(int totalbytes, char *src,
                        int  recid);
int epic_rotmatrix(int totalbytes, char *src,
                        int  recid);

int epic_scale_rot_matrix(void);

int epic_trackrotmatrix(int varnum,int totalbytes,
                        char *src,int recid );

int epic_transpose_trackrot(int varnum);

#endif  /* epicput_h */

