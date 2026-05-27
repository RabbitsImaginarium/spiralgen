/*
 * GE Medical Systems
 * Copyright (C) 1997 The General Electric Company
 *
 * FastcardPC.host.h
 * 
 * Interface for FastcardPC.
 * 
 * Language : ANSI C
 * Author   : Pradeep S
 * Date     : 14 Oct 1998
 */
/* do not edit anything above this line */

/*
  Version   Author     Date       Comment
--------------------------------------------------------------
  CDP0.1     GFN    07-Jul-1997   Created file.

  CDP0.2     GFN    14-Aug-1997   Added Jason's performance enhancements.

  CDP0.3     GFN    25-Sep-1997   Removed unsafe datatypes from interface.

  CDP0.4     GFN    24-Oct-1997   Changed fastcardPC_resetscale() arguments
                                  from INT * to FLOAT *. BUG!

************************* Initial CV-1 Version ***********************

 sccs1.7     GFN    22-Dec-1997   Activated Maxwell PC additional arguments
                                  for fastcardPC_predownload.

 sccs1.8     GFN    19-Feb-1998   Removed prototype code for Fast CINE.
                                  Removed K&R declarations.

 sccs1.9     GFN    07-Mar-1998   Removed conditional code for
                                  Performance Enhancements.

 sccs1.10    GFN    24-Apr-1998   Removed unused arguments in
                                  fastcardPC_cvcheck().

 sccs1.12    GFN    18-May-1998   Changed Rsprot from 'INT *' to 'long *'.

             GFN    06-Apr-1999   Changed fastcardPC_set_amps() to
                                  fastcardPC_calcPulseParams().
                                  Removed unused arguments in
                                  fastcardPC_predownload().

 */

#ifndef FastcardPC_host_h
#define FastcardPC_host_h

/*
 * @host section
 */
STATUS fastcardPC_cvinit( PULSE_TABLE *pulse_table );
STATUS fastcardPC_cveval_init( INT *nevermind, INT flag );
STATUS fastcardPC_calcs( void );
STATUS amppwgypc( INT pwgy1, INT pwgy1a, INT pwgy1d, INT *pwgyfe1,
                  INT *pwgyfe1a, INT *pwgyfe1d, INT *pwgyfe2,
                  INT *pwgyfe2a, INT *pwgyfe2d, FLOAT *A_gyfe1,
                  FLOAT *A_gyfe2, INT *Yfe_time );
STATUS set_pc_fecho_lim( FLOAT *Fecho_lim );
STATUS calc_pc_fecho( INT *Xres, FLOAT *Fecho_lim, INT Opxres,
                     INT sequence_type, INT flag);
STATUS amppwgxzpc( INT *pwgxz1, INT *pwgxz1a, INT *pwgxz1d, INT *pwgxzfc,
                   INT *pwgxzfca, INT *pwgxzfcd, FLOAT *A_gxz1,
                   FLOAT *A_gxzfc, DOUBLE A_gxw_gzrf1, INT pwgxz_ad,
                   DOUBLE flow_wdth, DOUBLE gfctarget, INT pw_ramp,
                   INT opflaxa, FLOAT *A_gxz1u, FLOAT *A_gxz1d,
                   FLOAT *A_gxzfcu, FLOAT *A_gxzfcd, INT Dephase,
                   INT flow_comp );
STATUS mintefgrePC( INT *Minte, INT *Rd1a, INT *Rd1b, INT *tfeextra,
                    INT fullte, INT a_pwgxw, INT d_pwgxw, FLOAT *amp_gx1,
                    INT *a_pwgx1, INT *c_pwgx1, INT *d_pwgx1, FLOAT *amp_gxfc,
                    INT *a_pwgxfc, INT *c_pwgxfc, INT *d_pwgxfc, INT c_pwgxwl,
                    INT c_pwgxw, INT c_pwgxwr, DOUBLE amp_gxw, INT *c_pwgyfe1,
                    INT *a_pwgyfe1, INT *d_pwgyfe1, INT *c_pwgyfe2,
                    INT *a_pwgyfe2, INT *d_pwgyfe2, FLOAT *amp_gyfe1,
                    FLOAT *amp_gyfe2, INT *c_pwgz1, INT *a_pwgz1,
                    INT *d_pwgz1, INT *c_pwgzfc, INT *a_pwgzfc, INT *d_pwgzfc,
                    FLOAT *amp_gz1, FLOAT *amp_gzfc, INT d_pwgzrf1,
                    DOUBLE amp_gzrf1, INT T_exb, INT *pwgy1_tot,
                    INT *Yfe_time, INT c_pwgy1, INT a_pwgy1, INT d_pwgy1,
                    INT sequence_type, INT Flow_comp, INT flag );
STATUS fastcardPC_resetscale( INT flag, FLOAT *A_gx1, FLOAT *A_gxfc,
                              FLOAT *A_gz1, FLOAT *A_gzfc );
STATUS fastcardPC_scale_flow_grads( INT flag, FLOAT *A_gx1, FLOAT *A_gxfc,
                                    FLOAT *A_gz1, FLOAT *A_gzfc, DOUBLE A_gy1,
                                    DOUBLE A_gyfe );
STATUS fastcardPC_cvcheck( INT feature_flag, INT ermes_flag );
STATUS fastcardPC_set_recon_vars( void );
STATUS fastcardPC_calcPulseParams( INT *iamp_gz1, INT *iamp_gzfc,
                                   INT *iamp_gx1, INT *iamp_gxfc,
                                   const DOUBLE amp_gz1,
                                   const DOUBLE amp_gzfc,
                                   const DOUBLE amp_gx1,
                                   const DOUBLE amp_gxfc,
                                   const INT feature_flag );
STATUS fastcardPC_predownload( DOUBLE flowwdthx, DOUBLE flowwdthz,
                               INT Pw_gxwa, INT Pw_gzrf1d,
                               INT Pw_gx1, INT Pw_gx1a, INT Pw_gx1d,
                               INT Pw_gxfc, INT Pw_gxfca, INT Pw_gxfcd,
                               INT Pw_gz1a, INT Pw_gz1, INT Pw_gz1d,
                               INT Pw_gzfca, INT Pw_gzfcd, INT Pw_gzfc,
                               INT Pw_gy1a, INT Pw_gy1,INT Pw_gy1d,
                               INT Pw_gyfe1a, INT Pw_gyfe1, INT Pw_gyfe1d,
                               DOUBLE A_gxw, DOUBLE A_gzrf1, long *Rsprot,
                               INT feature_flag, INT ermes_flag );

#endif /* FastcardPC_host_h */

