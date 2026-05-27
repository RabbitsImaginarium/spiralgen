 _cvint  _rsamp_time
= {&rsamp_time,      4  , 1000000, 10000,0,0,0,1, (1 + 2), "Time interval to sample resp. waveform", 0,"",} 
;
 _cvint  _max_resp_wait
= {&max_resp_wait,      0, 120000000, 10000000,0,0,0,1, (1 + 2), "Max time to wait for resp. trigger", 0,"",} 
;
 _cvint  _debug_rg
= {&debug_rg,      0, 1, 0,0,0,0,1, (1 + 2), "Debug flag for Respiratory Gating", 0,"",} 
;
 _cvint  _oprtpoint0
= {&oprtpoint0,      0, 100, 0,0,0,0,1, (1 + 2), "Offset from resp. trigger point to start dda", 0,"",} 
;
