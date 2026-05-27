#ifndef error_message_h
#define error_message_h

#include <stddef_ep.h>

void error_message(
#ifdef __STDC__
    INT ermes, INT nos, CHAR *strs
#endif /* __STDC__ */
);

#endif /* error_message_h */
