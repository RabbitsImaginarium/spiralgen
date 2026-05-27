/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1995-1998 The General Electric Company
 *
 *      File Name:  psdplotlib_proto.h
 *      Developer:  Dale Thayer
 *
 * $Source: psdplotlib_proto.h $
 * $Revision: 1.4 $  $Date: 7/27/98  18:20:02  $
 *
 *@Description
 * This contains the prototype definition for all routines in
 * the psdplotlib project.
 *
 *
 * do not edit anything above this line
 *

 ******************************************************************
 *      Revision History
 ******************************************************************
 Version           Date/         Author
                   Description
 ------------------------------------------------------------------
 sccs1.2           24-Jun-98     Dale Thayer
                   Original for cardiac, CV1, conversion to ANSI C.

 sccs1.4           27-Jul-98     Dale Thayer
                   Took ParseSSP out of list to avoid conflict with file
                   and prototype from psdipgsimlib.

 /main/mr_main/1   9-Oct-98      Dale Thayer
                   Original version of file moved from wtools/psdplotlib
                   because the PET directory uses it.

 /main/mr_main/2   27-Oct-98     Dale Thayer
                   Added the prototypes for DebugPanel.c, OutMsg.c, WriteMsg.c,
                   PrintPopUp.c, QuitPanel.c, SetPanel.c, StartTimeHist.c
                   SetDataPoints.c, getbytes.c, proc_utils.c, XmBuilderUtils.c.

 *@End*************************************************************/

#ifndef  psdplotlib_proto_h		/* we only want file included once */
#define  psdplotlib_proto_h



/* from DebugPanel.c */

void StartDebug( void );
int  StartDbx( void );
void KillDebug( void );



/* from OutMsg.c */

void OutMsg( char  *fmt_str, ... );



/* from PDStoreData.c */

STATUS PDStoreData( CHAR *rootfile );



/* from PDStorePlot.c */

STATUS PDStorePlot( CHAR *rootfile );



/* from PrintPopUp.c */

void PrintPopUp( Widget parent, XtPointer data, XtPointer cbs );
#ifdef OLD_XVIEW_CODE
void TurnOffPrintFlash( void );
#endif
STATUS LoadPrinters( void );
Widget PPMain_toplevel_widget( void );



/* from PulseData.c */

FILE   *PDLoadData( PULSE_DATA_TABLE *data_table, CHAR *filename );
SHORT  PDGetSequences( PULSE_DATA_TABLE *data_table );
STATUS PDSetupDataNodes( PULSE_DATA_TABLE  *data_table, INT sequence_no,
                         LONG starttime, LONG endtime, INT alias, 
                         FILE  *db_fptr, INT  *temp_length, STATUS freef );
LONG   PDGetEndTime( PULSE_DATA_TABLE *data_table, INT seqnumber );
void   FreePlotData( PULSE_DATA_TABLE  *data_table );
STATUS PDCleanUp( PULSE_DATA_TABLE *data_table, FILE *db_fptr );



/* from QuitPanel.c */

void LoadSetupProc( char *text );
void SaveSetupProc( char *text );
void QCheckProc( void (*subrtn)( void ) );
void RestartProc( void );



/* from SetDataPoints.c */

STATUS SetDataPoints( DATA_POINTS_NODE  *data_pts, LONG start, LONG end,
                      INT nsamples, INT delta_sampling, SHORT *wavemem,
                      USHORT  *instr_addr, INT current_sequence,
                      INT weos_bit, INT exectime );
STATUS ReadDataPoints( PULSE_DATA_TABLE  *data_table, INT  ix,
                       DATA_POINTS_NODE  *wavegen );



/* from StartTimeHist.c */

void StartTimeHist( char *text );
void ExecuteHistProc( void );
void CancelHistProc( void );
void ExitTimeHist( void );
void KillTimeHistWin( void );
void SaveFileProc( void );



/* from WriteMsg.c */

void WriteMsg( STATUS bell, STATUS crt, char *text, ... );



/* from XmBuilderUtils.c */

void       WTPutText( Widget w, char *text, int type );
char       *WTGetText( Widget w );
Widget     GetTopShell( Widget w );
Widget     GetTopApplShell( Widget w );
Widget     GetShell( Widget w );
optionRec* Createoption( char *name, XtCallbackProc callback, 
                         XtPointer client_data );
void       RegisterOption( char *name, XtCallbackProc callback, 
                           XtPointer client_data );
void       BuildOptionButtons( Widget parent, XmFontList fontlist, 
                               int orient, int cols );
void       BuildToolBarH( Widget parent, XmFontList fontlist, 
                          int numbut, int hspace, ... );
Widget     BuildActionArea( Widget parent, int numbut, ... );
void       BuildRadioBox( char *title, Widget parent, XmFontList fontlist, 
                          int defbutton );
void       BuildCheckBox( char *title, Widget parent, XmFontList fontlist,
                          unsigned char orientation, int defbutton );
void       ReportError( char title[], char text[], Widget parent,
                        XmFontList fontlist, XmFontList fontlist2 );
void       ErrorMessage( Widget parent, char *message );
int        QueryUser( Widget parent, char *message, char *ok_text, 
                      int ok_return, char *cancel_text, int cancel_return );
void       PopdownWidget( Widget w, Widget cd );
void       PopupWidget( Widget w );
void       InitFontLists( Widget toplevel, 
                          XmFontList fontlist, XmFontList fontlist2 );



/* from getbytes.c */

int getbytes( FILE *finp, int position, char *buff, int number, int size );



/* from proc_utils.c */

int RegisterChild( pid_t pid, void (*func)() );
void ChildDeath( void );



#endif				/* end: if psdplotlib_proto_h not defined */


