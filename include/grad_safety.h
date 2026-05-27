/*
 *  GE Medical Systems
 *  Copyright (C) 1997 The General Electric Company
 *  
 *  grad_safety.h
 *  
 *  Interface code for the functions defines in grad_safety.e.
 *  
 *  Language : ANSI C
 *  Author   : Gabriel Fernandez
 *  Date     : 22-Sep-1997
 */
/* do not edit anything above this line */

#ifndef grad_safety_h
#define grad_safety_h

/*
 *  @host section
 */
STATUS
init_powscale(
#ifdef __STDC__
    INT srmode, INT plane, PULSE_TABLE *pulse_table, LOG_GRAD *log_grad
#endif /* __STDC__ */
);
STATUS
init_grad_safe_times(
#ifdef __STDC__
    INT *tcoil, INT *txgrd, INT *tygrd, INT *tzgrd, INT *tgram, INT *tgpm
#endif /* __STDC__ */
);

#endif /* grad_safety_h */

