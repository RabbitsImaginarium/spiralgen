/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: Prescan+.host.h $
 * $Revision: 1.1 $  $Date: 6/24/98 17:36:05 $
 * 
 * Language : ANSI C
 * Author   : Pradeep S.
 * Date     : 14/Oct/98
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------
/main/mr_main/2 10/20/98  VB        changed definition of maxB1 and
                                    maxB1seq to FLOAT from DOUBLE.

 */


#ifndef Prescan_plus_host_h
#define Prescan_plus_host_h

/*
 * @host section
 */

STATUS prescan_cvinit(PULSE_TABLE *pulse_table,INT  flag);
STATUS prescan_cveval(void);
STATUS prescan_predownload(RF_PULSE *rfpulse_list,INT  RF_FREE, FLOAT maxB1[],FLOAT  maxB1Seq);
STATUS create_prescan_pulses( PULSE_TABLE *pulse_table);
STATUS PScvinit(INT flag);
STATUS FTGcvinit(void);
STATUS AScvinit(void);
STATUS AScveval(void);
STATUS PScveval(void);
STATUS FTGcveval(void);
STATUS PSfilter( INT num_filter_slots);
STATUS PSpredownload(RF_PULSE *rfpulse_list,INT  RF_FREE, FLOAT maxB1[], FLOAT  maxB1Seq);
STATUS FTGpredownload(RF_PULSE *rfpulse_list, INT RF_FREE,FLOAT maxB1[], FLOAT  maxB1Seq);
STATUS ASpredownload(RF_PULSE *rfpulse_list,INT  RF_FREE,FLOAT maxB1[],FLOAT  maxB1Seq);

#endif  /*  Prescan_plus_host_h */

