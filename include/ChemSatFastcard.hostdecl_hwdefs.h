 _cvint  _GXKCS2_SLOT
= {&GXKCS2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _GYKCS2_SLOT
= {&GYKCS2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _GZKCS2_SLOT
= {&GZKCS2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _RFCSSAT1_SLOT
= {&RFCSSAT1_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _RFCSSAT2_SLOT
= {&RFCSSAT2_SLOT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _bw_rfcssat1
= {&bw_rfcssat1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rfcssat1
= {&pw_rfcssat1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rfcssat2
= {&pw_rfcssat2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _off_rfcssat1
= {&off_rfcssat1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rfcssat1
= {&ia_rfcssat1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rfcssat1
= {&a_rfcssat1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _cyc_rfcssat1
= {&cyc_rfcssat1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rfcssat2
= {&ia_rfcssat2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rfcssat2
= {&a_rfcssat2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _flip_rfcssat1
= {&flip_rfcssat1,      -180.0, 1000.0, 0,0,0,0,1, (1 + 2), "flip angle of chemsat pulse in Hz",0,"",} 
;
 _cvfloat  _flip_rfcssat2
= {&flip_rfcssat2,      -180.0, 1000.0, 0,0,0,0,1, (1 + 2), "flip angle of 1st chemsat pulse in Hz",0,"",} 
;
 _cvfloat  _gscale_rfcssat1
= {&gscale_rfcssat1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _min_cssat_ti
= {&min_cssat_ti,      -MAXINT, MAXINT, 0,0,0,0,1, (1 + 2), " minimum cssat prep time",0,"",} 
;
 _cvint  _min_cssat_ti_rnd
= {&min_cssat_ti_rnd,      -MAXINT, MAXINT, 0,0,0,0,1, (1 + 2), " minimum cssat prep time rounded up",0,"",} 
;
 _cvint  _cssat_ti
= {&cssat_ti,      20  , 2000000, 0,0,0,0,1, (1 + 2), "Inversion time for Chem Sat. min_cssat_ti",0,"",} 
;
 _cvint  _cssat_ti_def
= {&cssat_ti_def,      20  , 2000000, 0,0,0,0,1, (1 + 2), " default Inversion time for Chem Sat.",0,"",} 
;
 _cvint  _chemsat_type
= {&chemsat_type,      0, 0, 0,0,0,0,1, (1 + 2), "ChemSatPulse cv: 0=sinc; 1=csm; 2=8ms min.ph.; "                    "4=16cinv; 5=12cinv175.",0,"",} 
;
 _cvint  _dospecir_flag
= {&dospecir_flag,      0, MAXINT, 0,0,0,0,1, (1 + 2), "on(=1) if double specir is on.",0,"",} 
;
 _cvint  _specir_flag
= {&specir_flag,      0, MAXINT, 0,0,0,0,1, (1 + 2), "on(=1) if sequential fat or water sat is on.",0,"",} 
;
 _cvint  _fccs_flag
= {&fccs_flag,      0, MAXINT, 0,0,0,0,1, (1 + 2), "on(=1) if fastcard chem sat is on.",0,"",} 
;
 _cvint  _time_ssi_cssat
= {&time_ssi_cssat,      0, MAXINT, 250000,0,0,0,1, (1 + 2), "time from eos to ssi in intern trig for chemsat",0,"",} 
;
 _cvfloat  _area_gxkcs2
= {&area_gxkcs2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _area_gykcs2
= {&area_gykcs2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _area_gzkcs2
= {&area_gzkcs2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rfcssat2
= {&res_rfcssat2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rfcssat1
= {&res_rfcssat1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxkcs2
= {&a_gxkcs2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxkcs2
= {&ia_gxkcs2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxkcs2a
= {&pw_gxkcs2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxkcs2d
= {&pw_gxkcs2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxkcs2
= {&pw_gxkcs2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gykcs2
= {&a_gykcs2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gykcs2
= {&ia_gykcs2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gykcs2a
= {&pw_gykcs2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gykcs2d
= {&pw_gykcs2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gykcs2
= {&pw_gykcs2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gzkcs2
= {&a_gzkcs2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gzkcs2
= {&ia_gzkcs2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzkcs2a
= {&pw_gzkcs2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzkcs2d
= {&pw_gzkcs2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gzkcs2
= {&pw_gzkcs2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 int  _temp0_RFCSSAT1_SLOT
;
 int  _temp1_pw_rfcssat1
;
 float  _temp2_a_rfcssat1
;
 float  _temp3_flip_rfcssat1
;
 int  _temp4_res_rfcssat1
;
 int  _temp5_RFCSSAT2_SLOT
;
 int  _temp6_pw_rfcssat2
;
 float  _temp7_a_rfcssat2
;
 float  _temp8_flip_rfcssat2
;
 int  _temp9_res_rfcssat2
;
 int  _temp10_GXKCS2_SLOT
;
 int  _temp11_pw_gxkcs2a
;
 int  _temp12_pw_gxkcs2d
;
 int  _temp13_pw_gxkcs2
;
 float  _temp14_a_gxkcs2
;
 int  _temp15_GYKCS2_SLOT
;
 int  _temp16_pw_gykcs2a
;
 int  _temp17_pw_gykcs2d
;
 int  _temp18_pw_gykcs2
;
 float  _temp19_a_gykcs2
;
 int  _temp20_GZKCS2_SLOT
;
 int  _temp21_pw_gzkcs2a
;
 int  _temp22_pw_gzkcs2d
;
 int  _temp23_pw_gzkcs2
;
 float  _temp24_a_gzkcs2
;
 int  _temp25_pw_rfcssat2
;
 float  _temp26_a_rfcssat2
;
 float  _temp27_flip_rfcssat2
;
 int  _temp28_pw_rfcssat1
;
 float  _temp29_a_rfcssat1
;
 float  _temp30_flip_rfcssat1
;
 int  _temp31_res_rfcssat1
;
 int  _temp32_pw_rfcssat1
;
 float  _temp33_a_rfcssat1
;
 int  _temp34_res_rfcssat1
;
 int  _temp35_pw_rfcssat1
;
 float  _temp36_a_rfcssat1
;
 float  _temp37_flip_rfcssat1
;
 int  _temp38_res_rfcssat1
;
 int  _temp39_pw_rfcssat1
;
 float  _temp40_a_rfcssat1
;
 float  _temp41_flip_rfcssat1
;
 int  _temp42_res_rfcssat1
;
 int  _temp43_pw_rfcssat2
;
 float  _temp44_a_rfcssat2
;
 float  _temp45_flip_rfcssat2
;
 int  _temp46_res_rfcssat2
;
 int  _temp47_res_rfcssat2
;
 int  _temp48_res_rfcssat1
;
 int  _temp49_res_rfcssat1
;
 int  _temp50_res_rfcssat1
;
 float  _temp51_a_gxkcs2
;
 int  _temp52_pw_gxkcs2a
;
 int  _temp53_pw_gxkcs2
;
 int  _temp54_pw_gxkcs2d
;
 float  _temp55_a_gykcs2
;
 int  _temp56_pw_gykcs2a
;
 int  _temp57_pw_gykcs2
;
 int  _temp58_pw_gykcs2d
;
 float  _temp59_a_gzkcs2
;
 int  _temp60_pw_gzkcs2a
;
 int  _temp61_pw_gzkcs2
;
 int  _temp62_pw_gzkcs2d
;
