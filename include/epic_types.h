/*********************************************************************
    INCLUDE FILE : epic_types.h

    DESCRIPTION: Miscellaneous types and constants that the application
	needs in order to use certain features of the runtime environment.
	(Could be part of epic_rt.h, but don't want to have to make
	application include the whole file.)
  
	This file should be included in order to use the following methods:
	    - getRsp:at:offset:
	    - putRsp:val:offset:
	    - header
	    - putCv:eval:
	Also, if the type of a CV needs to be examined, use the CV types
	defined below.
      
    $Source: epic_types.h $
    $Revision: 1.12 $  $Date: 11/7/94 19:06:10 $

    RELEASE	DATE            AUTHOR(S)	DESCRIPTION
    -------	------------    ------------	-----------
    5.0		1/2/90		Douglas Earl	initial version
    8.1         10/26/95        RJL             Remove VMX additions of meng (sccs1.15)
**********************************************************************/
#ifndef  epic_types_INCL
#define  epic_types_INCL


/****** miscellaneous constants **************************************/
#define NOSUBSCRIPT -1	/* for getting an RSP */
#define DONTCARE -1	/* for CV revision when starting a PSD */
#define LASTCV -1	/* for specifying an array of CVs to get or put */

/****** CV types and error argument types ****************************/
/* note: these correspond with the constants in epic_macros.h */
#define INTTYP 0
#define SHORTTYP 1
#define FLOATTYP 2
#define DOUBLETYP 3
#define CHARTYP 4
#define STRINGTYP 5

/****** constants for getting multiple CVs and RSPs ******************/
/* startloc - make these negative since a specific CV location can be given */
#define FIRSTPAGE 0
#define LASTPAGE -1
#define PRIORPAGE -2
#define NEXTPAGE -3

#define ATSTART 0
#define ATEND 1
#define INMIDDLE 2

/****** evaluation mode bitmasks ************************************/
/* Bits are defined in the order used in evaltool.  If evaltool changes,
   these must too. */
#define INITBIT 0
#define EVALBIT 1
#define CHECKBIT 2
#define DLOADBIT 3

#define DO_CVINIT (1 << INITBIT)
#define DO_CVEVAL (1 << EVALBIT)
#define DO_CVCHECK (1 << CHECKBIT)
#define DO_PREDOWNLOAD (1 << DLOADBIT)

#define NOEVAL 0
#define FULLEVAL (DO_CVINIT + DO_CVEVAL + DO_CVCHECK + DO_PREDOWNLOAD)
#define PARTIALEVAL DO_CVEVAL

/****** header constants *********************************************/
#define MAXNAME 32
#define MAXABSTRACT 128
#define MAXREVSTR 16
#define MAXRSPNAME 32

/****** structure for the header of the PSD ************************/
typedef struct {
    /* following fields filled in by PSD */
    char name[MAXNAME];			/* name of PSD */
    char abstract[MAXABSTRACT];		/* short description of PSD */
    char revision[MAXREVSTR];		/* compiler revision */
    char release[MAXREVSTR];		/* product release */
    short product;			/* boolean - product or research? */
    short fixed;			/* boolean - compiled w/ fix switch? */

    /* following fields filled in by PSD manager */
    char *path;				/* Unix path name of executable */
    char *time;				/* time last modified */
    long itime;				/* as integer (st_mtime from stat(2)) */
    short saved;			/* boolean - a saved PSD? */
} headerstruct;

/****** structure for an rsp variable *****************************/
typedef struct {
    int type;
    union {
	int ival;
	short sval;
	float fval;
	double dval;
    } u;
} rspstruct;

/****** structure for displaying an rsp variable ******************/
typedef struct {
    short type;
    int nelements;
    char name[MAXRSPNAME];
} rspdata;

#endif
