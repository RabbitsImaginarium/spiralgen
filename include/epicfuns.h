/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1989 The General Electric Company
 *
 *      Include File Name:  epicfuns.h   
 *      Developer:          B.L. Mazin
 *
 * $Source: epicfuns.h $
 * $Revision: 1.14 $  $Date: 6/9/98 19:35:17 $
 */

/*@Synopsis 
*/     

/*@Description
     
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  epicfuns_h
#define  epicfuns_h

/* PSD related subroutines */

/************************************************/
/* Commands that enable the user to review and modify the Pulse Waveform
 and Instructions in memory. */


STATUS attenlockon(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS attenlockoff(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS BoreOverTemp(
#ifdef __STDC__
    INT monitor_temp, INT debug
#endif /* __STDC__ */
);
STATUS buildinstr(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);
STATUS calcdelay(
#ifdef __STDC__
    FLOAT *delay_val, INT control, INT fastrec, INT lpf, DOUBLE gldelayx,
    DOUBLE gldelayy, DOUBLE gldelayz, INT *defaultdelay, INT nslices,
    INT debug, long (*rsprot)[9]
#endif /* __STDC__ */
);
STATUS calcdelayfile(
#ifdef __STDC__
    FLOAT *delay_val, INT control, INT fastrec, INT lpf, DOUBLE gldelayx,
    DOUBLE gldelayy, DOUBLE gldelayz, INT *defaultdelay, INT nslices,
    INT debug, long (*rsprot)[9], FLOAT *buffer
#endif /* __STDC__ */
);
LONG calciphase(
#ifdef __STDC__
    DOUBLE phase
#endif /* __STDC__ */
);
STATUS copyframe(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG frame_control, LONG pass_src, LONG slice_src, LONG echo_src, LONG view_src, LONG pass_des, LONG slice_des, LONG echo_des, LONG view_des, LONG nframes, TYPDAB_PACKETS acqon_flag
#endif /* __STDC__ */
);
STATUS create3dim(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_readout, LONG pos_ref
#endif /* __STDC__ */
);
STATUS create3dim2(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_readout, LONG pos_ref
#endif /* __STDC__ */
);
STATUS rfon(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS rfoff(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS scopeoff(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS scopeon(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS setPSDtags(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PGMREUSE reuse, WF_PGMTAG tag, LONG addtag, INT id, INT board_type, STATUS force
#endif /* __STDC__ */
);
STATUS getctrl(
#ifdef __STDC__
    long *ctrl, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS
getiwave(
#ifdef __STDC__
    long *waveform_ix, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getphase(
#ifdef __STDC__
    FLOAT *phase, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getieos(
#ifdef __STDC__
    SHORT *eos, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getpulse(
#ifdef __STDC__
    WF_PULSE_ADDR *ret_pulse, WF_PULSE_ADDR pulse, WF_PGMTAG tagfield, INT id, LONG index
#endif /* __STDC__ */
);
STATUS getssppulse(
#ifdef __STDC__
    WF_PULSE_ADDR *ssppulse, WF_PULSE_ADDR pulse, CHAR *pulsesuff, LONG index
#endif /* __STDC__ */
);
STATUS getiamp(
#ifdef __STDC__
    SHORT *amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getperiod(
#ifdef __STDC__
    long *period, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getwamp(
#ifdef __STDC__
    SHORT *amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getweos(
#ifdef __STDC__
    SHORT *eos, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS getwave(
#ifdef __STDC__
    LONG *waveform_ix, WF_PULSE_ADDR pulse
#endif /* __STDC__ */
); 
STATUS initfastrec(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_ref, LONG xres, LONG tsptics, LONG deltics, LONG lpf
#endif /* __STDC__ */
);
STATUS movewave(
#ifdef __STDC__
    SHORT *pulse_mem, WF_PULSE_ADDR pulse, LONG index, INT resolution, HW_DIRECTION direction
#endif /* __STDC__ */
); 
STATUS setattenlock(
#ifdef __STDC__
    STATUS restore_flag, WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS setctrl(
#ifdef __STDC__
    LONG ctrl_mask, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setfastdly(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG deltics
#endif /* __STDC__ */
);
STATUS setfreqphase(
#ifdef __STDC__
    LONG frequency, LONG phase, WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS setfrequency(
#ifdef __STDC__
    LONG frequency, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setiamp(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setiampall(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setiampimm(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setiamptimm(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setiphase(
#ifdef __STDC__
    LONG phase, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setphase(
#ifdef __STDC__
    DOUBLE phase, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setiampt(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setieos(
#ifdef __STDC__
    INT eos_flag, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);

STATUS setperiod(
#ifdef __STDC__
    LONG period, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setrf(
#ifdef __STDC__
    STATUS restore_flag, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setrfltrs(
#ifdef __STDC__
    LONG filter_no, WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS settransceiver(
#ifdef __STDC__
    INT board
#endif /* __STDC__ */
);
STATUS setwampimm(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setwamp(
#ifdef __STDC__
    INT amplitude, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS setwave(
#ifdef __STDC__
    WF_HW_WAVEFORM_PTR waveform_ix, WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
void   simulationInit(
#ifdef __STDC__
    long *rot_ptr
#endif /* __STDC__ */
);
STATUS setweos(
#ifdef __STDC__
    INT eos_flag, WF_PULSE_ADDR pulse, LONG index
#endif  /* __STDC__ */
);
STATUS sspextload(
#ifdef __STDC__
    LONG *loc_addr, WF_PULSE_ADDR pulse, LONG index, INT resolution, HW_DIRECTION direction, SSP_S_ATTRIB s_attr
#endif /* __STDC__ */
);
STATUS sspinit(
#ifdef __STDC__
    INT psd_board_type
#endif /* __STDC__ */
);
STATUS sspload(
#ifdef __STDC__
    SHORT *loc_addr, WF_PULSE_ADDR pulse, LONG index, INT resolution, HW_DIRECTION direction, SSP_S_ATTRIB s_attr
#endif /* __STDC__ */
);
STATUS syncon(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
STATUS syncoff(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
/************************************************/
/* Instruction - Create commands */
/************************************************/
/* RSP routines */

STATUS movewaversp(
#ifdef __STDC__
    void
#endif /* __STDC__ */
); 

STATUS	 stretchpulse(
#ifdef __STDC__
    INT oldres, INT newres, SHORT *opulse, SHORT *newpulse
#endif /* __STDC__ */
);


STATUS AddToInstrQueue(
#ifdef __STDC__
    WF_INSTR_QUEUE *queue, WF_INSTR_HDR *instr_ptr
#endif /* __STDC__ */
);
#ifdef __STDC__
void *AllocNode( LONG size );
#else /* !__STDC__ */
char *AllocNode();
#endif /* __STDC__ */
STATUS FreeNode(
#ifdef __STDC__
    void *address
#endif /* __STDC__ */
);
STATUS FreePSDHeap(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);
STATUS BridgeTrap(
#ifdef __STDC__
    WF_PULSE_ADDR *pulses, LONG n_pulses, STATUS bridge_first, WF_INSTR_QUEUE *queue
#endif /* __STDC__ */
);
STATUS BuildBridgesIn(
#ifdef __STDC__
    WF_INSTR_QUEUE *queue
#endif /* __STDC__ */
);
STATUS CreatePulse(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, WF_PULSE_TYPES waveform_type, INT resol, WF_PULSE_EXT *extension, WF_HW_WAVEFORM_PTR wave_addr
#endif /* __STDC__ */
);
/* RJF removes EpicConf prototype and puts it in epicconf.h */
/* 15 Oct 1998 */

STATUS FreePsdsQ(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);
STATUS AddToPsdQ(
#ifdef __STDC__
    WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
LONG    GetMinPeriod(
#ifdef __STDC__
    WF_PROCESSOR waveform_gen, LONG pulse_width
#endif /* __STDC__ */
);
INT    SetResol(
#ifdef __STDC__
    LONG pulse_width, LONG min_period
#endif /* __STDC__ */
);
STATUS TimeHist(
#ifdef __STDC__
    CHAR *ipgname
#endif /* __STDC__ */
);
STATUS acqctrl(
#ifdef __STDC__
    TYPDAB_PACKETS acqon_flag, INT recvr, WF_PULSE_ADDR pulse
#endif /* __STDC__ */
);
void   MsgHndlr(
#ifdef __STDC__
    const CHAR *routine, ...
#endif /* __STDC__ */
);

/* Routines visible to the user after the pre-processor; the routines are
  required for creating the pulse data and instructions. */
STATUS acqq(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_ref, LONG dab_ref, LONG xtr_ref, LONG fslot_value, LONG receiver_value, TYPDAB_PACKETS cine_flag, LONG prefills
#endif /* __STDC__ */
);
STATUS acqq2(
#ifdef __STDC__
    WF_PULSE_ADDR dabpulse, WF_PULSE_ADDR rcvpulse, LONG pos_ref, LONG fslot_value, LONG receiver_value, LONG dabstart, TYPDAB_PACKETS cine_flag, TYPACQ_PASS passthrough_flag
#endif /* __STDC__ */
);
STATUS addrfbits(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG offset, LONG refstart, LONG refduration
#endif /* __STDC__ */
);
STATUS attenflagon(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS attenflagoff(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
STATUS createatten(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG start
#endif /* __STDC__ */
);
STATUS createbits(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, INT resol, SHORT *bits_array
#endif /* __STDC__ */
);
STATUS createcine(
#ifdef __STDC__
    WF_PULSE *pulse, CHAR *name
#endif /* __STDC__ */
);
STATUS createconst(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, LONG pulse_width, INT amplitude
#endif /* __STDC__ */
);
STATUS createextwave(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, INT resol, CHAR *ext_wave_pathname
#endif /* __STDC__ */
);
void destroyExtWave( void );
void printExtWave( void );
STATUS createhadamard(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, INT resol, INT amplitude, DOUBLE sep, DOUBLE ncycles, DOUBLE alpha
#endif /* __STDC__ */
);
void CleanUp(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);
STATUS createhsdab(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_ref
#endif /* __STDC__ */
);

STATUS createhscdab(
#ifdef __STDC__
    WF_PULSE_ADDR pulse,
    LONG pos_ref,
    TYPDAB_PACKETS cine_flag
#endif /* __STDC__ */
);

STATUS createinstr(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG start, LONG pulse_width, LONG ampl
#endif /* __STDC__ */
);
STATUS createpass(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG start
#endif /* __STDC__ */
);
STATUS createramp(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, LONG pulse_width, INT start_amp, INT end_amp, INT resol, DOUBLE ramp_beta
#endif /* __STDC__ */
);
STATUS createreserve(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, INT resol
#endif /* __STDC__ */
);
STATUS createsinc(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, INT resol, INT amplitude, DOUBLE ncycles, DOUBLE alpha
#endif /* __STDC__ */
);
STATUS createsinusoid(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, INT resol, INT amplitude, DOUBLE start_phase, DOUBLE phase_length, INT offset
#endif /* __STDC__ */
);
STATUS createseq(
#ifdef __STDC__
    WF_PULSE_ADDR ssp_pulse, LONG length, long int *entry_array
#endif /* __STDC__ */
);
STATUS createtraps(
#ifdef __STDC__
    WF_PROCESSOR wgname, WF_PULSE *traparray, WF_PULSE *traparraya, WF_PULSE *traparrayd, INT ia_start, INT ia_end, DOUBLE a_base, DOUBLE a_delta, INT nsteps, INT pw_plateau, INT pw_attack, INT pw_decay, INT slope_direction, DOUBLE target_amp, DOUBLE beta
#endif /* __STDC__ */
);
STATUS createubr(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_ref, INT board_type
#endif /* __STDC__ */
);
STATUS epiacqq(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG pos_ref, LONG dab_ref, LONG xtr_ref, LONG fslot_value, LONG receiver_value, TYPDAB_PACKETS cine_flag, LONG prefills, LONG receiver_type, LONG dab_on
#endif /* __STDC__ */
);
STATUS loaddab(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG slice, LONG echo, LONG oper, LONG view, TYPDAB_PACKETS acqon_flag, LONG ctrlmask
#endif /* __STDC__ */
);
STATUS loaddab2(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PULSE_ADDR rbapulse, LONG slice, LONG echo, LONG oper, LONG view, TYPDAB_PACKETS acqon_flag
#endif /* __STDC__ */
);
STATUS load3d(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG view, TYPDAB_PACKETS acqon_flag
#endif /* __STDC__ */
);
STATUS loaddabecho(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG echo
#endif /* __STDC__ */
);
STATUS loaddaboper(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG oper
#endif /* __STDC__ */
);
STATUS loaddabset(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, TYPDAB_PACKETS dab_acq, TYPDAB_PACKETS rba_acq
#endif /* __STDC__ */
);
STATUS loaddabslice(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG slice
#endif /* __STDC__ */
);
STATUS loaddabview(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG view
#endif /* __STDC__ */
);
STATUS load3decho(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG view, LONG echo, TYPDAB_PACKETS acqon_flag
#endif /* __STDC__ */
);
STATUS loadcine(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, INT arr, INT op, LONG pview, INT frame1, INT frame2, INT frame3, INT frame4, LONG delay, LONG fslice, TYPDAB_PACKETS acqon_flag
#endif /* __STDC__ */
);
STATUS loadhsdab(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG slnum, LONG ecno, LONG dab_op, LONG vstart, LONG vskip, LONG vnum, LONG card_rpt, LONG k_read, TYPDAB_PACKETS acqon_flag, LONG ctrlmask
#endif /* __STDC__ */
);
STATUS movewave(
#ifdef __STDC__
    SHORT *pulse_mem, WF_PULSE_ADDR pulse, LONG index, INT resolution, HW_DIRECTION direction
#endif /* __STDC__ */
); 
STATUS movewaveimm(
#ifdef __STDC__
    SHORT *pulse_mem, WF_PULSE_ADDR pulse, LONG index, INT resolution, HW_DIRECTION direction
#endif /* __STDC__ */
);
STATUS linkpulses(
#ifdef __STDC__
    INT l_arg, ...
#endif /* __STDC__ */
);
STATUS pulsename(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, CHAR *pulse_name
#endif /* __STDC__ */
);
STATUS CreatePulse(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, WF_PROCESSOR waveform_gen, WF_PULSE_TYPES waveform_type, INT resol, WF_PULSE_EXT *extension, WF_HW_WAVEFORM_PTR wave_addr
#endif /* __STDC__ */
);
/* Mandatory routines required for building a pulse */
STATUS scan(void);
LONG pbeg(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, CHAR *pulse_name, LONG index
#endif /* __STDC__ */
);
LONG pbegall(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
LONG pbegallssp(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
LONG pend(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, CHAR *pulse_name, LONG index
#endif /* __STDC__ */
);
LONG pendall(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
LONG pendallssp(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
WF_INSTR_HDR *GetFreqInstrNode(
#ifdef __STDC__
    WF_PULSE *this_pulse, LONG index, CHAR *name
#endif /* __STDC__ */
);
void init_pgen_times(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);
void print_pgen_times(
#ifdef __STDC__
    void
#endif /* __STDC__ */
);
void start_timer(
#ifdef __STDC__
    long *start_time
#endif /* __STDC__ */
);
void end_timer(
#ifdef __STDC__
    long start_time, INT function_index, CHAR *name
#endif /* __STDC__ */
);
LONG pmid(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, CHAR *pulse_name, LONG index
#endif /* __STDC__ */
);
LONG pmidall(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG index
#endif /* __STDC__ */
);
void psdexit(
#ifdef __STDC__
    INT ermes_no, INT abcode, CHAR *txt_str, const CHAR *routine, ...
#endif /* __STDC__ */
);

STATUS trapezoid(
#ifdef __STDC__
    WF_PROCESSOR wgname, CHAR *name, WF_PULSE_ADDR pulseptr,
    WF_PULSE_ADDR pulseptra, WF_PULSE_ADDR pulseptrd, LONG pw_pulse,
    LONG pw_pulsea, LONG pw_pulsed, LONG ia_pulse, LONG ia_pulsewa,
    LONG ia_pulsewb, LONG ia_start, LONG ia_end, LONG position,
    LONG trp_parts, LOG_GRAD *loggrd
#endif /* __STDC__ */
);

WF_INSTR_HDR    *GetPulseInstrNode(
#ifdef __STDC__
    WF_PULSE_ADDR pulse, LONG position
#endif /* __STDC__ */
);

#endif /* epicfuns_h */

