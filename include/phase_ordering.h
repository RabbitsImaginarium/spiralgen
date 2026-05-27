/*@Start***********************************************************/
/* GEMSBG C source File
 * Copyright (C) 1991 The General Electric Company
 *
 *      File Name:  fitresol
 *      Developer:  B.L. Mazin
 *
 * $Source: fitresol.c $
 * $Revision: 1.1 $  $Date: 10/31/93 10:44:16 $
 */
/* do not edit anything above this line */
/*
  Version  Author      Date      Comment
------------------------------------------------------------------
    1.0     GFN    20-Sep-1997   Initial Version

    1.1     GFN    25-Sep-1997   Removed unsafe datatypes from the
                                 interface. Changed SHORT for INT.
                                 (SHORT *) is safe.
 */

#ifndef phase_ordering_h
#define phase_ordering_h

#include <stddef_ep.h>

STATUS phase_ordering(
#ifdef __STDC__
    SHORT *view_tab, INT phase_order, INT rspviews, INT viewoffset,
    INT flag, INT views_per_seg, INT phoffset
#endif /* __STDC__ */
);

#endif /* phase_ordering_h */
