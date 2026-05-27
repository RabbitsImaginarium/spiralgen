/*
 *  Echotrain.host.h
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
  sccs1.11   FHE    19-Oct-1998   Modified et_cvcheck for vps,etl,yres check.

             AKG    04-Feb-1999   Added prototype for et_setacqparams which bumps avmintr if it is 
                                  less than CERD processing time limit
             AKG    12-march-1999 changed "int pwgxgap" argument of et_cvcheck to "int * pwgxgapp"
                                  for MRIge51740 CERD limits

             GFN    06-Apr-1999   Added et_calcPulseParams().
      
             AKG    26-Oct-1999   MRIge55679 added set_Echotrian_times
                                  to check avminti > 10ms for ET.
             AKG    05-Nov-1999   Added TR_PASS_p to et_cveval_init parameters.
             AKG    09-Mar-2000   Added ET_MAX_SLICES definition.
                                  Added ETA_TIME_PER_SLICE definition in usecs.
 */

#ifndef Echotrain_host_h
#define Echotrain_host_h

/******************* Host section *******************/

#define ET_MAX_SLICES 64
#define ETA_TIME_PER_SLICE 260000.0

STATUS et_cvinit(
#ifdef __STDC__
    int *pwgxwl, 
    int *pwgxwr, 
    int *pwgxgap,
    const int *pwgyba, 
    const int *pwgybd, 
    const int *pwgyb, 
    const float *agyb, 
    const GRAD_PULSE *Gxw_pulse,
    PULSE_TABLE *Pulse_table
#endif
);

STATUS et_cveval_init(
#ifdef __STDC__
    int *Etl, 
    int *Dda, 
    int *Gxwexon,
    int *Fast_pass,
    int *Short_rf,
    int *Read_shift,
    int *TR_PASS_p,
    int flag
#endif
);


STATUS et_cveval(
#ifdef __STDC__
    float Fov, 
    int *Xres,
    int Yres,
    int Etl,
    int Fastrec,
    int no_coils,
    GRAD_PULSE *Gxw_pulse,
    float Tsp, 
    int *pwgxgapp,
    int Read_shift,
    int *xtroffset,
    int *Vps, 
    int *pwgxwl, 
    int *pwgxwr,
    int *pwgxwad, 
    int *p_gxktime,
    int *Dacq_offset, 
    int *Rspqueue_size,
    int *Time_ssi,
    int *p_etssptime,
    int *p_rs_offset,
    int f_flag
#endif
);

STATUS set_echotrain_targets(
#ifdef __STDC__
    PULSE_TABLE *pulse_table, 
    const LOG_GRAD *p_loggrd,
    FLOAT Gxwtarget
#endif
);


STATUS et_grad_calc(
#ifdef __STDC__
    int f_flag,
    int Etl, 
    int Fcomp,
    int t_ex2rd,
    int Read_shift,
    int Grdrs_offset,
    GRAD_PULSE *Gzrf1_pulse, 
    GRAD_PULSE *Gzfc_pulse, 
    GRAD_PULSE *Gz1_pulse, 
    GRAD_PULSE *Gx1_pulse,
    GRAD_PULSE *Gxfc_pulse, 
    GRAD_PULSE *Gxw_pulse,
    GRAD_PULSE *Gy1_pulse, 
    GRAD_PULSE *Gy1r_pulse, 
    GRAD_PULSE *Gzk_pulse
#endif
);


STATUS et_calcPulseParams(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);


STATUS et_predownload(
#ifdef __STDC__
    int f_flag,
    int Etl,
    int Opcoil,
    int Fast_rec,
    float Tsp,
    int Opfov,
    int Opxres,
    int Phaseres,
    int Frsize,
    int Et_ia_gyb,
    long Rsprot[][9], 
    int Num_entries,
    PSD_FILTER_GEN *p_scanslot
#endif
);


STATUS et_cvcheck(
#ifdef __STDC__
    int Fullte_flag,
    int Etl, 
    float Opnex,
    int Oppseq,
    int Opsat,
    int Yres,
    int Vps,
    int f_flag
#endif
);


STATUS et_setacqparams(
#ifdef __STDC__
    INT *avmintr, 
    INT fftsize, 
    INT etl, 
    INT nocoils,  
    INT cerdinpoints 
#endif
); 

STATUS set_Echotrain_times( 
#ifdef __STDC__
    INT *pitslicep, 
    INT opslquantET,
    DOUBLE tr,
    INT *reps,
    INT Dda,
    INT Dex,
    INT Baseline,
    INT pass_time,
    INT ccsrelax_time,
    DOUBLE extraTime,
    INT Acqs,
    DOUBLE Truenex,
    INT sat_times,
    INT tseqPrep,
    INT Etl,
    FLOAT *avmintscanET, 
    INT f_flag
#endif
);

#endif /* Echotrain_host_h */


