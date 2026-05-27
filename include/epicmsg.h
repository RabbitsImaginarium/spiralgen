/*
 * GE Medical Systems
 * Copyright (C) 1989-1998 The General Electric Company
 * 
 * $Source: %M% $
 * $Revision: %I% $  $Date: %G% %U% $
 * 
 * This header file contains the enumerator types that will be passed
 * to the MsgHndlr when an error is logged.  It also contains the
 * error messages that will be displayed in simulation run.
 * This header file contains the enumerator types that will be passed
 * to the MsgHndlr when an error is logged.  It also contains the
 * error messages that will be displayed in simulation run.
 * The enumerator types indicates to the MsgHndlr how it will parse its
 * parameters.  
 * There is one to one correspondence between the EMT enumerator types
 * and the ERMES enumerator types that will be logged in real-time.
 * 
 * Language : ANSI C
 * Author   : B. L. Mazin
 * Date     : 30/Nov/1989
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
  5.2.1    04/May/1992  B.L.M.      Created new messages for Invalid Value.
  5.2.2    11/May/1992  B.L.M.      Modified the message for rfupd.
  8.3      05/Oct/1998  GFN         Added EMT_INVLD_CONFIG and
                                    EMT_INVLD_TIME_FOUND.
                                    Added #ifndef wrapper to prevent multiple
                                    inclusions.
 */


#ifndef epicmsg_h
#define epicmsg_h

/* Error Checking Constants */
#define MSG_DONE        0
#define MSG_PULSE       1
#define MSG_INSTR       2
#define MSG_FORMAT      3
#define MSG_FILESTREAM  4
#define MSG_FILEOPEN    5
#define MSG_FILECLOSE   6


/* only do this once in any given compilation.*/
#ifndef  epicmsg_INCL



#endif /* epicmsg_INCL */
#define UNKNOWN_IT        	-1   /* Iteration for instruction is unknown */

#define ROUTINE_PBM             0
#define CODING_PBM		1
#define FILE_PBM		2
#define HARDWARE_PBM		3
#define SOFTWARE_PBM		4
#define WARNING_PBM     	5

#define FILE_ERR 		0
#define CODING_KEY_ERR 		1
#define PULSE_ERR 		2
#define CONST_EXT_ERR 		3
#define HADAMARD_EXT_ERR	4
#define RAMP_EXT_ERR		5
#define SINC_EXT_ERR		6
#define SINUSOID_EXT_ERR	7
#define INSTR_ERR       	8

/*****************/
#define EMT_ALLOC	         9
#define EMT_UNBALANCEPULSE      10
#define EMT_BTRAPGAP            11
#define EMT_BTRAPRAMPS          12
#define EMT_CREATEINSTR         13
#define EMT_INVLD_BRIDG         14
#define EMT_INVLD_PULSEPOS      15
#define EMT_INSTROVERLAP        16
#define EMT_START_BTIME         17
#define EMT_FREE                18
#define EMT_TIMING_OVERFLOW     19
#define EMT_INVLD_VALUE         20
#define EMT_NO_SSP              21
#define EMT_WRONG_PULSE         22
#define EMT_PULSE_SHORT         23
#define EMT_INVLD_SSPATTR       24
#define EMT_INVLD_VARNAME       25
#define EMT_INVLD_FVALUE        26
#define EMT_MACHINE_ADJ         27

/******* New Messages For Invalid Values ****/
#define EMT_INVLD_BRIDGE_TYPE   28
#define EMT_INVLD_PULSE_RESOL   29
#define EMT_DAB_SLOT_NO         30
#define EMT_DAB_RECVR_NO        31
#define EMT_CINE_FLAG_MSK       32
#define EMT_INVLD_RFUPA_OFF     33
#define EMT_INVLD_RFUPD_OFF     34
#define EMT_INVLD_RFSTART       35
#define EMT_INVLD_INSTR_IX      36
#define EMT_INVLD_WAIT_PERIOD   37
#define EMT_INVLD_INSTR_START   38
#define EMT_INVLD_INSTR_PERIOD  39
#define EMT_INVLD_INSTR_AMPLITUDE    40
#define EMT_INVLD_SSP_SHUTDOWN_DELAY 41
#define EMT_INVLD_HW_INSTR      42
#define EMT_INVLD_RESOL_IX      43
#define EMT_INVLD_EOS_MSK       44
#define EMT_INVLD_PHASE         45
#define EMT_INVLD_WAVEGEN_VALUE 47
#define EMT_INVLD_NSINC_CYCLES  48
#define EMT_INVLD_START_PHASE   49
#define EMT_INVLD_PHASE_LENGTH  50
#define EMT_INVLD_CONFIG        51
#define EMT_INVLD_TIME_FOUND    52



#ifdef PSD_MSGHNDLR
CHAR *pgen_error_hdrs[] = {
 "\n### Routine <%s> ###\n\n",
"\n   *** Coding Error ***\n",
"\n   *** File Error ***\n",
"\n   *** Internal Software Error ***\n",
"\n   *** Software Error ***\n",
"\n   ***  Warning Only ***\n",
};

CHAR *pgen_error_message[] = {
 "    File-> %s \n",
 "    Invld key: %d\n",
 "    <Pulse>\n    Pulse Name:%-10s\n    Type:%-10s  Board:%-6s  Resol:%-8d\n",
 "    Amp:%-d\n",
 "    Amp:%-d Sep:%-d NSinc Cycles:%-f Alpha:%-f\n",
 "    Start Amp:%-d  End Amp:%-d\n",
 "    Amp:%-d Nsinc Cycles:%-f Alpha:%-f\n",
 "    amp:%-d start phase:%-f Phase Length:%-f Offset:%-f\n",
 "    <Instr>\n    Pulse Name:%-10s\n    Iteration:%-d  Start:%-d  End:%-d \n    Amp:%-d Period:%-d\n",
 "  Failed Allocating Memory For: %s\n\n",
 "  A pulse is missing in one of the bridged trapezoids.\n Its position in the pulse list is missing at: %d\n\n",
 "  The duration between the two constants parts of the bridged traps are not consistent (was:%d) (is:%d)\n  Check the pulse widths of the bridged ramps.\n\n",
 "  Two ramps that are bridged do not have the same start and end times.\n The attack and decay ramps are in the ordinal positions: (%d) (%d)\n\n",
 "  Failure creating instr -> %s \n\n",
 "  Invalid bridge \n\n",
 "  Invalid position of trapezoid pulse in time-line:(ord pos:%-d)\n\n",
 "  The two instructions on the same waveform generator overlap. \n\n",
 "  Invalid start of ramp %d : Invld Bridge \n\n",
 "  %s should have been freed \n\n",
 "  An instruction on the waveform generator (%d) exceeds the act_tr \n\n",
 "  Invalid value (%d) for %s\n\n",
 "  Generator is not the SSP board\n\n",
 "  Wrong pulse for command\n\n",
 "  Not enough pulses in list %d\n\n",
 "  Invld SSP attrbutes (s_attr:%d) (direction:%d)\n\n",
 "  Variable name - %s - not found in pulse structure \n\n",
 "  Invalid value (%7.3f) for %s\n\n",
 "  The pulse's %s must be divisible by the hardware's cycle rate * resolution\n    (value:%d) (hw rate:%d) (resol:%d)\n\n",
 "  Waveform type %d is invalid, can not bridge with waveform\n\n",
 "  Resolution of %d is out of range\n\n",
 "  Slot number %d for dab packet is out of range\n\n",
 "  Receiver value %d for dab packet is out of range\n\n",
 "  Unknown CINE Flag mask of %d\n\n",
 "  RFUPA offset must be a negative number, rfupa currently set to %d\n\n",
 "  RFUPD offset must be a positive number, rfupd currently set to %d\n\n",
 "  Start of rf is invalid, rfstartmod_off currently set to %d\n\n",
 "  Index %d for instruction is out of range\n\n",
 "  Invalid period %d for wait instruction on processor %s\n\n",
 "  Can not start the waveform at %d\n\n",
 "  Invalid period of %d for instruction\n\n",
 "  Amplitude of %d is out of range for instruction\n\n",
 "  Shutdown delay %d on SSP must be aligned with the gradients\n\n",
 "  Must define hardware instr before calling this routine\n\n",
 "  Index %d must be within the range of the pulse resolution\n\n",
 "  EOS flag of %d is invalid. Must be set to either 0 or 1\n\n",
 "  Phase value of %d is out of range\n\n",
 "  %d does not correspond to a waveform generator listed in pulsege.h\n\n",
 "  Invalid value of %f for number of sinc cycles in pulse\n\n",
 "  Invalid phase start of %f in sinusoid pulse\n\n",
 "  Invalid phase length of %f in sinusoid pulse\n\n",
};
#else
extern CHAR *pgen_error_hdrs[];
extern CHAR *pgen_error_message[];
#endif

#define  epicmsg_INCL

#endif /* epicmsg_h */

