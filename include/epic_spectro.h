/************************************************

	epic_spectro.h

	This file contains all macros specific for spectroscopy psds.


	Date		Author		Comments
	7/31/96		Pom		first version for testing
                                        proton on BB-CERD.
************************************************/

@global
#define SPECPSD_CERD1_H1 0
#define SPECPSD_CERD2_H1 1
#define SPECPSD_CERD1_MNS 2
#define SPECPSD_CERD2_MNS 3

/*#include "specrfbits.c"*/

@pulsedef

SINCBB1(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
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
        addrfbitsbb(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
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

SINCBB2(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
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
        addrfbitsmns(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
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

SINCBB3(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
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
        addrfbitsmns1(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
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

EXTWAVEBB1(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
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
        addrfbitsbb(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) +
                 psd_rf_wait,pw_$[ext_name]);
      }
    else
      {
        createinstr( &$[ext_name],(long)($[ext_pos]),
                    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

EXTWAVEBB2(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
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
        addrfbitsmns(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) +
                 psd_rf_wait,pw_$[ext_name]);
      }
    else
      {
        createinstr( &$[ext_name],(long)($[ext_pos]),
                    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

EXTWAVEBB3(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
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
        addrfbitsmns1(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) +
                 psd_rf_wait,pw_$[ext_name]);
      }
    else
      {
        createinstr( &$[ext_name],(long)($[ext_pos]),
                    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

CONSTBB1(cnst_wgname,cnst_name,cnst_pos,cnst_dur,cnst_amp,cnst_loggrd) {
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
        addrfbitsbb(&$[cnst_name],0,(long)($[cnst_pos]),pw_$[cnst_name]);
      }
  }
}
}


CONSTBB2(cnst_wgname,cnst_name,cnst_pos,cnst_dur,cnst_amp,cnst_loggrd) {
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
        addrfbitsmns(&$[cnst_name],0,(long)($[cnst_pos]),pw_$[cnst_name]);
      }
  }
}
}

CONSTBB3(cnst_wgname,cnst_name,cnst_pos,cnst_dur,cnst_amp,cnst_loggrd) {
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
        addrfbitsmns1(&$[cnst_name],0,(long)($[cnst_pos]),pw_$[cnst_name]);
      }
  }
}
}

SLICESELZBB(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
        slsel_cycles:1.0,slsel_define:1,slsel_loggrd,slsel_type:0){
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
    createsinc(&$[slsel_name],TYPRHO2,res_$[slsel_name],
               MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
                pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
               &gz$[slsel_name]d);
    specrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) +
                psd_rf_wait,pw_$[slsel_name],$[slsel_type]);

  }
}

SLICESELZEXTBB(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
        slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
        res_rf, extern_rf_file, slsel_define:1, slsel_loggrd,slsel_type:0){
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
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

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

    createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
                pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
               &gz$[slsel_name]d);
    specrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf
_wait,
              pw_$[slsel_name],$[slsel_type]);

  }
}


SINCBB(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
         snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46,snc_loggrd,snc_type:0){
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
subst:{
    pulsename(&$[snc_name],"$[snc_name]");
    createsinc(&$[snc_name],$[snc_wgname],res_$[snc_name],
               MAX_PG_WAMP,cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
        ($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
        createinstr( &$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
                    pw_$[snc_name],ia_$[snc_name]);
        specrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
                  pw_$[snc_name],$[snc_type]);
      }
    else
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}

EXTWAVEBB(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
        extern_file, ext_offset:0, ext_loggrd, ext_type:0){

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
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}

var:{

  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
                      res_$[ext_name],fileloc_$[ext_name]);
    if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
        ($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
      {
        createinstr( &$[ext_name],(long)($[ext_pos]) + psd_rf_wait,
                    pw_$[ext_name],ia_$[ext_name]);
        specrfbits(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) +
                 psd_rf_wait,pw_$[ext_name],$[ext_type]);
      }
    else
      {
        createinstr( &$[ext_name],(long)($[ext_pos]),
                    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}

CONSTBB(cnst_wgname,cnst_name,cnst_pos,cnst_dur,cnst_amp,cnst_loggrd,cnst_type:0) {
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
    pulsename(&$[cnst_name],"$[cnst_name]");
    createconst(&$[cnst_name],$[cnst_wgname],pw_$[cnst_name],MAX_PG_WAMP);
    createinstr( &$[cnst_name],(long)($[cnst_pos]),
                pw_$[cnst_name],ia_$[cnst_name]);
    if (($[cnst_wgname]==TYPRHO1)||($[cnst_wgname]==TYPRHO2))
      {
        specrfbits(&$[cnst_name],0,(long)($[cnst_pos]),pw_$[cnst_name],$[cnst_type]);
      }
  }
}

