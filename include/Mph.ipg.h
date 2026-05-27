/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  Mph.ipg.h
 *      Developer:  Roshy J. Francis 
 *
 * Source: Mph.ipg.h
 * Creation date : 13-Oct-1998  
 *
 *@Description
 *
 * This file contains prototypes for functions defined in the ipg and RSP section
 * of Mph.e module
 *
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version      		Date         Author
              		Description
 ------------------------------------------------------------------
 /main/mr_main/1	13-Oct-1998	Roshy Francis 
					Initial version	
 *@End*************************************************************/

#ifndef  MPH_IPG_H /* we only want file included once */
#define  MPH_IPG_H

/*  from @pg section */
int mph_long_delay( int sl_deltime, int flag );
int mph_passtime( int *passtime, int sl_deltime, int flag );
int mph_pass_ptrs( int flag, short *slice_in_acq, short *acq_pointer, 
                   int pass_index );

/* from @rsp section */
int scandelay1( void );




#endif    
