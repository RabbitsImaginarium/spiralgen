/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1998 The General Electric Company
 *
 *      File Name:  epic_error.h
 *      Developer:  Pradeep S.
 *
 * $Source: epic_error.h $
 * $Revision: 1.2 $  $Date: 8/24/98  17:20:00  $
 *
 *@Description
 *
 * A prototype include file for just epic_error.c.  (NOTE: This routine
 * is included in the prototype file for the psdIF project. Because 
 * epic_error is used by itself so much, we gave it a separate protoype 
 * file.  Epic_nerror and epic_serror were not prototyped separately 
 * because they should not be used any more for ease of internationalization.)
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
 sccs1.2      24-Aug-98    Dale Thayer
              Newer version with disclaimer about separate prototype.

 sccs1.4      6-Oct-98     Dale Thayer
              Made four static arguments for epic_error call.

              18-Nov-1998  GFN
              Made all arguments constant.

 *@End*************************************************************/

#ifndef  epic_error_h
#define  epic_error_h

/* from epic_error.c */
void epic_error( const int ermes, const char *plain_fmt, const int ermes_num,
                 const int num_args, ... );

#endif /* epic_error_h */

