 _cvint  _RF0_SLOT
= {&RF0_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _RF2_SLOT
= {&RF2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _RF1SE1_SLOT
= {&RF1SE1_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _RF1SE2_SLOT
= {&RF1SE2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _GZRF0_SLOT
= {&GZRF0_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _GZRF2_SLOT
= {&GZRF2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _GZRF1SE1_SLOT
= {&GZRF1SE1_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _GZRF1SE2_SLOT
= {&GZRF1SE2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _GZ1SE1_SLOT
= {&GZ1SE1_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _GZ1SE2_SLOT
= {&GZ1SE2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _GZIRK_SLOT
= {&GZIRK_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint _GZSEK_SLOT
= {&GZSEK_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _max_ti
= {&max_ti,  -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"maximum prep time",0,"",} 
;
 _cvfloat  _area_gzirk
= {&area_gzirk,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gzirk pulse",0,"",} 
;
 _cvfloat  _area_gzsek
= {&area_gzsek,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gzsek pulse",0,"",} 
;
 _cvfloat  _area_gzrf1se1
= {&area_gzrf1se1,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gzrf1se1 pulse within prep time",0,"",} 
;
 _cvfloat  _area_gzrf1se2
= {&area_gzrf1se2,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gzrf1se2 pulse within prep time",0,"",} 
;
 _cvfloat  _area_gz1se1
= {&area_gz1se1,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gz1se1 pulse",0,"",} 
;
 _cvfloat  _area_gz1se2
= {&area_gz1se2,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "area of gz1se2 pulse",0,"",} 
;
 _cvfloat  _area_crusher
= {&area_crusher,  0,((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2), "nominal area of DE prep crusher pulse",0,"",} 
;
 _cvint  _min_tdel
= {&min_tdel,  -MAXINT,MAXINT,0,0,0,0,1,(1 + 2)," minimum trigger delay",0,"",} 
;
 _cvint  _min_ti
= {&min_ti,  -MAXINT,MAXINT,0,0,0,0,1,(1 + 2)," minimum prep time",0,"",} 
;
 _cvint  _min_trf1_2
= {&min_trf1_2,  -MAXINT,MAXINT,0,0,0,0,1,(1 + 2)," minimum time between rf1se1 and rf2",0,"",} 
;
 _cvint  _min_trf2se2
= {&min_trf2se2,  -MAXINT,MAXINT,0,0,0,0,1,(1 + 2)," minimum time between rf2 and rf1se2",0,"",} 
;
 _cvint  _tmin_prep
= {&tmin_prep,  0,MAXINT,0,0,0,0,1,(1 + 2), "Minimum time for the prep section",0,"",} 
;
 _cvint  _pos_start_ir
= {&pos_start_ir,  0,MAXINT,0,0,0,0,1,(1 + 2), "Start time for IR prep sequence.  ",0,"",} 
;
 _cvint  _pos_start_se
= {&pos_start_se,  0,MAXINT,0,0,0,0,1,(1 + 2), "Start time for SE prep sequence.  ",0,"",} 
;
 _cvint  _t_exa_rf1se1
= {&t_exa_rf1se1,  0,MAXINT,0,0,0,0,1,(1 + 2),"time from start of se1 90 to mid se1 90",0,"",} 
;
 _cvint  _t_exb_rf1se1
= {&t_exb_rf1se1,  0,MAXINT,0,0,0,0,1,(1 + 2),"time from mid of se1 90 to end se1 90",0,"",} 
;
 _cvint  _t_exa_rf1se2
= {&t_exa_rf1se2,  0,MAXINT,0,0,0,0,1,(1 + 2),"time from start of se2 90 to mid se2 90",0,"",} 
;
 _cvint  _t_exb_rf1se2
= {&t_exb_rf1se2,  0,MAXINT,0,0,0,0,1,(1 + 2),"time from mid of se2 90 to end se2 90",0,"",} 
;
 _cvint  _tlead_prep
= {&tlead_prep,  0,MAXINT,320  ,0,0,0,1,(1 + 2), "Init deadtime for the prep section",0,"",} 
;
 _cvint  _tseq_prep
= {&tseq_prep,  0,MAXINT,0,0,0,0,1,(1 + 2), "Sequence time for the prep section",0,"",} 
;
 _cvint  _ps2prep_samps
= {&ps2prep_samps,  0,MAXINT,0,0,0,0,1,(1 + 2), "Number of samples to acquire in ps2 with prep.",0,"",} 
;
 _cvint  _avail_pwgz1se1
= {&avail_pwgz1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _avail_pwgz1se2
= {&avail_pwgz1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bw_rf2
= {&bw_rf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bw_rf1se1
= {&bw_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bw_rf1se2
= {&bw_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bw_rf0
= {&bw_rf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off90_rf1se1
= {&off90_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off90_rf1se2
= {&off90_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bd_index
= {&bd_index, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _iso_delay_rf1se1
= {&iso_delay_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _iso_delay_rf1se2
= {&iso_delay_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _preporder
= {&preporder, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _gss_pulse
= {&gss_pulse, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bw_notch
= {&bw_notch, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _notchthick
= {&notchthick, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _sat_factor
= {&sat_factor, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _notch_factor
= {&notch_factor, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _notch_b1
= {&notch_b1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _separation
= {&separation, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _notchpulse
= {&notchpulse, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzrf0
= {&a_gzrf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzrf0
= {&ia_gzrf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf0a
= {&pw_gzrf0a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf0d
= {&pw_gzrf0d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf0
= {&pw_gzrf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_gzrf0
= {&res_gzrf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rf0
= {&a_rf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rf0
= {&ia_rf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rf0
= {&pw_rf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rf0
= {&res_rf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _cyc_rf0
= {&cyc_rf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off_rf0
= {&off_rf0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _alpha_rf0
= {&alpha_rf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _thk_rf0
= {&thk_rf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _gscale_rf0
= {&gscale_rf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _flip_rf0
= {&flip_rf0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzirk
= {&a_gzirk, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzirk
= {&ia_gzirk, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzirka
= {&pw_gzirka, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzirkd
= {&pw_gzirkd, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzirk
= {&pw_gzirk, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzrf1se1
= {&a_gzrf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzrf1se1
= {&ia_gzrf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf1se1a
= {&pw_gzrf1se1a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf1se1d
= {&pw_gzrf1se1d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf1se1
= {&pw_gzrf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_gzrf1se1
= {&res_gzrf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rf1se1
= {&a_rf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rf1se1
= {&ia_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rf1se1
= {&pw_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rf1se1
= {&res_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _cyc_rf1se1
= {&cyc_rf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off_rf1se1
= {&off_rf1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _alpha_rf1se1
= {&alpha_rf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _thk_rf1se1
= {&thk_rf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _gscale_rf1se1
= {&gscale_rf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _flip_rf1se1
= {&flip_rf1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gz1se1
= {&a_gz1se1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gz1se1
= {&ia_gz1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gz1se1a
= {&pw_gz1se1a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gz1se1d
= {&pw_gz1se1d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gz1se1
= {&pw_gz1se1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzrf2
= {&a_gzrf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzrf2
= {&ia_gzrf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf2a
= {&pw_gzrf2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf2d
= {&pw_gzrf2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf2
= {&pw_gzrf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_gzrf2
= {&res_gzrf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rf2
= {&a_rf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rf2
= {&ia_rf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rf2
= {&pw_rf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rf2
= {&res_rf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _cyc_rf2
= {&cyc_rf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off_rf2
= {&off_rf2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _alpha_rf2
= {&alpha_rf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _thk_rf2
= {&thk_rf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _gscale_rf2
= {&gscale_rf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _flip_rf2
= {&flip_rf2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzrf1se2
= {&a_gzrf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzrf1se2
= {&ia_gzrf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf1se2a
= {&pw_gzrf1se2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf1se2d
= {&pw_gzrf1se2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzrf1se2
= {&pw_gzrf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_gzrf1se2
= {&res_gzrf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rf1se2
= {&a_rf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rf1se2
= {&ia_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rf1se2
= {&pw_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rf1se2
= {&res_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _cyc_rf1se2
= {&cyc_rf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off_rf1se2
= {&off_rf1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _alpha_rf1se2
= {&alpha_rf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _thk_rf1se2
= {&thk_rf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _gscale_rf1se2
= {&gscale_rf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _flip_rf1se2
= {&flip_rf1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gz1se2
= {&a_gz1se2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gz1se2
= {&ia_gz1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gz1se2a
= {&pw_gz1se2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gz1se2d
= {&pw_gz1se2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gz1se2
= {&pw_gz1se2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzsek
= {&a_gzsek, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzsek
= {&ia_gzsek, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzseka
= {&pw_gzseka, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzsekd
= {&pw_gzsekd, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzsek
= {&pw_gzsek, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 int  _temp0_RF0_SLOT
;
 int  _temp1_pw_rf0
;
 float  _temp2_a_rf0
;
 float  _temp3_flip_rf0
;
 int  _temp4_res_rf0
;
 int  _temp5_RF0_SLOT
;
 int  _temp6_pw_rf0
;
 float  _temp7_a_rf0
;
 float  _temp8_flip_rf0
;
 int  _temp9_RF0_SLOT
;
 int  _temp10_pw_rf0
;
 float  _temp11_a_rf0
;
 float  _temp12_flip_rf0
;
 int  _temp13_res_rf0
;
 int  _temp14_RF0_SLOT
;
 int  _temp15_pw_rf0
;
 float  _temp16_a_rf0
;
 float  _temp17_flip_rf0
;
 int  _temp18_res_rf0
;
 int  _temp19_RF2_SLOT
;
 int  _temp20_pw_rf2
;
 float  _temp21_a_rf2
;
 float  _temp22_flip_rf2
;
 int  _temp23_res_rf2
;
 int  _temp24_RF1SE1_SLOT
;
 int  _temp25_pw_rf1se1
;
 float  _temp26_a_rf1se1
;
 float  _temp27_flip_rf1se1
;
 int  _temp28_res_rf1se1
;
 int  _temp29_RF1SE2_SLOT
;
 int  _temp30_pw_rf1se2
;
 float  _temp31_a_rf1se2
;
 float  _temp32_flip_rf1se2
;
 int  _temp33_res_rf1se2
;
 int  _temp34_GZRF0_SLOT
;
 int  _temp35_pw_gzrf0a
;
 int  _temp36_pw_gzrf0d
;
 int  _temp37_pw_gzrf0
;
 float  _temp38_a_gzrf0
;
 int  _temp39_GZRF2_SLOT
;
 int  _temp40_pw_gzrf2a
;
 int  _temp41_pw_gzrf2d
;
 int  _temp42_pw_gzrf2
;
 float  _temp43_a_gzrf2
;
 int  _temp44_GZRF1SE1_SLOT
;
 int  _temp45_pw_gzrf1se1a
;
 int  _temp46_pw_gzrf1se1d
;
 int  _temp47_pw_gzrf1se1
;
 float  _temp48_a_gzrf1se1
;
 int  _temp49_GZRF1SE2_SLOT
;
 int  _temp50_pw_gzrf1se2a
;
 int  _temp51_pw_gzrf1se2d
;
 int  _temp52_pw_gzrf1se2
;
 float  _temp53_a_gzrf1se2
;
 int  _temp54_GZ1SE1_SLOT
;
 int  _temp55_pw_gz1se1a
;
 int  _temp56_pw_gz1se1d
;
 int  _temp57_pw_gz1se1
;
 float  _temp58_a_gz1se1
;
 int  _temp59_GZ1SE2_SLOT
;
 int  _temp60_pw_gz1se2a
;
 int  _temp61_pw_gz1se2d
;
 int  _temp62_pw_gz1se2
;
 float  _temp63_a_gz1se2
;
 int  _temp64_GZIRK_SLOT
;
 int  _temp65_pw_gzirka
;
 int  _temp66_pw_gzirkd
;
 int  _temp67_pw_gzirk
;
 float  _temp68_a_gzirk
;
 int  _temp69_GZSEK_SLOT
;
 int  _temp70_pw_gzseka
;
 int  _temp71_pw_gzsekd
;
 int  _temp72_pw_gzsek
;
 float  _temp73_a_gzsek
;
 float  _temp74_a_gzrf0
;
 float  _temp75_a_gzrf0
;
 int  _temp76_pw_gzrf0a
;
 float  _temp77_flip_rf0
;
 float  _temp78_a_gzrf2
;
 int  _temp79_pw_gzrf2a
;
 float  _temp80_flip_rf2
;
 float  _temp81_flip_rf1se1
;
 float  _temp82_a_gzrf1se1
;
 int  _temp83_pw_gzrf1se1d
;
 float  _temp84_flip_rf1se2
;
 float  _temp85_a_gzrf1se2
;
 int  _temp86_pw_gzrf1se2d
;
 int  _temp87_max_ti
;
 int  _temp88_min_tdel
;
 int  _temp89_min_ti
;
 float  _temp90_a_gzrf0
;
 int  _temp91_pw_gzrf0a
;
 int  _temp92_pw_gzrf0d
;
 float  _temp93_a_gzirk
;
 int  _temp94_pw_gzirka
;
 int  _temp95_pw_gzirk
;
 int  _temp96_pw_gzirkd
;
 float  _temp97_a_gzrf1se1
;
 int  _temp98_pw_gzrf1se1a
;
 int  _temp99_pw_gzrf1se1d
;
 float  _temp100_a_gz1se1
;
 int  _temp101_pw_gz1se1a
;
 int  _temp102_pw_gz1se1
;
 int  _temp103_pw_gz1se1d
;
 float  _temp104_a_gzrf2
;
 int  _temp105_pw_gzrf2a
;
 int  _temp106_pw_gzrf2d
;
 float  _temp107_a_gzrf1se2
;
 int  _temp108_pw_gzrf1se2a
;
 int  _temp109_pw_gzrf1se2d
;
 float  _temp110_a_gz1se2
;
 int  _temp111_pw_gz1se2a
;
 int  _temp112_pw_gz1se2
;
 int  _temp113_pw_gz1se2d
;
 float  _temp114_a_gzsek
;
 int  _temp115_pw_gzseka
;
 int  _temp116_pw_gzsek
;
 int  _temp117_pw_gzsekd
;
