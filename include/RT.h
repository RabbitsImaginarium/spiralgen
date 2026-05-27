/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: RT.h $
 * $Revision: 1.2 $  $Date: 5/7/98 13:16:58 $
 * 
 * Interface file for RT.e.
 * 
 * Language : ANSI C
 * Author   : Gabriel Fernandez
 * Date     : 07/May/1998
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.1   07/May/1998  GFN         Initial version.
 */

#ifndef RT_h
#define RT_h

STATUS RT_pginit( void );
STATUS RTUpdate( void );
STATUS RTPrescanUpdate( void );

#endif /* RT_h */

