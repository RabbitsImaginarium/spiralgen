/*
 *  GE Medical Systems
 *  Copyright (C) 1997 The General Electric Company
 *  
 *  rf_safety.h
 *  
 *  Interface code for the functions in rf_safety.e.
 *  
 *  Language : ANSI C
 *  Author   : Gabriel Fernandez
 *  Date     : 20-Sep-1997
 */
/* do not edit anything above this line */

#ifndef rf_safety_h
#define rf_safety_h

/*
 *  @host section
 */
STATUS
initialize_rfpulseInfo(
#ifdef __STDC__
    INT num_rf, RF_PULSE_INFO *rfinfo
#endif /* __STDC__ */
);
STATUS
scale_rfpulses(
#ifdef __STDC__
    INT max_pts, PULSE_TABLE *pulse_table, RF_PULSE *rflist,
    FLOAT opwt, INT cfgcoil, RF_PULSE_INFO *rfinfo
#endif /* __STDC__ */
);

/*
 *  @pg section
 */
STATUS
stretch_pulse(
#ifdef __STDC__
    INT slot, CHAR *extname, RF_PULSE_INFO *rfInfo,
    INT *res, SHORT **wavespace
#endif /* __STDC__ */
);

#endif /* rf_safety_h */

