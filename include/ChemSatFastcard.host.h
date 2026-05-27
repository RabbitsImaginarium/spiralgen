/*
 * GE Medical Systems
 * Copyright (C) 1997-1998 The General Electric Company
 *  
 * $Source: ChemSatFastcard.host.h $
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

             GFN    08-Dec-1998   MRIge49315 - Added sync_length argument to
                                  ChemSat_FC_Eval().

             GFN    06-Apr-1999   Added ChemSat_FC_calcPulseParams().

 */

#ifndef ChemSatFastcard_host_h
#define ChemSatFastcard_host_h

/*
 * @host section
 */
STATUS create_chemsat_FC_pulses( PULSE_TABLE *pulse_table );
STATUS insert_rf_pulse_values( RF_PULSE *pulse, INT *pw, FLOAT *amp,
                               DOUBLE abswidth, DOUBLE effwidth, DOUBLE area,
                               DOUBLE dutycyc, DOUBLE maxpw, DOUBLE max_b1,
                               DOUBLE max_int_b1, DOUBLE max_rms, DOUBLE nom_fa,
                               FLOAT *act_fa, DOUBLE nom_pw, DOUBLE nom_bw,
                               UINT activity, INT num, UCHAR ref,
                               INT isodelay, DOUBLE scale, INT *res,
                               INT extflag );
STATUS ChemSat_FC_Init( PULSE_TABLE *pulse_table );
STATUS ChemSat_FC_rfinit( const INT cs_flag, const INT feature_flag );
STATUS ChemSat_FC_Init_pulse_fields( void );
STATUS ChemSat_FC_Eval( INT *cs_time, const INT board_index,
                        const INT cs_flag, const INT feature_flag,
                        const INT ermes_flag );
STATUS ChemSat_FC_setpulsenum( RF_PULSE *rfpulse, const INT Tmin_satoff,
                               INT *Tmin, const INT feature_flag );
STATUS ChemSat_FC_calcPulseParams( void );
STATUS ChemSat_FC_predownload( RF_PULSE *rfpulse,
                               ENTRY_POINT_TABLE *entryPoint,
                               const INT entry, const INT numPulses,
                               const INT actTR, const DOUBLE maxB1,
                               const INT feature_flag );
STATUS ChemSat_FC_IAmp( const INT cs_flag );
STATUS set_chemsat_fastcard_targets( PULSE_TABLE *pulse_table,
                                     const LOG_GRAD *loggrd,
                                     const INT ermes_flag );

#endif /* ChemSatFastcard_host_h */

