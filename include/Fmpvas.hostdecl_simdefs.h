 _cvint  _numsegs
= {&numsegs, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _trigStart
= {&trigStart, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _maxRR
= {&maxRR, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _maxHWbad
= {&maxHWbad, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _maxHWtime
= {&maxHWtime,  0,20000000,10000000,0,0,0,1,(1 + 2),"Max time before sequence times out",0,"",} 
;
 _cvint  _rwaits
= {&rwaits,  1,4,2,0,0,0,1,(1 + 2),"Number of r beats to wait upon arrhythmia",0,"",} 
;
 _cvint  _extraRRlimit
= {&extraRRlimit,  0,100,4,0,0,0,1,(1 + 2),"Extra RR periods allowed per scan",0,"",} 
;
 _cvint  _cs_time
= {&cs_time, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _cs_dda
= {&cs_dda, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _cs_satstart
= {&cs_satstart, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _coredda
= {&coredda,  0,MAXINT,2,0,0,0,1,(1 + 2),"Number of disdaqs for slice = 1",0,"",} 
;
 _cvint  _coredda2
= {&coredda2,  0,MAXINT,2,0,0,0,1,(1 + 2),"Number of disdaq triggers for slice > 1",0,"",} 
;
 _cvint  _ps2coredda
= {&ps2coredda,  0,MAXINT,2,0,0,0,1,(1 + 2),"number of dummy triggers sequence will accept",0,"",} 
;
 _cvint  _prep_dda
= {&prep_dda,  0,MAXINT,8,0,0,0,1,(1 + 2)," number of disdaqs before IR in FMPVAS",0,"",} 
;
 _cvint  _ramp_flip
= {&ramp_flip,  0,1,0,0,0,0,1,(1 + 2),"Ramp flip angle to max. 0=normal, 1=ramped",0,"",} 
;
 _cvfloat  _Meq
= {&Meq,  -1.0,1.0,0.6,0,0,0,1,(1 + 2),            "target equilibrium magnetization for ramp flip calcs.",0,"",} 
;
 _cvfloat  _T1
= {&T1,  1.0,1.E7,3.0E5,0,0,0,1,(1 + 2),            "T1 to use in ramp flip calculations.",0,"",} 
;
 _cvint  _calc_type
= {&calc_type,  0,1,1,0,0,0,1,(1 + 2),           "type 0 assumes T1 >> TR for ramp flip calc.",0,"",} 
;
 _cvint  _var_ext
= {&var_ext,  0,MAXINT,1,0,0,0,1,(1 + 2),            "number of extra views to calculate ramp flip angles.",0,"",} 
;
 _cvint  _numphases
= {&numphases, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _num_delays
= {&num_delays, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _segment_dda
= {&segment_dda, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _views_per_sat
= {&views_per_sat,  1,8,1,0,0,0,1,(1 + 2), " Number of views for each intermittent SAT.",0,"",} 
;
 _cvint  _min_viewoffs
= {&min_viewoffs,  0,MAXINT,20,0,0,0,1,(1 + 2), "Minimum number of views to offset for centric ordering.",0,"",} 
;
 _cvint  _qrs_killer
= {&qrs_killer,  0,1,1,0,0,0,1,(1 + 2), "Play killer at end of every QRS.",0,"",} 
;
 _cvint  _nflow
= {&nflow,  2,4,2,0,0,0,1,(1 + 2), " Number of flow images for recon to process.",0,"",} 
;
 _cvint  _modflip_flag
= {&modflip_flag,  0,MAXINT,0,0,0,0,1,(1 + 2),"on(=1) flag for changing 1st flip angle.",0,"",} 
;
 _cvfloat  _flip_modrf1
= {&flip_modrf1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _mod_dda
= {&mod_dda,  0,MAXINT,0,0,0,0,1,(1 + 2),"number of disdaqs after the modflip rf1 pulse.",0,"",} 
;
 _cvint  _debug_card_sim
= {&debug_card_sim,  0,1,0,0,0,0,1,(1 + 2),"debug switch to simulate cardiac triggers. ",0,"",} 
;
 _cvint  _debug_ramp
= {&debug_ramp,  0,1,0,0,0,0,1,(1 + 2),"prints out ramp flips on ipg. ",0,"",} 
;
 _cvfloat  _area_killx
= {&area_killx, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _area_killy
= {&area_killy, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _area_killz
= {&area_killz, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _xkiller
= {&xkiller, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ykiller
= {&ykiller, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _zkiller
= {&zkiller, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _qrs_ext_time
= {&qrs_ext_time, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _qrs_killer_time
= {&qrs_killer_time, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _extra_mpl_time
= {&extra_mpl_time, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _tdel_prepdda
= {&tdel_prepdda,  0000000,5000000,0000000,0,0,0,1,(1 + 2),"delay time for IR prep_dda when gating",0,"",} 
;
 _cvint  _seg_delay
= {&seg_delay,  0000000,5000000,0000000,0,0,0,1,(1 + 2),"Delay time from cardiac trigger to data acquisition",0,"",} 
;
 _cvint  _minwait
= {&minwait,  0000000,50000,0000000,0,0,0,1,(1 + 2),"Minimum duration of wait_aftertrig sequence",0,"",} 
;
 _cvfloat  _satgap
= {&satgap,  10.,30.,10.,0,0,0,1,(1 + 2),"Concat. sat gap along z (mm)",0,"",} 
;
 _cvfloat  _a_gxk2
= {&a_gxk2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxk2
= {&ia_gxk2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxk2a
= {&pw_gxk2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxk2d
= {&pw_gxk2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxk2
= {&pw_gxk2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gyk2
= {&a_gyk2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gyk2
= {&ia_gyk2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gyk2a
= {&pw_gyk2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gyk2d
= {&pw_gyk2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gyk2
= {&pw_gyk2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzk2
= {&a_gzk2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzk2
= {&ia_gzk2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzk2a
= {&pw_gzk2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzk2d
= {&pw_gzk2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzk2
= {&pw_gzk2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 float  _temp0_a_gxk2
;
 int  _temp1_pw_gxk2a
;
 int  _temp2_pw_gxk2
;
 int  _temp3_pw_gxk2d
;
 float  _temp4_a_gyk2
;
 int  _temp5_pw_gyk2a
;
 int  _temp6_pw_gyk2
;
 int  _temp7_pw_gyk2d
;
 float  _temp8_a_gzk2
;
 int  _temp9_pw_gzk2a
;
 int  _temp10_pw_gzk2
;
 int  _temp11_pw_gzk2d
;
