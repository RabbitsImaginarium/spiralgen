@pulsedef

/* changed cvs from shorts to ints *//* changed for 5.5. YH 10/13/94 */
ACQUIREDATA(acq_name, acq_pos, dab_pos:DEFAULTPOS, xtr_pos:DEFAULTPOS,
                  acq_recvfilter:1, acq_recvnum:0, acq_dabtype:DABNORM,
                  acq_prefills:DEFPREFILLS){
cv:{
  int filter_$[acq_name];
  int rcvr_$[acq_name];
  int prefill_$[acq_name];
}
insert: cvinit =>{
  filter_$[acq_name] = $[acq_recvfilter];
  rcvr_$[acq_name] = $[acq_recvnum];
  prefill_$[acq_name] = DEFPREFILLS;
}
insert: predownload => {
}
var:{
  WF_PULSE $[acq_name] = INITPULSE;
}    
subst:{
  {
    pulsename(&$[acq_name],"$[acq_name]");
    acqq(&$[acq_name], (long)($[acq_pos]),(long)($[dab_pos]),
        (long)($[xtr_pos]),(long)filter_$[acq_name],
        (long)rcvr_$[acq_name],
        (TYPDAB_PACKETS)$[acq_dabtype], (long)$[acq_prefills]);
  }
}
}

ATTENUATOR(atten_name, atten_pos){
var:{
  WF_PULSE $[atten_name] = INITPULSE;
}
subst:{
  {
  pulsename(&$[atten_name],"$[atten_name]");
  createatten(&$[atten_name], (long)($[atten_pos]));
}
}
}

CONST(cnst_wgname,cnst_name,cnst_pos,cnst_dur,cnst_amp,cnst_loggrd) {
cv:{
  float a_$[cnst_name];
  int ia_$[cnst_name];
  int pw_$[cnst_name];
}
insert:  cvinit => {
  a_$[cnst_name] = $[cnst_amp];
  pw_$[cnst_name] = $[cnst_dur];
}
var:{
  WF_PULSE $[cnst_name] = INITPULSE;
}
insert: predownload => {
{
  float target;
  gettarget(&target, $[cnst_wgname], &$[cnst_loggrd]);
  ia_$[cnst_name] = (a_$[cnst_name] / target) * MAX_PG_IAMP;
}
}
subst:{
  {
    pulsename(&$[cnst_name],"$[cnst_name]");
    createconst(&$[cnst_name],$[cnst_wgname],pw_$[cnst_name],MAX_PG_WAMP);
    createinstr( &$[cnst_name],(long)($[cnst_pos]),
		pw_$[cnst_name],ia_$[cnst_name]);
    if (($[cnst_wgname]==TYPRHO1)||($[cnst_wgname]==TYPRHO2))
      {
	addrfbits(&$[cnst_name],0,(long)($[cnst_pos]),pw_$[cnst_name]);
      }
  }
}
}

/* merged 5.5 bch into vmx. YH 10/13/94 */
EFFSLICESELZ(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
                 slsel_cycles:1.0,slsel_usegrad:1,
                         res_gz,extern_grad_file, slsel_userf:1, res_rf,
                 extern_rf_file, slsel_usetheta:0, slsel_define:1,
                         slsel_loggrd, slsel_tune:0){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
  float a_theta$[slsel_name];
  int ia_theta$[slsel_name];
  int pw_theta$[slsel_name];
  int res_theta$[slsel_name];
  int off_theta$[slsel_name] = 0;
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
  a_theta$[slsel_name] = 0;
  res_theta$[slsel_name] = $[res_gz];
  pw_theta$[slsel_name] = $[slsel_dur];
}
insert: predownload => {
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],
              $[slsel_loggrd].tz, $[slsel_loggrd].zrt, $[slsel_define]) == FAILURE)
        return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],
              $[slsel_loggrd].tz, $[slsel_loggrd].zft, $[slsel_define]) == FAILURE)
        return FAILURE;
  ia_gz$[slsel_name] = a_gz$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * max_pg_iamp;
  ia_theta$[slsel_name] = a_theta$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz ;
}
var:{
  EXTERN_FILENAME2 grad_z$[slsel_name];
  EXTERN_FILENAME2 rf_$[slsel_name] ;
  EXTERN_FILENAME2 theta_$[slsel_name];
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
  WF_PULSE theta$[slsel_name]  = INITPULSE;
}
subst:{
  {
   /* Select proper filename */
   grad_z$[slsel_name]=  $[extern_grad_file];
   rf_$[slsel_name] =  $[extern_rf_file];
   theta_$[slsel_name] = $[extern_grad_file];
    /* Now create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    pulsename(&theta$[slsel_name], "theta$[slsel_name]");
    /*  Now create the slice select trapezoid */
        pg_beta = $[slsel_loggrd].zbeta;
    if ( $[slsel_usegrad] == PLAY_GFILE)
        createextwave(&gz$[slsel_name],ZGRAD,
                res_gz$[slsel_name],grad_z$[slsel_name]);
    else {
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               max_pg_wamp,(short)(maxGradRes*(pw_gz$[slsel_name]a/
 
   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
        createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],max_pg_wamp);
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,max_pg_wamp,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/

GRAD_UPDATE_TIME)),pg_beta);                                     
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
                pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
      }
    createinstr( &gz$[slsel_name],(long)$[slsel_pos],
                pw_gz$[slsel_name],ia_gz$[slsel_name]);
    /* Now create the rf pulse */
    if ( $[slsel_userf] == PLAY_RFFILE)
     createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    else
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
               max_pg_wamp,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune],  pw_$[slsel_name],ia_$[slsel_name]);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)$[slsel_pos]
                          + psd_rf_wait + $[slsel_tune], pw_$[slsel_name]);
    /* Now create the theta pulse */
    if ( $[slsel_usetheta] == PLAY_THETA) {
    createextwave(&theta$[slsel_name],TYPOMEGA,
            res_theta$[slsel_name],theta_$[slsel_name]);
    createinstr( &theta$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune],  pw_theta$[slsel_name],ia_theta$[slsel_name]);
    addrfbits(&theta$[slsel_name],off_theta$[slsel_name],(long)$[slsel_pos]
              + psd_rf_wait + $[slsel_tune], pw_theta$[slsel_name]);
  }
    if ( $[slsel_usegrad] == PLAY_GFILE)
    linkpulses(3, &$[slsel_name], &gz$[slsel_name], &theta$[slsel_name]);
    else
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
                           &gz$[slsel_name]d);
}
}
}


/*
 *  EFFSLICESELZ_SPSP
 *  
 *  Type: Macro
 *  
 *  Description:
 *    This macro is based on EFFSLICESELZ and allows the user to
 *    create an EchoTrain on the Host side using a sequence of
 *    trapezoids.  On the IPG side, it will read an external file.
 */
EFFSLICESELZ_SPSP( slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
                   slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
                   slsel_userf:1, res_rf, extern_rf_file, slsel_usetheta:0,
                   slsel_define:1, slsel_loggrd, slsel_tune:0 )
{
cv:{
    float a_gz$[slsel_name];
    int ia_gz$[slsel_name];
    int pw_gz$[slsel_name]a;
    int pw_gz$[slsel_name]d;
    int pw_gz$[slsel_name];
    int res_gz$[slsel_name];
    float a_$[slsel_name];
    int ia_$[slsel_name];
    int pw_$[slsel_name];
    int res_$[slsel_name];
    float cyc_$[slsel_name];
    int off_$[slsel_name] = 0;
    float alpha_$[slsel_name] = 0.46;
    float thk_$[slsel_name];
    float gscale_$[slsel_name] = 1.0;
    float flip_$[slsel_name];
    float a_theta$[slsel_name];
    int ia_theta$[slsel_name];
    int pw_theta$[slsel_name];
    int res_theta$[slsel_name];
    int off_theta$[slsel_name] = 0;
}
insert: cvinit =>{
    flip_$[slsel_name] = $[slsel_flip];
    a_$[slsel_name] = flip_$[slsel_name]/180;
    pw_gz$[slsel_name] = $[slsel_dur];
    res_gz$[slsel_name] = $[res_gz];
    res_$[slsel_name] = $[res_rf];
    pw_$[slsel_name] = $[slsel_dur];
    cyc_$[slsel_name] = $[slsel_cycles];
    thk_$[slsel_name] = $[slsel_thk];
    a_theta$[slsel_name] = 0;
    res_theta$[slsel_name] = $[res_gz];
    pw_theta$[slsel_name] = $[slsel_dur];
}
insert: predownload => {

    if (optramp( &pw_gz$[slsel_name]a,a_gz$[slsel_name],
                 $[slsel_loggrd].tz, $[slsel_loggrd].zrt, 
                 $[slsel_define] ) == FAILURE) {
        return FAILURE;
    }

    if (optramp( &pw_gz$[slsel_name]d,a_gz$[slsel_name],
                 $[slsel_loggrd].tz, $[slsel_loggrd].zft, 
                 $[slsel_define] ) == FAILURE) {
        return FAILURE;
    }

    ia_gz$[slsel_name] = a_gz$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz;

    ia_$[slsel_name] = a_$[slsel_name] * max_pg_iamp;

    ia_theta$[slsel_name] = a_theta$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz ;

}

var:{
    EXTERN_FILENAME2 grad_z$[slsel_name];
    EXTERN_FILENAME2 rf_$[slsel_name] ;
    EXTERN_FILENAME2 theta_$[slsel_name];
    WF_PULSE gz$[slsel_name]a = INITPULSE;
    WF_PULSE gz$[slsel_name]  = INITPULSE;
    WF_PULSE gz$[slsel_name]d = INITPULSE;
    WF_PULSE $[slsel_name] = INITPULSE;
    WF_PULSE theta$[slsel_name]  = INITPULSE;
}

subst:{
  {
      /* Select proper filename */
      grad_z$[slsel_name]=  $[extern_grad_file];
      rf_$[slsel_name] =  $[extern_rf_file];
      theta_$[slsel_name] = $[extern_grad_file];

      /* Now create the pulses */
      pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
      pulsename(&gz$[slsel_name],"gz$[slsel_name]");
      pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
      pulsename(&$[slsel_name],"$[slsel_name]");
      pulsename(&theta$[slsel_name], "theta$[slsel_name]");

      /*  Now create the slice select trapezoid */
      pg_beta = $[slsel_loggrd].zbeta;

      if ( $[slsel_usegrad] == PLAY_GFILE) {

#ifdef IPG 
          /* Use external gradient file for now */
          createextwave( &gz$[slsel_name], ZGRAD, res_gz$[slsel_name],
                         grad_z$[slsel_name] );
#else /* !IPG */
          /* Create train of trapezoids on the Host side */
          int i;
          int polarity = 1;
       
          pulsepos = $[slsel_pos]; 
       
          for(i = 1; i <= num_rf1lobe; i++) {
              polarity *= -1;

              trapezoid( ZGRAD,"gz$[slsel_name]", &gz$[slsel_name], 
                         &gz$[slsel_name]a, &gz$[slsel_name]d,
                         pw_constant, pw_ss_rampz, pw_ss_rampz, 
                         (polarity*(ia_gz$[slsel_name])),
                         (polarity*(ia_gz$[slsel_name])),
                         (polarity*(ia_gz$[slsel_name])), 0, 0, 
                         pulsepos, TRAP_ALL, &$[slsel_loggrd] );

              pulsepos += pw_constant + 2 * pw_ss_rampz;
          }
#endif /* IPG */

      } else {

          /* Create simple trapezoid for chem sat + rf */
          createramp( &gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,
                      (short)0, max_pg_wamp,
                      (short)(maxGradRes *
                              (pw_gz$[slsel_name]a / GRAD_UPDATE_TIME)),
                      pg_beta );

          createinstr( &gz$[slsel_name]a,
                       (long)($[slsel_pos] - pw_gz$[slsel_name]a),
                       pw_gz$[slsel_name]a, ia_gz$[slsel_name] );

          createconst( &gz$[slsel_name], ZGRAD, pw_$[slsel_name], max_pg_wamp );

          createramp( &gz$[slsel_name]d, ZGRAD, pw_gz$[slsel_name]d,
                      max_pg_wamp, (short)0,
                      (short)(maxGradRes *
                              (pw_gz$[slsel_name]d / GRAD_UPDATE_TIME)),
                      pg_beta );
          createinstr( &gz$[slsel_name]d,
                       (long)($[slsel_pos] + pw_gz$[slsel_name]),
                       pw_gz$[slsel_name]d, ia_gz$[slsel_name] );

      }

#ifdef IPG 
      createinstr( &gz$[slsel_name], (long)$[slsel_pos],
                   pw_gz$[slsel_name], ia_gz$[slsel_name] );
#endif /* IPG */

      /* Now create the rf pulse */
      if ( $[slsel_userf] == PLAY_RFFILE) {
          createextwave( &$[slsel_name],TYPRHO1, res_$[slsel_name],
                         rf_$[slsel_name]);
      } else {
          createsinc( &$[slsel_name],TYPRHO1, res_$[slsel_name],
                      max_pg_wamp,cyc_$[slsel_name], alpha_$[slsel_name] );
      }

      createinstr( &$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                   $[slsel_tune],  pw_$[slsel_name],ia_$[slsel_name]);

      addrfbits( &$[slsel_name], off_$[slsel_name], (long)$[slsel_pos] +
                 psd_rf_wait + $[slsel_tune], pw_$[slsel_name] );

      /* Now create the theta pulse */
      if ( $[slsel_usetheta] == PLAY_THETA) {
          createextwave( &theta$[slsel_name], TYPOMEGA,
                         res_theta$[slsel_name], theta_$[slsel_name] );

          createinstr( &theta$[slsel_name], (long)$[slsel_pos] + psd_rf_wait +
                       $[slsel_tune], pw_theta$[slsel_name],
                       ia_theta$[slsel_name] );

          addrfbits( &theta$[slsel_name], off_theta$[slsel_name],
                     (long)$[slsel_pos] + psd_rf_wait + $[slsel_tune],
                     pw_theta$[slsel_name] );
      }
#ifdef IPG
      if ( $[slsel_usegrad] == PLAY_GFILE) {
          linkpulses( 3,
                      &$[slsel_name], &gz$[slsel_name], &theta$[slsel_name]);
      } else {
          linkpulses( 4,
                      &$[slsel_name], &gz$[slsel_name],
                      &gz$[slsel_name]a, &gz$[slsel_name]d);
      }
#endif /* IPG */
  }
}
}

/* merged 5.5 bch into vmx. YH 10/13/94 */
/* Possible EFFSLICESEL that does not care which axis it uses,
   this macro is not used presently but was added in case a non
   axis specific macro is desired in the future with this functionality   */
EFFSLICESEL( slsel_wgname, slsel_name, slsel_pos, slsel_dur, slsel_thk,
             slsel_flip,slsel_cycles:1.0,slsel_usegrad:1,
             res_g,extern_grad_file, slsel_userf:1, res_rf,
             extern_rf_file, slsel_usetheta:0, slsel_define:1,
             slsel_loggrd, slsel_tune:0 )
{
cv:{
  float a_g$[slsel_name];
  int ia_g$[slsel_name];
  int pw_g$[slsel_name]a;
  int pw_g$[slsel_name]d;
  int pw_g$[slsel_name];
  int res_g$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
  float a_theta$[slsel_name];
  int ia_theta$[slsel_name];
  int pw_theta$[slsel_name];
  int res_theta$[slsel_name];
  int off_theta$[slsel_name] = 0;
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_g$[slsel_name] = $[slsel_dur];
  res_g$[slsel_name] = $[res_g];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
  a_theta$[slsel_name] = 0;
  res_theta$[slsel_name] = $[res_g];
  pw_theta$[slsel_name] = $[slsel_dur];
}  
insert: predownload => {
{
  float target;
  int rise_time, fall_time;
 
  gettarget(&target, $[slsel_wgname],&$[slsel_loggrd]);
  getramptime(&rise_time, &fall_time, $[slsel_wgname],&$[slsel_loggrd]);

  if (optramp(&pw_g$[slsel_name]a,a_g$[slsel_name],                      
              target, rise_time, $[slsel_define]) == FAILURE)
        return FAILURE;
  if (optramp(&pw_g$[slsel_name]d,a_g$[slsel_name],
              target, fall_time, $[slsel_define]) == FAILURE)
        return FAILURE;
  ia_g$[slsel_name] = a_g$[slsel_name] * max_pg_iamp / target;
  ia_$[slsel_name] = a_$[slsel_name] * max_pg_iamp;
  ia_theta$[slsel_name] = a_theta$[slsel_name] * max_pg_iamp / target;
}
}
var:{
  EXTERN_FILENAME2 grad_$[slsel_name];
  EXTERN_FILENAME2 rf_$[slsel_name] ;
  EXTERN_FILENAME2 theta_$[slsel_name];
  WF_PULSE g$[slsel_name]a = INITPULSE;
  WF_PULSE g$[slsel_name]  = INITPULSE;
  WF_PULSE g$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
  WF_PULSE theta$[slsel_name]  = INITPULSE;
}
subst:{
  {

   /* Select proper filename */
   grad_$[slsel_name] =  $[extern_grad_file];
   rf_$[slsel_name] =  $[extern_rf_file];
   theta_$[slsel_name] = $[extern_grad_file];
 
    /* Now create the pulses */
    pulsename(&g$[slsel_name]a,"g$[slsel_name]a");
    pulsename(&g$[slsel_name],"g$[slsel_name]");
    pulsename(&g$[slsel_name]d,"g$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    pulsename(&theta$[slsel_name], "theta$[slsel_name]");
 
    /*  Now create the slice select trapezoid */
        getbeta(&pg_beta, $[slsel_wgname], &$[slsel_loggrd]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
        createextwave(&g$[slsel_name],$[slsel_wgname],
                res_g$[slsel_name],grad_$[slsel_name]);
    else {
    createramp(&g$[slsel_name]a,$[slsel_wgname],pw_g$[slsel_name]a,(short)0,
               max_pg_wamp,(short)(maxGradRes*(pw_g$[slsel_name]a/
                                                      GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]a,(long)($[slsel_pos]-pw_g$[slsel_name]a),
                pw_g$[slsel_name]a,ia_g$[slsel_name]);
        createconst(&g$[slsel_name],$[slsel_wgname], pw_$[slsel_name],max_pg_wamp);
    createramp(&g$[slsel_name]d,$[slsel_wgname],pw_g$[slsel_name]d,max_pg_wamp,
               (short)0,(short)(maxGradRes*(pw_g$[slsel_name]d/
                                                      GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]d,(long)($[slsel_pos]+pw_g$[slsel_name]),
                pw_g$[slsel_name]d,ia_g$[slsel_name]);
      }
    createinstr( &g$[slsel_name],(long)$[slsel_pos],
                pw_g$[slsel_name],ia_g$[slsel_name]);
 
    /* Now create the rf pulse */
    if ( $[slsel_userf] == PLAY_RFFILE)
     createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    else
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
               max_pg_wamp,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune], pw_$[slsel_name],ia_$[slsel_name]);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)$[slsel_pos]
                          + psd_rf_wait + $[slsel_tune], pw_$[slsel_name]);
 
    /* Now create the theta pulse */
    if ( $[slsel_usetheta] == PLAY_THETA) {
    createextwave(&theta$[slsel_name],TYPOMEGA,
            res_theta$[slsel_name],theta_$[slsel_name]);
    createinstr( &theta$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune],  pw_theta$[slsel_name],ia_theta$[slsel_name]);
    addrfbits(&theta$[slsel_name],off_theta$[slsel_name],(long)$[slsel_pos]
              + psd_rf_wait + $[slsel_tune], pw_theta$[slsel_name]);
  }
    if ( $[slsel_usegrad] == PLAY_GFILE)
    linkpulses(3, &$[slsel_name], &g$[slsel_name], &theta$[slsel_name]);
    else
    linkpulses(4,&$[slsel_name],&g$[slsel_name],&g$[slsel_name]a,
                           &g$[slsel_name]d);
}
}
}

/* merged 5.5 bch into vmx context.  YH  10/13/94 */
EP_TRAIN( et_pos:0, et_vps:1, et_offset:0, et_vtot,
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
   et_vps         -  views per shot (number of echoes macro generates)
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
   pw_gxcla, pw_gxcl, pwgxcld, pwgxwl, pwgxwr, pw_gxgap, pw_gxcra,
   pw_gxcr, pw_gxcrd.
 
   Combined Exciter/Receiver(/DAB) packets are labeled as echoxxxx (where
   xxxx ranges from 0000 to 9999).  This is useful for programming exciter
   phase and frequency on a per-view basis.
 
*/
 
cv:{
 
  float a_gxcl;
  float a_gxw;
  float a_gxcr;
  float a_gyb;
  int   ia_gxcl;
  int   ia_gxw;
  int   ia_gxcr;
  int   ia_gyb;
  int   pw_gxcla;
  int   pw_gxcl;
  int   pw_gxcld;
  int   pw_gxwl;
  int   pw_gxw;
  int   pw_gxwr;
  int   pw_gxwad;
  int   pw_gxgap;
  int   pw_gxcra;
  int   pw_gxcr;
  int   pw_gxcrd;
  int   pw_gyba;
  int   pw_gyb;
  int   pw_gybd;
 
}
var:{
 
  WF_PULSE gxcla = INITPULSE;
  WF_PULSE gxcl = INITPULSE;
  WF_PULSE gxcld = INITPULSE;
 
  WF_PULSE gxwa = INITPULSE;
  WF_PULSE gxw = INITPULSE;
  WF_PULSE gxwd = INITPULSE;
  WF_PULSE gxwde = INITPULSE;
  WF_PULSE gxcra = INITPULSE;
  WF_PULSE gxcr = INITPULSE;
  WF_PULSE gxcrd = INITPULSE;
 
  WF_PULSE gxgap = INITPULSE;
 
  WF_PULSE gyb = INITPULSE;
  WF_PULSE gyba = INITPULSE;
  WF_PULSE gybd = INITPULSE;
   
  WF_PULSE *echotrain;
 
}
 
insert: cvinit => {
}
 
insert: predownload => {
  ia_gxcl = a_gxcl * max_pg_wamp / $[et_loggrd].tx;
  ia_gxw = a_gxw * max_pg_wamp / $[et_loggrd].tx;
  ia_gxcr = a_gxcr * max_pg_wamp / $[et_loggrd].tx;
  ia_gyb = a_gyb * max_pg_iamp / $[et_loggrd].ty;
}
 
subst:{
    {
        int psd_gxwcnt;
        int psd_pulsepos;
        int psd_eparity;
        long psd_epxtroff;
        long psd_epdaboff;
        float psd_etbetax;
        float psd_etbetay;
        char psd_epstring[EPSTRING_LENGTH];

        psd_pulsepos = $[et_pos];           
 
        /* allocate on 1st pass only  */
        if ( $[et_offset] == 0 ) {
            echotrain = (WF_PULSE *)AllocNode(($[et_vtot] + 3) * sizeof(WF_PULSE));
        }
 
        pulsename(&gxcla, "gxcla");
        pulsename(&gxcl, "gxcl");
        pulsename(&gxcld, "gxcld");
 
        pulsename(&gxwa, "gxwa");
        pulsename(&gxw, "gxw");
        pulsename(&gxwd, "gxwd");
        pulsename(&gxwde, "gxwde");
 
        pulsename(&gxgap, "gxgap");
 
        pulsename(&gyba, "gyba");
        pulsename(&gyb, "gyb");
        pulsename(&gybd, "gybd");
 
        pulsename(&gxcra, "gxcra");
        pulsename(&gxcr, "gxcr");
        pulsename(&gxcrd, "gxcrd");
 
        getbeta(&psd_etbetax, XGRAD, &$[et_loggrd]);
        getbeta(&psd_etbetay, YGRAD, &$[et_loggrd]);
 
        if (pw_gxcla >= GRAD_UPDATE_TIME) {
            createramp(&gxcla, XGRAD, pw_gxcla, (short)0,
                       (short)ia_gxcl, (short)(maxGradRes*(pw_gxcla/
                                                           GRAD_UPDATE_TIME)), psd_etbetax);
            createinstr(&gxcla, (long)(psd_pulsepos),
                        pw_gxcla, max_pg_iamp);
            psd_pulsepos += pw_gxcla;
        }
    
        if (pw_gxcl >= GRAD_UPDATE_TIME) {
            createconst(&gxcl, XGRAD, pw_gxcl, max_pg_wamp);
            createinstr(&gxcl, (long)psd_pulsepos,
                        pw_gxcl, ia_gxcl);
            psd_pulsepos += pw_gxcl;
        }
    
        if (pw_gxcld >= GRAD_UPDATE_TIME) {
            createramp(&gxcld, XGRAD, pw_gxcld, (short)ia_gxcl,
                       (short)ia_gxw, (short)(maxGradRes*(pw_gxcld/
                                                          GRAD_UPDATE_TIME)), psd_etbetax);
            createinstr(&gxcld, (long)psd_pulsepos,
                        pw_gxcld, max_pg_iamp);
            psd_pulsepos += pw_gxcld;
        }
    
        createconst(&gxw, XGRAD, pw_gxwl+pw_gxw+pw_gxwr, max_pg_wamp);
        createinstr(&gxw, (long)psd_pulsepos,
                    pw_gxwl+pw_gxw+pw_gxwr, ia_gxw);
        psd_pulsepos += pw_gxwl;
    
        sprintf(psd_epstring, "echo%04d", $[et_offset]);
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
        
            linkpulses(3,&gyb,&gyba,&gybd);
        
            if (pw_gxgap == 0) {    /* Combine decay and attack ramps */
                createramp(&gxwd, XGRAD, 2*pw_gxwad, max_pg_wamp, -max_pg_wamp,
                           (short)(maxGradRes*(2*pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwd, (long)psd_pulsepos, 2*pw_gxwad, psd_eparity*
                            (-ia_gxw));
                psd_pulsepos += 2*pw_gxwad;
            
            } else {
                createramp(&gxwd, XGRAD, pw_gxwad, -max_pg_wamp, 0,
                           (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwd, (long)psd_pulsepos, pw_gxwad, psd_eparity*
                            ia_gxw);
                psd_pulsepos += pw_gxwad;
            
                createconst(&gxgap, XGRAD, pw_gxgap, 0);
                createinstr(&gxgap, (long)psd_pulsepos,
                            pw_gxgap, 0);
                psd_pulsepos += pw_gxgap;
            
                createramp(&gxwa, XGRAD, pw_gxwad, 0, max_pg_wamp,
                           (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwa, (long)psd_pulsepos, pw_gxwad, psd_eparity*
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
    
        if (($[et_vps] % 2) == 1) {    /* views per shot is odd */          
            if (pw_gxcra >= GRAD_UPDATE_TIME) {
                createramp(&gxcra, XGRAD, pw_gxcra, (short)ia_gxw,
                           (short)ia_gxcr, (short)(maxGradRes*(pw_gxcra/
                                                               GRAD_UPDATE_TIME)),
                           psd_etbetax);
                createinstr(&gxcra, (long)(psd_pulsepos),
                            pw_gxcra, max_pg_iamp);
                psd_pulsepos += pw_gxcra;
            }
                                         
        } else {                        /* views per shot is even */

            /* single transition ramp into crusher */                  

            if ((ia_gxw == ia_gxcr) && (pw_gxwad == pw_gxcra)) {
                createramp(&gxwd, XGRAD, 2*pw_gxwad, -max_pg_wamp, max_pg_wamp,
                           (short)(maxGradRes*(2*pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwd, (long)psd_pulsepos, 2*pw_gxwad, ia_gxw);
                psd_pulsepos += 2*pw_gxwad;

            } else {    /* two separate ramps, decay ramp needs new waveform */

                createramp(&gxwde, XGRAD, pw_gxwad, -max_pg_wamp, 0,              
                           (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME), psd_etbetax);
                createinstr(&gxwde, (long)psd_pulsepos, pw_gxwad, ia_gxw);
                psd_pulsepos += pw_gxwad;

                if (pw_gxcra >= GRAD_UPDATE_TIME) {
                    createramp(&gxcra, XGRAD, pw_gxcra, (short)0,
                               (short)ia_gxcr, (short)(maxGradRes*(pw_gxcra/
                                                                   GRAD_UPDATE_TIME)),
                               psd_etbetax);
                    createinstr(&gxcra, (long)(psd_pulsepos),
                                pw_gxcra, max_pg_iamp);
                    psd_pulsepos += pw_gxcra;
                }

            }   
        }        
        if (pw_gxcr >= GRAD_UPDATE_TIME) {
            createconst(&gxcr, XGRAD, pw_gxcr, max_pg_wamp);
            createinstr(&gxcr, (long)psd_pulsepos,
                        pw_gxcr, ia_gxcr);
            psd_pulsepos += pw_gxcr;
        }

        if (pw_gxcrd >= GRAD_UPDATE_TIME) {
            createramp(&gxcrd, XGRAD, pw_gxcrd, (short)ia_gxcr,
                       (short)0, (short)(maxGradRes*(pw_gxcrd/

                                                     GRAD_UPDATE_TIME)), psd_etbetax);                             
            createinstr(&gxcrd, (long)psd_pulsepos,
                        pw_gxcrd, max_pg_iamp);
            psd_pulsepos += pw_gxcrd;
        }
 
    }
}

}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
EXTWAVE(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
	extern_file, ext_offset:0, ext_loggrd){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}

insert: cvinit =>{
  a_$[ext_name] = $[ext_amp];
  res_$[ext_name] = $[ext_res];
  pw_$[ext_name] = $[ext_dur];
  off_$[ext_name] = $[ext_offset];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}
}

var:{
  
  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
		      res_$[ext_name],fileloc_$[ext_name]);
    if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
      {
	createinstr( &$[ext_name],(long)($[ext_pos]) + psd_rf_wait, 
		    pw_$[ext_name],ia_$[ext_name]);
	addrfbits(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) + psd_rf_wait,
		  pw_$[ext_name]);
      }
    else
      {
	createinstr( &$[ext_name],(long)($[ext_pos]), 
		    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

/*Meng: 11/2/95, added to take name string for external pulse*/

EXTWAVE_INV(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
	extern_file, ext_offset:0, ext_loggrd){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}

insert: cvinit =>{
  a_$[ext_name] = $[ext_amp];
  res_$[ext_name] = $[ext_res];
  pw_$[ext_name] = $[ext_dur];
  off_$[ext_name] = $[ext_offset];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}
}

var:{
  
/*  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";*/
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
		      res_$[ext_name],$[extern_file]);
    if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
      {
	createinstr( &$[ext_name],(long)($[ext_pos]) + psd_rf_wait, 
		    pw_$[ext_name],ia_$[ext_name]);
	addrfbits(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) + psd_rf_wait,
		  pw_$[ext_name]);
      }
    else
      {
	createinstr( &$[ext_name],(long)($[ext_pos]), 
		    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

/* 3/13/95 YI  added EXTWAVE2
               changed datatype of res_$[ext_name] filed from short to int. */

EXTWAVE2(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
	extern_file, ext_offset:0, ext_loggrd, rf_slot){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}

insert: cvinit =>{
  a_$[ext_name] = $[ext_amp];
  res_$[ext_name] = $[ext_res];
  pw_$[ext_name] = $[ext_dur];
  off_$[ext_name] = $[ext_offset];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}
}

var:{
  
  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");

    /* Scale waveform if needed */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	createsinc(&$[ext_name], $[ext_wgname],rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,1.0,0.46);
	if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	    ($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait, 
			pw_$[ext_name],ia_$[ext_name]);
	    addrfbits(&$[ext_name],off_$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait,
		      pw_$[ext_name]);
	  }
	else
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]), 
			pw_$[ext_name],ia_$[ext_name]);
	  }

	/* Create some board waveform space, scale the pulse, and then move
	 * the local memory to the reserved board memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[ext_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[ext_name], fileloc_$[ext_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[ext_name],(int)rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[ext_name] = rfpulseInfo[$[rf_slot]].newres;
	
	/* Move immediately into permanent memory */
	movewaveimm(wave_space, &$[ext_name], (int)0, res_$[ext_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[ext_name],$[ext_wgname],
		      res_$[ext_name],fileloc_$[ext_name]);
	if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	    ($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait, 
			pw_$[ext_name],ia_$[ext_name]);
	    addrfbits(&$[ext_name],off_$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait,
		      pw_$[ext_name]);
	  }
	else
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]), 
			pw_$[ext_name],ia_$[ext_name]);
	  }
      }
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
/* Make the use of external RF files easier to switch internally.
   The EXTWAVE macro in epic.h is not quite flexible enough. */
EXTWAVEX(ext_wgname, ext_name, ext_pos, extern_file){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}
 
insert: predownload =>{
  ia_$[ext_name] = a_$[ext_name] * MAX_PG_IAMP;
}
 
var:{
 
  EXTERN_FILENAME $[extern_file];
  WF_PULSE $[ext_name] = INITPULSE;
}
 
subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
                      res_$[ext_name],$[extern_file]);
    createinstr( &$[ext_name],(long)$[ext_pos] + psd_rf_wait,
                pw_$[ext_name],ia_$[ext_name]);
    addrfbits(&$[ext_name],off_$[ext_name],(long)$[ext_pos] + psd_rf_wait,
              pw_$[ext_name]);
  }
}
}
 
/* merged 55 bch into vmx.  YH  10/13/94 */
FREC_DIAGS(fd_name, fd_pos, fd_rinibble, fd_rqnibble, fd_diag_mode:0) {
 
/* FREC_DIAGS creates an ssp packet that sets up the fast receiver with
   diagnostics data nibbles that can be used to test the integrity of the
   data pathways.  This data is sent from the remote fast receiver to
   the dab instead of the actual sampled data.  The diagnostic mode
   'A' must be set explicitly in the fast receiver RBA packet to force
   the receiver to output the diagnostic data nibbles.
 
   Argument definitions:
   fd_name        -  name of packet
   fd_pos         -  position of packet
   fd_rinibble    -  remoted i nibble
   fd_rqnibble    -  remoted q nibble
   fd_diag_mode   -  diagnostic mode, 1=mode A, 2=mode B
 
*/
 
cv:{
}
insert: cvinit =>{
}
insert: predownload => {
}
var:{
  WF_PULSE $[fd_name] = INITPULSE;
}
subst:{
  {
        short inibbleout;
        short qnibbleout;
 
        switch (fast_diag_mode) {
        case 1:
          inibbleout = ($[fd_rinibble] & 0x0F) | 0xC0;
          qnibbleout = ($[fd_rqnibble] & 0x0F) | 0xD0;
          break;
        case 2:
          inibbleout = ($[fd_rinibble] & 0x0F) | 0xE0;
          qnibbleout = ($[fd_rqnibble] & 0x0F) | 0xF0;
          break;
        default:
          break;
        }
 
    pulsename(&$[fd_name],"$[fd_name]");
        FAST_DIAG_bits[2] = SSPD + inibbleout;
        FAST_DIAG_bits[4] = SSPD + qnibbleout;
 
        createbits((WF_PULSE_ADDR)&$[fd_name],
                           (WF_PROCESSOR)TYPSSP,
                           (short)FAST_DIAG_length,
                           (short *)FAST_DIAG_bits);

        createinstr((WF_PULSE_ADDR)&$[fd_name],      
                                (long)$[fd_pos],
                                (long)FAST_DIAG_length,
                                (long)0);
  }
}
}
 
/* merged 55 bch into vmx.  YH  10/13/94 */
FASTACQUIREDATA(facq_name, facq_pos, frecv_type: 1, fdab_switch:1,
                          fdab_pos:DEFAULTPOS, fxtr_pos:DEFAULTPOS, facq_fslot:1,
                          facq_recvval:4,facq_dabtype:DABNORM, facq_prefills:DEFPREFILLS){
 
/* FASTACQUIREDATA creates a single data acquisition frame for either the
   standard or fast receivers, with an optional single frame dab packet.
 
   Argument definitions:
   facq_name      -  name of packet, basename for CVs created
   facq_pos       -  absolute time position of start of acquisition (RBA)
   frecv_type     -  0=standard receiver, 1=fast receiver
   fdab_switch    -  0=don't create dab packet, 1=create a standard dab packet
   fdab_pos       -  absolute time position of dab packet; if zero then default
                     to rules specified in acqq or epiacqq.
   fxtr_pos       -  absolute time position of xtr packet; if zero then default
                     to rules specified in acqq or epiacqq.
   facq_fslot     -  filter slot to use (only applies if frecv_type == 0)
   facq_recvval   -  receiver unit number (0-3 = std recvr, 4 = fast receiver)
   facq_dabtype   -  normal or cine packet
   facq_prefills  -  number of prefills to position DAB packet (only applies
                     if frecv_type == 0 and fdab_switch == 1)
*/
 
cv:{
  int filter_$[facq_name];
  int rcvr_$[facq_name];
  int prefill_$[facq_name];
}
insert: cvinit =>{
  filter_$[facq_name] = $[facq_fslot];
  rcvr_$[facq_name] = $[facq_recvval];
  prefill_$[facq_name] = DEFPREFILLS;
}
insert: predownload => {
}
var:{
  WF_PULSE $[facq_name] = INITPULSE;
}    
subst:{
  {
    pulsename(&$[facq_name],"$[facq_name]");
 
    epiacqq(&$[facq_name], (long)($[facq_pos]),(long)($[fdab_pos]),
             (long)($[fxtr_pos]), (long)(filter_$[facq_name]),
             (long)(rcvr_$[facq_name]), (TYPDAB_PACKETS)($[facq_dabtype]),
                         (long)($[facq_prefills]), (long)($[frecv_type]),
                         (long)($[fdab_switch]));
  }
}
}

/* changed res_$ from short to int YH */
HADAMARD(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_sep,
       snc_res:0, snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46){
cv:{
  float a_$[snc_name];
  int ia_$[snc_name];
  int pw_$[snc_name];
  float sep_$[snc_name];
  int res_$[snc_name];
  float cyc_$[snc_name];
  int off_$[snc_name];
  float alpha_$[snc_name];
}
var:{
  WF_PULSE $[snc_name] = INITPULSE;
}
insert: cvinit =>{
  a_$[snc_name] = $[snc_amp];
  res_$[snc_name] = $[snc_res];
  cyc_$[snc_name] = $[snc_cycles];
  off_$[snc_name] = $[snc_offset];
  alpha_$[snc_name] = $[snc_alpha];
  pw_$[snc_name] = $[snc_dur];
  sep_$[snc_name] = $[snc_sep];
}

insert: predownload =>{
  if (res_$[snc_name] == 0)
    {
    res_$[snc_name] = pw_$[snc_name]/(RF_UPDATE_TIME);
    }
  ia_$[snc_name] = a_$[snc_name] * MAX_PG_IAMP;
}
subst:{
  {
    pulsename(&$[snc_name],"$[snc_name]");
    createhadamard(&$[snc_name],$[snc_wgname],res_$[snc_name],MAX_PG_WAMP,
		   sep_$[snc_name],cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
	($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
	createinstr( &$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
		    pw_$[snc_name],ia_$[snc_name]);
	addrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
		  pw_$[snc_name]);
      }
    else
      {
	createinstr( &$[snc_name],(long)($[snc_pos]),
		    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
HSDAB(hsdab_name, hsdab_pos) {
 
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

        createhsdab(&$[hsdab_name], (long)($[hsdab_pos]));
  }
}
}
 
/* merged 55 bch into vmx.  YH 10/13/94 */
INITFASTRECV(ifr_name, ifr_pos, ifr_samps, ifr_tsp, ifr_delay, ifr_lpf:1) {
 
/* INITFASTRECV creates an ssp packet that programs the fast receiver.
 
   Argument definitions:
   ifr_name      -  name of packet
   ifr_pos       -  absolute time position of fast receiver init packet
   ifr_samps     -  number of samples per frame
   ifr_tsp       -  sample period in tics (1 tic = 50ns)
   ifr_delay     -  frame delay in tics (1 tic = 50ns)
   ifr_lpf       -  low pass filter setting (1-5, 1=100kHz,..,5=500kHz)
 
*/
 
cv:{
}
insert: cvinit =>{
}
insert: predownload => {
}
var:{
  WF_PULSE $[ifr_name] = INITPULSE;
}
subst:{
  {
    pulsename(&$[ifr_name],"$[ifr_name]");
 
        initfastrec(&$[ifr_name], (long)($[ifr_pos]),
                  (long)($[ifr_samps]), (long)($[ifr_tsp]),
                  (long)($[ifr_delay]), (long)($[ifr_lpf]));
  }
}
}
 
/* merged 55 bch into vmx.  YH 10/13/94 */
MEMTRAP(trp_wgname,trp_name,trp_pos,trp_area,trp_define:TYPDEF,trp_loggrd) {
  /* Create a Trapezoid completely in memory. This really burns memory
     but it only requires one update call. It was written to address
     a performance issue in the ISI update for the fgre3d killer/rewinder.
     The pulse is first created in user allocated memory with rsp
     calls then moved into reserved waveform memory. The user memory is
     then freed.
         */
 
 
cv:{
  float a_$[trp_name];
  int ia_$[trp_name];
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name];
  int res_$[trp_name];
  int per_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
  s16 *$[trp_name]_mem;         /* temporary memory pointer */
  s16 $[trp_name]_indx;         /* indx into user memory */
}
insert: cvinit => {
}
insert: predownload => {
{
   float target;
   int rtime,ftime;
 
   gettarget(&target, $[trp_wgname], &$[trp_loggrd]);
   getramptime(&rtime,&ftime,$[trp_wgname], &$[trp_loggrd]);
   if ($[trp_define] == TYPDEF) {
     if (amppwgrad((float)($[trp_area]),target,0.0,0.0,rtime,MIN_PLATEAU_TIME,
                                 &a_$[trp_name], &pw_$[trp_name]a, &pw_$[trp_name],
                                 &pw_$[trp_name]d) == FAILURE) return FAILURE;
   }
   ia_$[trp_name] = (a_$[trp_name] / target) * MAX_PG_IAMP;
   if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2) ||
       ($[trp_wgname]==TYPTHETA)||($[trp_wgname]==TYPOMEGA))
     {                          /* Determine min period */
       per_$[trp_name] = (RF_UPDATE_TIME);
     }
   else
     {
       per_$[trp_name] = (GRAD_UPDATE_TIME);
     }
   res_$[trp_name] =            /* Find resolution */
     (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d)/
       per_$[trp_name];
}
}
subst:{
  {
                                /* Allocate user memory */
    $[trp_name]_mem = (s16 *)AllocNode( res_$[trp_name]*sizeof(s16));
    $[trp_name]_indx = 0;
 
    getbeta(&pg_beta, $[trp_wgname], &$[trp_loggrd]);
 
                                /* Up ramp */
    uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
          (pw_$[trp_name]a/per_$[trp_name]),
          (short) 0, MAX_PG_WAMP, pg_beta);
                                /* Clear EOW */
    $[trp_name]_indx = ( pw_$[trp_name]a / per_$[trp_name] );
    $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
                                /* Top const */
    uramp((&$[trp_name]_mem[$[trp_name]_indx]),
          (pw_$[trp_name]/per_$[trp_name]),
          MAX_PG_WAMP, MAX_PG_WAMP, pg_beta);
                                /* Clear EOW */
    $[trp_name]_indx = ( (pw_$[trp_name]a+pw_$[trp_name]) /per_$[trp_name] );
    $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
                                /* Decay Ramp */
    uramp((&$[trp_name]_mem[$[trp_name]_indx]),
          (pw_$[trp_name]d/per_$[trp_name]),
          MAX_PG_WAMP, (short) 0, pg_beta);
                                /* Create pulse and memory */
    pulsename( &$[trp_name], "$[trp_name]");
    createreserve( &$[trp_name], $[trp_wgname], res_$[trp_name]);
    createinstr( &$[trp_name],(long)($[trp_pos]-pw_$[trp_name]a),
                (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d),
                ia_$[trp_name]);
                                /* Move user pulse into waveform mem */
    movewaveimm($[trp_name]_mem, &$[trp_name],
                (int)0, res_$[trp_name], TOHARDWARE);
                                /* Free user memory */
    FreeNode( $[trp_name]_mem );
    if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2))
      {                         /* Add rf control bits if rf pulse */
        addrfbits(&$[trp_name],0,(long)($[trp_pos]),
                  (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d));
      }
  }
}
}

PASSPACK(pass_pack_name, pass_pack_pos){
var:{
  WF_PULSE $[pass_pack_name] = INITPULSE;
}
insert: predownload => {
}
insert: cvinit => {
}
subst:{
  {
    pulsename(&$[pass_pack_name],"$[pass_pack_name]");
    createpass(&$[pass_pack_name],(long)($[pass_pack_pos]));
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
RAMP(rmp_wgname,rmp_name,rmp_pos,rmp_dur,rmp_startamp,rmp_endamp,rmp_res:0,rmp_loggrd) {
cv:{
  float start_$[rmp_name];
  float end_$[rmp_name];
  int ia_st$[rmp_name];
  int ia_end$[rmp_name];
  int pw_$[rmp_name];
  int res_$[rmp_name];
}
var:{
  WF_PULSE $[rmp_name] = INITPULSE;
}
insert: cvinit =>{
  start_$[rmp_name] = $[rmp_startamp];
  end_$[rmp_name] = $[rmp_endamp];
  pw_$[rmp_name] = $[rmp_dur];
  res_$[rmp_name] = $[rmp_res];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[rmp_wgname], &$[rmp_loggrd]);
  if (($[rmp_wgname]==TYPRHO1)||($[rmp_wgname]==TYPRHO2)||($[rmp_wgname]==TYPOMEGA)||($[rmp_wgname]==TYPTHETA))
    {
      ia_st$[rmp_name] = start_$[rmp_name] * MAX_PG_WAMP;
      if (start_$[rmp_name])
        {
          ia_end$[rmp_name] = end_$[rmp_name] * MAX_PG_WAMP;
        }
      else
        {
          ia_end$[rmp_name] = end_$[rmp_name] * MAX_PG_IAMP;
        }
     }
  else
    {
      ia_st$[rmp_name] = (start_$[rmp_name] / target) * MAX_PG_WAMP;
      if (start_$[rmp_name])
        {
          ia_end$[rmp_name] = (end_$[rmp_name] / target) * MAX_PG_WAMP;
        }
      else
        {
          ia_end$[rmp_name] = (end_$[rmp_name] / target) * MAX_PG_IAMP;
        }
    }	
}
}

subst:{
  {
    pulsename(&$[rmp_name],"$[rmp_name]");
 
        getbeta(&pg_beta, $[rmp_wgname], &$[rmp_loggrd]);
 
    if (start_$[rmp_name])
      {
        createramp(&$[rmp_name],$[rmp_wgname],pw_$[rmp_name],
                   ia_st$[rmp_name],ia_end$[rmp_name],
                   (short)(maxGradRes*(pw_$[rmp_name]/GRAD_UPDATE_TIME)),
                   pg_beta);
        createinstr( &$[rmp_name],(long)($[rmp_pos]),pw_$[rmp_name],MAX_PG_IAMP);
      }
    else
      {
        createramp(&$[rmp_name],$[rmp_wgname],pw_$[rmp_name],
                   (short)0,MAX_PG_WAMP,
                   (short)(maxGradRes*(pw_$[rmp_name]/GRAD_UPDATE_TIME)),
                   pg_beta);
        createinstr(&$[rmp_name],(long)($[rmp_pos]),pw_$[rmp_name],
                    ia_end$[rmp_name]);
      }
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
RCVRBLANK(rcvbl_name,rcvbl_pos,rcvbl_val:0) {
cv:{
  int ia_$[rcvbl_name];
}   
insert:  cvinit => {
}
insert: predownload => {
  ia_$[rcvbl_name] = $[rcvbl_val];
}
var:{
  WF_PULSE $[rcvbl_name] = INITPULSE;
  short $[rcvbl_name]_pack[4];
}
subst:{
  {
    $[rcvbl_name]_pack[0] = SSPDS+RDC;
    $[rcvbl_name]_pack[1] = SSPOC+RFUBL+RSEL_ALL;
    $[rcvbl_name]_pack[2] = SSPD+RBL;
    $[rcvbl_name]_pack[3] = SSPDS;

    pulsename(&$[rcvbl_name],"$[rcvbl_name]");
    createbits(&$[rcvbl_name],TYPSSP,4,$[rcvbl_name]_pack);
    createinstr( &$[rcvbl_name],(long)($[rcvbl_pos]),4,ia_$[rcvbl_name]);
  }
}
}
 
RCVRUNBLANK(rcvbl_name,rcvbl_pos,rcvbl_val:0) {
cv:{
  int ia_$[rcvbl_name];
}
insert:  cvinit => {
}
insert: predownload => {
  ia_$[rcvbl_name] = $[rcvbl_val];
}
var:{
  WF_PULSE $[rcvbl_name] = INITPULSE;
  short $[rcvbl_name]_pack[4];
}
subst:{
  {
    $[rcvbl_name]_pack[0] = SSPDS+RDC;
    $[rcvbl_name]_pack[1] = SSPOC+RFUBL+RSEL_ALL;
    $[rcvbl_name]_pack[2] = SSPD+RUBL;
    $[rcvbl_name]_pack[3] = SSPDS;

    pulsename(&$[rcvbl_name],"$[rcvbl_name]");
    createbits(&$[rcvbl_name],TYPSSP,4,$[rcvbl_name]_pack);
    createinstr( &$[rcvbl_name],(long)($[rcvbl_pos]),4,ia_$[rcvbl_name]);
  }
}
}


SEQLENGTH(seq_name, seq_reprate, seq_offset){

var:{
  SEQUENCE_ENTRIES  off_$[seq_offset];
  WF_PULSE $[seq_name];
#ifndef IPG
  int idx_$[seq_name];   /* sequence entry index */
#endif /* !IPG */
}
insert: predownload => {
}
insert: cvinit => {
}

subst:{
  {
    pulsename(&$[seq_name],"$[seq_name]");
    createseq(&$[seq_name],$[seq_reprate], off_$[seq_offset]);
#ifndef IPG
    /* Update sequence counter and get current sequence entry index */
    updateIndex( &idx_$[seq_name] );
    printDebug( DBLEVEL1, (dbLevel_t)seg_debug, "SEQLENGTH",
                "idx_$[seq_name] = %d\n", idx_$[seq_name] );
#endif /* !IPG */
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
/* changed res_$ from short to int YH */
SINC(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
         snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46,snc_loggrd){
cv:{
  float a_$[snc_name];
  int ia_$[snc_name];
  int pw_$[snc_name];
  int res_$[snc_name];
  float cyc_$[snc_name];
  int off_$[snc_name];
  float alpha_$[snc_name];
}
var:{
    WF_PULSE $[snc_name] = INITPULSE;
}
insert: cvinit =>{
  a_$[snc_name] = $[snc_amp];
  res_$[snc_name] = $[snc_res];
  cyc_$[snc_name] = $[snc_cycles];
  off_$[snc_name] = $[snc_offset];
  alpha_$[snc_name] = $[snc_alpha];
  pw_$[snc_name] = $[snc_dur];
}
insert: predownload =>{
{
  float target;
  gettarget(&target, $[snc_wgname],&$[snc_loggrd]);
  if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2)
        ||($[snc_wgname]==TYPOMEGA)||($[snc_wgname]==TYPTHETA))
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(RF_UPDATE_TIME);
        }
      ia_$[snc_name] = a_$[snc_name] * MAX_PG_IAMP;
    }    
  else
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(GRAD_UPDATE_TIME);
        }
      ia_$[snc_name] = (a_$[snc_name] / target) * MAX_PG_IAMP;
    }    
}
}
subst:{
  {
    pulsename(&$[snc_name],"$[snc_name]");
    createsinc(&$[snc_name],$[snc_wgname],res_$[snc_name],
               MAX_PG_WAMP,cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
        ($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
        createinstr( &$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
                    pw_$[snc_name],ia_$[snc_name]);
        addrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
                  pw_$[snc_name]);
      }
    else
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}
}

/* added 55 changes.  YH  10/13/94 */
/* vmx */
SINC2(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
         snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46,snc_loggrd){
cv:{
  float a_$[snc_name];
  int ia_$[snc_name];
  int pw_$[snc_name];
  int res_$[snc_name];
  float cyc_$[snc_name];
  int off_$[snc_name];
  float alpha_$[snc_name];
}
var:{
    WF_PULSE $[snc_name] = INITPULSE;
}
insert: cvinit =>{
  a_$[snc_name] = $[snc_amp];
  res_$[snc_name] = $[snc_res];
  cyc_$[snc_name] = $[snc_cycles];
  off_$[snc_name] = $[snc_offset];
  alpha_$[snc_name] = $[snc_alpha];
  pw_$[snc_name] = $[snc_dur];
}
insert: predownload =>{
{
  float target;
  gettarget(&target, $[snc_wgname],&$[snc_loggrd]);
  if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2)
        ||($[snc_wgname]==TYPOMEGA)||($[snc_wgname]==TYPTHETA))
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(RF_UPDATE_TIME);
        }
      ia_$[snc_name] = a_$[snc_name] * MAX_PG_IAMP;
    }    
  else
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(GRAD_UPDATE_TIME);
        }
      ia_$[snc_name] = (a_$[snc_name] / target) * MAX_PG_IAMP;
    }    
}
}
subst:{
  {
    pulsename(&$[snc_name],"$[snc_name]");
    createsinc(&$[snc_name],$[snc_wgname],res_$[snc_name],
               MAX_PG_WAMP,cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
        ($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
        addrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]),
                  pw_$[snc_name]);
      }
    else
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}
}
/* end vmx */

/* merged 55 bch into vmx.  YH 10/13/94 */
/* changed res_$ from short to int YH */
SINUSOID(sin_wgname,sin_name,sin_pos,sin_dur,sin_amp,sin_res:0,
         sin_sphase:0.0,sin_phasel:0.5,sin_offset:0.0,rmp_loggrd){
cv:{
  int ia_$[sin_name]w;
  float a_$[sin_name];
  int ia_$[sin_name];
  int pw_$[sin_name];
  int res_$[sin_name];
  float phs_$[sin_name];
  float phl_$[sin_name];
  int off_$[sin_name];
}
var:{
  WF_PULSE $[sin_name] = INITPULSE;
}

insert: cvinit => {
  a_$[sin_name] = $[sin_amp];
  ia_$[sin_name]w = MAX_PG_WAMP;
  res_$[sin_name] = $[sin_res];
  phs_$[sin_name] = $[sin_sphase];
  phl_$[sin_name] = $[sin_phasel];
  off_$[sin_name] = $[sin_offset];
  pw_$[sin_name] = $[sin_dur];
}

insert: predownload =>{
{
  float target;
 
  gettarget(&target, $[sin_wgname],&$[rmp_loggrd]);
  if (($[sin_wgname]==TYPRHO1)||($[sin_wgname]==TYPRHO2)
        ||($[sin_wgname]==TYPOMEGA)||($[sin_wgname]==TYPTHETA))
    {
      if (res_$[sin_name] == 0)
        {
          res_$[sin_name] = pw_$[sin_name]/(RF_UPDATE_TIME);
        }
      ia_$[sin_name] = a_$[sin_name] * MAX_PG_IAMP;
    }    
  else
    {
      if (res_$[sin_name] == 0)
        {
          res_$[sin_name] = pw_$[sin_name]/(GRAD_UPDATE_TIME);
        }
      ia_$[sin_name] = (a_$[sin_name] / target) * MAX_PG_IAMP;
    }    
 
  if (off_$[sin_name] != 0.0)
    {
      ia_$[sin_name]w = (a_$[sin_name] / target) * MAX_PG_WAMP;
      ia_$[sin_name] = MAX_PG_IAMP;
    }
}
}

subst:{
  {
    pulsename(&$[sin_name],"$[sin_name]");
    createsinusoid(&$[sin_name],$[sin_wgname],res_$[sin_name],
		   ia_$[sin_name]w,phs_$[sin_name],phl_$[sin_name],
		   off_$[sin_name]);
    createinstr(&$[sin_name],(long)($[sin_pos]),pw_$[sin_name],ia_$[sin_name]);
     
    if (($[sin_wgname]==TYPRHO1)||($[sin_wgname]==TYPRHO2))
      {
	addrfbits(&$[sin_name],0,(long)($[sin_pos]),pw_$[sin_name]);
      }
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELX(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float gscale_$[slsel_name] = 1.0;
  float thk_$[slsel_name];
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
                                         pw_$[slsel_name]),
               (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
               (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx,
              $[slsel_loggrd].xrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
                  $[slsel_loggrd].xft,$[slsel_define])
      == FAILURE) return FAILURE;

  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0) 
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;

}
subst:{
  {
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
     pg_beta = $[slsel_loggrd].xbeta;
         createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(long)($[slsel_pos]-pw_gx$[slsel_name]a),
                pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    createconst(&gx$[slsel_name],XGRAD,pw_gx$[slsel_name],MAX_PG_WAMP);
    createinstr( &gx$[slsel_name],(long)($[slsel_pos]),
                pw_gx$[slsel_name],ia_gx$[slsel_name]);
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gx$[slsel_name]d/GRAD_UPDATE_TIME)),
                   pg_beta);
    createinstr( &gx$[slsel_name]d,(long)($[slsel_pos]+pw_gx$[slsel_name]),
                pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
	       &gx$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
    
}
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELY(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name], $[slsel_loggrd].ty,
	      $[slsel_loggrd].yrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name], $[slsel_loggrd].ty, 
	      $[slsel_loggrd].yft,$[slsel_define]) == FAILURE) return FAILURE;

  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0) 
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
	/* First create the pulses */
  pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
  pulsename(&gy$[slsel_name],"gy$[slsel_name]");
  pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
  pulsename(&$[slsel_name],"$[slsel_name]");

	/*  Now create the slice select trapezoid */
  pg_beta = $[slsel_loggrd].ybeta;
  createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,MAX_PG_WAMP,
                        (short)(maxGradRes*(pw_gy$[slsel_name]a/GRAD_UPDATE_TIME))
                        ,pg_beta);
  createinstr( &gy$[slsel_name]a,(long)($[slsel_pos]-pw_gy$[slsel_name]a),
      pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
  createconst(&gy$[slsel_name],YGRAD,pw_gy$[slsel_name],MAX_PG_WAMP);
  createinstr( &gy$[slsel_name],(long)($[slsel_pos]),
      pw_gy$[slsel_name],ia_gy$[slsel_name]);
  createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
                        (short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/GRAD_UPDATE_TIME))
                        ,pg_beta);
  createinstr( &gy$[slsel_name]d,(long)($[slsel_pos]+pw_gy$[slsel_name]),
      pw_gy$[slsel_name]d,ia_gy$[slsel_name]);

	/* Now create the rf pulse */
  createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
  createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
      pw_$[slsel_name],ia_$[slsel_name]);
  linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,&gy$[slsel_name]d);
  addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	pw_$[slsel_name]);

}
}
}

/* 3/13/95 YI  added SLICESELX2 and SLICESELY2
               changed data taype of res_$[slsel_name] from short to int. */

SLICESELX2(slsel_name, rf_slot, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  int temp_res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float gscale_$[slsel_name] = 1.0;
  float thk_$[slsel_name];
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx, 
	      $[slsel_loggrd].xrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
		  $[slsel_loggrd].xft,$[slsel_define]) 
      == FAILURE) return FAILURE;

  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* Modify resolution if scaling required */
    temp_res_$[slsel_name] = res_$[slsel_name];
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].xbeta;
    createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
					       GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(LONG)($[slsel_pos]-pw_gx$[slsel_name]a),
		pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    createconst(&gx$[slsel_name],XGRAD,pw_gx$[slsel_name],MAX_PG_WAMP);
    createinstr( &gx$[slsel_name],(LONG)($[slsel_pos]),
		pw_gx$[slsel_name],ia_gx$[slsel_name]);
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gx$[slsel_name]d/GRAD_UPDATE_TIME)),
		   pg_beta);
    createinstr( &gx$[slsel_name]d,(LONG)($[slsel_pos]+pw_gx$[slsel_name]),
		pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
	       &gx$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
    /* Changed back resolution incase external rf used later in pulsegen. We need
     * original resolution to scale pulses that are external
     */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = temp_res_$[slsel_name];
}
}
}

SLICESELY2(slsel_name, rf_slot, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  int temp_res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name],$[slsel_loggrd].ty,
		  $[slsel_loggrd].yrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name],$[slsel_loggrd].ty,
	      $[slsel_loggrd].yft,$[slsel_define]) == FAILURE) return FAILURE;

  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
    /* Modify resolution if scaling required */
    temp_res_$[slsel_name] = res_$[slsel_name];
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
    /* First create the pulses */
    pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
    pulsename(&gy$[slsel_name],"gy$[slsel_name]");
    pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

	/*  Now create the slice select trapezoid */
  pg_beta = $[slsel_loggrd].ybeta;
  createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,MAX_PG_WAMP,
			(short)(maxGradRes*(pw_gy$[slsel_name]a/GRAD_UPDATE_TIME))
			,pg_beta);
  createinstr( &gy$[slsel_name]a,(LONG)($[slsel_pos]-pw_gy$[slsel_name]a),
      pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
  createconst(&gy$[slsel_name],YGRAD,pw_gy$[slsel_name],MAX_PG_WAMP);
  createinstr( &gy$[slsel_name],(LONG)($[slsel_pos]),
      pw_gy$[slsel_name],ia_gy$[slsel_name]);
  createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
			(short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/GRAD_UPDATE_TIME))
			,pg_beta);
  createinstr( &gy$[slsel_name]d,(LONG)($[slsel_pos]+pw_gy$[slsel_name]),
      pw_gy$[slsel_name]d,ia_gy$[slsel_name]);

    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,&gy$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
    /* Changed back resolution incase external rf used later in pulsegen. We need
     * original resolution to scale pulses that are external
     */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      res_$[slsel_name] = temp_res_$[slsel_name];
}

}
}


/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELZ(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
      $[slsel_loggrd].zrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
          $[slsel_loggrd].zft,$[slsel_define])== FAILURE) return FAILURE;

  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);


}
var:{
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    createconst(&gz$[slsel_name],ZGRAD,pw_gz$[slsel_name],MAX_PG_WAMP);
    createinstr( &gz$[slsel_name],(long)($[slsel_pos]),
                pw_gz$[slsel_name],ia_gz$[slsel_name]);
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/GRAD_UPDATE_TIME)),
                   pg_beta);
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
                pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait, 
	      pw_$[slsel_name]);
  }
}
}

/* 3/13/95 YI addd SLICESELZ2
              changed data type of res_$ and temp_res_$ from short to int. */

SLICESELZ2(slsel_name, rf_slot,slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  int temp_res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
      $[slsel_loggrd].zrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
	  $[slsel_loggrd].zft,$[slsel_define])== FAILURE) return FAILURE;

  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);


}
var:{
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
    /* Modify resolution if scaling required */
    temp_res_$[slsel_name] = res_$[slsel_name];
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(LONG)($[slsel_pos]-pw_gz$[slsel_name]a),
		pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    createconst(&gz$[slsel_name],ZGRAD,pw_gz$[slsel_name],MAX_PG_WAMP);
    createinstr( &gz$[slsel_name],(LONG)($[slsel_pos]),
		pw_gz$[slsel_name],ia_gz$[slsel_name]);
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/GRAD_UPDATE_TIME)),
		   pg_beta);
    createinstr( &gz$[slsel_name]d,(LONG)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait, 
	      pw_$[slsel_name]);
    /* Changed back resolution incase external rf used later in pulsegen. We need
     * original resolution to scale pulses that are external
     */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = temp_res_$[slsel_name];
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
SLICESELEXT(slsel_wgname, slsel_name, slsel_pos, slsel_dur, slsel_thk,
        slsel_flip, slsel_cycles:1.0,slsel_usegrad:1, res_g,extern_grad_file,
        res_rf, extern_rf_file, slsel_define:1,slsel_loggrd){
cv:{
  float a_g$[slsel_name];
  int ia_g$[slsel_name];
  int pw_g$[slsel_name]a;
  int pw_g$[slsel_name]d;
  int pw_g$[slsel_name];
  int res_g$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_g$[slsel_name] = $[slsel_dur];
  res_g$[slsel_name] = $[res_g];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
{
  float target;
  int rise_time, fall_time;
 
  gettarget(&target, $[slsel_wgname],&$[slsel_loggrd]);
  getramptime(&rise_time, &fall_time, $[slsel_wgname],&$[slsel_loggrd]);
 
  if (ampslice(&a_gx$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
                                         pw_$[slsel_name]),
               (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
               (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],target,
              rise_time,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],target,
              fall_time,(int)$[slsel_define])
      == FAILURE) return FAILURE;

  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/target;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
}
}
var:{
  EXTERN_FILENAME grad_$[slsel_name] = "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE g$[slsel_name]a = INITPULSE;                   
  WF_PULSE g$[slsel_name]  = INITPULSE;
  WF_PULSE g$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
 
subst:{
  {
    getbeta(&pg_beta, $[slsel_wgname], &$[slsel_loggrd]);
        /* First create the pulses */
    pulsename(&g$[slsel_name]a,"g$[slsel_name]a");
    pulsename(&g$[slsel_name],"g$[slsel_name]");
    pulsename(&g$[slsel_name]d,"g$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
    createramp(&g$[slsel_name]a,$[slsel_wgname],pw_g$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_g$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]a,(long)($[slsel_pos]-pw_g$[slsel_name]a),
                pw_g$[slsel_name]a,ia_g$[slsel_name]);
    if ($[slsel_usegrad] == PLAY_GFILE)
      {
        createextwave(&g$[slsel_name],$[slsel_wgname],
                res_g$[slsel_name],grad_$[slsel_name]);
      }
    else
      {
        createconst(&g$[slsel_name],$[slsel_wgname], pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &g$[slsel_name],(long)($[slsel_pos]),
                pw_g$[slsel_name],ia_g$[slsel_name]);

    createramp(&g$[slsel_name]d,$[slsel_wgname],pw_g$[slsel_name]d,MAX_PG_WAMP,
               (short)(maxGradRes*(pw_g$[slsel_name]d/GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]d,(long)($[slsel_pos]+pw_g$[slsel_name]),
                pw_g$[slsel_name]d,ia_g$[slsel_name]);

    /* Now create the rf pulse */                      
    createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
                pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&g$[slsel_name],&g$[slsel_name]a,
               &g$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
              pw_$[slsel_name]);
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELXEXT(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gx,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  int res_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  res_gx$[slsel_name] = $[res_gx];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xft,(int)$[slsel_define])
      == FAILURE) return FAILURE;
 
  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
}
var:{
  EXTERN_FILENAME grad_x$[slsel_name] = "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
    
  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].xbeta;
    createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(long)($[slsel_pos]-pw_gx$[slsel_name]a),
                pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    if ($[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gx$[slsel_name],XGRAD, 
		res_gx$[slsel_name],grad_x$[slsel_name]);
      }
    else
      {
	createconst(&gx$[slsel_name],XGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gx$[slsel_name],(long)($[slsel_pos]),
		pw_gx$[slsel_name],ia_gx$[slsel_name]);
    
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes * pw_gx$[slsel_name]d/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]d,(long)($[slsel_pos]+pw_gx$[slsel_name]),
		pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1, res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
	       &gx$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
  }
}
}

/********************************************************************************
** To facilitate system safety, pulse and waveform scaling needs to be performed
** inside the SLICESELXEXT macro. This macro will scale the gradient and rfpulse
** waveforms given the position of the rfpulse in the rfpulse structure. The
** gradient scaling is performed by default with larger pw, or explicitly with
** stretchpulse using 1/2 the rfpulse resolution. This is done to ensure that
** the new gradient pw/res is multiple of GRAD_UPDATE_TIME (4usec) while
** RF_UPDATE_TIME(2usec). We assume the gradient resolution <= rfpulse resolution
** in the files.
*********************************************************************************//* vmx 06/07/95 YI  changed res_$[] to int type */
SLICESELXEXT2(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gx,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  int res_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  res_gx$[slsel_name] = $[res_gx];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_x$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].xbeta;
    createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(LONG)($[slsel_pos]-pw_gx$[slsel_name]a),
		pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gx$[slsel_name],XGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gx$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gx$[slsel_name],(LONG)($[slsel_pos]),
			pw_gx$[slsel_name],ia_gx$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gx$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gx$[slsel_name], grad_z$[slsel_name]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gx$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gx$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gx$[slsel_name], (int)0, res_gx$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gx$[slsel_name],XGRAD, 
			  res_gx$[slsel_name], grad_z$[slsel_name]);
	    createinstr(&gx$[slsel_name],(LONG)($[slsel_pos]),
			pw_gx$[slsel_name],ia_gx$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gx$[slsel_name],XGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gx$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gx$[slsel_name],ia_gx$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gx$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]d,(LONG)($[slsel_pos]+pw_gx$[slsel_name]),
		pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure cycles have a value */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
		   &gx$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], rf_$[slsel_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name],rf_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
		   &gx$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELYEXT(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gy,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  int res_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  res_gy$[slsel_name] = $[res_gy];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name],$[slsel_loggrd].ty,
              $[slsel_loggrd].yrt,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name],$[slsel_loggrd].ty,
              $[slsel_loggrd].yft,(int)$[slsel_define]) == FAILURE) return FAILURE;
  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_y$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
    
  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
    pulsename(&gy$[slsel_name],"gy$[slsel_name]");
    pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].ybeta;
    createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gy$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gy$[slsel_name]a,(long)($[slsel_pos]-pw_gy$[slsel_name]a),
		pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
    if ($[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gy$[slsel_name],YGRAD, 
		res_gy$[slsel_name],grad_y$[slsel_name]);
      }
    else
      {
	createconst(&gy$[slsel_name],YGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gy$[slsel_name],(long)($[slsel_pos]),
		pw_gy$[slsel_name],ia_gy$[slsel_name]);
    createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/GRAD_UPDATE_TIME))
                   ,pg_beta);
    createinstr( &gy$[slsel_name]d,(long)($[slsel_pos]+pw_gy$[slsel_name]),
		pw_gy$[slsel_name]d,ia_gy$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1, res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gy$[slsel_name],
	       &gy$[slsel_name]a,&gy$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
  }
}
}

/********************************************************************************
** To facilitate system safety, pulse and waveform scaling needs to be performed
** inside the SLICESELYEXT macro. This macro will scale the gradient and rfpulse
** waveforms given the position of the rfpulse in the rfpulse structure. The
** gradient scaling is performed by default with larger pw, or explicitly with
** stretchpulse using 1/2 the rfpulse resolution. This is done to ensure that
** the new gradient pw/res is multiple of GRAD_UPDATE_TIME (4usec) while
** RF_UPDATE_TIME(2usec). We assume the gradient resolution <= rfpulse resolution
** in the files.
*********************************************************************************//* vmx 06/07/95 YI  changed res_$[] to int type */
SLICESELYEXT2(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gy,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  int res_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  res_gy$[slsel_name] = $[res_gy];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name],$[slsel_loggrd].ty,
	      $[slsel_loggrd].yrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name],$[slsel_loggrd].ty,
	      $[slsel_loggrd].yft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_y$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
    pulsename(&gy$[slsel_name],"gy$[slsel_name]");
    pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].ybeta;
    createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gy$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gy$[slsel_name]a,(LONG)($[slsel_pos]-pw_gy$[slsel_name]a),
		pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gy$[slsel_name],YGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gy$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gy$[slsel_name],(LONG)($[slsel_pos]),
			pw_gy$[slsel_name],ia_gy$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gy$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gy$[slsel_name], grad_z$[slsel_name]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gy$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gy$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gy$[slsel_name], (int)0, res_gy$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gy$[slsel_name],YGRAD, 
			  res_gy$[slsel_name], grad_z$[slsel_name]);
	    createinstr(&gy$[slsel_name],(LONG)($[slsel_pos]),
			pw_gy$[slsel_name],ia_gy$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gy$[slsel_name],YGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gy$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gy$[slsel_name],ia_gy$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gy$[slsel_name]d,(LONG)($[slsel_pos]+pw_gy$[slsel_name]),
		pw_gy$[slsel_name]d,ia_gy$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure we have a value for createsinc */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,
		   &gy$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], rf_$[slsel_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name],rf_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,
		   &gy$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELZEXT(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zrt,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zft,(int)$[slsel_define])
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
    
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gz$[slsel_name],ZGRAD, 
		res_gz$[slsel_name],grad_z$[slsel_name]);
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gz$[slsel_name],(long)($[slsel_pos]),
		pw_gz$[slsel_name],ia_gz$[slsel_name]);
    
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1,
	    res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);

}
}
}

/*Meng: 11/2/95, added to take name string for external pulse*/
SLICESELZEXT_INV(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zrt,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zft,(int)$[slsel_define])
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
/*  EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
*/
    
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gz$[slsel_name],ZGRAD, 
		res_gz$[slsel_name],$[extern_grad_file]);
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gz$[slsel_name],(long)($[slsel_pos]),
		pw_gz$[slsel_name],ia_gz$[slsel_name]);
    
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1,
	    res_$[slsel_name],$[extern_rf_file]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);

}
}
}

/********************************************************************************
** To facilitate system safety, pulse and waveform scaling needs to be performed
** inside the SLICESELZEXT macro. This macro will scale the gradient and rfpulse
** waveforms given the position of the rfpulse in the rfpulse structure. The
** gradient scaling is performed by default with larger pw, or explicitly with
** stretchpulse using 1/2 the rfpulse resolution. This is done to ensure that
** the new gradient pw/res is multiple of GRAD_UPDATE_TIME (4usec) while
** RF_UPDATE_TIME(2usec). We assume the gradient resolution <= rfpulse resolution
** in the files.
*********************************************************************************/
/* 3/13/95 YI  added SLICESELZEXT2.
               changed data type of res_*  from short to int. */

SLICESELZEXT2(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(LONG)($[slsel_pos]-pw_gz$[slsel_name]a),
		pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gz$[slsel_name],ZGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gz$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gz$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gz$[slsel_name], grad_z$[slsel_name]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gz$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gz$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gz$[slsel_name], (int)0, res_gz$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gz$[slsel_name],ZGRAD, 
			  res_gz$[slsel_name], grad_z$[slsel_name]);
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gz$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gz$[slsel_name],ia_gz$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(LONG)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure we have a value for createsinc */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], rf_$[slsel_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name],rf_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}

/**************************************************
 *  allowed string vars to be passed for filenames 
 * in SLICESELZEXT2 -AKG
 **************************************************/

SLICESELZEXT2STR(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
/* 
   EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
   EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]"; 
*/

  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(LONG)($[slsel_pos]-pw_gz$[slsel_name]a),
		pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gz$[slsel_name],ZGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gz$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gz$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gz$[slsel_name], $[extern_grad_file]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gz$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gz$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gz$[slsel_name], (int)0, res_gz$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gz$[slsel_name],ZGRAD, 
			  res_gz$[slsel_name], $[extern_grad_file]);
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gz$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gz$[slsel_name],ia_gz$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(LONG)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure we have a value for createsinc */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], $[extern_rf_file]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name], $[extern_rf_file] );
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}





/* changed res_$ from short to int YH */
SPACESAVER(spsave_wgname, spsave_name, spsave_res:1){

cv:{
  int res_$[spsave_name];
}

insert: cvinit =>{
  res_$[spsave_name] = $[spsave_res];
}

insert: predownload => {
}

var:{
  WF_PULSE $[spsave_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[spsave_name],"$[spsave_name]");
    createreserve(&$[spsave_name],$[spsave_wgname],
		  res_$[spsave_name]);
  }
}
}

SSPPACKET(sspp_name,sspp_pos,sspp_dur,sspp_pack,sspp_val:0) {
cv:{
  int ia_$[sspp_name];
}
insert:  cvinit => {
  ia_$[sspp_name] = $[sspp_val];
}
var:{
  WF_PULSE $[sspp_name] = INITPULSE;
}

insert: predownload => {
}

subst:{
  {
    pulsename(&$[sspp_name],"$[sspp_name]");
    createbits(&$[sspp_name],TYPSSP,sizeof($[sspp_pack])/2,$[sspp_pack]);
    createinstr( &$[sspp_name],(long)($[sspp_pos]),
		$[sspp_dur],ia_$[sspp_name]);
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
THREEDIMDAB(threeddab_name, PosReadOut, threeddab_pos:DEFAULTPOS) {
var:{
  WF_PULSE $[threeddab_name] = INITPULSE;
}
insert: predownload => {
}

subst:{
  {
    pulsename(&$[threeddab_name],"$[threeddab_name]");
    create3dim(&$[threeddab_name],(long)($[PosReadOut]),(long)($[threeddab_pos]));
  }
}
}

/********************************************************
 * 08/01/95 Changed from SSPDS+DABDC to SSPTD+EDC - RJL
 * for CERD changed. DABDC no longer required. Since EDC
 * a global variable and not a #define constant, cannot be
 * located in variable initialization of pack.
 ********************************************************/
TNSON(tnson_name,tnson_pos) {
var:{
  WF_PULSE $[tnson_name] = INITPULSE;
  short $[tnson_name]_pack[4] = {0,SSPOC+DREG,SSPD+DCBL,SSPDS};
}
subst:{
  {
    $[tnson_name]_pack[0] = SSPDS+EDC;
    pulsename(&$[tnson_name],"$[tnson_name]");
    createbits(&$[tnson_name],TYPSSP,4,$[tnson_name]_pack);
    createinstr( &$[tnson_name],(LONG)($[tnson_pos]),4,0);
  }
}
}

/********************************************************
 * 08/01/95 Changed from SSPDS+DABDC to SSPTD+EDC - RJL
 * for CERD changed. DABDC no longer required.Since EDC
 * a global variable and not a #define constant, cannot be
 * located in variable initialization of pack.
 ********************************************************/
TNSOFF(tnsoff_name,tnsoff_pos) {
var:{
  WF_PULSE $[tnsoff_name] = INITPULSE;
  short $[tnsoff_name]_pack[4] = {0,SSPOC+DREG,SSPD,SSPDS};
}
subst:{
  {
    $[tnsoff_name]_pack[0] = SSPDS+EDC;
    pulsename(&$[tnsoff_name],"$[tnsoff_name]");
    createbits(&$[tnsoff_name],TYPSSP,4,$[tnsoff_name]_pack);
    createinstr( &$[tnsoff_name],(LONG)($[tnsoff_pos]),4,0);
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
TRAPEZOID(trp_wgname,trp_name,trp_pos,trp_area,trp_define:1,trp_loggrd) {

cv:{
  float a_$[trp_name];
  int ia_$[trp_name];
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
}

insert: cvinit => {
}
insert: predownload => {
{
  float target;
  int rtime, ftime;

  gettarget(&target, $[trp_wgname],&$[trp_loggrd]);
  if ($[trp_define] == TYPDEF) {
        getramptime(&rtime, &ftime, $[trp_wgname],&$[trp_loggrd]);
        if (amppwgrad((float)($[trp_area]),target, 0.0, 0.0, rtime,
                                  MIN_PLATEAU_TIME,
                                  &a_$[trp_name], &pw_$[trp_name]a, &pw_$[trp_name],
                                  &pw_$[trp_name]d) == FAILURE)
          return FAILURE;
  }
  
  ia_$[trp_name] = (a_$[trp_name] / target) * MAX_PG_IAMP;
}
}

subst:{

  trapezoid($[trp_wgname], "$[trp_name]", &$[trp_name], &$[trp_name]a,
                        &$[trp_name]d, pw_$[trp_name], pw_$[trp_name]a, pw_$[trp_name]d,
                        ia_$[trp_name], 0, 0, 0, 0, $[trp_pos]-pw_$[trp_name]a, TRAP_ALL,
                        &$[trp_loggrd]);
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
TRAPEZOID2(trp_wgname,trp_name,trp_pos,trp_parts:TRAP_ALL,
         trp_start:0,trp_end:0,trp_scale:1.0,trp_loggrd) {

cv:{
  float a_$[trp_name];
  float a_$[trp_name]a;
  float a_$[trp_name]b;
  int ia_$[trp_name];
  int ia_$[trp_name]wa;
  int ia_$[trp_name]wb;
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
}
 
insert: cvinit => {
}
insert: predownload => {
 
{
   float target;

   gettarget(&target,$[trp_wgname],&$[trp_loggrd]);
   ia_$[trp_name] = ($[trp_scale] * a_$[trp_name] / target) *
                    MAX_PG_IAMP;
   ia_$[trp_name]wa = ($[trp_scale] * a_$[trp_name]a / target) *
                          MAX_PG_IAMP;
   ia_$[trp_name]wb = ($[trp_scale] * a_$[trp_name]b / target) *
                      MAX_PG_IAMP;
}
}

subst:{
    trapezoid($[trp_wgname],"$[trp_name]",
              &$[trp_name],&$[trp_name]a,&$[trp_name]d,
              pw_$[trp_name],pw_$[trp_name]a,pw_$[trp_name]d,
              ia_$[trp_name],ia_$[trp_name]wa,ia_$[trp_name]wb,
              $[trp_start],$[trp_end],$[trp_pos],$[trp_parts],
                          &$[trp_loggrd]);
}
}

WAIT(wait_wgname,wait_name,wait_pos,wait_dur) {
cv:{
  int pw_$[wait_name];
}
insert:  cvinit => {
  pw_$[wait_name] = $[wait_dur];
}
var:{
  WF_PULSE $[wait_name] = INITPULSE;
}
insert: predownload => {
}

subst:{
  {
    pulsename(&$[wait_name],"$[wait_name]");
    createconst(&$[wait_name],$[wait_wgname],pw_$[wait_name],(short)0); 
    createinstr( &$[wait_name],(long)($[wait_pos]),pw_$[wait_name],0);
  }
}
}


SINGLE_TRAP( trp_wgname, trp_name, trp_pos, trp_area:0.0, trp_scale:1.0,
             trp_define:TYPDEF, trp_parts:TRAP_ALL, trp_lead:0, trp_lead_pw:0,
             trp_loggrd )
{
  /*
    Built from MEMTRAP().         TKF 14-Nov-95.

    Create a Trapezoid completely in memory. This really burns memory
    but it only requires one update call. It was written to address 
    a performance issue in the ISI update for the fgre3d killer/rewinder. 
    The pulse is first created in user allocated memory with rsp 
    calls then moved into reserved waveform memory. The user memory is
    then freed.
    
    Supports sloped trapezoid. Special for phase encode.
    trp_lead = 0 no leading edge, 1=leading edge.
    trp_lead_pw = leading edge pulse width
    
    If this is not a sloped trapezoid, builds single normal
    trapezoid with waveform amplitude at max_pg_wamp.
	 */


cv:{
  float a_$[trp_name];
  float a_$[trp_name]a;
  float a_$[trp_name]b;
  int ia_$[trp_name];
  int ia_$[trp_name]wa;
  int ia_$[trp_name]wb;
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name]f;    /* pulse width of leading edge */
  int pw_$[trp_name];
  int res_$[trp_name];
  int per_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
  s16 *$[trp_name]_mem;		/* temporary memory pointer */
  s16 $[trp_name]_indx;		/* indx into user memory */
}
insert: cvinit => {
}
insert: predownload => {
{
   float target;
   int rtime,ftime;

   gettarget(&target, $[trp_wgname], &$[trp_loggrd]);
   getramptime(&rtime,&ftime,$[trp_wgname], &$[trp_loggrd]);
   if ($[trp_define] == TYPDEF) {
     if (amppwgrad((float)($[trp_area]),target,0.0,0.0,rtime,MIN_PLATEAU_TIME,
				 &a_$[trp_name], &pw_$[trp_name]a, &pw_$[trp_name],
				 &pw_$[trp_name]d) == FAILURE) return FAILURE;
   }
   if ($[trp_parts] & TRAP_SLOPED)
     {
       ia_$[trp_name] = ($[trp_scale] * a_$[trp_name] / target) * MAX_PG_IAMP;
       ia_$[trp_name]wa = ($[trp_scale] * a_$[trp_name]a / target) * MAX_PG_IAMP;
       ia_$[trp_name]wb = ($[trp_scale] * a_$[trp_name]b / target) * MAX_PG_IAMP;
     }
   else  /* standard trapezoid */
     {
       ia_$[trp_name] = (a_$[trp_name] / target) * MAX_PG_IAMP;
       ia_$[trp_name]wa =  MAX_PG_WAMP;
       ia_$[trp_name]wb = MAX_PG_WAMP;
     }

   if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2) ||
       ($[trp_wgname]==TYPTHETA)||($[trp_wgname]==TYPOMEGA))
     {				/* Determine min period */
       per_$[trp_name] = (RF_UPDATE_TIME); 
     }
   else
     {
       per_$[trp_name] = (GRAD_UPDATE_TIME);
     }

   /* set leading edge pulse width */
   if ($[trp_lead] != 0)
     pw_$[trp_name]f = IMax(2,GRAD_UPDATE_TIME,$[trp_lead_pw]);
   else
     pw_$[trp_name]f = 0;

   if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2) ||
       ($[trp_wgname]==TYPTHETA)||($[trp_wgname]==TYPOMEGA))
     pw_$[trp_name] = 0;    /* no need for leading edge if rf */

   res_$[trp_name] =		/* Find resolution */
     (pw_$[trp_name]f + pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d)/
       per_$[trp_name];
}
}
subst:{
    {
#ifdef IPG
        /* Allocate user memory */
        $[trp_name]_mem = (s16 *)AllocNode( res_$[trp_name]*sizeof(s16));
        $[trp_name]_indx = 0;

        getbeta(&pg_beta, $[trp_wgname], &$[trp_loggrd]);

        /* leading edge of zeros */
        if (($[trp_lead] != 0) && (pw_$[trp_name]f != 0))
        {
            uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
                   (pw_$[trp_name]f/per_$[trp_name]),
                   (short)0, (short)0, pg_beta );
            /* Clear EOW */
            $[trp_name]_indx = ( pw_$[trp_name]f / per_$[trp_name] );
            $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
        }
        /* Up ramp */
        uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
               (pw_$[trp_name]a/per_$[trp_name]),
               (short) 0, ia_$[trp_name]wa , pg_beta);
        /* Clear EOW */
        $[trp_name]_indx = ( (pw_$[trp_name]a + pw_$[trp_name]f) / per_$[trp_name] );
        $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
        /* Top const */
        uramp((&$[trp_name]_mem[$[trp_name]_indx]),
              (pw_$[trp_name]/per_$[trp_name]),
              ia_$[trp_name]wa, ia_$[trp_name]wb, pg_beta);
        /* Clear EOW */
        $[trp_name]_indx = ( (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]f ) / per_$[trp_name] );
        $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
        /* Decay Ramp */
        uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
               (pw_$[trp_name]d/per_$[trp_name]),
               ia_$[trp_name]wb, (short) 0, pg_beta );

        /* Create pulse and memory */
        pulsename( &$[trp_name], "$[trp_name]" );
        createreserve( &$[trp_name], $[trp_wgname], res_$[trp_name] );
        createinstr( &$[trp_name],(LONG)($[trp_pos]-pw_$[trp_name]a - 
                                         pw_$[trp_name]f),
                     (pw_$[trp_name]f + pw_$[trp_name]a + 
                      pw_$[trp_name] + pw_$[trp_name]d), 
                     ia_$[trp_name] );
        /* Move user pulse into waveform mem */
        $[trp_name]_mem[res_$[trp_name]-1] |= WEOS_BIT;  
        movewaveimm($[trp_name]_mem, &$[trp_name], 
                    (int)0, res_$[trp_name], TOHARDWARE);
        /* Free user memory */
        FreeNode( $[trp_name]_mem );
        if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2))
        {				/* Add rf control bits if rf pulse */
            addrfbits(&$[trp_name],0,(LONG)($[trp_pos]),
                      (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d));
        }
#else /* !IPG */
        /* When the SINGLE_TRAP macro is expanded on the Host, we want a real
           trapezoid (a TRAPEZOID2) to be created instead. Note that the start
           and end amplitudes are not provided as arguments to this macro and
           are assumed to be zero. Also, the position of the trapezoid does
           not include the attack and leading parts. This is the same thing 
           that is done in the uramp() calls above. - GFN - 12/Aug/1998 */
        trapezoid( $[trp_wgname], "$[trp_name]",
                   &$[trp_name], &$[trp_name]a, &$[trp_name]d,
                   pw_$[trp_name], pw_$[trp_name]a, pw_$[trp_name]d,
                   ia_$[trp_name], ia_$[trp_name]wa, ia_$[trp_name]wb,
                   0 /* trp_start */, 0 /* trp_end */,
                   (LONG)($[trp_pos] - pw_$[trp_name]a - pw_$[trp_name]f),
                   $[trp_parts], &$[trp_loggrd] );
#endif /* IPG */
    }
}
}

/* This macro sets up the proper SSP control words that tells the
   CERD to reroute the data from the VSB bus to the XD bus. This is
   used to send data to the SPU.
*/
XDCNTRL(spu_pack_name, spu_pack_pos){
var:{
  WF_PULSE $[spu_pack_name] = INITPULSE;
  short $[spu_pack_name]_bits[PASS_LENGTH];
}
insert: predownload => {
}
insert: cvinit => {
}
subst:{
  {
    $[spu_pack_name]_bits[0] = SSPDS + DABDC;
    $[spu_pack_name]_bits[1] = SSPOC + DPASS;
    $[spu_pack_name]_bits[2] = SSPD + 0x10;
    /* Initialize to normal routing of data */
    $[spu_pack_name]_bits[3] = SSPD;
    $[spu_pack_name]_bits[4] = SSPDS;
    $[spu_pack_name]_bits[5] = SSPOC;
    $[spu_pack_name]_bits[6] = SSPDS;

    pulsename(&$[spu_pack_name],"$[spu_pack_name]");

    createbits((WF_PULSE *)&$[spu_pack_name], (WF_PROCESSOR)TYPSSP,
        (SHORT)pass_length, (SHORT *)$[spu_pack_name]_bits);

    createinstr((WF_PULSE *)&$[spu_pack_name], (LONG) $[spu_pack_pos],
        (LONG)pass_length,0L);

    $[spu_pack_name].tag = SSPPASS;
 }
}
}


