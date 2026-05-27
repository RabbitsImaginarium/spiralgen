/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: ChemSat+.ipg.h $
 * $Revision: 1.1 $  $Date: 4/25/98 01:26:45 $
 *  
 * Interface for the ChemSat+.e file.
 *  
 * Language : ANSI C/EPIC+
 * Author   : Pradeep S 
 * Date     : 14/Oct/1998
 */
/* do not edit anything above this line */

#ifndef ChemSat_plus_ipg_h
#define ChemSat_plus_ipg_h

/*
 * @pg section
 */
STATUS ChemSatPG( INT chemsat_start, INT *cssat_index, INT *cstune );

/*
 * @rsp section
 */
STATUS CScfh( INT cs_sat );
STATUS ChemSatResetScope( void );
STATUS ChemSatSync( void );
STATUS CsSatMod( INT num_chemsats, INT cs_flag, INT cstun );
STATUS CsSatPrep( INT num_chemsats, INT psdindex, INT exciter_phase,
                  INT cs_flag );
STATUS CsSatPrepFast( INT psdindex, INT exciter_phase, INT cs_flag );
STATUS CsSatChopKiller( INT num_chemsats, INT cs_flag, INT cstun );
STATUS ChemSatPhase( INT exphase, INT index );
STATUS ChemSatAmp( INT amplitude, INT index );
#endif /* ChemSat_plus_ipg_h */
