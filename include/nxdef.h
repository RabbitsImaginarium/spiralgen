/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1992 The General Electric Company
 *
 *	Include File Name:  nxdef   
 *	Developer:
 *
 * $Source: nxdef.h $
 * $Revision: 1.3 $  $Date: 21 Feb 1996 12:42:47 $
 */

/*@Synopsis 
	typedefs for the nxDrawRoutines
*/     

/*@Description
    	This file contains typedef for variable structure that will be used
	by nxDrawRoutines but are set by routines outside of the 
	nxDrawRoutines.c file.
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  nxdef_INCL
#define  nxdef_INCL

#define LANDSCAPE_FLAG 0
#define PORTRAIT_FLAG  1

#define POSTSCRIPT      1
#define XWINDOWS        0

#define PS_INCHES(x)((float)x*72.0)

/* #ifndef PSDPLOTPULSE_BUILD */
#ifdef trash
typedef struct {
	int xid;
	Xv_Font font;
} nxFONT;

nxFONT *nxfont_family;
#endif

#define PS_TOP_MARGIN PS_INCHES(1.0)
#define PS_BOTTOM_MARGIN PS_INCHES(1.0)
#define PS_SIDE_MARGIN PS_INCHES(.75)

#endif /* nxdef_INCL */
