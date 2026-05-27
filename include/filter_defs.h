/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1990 The General Electric Company
 *
 *      Include File Name:  @filter@
 *      Developer: 
 *
 * $Source: filter_defs.h $
 * $Revision: 1.6 $  $Date: 10/31/93 10:41:53 $
 */


/*@Synopsis 
	Acquistion Filters.
*/     

/*@Description

***************************************************************
   Author	Date		Comment
-------------------------------------------------------
   WFB		12/14/90	Added 512 output filters.

   KMC          02/19/91        Took out FILTER_INFO structure
                                definition.  This is now in
				epic.h

   MGH          06/25/92        Change f32 to f320 to accomodate 
                                GEtypes.h in 5.3.

   JDM          08/30/94        Split file into defines and 
                                structure portions of original
                                filter.h - this is the defines
                                part.

   GFN          08/13/97        Added PSD_TSP_CERD and PSD_CERD_BW
                                for 125KHz bandwith.
                                
*/

/* only do this once in any given compilation.*/
#ifndef  filter_defs_h
#define  filter_defs_h

#define PSD_TSP 		8
#define PSD_TPS_BW             62.5

#define PSD_TSP_CERD            4
#define PSD_CERD_BW           125.0

#define F625DECIMATION	        1
#define F32DECIMATION           2
#define F208DECIMATION          3
#define F16DECIMATION	        4
#define F128DECIMATION          5
#define F104DECIMATION	        6
#define F8DECIMATION            8
#define F4DECIMATION           16
#define F2DECIMATION           32
#define F500DECIMATION        128
#define F16_SLOT                1
#define F2_SLOT                 2
#define F500_SLOT               3
#define FOPT_SLOT               4

#endif /* filter_defs_h */


