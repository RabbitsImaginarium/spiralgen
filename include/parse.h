/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1995-1998 The General Electric Company
 *
 *      File Name:  parse.h
 *      Developer:  Carl R. Crawford
 *
 * $Source: parse.h $
 * $Revision: 1.3 $  $Date: 6/19/98  16:53:07  $
 *
 *@Description
 * Include file for routines that use parse.a
 *
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version      Date         Author
              Description
 ------------------------------------------------------------------
              18 Feb 91    Carl R. Crawford	
              installed parse_malloc

              12 Apr 91    Carl R. Crawford	
              added parse_root

              11 Jul 91    Carl R. Crawford	
              documented PARSE_ types; added char_pointer and _buf

              26 Sep 91    Carl R. Crawford	
              added PARSE_MAX_LINE

              10 Feb 92    Carl R. Crawford	
              put in defines for block calculation, include stdio.h

              21 Feb 92    Carl R. Crawford	
              rmi returns address of image

              12 Mar 92    Carl R. Crawford	
              support for parse_flags

              18 Sep 92    Carl R. Crawford	
              procs for flags and options

              23 Sep 92    Carl R. Crawford	
              make lint happy w/ parse_malloc

              13 Oct 92    Carl R. Crawford	
              added fn_ support

              04 Dec 92    Carl R. Crawford	
              allow help in command table

              18 Dec 92    Carl R. Crawford	
              bring in void function def's

              05 Jan 93    Carl R. Crawford	
              make PARSE_ARG  (void *)

              15 Jun 93    Carl R. Crawford      
              rda

 sccs1.3      17-Jun-98    Dale Thayer
              Original for cardiac, CV1, conversion to ANSI C.

 *@End*************************************************************/


/***************************************************************************
 *      Revision History for Clearcase
 ***************************************************************************
 Version            Date/        Author
                    Comment
 ***************************************************************************
 /main/mr_main/2    9-Oct-98     Dale Thayer
                    Took the version from /vobs/psd/parse and then deleted it
                    from that directory so there would only be one version.

 /main/mr_main/3    19-Oct-98    Dale Thayer
                    Put a conditional compile around stdio.h for stdioLib.h
                    use with IPG compilations.

 ***************************************************************************/




#ifndef  _parse_h                        /* we only want file included once */
#define  _parse_h

#ifdef HW_IO

#ifdef PSD
#include <stdioLib.h>
#endif

#else
#include <stdio.h>
#endif

/*
	stuff for command table
*/
#define PARSE_INT     0
#define PARSE_FLOAT   1
#define PARSE_LONG    2
#define PARSE_CHAR    3		/* pointer */
#define PARSE_STRING  4		/* buffer */
#define PARSE_PROC    5		

		/* all int, for additional flag setting */
#define PARSE_SET 6
#define PARSE_CLR 7
#define PARSE_INC 8
#define PARSE_DCR 9
#define PARSE_VAL 10

#define PARSE_SHIFT 5
#define PARSE_VALUE(x) ((x)<< PARSE_SHIFT)|PARSE_VAL

#define PARSE_CHAR_POINTER PARSE_CHAR
#define PARSE_CHAR_BUF PARSE_STRING

typedef void *PARSE_ARG;

struct PARSE_OPTION_TABLE {
	char *label;
	int type;
	PARSE_ARG pointer;
	char *help;
	};

#define PARSE_STRUCT PARSE_OPTION_TABLE

/*
	stuff for flag table 
*/
struct PARSE_FLAG_TABLE{
	char flag;
	int *var;
	int type;
	char *help;
};
#define PARSE_FLAG_SET 0
#define PARSE_FLAG_CLR 1
#define PARSE_FLAG_INC 2
#define PARSE_FLAG_DCR 3
#define PARSE_FLAG_VAL 4
#define PARSE_FLAG_PROC 5

#define PARSE_FLAG_SHIFT 3
#define PARSE_FLAG_VALUE(x) ((x)<< PARSE_FLAG_SHIFT)|PARSE_FLAG_VAL
/*
	other defines
*/
#define PARSE_MAX_LINE	256	/* max # of characters read */
#define PARSE_ITOA	12	/* max # of characters in itoa call */
/*
	macros
*/
#define BLOCK_SHORT(x) (((x)+(512/sizeof(short)-1))/(512/sizeof(short)))
#define BLOCK_FLOAT(x) (((x)+(512/sizeof(float)-1))/(512/sizeof(float)))
/*
	function defintions
*/
#ifndef lint
char *parse_malloc( int n );
#else
#define parse_malloc(x) ((x),NULL)
#endif


/* from accept.c */
void parse_aci( char *message, int d, int *i );
void parse_acimm( char *message, int amin, int amax, int d, int *i );
void parse_acf( char *message, float d, float *i );
void parse_acfmm( char *message, float amin, float amax, float d, float *i );
char *parse_acs( char *message, char *d, char *fe, char *i );
void parse_act( char *message, int d, int *i );
void parse_acm( char *message, int d, char *modes, int *i );

/* from args.c */
int parse_args_proc( struct PARSE_STRUCT *options, struct PARSE_FLAG_TABLE *flags, FILE *fd, char *arg, int (*proc)(), int proc_type );

/* from args_ext.c */
void parse_args( char *arg );

/* from atof.c */
double parse_atof( char *s );
int parse_atof_error( void );
void parse_atof_args( FILE *fd, int stop );

/* from basic.c */
void parse_basic( int argc, char **argv );
void parse_file_basic( char *file );
void parse_args_basic( char *arg );
void parse_help_basic( void );
void parse_all_basic( char *file, char *arg, int argc, char **argv );

/* from buffer.c */
void parse_zbuf( short int *a, int n );
void parse_zrbuf( float *a, int n );

/* from check.c */
void parse_pcheck( int i, int imin, int imax, char *s );
void parse_fcheck( float i, float imin, float imax, char *s );

/* from da.c */
void parse_vwrite( int *data, int n, int type, char *file, char *message );
void parse_vwrite_float( int *data, int n, char *file );
float *parse_vread( float *data, int *n,  int mn, int type, char *file );
void parse_wda( float *data, int col, int row, char *file );
float *parse_rda( float *data, int *rcol, int *rrow, char *file );

/* from disk.c */
FILE *parse_fopen( char *s, char *mode );
FILE *parse_copen( char *s, char *mode );
FILE *parse_open( char *s, char *mode );
void parse_fclose( FILE *s );
void parse_cclose( FILE *s );
void parse_close( FILE *s );
void parse_fseek( FILE *unit, long byte, char *type );
void parse_seek( FILE *unit, long byte, char *type );
void parse_fread( char *ptr, int size, int n, FILE *unit );
void parse_fwrite( char *ptr, int size, int n, FILE *unit );
void parse_fread_block( char *ptr, int size, int n, FILE *unit, int blk );
void parse_rblock( FILE *unit, int start, char *data, int count );
void parse_wblock( FILE *unit, int start, char *data, int count );
int parse_urline( FILE *u, char *s );
int parse_rline( char *s );
#ifdef PARSE_FN_TEST
void parse_fn_print( void );
/* void main( void ); */
#endif

/* from fft.c */
void parse_fft( float *a, float *b, int m, int iopt );

/* from file.c */
int parse_file_proc( struct PARSE_STRUCT *options, struct PARSE_FLAG_TABLE *flags, FILE *fd, char *file, int (*proc)(), int proc_type );

/* from file_ext.c */
void parse_file( char *file );

/* from flags.c */
void parse_flag_help( struct PARSE_FLAG_TABLE table[], FILE *fd );
int parse_fflags( struct PARSE_FLAG_TABLE table[], char *s, FILE *fd );

/* from flags_ext.c */
void parse_flags( char *s );

/* from general.c */
int parse_general( struct PARSE_STRUCT *options, struct PARSE_FLAG_TABLE *flags, FILE *fd, int argc, char **argv );
int parse_file_general( struct PARSE_STRUCT *options, struct PARSE_FLAG_TABLE *flags, FILE *fd, char *file );
int parse_args_general( struct PARSE_STRUCT *options, struct PARSE_FLAG_TABLE *flags, FILE *fd, char *arg );
void parse_help_general( struct PARSE_STRUCT *options, struct PARSE_FLAG_TABLE *flags, FILE *fd );

/* from malloc.c */
#ifndef lint
char *parse_malloc( int  n );
#else
char *parse_malloc_lint( int n );
#endif
void parse_free( char *p );
float *parse_malloc_float( int n );
char *parse_malloc_char( int n );
int *parse_malloc_int( int n );
long *parse_malloc_long( int n );
double *parse_malloc_double( int n );
short *parse_malloc_short( int n );

/* from mi.c */
void parse_wmi( char *file, short *image, int ncol, int nrow );
short int *parse_rmi( char *file, short *image, int *rncol, int *rnrow );

/* from options.c */
int parse_opexist( char *op );
int parse_pparse( struct PARSE_STRUCT parse_table[], char *s, FILE *fd );
int parse_pparse_aa( struct PARSE_STRUCT parse_table[], FILE *fd, int *argc, char ***argv );
void parse_option_help( struct PARSE_STRUCT parse_table[], FILE *fd );

/* from options_ext.c */
int parse_comm( char *s );
int parse_comm_aa( int *argc, char ***argv );

/* from print.c */
void parse_upri( FILE *u, char *s, int i );
void parse_pri( char *s, int i );
void parse_uprf( FILE *u, char *s, float i );
void parse_prf( char *s, float i );
void parse_uprs( FILE *u, char *s, char *i );
void parse_prs( char *s, char *i );
void parse_err( char *s1, char *s2 );
void parse_er( char *s1 );
void parse_uwtext( FILE *u, char *s );
void parse_wtext( char *s );
void parse_updt( FILE *u, char *s );
void parse_pdt( char *s );
void parse_uprt( FILE *u, char *s, int i );
void parse_prt( char *s, int i );
void parse_uprm( FILE *u, char *s, char *modes, int i );
void parse_prm( char *s, char *modes, int i );
void parse_uprc( FILE *u, char *s, char i );
void parse_prc( char *s, char i );

/* from string.c */
void parse_toupper( char *s );
void parse_tolower( char *s );
void parse_words( char *s, int *argc, char **argv, int mword );
char *parse_itoa( int i, char *s );
char *parse_suffix_malloc( char *n, char *s );
void parse_suffix( char *n, char *s );
void parse_remove_suffix( char *n );
char *parse_root( char *s );

#endif                                  /* end: if _parse_h not defined */
