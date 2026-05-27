/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1990 The General Electric Company
 *
 *      Include File Name:  epic_psddef
 *      Developer: B.L. Mazin
 *
 * $Source: epic_psddef.h $
 * $Revision: 1.1 $  $Date: 11/2/93 09:27:53 $
 */

/*@Synopsis 
	Allocation Queues.
*/     

/*@Description
	These queue will point to pulse memory and dynamic memory.  
	They are used by the routines that reset memory and free
	dynamically allocated heap
     
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  epic_psddef_INCL
#define  epic_psddef_INCL

typedef struct ALLOC_QUEUE_PTR {
        ADDRESS data_ptr;
        struct ALLOC_QUEUE_PTR *next;
} WFALLOC_QUEUE;

typedef struct PULSE_QUEUE_PTR {
	WF_PULSE_ADDR pulse_ptr;
        struct PULSE_QUEUE_PTR *next;
} WFPULSE_QUEUE;
        
extern WFPULSE_QUEUE wf_pulse_alloc;
extern WFALLOC_QUEUE wf_alloc_queue;

#endif /* epic_psddef_INCL */
