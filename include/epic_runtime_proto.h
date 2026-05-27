/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  epic_runtime_proto.h
 *      Developer:  Dale Thayer
 *
 * $Source: epic_runtime_proto.h $
 * $Revision: 1.2 $  $Date: 7/23/98  20:04:55  $
 *
 *@Description
 *
 * This is the prototype include file for the epic_runtime project.
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
 sccs1.2      23-Jul-98    Dale Thayer
              Original for cardiac, CV1, conversion to ANSI C.

 *@End*************************************************************/

#ifndef   EPIC_RUNTIME_PROTO_H		/* we only want file included once */
#define   EPIC_RUNTIME_PROTO_H

/* from epic_cm.c */
void epic_queue_init( int sendkey, int reckey );
void epic_send( int opcode, cmd_pkt *pkt, int nbytes, int destid, int srcid );
int  epic_rec( data_pkt *pkt, int recid );
void epic_reply( data_pkt *out_pkt, cmd_pkt *in_pkt, int nbytes, int more );
void epic_unblock( int blocked_id, int noresponse_id );
int  epic_queue_clear( void );
void epic_remove_queue( void );


#endif				/* end: if EPIC_RUNTIME_PROTO_H not defined */


