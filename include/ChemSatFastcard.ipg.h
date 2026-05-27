/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: ChemSatFastcard.ipg.h $
 * $Revision: 1.8 $  $Date: 4/25/98 01:08:22 $
 *  
 * Interface for ChemSatFastcard routines in ChemSatFastcard.e.
 *  
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

/*
  Version   Author     Date       Comment
--------------------------------------------------------------
  CDP-0      GFN    25-Sep-1997   Removed unsafe datatypes from interface.

  sccs1.7    GFN    20-Feb-1998   Removed K&R code.

  sccs1.8    GFN    24-Apr-1998   Added ermes flag to ChemSat_FC_Eval() and
                                  set_chemsat_fastcard_targets().
 */

#ifndef ChemSatFastcard_ipg_h
#define ChemSatFastcard_ipg_h

/*
 * @rsp section
 */
STATUS ChemSatResetScope_fc( void );
STATUS ChemSatSync_fc( void );
STATUS set_cssat1_params( void );
STATUS set_first_rfcssat1( void );
STATUS set_normal_rfcssat1( void );
/*
 * @pg section
 */
STATUS ChemSat_FC_PG( INT start_time, INT cs_sat_time );

#endif /* ChemSatFastcard_ipg_h */


