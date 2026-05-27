/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: nxDrawRoutine.h $
 * $Revision: 1.2 $  $Date: 5/14/98 20:03:23 $
 * 
 * Interface for the nxDrawRoutine.c file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 14/May/1998
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.1   14/May/1998  GFN         Initial version.

 sccs1.2   14/May/1998  GFN         Added more prototypes.
 */

#ifndef nxDrawRoutine_h
#define nxDrawRoutine_h

void nxSetMargins( double sides, double top, double bottom );
char *nxOpenPs( char *psheader, int  paperlayout );
FILE *nxOpenFile( char *filename );
void nxCloseFile( void );
void nxSetLandscape( int landscape_flag );
void nxSetHeader( char *header );
void nxSetComment( char *comment, int ix );
void nxClearWindow( int mode, Display *dpy, Window xwin );
void nxClearArea( int mode, Display *dpy, Window xwin, int left, int top,
                  int height, int width );
void nxInitScale( int mode, int width, int height );
void nxFitRatio( double aspratio, double *width, double *height );
double nxX( double value );
double nxY( double value );
void nxDrawRectangle( int mode, Display *dpy, Window xwin, GC gc, int left,
                      int top, int width, int height );
void nxDrawLine( int mode, Display *dpy, Window xwin, GC gc, int x1, int y1,
                 int x2, int y2 );
void nxDrawString( int mode, Display *dpy, Window xwin, GC gc, int x1, int y1,
                   char *strvalue, int strlength );
void nxDrawLines( int mode, Display *dpy, Window xwin, GC gc, XPoint points[],
                  int npts, int coordmode );
void nxSetLineDash( Display *dpy, GC gc );
void nxSetLineWidth( Display *dpy, GC gc );
void nxSetFont( Display *dpy, GC gc );
void nxCopyFile( FILE *dest_fptr, char *source_file );
void nxPrintComment( char *comment );
void nxWriteCmd( char *str );
void nxAdjMargins( double left, double top );
void nxChangeDumpScale( double xscale, double yscale );
void nxAdjDumpScale( double adjx, double adjy );
void nxSetDumpScale( void );
void nxDumpDrawing( Display *dpy, Window xwin, int x, int y, unsigned width,
                    unsigned height );
void nxSetScale( void );

#endif /* nxDrawRoutine_h */
