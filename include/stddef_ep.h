/*
 * GE Medical Systems
 * Copyright (C) 1990-1998 The General Electric Company
 *  
 * $Source: stddef_ep.h $
 * $Revision: 1.33 $  $Date: 7/24/98 11:28:23 $
 *  
 * Standard definitions and typedefs. Includes some common prototypes.
 *  
 * Language : ANSI C
 * Author   : B. L. Mazin
 * Date     : 16/Aug/1990
 */
/* do not edit anything above this line */

/*
        Author   Date           Description
------------------------------------------------------------------------------
	B.L.M.	8/16/90		Modification to typdefs
				for successful gcc.
--------------------------------------------------------
	Y.H	02/10/94	Rename

	RJL     04/14/96        Add ADVISORY_ERROR so that can be imported
	                        by psdmgr and PSD projects.

	RJL     04/15/96        Change LX_POPUP to LX_ENBLpopup to coincide
                                with build environment variables.

        RJL     10/31/96        Added ENBLpopup as a global variable for use
                                in psdIF to shut down popup for system range
                                errors. Needed since psdIF builds with no
                                knowledge of environment per design.

        RJL     11/04/96        Moved Advisory Failure back to a #define to
                                eliminate the build Failure problem.

        RJL     1/10/97         Removed extraneous comments that added nothing.

        GFN    09/16/1997       Mapped datatypes to the ones in GEtypes.h
                                to be consistent. Added DOUBLE.
                                Added check for PSD_HW.
                                Added definitions for TRUE and FALSE.
                                Added definition for t_axis.

        GFN    09/21/1997       Added vxTypes.h for hardware compilations.
                                Verified that there are not multiple
                                definitions.

        GFN    09/23/1997       Added defintions for ON and OFF. Added
                                verifications for all the #defines to avoid
                                multiple definitions.

        GFN    10/09/1997       Added IPG in the check for HW compilations.
                                The vxTypes.h file should only be included for
                                HW compilations for the IPG.

        GFN    11/04/1997       Changed #include <GEtypes.h> to
                                #include "GEtypes.h" to allow projects that
                                do not use -I. to be able to find the file
                                locally.

        GFN    11/04/1997       Fixed to include the right header for
                                variable list of arguments. stdarg.h for
                                ANSI C and varargs.h K&R C. This check is
                                done by iovx_def.h.

        GFN    11/05/1997       Removed #include "iovx_def.h" because it
                                is not really needed for the prototypes.

        GFN    11/14/1997       Since CV's and RSP vars. cannot be long's,
                                it does not make sense to make INT and LONG
                                of type s32 (which is long). I am changing
                                these to 'int' to be compatible everywhere.
                                The same applies to UINT and ULONG.

        GFN    12/18/1997       Updated SCCS headers.

        GFN    04/06/1998       Added a comment explaining the definitions
                                for non-VxWorks compilations.
                                Simplified #if condition.

        GFN    05/13/1998       Made ADDRESS a true generic pointer.

        GFN    05/14/1998       Removed prototypes for FMax(), FMin, IMax()
                                and IMin(). They belong to psdutil.h.

        GFN    05/18/1998       Include psdutil.h to provide some common
                                prototypes, e.g., FMax(), FMin(), etc.
                                Updated header. Changed conditional HW_IO code
                                to include io_def.h.

 Dale Thayer   98-7-24          Changed include of <psdutil.h> to "psdutil.h".

*/

/* only do this once in any given compilation.*/
#ifndef  stddef_ep_h
#define  stddef_ep_h

#include "GEtypes.h"
#include "io_def.h"

/* New definitions match ones in GEtypes.h */
typedef s8 CHAR;
typedef s16 SHORT;
typedef int INT;
typedef INT LONG;
typedef f32 FLOAT;
typedef f64 DOUBLE;

/*
 * This section of code is included only for non-VxWorks compilations.
 * These definitions are already provided by vxTypes.h.
 */
#ifndef HW_IO
typedef n8 UCHAR;
typedef n16 USHORT;
typedef unsigned int UINT;
typedef UINT ULONG;
typedef int STATUS;
#endif  /* !HW_IO */

/* Generic address pointer */
#ifdef __STDC__
typedef void * ADDRESS;
#else /* !__STDC__ */
typedef char * ADDRESS;
#endif /* __STDC__ */

/* Define generic axis letters */
typedef enum e_axis {
    X = 0,
    Y,
    Z
} t_axis;

/* Include psdutil.h for some common definitions */
#include "psdutil.h"

/* All of these get defined so many times, */
/* let's not get in the way of other definitions. */
#ifndef ERROR
#define ERROR    -1
#endif /* ERROR */

#ifndef EOF
#define EOF     (-1)
#endif /* EOF */

#ifndef NULL
#define NULL    0
#endif /* NULL */

#if     !defined(FAILURE) || ((FAILURE) != 0)
#define FAILURE  (0)
#endif /* FAILURE */

#if     !defined(SUCCESS) || ((SUCCESS) != 1)
#define SUCCESS  (1)
#endif /* SUCCESS */

#ifdef LX_ENBLpopup
#define ADVISORY_FAILURE 2
#else
#define ADVISORY_FAILURE FAILURE
#endif

#if     !defined(SKIP) || ((SKIP) != 3)
#define SKIP  (3)
#endif /* SUCCESS */

#if     !defined(YES) || ((YES) != 1)
#define YES 	(1)
#endif /* YES */
#if     !defined(NO) || ((NO) != 0)
#define NO      (0)
#endif /* NO */

#if     !defined(ON) || ((ON) != 1)
#define ON 	(1)
#endif /* ON */
#if     !defined(OFF) || ((OFF) != 0)
#define OFF      (0)
#endif /* OFF */

#if     !defined(TRUE) || ((TRUE) != 1)
#define TRUE    (1)
#endif /* TRUE */
#if     !defined(FALSE) || ((FALSE) != 0)
#define FALSE   (0)
#endif /* FALSE */

#endif /* stddef_ep_h */

