/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1995 The General Electric Company
 *
 *      Include File Name:  @report@   
 *      Developer: Robert J. Laferriere
 *
 * $Source: report.h $
 * $Revision: 1.4 $  $Date: 20 Jul 1995 16:13:14 $
 */

/*@Synopsis 
	#defines for printARGS bitmask to dump only certain routines.
*/     

/*@Description
	Use these #defines as environment variables to set up a
	bitmask to use for printARGS routine. 
	
	e.g. > setenv PSDALL <cr>
	Typing above before starting PSD will cause all routines
	to dump through printARGS routine as listed below. 

	e.g. > setenv PSDAMPFOV <cr>
	Only ampfov() will dump relevant variable information
     

	RJL     07/14/95   Initial Version
	RJL     08/24/95   Remove AMPPWGRADMETHOD, EPIRECVFRQPHS, EPIGRADOPT
*/

/*@End*********************************************************/

/* only do this once in any given compilation.*/

#ifndef report_INCL
#define report_INCL

#define PSD_AMPPWCRUSH		1
#define PSD_AMPPWENCODE		2
#define PSD_AMPPWENCODEFSE	3
#define PSD_AMPPWENCODET	4
#define PSD_AMPPWFCSE1		5
#define PSD_AMPPWFCSE2		6
#define PSD_AMPPWGXFC		7
#define PSD_AMPPWGY1		8
#define PSD_AMPPWGZ1		9
#define PSD_AMPPWGZFC		10
#define PSD_AMPPWLCRSH		11
#define PSD_AMPTARGET		12
#define PSD_CRUSHERUTIL		13
#define PSD_FRACTECHO		14
#define PSD_GET_RF_DLY		15
#define PSD_INITTARGETS		16
#define PSD_MATRIXCHECK		17
#define PSD_MAXSEQSAR_B1SCALE	18
#define PSD_SETSYSPARMS		19

#endif








