/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1990 The General Electric Company
 *
 *      Include File Name:  IPCwtterm
 *      Developer: B.L. Mazin
 *
 * $Source: IPCwtterm.h $
 * $Revision: 1.4 $  $Date: 5/9/95 09:24:22 $
 */

/*@Synopsis 
   	IPC constants used by the Workstation Tool for managing
	other tools that have been forked.
*/     

/*@Description
	The following constants are used by the MsgCenter in the
	Workstation Tool routine for tracking the statuses of
	other tools that have been forked.

Revisions:
8.0.0   05/09/95        JDM             Removed trailing comma in enum types.
     
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  IPCwtterm_INCL
#define IPCwtterm_INCL

typedef enum {
   WT_WIN_LOCK,
   WT_WIN_UNLOCK,
   WT_WIN_CLOSE,
   WT_WIN_READY,
   WT_INIT,
   WT_ERROR_MSG
} IPCTERM_STATUS;

#endif /* IPCwtterm_INCL */
