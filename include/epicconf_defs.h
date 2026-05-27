/*
 *  epicconf_defs.h
 *  
 *  This file contains the macro definitions used by EpicConf.c 
 *  
 *
 *  Language : EPIC/ANSI C
 *  Author   : Roshy J. Francis / Pradeep.S 
 *  Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

/*
   Version    Author     Date       Comment
----------------------------------------------------------------------
 /main/mr_main/1 RJF	 15/Oct/1998	Initial version.
										This file is used only by EpicConf.c
 */

#ifndef epicconf_defs_h 
#define epicconf_defs_h 

#define RFFREQ_LENGTH_MAX 14      /* spectro:14, cerd:14 */
#define RFUNBLANK_LENGTH_MAX 4    /* spectro:4,  cerd:4  */
#define DAB_LENGTH_MAX 16         /* spectro:15, cerd:16 */
#define XTR_LENGTH_MAX 16         /* spectro:15, cerd:16 */
#define RBA_LENGTH_MAX 12         /* spectro:12, cerd:4  */
#define SQ_SYNC_LENGTH_MAX 13     /* spectro:13, cerd:8  */
#define ATTEN_UNLOCK_LENGTH_MAX 6 /* spectro:6 , cerd:6  */


#endif /* epicconf_defs_h */ 

