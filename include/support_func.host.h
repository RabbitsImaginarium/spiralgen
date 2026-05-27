/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 *  
 * $Source: support_func.host.h $
 * $Revision: 1.35 $  $Date: 5/18/98 20:31:57 $
 *  
 * Function Prototypes for psdsupport functions.
 *  
 * If you add a new support function make sure you add a new prototype.
 *
 * Language : ANSI C
 * Author   : Pradeep S 
 * Date     : 14 Oct 1998
 */
/* do not edit anything above this line */

/*
 Version       Date      Author      Description
------------------------------------------------------------------------------
 sccs 1.16  13/Nov/1997  Dale Thayer Added diffcvs() to list.
 
 sccs 1.27  16/Dec/1997  GFN         Initial CV-1 version. Merged with Lx-2.

 sccs 1.33  27/Apr/1998  BJM         Added MaxAcq to slicesort delcaration.

 sccs 1.34  18/May/1998  GFN         Changed type of rotation matrix args
                                     to long.

 sccs 1.37  22/June/1998 AKG         MRIge46303 changed LOG_GRAD structure 
                                     argument(Loggrad) to a pointer to 
                                     LOG_GRAD struct(Loggradp)

 sccs 1.38  05/Aug/1998  BJM         Add xtr_pkt_off to getfiltparams interface
                                     for EPI.

 sccs 1.39  15/Jul/1998  GFN         Added tsamp argument to minseqseg().

 sccs 1.40  14/Aug/1998  GFN         Added more arguments to minseqseg() used
                                     for coil heating calculations. Made
                                     LOG_GRAD argument in minseqgrad() constant.

            13/Oct/1998  GFN         Added minseq() and setGradCalcMethod()
                                     functions as interface for the gradient
                                     and coil heating routines.

            14/Oct/1998  GFN         Updated prototype for minseqseg().

            18/Nov/1998  GFN         Updated prototype for setScale().

            09/Feb/1999  GFN         Updated interface for minseq(). Added
                                     getCornerPoints() and applyRotMatrices().

            04/19/99     SGT         Changed the prototype definition of the
                                     support routine prescanslice1().

                                     Changed the prototype definition of the
                                     support routine orderslice2().

            07/Jun/1999  GFN         Added updateIndex().

            03/Aug/1999  BJM         Added FLOAT *reftime to epiRecvFrqPhs()

            18/Aug/1999  RJF         Added calcOptimizedPulses().

            03/Mar/2000  BJM         Updated calcOptimizedPulses() argument list

 */

/* Only do this once in any given compilation */
#ifndef  support_func_host_h
#define  support_func_host_h

#include <stddef_ep.h>
#include <printDebug.h>

#ifdef __STDC__

STATUS OpenDelayFile(

    FLOAT *buffer

);
STATUS OpenDitherFile(

    INT coiltype, FLOAT *buffer

);
STATUS OpenDitherInterpoFile(

    INT coiltype, FLOAT *ccinx, FLOAT *cciny, FLOAT *ccinz, INT *esp_in,
    FLOAT *fesp_in, FLOAT *g0, INT *num_elements, INT *exist

);

STATUS advroundup(

    INT *adv_panel_value

);
STATUS advrounddown(

    INT *adv_panel_value

);
STATUS altrfgen(

    INT gentypflag, INT resolution, SHORT *kernel, DOUBLE cycles,
    DOUBLE slice_offset, DOUBLE slice_mod_fact, SHORT *phase_kernel,
    DOUBLE start_phase, SHORT *result_wave, DOUBLE freq_step

);
STATUS ampfov(

    FLOAT *Ampfov, DOUBLE readout_filter, DOUBLE fov

);
STATUS amppwcombpe(

    DOUBLE a_start, DOUBLE area_const, DOUBLE area_pe, DOUBLE max_amp,
    DOUBLE slew_rate, INT nencodes, INT *pw_attack, INT *pw_plat,
    INT *pw_decay, FLOAT *a_base, FLOAT *a_ramp

);
STATUS amppwcrush(

    GRAD_PULSE *rightgradcrush, GRAD_PULSE *leftgradcrush, INT echonum,
    DOUBLE crushscale, DOUBLE targetamp, DOUBLE ampslicesel, DOUBLE stdarea,
    INT minconstpw, INT rmpfullscale

);
STATUS amppwencode(

    GRAD_PULSE *gradpulse, INT *total_pw, DOUBLE target_amp, INT rise_time,
    DOUBLE fov, INT num_encodes, DOUBLE area_offset

);
STATUS amppwencodefse(

    FLOAT *ampencode, INT *pw_encode, DOUBLE fov, INT encodes, INT logaxis,
    INT xflag, INT yflag, INT zflag

);
STATUS amppwencodet(

    FLOAT *a_attack, FLOAT *a_decay, INT *pw_middle, INT *pw_attack,
    INT *pw_decay, DOUBLE target_amp, INT rise_time, DOUBLE fov, INT size

);
STATUS amppwfcse1(

    GRAD_PULSE *gxf11, GRAD_PULSE *gxf21, GRAD_PULSE *gzf11, GRAD_PULSE *gzf21,
    GRAD_PULSE *gxw, GRAD_PULSE *gzrf1, GRAD_PULSE *gzrf2, GRAD_PULSE *gzrf2l1,
    GRAD_PULSE *gzrf2r1, DOUBLE pw_read, DOUBLE fnecho, DOUBLE pcor90,
    DOUBLE pcor180, DOUBLE xtarget, INT pw_rampx, DOUBLE ztarget,
    INT pw_rampz, INT te, INT isodelay

);
STATUS amppwfcse2(

    GRAD_PULSE *gxf12, GRAD_PULSE *gxf22, GRAD_PULSE *gzf12, GRAD_PULSE *gzf22,
    GRAD_PULSE *gxw, GRAD_PULSE *gxw2, GRAD_PULSE *gzrf1, GRAD_PULSE *gzrf2,
    GRAD_PULSE *gzrf2l2, GRAD_PULSE *gzrf2r2, DOUBLE pw_read, DOUBLE te2_te1,
    DOUBLE pcor180, DOUBLE xtarget, INT pw_rampx, DOUBLE ztarget, INT pw_rampz

);
STATUS amppwgmn(

    DOUBLE ref_area, DOUBLE ref_moment, DOUBLE encode_area, DOUBLE moment_area,
    INT max_allowable_time, DOUBLE beta, DOUBLE targetamp, INT ramp2target,
    INT minconstpw, FLOAT *a_gmn1, INT *pw_gmn1a, INT *pw_gmn1, INT *pw_gmn1d,
    FLOAT *a_gmn2, INT *pw_gmn2a, INT *pw_gmn2, INT *pw_gmn2d

);
STATUS amppwgrad(

    DOUBLE targetArea, DOUBLE targetAmp, DOUBLE startAmp, DOUBLE endAmp,
    INT riseTime, INT minConst, FLOAT *Amp, INT *Attack, INT *Pw, INT *Decay

);
STATUS amppwgradmethod(

    GRAD_PULSE *gradpulse, DOUBLE targetArea, DOUBLE targetAmp,
    DOUBLE startAmp, DOUBLE endAmp, INT riseTime, INT minConst

);
STATUS amppwgx1(

    FLOAT *ampgx1, INT *c_pwgx1, INT *a_pwgx1, INT *d_pwgx1, INT seq_type,
    DOUBLE area, DOUBLE area_ramp, INT avai_ptime, DOUBLE fract_echo,
    INT minconstpw, INT rmpfullscale, DOUBLE target

);
STATUS amppwgxfc(

    DOUBLE a_gxw, INT pw_gxwa, INT pw_gxw, INT pw_gxwd, INT pw_ramp,
    INT avail_time, DOUBLE frac_echo, FLOAT *a_gx1, INT *pw_gx1a,
    INT *pw_gx1, INT *pw_gx1d, FLOAT *a_gxfc, INT *pw_gxfca, INT *pw_gxfc,
    INT *pw_gxfcd

);
STATUS amppwgxfc2(

    DOUBLE a_gxw, INT pw_gxw, INT pw_gxwd, INT pw_gxw2a, INT pw_gxw2,
    INT pw_ramp, INT avail_time, DOUBLE loggrd_target, INT te1_te2,
    FLOAT *a_gxfc2, INT *pw_gxfc2a, INT *pw_gxfc2, INT *pw_gxfc2d,
    FLOAT *a_gxfc3, INT *pw_gxfc3a, INT *pw_gxfc3, INT *pw_gxfc3d

);
STATUS amppwgxfcmin(

    DOUBLE a_gxw, INT pw_gxwa, INT pw_gxw, INT pw_gxwd, INT avail_time,
    DOUBLE frac_echo, DOUBLE amp_target, INT pw_rampx, DOUBLE xbeta,
    FLOAT *a_gx1, INT *pw_gx1a, INT *pw_gx1, INT *pw_gx1d, FLOAT *a_gxfc,
    INT *pw_gxfca, INT *pw_gxfc, INT *pw_gxfcd

);
STATUS amppwgy1(

    FLOAT *ampgy1, INT *pw_gy1, INT yresolution, DOUBLE foview,
    LONG avail_pwgy1_time, INT numGrad

);
STATUS amppwgz1(

    FLOAT *ampgz1, INT *c_pwgz1, INT *a_pwgz1, INT *d_pwgz1, DOUBLE area,
    INT avai_ptime, INT minconstpw, INT rmpfullscale, DOUBLE target

);
STATUS amppwgzfc(

    DOUBLE a_gzrf1, INT pw_gzrf1a, INT pw_gzrf1, INT pw_gzrf1d, INT pw_ramp,
    INT avail_time, FLOAT *a_gz1, INT *pw_gz1a, INT *pw_gz1, INT *pw_gz1d,
    FLOAT *a_gzfc, INT *pw_gzfca, INT *pw_gzfc, INT *pw_gzfcd

);
STATUS amppwgzfcmin(

    DOUBLE a_gzrf1, INT pw_gzrf1a, INT fulltexb, INT pw_gzrf1d,
    INT avail_time, INT off_90, DOUBLE amp_target, INT pw_rampz, DOUBLE zbeta,
    FLOAT *a_gz1, INT *pw_gz1a, INT *pw_gz1, INT *pw_gz1d, FLOAT *a_gzfc,
    INT *pw_gzfca, INT *pw_gzfc, INT *pw_gzfcd

);
STATUS amppwlcrsh(

    GRAD_PULSE *gradleftcrush, GRAD_PULSE *gradrightcrush, DOUBLE area_rephase,
    DOUBLE amp_180slicesel, DOUBLE target_amp, INT minconstpw,
    INT rmpfullscale, INT *attackpw_180slicesel

);
STATUS amppwtpe(

    FLOAT *a_attack, FLOAT *a_decay, INT *pw_middle, INT *pw_attack,
    INT *pw_decay, DOUBLE target_amp, INT rise_time, DOUBLE target_area

);
STATUS amppwygmn(

    DOUBLE zeromoment, DOUBLE firstmoment, INT pw_gy1fa, INT pw_gy1f,
    INT pw_gy1fd, DOUBLE a_gy1fa, DOUBLE a_gy1fb, DOUBLE targetamp,
    DOUBLE ramp2target, INT method, INT *pw_gymna, INT *pw_gymn,
    INT *pw_gymnd, FLOAT *a_gymn

);
STATUS ampslice(

    FLOAT *amp_slice_select, LONG trans_bwd, DOUBLE slice_thk, DOUBLE factor,
    INT def_type

);
STATUS amptarget(

    FLOAT *Amptarget, INT laxis, INT lx, INT ly, INT lz

);
STATUS applyRotMatrices(

    FLOAT **amplitude, FLOAT **pulsetype,
    const INT numpoints, const SHORT *rot_mat,
    FLOAT **rot_amplitude, FLOAT **rot_ptype

);
STATUS avepepowscale(

    FLOAT *scale_fact, INT num_encodes, INT overscans

);

STATUS b0Dither_ifile(

    FLOAT *dither_val, INT control, DOUBLE dx, DOUBLE dy, DOUBLE dz,
    DOUBLE agxw, INT esp, INT nslices, INT coiltype, INT debug,
    long (*rsprot)[9], FLOAT *ccinx, FLOAT *cciny, FLOAT *ccinz,
    INT *esp_in, FLOAT *fesp_in, FLOAT *g0, INT *num_elements, INT *exist

);
STATUS b0DitherFile(

    FLOAT *dither_val, INT control, DOUBLE dx, DOUBLE dy, DOUBLE dz,
    DOUBLE agxw, INT esp, INT nslices, INT coiltype, INT debug,
    long (*rsprot)[9], FLOAT *buffer

);
STATUS blipcorr(

    INT *ia_gyb_corr, DOUBLE da_gyb_corr, INT debug, long (*rsprot)[9],
    DOUBLE mult_fact, INT xfs, INT yfs, INT zfs, DOUBLE itx, DOUBLE ity,
    DOUBLE itz, INT control, INT nslices, LOG_GRAD *lgrad, INT pw_gyb,
    INT pw_gyba, DOUBLE a_gxw

);
STATUS blipcorrdel(

    FLOAT *bc_delx, FLOAT *bc_dely, FLOAT *bc_delz, INT esp, INT coiltype,
    INT debug

);

#ifdef DEBUG
STATUS calctrap1stmom(

    FLOAT *moment, DOUBLE ampl, INT attack, INT plateau, INT decay,
    DOUBLE timeref

);
#endif /* DEBUG */
STATUS crusherutil(

    FLOAT *crusher_scale, INT psd_type

);

STATUS dbdtderate(

    LOG_GRAD *lgrad, INT debug

);
void diffcvs(

    CHAR *tag, INT defv, INT ncvs, _cvname *namearray, _cvdataptr *cvarray

);

STATUS endview(

    INT resolution, INT *last_phase_iamp

);
STATUS entrytabinit(

    ENTRY_POINT_TABLE *entryPoint, INT numEntries

);
STATUS epiRFP_mxwl(

    INT nslices, INT nileaves, INT etl, INT esp, DOUBLE tsp,
    DOUBLE xtr_rba_time, DOUBLE frtime, INT fast_rec, DOUBLE opfov,
    INT opyres, DOUBLE oprbw, DOUBLE fovar, INT frsize, FLOAT *b0_dither_val,
    INT spgr_flag, INT **rf_phase_spgr, INT dro, INT dpo, FLOAT *dpo_shift,
    RSP_INFO *rspinfo, INT *view1st, INT *viewskip, INT *gradpol,
    INT ref_mode, INT kydir, INT dc_chop_flag, INT pepolar_flag,
    INT ***recv_freq, DOUBLE ***recv_phase_angle, INT ***recv_phase_ctrl,
    FLOAT *gldelayfval, DOUBLE ampgxw, INT debug

);
STATUS epiRecvFrqPhs(

    INT nslices, INT nileaves, INT etl, INT esp, DOUBLE tsp,
    DOUBLE xtr_rba_time,FLOAT *reftime, DOUBLE frtime, INT fast_rec, DOUBLE opfov,
    INT opyres, DOUBLE oprbw, DOUBLE fovar, INT frsize, FLOAT *b0_dither_val,
    INT spgr_flag, INT **rf_phase_spgr, INT dro, INT dpo, RSP_INFO *rspinfo,
    INT *view1st, INT *viewskip, INT *gradpol, INT ref_mode, INT kydir,
    INT dc_chop_flag, INT pepolar_flag, INT ***recv_freq,
    DOUBLE ***recv_phase_angle, INT ***recv_phase_ctrl, FLOAT *gldelayfval,
    DOUBLE ampgxw, INT debug

);
STATUS epigradopt(

    OPT_GRAD_INPUT *gradin, OPT_GRAD_PARAMS *gradout, FLOAT *pidbdtts,
    FLOAT *pidbdtper, DOUBLE cfdbdtts, DOUBLE cfdbdtper, DOUBLE cfdbdtdx,
    DOUBLE cfdbdtdy, INT reqesp, INT autogap, INT rampsamp, INT vrgsamp,
    INT debug

);
void error_out(

    CHAR *message, INT line, CHAR *file

);
void error_param(

    CHAR *message, INT line, CHAR *file

);

STATUS fdsetup( 

    INT out_xres, FILTER_INFO *echo1rtf

);
STATUS fdcalcfiltinfo( 

    FILTER_INFO *echo1rtf, DOUBLE bandwidth, INT outputs, 
    INT *fracdec_flag

);
STATUS filterutil(

    FILTER_INFO *echo1filter, FILTER_INFO **echo2filter, INT read_time,
    INT read_wing

);
STATUS filterutilv6(

    FILTER_INFO *echo1rtf, FILTER_INFO *echo2rtf, INT outputs,
    DOUBLE fnecholim, INT pwramp, INT read_timel, INT read_timer,
    INT read_wingl, INT read_wingr, INT read_wing2l, INT read_wing2r,
    INT treadvbw, INT maxseqtime

);
STATUS fitresol(

    SHORT *resolution, INT *pulsewidth, INT maxlimit, INT minlimit, INT cycle

);
STATUS fpntoxyz(

    long (*rotmit)[9], INT slquant, FLOAT (*xyz)[3], RSP_INFO *fpn,
    LOG_GRAD *lgrad, PHYS_GRAD *pgrad, INT contdebug

);
STATUS fractecho(

    INT *tfe_extra, DOUBLE fnecho_lim, INT seq_type, INT min_tenfe,
    INT read_pw, INT max_gx1time, DOUBLE amp_targetx, INT target_xrt,
    INT xres, DOUBLE fov

);
STATUS fseminti(

    INT *mintitime, INT hrf0, INT pw_gzrf0d, INT cs_sattime, INT sp_sattime,
    INT satdelay, INT t_exa

);

STATUS getCornerPoints(

    FLOAT **time, FLOAT *ampl[3], FLOAT *pul_type[3], INT *num_totpoints,
    const LOG_GRAD *log_grad, const INT seq_entry_index, const INT samp_rate,
    const INT min_tr, const dbLevel_t debug

);
STATUS genVRGF(

    OPT_GRAD_PARAMS *gradout, INT xres, DOUBLE period, DOUBLE tamp,
    DOUBLE tfthw, DOUBLE tadw, DOUBLE alpha, DOUBLE beta

);
INT get_grad_dly(

    void

);
INT get_rf_dly(

    void

);
STATUS getfiltparams(

    INT decimation, INT outputs, INT *filtertaps, INT *prefills,
    FLOAT *filtergain, INT *minesp, INT xtr_pkt_off

);
CHAR *getGradType(

    const INT ptype

 );

STATUS highlow(

    INT *low, INT *high, INT resolution, SHORT *waveform

);

STATUS ileaveinit(

    INT nframes, INT kydir, INT intleaves, INT alt_fact, INT gpolarity,
    INT bpolarity, INT debug, INT rfchop, INT rfamp, INT blipamp,
    INT pepolarity, INT etl, INT seqdata, DOUBLE tshift, INT tfon,
    INT fract_ky, INT nex, DOUBLE ky_off, INT pe_end_iamp, INT esp,
    DOUBLE tsp, INT samples, DOUBLE ro_amp, INT xft_size, INT slquant,
    INT lpf, INT *gy1f, INT *view1st, INT *viewskip, INT *tf, INT *rfpol,
    INT *gradpol, INT *blippol, INT *mintf

);
STATUS imgtimutil(

    LONG premidRF1_time, LONG acqType, LONG gating, LONG *availimagetime

);
STATUS inittargets(

    LOG_GRAD *lgrad, PHYS_GRAD *pgrad

);

STATUS l_p_transver(

    FLOAT *phy, INT a, INT b, INT c, DOUBLE logx, DOUBLE logy, DOUBLE logz

);

STATUS matrixcheck(

    INT maxx, INT maxy

);
STATUS maxfov(

    FLOAT *Maxfov

);
STATUS maxnecho(

    INT *Maxnecho, LONG nonTEtime, LONG maxSeqTime, INT echoType

);
STATUS maxpass(

    INT *Maxpass, INT acqType, INT numLocs, INT locsPerPass

);
STATUS maxphases(

    INT *Maxphases, LONG seqTimPresc, INT acqType, LONG otherslicelimit

);
STATUS maxseqsar(

    LONG *Maxseqsar, INT numPulses, RF_PULSE *rfpulse, INT entry

);
STATUS maxseqsar_b1scale(

    LONG *Maxseqsar, INT numPulses, RF_PULSE *rfpulse, INT entry

);
STATUS maxslicesar(

    LONG *Maxslicesar, INT numPulses, RF_PULSE *rfpulse, INT entry

);
STATUS maxslicesar_b1scale(

    LONG *Maxslicesar, INT numPulses, RF_PULSE *rfpulse, INT entry

);
STATUS maxslquant(

    INT *Maxslquant, INT repetitionTime, INT otherslicelimit, INT acqType,
    INT seqTimPresc

);
STATUS maxslquanttps(

    INT *Maxslquanttps, INT imageSize, INT numImType, INT numFrame, INT siSize

);
STATUS maxte1(

    LONG *Maxte1, LONG maxSeqTime, INT echoType, LONG nonTEtime, INT min_fullte

);
STATUS maxte2(

    LONG *Maxte2, LONG maxSeqTime, LONG nonTEtime

);
STATUS maxti(

    INT *maxtitime, INT gating, INT te_time, INT nonteti, INT slquant_one,
    INT tmin, INT left_rf0_time, INT left_rf1_time

);
STATUS maxtr(

    INT *Maxtr

);
STATUS maxwellcomp(

    FLOAT *a_mid, INT *pw_attack, INT *pw_mid, INT *pw_decay, DOUBLE maxterm,
    DOUBLE a_start, DOUBLE targetAmp, INT riseTime, FLOAT *r1, FLOAT *r2,
    FLOAT *r3

);
STATUS maxwell_pc_calc(

    INT max_flag, INT num_points, INT debug, INT pwgx1a, INT pwgx1, INT pwgx1d,
    INT pwgxfca, INT pwgxfc, INT pwgxfcd, INT pwgz1a, INT pwgz1, INT pwgz1d,
    INT pwgzfca, INT pwgzfc, INT pwgzfcd, INT pwgyfe1a, INT pwgyfe1,
    INT pwgyfe1d, INT pwgxwa, INT pwgy1a, INT pwgy1, INT pwgy1d, INT pwgzrf1d,
    DOUBLE flow_wdth_x, DOUBLE flow_wdth_z, INT iagx1fen, INT iagx1feu,
    INT iagx1fed, INT iagx2fen, INT iagx2feu, INT iagx2fed, INT iagz1fen,
    INT iagz1feu, INT iagz1fed, INT iagz2fen, INT iagz2feu, INT iagz2fed,
    INT iagy1feu, INT iagy1fed, INT iagy2feu, INT iagy2fed, DOUBLE agxw,
    DOUBLE agzrf1, long *rotmat, FLOAT *maxcoef1a, FLOAT *maxcoef1b,
    FLOAT *maxcoef1c, FLOAT *maxcoef1d, FLOAT *maxcoef2a, FLOAT *maxcoef2b,
    FLOAT *maxcoef2c, FLOAT *maxcoef2d, FLOAT *maxcoef3a, FLOAT *maxcoef3b,
    FLOAT *maxcoef3c, FLOAT *maxcoef3d

);
STATUS maxyres(

    INT *Maxyres, DOUBLE targetAmp, INT ramp_time, INT avaiPhaseTime,
    DOUBLE fov, GRAD_PULSE *gradstruct_y, INT stepsize

);
STATUS minfov(

    FLOAT *Minfov, GRAD_PULSE *gradstruct, DOUBLE foview, INT seq_type,
    INT phase_time, INT freq_time, DOUBLE readout_BW,
    INT phase_encode_resolution, INT existyres, INT phasestep,
    DOUBLE yaspect_ratio, INT flow_comp_type, INT readout_pw,
    DOUBLE fractecho_fact, DOUBLE gxwtargetamp, DOUBLE gx1targetamp,
    INT ramp2xtarget, DOUBLE gy1targetamp, INT ramp2ytarget

);
STATUS minseq(

    INT *p_minseqgram, INT *p_minseqgrddrv, INT *p_minseqgpm, INT *p_minseqcoil,
    GRAD_PULSE *gradx, const INT gx_free, GRAD_PULSE *grady, const INT gy_free,
    GRAD_PULSE *gradz, const INT gz_free, const LOG_GRAD *loggrd,
    const INT seq_entry_index, const INT samp_rate, const INT min_tr,
    const INT e_flag, const INT debug_flag

);
STATUS minseqcoil(

    INT *minseqtime, FLOAT *xa2s, FLOAT *ya2s, FLOAT *za2s, INT srmode,
    GRAD_PULSE *gradx, GRAD_PULSE *grady, GRAD_PULSE *gradz, INT numXpulse,
    INT numYpulse, INT numZpulse, DOUBLE gcontirms

);
STATUS minseqgrad(

    INT *minseqtime, INT *minseqgrddrv, INT *minseqgrddrvx, INT *minseqgrddrvy,
    INT *minseqgrddrvz, INT *ro_time, INT *pe_time, INT *ss_time, INT *px_time,
    INT *py_time, INT *pz_time, GRAD_PULSE *gradx, GRAD_PULSE *grady,
    GRAD_PULSE *gradz, INT numx, INT numy, INT numz, const LOG_GRAD *lgrad,
    PHYS_GRAD *pgrad, SCAN_INFO *scaninfotab, INT slquant, INT plane_type,
    INT coaxial, INT _sigrammode, INT debug, FLOAT *amptrans_px,
    FLOAT *amptrans_py, FLOAT *amptrans_pz, FLOAT *amptrans_lx,
    FLOAT *amptrans_ly, FLOAT *amptrans_lz, FLOAT *abspower_px,
    FLOAT *abspower_py, FLOAT *abspower_pz, FLOAT *abspower_lx,
    FLOAT *abspower_ly, FLOAT *abspower_lz, FLOAT *power_lx,
    FLOAT *pospower_lx, FLOAT *negpower_lx, FLOAT *power_ly,
    FLOAT *pospower_ly, FLOAT *negpower_ly, FLOAT *power_lz,
    FLOAT *pospower_lz, FLOAT *negpower_lz, INT *minseqpwmx,
    INT *minseqpwmy, INT *minseqpwmz, INT *minseqgpm

);
STATUS minseqgram(

    INT *minseqtime, INT *ro_time, INT *pe_time, INT *ss_time, INT *px_time,
    INT *py_time, INT *pz_time, GRAD_PULSE *gradx, GRAD_PULSE *grady,
    GRAD_PULSE *gradz, INT numx, INT numy, INT numz, PHYS_GRAD *pgrad,
    SCAN_INFO *scaninfotab, INT slquant, INT plane_type, INT coaxial,
    INT _sigrammode, INT debug, FLOAT *amptrans_px, FLOAT *amptrans_py,
    FLOAT *amptrans_pz, FLOAT *amptrans_lx, FLOAT *amptrans_ly,
    FLOAT *amptrans_lz, FLOAT *abspower_px, FLOAT *abspower_py,
    FLOAT *abspower_pz, FLOAT *abspower_lx, FLOAT *abspower_ly,
    FLOAT *abspower_lz

);
STATUS minseqgrddrv(

    LONG *minseqtime, FLOAT *power, FLOAT *pospower, FLOAT *negpower,
    INT numPulses, GRAD_PULSE *grad, INT gramtype, DOUBLE irmspos,
    DOUBLE irmsneg, DOUBLE irms, DOUBLE ampgcmfs, DOUBLE gcmfs

);
STATUS minseqrfamp_b1scale(

    LONG *Minseqrfamp, INT numPulses, RF_PULSE *rfpulse, INT entry

);
/* Added for N32 - RJF 15 Oct 1998 */
STATUS minseqrfamp(

    LONG *Minseqrfamp, INT numPulses, RF_PULSE *rfpulse, INT entry

);
STATUS minseqseg(

    INT *p_minseqgram, INT *p_minseqgrddrv, INT *p_minseqgpm,
    INT *p_minseqcoil, FLOAT *p_xa2s, FLOAT *p_ya2s, FLOAT *p_za2s,
    FLOAT *time, FLOAT *ampl[3], FLOAT *pul_type[3],
    const INT num_totpoints, const DOUBLE gcontirms,
    const SCAN_INFO *scaninfotab, const INT num_slices, const dbLevel_t debug

);
STATUS minseqsys(

    INT *Minseqsys

);
STATUS minte1(

    INT *Minte1, INT yresolution, DOUBLE foview, INT min_seq1, INT min_seq2,
    INT min_seq3, INT seq_type, INT echo_type, INT read_pw, INT iso_delay,
    INT rf_180_pw, INT flow_comp_type, DOUBLE fnecho_lim,
    GRAD_PULSE *gradstruct_y, DOUBLE gxw_target, DOUBLE gx1_target,
    INT pw_rampx

);
STATUS minte2(

    INT *Minte2, INT tfe_extra, INT min_seq1, INT min_seq2, INT seq_type,
    INT echo_type, INT read_pw1, DOUBLE amp_read1, INT read_pw2,
    DOUBLE amp_read2, INT flow_comp_type, DOUBLE target_ampx, INT target_xrt

);
STATUS minti(

    INT *Minti, INT slquant1, INT tmin, INT tileftovers, INT sat2flag

);
STATUS mintr(

    LONG *Mintr, INT acqType, LONG minseqTime, INT Slquant1, INT gating

);
STATUS modrotmats(

    long (*inrot)[9], long (*outrot)[9], INT alpha, INT beta, INT gamma,
    INT slquant, INT debug

);

STATUS newrotatearray(

    long (*inrot)[9], long (*outrot)[9], DOUBLE alpha, DOUBLE beta,
    DOUBLE gamma, INT slquant, LOG_GRAD *lgrad, PHYS_GRAD *pgrad,
    INT contdebug

);

STATUS obloptimize(

    LOG_GRAD  *lgrad, PHYS_GRAD *pgrad, SCAN_INFO *scaninfotab,
    INT slquant, INT plane_type, INT coaxial, INT method, INT debug,
    INT *newgeo, INT srmode

);
STATUS opt_pw_amp(

    DOUBLE area, DOUBLE targetamp, DOUBLE maxamp, INT rmp2fs, DOUBLE *amp,
    INT *c_pw, INT *a_pw, INT *d_pw

);
STATUS optgmn(

    DOUBLE a_left, INT pw_lefta, INT pw_left, INT pw_leftd, DOUBLE a_right,
    INT pw_righta, INT pw_right, INT pw_rightd, FLOAT *a_mid, INT *pw_mida,
    INT *pw_mid, INT *pw_midd, DOUBLE rate, INT *pos_mid, INT *pos_right

);
STATUS optramp(

    LONG *pulsewidth, DOUBLE ampdelta, DOUBLE maxamp, INT rmp2fullscale,
    INT defineType

);
STATUS optspecir(

    FLOAT *opttheta, INT *maxti, INT soltype

);
STATUS orderphases(

    SHORT *phase2view, INT respCompType, INT phaseRes

);
STATUS orderslice(

    INT acqType, INT numLocs, INT locsPerPass, INT gating

);
STATUS orderslice2(

    INT acqType, INT numLocs, INT numAcqs, INT *sl_pass, INT *prescan_pass, INT gating

);

STATUS pcflowtarget(

    INT flaxx, INT flaxy, INT flaxz, DOUBLE derate_factor, FLOAT *xtarget,
    FLOAT *ytarget, FLOAT *ztarget, LOG_GRAD *Loggrdp, INT derate_flag

);
STATUS peakB1(

    FLOAT *maxB1Val, INT entryPoint, INT numPulseEntries, RF_PULSE *rfPulse

);
STATUS peakrf(

    FLOAT *peak_output, FLOAT *est_jstd, INT numPulses, RF_PULSE *rfpulse,
    INT entry

);
INT phase_order_fgre3d(

    SHORT *view_tab, INT phase_order, INT rspviews, INT viewoffset

);
STATUS power_peraxis(

    FLOAT *power, INT numPulses, GRAD_PULSE *grad

);
STATUS powermon(

    ENTRY_POINT_TABLE *entryPoint, INT entry, INT numPulses, RF_PULSE *rfpulse,
    INT sarTseq, DOUBLE maxB1, FLOAT *average_sar, FLOAT *peak_sar

);
STATUS powermon_b1scale(

    ENTRY_POINT_TABLE *entryPoint, INT entry, INT numPulses, RF_PULSE *rfpulse,
    INT sarTseq, DOUBLE maxB1, FLOAT *average_sar, FLOAT *peak_sar

);
STATUS prescanslice(

    INT *slpass, INT *sltime, LONG numLocs

);
STATUS prescanslice1(

    INT *preslorder, INT pre_slquant, LONG numLocs

);
STATUS printGRADPULSE( GRAD_PULSE *pulse );
STATUS printRFPULSE( RF_PULSE *pulse );
STATUS printLOGGRAD( LOG_GRAD *pulse );
STATUS printPHYSGRAD( PHYS_GRAD *pulse );
STATUS printARGS( CHAR *routine, ... );
INT psd_getgradmode(

    void

);
void psd_dump_scan_info(

    void

);
void psd_dump_rsp_info(

    void

);

STATUS rampmoments(

    DOUBLE ampinitial, DOUBLE ampfinal, INT duration, INT invertphaseflag,
    INT *pulsepos, FLOAT *zerothmoment, FLOAT *firstmoment,
    FLOAT *zeromomentsum, FLOAT *firstmomentsum

);
STATUS readgrdcfg();

STATUS scale(

    FLOAT (*inrotmat)[9], long (*outrotmat)[9], INT slquant, LOG_GRAD *lgrad,
    PHYS_GRAD *pgrad, INT contdebug

);
STATUS scalerfpulses(

    DOUBLE weight, INT gcoiltype, INT numPulses, RF_PULSE *rfpulse, INT entry,
    RF_PULSE_INFO *rfpulseInfo

);
STATUS scalerotmats(

    long (*rsprot)[9], LOG_GRAD *lgrad, PHYS_GRAD *pgrad, INT slquant, INT debug

);
STATUS scaninfotab_init(

    SCAN_INFO *scaninfotab, INT plane_type, INT slquant, INT debug

);
STATUS seqtime(

    LONG *Seqtime, LONG availimagetime, INT Slquant1, INT acqType

);
STATUS seqtype(

    LONG *Seqtype

);
STATUS setGradCalcMethod(

    const INT gradmethod, const INT e_flag

);
STATUS setScale(

    INT entryPoint, INT numPulseEntries, RF_PULSE *rfPulse, FLOAT maxB1,
    FLOAT extraScale

);
STATUS setfilter(

    INT type, INT board, PSD_FILTER_GEN *filter_struct, INT filter_slot,
    INT taps, INT decimation, INT outputs, INT prefills, INT flush,
    INT tflush, INT post_flush, INT rshift, DOUBLE alp, DOUBLE filfrq,
    DOUBLE picw, DOUBLE wt, INT invert_q, DOUBLE tps_bw

);
STATUS setsysparms(

    void

);
STATUS setupphasetable(

    SHORT *phaseTab, INT respCompType, INT phaseRes

);
STATUS setuprfpulse(

    INT slot, INT *pw, FLOAT *amp, DOUBLE abswidth, DOUBLE effwidth,
    DOUBLE area, DOUBLE dtycyc, DOUBLE maxpw, INT num, DOUBLE max_b1,
    DOUBLE max_int_b1_sq, DOUBLE max_rms_b1, DOUBLE nom_fa, FLOAT *act_fa,
    DOUBLE nom_pw, DOUBLE nom_bw, UINT activity, UCHAR reference,
    INT isodelay, DOUBLE scale, INT *res, INT extgradfile, RF_PULSE *rfpulse

);
STATUS setupslices(

    INT *sliceTab, RSP_INFO *rspInfoTab, INT numLocs, DOUBLE gradStrength,
    DOUBLE receiveBW, DOUBLE fov, INT transmitFlag

);
STATUS slicein1(

    INT *Slquant1, INT numAcqs, INT acqType

);
STATUS slicesort(

    INT *Slquant1, INT *sl_pass, INT maxlocsPerPass, INT *numAcqs, INT MaxAcq, INT acqType

);

STATUS trapmaxwell(

    DOUBLE a_start, INT pw_attack, DOUBLE a_mid, INT pw_mid, DOUBLE a_end,
    INT pw_decay, FLOAT *maxterm

);
STATUS trapvals(

    DOUBLE area, INT *a_pw, INT *d_pw, FLOAT *amp, INT *c_pw, INT def_type

);
STATUS typ3dmscat(

    INT *pislab, INT numLocs, INT numSlabs, INT numAcqs

);
STATUS typ3dmsncat(

    INT *pislab, INT numLocs, INT numSlabs, INT numAcqs

);
STATUS typcard(

    INT *indexrot, INT numLocs, INT maxphase

);
STATUS typcat(

    INT *pislice, INT numLocs, INT locsPerPass, INT numAcqs

);
STATUS typfsa(

    INT *pislice, INT numLocs, INT *locsPass, INT numAcqs

);
STATUS typncat(

    INT *pislice, INT numLocs, INT numAcqs

);
STATUS typncatPomp(

    DATA_ACQ_ORDER *tempAcqTab, INT *pislice, INT numLocs, INT numAcqs

);
STATUS typssfseint(

    INT *pislice, INT numLocs, INT locsPerPass, INT numAcqs

);
STATUS typssfseseq(

    INT *pislice, INT numLocs, INT locsPerPass, INT numAcqs

);
STATUS typxrr(

    INT *pislice, INT numLocs, INT numAcqs

);
STATUS typxrrPomp(

    DATA_ACQ_ORDER *tempAcqTab, INT *pislice, INT numLocs, INT numAcqs

);

STATUS unscale(

    long (*inrotmat)[9], FLOAT (*outrotmat)[9], INT slquant, LOG_GRAD *lgrad,
    PHYS_GRAD *pgrad, INT contdebug

);
STATUS updateIndex(

    int *index

);

STATUS vrghighlow(

    INT *low, INT *high, INT resolution, SHORT *waveform

);

STATUS xyztofpn(

    long (*rotmit)[9], INT slquant, FLOAT (*xyz)[3], RSP_INFO *fpn,
    LOG_GRAD *lgrad, PHYS_GRAD *pgrad, INT contdebug

);

STATUS calcOptimizedPulses ( 
    LOG_GRAD *p_loggrd, FLOAT *Pidbdtper, FLOAT *derate_factor,
    const INT core_index, 
    INT debug_level, int e_flag, int open_grx 
);
 
#else /* !__STDC__ */

STATUS OpenDelayFile();
STATUS OpenDitherFile();
STATUS OpenDitherInterpoFile();

STATUS advroundup();
STATUS advrounddown();
STATUS altrfgen();
STATUS ampfov();
STATUS amppwcombpe();
STATUS amppwcrush();
STATUS amppwencode();
STATUS amppwencodefse();
STATUS amppwencodet();
STATUS amppwfcse1();
STATUS amppwfcse2();
STATUS amppwgmn();
STATUS amppwgrad();
STATUS amppwgradmethod();
STATUS amppwgx1();
STATUS amppwgxfc();
STATUS amppwgxfc2();
STATUS amppwgxfcmin();
STATUS amppwgy1();
STATUS amppwgz1();
STATUS amppwgzfc();
STATUS amppwgzfcmin();
STATUS amppwlcrsh();
STATUS amppwtpe();
STATUS amppwygmn();
STATUS ampslice();
STATUS amptarget();
STATUS applyRotMatrices();
STATUS avepepowscale();

STATUS b0Dither_ifile();
STATUS b0DitherFile();
STATUS blipcorr();
STATUS blipcorrdel();

#ifdef DEBUG
STATUS calctrap1stmom();
#endif /* DEBUG */
STATUS crusherutil();

STATUS dbdtderate();
void diffcvs();

STATUS endview();
STATUS entrytabinit();
STATUS epiRFP_mxwl();
STATUS epiRecvFrqPhs( );
STATUS epigradopt();
void error_out();
void error_param();

STATUS fdsetup();
STATUS fdcalcfiltinfo();
STATUS filterutil();
STATUS filterutilv6();
STATUS fitresol();
STATUS fpntoxyz();
STATUS fractecho();
STATUS fseminti();

STATUS getCornerPoints();
STATUS genVRGF();
INT get_grad_dly();
INT get_rf_dly();
STATUS getfiltparams();

STATUS highlow();

STATUS ileaveinit();
STATUS imgtimutil();
STATUS inittargets();

STATUS l_p_transver();

STATUS matrixcheck();
STATUS maxfov();
STATUS maxnecho();
STATUS maxpass();
STATUS maxphases();
STATUS maxseqsar();
STATUS maxseqsar_b1scale();
STATUS maxslicesar();
STATUS maxslicesar_b1scale();
STATUS maxslquant();
STATUS maxslquanttps();
STATUS maxte1();
STATUS maxte2();
STATUS maxti();
STATUS maxtr();
STATUS maxwellcomp();
STATUS maxwell_pc_calc();
STATUS maxyres();
STATUS minfov();
STATUS minseq();
STATUS minseqcoil();
STATUS minseqgrad();
STATUS minseqgram();
STATUS minseqgrddrv();
/* Added for N32 - RJF - 15 Oct 1998 */
STATUS minseqrfamp();
STATUS minseqrfamp_b1scale();
STATUS minseqseg();
STATUS minseqsys();
STATUS minte1();
STATUS minte2();
STATUS minti();
STATUS mintr();
STATUS modrotmats();

STATUS newrotatearray();

STATUS obloptimize();
STATUS opt_pw_amp();
STATUS optgmn();
STATUS optramp();
STATUS optspecir();
STATUS orderphases();
STATUS orderslice();
STATUS orderslice2();

STATUS pcflowtarget();
STATUS peakB1();
STATUS peakrf();
INT phase_order_fgre3d();
STATUS power_peraxis();
STATUS powermon();
STATUS powermon_b1scale();
STATUS prescanslice();
STATUS prescanslice1();
INT psd_getgradmode();
void psd_dump_scan_info();
void psd_dump_rsp_info();

STATUS rampmoments();

STATUS scale();
STATUS scalerfpulses();
STATUS scalerotmats();
STATUS scaninfotab_init();
STATUS seqtime();
STATUS seqtype();
STATUS setGradCalcMethod();
STATUS setScale();
STATUS setfilter();
STATUS setsysparms();
STATUS setupphasetable();
STATUS setuprfpulse();
STATUS setupslices();
STATUS slicein1();
STATUS slicesort();

STATUS trapmaxwell();
STATUS trapvals();
STATUS typ3dmscat();
STATUS typ3dmsncat();
STATUS typcard();
STATUS typcat();
STATUS typfsa();
STATUS typncat();
STATUS typncatPomp();
STATUS typssfseint();
STATUS typssfseseq();
STATUS typxrr();
STATUS typxrrPomp();
STATUS unscale();
STATUS updateIndex();  
STATUS vrghighlow();
STATUS xyztofpn();
STATUS calcOptimizedPulses();
#endif /* __STDC__ */

#endif /* support_func_host_h */

