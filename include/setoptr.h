#ifndef setoptr_h
#define setoptr_h

#include <stddef_ep.h>

STATUS setoptr(
#ifdef __STDC__
    INT *actTR, INT *AvailImageTime, INT avminTR, INT flag
#endif /* __STDC__ */
);

#endif /* setoptr_h */
