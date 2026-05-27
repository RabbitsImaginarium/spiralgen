/*
 * GE Medical Systems
 * Copyright (C) 1993-1998 The General Electric Company
 *  
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 *  
 * Acquisition Filters.
 *  
 * Language : ANSI C
 * Author   : Wally Block
 * Date     : 31/Oct/1993
 */
/* do not edit anything above this line */

/*
   Author	Date		Comment
-------------------------------------------------------
   WFB		12/14/90	Added 512 output filters.

   KMC          02/19/91        Took out FILTER_INFO structure
                                definition.  This is now in
				epic.h

   MGH          06/25/92        Change f32 to f320 to accomodate 
                                GEtypes.h in 5.3.

   JDM          08/30/94        Split file into defines and 
                                structure portions of original
                                filter.h - this is the defines
                                part.

   GFN          08/13/1997      Added filter structure for 125KHz
                                bandwith.

   GFN          09/29/1998      Moved initializations to filter_structs.c
                                in psdsupport and made this declarations
                                'extern' to prevent unnecessary
                                multiple definitions.
*/

#ifndef filter_structs_h
#define filter_structs_h

extern FILTER_INFO f2;
extern FILTER_INFO f4;
extern FILTER_INFO f8;
extern FILTER_INFO f16;
extern FILTER_INFO f104;
extern FILTER_INFO f125;
extern FILTER_INFO f128;
extern FILTER_INFO f165;
extern FILTER_INFO f215;
extern FILTER_INFO f320;
extern FILTER_INFO f325;
extern FILTER_INFO f326;
extern FILTER_INFO f405;
extern FILTER_INFO f500;
extern FILTER_INFO f625;
extern FILTER_INFO f805;
extern FILTER_INFO f1250;

#endif /* filter_structs_h */

