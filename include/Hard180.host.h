/*
 *	GE Medical Systems
 *	Copyright (C) 1998- The General Electric Company
 *  Filename : Hard180.h
 *
 *  
 *  Interface file for Hard180.e 
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
RJF		   18/Oct/98			Split into host and ipg sections to be 
								consistent with the new EPIC+ include
								file reorganization.
											
*/

#ifndef Hard180_host_h 
#define Hard180_host_h 

STATUS Hard180_cvinit (PULSE_TABLE *pulse_table);
STATUS Hard180_eval (int *hard180_time, 
					 INT feature_flag);
STATUS Hard180_predownload (INT feature_flag, RF_PULSE *rfpulse);
STATUS deactivate_ir_pulses (RF_PULSE *rfpulselist, 
							 int use_flowcomp_list);
STATUS activate_ir_pulses (RF_PULSE *rfpulselist, 
						   int use_flowcomp_list);

STATUS RTIA_scale_hard180B1 ( RF_PULSE *rfpulse, float scale );

#endif
