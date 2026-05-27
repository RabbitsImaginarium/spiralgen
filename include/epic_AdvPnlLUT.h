/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1996 The General Electric Company
 *
 *      Include File Name: epic_AdvPnlLUT_INCL  
 *      Developer: Robert J. Laferriere
 *
 * $Source: epic_AdvPnlLUT.h $
 * $Revision: 1.19 $  $Date: 1/5/98 16:38:59 $
 */

/*@Synopsis 
  Look up table (LUT) for ruleset to support advisory panel popup for
  8.0 program. 
*/     

/*@Description
  The global LUT (CheckRules) defines a ruleset for looking up other possible CV's which could be 
  changed to make the current desired entry valid. For example, the following expanded LUT line
  is used to evaluate possible solutions to an out of range field of view entry by the user, or
  when switching between PSD types.
  
    0: opfov, avminfov, avmaxfov, opte, avminte, avmaxte, opte2, avminte2, avmaxte2, oprbw, avminrbw, avmaxrbw, ENDLUT

  The cause of the error is the first parameter (opfov) while the remaining entries are possible solutions.
  Note that the cause can also be a possible solution by comparing the current desired value with the true
  ranges of the advisory panel calculations. This LUT is located in psdIF to be one level above the PSD's so
  that changes to the LUT will automatically be incorperated into each of the PSD's during the next build.
  To facilitate a robust LUT, the PSD has the option of declaring each "rule" as either a lone cv (CV_ENTRY)
  which has no advisory panel cv's associated, or a CV which is tracked by advisory panel values (e.g. opte
  which is tracked by avminte and avmaxte) entered as ADVPNL_ENTRY. This makes the LUT very readable and
  easily modifiable under this condition. 

  The macros (CVCHOICE and ADVCHOICE) expand the desired cv to create a LUT that uses the CV indices than Scan and
  PSD use to communicate into the _cvarray. This keeps the LUT dynamic and robust to CV changes in ordering inside
  epic.h.

  The end of each ruleset and the end of the entire LUT is marked by the symbolic ant ENDLUT (-999). 
  The LUT is a 2D array of integers of size [MAXROWS][BUFSIZ] to ease passing based on system block size.
  The value of MAXROWS can be increased incrementally as needed when new rules are required. 

  The "rules" do not require a detailed knowledge of MR Physics. They are derived to offer possible other CV's
  which can change in some way to make the last entered CV value valid. The LAST_LUT_LINE is the default rule
  to use by the algorithm incase a valid "rule" is not found. An example is if scan passed several CV's at once.
  The PSD will set all cv's then do a cveval,cvcheck. On error, we cannot be confident of which CV caused the
  error so must evaluate the cv's in the ruleset below.

  Refer to 8.0 EPIC Advisory Panel SDD for detailed description of implementation and usage.


  9-13-96    RJL   MRIge34869: Added opvenc to ruleset
                   MRIge34948: Moved slthick and scanning range rulesets to beginning. These
		               must get processed first.
  9-25-96    RJL   MRIge36550: Removed opslquant from all other processing. Only things are slquant and Tr
                   that can make fixes.
  10-31-96   RJL   MRIge36380: Added USERCVCHOICE, USERCV_ENTRY, and opuserCV rulesets to disallow the UserCV page
                               from the Processing engine.

  11-14-96   RJL   MRIge36756: Removed MAXROWS, MAXCOLS, MAXLUT allocation and let compiler
                               determine array size dynamically at compile time. Moved the defines of ADVPNL_ENTRY,
			       CV_ENTRY, USERCV_ENTRY, and ENDLUT to epic_rt.h so that the CheckRules ruleset can
			       be defined in one place and externed to other routines. Changed the array to 2D array
			       of shorts. Let first dimension be dynamically allocated at compile time to limit
			       resource use. Make each ruleset a seperate auto array and CheckRules an array of
			       pointers. This gives a HUGE savings in memory per each PSD for this.
*/

/*@End*********************************************************/

/* only do this once in any given compilation. */
#ifndef  epic_AdvPnlLUT_INCL
#define  epic_AdvPnlLUT_INCL

/*********************************************************************************************
 * Only a maximum of 45 entries or 11 rules + end of rule marker are allowed on any ruleset (row). To add a new
 *  rule to a ruleset you may have to increase the MAXCOLS size accordingly
 *********************************************************************************************/
#define ADVCHOICE(cv) ADVPNL_ENTRY,CV_op##cv,CV_avmin##cv,CV_avmax##cv
#define CVCHOICE(cv)  CV_ENTRY,CV_op##cv
#define USERCVCHOICE(cv) USERCV_ENTRY,CV_op##cv

#define LAST_LUT_LINE 19 /* To be increased whenever new rules added */
 
short ruleset0[] =   {ADVCHOICE(slthick), ADVCHOICE(te), ADVCHOICE(tr), ENDLUT};
short ruleset1[] =   {ADVCHOICE(slspace), ENDLUT};
short ruleset2[] =   {ADVCHOICE(venc), ENDLUT};
short ruleset3[] =   {ADVCHOICE(flip), ENDLUT};
short ruleset4[] =   {ADVCHOICE(slicecnt), ENDLUT};
short ruleset5[] =   {ADVCHOICE(phasefov), ADVCHOICE(nex), ENDLUT};
short ruleset6[] =   {ADVCHOICE(nex), ADVCHOICE(phasefov), ENDLUT};
short ruleset7[] =   {ADVCHOICE(fov), ADVCHOICE(te), ADVCHOICE(te2),  ADVCHOICE(rbw), 
			 ADVCHOICE(rbw2), ADVCHOICE(yres), ADVCHOICE(tr), ADVCHOICE(ti),
			 ADVCHOICE(nshots), ADVCHOICE(xres), ADVCHOICE(etl), ENDLUT};
short ruleset8[] =   {ADVCHOICE(te), ADVCHOICE(fov), ADVCHOICE(te2),  ADVCHOICE(rbw),
			 ADVCHOICE(rbw2), ADVCHOICE(yres), ADVCHOICE(tr), ADVCHOICE(ti),
			 ADVCHOICE(nshots), ADVCHOICE(xres), ADVCHOICE(etl), ENDLUT};
short ruleset9[] =   {ADVCHOICE(te2),  ADVCHOICE(te),  ADVCHOICE(fov), ADVCHOICE(rbw), 
			 ADVCHOICE(rbw2), ADVCHOICE(yres), ADVCHOICE(tr), ADVCHOICE(ti),
			 ADVCHOICE(nshots), ADVCHOICE(xres), ADVCHOICE(etl), ENDLUT};
short ruleset10[] =   {ADVCHOICE(rbw),  ADVCHOICE(te),  ADVCHOICE(te2),  ADVCHOICE(fov),
			  ADVCHOICE(rbw2), ADVCHOICE(tr), ADVCHOICE(ti), 
			  ADVCHOICE(nshots), ADVCHOICE(etl), ENDLUT};
short ruleset11[] =   {ADVCHOICE(rbw2),  ADVCHOICE(te),  ADVCHOICE(te2),  ADVCHOICE(rbw), 
			  ADVCHOICE(fov),  ADVCHOICE(tr), ADVCHOICE(ti), ADVCHOICE(nshots), 
			  ADVCHOICE(etl), ENDLUT};
short ruleset12[] =   {ADVCHOICE(tr),  ADVCHOICE(te),  ADVCHOICE(te2),  ADVCHOICE(rbw), 
			  ADVCHOICE(rbw2), ADVCHOICE(yres), ADVCHOICE(fov), ADVCHOICE(ti), 
			  ADVCHOICE(nshots), ADVCHOICE(xres), ADVCHOICE(etl), ENDLUT};
short ruleset13[] =   {ADVCHOICE(ti),  ADVCHOICE(te),  ADVCHOICE(te2),  ADVCHOICE(rbw), 
			  ADVCHOICE(rbw2), ADVCHOICE(yres), ADVCHOICE(tr), ADVCHOICE(fov), 
			  ADVCHOICE(nshots), ADVCHOICE(xres), ADVCHOICE(etl), ENDLUT};
short ruleset14[] =   {ADVCHOICE(nshots),  ADVCHOICE(te),  ADVCHOICE(te2),  ADVCHOICE(rbw), 
			  ADVCHOICE(rbw2), ADVCHOICE(yres), ADVCHOICE(tr), ADVCHOICE(ti), 
			  ADVCHOICE(fov), ADVCHOICE(xres), ADVCHOICE(etl), ENDLUT};
short ruleset15[] =   {ADVCHOICE(yres), ADVCHOICE(te), ADVCHOICE(te2), ADVCHOICE(fov), 
			  ADVCHOICE(tr), ADVCHOICE(xres), ENDLUT};
short ruleset16[] =   {ADVCHOICE(xres),  ADVCHOICE(te),  ADVCHOICE(te2), ADVCHOICE(yres), 
			  ADVCHOICE(tr), ADVCHOICE(fov), ENDLUT};
short ruleset17[] =   {ADVCHOICE(etl), ADVCHOICE(te), ADVCHOICE(te2), ADVCHOICE(rbw), 
			  ADVCHOICE(rbw2), ADVCHOICE(fov), ADVCHOICE(ti), ADVCHOICE(nshots), 
			  ADVCHOICE(tr), ENDLUT};
short ruleset18[] =   {ADVCHOICE(slquant), ADVCHOICE(tr), ENDLUT};
short ruleset19[] =   {ADVCHOICE(necho), ADVCHOICE(te), ADVCHOICE(te2), ADVCHOICE(tr), 
			  ADVCHOICE(ti), ADVCHOICE(etl), ENDLUT};
short ruleset20[] =   {USERCVCHOICE(user0), ENDLUT};
short ruleset21[] =   {USERCVCHOICE(user1), ENDLUT};
short ruleset22[] =   {USERCVCHOICE(user2), ENDLUT};
short ruleset23[] =   {USERCVCHOICE(user3), ENDLUT};
short ruleset24[] =   {USERCVCHOICE(user4), ENDLUT};
short ruleset25[] =   {USERCVCHOICE(user5), ENDLUT};
short ruleset26[] =   {USERCVCHOICE(user6), ENDLUT};
short ruleset27[] =   {USERCVCHOICE(user7), ENDLUT};
short ruleset28[] =   {USERCVCHOICE(user8), ENDLUT};
short ruleset29[] =   {USERCVCHOICE(user9), ENDLUT};
short ruleset30[] =   {USERCVCHOICE(user10), ENDLUT};
short ruleset31[] =   {USERCVCHOICE(user11), ENDLUT};
short ruleset32[] =   {USERCVCHOICE(user12), ENDLUT};
short ruleset33[] =   {USERCVCHOICE(user13), ENDLUT};
short ruleset34[] =   {USERCVCHOICE(user14), ENDLUT};
short ruleset35[] =   {USERCVCHOICE(user15), ENDLUT};
short ruleset36[] =   {USERCVCHOICE(user16), ENDLUT};
short ruleset37[] =   {USERCVCHOICE(user17), ENDLUT};
short ruleset38[] =   {USERCVCHOICE(user18), ENDLUT};
short ruleset39[] =   {USERCVCHOICE(user19), ENDLUT};
short ruleset40[] =   {USERCVCHOICE(user20), ENDLUT};
short ruleset41[] =   {USERCVCHOICE(user21), ENDLUT};
short ruleset42[] =   {USERCVCHOICE(user22), ENDLUT};
short ruleset43[] =   {USERCVCHOICE(user23), ENDLUT};
short ruleset44[] =   {USERCVCHOICE(user24), ENDLUT};
short ruleset45[] =   {USERCVCHOICE(user25), ENDLUT};
short ruleset46[] =   {USERCVCHOICE(user26), ENDLUT};
short ruleset47[] =   {USERCVCHOICE(user27), ENDLUT};
short ruleset48[] =   {USERCVCHOICE(user28), ENDLUT};
short ruleset49[] =   {USERCVCHOICE(user29), ENDLUT};
short ruleset50[] =   {USERCVCHOICE(user30), ENDLUT};
short ruleset51[] =   {USERCVCHOICE(user31), ENDLUT};
short ruleset52[] =   {USERCVCHOICE(user32), ENDLUT};
short ruleset53[] =   {USERCVCHOICE(user33), ENDLUT};
short ruleset54[] =   {USERCVCHOICE(user34), ENDLUT};
short ruleset55[] =   {USERCVCHOICE(user35), ENDLUT};
short ruleset56[] =   {USERCVCHOICE(user36), ENDLUT};
short ruleset57[] =   {USERCVCHOICE(user37), ENDLUT};
short ruleset58[] =   {USERCVCHOICE(user38), ENDLUT};
short ruleset59[] =   {USERCVCHOICE(user39), ENDLUT};
short ruleset60[] =   {USERCVCHOICE(user40), ENDLUT};
short ruleset61[] =   {USERCVCHOICE(user41), ENDLUT};
short ruleset62[] =   {USERCVCHOICE(user42), ENDLUT};
short ruleset63[] =   {USERCVCHOICE(user43), ENDLUT};
short ruleset64[] =   {USERCVCHOICE(user44), ENDLUT};
short ruleset65[] =   {USERCVCHOICE(user45), ENDLUT};
short ruleset66[] =   {USERCVCHOICE(user46), ENDLUT};
short ruleset67[] =   {USERCVCHOICE(user47), ENDLUT};
short ruleset68[] =   {USERCVCHOICE(user48), ENDLUT};
short endofrules[] =  {ENDLUT};

/* Now here is the real Ruleset table we use in the psdIF routines */
short *CheckRules[] = { 
    ruleset0,  ruleset1,  ruleset2,  ruleset3,  ruleset4,  ruleset5,  
    ruleset6,  ruleset7,  ruleset8,  ruleset9, ruleset10, ruleset11, 
   ruleset12, ruleset13, ruleset14, ruleset15, ruleset16, ruleset17, 
   ruleset18, ruleset19, ruleset20, ruleset21, ruleset22, ruleset23, 
   ruleset24, ruleset25, ruleset26, ruleset27, ruleset28, ruleset29, 
   ruleset30, ruleset31, ruleset32, ruleset33, ruleset34, ruleset35, 
   ruleset36, ruleset37, ruleset38, ruleset39, ruleset40, ruleset41, 
   ruleset42, ruleset43, ruleset44, ruleset45, ruleset46, ruleset47, 
   ruleset48, ruleset49, ruleset50, ruleset51, ruleset52, ruleset53, 
   ruleset54, ruleset55, ruleset56, ruleset57, ruleset58, ruleset59,
   ruleset60, ruleset61, ruleset62, ruleset63, ruleset64, ruleset65, 
   ruleset66, ruleset67, ruleset68, endofrules };

#endif /* @FILENAME_WITHOUT_H_SUFFIX@_INCL */



