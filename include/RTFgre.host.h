/* 	GE Medical Systems
 *	Copyright (C) 1998- The General Electric Company
 *  RTFgre.h
 *  
 * 	Interface file for RTFgre.e 
 *
 *  Language : EPIC/ANSI C
 *  Author   : Roshy J. Francis. 
 *  Date     : 16-Sep-1998 
 */
/* do not edit anything above this line */

/*
   Version    				Author     Date       Comment
----------------------------------------------------------------------
/main/mr_main/roshy_rtia	RJF		   19/Oct/1998	Modified to Include 
													only public functions.
													Others are declared static in RTFgre.e now.
													static Prototypes have been added to RTFgre.e
 */

#ifndef RTFgre_host_h
#define RTFgre_host_h


STATUS RTIAFlowCompPulseTableInit(void);

STATUS RTIA_cvinit (int featureflag, int *oblmethod,
					int *bridge, int *contflag);

STATUS RTIA_cveval_init (int featureflag, int *psdfov, 
				  int *dda, int *ssi_time, int *phorder);

STATUS CalcFlowCompMinTimes (int TExB, float AmpRdOut, int NonTeTime, 
               float FracEchoFactor, int RdOutPwFrac, int RdOutPwFull,
               int cssatime, int spsattime, int hard180time, 
			   int *FlowCompMinTRTime, 
			   int *FlowCompMinTETime, int featureflag);

STATUS RTIA_set_times(int featureflag, int FcMinTR, int FcMinTE, 
				  int NonFcMinTR, float *use_tr, int *act_tr_flowcomp, 
				  int *act_te_flowcomp) ;

STATUS RTIA_cvcheck(int featureflag);

STATUS RTIA_predownload(void);

STATUS RTIA_get_tmin (int index, int *Tmin, int tminsatoff,
				  int cssattime, int spsattime, 
				  int hard180time, int featureflag);

STATUS CopyToFlowCompRFPulse (RF_PULSE *main_pulse);

STATUS RTIA_modify_pulselists (int featureflag,
                        int index,
                        GRAD_PULSE *gradx_list,
                        GRAD_PULSE *grady_list,
                        GRAD_PULSE *gradz_list,
                        RF_PULSE *rfpulse_list,
                        int flowcomp_pulselist_flag);

STATUS
RTIA_select_safe_params ( int *tmin_temp ,
                          int *tmintotal,
                          int *minseqrfamp,
                          int *minseqgram,
                          int *minseqgrddrv,
                          int *minseqcoil,
                          int *maxseqsar,
                          int *maxslicesar,
                          float *avesar,
                          float *peaksar,
                          float *pwrmon_pw ,
                          float *pwrmon_dc ,
                          float *pwrmon_amp,
                          RTIA_POWERMON_VALUES *powermon_array,
                          RTIA_SAFE_TIMES *time_array, int featureflag);

STATUS RTIA_set_avminte (int *AvminTE, int FlowCompMinTE, int featureflag);

STATUS RTIA_set_avmintr (int *AvminTR, int FlowCompMinTR, int featureflag);

STATUS RTIA_set_powermon(ENTRY_POINT_TABLE *entryPoint, 
                         FLOAT pw, FLOAT duty_cycle, 
                         FLOAT amp, INT max_realtime_tr);

STATUS RTIA_calc_powermon_values(  INT entry,
                            INT numPulses,
                            RF_PULSE *rfpulse,
                            INT sarTseq,
                            DOUBLE maxB1,
                            RTIA_POWERMON_VALUES *rtia_pwrmon_safe);

STATUS RTIA_dummy_sequence_eval ( int featureflag , int ssitime, int *dummy_seq_time); 

#endif /* RTFgre_host_h */

