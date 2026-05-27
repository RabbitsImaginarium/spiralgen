/*
 *  CoreSelect.h
 *  
 *  Interface for CoreSelect.e
 *  
 *  Language : ANSI C
 *
 *	  Date	    Author	Comments
 * -----------------------------------------------------------
 *     28/Jul/1997  GFN         Initial version.
 */
/* do not edit anything above this line */

#ifndef CoreSelect_h
#define CoreSelect_h

#ifdef __STDC__

/*
 * @rsp section
 */
STATUS core_select( INT flag, INT rsp_slq, INT sldeltime, INT Phorder,
                    INT opfphases );
STATUS ps2core_select( INT flag, INT rsp_slq, INT MPS2_deadtime, INT Rspdda,
                       INT Rspvus, INT Rspnex );

#else /* __STDC__ */

/*
 * @rsp section
 */
STATUS core_select();
STATUS ps2core_select();

#endif /* __STDC__ */

#endif /* CoreSelect_h */

