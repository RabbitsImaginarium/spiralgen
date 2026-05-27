/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1995-1998 The General Electric Company
 *
 *      File Name:  psd_proto.h
 *      Developer:  Dale Thayer
 *
 * $Source: psd_proto.h $
 * $Revision: 1.2 $  $Date: 6/18/98  15:31:50  $
 *
 *@Description
 *
 * This is the prototype description file for PSD's.
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version      Date         Author
              Description
 ------------------------------------------------------------------
 sccs1.2      18-Jun-98    Dale Thayer
              Original for cardiac, CV1, conversion to ANSI C.

              02-Apr-1999  Jason Polzin, Gabriel Fernandez
                           Updated to add calcPulseParams() and remove 
                           private functions within the PSDs.

 *@End*************************************************************/

#ifndef psd_proto_h
#define psd_proto_h

STATUS aps1(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS aps2(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS autoshim(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS cfh(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS cfl(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS cvcheck(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);

STATUS cveval(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);

STATUS cvinit(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS fasttg(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS mps1(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);

STATUS mps2(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);

STATUS predownload(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS pulsegen(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS scan(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);

STATUS scanloop(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS calcPulseParams(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

STATUS psdinit(
#ifdef __STDC__
     void
#endif /* __STDC__ */
);

#endif /* psd_proto_h */

