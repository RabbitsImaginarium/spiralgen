/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1992-1998 The General Electric Company
 *
 *	File Name:  rfprof_def.h
 *	Developer:  BL Mazin
 *
 * $Source: rfprof_def.h $
 * $Revision: 1.4 $  $Date: 6/25/98  11:02:10  $
 *
 *@Description
 *      This file contains the typecasts shared between relocatable files.
 *
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version      Date         Author
              Description
 ------------------------------------------------------------------
 5.3.1	      01/23/93	   BLM	
              Added the original 5x format to the list of options

              05/19/97     CQ      
              changed  PROF_SIG to  PROF_SIG2 since it is used by UNIX
              This Symbol is not used by PET code

 sccs1.4      22-May-98    Dale Thayer
              Original for cardiac, CV1, conversion to ANSI C.

 *@End*************************************************************/


#ifndef  rfprof_def_h 			/* we only want file included once */
#define  rfprof_def_h

#include <math.h>

#define OLDFILE_FORMAT(x) (x == SHOW_4XOPTIONS || x == SHOW_5XOPTIONS)

typedef enum {
   SHOW_SINC,
   SHOW_6XOPTIONS,	/*This option will not be implemented in 5.x, so
			 * it will be referenced as 6.x in the code. */
   SHOW_5XOPTIONS,   /*This option is the original 5.x format */
   SHOW_4XOPTIONS,
   SHOW_EXTFILE,
   SHOW_NONE
} SHOW_CHOICES;


typedef enum {
	SMALL_TIP,
	INVERSION,
	SPIN_ECHO,
	SATURATION,
	P1_2,
	UNENTERED_PULSE
} PULSE_TYPES;

	
typedef enum {
	PROF_SIG2,
	PROF_CRUSH_SIG,
	PROF_MZ
}PROFILE_PULSES;
	

typedef enum {
	LINEAR_PHASE,
	MINIMUM_PHASE,
	MAXIMUM_PHASE,
	QUAD_PHASE,
	SELF_REF_PHASE,
	UNENTERED_PHASE
} PHASE_TYPES;

typedef enum {
	LOAD_RF,
	DESIGN_RF,
	PLOT_RF,
	PLOT_RESPONSE,
	CREATE_RF_FILE,
	NO_INPUT_SELECTION
} IO_SELECTION;

#define MAX_FILE_NAME 120
#define VERSION_4X    0
#define VERSION_5X    1
#define VERSION_6X    2

typedef struct {
  	INT pulsetype;
 	CHAR filename[MAX_FILE_NAME];			
	FLOAT right_sinc;
	FLOAT left_sinc;
	INT resol_pts;
	FLOAT flip_angle;
	FLOAT pulse_dur;
        INT   version;
        FLOAT maxB1;
	PULSE_TYPES pulse_type;
	PHASE_TYPES phase_type;
}LOADRF;

typedef struct {
	PULSE_TYPES pulse_type;
	PHASE_TYPES phase_type;
	FLOAT bandwidth;
	FLOAT passband;
	FLOAT stopband;
  	INT resol_pts;
	FLOAT flip_angle;
	FLOAT pulse_dur;
}DESIGNRF;

typedef struct {
	INT plottype;
	INT plottrace;
 	CHAR *filename;			
}PLOTRF;

typedef struct {
	INT plottype;
	INT plottrace;
	INT plotfeatures;
 	CHAR *filename;			
}PLOTRESPONSE;


typedef struct {
  	INT filetype;
	INT systemtype;
	INT npts;
 	CHAR *filename;			
}CREATERF;

typedef struct {
	STATUS load_only;
        STATUS exiting;
        STATUS bell_on_flag;
        IO_SELECTION last_choice;
        IO_SELECTION last_input;
        PULSE_TYPES  last_pulse;
        PHASE_TYPES  last_phase;
	LOADRF   init_loadrf;
	DESIGNRF init_designrf;
	PLOTRF    init_plotrf;
	PLOTRESPONSE  init_plotresp;
        CREATERF init_createrf;
	STATUS rf_loaded;
        INT    nwindows;
} STATUS_FIELDS;

typedef struct {
	FLOAT fp;
	FLOAT fs;
	FLOAT w;
	INT npts;
	FLOAT dinf;
} ADVISORY_FIELDS;

typedef struct {
	INT length;
	INT fractal_position;
	STATUS neg_allowed;
} INPUT_ATTRBS;

typedef struct {
	FLOAT lower;
	FLOAT upper;
	CHAR *name;
} INPUT_LIMITS;

typedef enum {
	TRACE_MAG,
	TRACE_REALIMAG,
	TRACE_MAGPHASE
} TRACE_TYPES;

#define SMALL_IMAG 0.0000000001
/*** Uses the complex structures defined in slr.h *****/
#define C_MAGNITUDE(n) sqrt(pow(n->x, 2.0) + pow(n->y, 2.0))
#define C_PHASE(n) ((n->y < SMALL_IMAG && n->y > -SMALL_IMAG) ? (n->x > 0 ? 0 : M_PI) :  atan2(n->y, n->x))
#define C_REAL_PART(n) n->x
#define C_IMAG_PART(n) n->y

#define KEY_NOT_FOUND(x){{ if (!ignore_error){WriteMsg(YES,YES,"***\n Can not find key %s in database",x); return (FAILURE); }}}
#define INVLD_INPVALUE_FOR(x){{if(!ignore_error){ WriteMsg(YES,YES,"***\n Invalid value for %s in database",x); return (FAILURE);} }}

/*
 * 	This following was copied from the xlatebin project. It has
 *	been updated for creating a 5.x external file.
 */

 
#define MAGICNUM              "IPG0"
#define REVNUM                 1

#define HDR_DESCR_LEN          16  /*  4 byte words  */
#define HDR_LEN_UNUSED         48  /*  bytes  */

typedef struct /*  header structure  */
{
        char magicnum[4];
        unsigned long            hdrlen;
        unsigned long            revnum;
        unsigned long            filelen;
        char                     unused[HDR_LEN_UNUSED];
} HDR_SECTION;


#endif                                  /* end: if rfprof_def_h not defined */
