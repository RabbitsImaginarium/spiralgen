/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1989 The General Electric Company
 *
 *	Include File Name:  plotdata
 *	Developer:	    B.L. Mazin
 *
 * $Source: plotdata.h $
 * $Revision: 1.4 $  $Date: 5/9/95 09:24:26 $
 */

/*@Synopsis 
*/     

/*@Description
     
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  plotdata_INCL
#define  plotdata_INCL
#define WEOS_BIT_SSP 0x8000
#define WEOS_BIT     0x0001
#define EOS_BIT      0x0100
#define PERIOD_POS   0

#define PERMS 0666
 
typedef struct {
   long wavegen_size;
   long instr_size[(int)WF_MAX_PROCESSORS];
   short *wavegen_addr;
   long *instr_addr[(int)WF_MAX_PROCESSORS];
} PLOT_DATA_HDR;
 
typedef struct {
   short y;
   long  time;
/*
   short *instr_ptr;
   short *resol_ptr;
   short resol_delta;
*/
   short gravity_pt;
} DATA_POINTS_NODE;

typedef struct {
   STATUS data_in_table;
   short nsamples;
   short current_sequence;
   PLOT_DATA_HDR hdr;                   /* Header information          */
   short *wavegen_ptr;                  /* Pointer to the wavegen data */
   short *instr_ptr[(int)WF_MAX_PROCESSORS]; /* Pointer to iwave/iwait data */
   DATA_POINTS_NODE *data_pts[(int)WF_MAX_PROCESSORS];
} PULSE_DATA_TABLE;
 
 
#endif /* plotdata_INCL */
