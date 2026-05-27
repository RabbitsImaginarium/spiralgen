/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * Interface for the printDebug.c file.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 05/Feb/1999
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
  1.0      05-Feb-1999  GFN         Initial version.
 */

#ifndef printDebug_h
#define printDebug_h

typedef enum dbLevel_e {
    NODEBUG = 0,
    DBLEVEL1,
    DBLEVEL2,
    DBLEVEL3,
    DBLEVEL4,
    DBLEVEL5,
    DBLEVEL6,
    DBLEVEL7,
    DBLEVEL8,
    DBLEVEL9,
    DBLEVEL10
} dbLevel_t;

void printDebug( const dbLevel_t level, const dbLevel_t dbLevel,
                 const CHAR *functionName, const CHAR *format, ... );

#endif /* printDebug_h */

