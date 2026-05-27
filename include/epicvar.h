/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1989 The General Electric Company
 *
 *      Include File Name:  epicvar   
 *      Developer:          B.L. Mazin
 *
 * $Source: epicvar.h $
 * $Revision: 1.3 $  $Date: 11/2/93 09:26:18 $
 */

/*@Synopsis 
*/     

/*@Description
     
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  epicvar_INCL
#define  epicvar_INCL

extern WF_INSTR_QUEUE wf_queue[WF_MAX_PROCESSORS];

extern LONG seq_greatestdur;  /* Greatest duration length of a sequence */
extern LONG seq_offset;       /* Sequence Offset */
extern LONG seq_group;        /* Sequnece Group  */
extern LONG seq_start;        /* Start of the sync and scope bits on SSP */
extern SEQUENCE_LIST sequence_list;

#endif /* epicvar_INCL */
