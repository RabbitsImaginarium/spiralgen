/*
 * GE Medical Systems
 * Copyright (C) 1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * 
 * 
 * Language : ANSI C
 * Author   : 
 * Date     : 
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 8.3       06-Oct-1998  GFN         Added header info and #ifndef wrapper to
                                    prevent multiple inclusions.
                                    Put definition of _PGEN_start_time into
                                    an #ifndef wrapper.

 */

#ifndef pg_ext_h
#define pg_ext_h

#define NUM_PGENS 118

#define pulsegen_ix 0
#define trapezoid_ix	1
#define AddToInstrQ_ix 2
#define BridgeTrap_ix 3
#define BuildBridges_ix 4
#define CleanUp_ix 5      
#define CreatePulse_ix 6
#define GetMinPeriod_ix 7
#define GetPulseInstr_ix 8
#define EpicConf_ix 9
#define FreePsdsQ_ix 10
#define SetResol_ix 11
#define TimeHist_ix 12
#define acqctrl_ix 13
#define acqq_ix      14
#define acqq2_ix       15
#define addrfbits_ix     16
#define attenflag_ix       17
#define attenlockon_ix 18
#define attenlockoff_ix  19
#define buildinstr_ix      20
#define calcdelay_ix         21
#define calciphase_ix 22
#define copyframe_ix  23
#define create3dim2_ix 24
#define createatten_ix 25
#define createbits_ix  26
#define createcine_ix  27
#define createconst_ix 28
#define createextwave_ix 29
#define createhad_ix 30
#define createhsdab_ix 31
#define createinstr_ix 32
#define createpass_ix  33
#define createramp_ix  34
#define createreserve_ix 35
#define createseq_ix     36
#define createsinc_ix    37
#define createsinu_ix    38
#define createtraps_ix   39
#define create3dim_ix    40
#define createubr_ix     41
#define epiacqq_ix       42
#define getctrl_ix       43
#define getiamp_ix       44
#define getieos_ix       45
#define getperiod_ix     46
#define getphase_ix      47
#define getpulse_ix 48
#define getssppulse_ix 49
#define getwamp_ix  50
#define getiwave_ix 51
#define getwave_ix  52
#define getweos_ix  53
#define initfastrec_ix 54
#define linkpulses_ix  55
#define load3d_ix      56
#define load3decho_ix  57
#define loadcine_ix    58
#define loaddab_ix     59
#define loaddab2_ix    60
#define loaddabslice_ix 61
#define loaddaboper_ix  62
#define loaddabview_ix  63
#define loaddabecho_ix  64    
#define loaddabset_ix   65
#define loadhsdab_ix    66
#define movewaveimm_ix  67
#define pbeg_ix         68
#define pmid_ix         69
#define pend_ix          70
#define pbegall_ix       71
#define pmidall_ix       72
#define pendall_ix       73
#define pbegallssp_ix    74
#define pendallssp_ix    75
#define psdexit_ix	 76
#define pulsename_ix     77
#define rfoff_ix         78
#define rfon_ix          79
#define scopeon_ix       80
#define scopeoff_ix      81
#define setattenlock_ix  82
#define setctrl_ix       83
#define setfastdly_ix 	84
#define setfrequency_ix   85
#define setfreqphase_ix   86
#define setiamp_ix        87
#define setiampall_ix     88   
#define setiampt_ix       89
#define setiampimm_ix     90
#define setiamptimm_ix    91
#define setieos_ix        92
#define setperiod_ix      93
#define setiphase_ix      94
#define setphase_ix       95
#define setrf_ix          96
#define setrfltrs_ix      97
#define settransceiver_ix 98
#define setwamp_ix        99
#define setwampimm_ix     100
#define setwave_ix        101
#define setweos_ix        102
#define setPSDtags_ix	103
#define sspextload_ix   104
#define sspinit_ix	105
#define sspload_ix 106
#define stretchpulse_ix 107
#define syncon_ix       108
#define syncoff_ix      109
#define DeleteFromQueue_ix 110
#define AddRFiwait_ix 111
#define PlayOutSSP_ix 112
#define GetFreqInstrNode_ix 113
#define BuildEachInstr_ix 114
#define AllocNode_ix 115
#define FreeNode_ix 116
#define FreePSDHeap_ix 117

#ifdef IPGHWTGT
static long _PGEN_start_time;
#endif /* IPGHWTGT */

#endif /* pg_ext_h */

