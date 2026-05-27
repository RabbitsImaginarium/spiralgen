/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  Prep.ipg.h
 *      Developer:  Roshy J. Francis 
 *
 * Source: Prep.ipg.h
 * Creation date : 13-Oct-1998  
 *
 *@Description
 *
 * This file contains prototypes for functions defined in the ipg and RSP section
 * of Prep.e module
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

#ifndef Prep_ipg_h
#define Prep_ipg_h

/* from @pg  */
int prep_pulsegen( int Intsldelay, int time_ssi,
                   int num_scanlocs, int flag );

/* from @rsp */
STATUS prep_mror_update( INT flag, DOUBLE rxslthick, DOUBLE contslthick,
                         LOG_GRAD *lgrad, INT contdebug );
int  ps2prepcore( int  flag );
int  prepcore( int flag );
int  scanprep( int flag );
int  scanwait( void );
int  perfprep( void );


#endif /* Prep_ipg_h */

