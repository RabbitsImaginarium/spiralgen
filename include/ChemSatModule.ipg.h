/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: ChemSatModule.ipg.h $
 * $Revision: 1.1 $  $Date: 4/25/98 01:26:43 $
 *  
 * Interface for the ChemSatModule.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

#ifndef ChemSatModule_ipg_h
#define ChemSatModule_ipg_h

/*
 * @pg section
 */
STATUS ChemSat_PG( INT start_time, INT cssattime, INT *cssatindex, INT *cstune,
                   INT f_flag );

/*
 * @rsp section
 */
STATUS ChemSat_Reset_Scope( INT f_flag );
STATUS ChemSat_Sync( INT flag );

#endif /* ChemSatModule_ipg_h */
