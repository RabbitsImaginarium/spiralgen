/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: grad.h $
 * $Revision: 1.6 $  $Date: 5/19/98 19:52:05 $
 * 
 * Interface file for the minseqseg.c file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 19-May-1998
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.1   16/Jun/1998  GNF         Initial version.
 */

#ifndef minseqseg_h
#define minseqseg_h

/* Public constants */
#define MAX_SLEWS 25

#define DBDT_ON       (1<<0)
#define PWM_ON        (1<<1)
#define IRMS_ON       (1<<2)
#define AMPTRANS_ON   (1<<3)
#define THEAT_ON      (1<<4)
#define SLEW_ON       (1<<5)
#define PHYSICAL_FLAG (1<<6)
#define ADJUST_TR     (1<<7)
#define IAVG_ON       (1<<8)

/* Public typedefs */
typedef struct s_list {
    INT time;
    FLOAT ampl;
    INT ptype;
} t_list;

#endif /* minseqseg_h */

