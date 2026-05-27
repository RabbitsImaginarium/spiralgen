/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: fcardsliceinfo.h $
 * $Revision: 1.6 $  $Date: 4/24/98 10:56:24 $
 *  
 * Interface for the fcardsliceinfo routine.
 *  
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 02/Jul/1997
 */
/* do not edit anything above this line */

#ifndef fcardsliceinfo_h
#define fcardsliceinfo_h

#include <stddef_ep.h>

STATUS fcardsliceinfo( INT *adv_maxslquant, INT *num_acqs, INT *slquant_per_acq,
                       INT slquant, INT avail_time, INT seq_tr,
                       INT views_per_segment, INT multi_planar, INT modflip,
                       INT mp_extra, INT mp_killer_time, INT chemsat,
                       INT chemsat_time, INT chemsat_dda, INT ph_contrast,
                       INT num_flow_expts, INT e_flag );

#endif /* fcardsliceinfo_h */

