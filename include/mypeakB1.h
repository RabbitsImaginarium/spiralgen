#ifndef mypeakB1_h
#define mypeakB1_h

#include <stddef_ep.h>

STATUS mypeakB1(
#ifdef __STDC__
    FLOAT *maxB1Val, INT entryPoint, INT numPulseEntries, INT *err_pulse, RF_PULSE *rfPulse
#endif /* __STDC__ */
);

#endif /* mypeakB1_h */
