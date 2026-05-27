/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: fcine_orderslice.h $
 * $Revision: 1.2 $  $Date: 3/9/98 08:50:17 $
 *  
 * Interface code for the fcineorderslice.c file.
 *  
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 16-Sep-1997
 */
/* do not edit anything above this line */

#ifndef fcine_orderslice_h
#define fcine_orderslice_h

#include <stddef_ep.h>

STATUS fcine_orderslice( const INT numLocs, const INT locsPerPass,
                         const INT gating, const INT rphases,
                         const INT aphases );

#endif /* fcine_orderslice_h */

