 _cvint  _dummy_temp
= {&dummy_temp, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _slq_per_sat
= {&slq_per_sat,  0,MAXINT,4,0,0,0,1,(1 + 2), "no. of slices per sp and chem sat pulses",0,"",} 
;
 _cvint  _slq_per_spsat
= {&slq_per_spsat,  0,MAXINT,4,0,0,0,1,(1 + 2), "no. of slices per sp sat pulses",0,"",} 
;
 _cvint  _slq_per_cssat
= {&slq_per_cssat,  0,MAXINT,4,0,0,0,1,(1 + 2), "no. of slices per chem sat pulses",0,"",} 
;
 _cvint  _test_flag
= {&test_flag, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
 _cvint  _maxsatcount
= {&maxsatcount,  0,MAXINT,1,0,0,0,1,(1 + 2), "maximum no. of sat pulses (spatial or chem sat) played in each TR",0,"",} 
;
 _cvint  _satcount
= {&satcount,  0,MAXINT,1,0,0,0,1,(1 + 2), "no. of sat pulses played in each TR",0,"",} 
;
 _cvint  _satinterval
= {&satinterval,  0,MAXINT,100000,0,0,0,1,(1 + 2), "Time interval between sat pulses",0,"",} 
;
 _cvfloat  _avesat_per_slq
= {&avesat_per_slq,  0,((float)3.40282346638528860e+38),1.0,0,0,0,1,(1 + 2), "average amount of the sat applied per slice.",0,"",} 
;
 _cvint  _NUMRFSAT
= {&NUMRFSAT, -MAXINT,MAXINT,0,0,0,0,1,(1 + 2),"",0,"",} 
;
