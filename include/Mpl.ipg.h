/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  Mpl.ipg.h
 *      Developer:  Pradeep S.
 *
 * $Source: Mpl.ipg.h $
 * $Revision: 1.1 $  $Date: 8/12/98  13:45:30  $
 *
 *@Description
 *
 * Prototype file for the Mpl.e EPIC+ file.
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
 sccs1.1      11-Aug-98    Dale Thayer
              ANSI C corrections made to original ANSI Mpl_incl.h file.
              File was changed to Mpl.h name.

 *@End*************************************************************/

#ifndef  MPL_IPG_H                    /* we only want file included once */
#define  MPL_IPG_H



/* from @rsp section */

/* RTIA change */
STATUS mpl_get_seqtime( int actTR, int cssattime, int spsattime,
						int slquant_1, int sc_deadtime, int ps2_deadtime, 
						int flag );
STATUS mpl_satrotate( int flag );
STATUS mpl_settriggers( int flag );
STATUS mplcore( void );
STATUS ps2mplcore( int numvus, int rsp_nex );


#endif                                  /* end: if MPL_IPG_H not defined */


