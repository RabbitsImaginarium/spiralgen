/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: fcardmaxphases.h $
 * $Revision: 1.6 $  $Date: 3/9/98 08:52:00 $
 *  
 * Interface code for fcardmaxphases.c.
 *  
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 02/Jul/1997
 */
/* do not edit anything above this line */

#ifndef fcardmaxphases_h
#define fcardmaxphases_h

#include <stddef_ep.h>

STATUS fcardmaxphases( INT seq_tr, INT views_per_segment, INT trigger_delay,
                       INT chemsat_flag, INT chemsat_time, INT chemsat_dda,
                       INT viewcopy_flag, INT viewcopyFactor, INT multi_planar,
                       INT *max_phases, INT *adv_maxphases, INT *num_tr_delays,
                       INT avail_time, INT ph_contrast, INT num_flow_expts,
                       INT fcine_flag );

#endif /* fcardmaxphases_h */

