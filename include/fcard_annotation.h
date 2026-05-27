/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: fcard_annotation.h $
 * $Revision: 1.6 $  $Date: 3/9/98 08:51:57 $
 *  
 * Interface for Fastcard annotation routines. 
 *  
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 02/Jul/1997
 */
/* do not edit anything above this line */

#ifndef fcard_annotation_h
#define fcard_annotation_h

#include <stddef_ep.h>

STATUS fcard_annotation( INT *delaytimetab, INT *trtab, INT seq_tr,
                         INT views_per_segment, INT slquant, INT nphases,
                         INT multi_planar, INT modflip, INT mp_extra,
                         INT viewcopy_flag, INT viewcopyFactor, INT chemsat,
                         INT chemsat_dda, INT chemsat_time, INT num_tr_delays,
                         INT ph_contrast, INT num_flow_expts, INT hrate,
                         INT fcine_flag );

#endif /* fcard_annotation_h */

