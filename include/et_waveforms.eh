@pulsedef

EP_TRAIN2( et_pos:0, et_vps:1, et_offset:0, et_vtot,
           et_recvr_type:0, et_filt_slot:4, et_dab_type:0,
           et_dacqdelay:0, et_samp_period:1, et_dab_off:0,
                 et_xtr_off:0, et_acq_prefills:DEFPREFILLS, et_loggrd) {
 
/* EP_TRAIN generates a blipped echo planar sequence with
   optional readout crushers.  Readout is generated on logical XGRAD,
   blips on logical YGRAD.  Data acquisition is generated for standard
   or fast receivers, with control of DAB packet type.

   This macro can be called recursively.  Memory allocation is done once
   on the first interation of the macro (i.e. when et_offset is set to zero).
   The allocation is based on the value of et_vtot; the user is responsibile
   for setting this equal to the views-per-shot (et_vps) times the total
   number of iterations.  An offset argument is provided to allow explicit
   labeling of each Exciter/Receiver(/DAB) packet.

   Argument definitions:                           
   et_pos         -  absolute time position of first non-zero pulsewidth on X
   et_vps         -  echo_train length 
   et_offset      -  numeric offset for view labeling, typically n*et_vps,
                     where n is the current iteration
   et_vtot        -  Total number of frames (for memory allocation).
                     Include number of views for all iterations
   et_recvr_type  -  0: standard receiver, 1: research fast receiver
   et_filt_slot   -  optional filter slot (0-7)
   et_dab_type    -  0: don't create a dab packet
                     1: create a standard dab (1ms prior to RBA),
   et_dacqdelay   -  delay of data acquisition relative to begin of gxw pulse
                     (after gxwl if non-zero) in usec
   et_samp_period -  sample period for fast receiver in usec
   et_dab_off     -  0: default position (1ms prior to RBA),
                     x: time position offset of xtr packet relative to RBA
   et_xtr_off     -  0: default position (100us prior to RBA),
                     x: time position offset of dab packet relative to RBA
   et_acq_prefills-  number of digital filter prefills (standard receiver)
   et_loggrd      -  logical gradient structure name
 
   Pulse attribute CVs are declared (see CV section below).

   The following pulse widths can be set to zero if desired:
   pwgxwl, pwgxwr, pw_gxgap.
 
   Combined Exciter/Receiver(/DAB) packets are labeled as echoxxxx (where
   xxxx ranges from 0000 to 9999).  This is useful for programming exciter
   phase and frequency on a per-view basis.
 
*/
 
cv:{
 
  float a_gxw;
  float a_gyb;
  int   ia_gxw;
  int   ia_gyb;
  int   pw_gxwl;
  int   pw_gxw;
  int   pw_gxwr;
  int   pw_gxwad;
  int   pw_gxgap;
  int   pw_gyba;
  int   pw_gyb;
  int   pw_gybd;
  int   pw_gxwa;
  int   pw_gxwd;
  int   filter_echo1;

}
var:{
 
 
  WF_PULSE gxwa = INITPULSE;
  WF_PULSE gxw = INITPULSE;
  WF_PULSE gxwd = INITPULSE;

  WF_PULSE gxgap = INITPULSE;
 
  WF_PULSE gyb = INITPULSE;
  WF_PULSE gyba = INITPULSE;
  WF_PULSE gybd = INITPULSE;

   WF_PULSE gxwaa = INITPULSE;
   WF_PULSE gxwdd = INITPULSE;
   WF_PULSE gxwad = INITPULSE;

  WF_PULSE *echotrain = NULL;             /* added = NULL -JFS */
  WF_PULSE echo1;
}
 
insert: cvinit => {
}
 
insert: predownload => {
  ia_gxw = a_gxw * max_pg_wamp / $[et_loggrd].tx;
  ia_gyb = a_gyb * max_pg_iamp / $[et_loggrd].ty;
}
 
subst:{
  {
        int psd_gxwcnt;
        int psd_pulsepos;
        int psd_eparity;
        long psd_epxtroff;
        long psd_epdaboff;
 
        float psd_etbetax, psd_etbetay;

        short epstring_length=EPSTRING_LENGTH;
        char psd_epstring[EPSTRING_LENGTH];

        psd_pulsepos = $[et_pos];           
 
        /* allocate on 1st pass only  */
        if ( $[et_offset] == 0 ) {
            
            /* JAP make sure to free this memory if it is already
               been allocated */
            if (echotrain != NULL && echotrain != &echo1) {   
                FreeNode(echotrain);   /* ?? could free &echo1, may be removed -JFS */
            }

            if ($[et_vps] == 1) {
                echotrain = &echo1;
            } else {
                echotrain = (WF_PULSE *)AllocNode(($[et_vtot] + 3) * 
                                                  sizeof(WF_PULSE));                                            
            }

            /* JAP Reinitialize number of instructions to zero. This
               fix bug when prescribing an etl > 1 scan followed by an
               etl = 1 scan.
               This is the same thing that is done in the
               FreeUpInstr() function
            */
            echotrain[0].ninsts = 0;
            echotrain[0].wave_addr = 0;
            echotrain[0].assoc_pulse = NULL;


        }
 

    pulsename(&gxwa, "gxwa");
    pulsename(&gxw, "gxw");
    pulsename(&gxwd, "gxwd");
 
    pulsename(&gxgap, "gxgap");

    pulsename(&gyba, "gyba");
    pulsename(&gyb, "gyb");
    pulsename(&gybd, "gybd");
 
    pulsename(&gxwaa, "gxwaa");
    pulsename(&gxwdd, "gxwdd");
    pulsename(&gxwad, "gxwad");
 
        getbeta(&psd_etbetax, XGRAD, &$[et_loggrd]);
        getbeta(&psd_etbetay, YGRAD, &$[et_loggrd]);
 
        /*********** JAP 10/10/97 ********************/
        createramp(&gxwa, XGRAD, pw_gxwa, 0, max_pg_wamp,
                                  (short)(maxGradRes*(pw_gxwa)/GRAD_UPDATE_TIME),
                                   psd_etbetax);
        createinstr(&gxwa, (long)(psd_pulsepos - pw_gxwa), pw_gxwa, ia_gxw);

        /*********************************************/

        createconst(&gxw, XGRAD, pw_gxwl+pw_gxw+pw_gxwr, max_pg_wamp);
        createinstr(&gxw, (long)psd_pulsepos,
                                pw_gxwl+pw_gxw+pw_gxwr, ia_gxw);
        psd_pulsepos += pw_gxwl;
 
        if ($[et_vps] == 1) {
            sprintf(psd_epstring, "echo1");
        } else {
            sprintf(psd_epstring, "echo%04d", $[et_offset]);
        }       

        pulsename(&(echotrain[$[et_offset]]), psd_epstring);
 
        if ($[et_dab_off] == 0)
          psd_epdaboff = 0;
        else
          psd_epdaboff = (long)(psd_pulsepos + $[et_dacqdelay] + $[et_dab_off]);            
        if ($[et_xtr_off] == 0)
          psd_epxtroff = 0;
        else
          psd_epxtroff = (long)(psd_pulsepos + $[et_dacqdelay] + $[et_xtr_off]);            
 
        epiacqq(&(echotrain[$[et_offset]]),
                        (long)(psd_pulsepos + $[et_dacqdelay]),
                        psd_epdaboff, psd_epxtroff,
                        (long)$[et_filt_slot], (long)TYPRECVALL, (TYPDAB_PACKETS)DABNORM,
                        (long)$[et_acq_prefills],(long)$[et_recvr_type],
                        (long)$[et_dab_type]);

        if (($[et_offset] == 0) && ($[et_vps] != 1)) {
            echo1 = echotrain[$[et_offset]];
        }

        psd_pulsepos += pw_gxw + pw_gxwr;      
 
        psd_eparity = 1;
        for (psd_gxwcnt = 2; psd_gxwcnt <= $[et_vps]; psd_gxwcnt++) {
          psd_eparity *= -1;
 
          createramp(&gyba, YGRAD, pw_gyba, 0, max_pg_wamp,
                                 (short)((maxGradRes*pw_gyba)/GRAD_UPDATE_TIME), psd_etbetay);
          createinstr(&gyba, (long)(psd_pulsepos + pw_gxwad + pw_gxgap/2 -
                                                                (pw_gyba + pw_gyb/2)), pw_gyba, ia_gyb);
 
          if (pw_gyb >= GRAD_UPDATE_TIME) {
                createconst(&gyb, YGRAD, pw_gyb, max_pg_wamp);
                createinstr(&gyb, (long)(psd_pulsepos + pw_gxwad + pw_gxgap/2 -
                                                                pw_gyb/2), pw_gyb, ia_gyb);
          }
           
          createramp(&gybd, YGRAD, pw_gybd, max_pg_wamp, 0,
                                 (short)((maxGradRes*pw_gybd)/GRAD_UPDATE_TIME), psd_etbetay);
          createinstr(&gybd, (long)(psd_pulsepos + pw_gxwad + pw_gxgap/2 +
                                                                pw_gyb/2), pw_gybd, ia_gyb);

          linkpulses(3,&gyb,&gyba,&gybd);   /* ?? gyb is not created if pw_gyb<4 usec */
            
          if (pw_gxgap == 0) {    /* Combine decay and attack ramps */
                createramp(&gxwad, XGRAD, 2*pw_gxwad, max_pg_wamp, -max_pg_wamp,
                                   (short)(maxGradRes*(2*pw_gxwad)/GRAD_UPDATE_TIME),
                                   psd_etbetax);
                createinstr(&gxwad, (long)psd_pulsepos, 2*pw_gxwad, psd_eparity*
                                        (-ia_gxw));
                psd_pulsepos += 2*pw_gxwad;
 
          } else {
                createramp(&gxwdd, XGRAD, pw_gxwad, -max_pg_wamp, 0,
                                   (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME),
                                   psd_etbetax);
                createinstr(&gxwdd, (long)psd_pulsepos, pw_gxwad, psd_eparity*
                                        ia_gxw);
                psd_pulsepos += pw_gxwad;

                createconst(&gxgap, XGRAD, pw_gxgap, 0);
                createinstr(&gxgap, (long)psd_pulsepos,
                                        pw_gxgap, 0);
                psd_pulsepos += pw_gxgap;
 
                createramp(&gxwaa, XGRAD, pw_gxwad, 0, max_pg_wamp,
                                   (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME),
                                   psd_etbetax);
                createinstr(&gxwaa, (long)psd_pulsepos, pw_gxwad, psd_eparity*
                                        ia_gxw);
                psd_pulsepos += pw_gxwad;
          }
 
          createconst(&gxw, XGRAD, pw_gxwl+pw_gxw+pw_gxwr, max_pg_wamp);
          createinstr(&gxw, (long)psd_pulsepos,
                                  pw_gxwl+pw_gxw+pw_gxwr, psd_eparity*ia_gxw);
          psd_pulsepos += pw_gxwl;

          sprintf(psd_epstring, "echo%04d", psd_gxwcnt-1 + $[et_offset]);
          pulsename(&(echotrain[psd_gxwcnt-1+$[et_offset]]), psd_epstring);

          if ($[et_dab_off] == 0)                                           
                psd_epdaboff = 0;
          else
                psd_epdaboff = (long)(psd_pulsepos + $[et_dacqdelay] + $[et_dab_off]);

          if ($[et_xtr_off] == 0)
                psd_epxtroff = 0;
          else
                psd_epxtroff = (long)(psd_pulsepos + $[et_dacqdelay] +
                                                          $[et_xtr_off]);

          epiacqq(&(echotrain[psd_gxwcnt-1+$[et_offset]]),                
                          (long)(psd_pulsepos + $[et_dacqdelay]),
                          psd_epdaboff, psd_epxtroff,
                          (long)$[et_filt_slot], (long)TYPRECVALL, (TYPDAB_PACKETS)DABNORM,
                          (long)$[et_acq_prefills],(long)$[et_recvr_type],
                          (long)$[et_dab_type]);

          psd_pulsepos += pw_gxw + pw_gxwr;      

        } /* for (psd_gxwcnt = 2; psd_gxwcnt <= $[et_vps]; psd_gxwcnt++) */

        /*********** JAP 10/10/97 ********************/
        createramp(&gxwd, XGRAD, pw_gxwd, max_pg_wamp, 0,
                   (short)(maxGradRes*(pw_gxwd)/GRAD_UPDATE_TIME),
                   psd_etbetax);
        createinstr(&gxwd, (long)psd_pulsepos, pw_gxwd, psd_eparity*
                    ia_gxw);
        psd_pulsepos += pw_gxwd;

        if ($[et_vps] == 1) {
            linkpulses(3, &gxw, &gxwa, &gxwd);
        }

        /*********************************************/

 
	}
}

}

/* merged 55 bch into vmx.  YH 10/13/94 */
HSCDAB(hsdab_name, hsdab_pos, acq_dabtype:DABNORM) {
 
/* HSDAB creates a hyperscan dab packet at the specified position.
 
   Argument definitions:
   hsdab_name      -  name of packet
   hsdab_pos       -  absolute time position of start of hs dab packet
*/
 
cv:{   
}
insert: cvinit =>{
}
insert: predownload => {
}
var:{
  WF_PULSE $[hsdab_name] = INITPULSE;
}    
subst:{
  {
    pulsename(&$[hsdab_name],"$[hsdab_name]");

        createhscdab(&$[hsdab_name], (long)($[hsdab_pos]), (TYPDAB_PACKETS)($[acq_dabtype]));
  }
}

}
