/* added active field to grad and rf list structures, per
   MRIge31377 fix involving rewrite of routines in pulses.c */

/*
   GFN  19-Sep-1997  Changed all datatypes to be consistent with the ones
                     in stddef_ep.h.

   GFN  27-Sep-1997  Added #ifndef block to avoid multiple inclusions.
 */

#ifndef pulse_structs_h
#define pulse_structs_h

#include <stddef_ep.h>

typedef struct GRAD_LIST_STRUCT {
  INT index;
  FLOAT target;
  INT active;
  GRAD_PULSE *gradpulse;
  struct GRAD_LIST_STRUCT *next;
  struct GRAD_LIST_STRUCT *prev;
} GRAD_LIST;

typedef struct RF_LIST_STRUCT {
  INT index;
  INT active;
  RF_PULSE *rfpulse;
  struct RF_LIST_STRUCT *next;
  struct RF_LIST_STRUCT *prev;
} RF_LIST;

typedef struct {
  GRAD_LIST *gradx;
  GRAD_LIST *xtop;
  INT xnum;
  GRAD_LIST *grady;
  GRAD_LIST *ytop;
  INT ynum;
  GRAD_LIST *gradz;
  GRAD_LIST *ztop;
  INT znum;
  RF_LIST *rflist;
  RF_LIST *rftop;
  INT rfnum;
} PULSE_TABLE;

#endif /* pulse_structs_h */

