/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: ChemSatModule.host.h   $
 * $Revision: 1.1 $  $Date: 4/25/98 01:26:43 $
 *  
 * Interface for the ChemSatModule.e file.
 *  
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

#ifndef ChemSatModule_host_h
#define ChemSatModule_host_h

/*
 * @host section
 */
STATUS ChemSat_Init( PULSE_TABLE *pulse_table );
STATUS ChemSat_rfinit( const INT cs_flag, const INT flag );
STATUS ChemSat_Eval( INT *cs_time, const INT cs_flag,
                     const INT board_index, const INT f_flag,
                     const INT e_flag );
STATUS ChemSat_Check( INT f_flag );
STATUS ChemSat_IAmp( const INT cs_flag, const INT f_flag );


#endif /* ChemSatModule_host_h */


