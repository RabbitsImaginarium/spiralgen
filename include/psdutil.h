/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: psdutil.h $
 * $Revision: 1.6 $  $Date: 9/15/98 18:23:21 $
 *  
 * Interface for the files in psdutil.
 *  
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 01-Apr-1998
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.2   01/Apr/1998  GFN         Updated function prototypes.

 sccs1.3   14/May/1998  GFN         Added more prototypes.
 sccs1.4   19/May/1998  Dale Thayer Added the DefOpenFile prototype.
 sccs1.5   16-Jul-98    Dale Thayer Added the Alert_confirm prototype.
 sccs1.6   15-Sep-98    Dale Thayer Changed WriteError to return void.
                                    Added the extern C lines for C++.

           16-Sep-98    Dale Thayer Copy of the lx3 version from CM.

 */

#ifndef psdutil_h
#define psdutil_h

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

/* Alert_confirm.c */
int Alert_confirm(CHAR *message, INT n_buttons, ...);

/* WTAlloc.c */
ADDRESS WTAlloc( LONG size );
void WTFree( ADDRESS address );

/* DefParser.c */
STATUS DefOpenUsrFile( CHAR *filename, CHAR *marker );
STATUS DefOpenFile( CHAR *markername );
STATUS DefFindKey( CHAR *key, INT  mark );
STATUS DefReadData( CHAR *format_str, ADDRESS data_addr );
STATUS DefCloseFile( void );

/* ExtractNameTo.c */
INT ExtractNameTo( CHAR *orig_name, CHAR *key, CHAR *new_name );

/* FMax.c, FMin.c, IMax.c, IMin.c */
#ifdef __STDC__
double FMax( int info, ... );
double FMin( int info, ... );
int IMax( int info, ... );
int IMin( int info, ... );
#else /* !__STDC__ */
double FMax();
double FMin();
int IMax();
int IMin();
#endif /* __STDC__ */

/* IOroutines.c */
FILE *OpenFile( CHAR *filename, STATUS mode );
STATUS CloseFile( FILE *plotdata_fptr );
STATUS RewindFile( FILE *plotdata_fptr );
STATUS RemoveFile( CHAR *filename );
STATUS FileExists( CHAR *filename );
LONG FileDate( CHAR *path );
void   WriteError( CHAR *string );
STATUS FileExecs( CHAR *filename );
STATUS IsaWDir( CHAR *filename );

/* IsSunview.c */
STATUS IsSunview( void );

/* Resides.c */
CHAR *Resides( CHAR *env_varname );
CHAR *SetBase( CHAR *filename );
CHAR *ExtractBase( CHAR *filename );

/* ScalePlot.c */
int ScalePlot( double start, double range, double *minor_tic_start,
               double *minor_tic_delta, double *major_tic_start,
               double *major_tic_delta, double *label_tic_start,
               double *label_tic_delta );

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* psdutil_h */

