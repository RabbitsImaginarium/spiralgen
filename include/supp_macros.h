/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1989 The General Electric Company
 *
 *	Include File Name:  supp_macros   
 *	Developer:
 *
 * $Source: supp_macros.h $
 * $Revision: 1.4 $  $Date: 11/29/89 13:22:45 $
 */

/*@Synopsis 
*/     

/*@Description
     
*/
/* *********************************************************
	Author		Date		Comments
-------------------------------------------------------------
	WFB		9/28/90		Added macros for gradient,
					rf roundup times.

        GFN           09/20/1997        Changed datypes to be consistent
                                        with stddef_ep.h.
                                        Added check to avoid multiple
                                        definitions of RUP_* and RDN_*
                                        macros. They are also defined in
                                        epic.h.

 ******************************************************* */

/* only do this once in any given compilation.*/
#ifndef  supp_macros_h
#define  supp_macros_h

#define MAX(A, B) 		(((A) > (B)) ? (A) : (B))
#define MIN(A, B) 		(((A) < (B)) ? (A) : (B))
#define ABSOLUTE(A) 	(((A) >  0 ) ? (A) : -(A)) 
#define ROUND(A)		(LONG)(((A) + 500) / 1000) * 1000 
#define ROUND_DOWN(A)	(LONG)((A) / 1000) * 1000
#define ROUND_UP(A)		(LONG)(((A) + 999) / 1000) * 1000

/* Macros for rounding up or down to a gradient or RF boundary */
/* These macros are also defined in epic.h. Let's check for multiple
   definitions. */
#ifndef RUP_GRD
#define RUP_GRD(A)  (((A)%GRAD_UPDATE_TIME) ? (INT)((A) + GRAD_UPDATE_TIME) & ~(GRAD_UPDATE_TIME - 1) : (A))
#endif /* RUP_GRD */

#ifndef RDN_GRD
#define RDN_GRD(A)  ((INT)(A) & ~(GRAD_UPDATE_TIME -1))
#endif /* RDN_GRD */

#ifndef RUP_RF
#define RUP_RF(A)  (((A)%RF_UPDATE_TIME) ? (INT)((A) + RF_UPDATE_TIME) & ~(RF_UPDATE_TIME - 1) : (A))
#endif /* RUP_RF */

#ifndef RDN_RF
#define RDN_RF(A)  ((INT)(A) & ~(RF_UPDATE_TIME -1))
#endif /* RDN_RF */


/* ERROR HANDLING, for psd_supportlib.a routines */
/* #define DEBUG */

#endif /* supp_macros_h */
