/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1990 The General Electric Company
 *
 *	Include File Name:  rfblochinc   
 *	Developer:
 *
 * $Source: rfblochinc.h $
 * $Revision: 1.4 $  $Date: 02 Sep 1992 08:40:49 $
 */

/*@Synopsis 
*/     

/*@Description
     
*/

/*@End*********************************************************/


/***************************************************************************
 *      Revision History
 ***************************************************************************
 Version          Date/        Author
                  Comment
 ***************************************************************************
 /main/mr_main/2  20-Nov-98    Dale Thayer
                  Original ClearCase consolidated version for ANSI C.

 ***************************************************************************/



/* only do this once in any given compilation.*/
#ifndef  rfblochinc_INCL
#define  rfblochinc_INCL

/*** Buttons ****/
#define B_PLOT  0x001
#define B_ABORT 0x002
#define B_CLEAR 0x004
#define B_PRINT 0x008
/*#define B_HELP  0x010 */
#define B_LOAD  0x010
#define B_STORE 0x020

#define PLOT_CHOICES 6

#ifdef MAINPROG
int calc_pid = 0;		/* Process id of active CalcBloch Task */
int calc_id = 0;		/* Associated id of active CalcBloch queue */
int print_pid = 0;		/* Process id of active Print Task */
int print_id = 0;		/* Associated id of active Print queue */
WT_ACTIVE_STATUS xcalc_mode;     /* Active status of CalcBloch Task */
int own_id;		        /* Own task process id */
int own_qid;			/* Own task queue id */
int data_point_ix = 0;		/* Data point index */
DATA_POINTS *data_points = NULL;/* Data point table */
CALC_INPUTS input_set;		/* Input setup that will be sent to CalcBloch*/
CALC_INPUTS input_plotted;	/* A history of the inputs for last plot */
int plot_choices = 0;	        /* Types of plots */
RFTOOL_STATUS rfstatus = { NO, NO, NO, VIEW_EMPTY, NO, NO, 0, PMODE_OFF};
long button_active = 0;
char *plot_name[PLOT_CHOICES] = {"signal", "phi", "theta", "mx", "my", "mz"};
PHASECTRL_BLOCK phasectrl_block = { 
   1, 0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
#else
extern int calc_pid;
extern int calc_id;
extern int print_pid;
extern int print_id;
extern int own_id;
extern int own_qid;
extern WT_ACTIVE_STATUS xcalc_mode;
extern int data_point_ix;
extern DATA_POINTS *data_points;
extern CALC_INPUTS input_set;
extern CALC_INPUTS input_plotted;
extern RFTOOL_STATUS rfstatus;
extern long button_active;
extern char *plot_name[PLOT_CHOICES];
extern int plot_choices;	        /* Types of plots */
extern PHASECTRL_BLOCK phasectrl_block;
#endif

#ifndef CREATEINPUTS
extern INPUT_ATTRBS  input_attrbs[];  /* Default setup attributes for Inputs,
					defined in CreateInputs.c  */
#endif

#endif /* rfblochinc_INCL */
