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
 * Author   : Gabriel Fernandez
 * Date     : 
 */
/* do not edit anything above this line */

/*
 Version      Date      Author      Description
------------------------------------------------------------------------------
 sccs1.1   16/Jun/1998  GFN         Initial version. Based off the PET version.
 */

#ifndef timehist_mem_h
#define timehist_mem_h

/* Public typedefs */
typedef struct s_wave {
    CHAR name[255];
    long wave_addr;
    INT ptype;
    INT resolution;
    INT amp;
    INT samp;
    INT eamp;
    INT offset;
    FLOAT sep;
    FLOAT nsinc;
    FLOAT alpha;
    FLOAT start_phase;
    FLOAT phase_len;
    struct s_wave *next;
} t_wave;

typedef struct s_instr {
    INT start;
    INT end;
    INT dur;
    INT period;
    INT amp;
    FLOAT area;
    FLOAT abs_area;
    struct s_instr *next;
} t_instr;

typedef struct s_seq {
    t_instr *instr;
    t_instr *itop;
    t_wave *wave;
    t_wave *wtop;
    struct s_seq *next;
    INT num_instrs;
    INT num_waves;
} t_seq;

typedef struct s_board {
    t_seq *top;
    t_seq *seqs;
    INT processor_type;
    struct s_board *next;
    INT num_seqs;
} t_board;

typedef struct s_timehist {
    t_board *top;
    t_board *boards;
    INT num_boards;
} t_timehist;

typedef struct s_extwave {
    CHAR *pulsename;
    CHAR *path;
    struct s_extwave *next;
    struct s_extwave *prev;
} t_extwaveentry;

/* Public function prototypes */
STATUS timehist_mem( t_timehist *timehist );
void load_pulse_into_mem( WF_PULSE_ADDR pulse, t_wave *waveptr );
void free_timehist( t_timehist *timehist );
void dump_timehist( const t_timehist *timehist );
void print_timehist( const t_timehist *timehist, const int entry_point );
INT count_points( const t_seq *seq_p, const INT res,
                  const int seq_entry_index );
STATUS find_pulse( CHAR *pulsename, INT *pw, const INT curtime,
                   const t_timehist *timehist, const INT ptype,
                   const INT seq_idx );

#endif /* timehist_mem_h */

