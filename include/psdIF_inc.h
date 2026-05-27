/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  psdIF_inc.h
 *      Developer:  Dale Thayer
 *
 * $Source: psdIF_inc.h $
 * $Revision: 1.2 $  $Date: 7/24/98  19:11:31  $
 *
 *@Description
 *
 * This include typedefs for the prototype include file of the psdIF project.
 *
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
 sccs1.2      22-Jul-98    Dale Thayer
              Original for cardiac, CV1, conversion to ANSI C.

 *@End*************************************************************/

#ifndef  PSDIF_INC_H		/* we only want file included once */
#define  PSDIF_INC_H


/* typedefs needed for arguments in the prototypes */

/*--------------------------------------------------------------------------------
 *   Structure used to keep track of cv's attributes for comparison.
 *-------------------------------------------------------------------------------*/
typedef struct {
      _cvptr cv;
      int cvnum;
      int avmincvnum;
      int avmaxcvnum;
      int type;
} cvinfo;


typedef struct {
      double   val;
      unsigned int fixedflag:1, existflag:5, modifiedflag:1, visflag:2;
} save_cv;


#endif				/* end: if PSDIF_INC_H not defined */
