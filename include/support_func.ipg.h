/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: support_func.ipg.h $
 * $Revision: 1.35 $  $Date: 5/18/98 20:31:57 $
 *  
 * Function Prototypes for psdsupport functions.
 *  
 * If you add a new support function make sure you add a new prototype.
 *
 * Language : ANSI C
 * Author   : Pradeep S. 
 * Date     : 14 Oct 1998
 */
/* do not edit anything above this line */

/*
 Version       Date      Author      Description
------------------------------------------------------------------------------
 sccs 1.16  13/Nov/1997  Dale Thayer Added diffcvs() to list.
 
 sccs 1.27  16/Dec/1997  GFN         Initial CV-1 version. Merged with Lx-2.

 sccs 1.33  27/Apr/1998  BJM         Added MaxAcq to slicesort delcaration.

 sccs 1.34  18/May/1998  GFN         Changed type of rotation matrix args
                                     to long.

 sccs 1.37  22/June/1998 AKG         MRIge46303 changed LOG_GRAD structure 
                                     argument(Loggrad) to a pointer to 
                                     LOG_GRAD struct(Loggradp)

 sccs 1.38  05/Aug, 1998 BJM         Add xtr_pkt_off to getfiltparams interface
                                     for epi         

 */

/* Only do this once in any given compilation */
#ifndef  support_func_ipg_h
#define  support_func_ipg_h

#include <stddef_ep.h>

#ifdef __STDC__

STATUS getbeta(

    FLOAT *beta, WF_PROCESSOR wgname, LOG_GRAD *lgrad

);

STATUS getramptime(

    INT *risetime, INT *falltime, WF_PROCESSOR wgname, LOG_GRAD *lgrad

);

STATUS gettarget(

    FLOAT *target, WF_PROCESSOR wgname, LOG_GRAD *lgrad

);


STATUS setxdcntrl(

    WF_PULSE *pulse_ptr, INT state, INT rcvr

);

#else /* !__STDC__ */

STATUS setxdcntrl();
STATUS gettarget();
STATUS getramptime();
STATUS getbeta();

#endif /* __STDC__ */

#endif /* support_func_ipg_h */
