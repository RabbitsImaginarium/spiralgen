/*@Start***********************************************************
 * GEMSBG Include File
 * Copyright (C) 1995-1998 The General Electric Company
 *
 *      File Name:  programs.h
 *      Developer:  Dale Thayer
 *
 *
 *@Description
 *
 *  These are the defines used to identify the calling program for
 *  runtime differentiation of consolidated routines (i.e. routines
 *  that have been combined even though they work slightly different 
 *  for different programs).  Consolidation was done to centralize
 *  common functionality so that bug fixes were not missed.
 *  The values will be loaded into the global variable named
 *  calling_program which is defined in the main source file of
 *  each program when this file is included.  This happens because
 *  each main source file has MAINPROG defined.  Subroutines which care 
 *  just need to compare the defined values below to tell who called them.
 *  The values themselves are grouped by hundreds depending on
 *  which ClearCase directory the main program lives in:
 *       100's = /vobs/psd/wtools/psdplotpulse
 *       200's = /vobs/psd/wtools/epic_eval
 *       300's = /vobs/psd/wtools/psdblochsim
 *       400's = /vobs/psd/wtools/psdipgsim
 *       500's = /vobs/psd/wtools/psdwtools
 *       600's = /vobs/psd/wtools/psdrfprof
 *       700's = /vobs/psd/wtools/psdipgsimlib  (library directory)
 *       800's = /vobs/psd/wtools/psdplotlib    (library directory)
 *       900's = /vobs/psd/wtools/psdprotect
 *      1000's = /vobs/psd/wtools/psdrfstat
 *      1100's = /vobs/psd/PET
 *  (Not too important now, just for possible further use).
 *
 *
 * do not edit anything above this line
 *
 ******************************************************************
 *      Revision History
 ******************************************************************
 Version           Date/         Author
                   Description
 ------------------------------------------------------------------
 /main/mr_main/1   12-Nov-98     Dale Thayer
                   Original version for consolidated ANSI C conversion.

 *@End*************************************************************/

#ifndef  PROGRAMS_H			/* we only want file included once */
#define  PROGRAMS_H


#ifdef   MAINPROG			/* does this define a main program? */
   long        calling_program;		/* yes-define global storage for prg */
#else
   extern long calling_program;		/* no-declare a global link to var */
#endif					/* end: main prog versus subroutine */

					/* executable      main source file */

#define  PLOT_PULSE     100		/* plotpulse_tool (PPMain.c) */
#define  CALC_MOMENTS   150		/* CalcMoments    (CalcMoments.c) */
#define  EVAL_TOOL      200		/* evaltool       (eval.c) */
#define  CHECK_PSD      250		/* checkpsd       (checkpsd.cc) */
#define  RFBLOCH_TOOL   300		/* rfblochtool    (rfblochtool.c) */
#define  CALC_BLOCH     350		/* CalcBloch      (CalcBloch.c) */
#define  PSD_IPGSIM     400		/* psdipgsim      (emultool.c) */
#define  WTOOLS_X       500		/* WTools.x       (WToolsMain.c) */
#define  WTOOLS_BG      550		/* WtoolsBg       (WtoolsBg.c) */
#define  RFPROF_TOOL    600		/* rfproftool     (slrtool.c) */
#define  GENPASS        900		/* genpass        (genpass.c) */
#define  GENPASS_TOOL   950		/* genpasstool    (genpasstool.c) */
#define  RFGRAPH       1000		/* rfgraph        (rfgraph.c) */
#define  MODGRAPH      1030		/* modgraph       (modgraph.c) */
#define  RFSTAT        1060		/* rfstat         (rfstat.c) */
#define  BINSUB        1100		/* binsub         (binsub.c) */
#define  PET_MAIN      1150		/* <psd ?? >      (main.c) */

#endif					/* end: if PROGRAMS_H not defined */


