/*
 * GE Medical Systems
 * Copyright (C) 1993-1998 The General Electric Company
 *  
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 *  
 * Acquisition filters.
 *  
 * Language : ANSI C
 * Author   : Wally Block
 * Date     : 14/Dec/1993
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

   GFN         07/25/1997       Athough this file has been superceeded by
                                filter_defs.h and filter_structs.h from
                                psd_features, I have upgraded its content
                                to contain the same information as those
                                files. Basically, definitions and a new
                                filter to support CERD's 125Hz bandwidth
                                have been added.

   GFN         09/19/1998       To prevent multiple definitions, I have
                                changed this file to #include filter_defs.h
                                and filter_structs.h.
 */

/* only do this once in any given compilation.*/
#ifndef  filter_h
#define  filter_h

#include <filter_defs.h>
#include <filter_structs.h>

#endif /* filter_h */


