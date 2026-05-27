/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: fcardorderslice.h $
 * $Revision: 1.6 $  $Date: 3/9/98 08:52:03 $
 *  
 * Interface for the Fastcard order slice routine. It includes
 * support for Fast CINE.
 *  
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 02/Jul/1997
 */
/* do not edit anything above this line */

#ifndef fcardorderslice_h
#define fcardorderslice_h

STATUS fcardorderslice( INT slquant, INT slquant_per_pass, INT gating_mode,
                        INT multi_planar, INT rphases, INT aphases,
                        INT fcine_flag );

#endif /* fcardorderslice_h */

