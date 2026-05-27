/*
 *	GE Medical Systems
 *	Copyright (C) 1998- The General Electric Company
 *  Filename : Hard180.h
 *
 *  This file contains the prototype declarations for the 
 *  functions defined in Hard180.e.
 *
 *  Author   : Roshy J. Francis.
 *  Date     : 16-Sep-1998
 */
/* do not edit anything above this line */

/* Revision Information */
/*
Author     Date       			Comment
----------------------------------------------------------------------
RJF		   16/Sep/98			Initial version.
RJF		   18/Oct/98		  	Created Hard180.ipg.h as the interface
								for ipg and RSP functions defined in 
								Hard180.e
									
											
*/

#ifndef Hard180_ipg_h 
#define Hard180_ipg_h 

STATUS Hard180PG (int featureflag, int hard180time);
STATUS PlayHard180 (INT psdindex);
STATUS offset_to_seqhard180 (void);

#endif
