/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: support_func.h $
 * $Revision: 1.35 $  $Date: 5/18/98 20:31:57 $
 *  
 * Function Prototypes for psdsupport functions.
 *  
 * If you add a new support function make sure you add a new prototype.
 *
 * Language : ANSI C
 * Author   : W. Masri
 * Date     : 
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

 sccs 1.37  22/Jun/1998  AKG         MRIge46303 changed LOG_GRAD structure 
                                     argument(Loggrad) to a pointer to 
                                     LOG_GRAD struct(Loggradp)

 sccs 1.38  05/Aug, 1998 BJM         Add xtr_pkt_off to getfiltparams interface
                                     for EPI.

 sccs 1.39  15/Jul/1998  GFN         Added tsamp argument to minseqseg().

 sccs 1.40  14/Aug/1998  GFN         Added more arguments to minseqseg() used
                                     for coil heating calculations. Made
                                     LOG_GRAD argument in minseqgrad() constant.

            13/Oct/1998  GFN         Added minseq() and setGradCalcMethod()
                                     functions as interface for the gradient
                                     and coil heating routines.

            14/Oct/1998  GFN         Updated prototype for minseqseg().

            18/Nov/1998  GFN         Updated prototype for setScale().

            10/Dec/1998  GFN         For Encore, this file was separated into
                                     a host and an ipg version. I have
                                     #include'd them here to prevent 
                                     duplication of code.

 */

/* Only do this once in any given compilation */
#ifndef  support_func_h
#define  support_func_h

/* Common definitions */
#include <stddef_ep.h>

/* Host function prototypes */
#include <support_func.host.h>

/* IPG function prototypes */
#include <support_func.ipg.h>

#endif /* support_func_h */

