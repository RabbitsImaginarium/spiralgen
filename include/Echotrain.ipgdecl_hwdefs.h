 WF_PULSE  setup_frec 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 SEQUENCE_ENTRIES  off_seq_initfastrec
;
 WF_PULSE  seq_initfastrec
;
 int  idx_seq_initfastrec
;
 WF_PULSE  ssp_ungated_wait 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 SEQUENCE_ENTRIES  off_seq_ungated_wait
;
 WF_PULSE  seq_ungated_wait
;
 int  idx_seq_ungated_wait
;
 WF_PULSE  wgz 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  hyperdab 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  wssp 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  sspdelay 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  eta_delay1 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  wgx 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  gxka 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  gxk 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  gxkd 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  wgy 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  wssps 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  gld_buf 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  eta_delay2 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 WF_PULSE  fast_pass_pulse 
= {0,0,-1, 2, PSDREUSEP, SSPUNKN, 0, 0, 0} 
;
 int  hsdabmask
;
 int  etcnt
;
 int  rspia_gyboc[512]
;
 int  rspshts
;
 int  shot
;
 int  dabshot
;
 int  acq_echotrain
;
 int  iarf1
;
 int  unfull_hb
;
 int  full_hb
;
 int  last_full
;
 int  hb
;
 int  eta_dt 
= 0 
;
 int  eta_force 
= 0 
;
 int  eta_scans2wait 
= 0 
;
 int  rspungated
;
