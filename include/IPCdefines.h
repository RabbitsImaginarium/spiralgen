/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1989 The General Electric Company
 *
 *      Include File Name:  IPCdefines
 *      Developer:          B.L. Mazin
 *
 * $Source: IPCdefines.h $
 * $Revision: 1.6 $  $Date: 5/9/95 09:24:17 $
 */

/*@Synopsis
        IPC definitions and typedefs.
*/

/*@Description

*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  IPCdefine_INCL
#define  IPCdefine_INCL

#define SIGNAL YES
#define MGIPC_WAIT     1
#define MGIPC_NOWAIT   0

/******* OP Code **********/

#define MGIPC_ERROR   1
#define MGIPC_DATA    2
#define MGIPC_STATUS  3
#define MGIPC_CONNECT 4
#define MGIPC_READ    5
#define MGIPC_QCHECK  6

/********* Sub MSG Packet *******/

#define MGIPCMAX_IPC_BUFFER 2000

typedef struct {
   long severity;
   char buffer[MGIPCMAX_IPC_BUFFER-sizeof(long)];
} ERROR_FIELD;

typedef struct {
   long data_type;
   char buffer[MGIPCMAX_IPC_BUFFER-sizeof(long)];
} DATA_FIELD;

typedef struct {
   STATUS status;
} STATUS_FIELD;

typedef struct {
   char buffer[MGIPCMAX_IPC_BUFFER];
} READ_FIELD;



/**** MSG PACKET STRUCTURE *****/
typedef struct {

   long mtype;
   long  opcode;
   long  rcvr;
   long  sender;
   int  size;

   union {
      ERROR_FIELD  err;
      DATA_FIELD   data;
      STATUS_FIELD cc;
      READ_FIELD   read;
   } field;

} MGIPC_MSG_PACKET;

/* size of "mtype, opcode, rcvr, sender" in the MSG_PACKET */
/*   Data field is the largest union type                  */
#define MGIPCMSG_HEADER_SIZE (sizeof(MGIPC_MSG_PACKET) - sizeof(DATA_FIELD))

#endif
