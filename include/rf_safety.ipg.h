/*
 *  GE Medical Systems
 *  Copyright (C) 1997 The General Electric Company
 *  
 *  rf_safety.ipg.h
 *  
 *  Interface code for the functions in rf_safety.e.
 *  
 *  Language : ANSI C
 *  Author   : Pradeep S 
 *  Date     : 20-Sep-1997
 */
/* do not edit anything above this line */

#ifndef rf_safety_ipg_h
#define rf_safety_ipg_h

/*
 *  @rsp section
 */


STATUS
stretch_pulse(
#ifdef __STDC__
    INT slot, CHAR *extname, RF_PULSE_INFO rfInfo[MAX_NUM_PULSES_PER_BOARD],
    INT *res, SHORT **wavespace
#endif /* __STDC__ */
);

#endif /* rf_safety_ipg_h */


