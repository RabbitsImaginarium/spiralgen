/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  psdIF_proto.h
 *      Developer:  Dale Thayer
 *
 * $Source: psdIF_proto.h $
 * $Revision: 1.3 $  $Date: 8/24/98  17:20:41  $
 *
 *@Description
 *
 * This is the prototype include file for the psdIF project.
 * (NOTE: epic_error() has its own include file epic_error.h.)
 * 
 * Language : ANSI C
 * Author   : Dale Thayer
 * Date     : 21/Jul/1998
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.2   21-Jul-1998  Dale Thayer Original for cardiac, CV1,
                                    conversion to ANSI C.

 sccs1.3   24-Aug-1998  Dale Thayer Include epic_error.h prototype for
                                    epic_error() definition.

 sccs1.5   06-Oct-1998  Dale Thayer Removed epic_nerror, epic_serror, and
                                    epic_vnerror prototypes.

           18-Nov-1998  GFN         Updated epic_vsprintf() to make fmt and numargs
                                    arguments constant.

           22-Dec-1999  RJF/YZ      Added #include  for prototypes containing accessor methods 
                                    get_cvs_changed and get_cvs_changed.

 */


#ifndef psdIF_proto_h
#define psdIF_proto_h

#include <printDebug.h>
#include <cv_change_status.h>

/* from epic_checksum.c */
long epic_checksum( unsigned char *addr, int nbytes );


/* from epic_dload.c */
int epic_rangecheck( BOOLEAN *needrangecheck );
int epic_dload_cvs( unsigned int addr, int ipg_cvlen,
                    BOOLEAN *  needrangecheck, BOOLEAN emulate );


/* from epic_error.c */
#include "epic_error.h"


/* from epic_get.c */
void save_orig_cvs( save_cv *valarray );
int epic_get_cvs( int cvnums[], valstruct dest[] );
BOOLEAN match( char  *expr, char *str );
int epic_get_cvdata_many( varchoice *whichcvs,cvstruct dest[],
                             char ss[MAXSTRSPACE] ,short *ncvs,
                             short *position);
int epic_get_cvname_many( varchoice *whichcvs,cvnamestruct  dest[],
                          char ss[MAXNAMESPACE], 
                          short *ncvs, short *position );
int epic_get_cvdata_one( char* name,cvstruct *dest, 
                         char ss[MAXSTRSPACE] );
int epic_get_cvdata_num( int cvindex,cvstruct *dest, 
                         char  ss[MAXSTRSPACE] );
int epic_get_sharedvar( int varnum,int  maxbytes, int *nbytes, char *dest,
                        BOOLEAN  do_checksum,int *checksum );
int epic_get_header( headerstruct *hdr );
int epic_get_cvrev( int *cvrev, long *srcrev, BOOLEAN  emulate_mode );
int epic_getrsp( char *name, int  subscript, int *dest );
int epic_getrspnames( varchoice *whichrsps, rspdata  buf[],
                      short *nrsps, short *position );


/* from epic_io.c */
int epic_copypsd( int *pid, int *recid );
int epic_writecvs( char *file, char *psdpath );
int epic_readcvs( char *file );


/* from epic_loadcvs.c */
int do_read( int fd, char *addr, int nbytes );
int epic_loadcvs( char *file );


/* from epic_main.c */
void printAdvPnlcvs( data_pkt  pkt );
unsigned long int createmask( void );
void epic_processcmds( char *argv[] );
/* void main(int argc, char **argv); */


/* from epic_put.c */
void restore_orig_cvs( save_cv *valarray );
int epic_checkRange( void );
int epic_put_cvs( cvdata *cvs, int evalmode, short *  hotcv, 
                  save_info *save_array, short  method );
void epic_setpage( int newpage );
int epic_setexist( int cvnums[], BOOLEAN set_to_true, int evalmode );
int epic_unfix( int cvnum, int evalmode );
int epic_put_sharedvar( int varnum,int  totalbytes, char *src, int recid );
int epic_rotmatrix( int totalbytes, char *src, int  recid );
int epic_scale_rot_matrix( void );
int epic_trackrotmatrix( int varnum,int totalbytes, char *src,int recid );
int epic_transpose_trackrot( int varnum );


/* from epic_util.c */
char *epic_cvnameof( int cvnum );
int epic_cvnumof( int cvindex );
void epic_warning( char *fmt, ... );
void epic_vserror( char *fmt, ... );
void epic_vsprintf( const char *fmt, const int numargs, int *argtype,
                    float *fval, int *ival, char *sval[] );
void epic_syserror( void );
int epic_cvrange_error( int cvnum, short  method ); 
int epic_find( char *name, char array[], int nelements,int  elementsize );
int epic_rangecheckLUT( void );
int epic_AdvPnlFail( int hotcv );
int OutOfRange( int cvnum );
int ScanRangeCV( int cvnum );
int StopProcessing( int existflag, int popupflag, int cvnum );
void PopupValue( int LutIndex, int *j, int choice, cvinfo *descv, 
                 int luttype, int *num, advpnlstruct *dest );
void TurnOffScnRngCVs( void );
int epic_processLUT( int LutIndex,int *numcvs,advpnlstruct  destcvs[] );
int epic_eval( int evalmode );
int getcvermes( int cvnum );



/* from timing.c */
void time_start( char *s );
void time_start2( char *s );
void time_done( void );
void time_init( void );
void usage_print( void );
void CV_print( int cn, char *cstr );
void time_print( char *s );


/* From checkCVs.c */

int checkPgenCVs( dbLevel_t debug );


#endif /* psdIF_proto_h */

