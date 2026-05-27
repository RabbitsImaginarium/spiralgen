/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: io_def.h $
 * $Revision: 1.2 $  $Date: 6/18/98 15:18:36 $
 *  
 * Include IO headers from VxWorks or the host computer.
 *  
 * Language : ANSI C
 * Author   : B. L. Mazin
 * Date     : 
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.2   18/May/1998  GFN         Removed SIM_IO conditional code.
 */

/* only do this once in any given compilation.*/
#ifndef  io_def_h
#define  io_def_h

#ifdef HW_IO

/* IPG Hardware */
#include <vxWorks.h>
#include <ioLib.h>
#include <stdioLib.h>
 
#else /* !HW_IO */
 
/* Anywhere else */
#include <stdio.h>
#include <sys/file.h>
 
#endif /* HW_IO */

#endif /* io_def_h */

