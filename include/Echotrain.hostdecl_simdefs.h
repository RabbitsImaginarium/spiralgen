 _cvint  _pw_frinit
= {&pw_frinit, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _fast_rec_lpf
= {&fast_rec_lpf,  1,5,1,0,0,0,1,(1 + 2), "Fast rec low pass freq: 1=100kHz,2=200kHz,3=300kHz,4=400kHz,5=500kHz",0,"",} 
;
 _cvint  _delayon
= {&delayon,  0,1,1,0,0,0,1,(1 + 2),             "1=use delay values from /usr/g/bin/delay.dat, 0=don't",0,"",} 
;
 _cvint  _debug_delay
= {&debug_delay,  0,1,0,0,0,0,1,(1 + 2),"1 to turn on delay debug",0,"",} 
;
 _cvint  _defaultdelay
= {&defaultdelay, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _esp
= {&esp,  0,MAXINT,0,0,0,0,1,(1 + 2),"echo spacing (Do not fix it!)",0,"",} 
;
 _cvint  _minesp
= {&minesp, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _no_shots
= {&no_shots,  1,MAXINT,1,0,0,0,1,(1 + 2),"no. of shots it takes to acquire an image",0,"",} 
;
 _cvint  _ky_dir
= {&ky_dir,  0,5,0,0,0,0,1,(1 + 2),"0=top down; 1=center out; 2=bottom"                          " up; 3=seq center out; 4=rev center out;"" 5 = quasi centric.",0,"",} 
;
 _cvint  _vsf
= {&vsf,  1,4,1,0,0,0,1,(1 + 2),"view sharing factor",0,"",} 
;
 _cvint  _rowflip
= {&rowflip,  0,1,0,0,0,0,1,(1 + 2),"0 = row flipping off, 1 = on.",0,"",} 
;
 _cvint  _no_viewskip
= {&no_viewskip,  1,MAXINT,1,0,0,0,1,(1 + 2),    "no. of views to skip by each phase blip",0,"",} 
;
 _cvint  _gycontrol
= {&gycontrol,  0,1,1,0,0,0,1,(1 + 2),"0 = y grad off, 1 = on.",0,"",} 
;
 _cvint  _etps
= {&etps,  1,256,2,0,0,0,1,(1 + 2),"0 = Echo trains per segment.",0,"",} 
;
 _cvint  _perf_prep
= {&perf_prep,  0, 1, 0,0,0,0,1, (1 + 2), "1 = perfusion sat pulse.",0,"",} 
;
 _cvint  _ref_on
= {&ref_on,  0,1,0,0,0,0,1,(1 + 2),"0 = ref scan off, 1 = on.",0,"",} 
;
 _cvint  _et_dc_chop
= {&et_dc_chop,  0,1,1,0,0,0,1,(1 + 2),"0 = echotrain DC chop off, 1 = on.",0,"",} 
;
 _cvfloat  _pckeeppct
= {&pckeeppct,  0.0, 100.0, 100.0,0,0,0,1, (1 + 2),             "Percentange of post-RFT array to use in phase correction",0,"",} 
;
 _cvint  _where_bestky
= {&where_bestky,  0,2,1,0,0,0,1,(1 + 2),           "When = 0, rhpcbestky = view1st[1]; when = 1, = view1st[no_shots/2]; when = 2, = view1st[no_shots].",0,"",} 
;
 _cvint  _et_ramp_flip
= {&et_ramp_flip,  0,1,0,0,0,0,1,(1 + 2),"Ramp flip angle to max. 0=normal, 1=ramped",0,"",} 
;
 _cvfloat  _et_ramp_TI
= {&et_ramp_TI,  1.0,100.0,10.0,0,0,0,1,(1 + 2),            "TI(ms) to use in Echo-Train perf ramp flip calculations.",0,"",} 
;
 _cvfloat  _et_ramp_T1
= {&et_ramp_T1,  1.0,3000000.0,70.0,0,0,0,1,(1 + 2),            "T1(ms) to use in Echo-Train perf ramp flip calculations.",0,"",} 
;
 _cvfloat  _et_ramp_init
= {&et_ramp_init,  1.0,90.0,40.0,0,0,0,1,(1 + 2),            "Initial flip to use in ramp flip calculations.",0,"",} 
;
 _cvint  _et_ramp_debug
= {&et_ramp_debug,  0,1,0,0,0,0,1,(1 + 2),            "Debug flag for Echo-Train perf ramp flip.",0,"",} 
;
 _cvint  _off_fov
= {&off_fov,  0,1,0,0,0,0,1,(1 + 2),"Off-center FOV correction:0=off,1=on.",0,"",} 
;
 _cvfloat  _xtr_rba_time
= {&xtr_rba_time,  -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),100 + 5,0,0,0,1,(1 + 2),           "phase accumulation interval for off-center FOV (usec)",0,"",} 
;
 _cvfloat  _a_gxwn
= {&a_gxwn, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxwlr
= {&pw_gxwlr, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _eshift
= {&eshift,  0,1,1,0,0,0,1,(1 + 2),"Echo shift:0=off,1=on.",0,"",} 
;
 _cvint  _debug_eshift
= {&debug_eshift,  0, 1, 0,0,0,0,1, (1 + 2), "Debug Eshift.",0,"",} 
;
 _cvint  _debug_oblcorr
= {&debug_oblcorr,  0,1,0,0,0,0,1,(1 + 2), "Debug switch for phase-encoding blip correction [0=off,1=on].",0,"",} 
;
 _cvfloat  _bc_delx
= {&bc_delx,  -1000.0,1000.0,0.0,0,0,0,1,(1 + 2), "Interpolated x delay for blip correction.",0,"",} 
;
 _cvfloat  _bc_dely
= {&bc_dely,  -1000.0,1000.0,0.0,0,0,0,1,(1 + 2), "Interpolated y delay for blip correction.",0,"",} 
;
 _cvfloat  _bc_delz
= {&bc_delz,  -1000.0,1000.0,0.0,0,0,0,1,(1 + 2), "Interpolated z delay for blip correction.",0,"",} 
;
 _cvint  _oblcorr_on
= {&oblcorr_on,  0,1,0,0,0,0,1,(1 + 2), "Control switch for use of oblique plane  blip correction [0=off,1=on].",0,"",} 
;
 _cvfloat  _da_gyboc
= {&da_gyboc,  0.0,2.2,0.0,0,0,0,1,(1 + 2), "Tweaking value for a_gyboc.",0,"",} 
;
 _cvfloat  _oc_fact
= {&oc_fact,  -10.0,10.0,1.0,0,0,0,1,(1 + 2), "Multiplication factor for a_gyboc.",0,"",} 
;
 _cvint  _debug_setphase
= {&debug_setphase,  0,1,0,0,0,0,1,(1 + 2), "Debug switch for phase-encoding blip correction [0=off,1=on].",0,"",} 
;
 _cvint  _pos_gxwp
= {&pos_gxwp, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pos_gxwn
= {&pos_gxwn, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pos_gyb
= {&pos_gyb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pos_gxk
= {&pos_gxk, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _area_gxk
= {&area_gxk,  -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gxk pulse",0,"",} 
;
 _cvint  _gxk_on
= {&gxk_on,  0,1,0,0,0,0,1, (1 + 2), "switch to turn on gxk pulse",0,"",} 
;
 _cvfloat  _gxk_target
= {&gxk_target, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _et_tagging_flag
= {&et_tagging_flag, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _arr_adj
= {&arr_adj,  0,1,0,0,0,0,1, (1 + 2), "flag for arrhythmia adjust",0,"",} 
;
 _cvint  _et_fast_pass
= {&et_fast_pass,  0,1,0,0,0,0,1, (1 + 2), "Fast Pass packet for ET",0,"",} 
;
 _cvint  _et_ps2shot
= {&et_ps2shot,  1, 256 + 1, 1,0,0,0,1, (1 + 2),                              "Shot to use for mps2/aps2",0,"",} 
;
 _cvint  _et_ps2echo
= {&et_ps2echo,  0, 31, 1,0,0,0,1, (1 + 2),                              "Echo to use for mps2/aps2",0,"",} 
;
 _cvint  _et_usefdelay
= {&et_usefdelay,  0, 1, 0,0,0,0,1, (1 + 2),                      "Use fine delay for fast receiver",0,"",} 
;
 _cvfloat  _dacq_adjust
= {&dacq_adjust,  -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "dacq starting time fine tuning adjustment",0,"",} 
;
 _cvint  _pos_tweak
= {&pos_tweak, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _etune
= {&etune,  0, 1, 0,0,0,0,1, (1 + 2), "Flag to allow echo tuning.",0,"",} 
;
 _cvint  _rampsamp
= {&rampsamp,  0, 1, 0,0,0,0,1, (1 + 2), "Ramp Sampling flag.",0,"",} 
;
 _cvint  _dbdt_iter
= {&dbdt_iter,  0, 1, 0,0,0,0,1, (1 + 2),                             "Use iterative apporach for db/dt.",0,"",} 
;
 _cvint  _eta_maxdelay
= {&eta_maxdelay, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _eta_nex
= {&eta_nex, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _eta_prep_dda
= {&eta_prep_dda, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _eta_post_dda
= {&eta_post_dda, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _eta_opcode
= {&eta_opcode, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _eta_wait4ref
= {&eta_wait4ref, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _queued
= {&queued,  0, 1, 0,0,0,0,1, (1 + 2), "EPI mode queueing flag. 1=ON ",0,"",} 
;
 _cvint  _gss_debug
= {&gss_debug, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _rot_debug
= {&rot_debug, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ecg_debug
= {&ecg_debug, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _perfusionkey
= {&perfusionkey,      0, 1, 0,0,0,0,1, (1 + 2), "perfusion key flag.",0,"",} 
;
 _cvint  _RTETkey
= {&RTETkey,      0, 1, 0,0,0,0,1, (1 + 2), "RTET key flag.",0,"",} 
;
 _cvint  _RTCAkey
= {&RTCAkey,      0, 1, 0,0,0,0,1, (1 + 2), "RTCA key flag.",0,"",} 
;
 _cvint  _IDRIVEkey
= {&IDRIVEkey,      0, 1, 0,0,0,0,1, (1 + 2), "IDRIVE key flag.",0,"",} 
;
 _cvint  _pw_ssp_ungated_wait
= {&pw_ssp_ungated_wait, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_wgz
= {&pw_wgz, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_wssp
= {&pw_wssp, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_sspdelay
= {&pw_sspdelay, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_eta_delay1
= {&pw_eta_delay1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_wgx
= {&pw_wgx, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxk
= {&a_gxk, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxk
= {&ia_gxk, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxka
= {&pw_gxka, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxkd
= {&pw_gxkd, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxk
= {&pw_gxk, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_wgy
= {&pw_wgy, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_wssps
= {&pw_wssps, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gld_buf
= {&pw_gld_buf, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_eta_delay2
= {&pw_eta_delay2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 int  _temp0_pw_gxwlr
;
 int  _temp1_pos_gxwp
;
 int  _temp2_pw_gxwlr
;
 float  _temp3_a_gxwn
;
 int  _temp4_pos_gxwn
;
 int  _temp5_pw_gxk
;
 float  _temp6_a_gxk
;
 int  _temp7_pos_gxk
;
 int  _temp8_pos_gyb
;
 int  _temp9_pw_gld_buf
;
 float  _temp10_bc_delx
;
 float  _temp11_bc_dely
;
 float  _temp12_bc_delz
;
 int  _temp13_defaultdelay
;
 float  _temp14_a_gxk
;
 int  _temp15_pw_gxka
;
 int  _temp16_pw_gxk
;
 int  _temp17_pw_gxkd
;
