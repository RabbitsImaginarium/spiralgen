/*
 *  GE Medical Systems
 *  Copyright (C) 1997 The General Electric Company
 *  
 *  pulses.h
 *  
 *  Interface code for the pulses.c file.
 *  
 *  Language : ANSI C
 *  Author   : Gabriel Fernandez
 *  Date     : 20-Sep-997
 */
/* do not edit anything above this line */
/*
  Version    Author       Date         Comment
------------------------------------------------------------------------
    1.0       GFN      20-Sep-1997     Initial version

    1.1       GFN      25-Sep-1997     Removed unsafe datatypes. Changed
                                       FLOAT for DOUBLE. (FLOAT *) is safe.
 */

#ifndef pulses_h
#define pulses_h

#include <stddef_ep.h>

STATUS initialize_pulse_table(
#ifdef __STDC__
    PULSE_TABLE *ptable
#endif /* __STDC__ */
);
STATUS insert_rf_pulse(
#ifdef __STDC__
    INT insert_mode, PULSE_TABLE *pulse_table, INT *index, INT *pw, FLOAT *amp,
    DOUBLE abswidth, DOUBLE effwidth, DOUBLE area, DOUBLE dtycyc, DOUBLE maxpw,
    INT num, DOUBLE max_b1, DOUBLE max_int_b1, DOUBLE max_rms_b1, DOUBLE nom_fa,
    FLOAT *act_fa, DOUBLE nom_pw, DOUBLE nom_bw, UINT activity, UCHAR ref,
    INT isodelay, DOUBLE scale, INT *res, INT extgradf
#endif /* __STDC__ */
);
STATUS delete_rf_pulse_by_index(
#ifdef __STDC__
    PULSE_TABLE *pulse_table, INT index
#endif /* __STDC__ */
);
STATUS find_rf_pulse_by_index(
#ifdef __STDC__
    RF_PULSE **rfpulse, PULSE_TABLE *pulse_table, INT index
#endif /* __STDC__ */
);
STATUS delete_rf_pulse(
#ifdef __STDC__
    PULSE_TABLE *pulse_table, RF_PULSE *rfpulse
#endif /* __STDC__ */
);
STATUS form_rf_pulse_list(
#ifdef __STDC__
    PULSE_TABLE pulse_table, RF_PULSE *plist, INT *tot
#endif /* __STDC__ */
);
STATUS reset_rfpulses(
#ifdef __STDC__
    PULSE_TABLE *pulse_table
#endif /* __STDC__ */
);
STATUS insert_grad_pulse(
#ifdef __STDC__
    INT board, INT insert_mode, PULSE_TABLE *pulse_table, INT *index,
    INT ptype, INT *attack, INT *decay, INT *pw, FLOAT *amps, FLOAT *amp,
    FLOAT *ampd, FLOAT *ampe, DOUBLE power, INT num, DOUBLE scale,
    INT *time, INT tdelta, DOUBLE powscale, DOUBLE powpos, DOUBLE powneg,
    DOUBLE powabs, DOUBLE amptran, INT pwm, INT bridge, DOUBLE target
#endif /* __STDC__ */
);
STATUS delete_grad_pulse_by_index(
#ifdef __STDC__
    PULSE_TABLE *pulse_table, INT index, INT board
#endif /* __STDC__ */
);
STATUS find_grad_pulse_by_index(
#ifdef __STDC__
    GRAD_PULSE **gradpulse, PULSE_TABLE *pulse_table, INT index, INT board
#endif /* __STDC__ */
);
STATUS set_pulse_target(
#ifdef __STDC__
    PULSE_TABLE *pulse_table, INT index, DOUBLE target, INT board
#endif /* __STDC__ */
);
STATUS delete_grad_pulse(
#ifdef __STDC__
    PULSE_TABLE *pulse_table, GRAD_PULSE *gradpulse, INT board
#endif /* __STDC__ */
);
STATUS form_grad_pulse_list(
#ifdef __STDC__
    PULSE_TABLE pulse_table, INT board, GRAD_PULSE *plist, INT *tot
#endif /* __STDC__ */
);

#endif /* pulses_h */
