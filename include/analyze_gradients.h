/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * Interface file for the analize_gradients.c file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 17/Jun/1998
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.1   17/Jun/1998  GFN         Initial version.

           11/Feb/1999  GFN         Added sequence entry index argument and
                                    debug argument to use dbLevel_t enum.

           04/Mar/1999  GFN         Moved the SKIP definition to stddef_ep.h.

 */

#ifndef analyze_gradients_h
#define analyze_gradients_h

/* Public function protoypes */
STATUS analyzeGradients( t_list **xlist, INT *xnum,
                         t_list **ylist, INT *ynum,
                         t_list **zlist, INT *znum,
                         const LOG_GRAD *loggrd,
                         const INT seq_entry_index,
                         const INT tsamp,
                         const INT min_tr,
                         const dbLevel_t debug );

#endif /* analyze_gradients_h */

