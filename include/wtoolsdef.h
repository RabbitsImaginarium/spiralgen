/*
 * GE Medical Systems
 * Copyright (C) 1996-1998 The General Electric Company
 *  
 * $Source: wtoolsdef.h $
 * $Revision: 1.9 $  $Date: 5/14/98 21:04:16 $
 *  
 * Definitions of structures and constants for WTools.
 *  
 * Language : ANSI C
 * Author   : 
 * Date     : 24/Jan/1996
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------

 */

/*@End*********************************************************/


/***************************************************************************
 *      Revision History
 ***************************************************************************
 Version          Date/        Author
                  Comment
 ***************************************************************************
 8.0.0            09/May/1995  JDM 
                  Removed trailing comma in enum types.

     	          24/Nov/1995  wfh/plexar  
                  Remove reference to xview.

                  08/May/1998  GFN 
                  Added definition for ACTV_ARGS.

 /main/mr_main/2  20-Nov-98    Dale Thayer
                  Original ClearCase consolidated version for ANSI C.
                  Removed the WT_CLOSED definition because it conflicts
                  with WT_ACTIVE_STATUS.

 ***************************************************************************/



/* only do this once in any given compilation.*/
#ifndef  wtoolsdef_h
#define  wtoolsdef_h

#include "wtoolsid.h"

/*
 * Generic Link Node that will be used to connect all nodes. 
 * This will afford us to create a generic link utility.  Less
 * room for mistake.
 */
typedef struct newnode {
    ADDRESS node_ptr;
    struct newnode *next;
} WT_LINK_NODE;


/************ Active Status ***********/
/* Active Nodes - Nodes for tracking active tools */
typedef enum {
    WT_CLOSED,
    WT_BUSY,
    WT_ACTIVE
} WT_ACTIVE_STATUS;

typedef struct {
    long queue_id;           /* Queue id (not the file descriptor) */
    long local_id;           /* Used to store the program id */
    STATUS locked;           /* Disable multiple copies */
    WT_ACTIVE_STATUS active; /* Closed, Busy, Or Active */
} WT_ACTIVE_NODE;

typedef struct {
    long active_cnt;            /* Number of active copy tools  */
    long max_copies;            /* Maximum number of copy tools */
    STATUS multi_allowed;       /* Are multiple copies allowed  */
    WT_LINK_NODE *active_list;  /* List of active copies        */
} WT_ACTIVE_BASE;

typedef WT_ACTIVE_BASE WT_ACTIVE_QUEUE[WT_IPCID_MAXTOOLS_NO];

/* Argument structure */
typedef struct {
    long queue_id;
    long local_id;
    short cnt;
    short max_copies;
    long locked;
    WT_ACTIVE_STATUS status;
} ACTV_ARGS;


/************ Browser Flag *******/


/****** Processor Mask ********/
#define XGRAD_MSK 0x0001
#define YGRAD_MSK 0x0002
#define ZGRAD_MSK 0x0004
#define SSP_MSK   0x0008
#define RHO1_MSK  0x0010
#define RHO2_MSK  0x0020
#define THETA_MSK 0x0040
#define OMEGA_MSK 0x0080
#define MAX_PROCESSORS_MSK 8

/*  Window and Icon Positions */
typedef struct {
    char *Wpx;
    char *Wpy;
    char *WPx;
    char *WPy;
} WT_IN_POSITIONS;

#define IGNORE -1
#endif /* wtoolsdef_h */
