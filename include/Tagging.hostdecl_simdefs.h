 _cvint  _tagging_type
= {&tagging_type, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _taggingflip
= {&taggingflip,      0.0, 180.0, 180.0,0,0,0,1, (1 + 2), "TAGGING flip angle",0,"",} 
;
 _cvfloat  _flip_rftagging1
= {&flip_rftagging1,      0.0, 180.0, 180.0,0,0,0,1, (1 + 2), "TAGGING flip angle (1D)",0,"",} 
;
 _cvfloat  _flip_rftagging2
= {&flip_rftagging2,      0.0, 180.0, 180.0,0,0,0,1, (1 + 2), "TAGGING flip angle (2D)",0,"",} 
;
 _cvfloat  _act_tagging1_flip
= {&act_tagging1_flip,      0.0, 180.0, 180.0,0,0,0,1, (1 + 2), "Actual TAGGING flip angle (1D)",0,"",} 
;
 _cvfloat  _act_tagging2_flip
= {&act_tagging2_flip,      0.0, 180.0, 180.0,0,0,0,1, (1 + 2), "Actual TAGGING flip angle (2D)",0,"",} 
;
 _cvfloat  _taggingangle
= {&taggingangle,      -180.0, 180.0, 45.0,0,0,0,1, (1 + 2), "TAGGING grid orientation angle",0,"",} 
;
 _cvint  _tagging_dda
= {&tagging_dda,      0, MAXINT, 1,0,0,0,1, (1 + 2), "Number of disdaqs after TAGGING",0,"",} 
;
 _cvfloat  _tagging_spoiler
= {&tagging_spoiler,      0.0, 50.0, 3.0,0,0,0,1, (1 + 2), "Spoiler amplitude",0,"",} 
;
 _cvint  _pos_spoiler
= {&pos_spoiler,      0, 100000000, 280,0,0,0,1, (1 + 2), "Start of spoiler",0,"",} 
;
 _cvint  _min_tagginggrad_space
= {&min_tagginggrad_space, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _min_tagginggrad_space_grid
= {&min_tagginggrad_space_grid, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _tlead_tagging
= {&tlead_tagging, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _inc_tagging_heat
= {&inc_tagging_heat, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _tagpw_scale
= {&tagpw_scale,      1.0, 50.0, 1.0,0,0,0,1, (1 + 2), "Pulse width scaling factor for power monitor",0,"",} 
;
 _cvint  _pw_gxtagging1_tot
= {&pw_gxtagging1_tot, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging1_tot
= {&pw_gytagging1_tot, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging2_tot
= {&pw_gxtagging2_tot, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging2_tot
= {&pw_gytagging2_tot, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging1_tot
= {&pw_gztagging1_tot, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging2_tot
= {&pw_gztagging2_tot, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _tagging_tr
= {&tagging_tr, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _tagging_tr_grid
= {&tagging_tr_grid, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _grid_time
= {&grid_time, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _tagging_option_key_status
= {&tagging_option_key_status,      0, 1, 0,0,0,0,1, (1 + 2), "Tagging option key flag.",0,"",} 
;
 _cvfloat  _a_rftagging1
= {&a_rftagging1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rftagging1
= {&ia_rftagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rftagging1
= {&pw_rftagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rftagging1
= {&res_rftagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _per_rftagging1
= {&per_rftagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging1
= {&a_gxtagging1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging1a
= {&a_gxtagging1a, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging1b
= {&a_gxtagging1b, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging1
= {&ia_gxtagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging1wa
= {&ia_gxtagging1wa, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging1wb
= {&ia_gxtagging1wb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging1a
= {&pw_gxtagging1a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging1d
= {&pw_gxtagging1d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging1
= {&pw_gxtagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging1
= {&a_gytagging1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging1a
= {&a_gytagging1a, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging1b
= {&a_gytagging1b, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging1
= {&ia_gytagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging1wa
= {&ia_gytagging1wa, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging1wb
= {&ia_gytagging1wb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging1a
= {&pw_gytagging1a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging1d
= {&pw_gytagging1d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging1
= {&pw_gytagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gztagging1
= {&a_gztagging1, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gztagging1
= {&ia_gztagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging1a
= {&pw_gztagging1a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging1d
= {&pw_gztagging1d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging1
= {&pw_gztagging1, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rftagging0
= {&a_rftagging0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rftagging0
= {&ia_rftagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rftagging0
= {&pw_rftagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rftagging0
= {&res_rftagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _per_rftagging0
= {&per_rftagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging0
= {&a_gxtagging0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging0a
= {&a_gxtagging0a, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging0b
= {&a_gxtagging0b, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging0
= {&ia_gxtagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging0wa
= {&ia_gxtagging0wa, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging0wb
= {&ia_gxtagging0wb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging0a
= {&pw_gxtagging0a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging0d
= {&pw_gxtagging0d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging0
= {&pw_gxtagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging0
= {&a_gytagging0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging0a
= {&a_gytagging0a, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging0b
= {&a_gytagging0b, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging0
= {&ia_gytagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging0wa
= {&ia_gytagging0wa, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging0wb
= {&ia_gytagging0wb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging0a
= {&pw_gytagging0a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging0d
= {&pw_gytagging0d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging0
= {&pw_gytagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gztagging0
= {&a_gztagging0, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gztagging0
= {&ia_gztagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging0a
= {&pw_gztagging0a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging0d
= {&pw_gztagging0d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging0
= {&pw_gztagging0, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_rftagging2
= {&a_rftagging2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_rftagging2
= {&ia_rftagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_rftagging2
= {&pw_rftagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _res_rftagging2
= {&res_rftagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _per_rftagging2
= {&per_rftagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging2
= {&a_gxtagging2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging2a
= {&a_gxtagging2a, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gxtagging2b
= {&a_gxtagging2b, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging2
= {&ia_gxtagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging2wa
= {&ia_gxtagging2wa, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gxtagging2wb
= {&ia_gxtagging2wb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging2a
= {&pw_gxtagging2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging2d
= {&pw_gxtagging2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gxtagging2
= {&pw_gxtagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging2
= {&a_gytagging2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging2a
= {&a_gytagging2a, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gytagging2b
= {&a_gytagging2b, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging2
= {&ia_gytagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging2wa
= {&ia_gytagging2wa, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gytagging2wb
= {&ia_gytagging2wb, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging2a
= {&pw_gytagging2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging2d
= {&pw_gytagging2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gytagging2
= {&pw_gytagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvfloat  _a_gztagging2
= {&a_gztagging2, -((float)3.40282346638528860e+38),((float)3.40282346638528860e+38),0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _ia_gztagging2
= {&ia_gztagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging2a
= {&pw_gztagging2a, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging2d
= {&pw_gztagging2d, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _pw_gztagging2
= {&pw_gztagging2, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 int  _temp0_pw_rftagging0
;
 float  _temp1_a_rftagging0
;
 float  _temp2_act_tagging1_flip
;
 int  _temp3_pw_rftagging1
;
 float  _temp4_a_rftagging1
;
 float  _temp5_act_tagging1_flip
;
 int  _temp6_pw_rftagging2
;
 float  _temp7_a_rftagging2
;
 float  _temp8_act_tagging2_flip
;
 int  _temp9_pw_gxtagging0a
;
 int  _temp10_pw_gxtagging0d
;
 int  _temp11_pw_gxtagging0
;
 float  _temp12_a_gxtagging0
;
 int  _temp13_pw_gytagging0a
;
 int  _temp14_pw_gytagging0d
;
 int  _temp15_pw_gytagging0
;
 float  _temp16_a_gytagging0
;
 int  _temp17_pw_gxtagging1a
;
 int  _temp18_pw_gxtagging1d
;
 int  _temp19_pw_gxtagging1
;
 float  _temp20_a_gxtagging1
;
 int  _temp21_pw_gytagging1a
;
 int  _temp22_pw_gytagging1d
;
 int  _temp23_pw_gytagging1
;
 float  _temp24_a_gytagging1
;
 int  _temp25_pw_gxtagging2a
;
 int  _temp26_pw_gxtagging2d
;
 int  _temp27_pw_gxtagging2
;
 float  _temp28_a_gxtagging2
;
 int  _temp29_pw_gytagging2a
;
 int  _temp30_pw_gytagging2d
;
 int  _temp31_pw_gytagging2
;
 float  _temp32_a_gytagging2
;
 int  _temp33_pw_gztagging0a
;
 int  _temp34_pw_gztagging0d
;
 int  _temp35_pw_gztagging0
;
 float  _temp36_a_gztagging0
;
 int  _temp37_pw_gztagging1a
;
 int  _temp38_pw_gztagging1d
;
 int  _temp39_pw_gztagging1
;
 float  _temp40_a_gztagging1
;
 int  _temp41_pw_gztagging2a
;
 int  _temp42_pw_gztagging2d
;
 int  _temp43_pw_gztagging2
;
 float  _temp44_a_gztagging2
;
 float  _temp45_a_gxtagging1
;
 int  _temp46_pw_gxtagging1a
;
 int  _temp47_pw_gxtagging1
;
 int  _temp48_pw_gxtagging1d
;
 float  _temp49_a_gytagging1
;
 int  _temp50_pw_gytagging1a
;
 int  _temp51_pw_gytagging1
;
 int  _temp52_pw_gytagging1d
;
 float  _temp53_a_gztagging1
;
 int  _temp54_pw_gztagging1a
;
 int  _temp55_pw_gztagging1
;
 int  _temp56_pw_gztagging1d
;
 float  _temp57_a_gxtagging0
;
 int  _temp58_pw_gxtagging0a
;
 int  _temp59_pw_gxtagging0
;
 int  _temp60_pw_gxtagging0d
;
 float  _temp61_a_gytagging0
;
 int  _temp62_pw_gytagging0a
;
 int  _temp63_pw_gytagging0
;
 int  _temp64_pw_gytagging0d
;
 float  _temp65_a_gztagging0
;
 int  _temp66_pw_gztagging0a
;
 int  _temp67_pw_gztagging0
;
 int  _temp68_pw_gztagging0d
;
 float  _temp69_a_gxtagging2
;
 int  _temp70_pw_gxtagging2a
;
 int  _temp71_pw_gxtagging2
;
 int  _temp72_pw_gxtagging2d
;
 float  _temp73_a_gytagging2
;
 int  _temp74_pw_gytagging2a
;
 int  _temp75_pw_gytagging2
;
 int  _temp76_pw_gytagging2d
;
 float  _temp77_a_gztagging2
;
 int  _temp78_pw_gztagging2a
;
 int  _temp79_pw_gztagging2
;
 int  _temp80_pw_gztagging2d
;
