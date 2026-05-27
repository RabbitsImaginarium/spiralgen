/*
 *  Echotrain.ipg.h
 *  
 *  Function prototypes for the Echotrain functions defined in Echotrain.e
 *  
 *  Language : ANSI C
 *  Author   : Pradeep S 
 *  Date     : 14-Oct-1998
 */
/* do not edit anything above this line */

/*
  Version   Author     Date       Comment
--------------------------------------------------------------

  sccs1.1    JAP    14-Jan-1998   Initial Revision.

  sccs1.2    JAP    12-Feb-1998   Fixed et_predownload prototype.

  sccs1.5    JAP    08-Apr-1998   Changed interface to match Echotrain.e

  sccs1.6    JAP    08-Apr-1998   Removed Oprbw from function
                                  call. Added prototypes for
                                  etmphcore, etmplcore, and etmpl_ref.

  sccs1.7    JAP    12-May-1998   Changed prototypes for et_cveval and
                                  et_predownload to support
                                  ramp-sampling.

  sccs1.8    FHE    21-Aug-1998   Added et_fcine_passviewtab.

  sccs1.10   FHE    09-Oct-1998   Modified et_pulsegen for offset phase fov.

             JFS    29-Oct-1998   Added prototype for etscancore and removed
                                  etmplcore and etmphcore. The prototypes for
                                  etmplcore and etmphcore were moved in Echotrain.e.

             AKG    26-Jun-1999   Added long rsprot[][9] to et_pulsegen function. 
                                  This is needed for accurate pgen_on_host calcs.

 */


/******************* IPG section *******************/

#ifndef Echotrain_ipg_h
#define Echotrain_ipg_h

STATUS et_psdinit(
#ifdef __STDC__
    int ia_Rf1,
    float flip_Rf1,
    int Act_tr, 
    int Dda,
    int Opslquant,
    const LOG_GRAD *Loggrd, 
    const PHYS_GRAD *Phyggrd, 
    int Pw_gyb, 
    int Pw_gyba, 
    float A_gxw,
    int Etl,
    int Fastrec,
    int f_flag
#endif
);


STATUS et_fcine_passviewtab(
#ifdef __STDC__
    int viewtabsize
#endif
);



STATUS et_pulsegen(
#ifdef __STDC__
    int f_flag,
    int Etl,
    int Fast_rec,
    int Slquant,
    int Tlead,
    double Tsp,
    int Dda,
    int Phaseres,
    double A_gxw,
    int Rhfrsize,
    int Spgr_flag,
    RSP_INFO *Rspinfo,
    long Rsprot[][9],   /* needed for pulsegen_on_host */
    int Yres,
    int Fov,
    float Phasefov
#endif
);

STATUS et_pulsegen2(
#ifdef __STDC__
    int f_flag,
    int Phaseres,
    const WF_PULSE *p_gz1fc, 
    const WF_PULSE *p_rf1, 
    const WF_PULSE *p_gx1fc, 
    const WF_PULSE *p_gy1, 
    const WF_PULSE *p_gxw, 
    const WF_PULSE *p_attenuator, 
    int Pw_gxwd, 
    int Etl, 
    const WF_PULSE *p_echotrain
#endif
);

STATUS ps2etcore(
#ifdef __STDC__
    INT numvus, 
    INT numnex
#endif
);


STATUS etscancore(
#ifdef __STDC__
    INT feature_flag
#endif
);


STATUS etmpl_ref(
#ifdef __STDC__
void
#endif
);

STATUS et_wait_for_ecg(
#ifdef __STDC__
    INT *sequence_count, INT psdindex
#endif /* __STDC__ */
);

STATUS et_setup_rf(
#ifdef __STDC__
void
#endif
);

#endif /* Echotrain_ipg_h */

