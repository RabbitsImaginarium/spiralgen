/*
 * GE Medical Systems
 * Copyright (C) 1995-1998 The General Electric Company
 * 
 * $Source: IPCroutines.h $
 * $Revision: 1.8 $  $Date: 5/14/98 21:04:13 $
 * 
 * Interface for the IPC routines.
 * 
 * Language : ANSI C
 * Author   : B. L. Mazin
 * Date     : 09/May/1995
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
           07/May/1998  GFN         Converted to ANSI.
 */

#ifndef IPCroutines_h
#define IPCroutines_h

void IPC_Cleanup( void );
STATUS IPC_QCheck( int own_id, long *status );
STATUS IPC_Init( int task_no, int *ipc_own_id, long *status );
STATUS IPC_Receive( ADDRESS data_packet, int *size_of_data, long from_id,
                    size_t max_data_size, long *status );
STATUS IPC_Send( ADDRESS data_packet, size_t size_of_data, int ipc_own_id,
                 int ipc_sendto_id, long signal_flag, long *status );
STATUS IPCMsgHndlr(
#if defined(__STDC__) && (__STDC__ != 0)
    int info, ...
#endif /* __STDC__ */
);

#endif /* IPCroutines_h */
