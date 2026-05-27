/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1990 The General Electric Company
 *
 *	Include File Name:  rfblochdef   
 *	Developer: B.L. Mazin
 *
 * $Source: rfblochdef.h $
 * $Revision: 1.5 $  $Date: 02 Sep 1992 08:40:44 $
 */

/*@Synopsis 
	rf bloch definitions.
*/     

/*@Description
	The following file contains the rf bloch definitions and default 
	values for the user inputs.
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
                  Consolidated the enum types for LINE_STYLES.

 ***************************************************************************/


/* only do this once in any given compilation.*/
#ifndef  rfblochdef_INCL
#define  rfblochdef_INCL

#define GAMMA 26.75
#define WAMP_LIMIT 32766.0

#define DELF_DEF 	0.0
#define FLIPANGLE_DEF 	90
#define MX_DEF 		0.0
#define MY_DEF 		0.0
#define MZ_DEF 		1.0
#define Minf_DEF 	1.0
#define T_DEF		1000.0
#define TOLERANCE_DEF 	0.00002
#define V0_DEF 		0.0
#define CFGCMFS         1.0

#define RUNGA_RANGE    40

#define _SIGNAL 0x1
#define _PHI    0x2
#define _THETA  0x3
#define _MX     0x4
#define _MY     0x5
#define _MZ     0x6

/*** Data Points for the plot ***/
typedef struct
{
   float tip;
   float fan;
   float signal;
   float mx;
   float my;
   float mz;
   float z;
} DATA_POINTS;

/*** Inputs Supplied by the User *****/
enum CLIENT_ORDER {
C_TOLERANCE,
C_FLIP_ANGLE,
C_CHEM_SHIFT,
C_RELAX_RATE1,
C_RELAX_RATE2,
C_MX,
C_MY,
C_MZ,
C_MINF,
C_Z_VEL,
C_Z_MIN,
C_Z_MAX,
C_Z_PTS,
C_CFGCMFS,
C_SEQUENCE,
C_TIME,
C_ITMAX
};

typedef struct
{
   float delf;             	/* Chemical Shift */
   float flipangle;	   	/* Flip Angle, degrees */
   int   grad_choice;      	/* Z Grad Choice */
   float mx;               	/* Initial Mag settings */
   float my;
   float mz;
   float minf;
   float t1;               	/* Relaxation Rate */
   float t2;               	/* Relaxation Rate */
   float tolerance;        	/* APC's divergence's tolerance */
   long int itmax;     /* In - Time, samplings */
   float tmin, tmax;
   int tseq;                    /* In - current working sequence */
   float v0;               	/* Velocity */
   float zmin, zmax; 
   int   izmax;     		/* Out - z gradient range, and */

   char *pd_name;               /* Name of PD file */

   FLOAT cfgcmfs;                 /* G/Cm2 normalized */

   WF_PROCESSOR which_rho;	/* rho1 or rho2 */
   int phase_ctrl;	        /* real, freq, phase, freq&phase */
   int dummy;
} CALC_INPUTS; /* From User or Plot pulse tool */



/***** RF Sequence Of Equations Obtained From Database ******/

typedef struct 
{
   float Mg;   /* Integral G(t)dt */
   float Mgt;  /* Integral G(t)tdt */
} LINEAR_NODE;

typedef struct
{
   float *grad;
   float *rho;
   float *theta;
   float *omega;
   float *fi;
   float *rfi;
   float *rfq;
   float *cur_time;
   float phase;
   float frequency;
} APC_NODE;

typedef enum
{
   SEQ_APC,
   SEQ_LINEAR
} SEQ_TYPE;


typedef struct 
{
   SEQ_TYPE seq_type;
   long start;
   long end;
   float delta_h;
   long nsamples;

   WT_LINK_NODE *data_lst;
   WT_LINK_NODE *next;         
} RF_SEQ; 

typedef struct {
   int nrf0_seq;
   WT_LINK_NODE *rf_seq;   
}EQUATION_ORDER;

/****** Attributes for reading man-machine inputs ****/
typedef struct
{
   int length;
   int fractal_positions;

   STATUS neg_allowed;   
} INPUT_ATTRBS;


typedef struct
{
   char *tolerance;
   char *flip;
   char *chem;
   char *relax_rate1;
   char *relax_rate2;
   char *mx;
   char *my;
   char *mz;
   char *minf;
   char *z_veloc;
   char *zmin;
   char *zmax;
   char *zpts;
   char *cfgcmfs;
   char *itmax;
   int  grad;
   int  rho;
   int phase_ctrl;		/* Real, Freq, Phase, Freq & Phase */
   int click_count;
} DEFAULT_INPUTS;

#define VIEW_EMPTY    (STATUS)0
#define VIEW_PLOTTING (STATUS)1
#define VIEW_UP       (STATUS)2
#define VIEW_PLOTTED  (STATUS)3
#define VIEW_ABORTED  (STATUS)4

typedef enum {
 	PMODE_OFF,
	PMODE_LPR,
	PMODE_POSCRIPT
} PRINT_MODE;


typedef struct
{
   STATUS exiting;
   STATUS load_only;
   STATUS bell_on_flag;
   STATUS plotview;
   STATUS canvas_active;
   STATUS hold_data;
   STATUS data_in_queue;
   PRINT_MODE print_mode;
} RFTOOL_STATUS;


#define CALC_PLOTSYNC 0x2222
   
#define MAX_PHASE_CTRLS 	20
typedef struct 
{
   int npulses;
   float phase[MAX_PHASE_CTRLS];
   float frequency[MAX_PHASE_CTRLS];
} PHASECTRL_BLOCK;

typedef enum 
{
   PCTRL_REAL,
   PCTRL_PHASEONLY,
   PCTRL_FREQONLY,
   PCTRL_PHASEFREQ
} PHASECTRL_CHOICES;

/**** Data Types for XMission ****/
#define CALC_DATA      1
#define CALC_PHASECTRL 2

/**** Define Constants for the Print ****/
typedef struct {
	char *filename;
        char *printer;
        char *title;
        PRINT_MODE mode;
        STATUS inputs_on;
        STATUS landscape_mode;
} PRINT_OPTIONS;
        
        
typedef enum
{
   GC_DOTTEDLINE,
   GC_SOLIDLINE,
   GC_DASHEDLINE,
   GC_MOMENT0,
   GC_MOMENT1,
   GC_MOMENT2,
   GC_MOMENT3,
   GC_COUR_R_16,
   GC_COUR_R_12,
   GC_COUR_R_10,
   GC_COUR_R_8,
   GC_COUR_B_10,
   GC_COUR_B_14,
   GC_HEADER_FONT,
   GC_TICK_FONT,
   GC_CURSORLINE,
   GC_LABEL_FONT,
   GC_BARS
} LINE_STYLES;

typedef enum {
C_CROSS_HAIR,
C_VERT_HAIR,
C_HORZ_HAIR,
C_VERT_HORZ_HAIR
} CURSOR_STYLES;

#endif /* rfblochdef_INCL */

