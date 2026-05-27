/*********************************************************************
    INCLUDE FILE : epic_rt.h

    DESCRIPTION: Contains various types and constants for the runtime
	routines.  This file is included by Psd interface code in the
	PSD runtime library (epic_rt.a) and by the Psd manager objects
	which get linked in to scan.  epic_struct.h should be included
	before this file to use certain macros.
      
    $Source: epic_rt.h $
    $Revision: 1.38 $  $Date: 22 Jul 1997 17:06:50 $


    RELEASE	DATE            AUTHOR(S)	DESCRIPTION
    -------	------------    ------------	-----------
    5.0		1/12/90		Douglas Earl	initial version
    5.1		12/13/90	Russ Brown	added opcodes 26 & 27
    5.1		05/08/91	Greg Pavlik 	added opcode 28
    5.1 	10/16/91	Greg Pavlik	get rid of allvis stuff
    8.1         10/26/95        RJL             Remove mrp additions of meng (1.28)
                                     VMX changed packet sizes and this caused MrMail
				     and psdmgr to fail.
    8.2         12/05/95        RJL             Change MAXPACKET to 4096. With all our
                                                new CV's over the years the old value
						of 2048 was causing IFCC to choke.
    8.3         04/15/96       RJL   1. Added constructs and defines for AdvPnl Popup:
                                            advpnlstruct structure,
					    advpnlcvs array added to send_pkt union,
					    ADVISORY_ERROR, ADVPNL_ENTRY, CV_ENTRY defines added
					    see 8.0 EPIC Advisory Panel SDD for details
				     2. Added ifdef wrapper to prevent multiple inclusion.
    8.4         04/15/96      RJL    Add closing to ifdef missed in 8.3
    8.5         09/13/96      RJL    MRIge34891: Added _rangeArray structure for use in
                                     maintaining log of system range errors in psdIF.
    8.6         11/14/96      RJL    MRIge36756: Added defines for advisory panel to be used
                                     within psdIF routines and epic_AdvPnlLUT.h
				     ADVPNL_ENTRY, USERCV_ENTRY, CV_ENTRY, ENDLUT.

 ***************************************************************************
 Version          Date/        Author
                  Comment
 ***************************************************************************
 /main/mr_main/2  8-Oct-98     Dale Thayer
                  Changed defines from epic_struct.h which conflicted with
                  stdarg.h (_INT, _SHORT, _FLOAT, _DOUBLE, _EXPORT,  _STRUCT).

 ***************************************************************************/


#ifndef  epic_rt_INCL
#define  epic_rt_INCL

/* Include the file that the application needs in order to use the PSD
   runtime environment.  This is also needed by the runtime environment
   itself */
#include "epic_types.h"

/****** opcodes ***********************************************/
#define REVISION	1
#define GETNAME		2
#define GETCVVALS	3
#define GETCVDATA_ONE	4
#define GETCVDATA_MANY	5
#define GETSHAREDVAR	6
#define GETRSP		7
#define GETRSP_NAMES	8
#define GETHEADER	9
#define PUTSHAREDVAR	10
#define PUTCVS		11
#define PUTCVEVAL	12
#define UNFIXCV		13
#define SETEXIST	14
#define SETPAGE		15
#define PREDOWNLOAD	16
#define CVCHECK		17
#define EVALCVS		18
#define RANGECHECK	19
#define SAVECVS		20
#define READCVS		21
#define DOWNLOADCVS	22
#define DLOADNEEDED	23
#define COPY		24
#define TERMINATE	25

/* new opcode to send down rotation matrix for */
/* scaling/transpose during predownload. -rjb  */
#define ROTMATRIX	26
/* new opcode for getting cv data by number - rjb */
#define GETCVDATA_NUM	27
/* new opcode for saying that the wavegen failed - gp */
#define WAVEGENFAIL	28
#define STARTAPSD	29
#define PSDINIT		30

#define GETCVNAME_MANY	31
/* added by jensong@wiproge for SmartPrep  for TRACKER Rotation matrix */
#define TRACKROTMATRIX  32


/****** miscellaneous constants *******************************/
#define MAXCVNAME 16
#define MAXCVSTRUCTS 30
#define MAXFILENAME 128
#define MAXPATHNAME 128
#define MAXRSPS 90
#define MAXARGLEN 16
#define MAXERRSTR 80
#define MAXERRSTRSP 128
#define MAXARGS 10
#define MAXPSDNAMELEN	256
#define MAXSWITCHLEN	32
#define MAXNAMESTRUCTS 100

/* max number of bytes in msg queue (system defined limit) */
#define MAXPACKET 4096

#define EOL -99		/* end of list (of CV numbers) */

#define ERROR 	-1
#define ADVISORY_ERROR -4
#define WARNING	-3
/* support for advisory panel */
#define ENDLUT -999
#define ADVPNL_ENTRY 0
#define CV_ENTRY 1
#define USERCV_ENTRY 2

#define TIMEDOUT -2
#define NORESPONSE -2
#define OK 0
#define LASTPACKET 0
#define MOREPKTS 1
#define NOTFOUND -1
#define SAVESUFFIX ".sav"
#define IPGSUFFIX ".psd.o"

/* visibility attributes - note that these are also declared in epic_struct.h
   for use by the PSD programmer (as bitmasks). */
#define VISBIT 0
#define MODBIT 1

/* keys for the message queues */
#define CMDQ 100	/* to PSD */
#define DATAQ 101	/* to PSD manager */

/* these may be defined elsewhere, so check 1st before re-defining them */
#ifndef LOCAL
#define LOCAL static
#endif
#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif
#ifndef BOOLEAN
#define BOOLEAN short
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/* include epic_struct.h in order to use these macros */
/* Visibility of a CV is determined by the visibility bit and whether
   or not CV "pilock" exists.  If it does, then visibility is based on
   the bit, if it doesn't, everything is visible. epic_allvis is a
   global variable defined and initialized in epic_main.c */
/* Editted by gp 10/16/91...get rid of allvis stuff...there is a 
   compiler option to take care of this now.  epic_main.c in the 
   project psdIF is where this variable originates. */

/*
extern BOOLEAN epic_allvis;
#define IS_VISIBLE(visflag) ((visflag & _VISBIT) || epic_allvis)
#define GET_VIS(visflag) (epic_allvis ? MODIFIABLE : visflag)
*/

/* new code by gp */
#define IS_VISIBLE(visflag) (visflag & _VISBIT)
#define GET_VIS(visflag) (visflag)

/* Define a macro to get a field out of the CV structure and assign it to
   a local variable.  The compiler requires that the type independent stuff
   follow the type dependent stuff, so a switch statement on the type is
   needed to access everything.  To use this macro declare a variable with
   the same name as the field being accessed. It will be assigned the value
   of the field for the CV indicated by cvnum. */
#define CVGET(cvnum, field)\
{\
    _cvptr cv;\
    cv.ptr = _cvarray[cvnum].cv;\
    switch (_cvarray[cvnum].type) {\
	case GE_INT: field = cv.i->field; break;\
	case GE_FLOAT: field = cv.f->field; break;\
	case GE_SHORT: field = cv.s->field; break;\
	case GE_DOUBLE: field = cv.d->field; break;\
    }\
}

#define CVPUT(cvnum, field, val)\
{\
    _cvptr cv;\
    cv.ptr = _cvarray[cvnum].cv;\
    switch (_cvarray[cvnum].type) {\
	case GE_INT: cv.i->field = val; break;\
	case GE_FLOAT: cv.f->field = val; break;\
	case GE_SHORT: cv.s->field = val; break;\
	case GE_DOUBLE: cv.d->field = val; break;\
    }\
}

/****** structures to hold CVs ********************************/
typedef struct {
    short type;
    double val;
} valstruct;

/* Structure for saving value of a CV before it is written to.  If there
   is an error after CV evaluation, this will be used to set the CV back
   to its original value. Moved here from epic_put.c 5/22/96 - RJL */
typedef struct {
    double oldval;
    unsigned char fixval;
    int existval;		/* added by gp 07/18/91 */
    int popupval;
} save_info;

/*--------------------------------------------------------------------------------------
 *  4/15/96 RJL - New structure for passing advisory panel popup items information to scan.
 *  For formatting into the list scan requires the type (FLOAT,SHORT,DOUBLE,INT). The cvnum
 *  is the CVindex used for communication between scan and psd as prior.
 *-------------------------------------------------------------------------------------*/
typedef struct {
    int   cvnum;
    short  type;
    double  val;
} advpnlstruct;

/* name and descr are offset into string space.  val, min and max are
   transferred between scan and PSD as doubles to avoid unnecessary type
   hassles. vis, fixed and exist are declared as bit fields (as defiend
   in epic_struct.h) in order to conserve on space. */
typedef struct {
    int name;
    int cvnum;
    short type;
    double val, min, max;
    unsigned int visibility:2, fixed:1, exist:4, popup:1;
    int descr;
} cvstruct;

typedef struct {
    int name;
    int cvnum;
} cvnamestruct;


/****** arguments to log with errors **************************/
typedef struct {
    short type;  /* use constants in epic_types.h for this field */
    union {
	int intval;
	double doubleval;
    } u;
} argstruct;

/****** error information *************************************/
typedef struct {
    char str[MAXERRSTR];
    int num;
    int nargs;
    argstruct args[MAXARGS];
    char ss[MAXERRSTRSP];
} error_info;

/****** data needed to change the value of a CV ***************/
typedef struct {
    short cvnum;
    double val;
} cvdata;

/* data needed to start a psd *******************************/
typedef struct {
	char psdname[MAXPSDNAMELEN];
	char switches[MAXSWITCHLEN];
} psdstart;

		
/****** identification of a group of CVs **********************/
typedef struct {
    int start, num;
    char matchstr[MAXCVNAME];
} varchoice;
		
/****** header for packet sent to/from PSD *************************/
typedef struct {
    int srcid;	/* for response packet */
    short opcode;
    int status;
    short more_pkts; /* are there more packets coming? */
} pkt_header;

/* define the max number of bytes allowed in the data portion of a packet */
#define MAXMSGBUF (MAXPACKET - sizeof(pkt_header) - sizeof(int))
/* subtract for extra fields in the shvar struct */
#define MAXPUTBUF (MAXMSGBUF - (2*sizeof(int)) - sizeof(BOOLEAN))
/* subtract for the evalmode int in the put struct */
#define MAXCVS ((MAXMSGBUF - sizeof(int)) / sizeof(cvdata))

/****** command packet for requests to PSD ********************/
typedef union {
    /* getcvvals, putgetcv */
    int cvnums[MAXCVS];

    /* putcvs */
    cvdata cvs[MAXCVS];

    /* putcveval */
    struct {
	int evalmode;
	cvdata cvs[MAXCVS];
    } put;

    /* unfix */
    struct {
	int evalmode;
	int cvnum;
    } unfix;

    /* setexist */
    struct {
	int evalmode;
	BOOLEAN setflag;	/* set existence to true (pagenum) or false? */
	int cvnums[MAXCVS];
    } exist;

    /* getcvdata_one */
    char name[MAXCVNAME];

    /* getcvdata_many, getrsp_names */
    varchoice which_vars;

    /* general purpose int: setpage (pagenum), evalcvs (evalmode) */
    int num;

    /* putsharedvar getsharedvar */
    struct {
	int varnum;
	int nbytes;
	BOOLEAN do_checksum;
	char buf[MAXPUTBUF];
    } shvar;

    /* saveCVs readCVs */
    struct {
	char filename[MAXFILENAME];	/* path of the file to read/write */
	char executable[MAXPATHNAME];	/* path of the executable */
    } savecvs;

    /* downloadCVs */
    struct {
	unsigned int addr;
	int maxlen;
    } dload;

    /* getRSP */
    struct {
	char name[MAXRSPNAME];
	int subscript;
    } rsp;

    psdstart	start;

    /* predownload cvcheck rangecheck copy terminate getheader
       revision, getname - no data */
} cmdpkt_union;

typedef struct {
    int destid;	/* must be 1st - corresponds to type in msgsnd packet */
    pkt_header hdr;
    cmdpkt_union u;
} cmd_pkt;

/* subtract bytes for the fields in the cvs structure below */
#define MAXSTRSPACE (MAXMSGBUF - 4 - (MAXCVSTRUCTS * sizeof(cvstruct)))

#define MAXNAMESPACE (MAXMSGBUF - 4 - (MAXNAMESTRUCTS * sizeof(cvnamestruct)))

/* subtract bytes for the fields in the shvar structure defined below */
#define MAXSHVARBUF (MAXMSGBUF - (2 * sizeof(int)))

/* subtract bytes for the fields in the rsps structure below */
#define MAXRSPSTRUCTS ((MAXMSGBUF - 4) / sizeof(rspdata))

/****** packet for responses from PSD *************************/
typedef union {
    error_info error;

    /* getcv, putgetcv */
    valstruct cvvals[MAXCVS];

    /*---------------------------------------------------------------------------
     * 4/15/96 RJL - New packet info to pass back which cv's to place into popup list
     * for 8.0 Advisory Panel Popup. We pass the number of cv's in the list and the 
     *  information for each item in the list.
     *--------------------------------------------------------------------------*/
    struct {
      int ncvs;
      advpnlstruct advcvs[MAXCVS];
    } advpnlcvs;

    /* getcvdata - one CV */
    /* For name and description of CV, use offset into a string space.
       Doing this allows a greater number of CVs to be returned than
       declaring the maximum space for the 2 strings here. */
    struct {
	cvstruct data;
	char str_space[MAXSTRSPACE];
    } cv;

    /* getcvdata - many CVs */
    struct {
	short ncvs;
	short position;		/* start, end or middle */
	cvstruct data[MAXCVSTRUCTS];
	char str_space[MAXSTRSPACE];
    } cvs;

    /* getcvname - many CVs */
    struct {
	short ncvs;
	short position;		/* start, end or middle */
	cvnamestruct data[MAXNAMESTRUCTS];
	char str_space[MAXNAMESPACE];
    } cvnames;

    /* getsharedvar, getsharedvar_cs */
    struct {
	int nbytes, checksum;
	char buf[MAXSHVARBUF];
    } shvar;

    /* getheader */
    headerstruct header;

    /* getrspnames */
    struct {
	short nrsps;
	short position;		/* start, end or middle */
	rspdata data[MAXRSPSTRUCTS];	/* rspdata defined in epic_types.h */
    } rsps;

    /* revision */
    struct {
	int	cv_rev;  /* revision of CVs specified by PSD programmer */
	long	src_rev; /* date and time of PSD source file */
    } rev;

    /* general purpose int: copy (pid), getrsp (type), dloadneeded (T/F) */
    int num;

    /* buffer for miscellaneous data (max packet size): getname */
    char buf[MAXMSGBUF];

    /* predownload cvcheck rangecheck terminate putcvs
       unfixCVs setexist saveCVs readCVs - no data */
} datapkt_union;

typedef struct {
    int destid;	/* must be 1st - corresponds to type in msgsnd packet */
    pkt_header hdr;
    datapkt_union u;
} data_pkt;

typedef struct {
    int cvnum;
    int error_type;
} _rangeArray;

#endif












