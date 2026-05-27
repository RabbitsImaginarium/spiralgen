/*
     "desc:1
 ******************************************************************************
   GEMSBG Include File
   Copyright (C) 1993 The General Electric Company

   Include File Name:  ca_filt   
   Developer:          David Hinds

   $Source: ca_filt.h $
   $Revision: 1.13 $  $Date: 2/11/98 08:54:55 $

   Purpose : This module contains type definitions and function
             prototype that are common to all CERD Filter Generation, and
             filter download applications. 

   Release #  Date        Author         Changes
   ---------  ---------   -------------  --------------------------------
     6.0      04-Aug-93   D. Hinds       Original
     8.0      22-Oct-95   D. Hinds       MAX_OUTPUTS now 2048 and MAX_DECIMATION                                         now 640 due to Spectro reqs.
     8.0      16-Nov-95   D. Hinds       MAX_OUTPUTS back to 512
                                         MAX_XRES and MIN_XRES defined
     CV1      11-Feb-98   B. Pettersson  Added COEFF_QUEUED
               
               
*******************************************************************************
"ETC  "ETX
*/ 


/* only do this once in any given compilation.*/
#ifndef  ca_filt_INCL
#define  ca_filt_INCL



/* ************************   Constant Definitions   ************************ */
/* Constants for Filter Param Block Flag */
#define FILT_SET             0x1
#define FILT_CLEAR           0x10
#define FILT_READY           0x100

/* AIME CRAM indexing constants */
#define FIR_MEM_OFFSET        0x2002  /* decimal 8194 */
#define PASS_MEM_OFFSET       0x1
#define FILTER_SLOTS_BASE     0x2000  /* start filter slots at point 8192 */

/* - Receiver boards supported */
#define           TARDIS                            0   /* current receiver */
#define           CERD                              1   /* cerd */
#define           MEDCAM                            2   /* Medcam HSI board */
#define           EPI                               3   /* EPI  */
 
/* - CERD Filtering mode - */
#define           NORMAL                            0   
       /* data input to cerd directly from RAP */
#define           CERD_SPECTRO                      1   
       /* data prefiltered from Spectro receiver */
 
/* - Coeff Generation Types - */
#define           WINDOWED_SINC                      0
#define           PARKS_MCCLELLAN                    1
#define           KAISER_BESSEL                      2
#define           VRGF                               3
#define           PASS_THRU                          4
   
/* - Coeffs in File/Packet? - */
#define           COEFF_NONE                         0
#define           COEFF_FREQUENCY                    1
#define           COEFF_TIME                         2
#define           COEFF_QUEUED                       3
 
/* - Parameter Ranges - */
#define           CERD_MIN_SLOT                      0
#define           CERD_MAX_SLOT                      27
#define           CERD_MIN_SLOT_FIR                  0
#define           CERD_MAX_SLOT_FIR                  13
#define           CERD_MIN_SLOT_PASS                 100
#define           CERD_MAX_SLOT_PASS                 113
 
#define           CERD_MIN_GEN_TYPE                  0
#define           CERD_MAX_GEN_TYPE                  4 
#define           CERD_MIN_SAMP_MODE                 0 /* CERD or Spectro */
#define           CERD_MAX_SAMP_MODE                 1 /* CERD or Spectro */

#define           CERD_MIN_COEFF_TYPE                0
#define           CERD_MAX_COEFF_TYPE                3
#define           CERD_MIN_COEFF_NUM                 4 
#define           CERD_MAX_COEFF_NUM                 4096
#define           CERD_FFT_SIZE_CNT                  6
#define           CERD_MIN_DECIMATION                1
#define           CERD_MAX_DECIMATION                640
#define           CERD_MIN_PREFILL                   0
                  /* MAX PREFILL defined by the number of taps -1 */
#define           CERD_MIN_POST_ZEROES               0
                  /* MAX POST_ZEROES defined by the number of taps -1 */
#define           CERD_MIN_OUTPUTS                   32
#define           CERD_MAX_OUTPUTS                   512

#define           CERD_MIN_XRES                      32
                  /* chagned original 2048 to 8192 for 256k CERD */
#define           CERD_MAX_XRES                      8192 

#define           CERD_MIN_DEMOD                     0
#define           CERD_MAX_DEMOD                     1
#define           CERD_MIN_GAIN                      0.0
#define           CERD_MAX_GAIN                      256.0
#define           CERD_MIN_FSAMP                     0.2
#define           CERD_MAX_FSAMP                     256.0
#define           CERD_MIN_SEGMENTS                  1
#define           CERD_MAX_SEGMENTS                  128
#define           CERD_MIN_CUTOFF                    0.1
#define           CERD_MAX_CUTOFF                    128.0
#define           CERD_MIN_PICT_WIDTH                0.0
#define           CERD_MAX_PICT_WIDTH                1.5
#define           CERD_MIN_ALPHA                     0.0
#define           CERD_MAX_ALPHA                     1.5
#define           CERD_MIN_WINDOW_TUNE               0.0
#define           CERD_MAX_WINDOW_TUNE               1.5
#define           CERD_MIN_BETA                      0
#define           CERD_MAX_BETA                      10
#define           CERD_DELTA_FREQ                    0.01/* For PARKS in kHz. This will probably change! */
 

#define NUM_PASS_THRU_FILTERS                        14
#define NUM_FIR_FILTERS                              14

/* **************************   Type Definitions   ************************** */

/* structure for filter download packet */
/* largest elements on top for riscification purposes */
typedef struct FILTER_SPEC
{
    unsigned long slot;           /* filter slot */
    unsigned long gen_type;       /* Generation Algorithm */
    unsigned long coeff_type;     /* Are coeffs available ? */
    unsigned long num_of_coeffs;
    unsigned long fft_length;
    unsigned long segment_cnt;    /* number of segments */
    unsigned long decim_ratio;
    unsigned long demod_flag;
    unsigned long num_of_outputs;
    unsigned long discard;
    unsigned long post_zeroes;
    unsigned long echo_cnt;       /* number of input pts */
    float gain;
    float cutoff;
    float samp_freq;
    float picture_width;
    float param1;                 /* optional parameter 1 */
    float param2;                 /* optional parameter 2 */
} CERD_FILTER_PB_TYPE;

/* structure sent down to CAP that contains the TI C30 floating point
   types rather than the IEEE floating standard.
*/
typedef struct FILTER_XLATED_SPEC
{
    unsigned long slot;           /* filter slot */
    unsigned long gen_type;       /* Generation Algorithm */
    unsigned long coeff_type;     /* Are coeffs available ? */
    unsigned long num_of_coeffs;
    unsigned long fft_length;
    unsigned long segment_cnt;    /* number of segments */
    unsigned long decim_ratio;
    unsigned long demod_flag;
    unsigned long num_of_outputs;
    unsigned long discard;
    unsigned long post_zeroes;
    unsigned long echo_cnt;       /* number of input pts */
    unsigned long gain;
    unsigned long cutoff;
    unsigned long samp_freq;
    unsigned long picture_width;
    unsigned long param1;                 /* optional parameter 1 */
    unsigned long param2;                 /* optional parameter 2 */
} CERD_FILTER_PB_XLATED_TYPE;

 
/* Filter Select Packet */
 
typedef struct _CERD_FILTER_SELECT {
n32    filter_slot;
} CERD_FILTER_SELECT;
 
/* BFPO Gain Factor Packet*/
 
typedef struct _CERD_BFPO {
n32    filter_slot;
n32    bfpo;
n32    psd_gain;
} CERD_BFPO;
 
/* Filter Gen. Status Packet */ 
typedef struct _CERD_FILTER_GEN_STATUS { 
s32    status; 
s32    slot;
} CERD_FILTER_GEN_STATUS; 


struct EXT_CERD_PARAMS {
  f64 fs;   /* CERD sampling frequency */
 
  /*** Future? Cerd supported algorithm parameters ***/
  /***************************************************/
  f64 pb_cutoff;  /* parks-mcclellan alg*/
  f64 sb_cutoff;  /* parks-mcclellan alg*/
  s32 beta;   /* kaiser-bessel alg */
  /***************************************************/
 
  s32 alg;    /* filter algorithms or pass thru data */
  s32 mode; /* where CERD gets input data from */
  s32 fft_N;    /* length of the freq. domain filter. -1 for optimal value
                       calculated on TPS */
  s32 num_segments; /* number of segments to process. -1 for optimal value
                       calculated on TPS */
  s32 post_zeroes;  /* number of zeroed data points placed at
                 the end of the echo */
  s32 demod;    /* rap multiplies every other point by -1 */
  s32 dummy;
 
} ;
 
/*
  Structure below is used for filter generation on the Tardis. For data
  alignment purposes, the large elements of the structure are declared first
  and the smallest are last.
  */
typedef struct {
  f64            dfg;         /* digital filter gain */
  f64            filfrq;      /* filter frequency */
  f64            picw;        /* picture width tuning parameters */
  f64            wt;          /* window tune for kernel */
  f64            alp;         /* alpha tuning parameter */
  struct EXT_CERD_PARAMS cerd;
  s32            taps;        /* no. of filter coeff */
  s32            dec;         /* decimation number */
  s32            outputs;     /* # of complex output points */
  s32            prefills;    /* # of prefill samples */
  s32            flush;       /* # of flush points to acquire */
  s32            tflush;      /* # of taps to flush */
  s32            receiver;    /* receiver being used */
  s32            filter_slot; /* slot(4-7 for tardis; 0-13, 100-113 for CERD) */
  s32            post_flush;  /* post flushing (1/0) */
  s32            queuing;     /* preprocessor queueing (1/0) */
  s32            rshift;      /* # of bits to right shift */
  s32            det;         /* detection in coefficients (1/0) */
  s32            invert_q;    /* invert q ceofficients */
  s32 dummy;
} PSD_FILTER_GEN;

 

/* 
 Used for CERD monitoring.

struct FILTER_STATUS
{
    char  title[32];
    unsigned long  download;
    struct FILTER_SPEC filt_spec;
};

*/


/* *************************   External Variables   ************************* */

/* *******************   External Function Prototypes   ********************* */




#endif /* ca_filt_INCL */


