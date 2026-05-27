/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1995-1998 The General Electric Company
 *
 *      File Name:  Mph.host.h
 *      Developer:  Pradeep S.
 *
 * $Source: Mph.h $
 * $Revision: 1.1 $  $Date: 14/Oct/98  13:51:02  $
 *
 *@Description
 *
 * This is the prototype include file for the Mph project.
 *
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version      Date         Author
              Description
 ------------------------------------------------------------------
 sccs1.1      12-Aug-98    Dale Thayer
              ANSI C corrections made to original ANSI Mph_incl.h file.
              File was changed to Mph.h name.

 /main/mr_main/3 13-Oct-98	Roshy Francis	
			  split host and ipg sections.
			  changed filename to host.h
 *@End*************************************************************/

#ifndef  MPH_HOST_H                    /* we only want file included once */
#define  MPH_HOST_H


/* from @host section */

int mph_cvinit( void );
int mph_cveval_init( int flag );
int mph_params( int *sl_deltime, int flag );
int mph_annotation( int act_TR, int sl_deltime, int reps,
                    int slop_time, int Gating, int flag );

int mph_cvcheck( int flag);
int mph_predownload( int flag );

#endif                                  /* end: if MPH_HOST_H not defined */
