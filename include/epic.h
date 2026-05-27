/****************************************

   GE Medical Systems
   Copyright (C) 1993-1998 The General Electric Company

   $Source: epic.h $
   $Revision: 1.98 $  $Date: 8/26/98 13:51:24 $
   
   This is the standard include file for psds.
   It includes all required cvs and export variables.
   It includes declarations of several structures that
   are used by scan and advisory panel routines.  It defines
   several constants used in CV definitions and advisory
   panel routines.

      Release Date 	Author 	Comments
      MRP
      10/7/93  PJG  Remove filter struct definition. Include ca_filt.h.

      11/2/93  PJG  In RCVRBLANK, fill in array for SSP separately.
      1/28/94  PJG  Increase PSD_FILTER_MAX to 13
      3/3/94   PJG  TARDIS_FREQ_OFFSET to pulsegen.h
      3/4/94   PJG  Added pidefrbw to match up with 5.4
      3/15/94  PJG  TARDIS_FREQ_OFFSET is ipgexport variable.
      3/16/94  PJG  Even out bytes for rcvrblank packet
      4/13/94   LP  added extra CV at the end for data window positioning
                    'coll_prefls' - collect prefills - defaults to yes
      4/14/94   LP  added PSD_RP_CERDMC define
      5/03/94   YH  created New Context for VMX(7.0).
                    merged solar2 and cerd context into vmx context.
      5/27/94   YS  added new config file CVs: cfpsdgraddly and cfpsdrfdly.
                    incremented the epic.h revision to 13.
		    added two more attributes to the ENTRY_POINT_TABLE:
		    eppkpower and epseqtime.
      6/14/94   YS  Added more CVs to support vectra electronics to the
                    end of the reqexport section.
                    Changed "spare1" to "epgradcoil" in ENTRY_POINT_TABLE.
      6/20/94   YI  Modified CONT and TRAPEZOID2 to support gradient amplitude
                    which is other than 1.0 G/cm. Added SINC2 macro, which 
                    ignores psd_rf_wait for MT pulse in 3dtof.
      7/14/94   YH  deleted test sentence.
      10/14/94  YH  merged 55 and vmx context into vmx context.
      10/24/94  YH  deleted RES_CFHRF0 and RF0_CFH_SLOT.
      11/04/94  LP  changed oprot declaration to int
      11/08/94  YI  added changes of psdinc:55 94fw44.5.
      11/11/94  LP  changed oprot declaration to an array of 10 shorts
                    due to scan geometry assumptions
      11/16/94  YI  added changes of :55 94fw45.4b(5.5.44 11/10/94  YS and
                    5.5.45  11/10/94  PL)
      11/28/94  YI  deleted cfgcm from SLICESELYEXT. changed default value for
                    cfpsdgraddly,cfpsdrfdly and pigradcoil. defined the initial
                    value of cfcoilshld.
      12/07/94  YI  added definition for gradient amp type.
      12/08/94  YI  added FOV_MIN_VMX.
      12/15/94  YI  added RCV_FREQ_TARDIS and RCV_FREQ_CERD.
      01/09/95  YI  added changes of :55 95fw1.5(5.5.50 to 5.5.54 12/09/94 aek)
      02/16/95  YI  changed data type for eg_sat_rot from int to short.
      03/13/95  YI  changed for new system safety.
      03/14/95  YI  added changes of:55 s95fw11.1(added element inSLICESELX2,Y2)
      03/17/95  YI  added rhpcinvft,rhpctest and rhpcsnore again to avoid
                    compiling error on IFCC.
                    added changes of :55 95fw11.4(to sccs 1.297 03/16/95  RJL)
      04/07/95  YI  55 merged(added cont_flag,optabent,sifsetwokey and iheesp)
      04/20/95  YI  55 merged(sccs 1.302  04/18/95 MGH)
      05/04/95  YI  55 merged(sccs 1.303    04/30/95 RJL)
      06/07/95  YI  55 merged(to sccs 1.306 06/02/95  LP)

8.0.0 06/20/95  JDM Merged with latest mrp version.

8.0.1 06/27/95
                sccs 1.307      950608 MGH      Changed TR_MAX to 15s.  Limit oprtreps to 5 
		sccs 1.308      06/23/95  FHE   Added cvs oplandmark and opautosldelay

8.0.2 07/05/05  RJL Merged with latest mrp version so build will pass.
sccs 1.208 07/24/95 RJL Merged with 55(95fw26.6a) and vmx(95fw25.4)
           55 Additions
	   ------------
	   sccs 1.310      950607 mgh  added export variables pidefspf, piphasfovnub2, and
                            pidltime.  
	   sccs 1.311      950714    QT    Added cv piswapfc to allow epi to swap default 
                                frequency encoding.
	   sccs 1.313      950721    QT    Reset piphasfov* cv.
           sccs 1.314      950722   mgh    Ordered cvs the way ther are in sccs 1.310 and added
                                new varables at bottom of variables.
           sccs 1.315      950722   mgh    piphasfovval1 added.
sccs 1.209 08/01/95 RJL Changed TNSON and TNSOFF to get TNS change for CERD support. See macro.
   
  22-Aug-95 JDM   Added RCV_FREQ_FAST.

  15-Sept-95 JDM, J. Meng  Added opfulltrain for Lightning FSE/FLAIR.
                           Added pi_neg_sp and piisvaldef for Lightning FGRE/FMPVAS.
  			   Added two PSDs, PSD_PROBES and PSD_PROBEP, for Lightning 
			   SPECTRA/PROBE.
			   Added ihoffsetfreq (MT) and ihneqscanspacing (FMPVAS)

			   Changed revision to 15 !!!
8.0.3   RJL  10/04/95      Merge with :55(95fw39.3) and :mrp(95fw37.3)
8.0.4   RJL  10/10/95      Modifey SLICESEL<X,Y,Z>EXT2 macros to initialize cyc_rf values
                           for temporary createsinc buffer for rfpulse scaling.
8.0.5	VB   10/18/95	   Set the max value for opmt from 0 to 1.

8.0.5	J.Meng 11/02/95	   Added SLICESELZEXT_INV and EXTWAVE_INV macros to take 
			   name string for external pulse. The macros are used in  
			   Inversion.e.

8.0.6	J.Meng 11/03/95	   Added PROBES and PROBEP in oppseq definition. Changed max value
			   for opfast to 1.

8.0.7	J.Meng 11/21/95	   Added 57 cvs for Custom Scan Schema (CSS):  
			   opuser_usage_tag, rhuser_usage_tag, rhFillMapMSW,
			   rfFillMapLSW, opuser25-48, rhuser20-48.

			   Changed revision to 16.

8.0.8   RJL    11/28/95    Error in 8.0.7 for bitmask for added cv's opuser_usage_tag etc..
                           Max value of 0xFFFFFFFF is a negative number and causes all PSD's
			   to core dump.
8.0.9   RJL    11/28/95    Change min for opuser_usage_tag to 0xFFFFFFFF. Max neg. number.
8.0.10  FHE    12/12/95    Picked up some additions from 5.5 (rhpc cvs). 5.5 comments were:
 --------------------------------------------------
sccs 1.326     951113 FHE   Moved the new rhpc cvs to the last @reqcvs section.
sccs 1.327     951113 FHE   Added yet another new rhpc cv (rhpccoil).
 --------------------------------------------------
8.0.11  FHE    12/15/95    Moved pinofreqoffset,piforkvrgf to proper place.

8.0.12  JDM    01/11/96    Added SINGLE_TRAP macro written by TKF.
8.0.13	YPD    01/16/96	   Added RCVRUNBLANK macro for RCVR unblanking.
8.0.14	J.Meng 01/24/96	   Changed upper limit to 1 for the cv definitions: 
			   opcs,opirprep,opmph and opdeprep.
8.0.15  PH    01/25/96     Add opssfse cv for single shot fse.

sccs 1.28
8.0.16  JDM    26-Feb-96   MRIge29945
                           Changed pidefrbw = 15.63 instead of 0 to be used
                           as default for all PSDs for Lx in the absence of
			   a specific PSD override.

sccs 1.29
8.0.17  JDM    11-Mar-96   Changed opslspace range from 0,200 to
                           -200,200 

sccs 1.30
8.0.18  JDM    11-Apr-96   MRIge31598
                           Changed opslspace range from -200,200 to
                           0,200 temporarily, until full system support
			   for negative slice gaps is in place.

sccs 1.32 
8.0.19 RJL     15-Apr-96  New PSD additions for Advisory Panel Popup Support.

sccs1.33 
8.0.20 RJL     16-Apr-96  Remove stdio.h include from 1.32. It was only there for Advisory
                          panel prototyping.

sccs1.34
8.0.21 RJL     16-Apr-96  Remove av<min,max>cvs for following since not needed for Advisory
                          panel popup:
			    av<min,max>rttseq, av<min,max>rtarr, av<min,max>rtpoint

sccs1.35
8.0.22 JDM     23-Apr-96  MRIge31909
                          Putback range of 0 to 0 for opirprep, opdeprep
			  and opmph, as scan-psd use this mechanism via
			  a cv rangecheck to disallow the feature. What a
			  kludge!!!
sccs1.36
8.0.23 RJL     02-May-96  Add av<min,max>flip for popup integration to last reqexports section.
                          This way we don't have to increase rev number and become out of sync
			  with scan.
sccs1.37
8.0.24 J.Meng  20-May-96  Changed lower limit of opslspace to -200 for neg slice spacing.

sccs1.38
8.0.25 RJL    30-May-96  Add av<min,max>slspace for advisory panel tracking to last reqexports
                         section. This way we don't need to bump up rev number or rebuild scan.

sccs1.39
8.0.26 RJL    22-Oct-96  MRIge35883 - Change system minimum of opxres to 256 and system min of
                         opyres to 128. We never allow anything less anyway.

sccs1.42
8.0.27 VB     04-Nov-96  MRIge35269 - Added a new cv - cfmaxb1rmhead = 3.6 - at the end of the
                         second @reqexport section.

8.0.28 RJL    10-Jan-97  Added a new CV cont_debug per mrt request

8.0.29 VB     06-Feb-97  Added two new #defines (G8651 and G8280) for SGD.

8.1.1  JAP	  28-May-97  Added CVs for Maxwell Phase-Contrast correction.	

sccs1.49   VB  18-Jun-97 Added new cvs for efgre3d, 3plane and epi2 psds.

sccs1.50   VB  20-Jun-97 Added opcmon for cardiac compensation.

sccs1.53  DRT  25-Jul-97 Added opzip512, opzip1024, opslzip2, and opslzip4
                             for 3dtof:lx2.

sccs1.54   PH  25-Aug-97 MRIge41379 - increase opautote to 5 to allow
                         MAXTE being selected.

sccs1.55  ALP  05-sep-97 Added pizmult to a required export and
                         CV num_images in the @cv section. 

sccs1.56  RJF  10-Sep-97 Changed the upper limit of all Lx2 New Imaging Option 
			 cvs to 0, so that the compatibility issues are caught in the 
			 psdIF.  Error message numbers have been added to these cv 
			 declarations so that these messages get popped up, on selecting 
			 an incompatible option with a pulse sequence.The CV definitions changed 
			 are of : opcmon, opsmartprep, opslzip2, opslzip4, and opzip512.

sccs1.57  NT  18-Sep-97 Changed the upper limit of cv rhimsize to 1024.
sccs1.59  JAP 23-Sep-97 Added macro XDCNTRL to change data path from
                        VSB to the XD. This is used in Smartprep.e for
                        SPU bolus monitoring. 

sccs1.61  VB  26-Sep-97 MRIge41781: Set max value for num_images to max int.
                        MRIge41965: Set pirtseqnub to 7.

sccs1.62  ALP  12-nov-97 Added piccsat_obl to a required export.

sccs1.63  VB   11-Dec-97 Set max value for opdiffuse to 0 with the error
                         with the error string EM_PSD_DIFF_INCOMPATIBLE.
                         MRIge43451.

cdp0.1   MS    12-Sep-1997   Added ipgexport CVs for Realtime (RT)

cdp0.2   GFN   21-Sep-1997   Added a check for multiple definitions of the
                             RUP_* and RDN_* macros.

cdp0.3   BJM   23-Oct-1997   Added a #define for sequential slice ordering
                             used in Black Blood
                             FSE (aka Blood Suppression and 2/3IR).

cdp0.4   GFN   23-Oct-1997   Added precision to the PI definition and added
                             a definition for M_PI.

cdp0.5   GFN   23-Oct-1997   Removed M_PI to avoid multiple definitions when
                             compiling for Simulaiton. epic.h in @inline'd
                             before any other file gets #include'd. Hence,
                             M_PI gets redefined during Simulation every time
                             math.h or values.h is #include'd.

cdp0.6	  MS   30-Oct-1997   Added realtime rspvar variables in the @rspvar
                             section. Previously these were scattered in 
                             Prescan and the psd sources.	

************************** Initial CV-1 Version ******************************

sccs1.69    BJM   10-Dec-1997  Initial port to lx2.  Updated #define for seq. 
                               slice order in 2/3IR-FSE since the cdp0 value is
                               used by ssfse in lx2.

sccs1.70    GFN   15-Dec-1997  Completed merge with Lx2. Many of the changes
                               in Lx2 were not incorporated.

sccs1.71    JAP   19-Dec-1997  Added CV-1 specific CVs.

sccs1.72    GFN   13-Jan-1997  Changed some CV-1 CV names to be consistent with
                               the naming convention and changed initial
                               value of optagspc from 0 to 7.
                               Added more CV's for Blood Suppression.

sccs1.73    GFN   16-Jan-1998  Changed revision to 17.

Lx-2        VB   18-Jan-98 set cvmax value for opfulltrain to 0

sccs1.74    GFN   19-Jan-1998  Put all CV's for Fast CINE together. Added
                               new ih CV's for this feature and renamed 
                               existing rh CV's to match naming conventions.
Lx-2        VB   04-Feb-98 set cvmax value for opssfse to 0

sccs1.75    BJM   21-Jan-1998  MRIge43968: modified definition of PSrot to be
                               a 2D matrix instead of a 1D array to make
                               passing this variable to scalerotmats() 
                               consistent with what is expected.

sccs1.76    BJM   21-Jan-1998  Added new #define PSD_AUTO_TI -1 so scan 
                               knows to set AUTO in pulldown menus for 
                               sequences that have internally calculated 
                               TI values.

sccs1.77    GFN   21-Jan-1998  Keep "prototype" CVs for Fast CINE.

sccs1.78    JAP   21-Jan-1998  Added config file variables for SGD
                               gradient heating support. Added
                               structure definitions and modified
                               LOG_GRAD for improved dB/dt ramp
                               derating.

sccs1.79   JAP    22-Jan-1998  Added intabspwmcurr argument to the
                               GRAD_PULSE structure. This is used for
                               the SGD heating calculation in
                               minseqgrad().

sccs1.81   JAP    4-Feb-1998   Added new fields to the FILTER_INFO
                               structure.

sccs1.82   BJM   20-Feb-1998   Changed min/max of opbspti to correspond
                               to TI_MIN & TI_MAX so the max/min dont have to 
                               be reset by the psd to use this CV.

sccs1.83   JAP   27-Feb-1998   Initialize opbspti/ihbspti to TI_MIN to
                               prevent download failure.

sccs1.84   JAP   03-Apr-1998   Added entry for CRM cfgcoiltype

sccs1.87   GFN   06-Apr-1998   MRIge44750 - Created raw header variable for
                               views per segment (rhvps).
                               MRIge42855 - Changed datatype of rsptrigger 
                               from int to long.

sccs1.88   JAP   21-Apr-1998   Merged in latest Lx-2 changes. Removed
                               rhpcgraph since it is unused. Bumped up
                               revision number to 18.

sccs1.89   JAP   12-May-1998   Put back rhpcgraph and set revision
                               back to 17 to make CV1M3 PSDs
                               compatible with CV1.

sccs1.90   GFN   18-May-1998   Changed type of rsprot and rsprot_base to 
                               long to match expected type in PGEN functions.

sccs1.91   GFN   26-May-1998   Changed ECG_MIN and ECG_MAX to match limits set
                               by the SPU.

sccs1.92   AKG   08-Jun-1998   Removed declaration of prescan rspvars pscR1,
                               pscR2, pscCF, pscTG from Prescan+.e and 
                               Prescan.e and added them in epic.h
                               to ensure availability to all PSDs.
                               Fix for spr MRIge46008

sccs1.93   GFN   09-Jun-1998   MRIge46184 - Added definitions for pirtwinval2,
                               pirtwinval3, pirtwinval4, pirtwinval5 and set
                               default for pirtrigwinnub.

sccs1.94   GFN   15-Jun-1998   MRIge46205 - Updated ECG_MIN to be 30 instead of
           AKG                 25. Added EM_PSD_HRATE_OUT_OF_RANGE as the 
                               default error message for ophrate and opchrate.

sccs1.95   GFN   18-Jun-1998   MRIge46184 - Since the reqexport section changed,
                               I am updating the revision ro 18.

sccs1.96   PS    24-Jun-1998   set PSrot and sat_rot_matrix to long since the
                               the prototypes require a long.

sccs1.97  VB/GFN 3-Aug-1998    MRIge46767: set the default value of ihfcineim 
                               and ihfcinemt to 0. This is to fix the problem 
                               with annotation.

           VB    3-Aug-1998    MRIge46787: added a new pi cv - pifractecho.
                               This is to implement the SNR Index feature.

sccs1.98   GFN   12-Aug-1998   Updated the subst: section of the SINGLE_TRAP
                               macro to expand as a TRAPEZOID2 macro for
                               pulsegen on the Host.

sccs1.99   NDG   20-Aug-1998   MRIge46987: The new field entry "intabspwmcurr"
                               moved to the last position in GRAD_PULSE 
			       structure so as to keep "bridge" entry in its 
			       original position (21st field).

sccs2.00   BJM   05-Oct-1998   MRIge47714 - added #PSD_SR150

sccs2.01   PH    07-Oct-1998   MRIge47732 - set default b value to 1000 
                               which is used in most DWI applications.

           GFN   12-Oct-1998   MRIge47485: Added seg_debug, seg_method,
                               minseqpwm_x, minseqpwm_y, minseqpwm_z, and
                               minseq_gpm for Improved Gradient Duty Cycle
                               feature.

           GFN   12-Nov-1998   Merged update for 3D Oblique. Added 
                               TYPF3DMSMPH.

           RJF   19-Oct-1998   Adding RTIA reqcv.

           GFN   17-Nov-1998   Merged changes into mr_main branch.

           CMC   24-Nov-1998   Added the CVs for Bolus Chasing. Changed the
                               rhrawsize max value also to prevent from
                               stoping the scan.

           CMC   25-Nov-1998   Changed the formating style for the CVs which
                               I have declared in the previous step.

           PRA   07-Dec-1998   MRIge47735 - Added faster prescan cv
                               cffastprescan.

           GFN   08-Dec-1998   Removed unused epstring_length variable in
                               EP_TRAIN macro.

           GFN   22-Dec-1998   Added new config variables for miniGRAM power
                               monitor calculation. Bumped revision to 20.

	   TAA   15-Feb-1999   Added a new Required CV to indicate whether the
			       mode is Protocol or Scan.

           GFN   11-Feb-1999   Renamed minseq_gpm to minseqgpm_t.
                               Renamed seg_method to gradHeatMethod.
                               Changed seg_debug to be a multilevel debugging
                               flag.
                               Added sgd_perf_simulate to simulate SGD
                               performance key.

           GFN   24-Feb-1999   MRIge51205 - Changed default value of 
                               cfmaxb1rmshead from 3.6 to 7.2.

           GFN   18-Mar-1999   Changed sgd_perf_simulate to be a boolean flag.

       BJM/GFN   19-Mar-1999   Added a new macro EFFSLICESELZ_SPSP to support
                               EchoTrains on the Host side using a sequence of
                               trapezoids.

           GFN   23-Mar-1999   Updated tsamp definition to include min, max,
                               and default values.

            PH   31-Mar-1999   MRIge52235 - define a CV opflair for flair-epi.

           GFN   02-Apr-1999   Since opflair was added in the middle of the
                               file, I am updating the revision number to 21
                               to prevent strange error messages.

           JAH   05-Apr-1999   Added new supported MNS sequence types, a new
                               CV acquire_type for CERD selection, updated
                               specnuc max value for Xenon support, and
                               updated GAM value (more precise).

           GFN   20-Apr-1999   Updated SLICESELXEXT() and SLICESELYEXT() to add
                               a missing $ in front of the [slsel_loggrd].xft
                               and [slsel_loggrd].yft arguments, respectively.

           GFN   28-Apr-1999   MRIge53080 - Added new config variable
                               cfcerdtype to indicate the type of CERD
                               installed.

           GFN   03-Jun-1999   MRIge53164 - Added new CV to allow corner points
                               to be dumped to a file.

           JFS   11-Jan-1999   Added an RSP variable flag cont_sp_changed, which
                               is set if cont_x|y|z_offset is not equal
                               to cont_x|y|z_offset_old and which is reset otherwise.

           GFN   16-Jun-1999   MRIge50364 - Changed SmartStep for MultiStation.

           GFN   23-Jun-1999   MRIge54002 - Updated SEQLENGTH to call a new
                               function that will provide the sequence index.

           GFN   02-Jul-1999   MRIge54002 - Provide a CV to allow the operator
                               to change the sequence used in the Full SGD
                               heating model.

           GFN   21-Jul-1999   MRIge54076 - Provide a CV to set percentange of
                               FOV to be used as overlap for Bolus Chasing.

           AKG   16-Aug-1999   added 10th bit to rhdacqctrl
                               RH_PASS_THROUGH_CERD_FLAG 1024 /* passthrough data acq. 
           NDG   26-Aug-1999   Added RHTYPSPIRAL field for rhtype1 for recon
           AKG   28-Sep-1999   added 11th bit to rhdacqctrl MRIge56094
                               10bit used for RDB_FCINE_ET. passthrough now uses 11th bit.
                          
           BJM   9-30-99       MRIge56151 -> 83 - 84 Merge - added the 
                                             following:
           BJM                 MRIge54970 - Added cfcerdbw1, cfcerdbw2, 
                               cfcerdbw3, cfcerdbw4. Updated revision to 22.

           GFN                 MRIge55689 - Moved opfovpctovl to 3-Plane.e as
                               the support to MultiStation has been removed
                               from 2dfast.e.

           PH                  MRIge55955 - Define t1flair_flag for the T1FLAIR
                               feature so that all the psds can see it.  No 
                               more compile errors for fse family.

           RJF  07-Oct-1999    RTIA/Echotrain realtime changes 
                               added rtia_firstscan_flag.
           AKG  14-oct-1999    Added macro SLICESELZEXT2STR which is same as SLICESELZEXT2
                               except that string vars are allowed for filenames.
           BJM  10-Nov-1999    Add opmintedif for Hi-B feature.
           NDG  10-Nov-1999    New rh values defined for spirals.
           NDG  17-Nov-1999    New options page CVs.
           NDG  22-Nov-1999    New negative slice spacing pi value.
           NDG  23-Nov-1999    Spirals through imaging option CV (opspiral).

           BJM  12-Dec-1999    **** 83M4 -> 84 Merge ***
                               MRIge56470 - define a config CV for "Picture 
                               This" mode. Let's call it cfpicture. SCAN will 
                               set it in the "Picture This" mode, otherwise 
                               it is 0.
                               MRIge56509 - Added new #define ( G8915 ) for 
                               ACGD Hi Slew.
           AKG  15-Dec-1999    MRIge57391 - added new reqd CV opET. (imaging option)
                               for spiral added reqd CVs cfxrdelay cfyrdelay cfzrdelay
                               (for recording group delays)
 
           BJM  01-Jan-2000    MRIge57291 - added opascalcfov for localized shim 
                               testing with spiral CAI

           YZ   14-Jan-2000    Add use_dbdt_opt as logic flag to indicate whether
                               dB/dt optimization is used.  See comment at the definition
                               for details.

           BJM  28-Jan-2000    MRIge58034 - change max of opssrf and opt2prep to 0.

           NDG  07-April-2000  MRIge58514 - Error message for T2Prep and ssrf.

************************************************ */

/* Bump up this integer value whenever the
   required cv section has changed */
@revision 27

@global

extern char psd_name[255];

/* ***************************
	IPG-PSD COMMON AREA
   Pulsegen Constants and
   Hardware specific variables
   ************************** */
#include "GEtypes.h"             /* type definitions from GEtypes project*/
#include "ca_filt.h"
#define EOS_PLAY 0
#define EOS_DEAD 1

/* IPG Trigger Codes */
#define TRIG_LINE 1
#define TRIG_ECG 3
#define TRIG_AUX 5
#define TRIG_INTERN 7
#define TRIG_NLINE 9  /* TRIG_NLINE is not a real hardware trigger.
			 It is used to bump up optr by TR_SLOP when a 
			 sequence may line gate based on the value
			 of optr.  So if a new #define is needed for
			 the hardware, change the value of TRIG_NLINE */

/* WARP codes */
#define WARP_UPDATE_NOW 0
#define WARP_UPDATE_ON_SSP_INT 1

/* Pause Attributes */
#define MAY_PAUSE 1
#define MUST_PAUSE 2
#define AUTO_PAUSE 3

/* Reilly dBdt value at infinite transition time  */
#define REILLYDBDTINF 54.0
/* DBDT factor divided by transition time added to REILLYDBDTINF */
#define REILLYDBDTFACTOR 132.0

/* Structure for the PSD supplied error parameters for rspexit */
typedef struct {
  long abcode;
  char text_string[256];
  char text_arg[16]; /* text argument */
  long *longarg[4];   /* pointers to global status ints */
} PSD_EXIT_ARG;

/* ************************************
   CINE Structures
   ********************************** */
typedef struct {     /* structure for cine info that is static */
  int c_numviews;   /* number of cine views to be played */
  int c_curpass;   /* current pass number */
  int c_tr;         /* cine TR in us */
  short c_slq;      /* number of slices */
  short c_acq;      /* # of acqs */
} CINE_PASS;        /* the psd will update this at the start of 
		       each pass */

/* The following packet will be updated by the IPG software and 
   ready to be read by the PSD ssivector routine during the ssi 
   interrupt.  It informs the the psd of the view to play, whether 
   the data collection should be in disdaq mode, whether a cine packet
   should be transmitted, and what information should be placed in
   the cine packet. */
typedef struct {   
  short c_arr;       /* arrhythmia of Cine packet */
  short c_op;        /* operation, as in DAB packet */
  int c_nview;       /* next view number to play */
  int c_pview;       /* previous view number  */
  short c_frame1;    /* frames, slice 1 */
  short c_frame2;    /* frames, slice 2 */
  short c_frame3;    /* frames, slice 3 */
  short c_frame4;    /* frames, slice 4 */
  int c_delay;       /* time from R-wave to beginning of first frame
			in units of 1.25 ms */
  int c_f1slice;     /* frame 1`s slice number */
  short c_check;     /* end of pass check */
  short c_collect;   /* data collection flag */
  short c_send;      /* cine packet send flag */
  short c_group;     /* cine exorcist group */
} CINE_SEQ;

/************************************/
/* These structures are new for 5.5 */
/************************************/

/* 3/13/95 YI changed for new system safety */

/* ************************************
   Physical and Logical Gradient Structures
  ********************************** */

typedef struct {   /* Physical gradient quantities */
  int xfull;       /* cfxfull */
  int yfull;       /* cfyfull */
  int zfull;       /* cfzfull */
  float xfs;       /* X grad full scale (G/cm) */
  float yfs;       /* Y grad full scale (G/cm) */
  float zfs;       /* Z grad full scale (G/cm) */
  int   xrt;       /* X rise time 0-full scale (usec) */
  int   yrt;       /* Y rise time 0-full scale (usec) */
  int   zrt;       /* Z rise time 0-full scale (usec) */
  int   xft;       /* X fall time full scale-0 (usec) */
  int   yft;       /* Y fall time full scale-0 (usec) */
  int   zft;       /* Z fall time full scale-0 (usec) */
  float xcc;       /* X current capacity (amps) */
  float ycc;       /* Y current capacity (amps) */
  float zcc;       /* Z current capacity (amps) */
  float xbeta;     /* X grad linear ramp factor */
  float ybeta;     /* Y grad linear ramp factor */
  float zbeta;     /* Z grad linear ramp factor */
  float xirms;     /* X constant RMS coil current rating  */
  float yirms;     /* Y constant RMS coil current rating  */
  float zirms;     /* Z constant RMS coil current rating  */
  float xipeak;    /* X peak current output (was xfa)   */
  float yipeak;    /* Y peak current output (was yfa)   */
  float zipeak;    /* Z peak current output (was zfa)   */
  float xamptran;  /* X amp transition current (KA/Sec) */
  float yamptran;  /* Y amp transition current (KA/Sec) */
  float zamptran;  /* Z amp transition current (KA/Sec) */
  float xiavrgabs; /* X absolute average value current limit (Amperes) */
  float yiavrgabs; /* Y absolute average value current limit (Amperes) */
  float ziavrgabs; /* Z absolute average value current limit (Amperes) */
  float xirmspos;  /* X positive RMS current limit (Amperes)  */
  float yirmspos;  /* Y positive RMS current limit (Amperes)  */
  float zirmspos;  /* Z positive RMS current limit (Amperes)  */
  float xirmsneg;  /* X negative RMS current limit (Amperes)  */
  float yirmsneg;  /* Y negative RMS current limit (Amperes)  */  
  float zirmsneg;  /* Z negative RMS current limit (Amperes)  */
  float xpwmdc;    /* X pulse width modulation duty cycle limit (0~1) */
  float ypwmdc;    /* Y pulse width modulation duty cycle limit (0~1) */
  float zpwmdc;    /* Z pulse width modulation duty cycle limit (0~1) */
  } PHYS_GRAD;

/*Structures for use with values that depend on the number of active
  logical gradients. For example t_xcon is a structure for information
  about gradient ramp-times (or targets) for the logical
  x-axis. The x structure member is used when only x is active, xy is
  used when only x and y are active, etc. */

typedef struct {
  int x;
  int xy;
  int xz;
  int xyz;
}  t_xact;

typedef struct {
  int y;
  int xy;
  int yz;
  int xyz;
}  t_yact;

typedef struct {
  int z;
  int xz;
  int yz;
  int xyz;
}  t_zact;

typedef struct { 
  int xrt;
  int yrt;
  int zrt;
  int xft;
  int yft;
  int zft;
} ramp_t;

typedef struct {   /* Logical gradient quantities */
  int   xrt;       /* X rise time 0-full scale (usec) */
  int   yrt;       /* Y rise time 0-full scale (usec) */
  int   zrt;       /* Z rise time 0-full scale (usec) */
  int   xft;       /* X fall time full scale-0 (usec) */
  int   yft;       /* Y fall time full scale-0 (usec) */
  int   zft;       /* Z fall time full scale-0 (usec) */
  ramp_t opt;      /* RJF optimized rise times for different axes based on actual dB/dt */
  t_xact xrta;     /* X rise time for different number of active gradients */
  t_yact yrta;     /* Y rise time for different number of active gradients */
  t_zact zrta;     /* Z rise time for different number of active gradients */
  t_xact xfta;     /* X fall time for different number of active gradients */
  t_yact yfta;     /* Y fall time for different number of active gradients */
  t_zact zfta;     /* Z fall time for different number of active gradients */
  float xbeta;     /* X grad linear ramp factor */
  float ybeta;     /* Y grad linear ramp factor */
  float zbeta;     /* Z grad linear ramp factor */
  float tx_xyz;    /* X target, 3 logical functions active (G/cm) */
  float ty_xyz;    /* Y target, 3 logical functions active (G/cm) */
  float tz_xyz;    /* Z target, 3 logical functions active (G/cm) */
  float tx_xy;     /* X target, x and y active (G/cm) */
  float tx_xz;     /* X target, x and z active (G/cm) */
  float ty_xy;     /* Y target, x and y active (G/cm) */
  float ty_yz;     /* Y target, y and z active (G/cm) */
  float tz_xz;     /* Z target, x and z active (G/cm) */
  float tz_yz;     /* Z target, y and z active (G/cm) */
  float tx;        /* X target, x active (G/cm) */
  float ty;        /* Y target, y active (G/cm) */
  float tz;        /* Z target, z active (G/cm) */
  float xfs;       /* X full scale value (G/cm)   */
  float yfs;       /* Y full scale value (G/cm)   */
  float zfs;       /* Z full scale value (G/cm)   */
  float xirms;     /* X constant RMS coil current rating  */
  float yirms;     /* Y constant RMS coil current rating  */
  float zirms;     /* Z constant RMS coil current rating  */
  float xipeak;    /* X peak current output    */
  float yipeak;    /* Y peak current output    */
  float zipeak;    /* Z peak current output    */
  float xamptran;  /* X amp transition current (KA/uSec)  */
  float yamptran;  /* Y amp transition current (KA/uSec)  */
  float zamptran;  /* Z amp transition current (KA/uSec)  */  
  float xiavrgabs; /* X absolute average value current limit (Amperes) */
  float yiavrgabs; /* Y absolute average value current limit (Amperes) */
  float ziavrgabs; /* Z absolute average value current limit (Amperes) */
  float xirmspos;  /* X positive RMS current limit (Amperes)   */
  float yirmspos;  /* Y positive RMS current limit (Amperes)   */
  float zirmspos;  /* Z positive RMS current limit (Amperes)   */
  float xirmsneg;  /* X negative RMS current limit (Amperes)    */
  float yirmsneg;  /* Y negative RMS current limit (Amperes)    */
  float zirmsneg;  /* Z negative RMS current limit (Amperes)    */
  float xpwmdc;    /* X pulse width modulation duty cycle limit (0~1) */
  float ypwmdc;    /* Y pulse width modulation duty cycle limit (0~1) */
  float zpwmdc;    /* Z pulse width modulation duty cycle limit (0~1) */
  } LOG_GRAD;

/* ************************************
   Echo Planar Optimization Structures
   ********************************** */
typedef struct {
  float xfs;       /* x grad full scale (g/cm) */
  float yfs;       /* y grad full scale (g/cm) */
  int   xrt;       /* x grad rise time 0-xfs (usec) */
  int   yrt;       /* y grad rise time 0-yfs (usec) */
  float xbeta;     /* beta for segmented parabolic waveshapes x grad */
  float ybeta;     /* beta for segmented parabolic waveshapes y grad*/
  float xfov;      /* fov in logical x direction (cm) */
  float yfov;      /* fov in logical y direction (cm) */
  int   xres;      /* operator selected x resolution (pixels) */
  int   yres;      /* operator selected y resolution (pixels) */
  int   ileaves;   /* number of interleaved shots */
  float xdis;      /* x distance for dB/dt calculation */
  float ydis;      /* y distance for dB/dt calculation */
  float tsp;       /* sample period */
  int   osamps;    /* Fractional echo oversamps */
  float fbhw;      /* fraction of blip half width excluded from
                                          sampling (VRG only) */
  int   vvp;       /* inter-echo base period */
  float pnsf;      /* peripheral nerve stimulation factor */
} OPT_GRAD_INPUT;
 
typedef struct {
  float *agxw;     /* epi readout pulse amplitude */
  int   *pwgxw;    /* epi readout pulse width */
  int   *pwgxwa;   /* epi readout attack/decay ramp */
  float *agyb;     /* epi blip pulse amplitude */
  int   *pwgyb;    /* epi blip pulse width */
  int   *pwgyba;   /* epi blip pulse attack/decay ramp */
  int   *frsize;   /* frame size - number of samples */
  int   *pwsamp;   /* sample window width */
  int   *pwxgap;   /* epi readout interecho gap */
} OPT_GRAD_PARAMS;
 
/*********************************/
/* End of new structures for 5.5 */
/*********************************/
 

#define CN_PASSES_EXCEEDED 1
#define CN_FRAMES_EXCEEDED 2
#define CN_NOINIT          3
#define EX_NOINIT          4
/* Number of entries in entry point table */
#define ENTRY_POINT_MAX 20

/* constants for createramps routine *//* merged 55 bch. YH */
#define PSD_SLOPE_NONE 0
#define PSD_SLOPE_UP 1
#define PSD_SLOPE_DOWN 2

/* END - PSD - IPG common area */

/* Visibility Constants */
#define VIS MODIFIABLE

#define PSD_FILTER_MAX 14

/* #ifdef MCVALL */ /* make all the CVs modifiable for vmx testing. 7/18/94 */ 

#define INVIS    MODIFIABLE
#define VISONLY  MODIFIABLE
/* #else
#define INVIS    INVISIBLE
#define VISONLY  VISIBLE
#endif */

/* Board Names */

#define XGRAD TYPXGRAD
#define YGRAD TYPYGRAD
#define ZGRAD TYPZGRAD
#define RHO   TYPRHO1
#define THETA TYPTHETA
#define OMEGA TYPOMEGA
#define SSP   TYPSSP
#define XGRADB TYPBXGRAD
#define YGRADB TYPBYGRAD
#define ZGRADB TYPBZGRAD
#define XGRD 1   /* merged 55 bch */
#define YGRD 2   /* into vmx.     */
#define ZGRD 3   /* YH 10/14/94   */
 
/* Can't use pulsegen constant for number of processors */
#define PSD_MAX_PROCESSORS 9
/* Misc. constants */
#ifndef PI
#define PI 3.14159265358979323846
#endif /* PI */
/* Positive Full Scale in IPG.  All #'s
/   scaled to this number */
#define FSI 32752 
#define FSI_PI

/* integer values for pi and 2pi */
#define FS_PI 32752
#define FS_2PI 65504

#define GFS 1.0 /* gradient full scale G/cm */

/* gradient amp constants */
#define G8603 0
#define G8604 1
#define G8607 2
#define G8645 3    /* merged 55 bch         */
#define G8250 4    /* Analogic single for VMX *//* into vmx. YH 10/14/94 */
#define G8251 5    /* Analogic twin for VMX SR40 *//* 06/21/95 YI */
#define G9090 6    /* YMS HDU for Profile system *//* 06/21/95 YI */
#define G8651 7    /* Analogic SGD Hi Slew */
#define G8280 8    /* Analogic SGD Base */
#define G8915 9    /* ACGD Hi Slew */

/* gradient coil types *//* vmx 12/07/94 YI */
#define GCOIL_NONE 0
#define GCOIL_CRD 1
#define GCOIL_ROEMER 2
#define GCOIL_HGC 101
#define GCOIL_VECTRA 102
#define GCOIL_PERMANENT 103

/* GRAM tuning board types */
#define GRAM_TUNE_ANALOG 0  /* merged 55 bch into vmx */
#define GRAM_TUNE_DIGITAL 1 /*            YH 10/14/94 */

/* Service Mode Types for Exciter */
#define PSD_SERVOFF 0
#define PSD_SERVSYNTH 1
#define PSD_SERVLB 2

/* Power Amplifier Selects */
#define AMP_ERBTEC 1
#define AMP_SPECTRO 2

/* Pre and Post Min RF AMP Unblank Times */
#define PSD_PRERFAMP_UBL 250
#define PSD_POSTRFAMP_UBL 50
#define PSD_PRERFAMP_UBL_VMX 600

/* Broadband Use */
#define PSD_BROADBANDOFF 0
#define PSD_BROADBANDON 1

/* Coil Types */
#define PSD_HEAD 1
#define PSD_BODY 2
#define PSD_SURFACE 3
#define PSD_TEST 4

/* Receiver Input Ports */
#define PSD_RP_HEAD 1
#define PSD_RP_BODY 2
#define PSD_RP_SURFACE 3
#define PSD_RP_CERDMC 4
#define PSD_RP_SPECTRO 5
#define PSD_RP_TEST 0

/* Receiver Bias Port */
#define PSD_RB_HEAD 4
#define PSD_RB_BODY 8
#define PSD_RB_SURFACE 16
#define PSD_RB_TEST 32

/* image modes */
#define PSD_2D 1
#define PSD_3D 2
#define PSD_CINE 3
#define PSD_ANGIO 4
#define PSD_SPECTRO 5
#define PSD_3DM 6   /* image mode for 3D Multi-slab */

/* Pulse Sequence Types */
#define PSD_SE 1
#define PSD_GE 2
#define PSD_IR 3
#define PSD_SSFP 4
#define PSD_SPGR 5
#define PSD_TOF 6
#define PSD_PC 7
#define PSD_TOFSP 8
#define PSD_PCSP 9
#define PSD_PROBES 10
#define PSD_PROBEP 11
#define PSD_PRESSCSI 12
#define PSD_STEAMCSI 13
#define PSD_FIDCSI 14
#define PSD_ECHOCSI 15
#define PSD_SPINECHO 16
#define PSD_3PLANELOC 17 

/* Scanning Planes */
#define PSD_AXIAL 1
#define PSD_SAG 2
#define PSD_COR 3
#define PSD_OBL 4
#define PSD_3PLANE 5

/* Scan Rotation Scaling */
#define SHAREDROTSCALE 32752

/* Maximum wave amplitude constants */
#define  max_pg_iamp 32767
#define  max_pg_wamp 32766
#define  MAX_PG_IAMP 32767
#define  MAX_PG_WAMP 32766

/* Pre Defined Timing Constants */
#define TGAP 2

/* Screen Flag values */
#define PSD_OFF 0
#define PSD_ON 1

/* TE Button Control Values */
#define PSD_MINFULLTE -1
#define PSD_MINIMUMTE -2
#define PSD_FWINPHASETE	-3
#define PSD_FWOUTPHASETE -4
#define PSD_MAXIMUMTE -5

/* Automin TR Button Control *//* merged 55 bch into vmx. YH 10/14/94 */
#define PSD_MINIMUMTR -1

/* label control for te buttons */
#define PSD_LABEL_TE_NORM 0
#define PSD_LABEL_TE_EFF  1

/* label control for ti buttons */
#define PSD_AUTO_TI -1
#define PSD_LABEL_TI_IR 0
#define PSD_LABEL_TE_PREP 1

/* label control for pause buttons */
#define PSD_LABEL_PAU_LOC 0
#define PSD_LABEL_PAU_REP 1
#define PSD_LABEL_PAU_ACQ 2

/* screen control for rbw buttons */
#define PSD_BW_SCREEN_SET 0
#define PSD_BW_SCREEN_TIM 1

/* Scan Clock Modes */
#define PSD_CLOCK_NORM 0
#define PSD_CLOCK_CARDIAC 1
#define PSD_CLOCK_PAUSE 2
#define PSD_CLOCK_CARDPAUSE 3

/* Cardiac Inter-Sequence Delay Defines */
#define PSD_CARD_INTER_OTHER 0
#define PSD_CARD_INTER_MIN 1
#define PSD_CARD_INTER_EVEN 2

/* Center Frequency Button Defines */
#define PSD_CFCURRENT 0
#define PSD_CFMID 1
#define PSD_CFH2O 2
#define PSD_CFFAT 3
#define PSD_CFPK 4
#define PSD_CFCENTROID 5

/* Rf pulse Activity bitmasks */
#define PSD_PULSE_OFF 0
#define PSD_CFL_ON 1
#define PSD_CFL_HAD 2
#define PSD_CFH_ON 4
#define PSD_CFH_HAD 8
#define PSD_MPS1_ON 16
#define PSD_MPS1_HAD 32
#define PSD_MPS2_ON 64
#define PSD_MPS2_HAD 128
#define PSD_APS1_ON 256
#define PSD_APS1_HAD 512
#define PSD_APS2_ON 1024
#define PSD_APS2_HAD 2048
#define PSD_SCAN_ON 4096
#define PSD_SCAN_HAD 8192
/*#define PSD_TEST_ON 16384
#define PSD_TEST_HAD 32768*/
#define PSD_FTG_ON  16384   /* merged 55 bch into vmx. YH 10/14/94 */
#define PSD_FTG_HAD 32768
#define PSD_AUS_ON 65536
#define PSD_AUS_HAD 131072
#define PSD_TEST_ON 262144
#define PSD_TEST_HAD 524288 /* merged 55 bch into vmx. YH 10/14/94 */

/* Type of phase generation for 
   altfrgen */

#define TYPLINEAR 0
#define TYPMFILE 1

/* Limit checks for advisory panel routines */
#define PSD_MIN3DSLICE 16
#define PSD_MINF3DSLICE 16
#define PSD_MIN3DPCSLICE 12
#define PSD_MINSLQPSLAB 16
#define PSD_MAXSLQPSLAB 128
#define PSD_MAXIMAGTYP 4

/* used for slice select external macro */
#define PLAY_GFILE 1
#define PLAY_TRAP 0
#define PLAY_RFFILE 1 /* merged 55 bch into vmx. YH 10/14/94 */
#define PLAY_SINC 0
#define PLAY_THETA 1
#define NO_THETA 0    /* merged 55 bch into vmx. YH 10/14/94 */

/* END - PSD - IPG common area */
/* Bitmask fields for explicit sat locations */
#define PSD_EXPLICIT_Z2 0x01
#define PSD_EXPLICIT_Z1 0x02
#define PSD_EXPLICIT_Y2 0x04
#define PSD_EXPLICIT_Y1 0x08
#define PSD_EXPLICIT_X2 0x10
#define PSD_EXPLICIT_X1 0x20

/* bits for opexsatmask */
#define PSD_EXPLICIT_1 0x01
#define PSD_EXPLICIT_2 0x02
#define PSD_EXPLICIT_3 0x04
#define PSD_EXPLICIT_4 0x08
#define PSD_EXPLICIT_5 0x10
#define PSD_EXPLICIT_6 0x20

/* bits for opexparal */
#define PSD_1_PARALLEL 0x01
#define PSD_2_PARALLEL 0x02
#define PSD_3_PARALLEL 0x04

/* Bitmask fields for rhvtype (vascular) */
#define VASCULAR   1                /* Vascular scan */
#define PHASE_CON  2                /* Phase contrast scan */
/** #define UNUSED    4             * Bit three currently unused */
#define TWO_SET    8                /* Two set processing */
#define ANTI_ALIAS 16               /* Anti alias algorithm */
#define PHASE_1    32               /* Phase correction bit 1 */
#define PHASE_2    64               /* Phase correction bit 2 */
#define NOISE_SUPP 128              /* Apply noise suppression mask */
#define MAGNITUDE  256              /* Display magnitude image */
#define PHYSICAL_X 512              /* Display physical x correction */
#define PHYSICAL_Y 1024             /* Display physical y correction */
#define PHYSICAL_Z 2048             /* Display physical z correction */
#define COLLAPSE_Z 4096             /* Collapse logical z image */
#define COLLAPSE_X 8192             /* Collapse logical x image */
#define COLLAPSE_Y 16384            /* Collapse logical y image */
#define VN_1SL_2ST 32768            /* Vinnie 1 slice, 2 set */
#define VN_1SL_4ST 65536            /* Vinnie 1 slice, 4 set */
#define VN_2SL_2ST 131072           /* Vinnie 2 slice, 2 set */
#define ANG_10_DEG 524288           /* Projections every 10 degrees */
#define ANG_5_DEG  1048576          /* Projections every 5  degrees */
#define NOISE2     2097152          /* Bit for complex difference */

/* constants for vascular enhancements */
#define PHASEDIFF 0
#define COMPLEXDIFF 1
#define FLOWANALYS 2

/* Argument types for psdexit */
#define PSD_ARG_INT 1
#define PSD_ARG_FLOAT 2
#define PSD_ARG_STRING 3

/* Control Fields in SSP instruction */
#define PSD_CINE_BIT  0x800000
#define PSD_EXOR_BIT  0x400000
#define PSD_ISI2_BIT  0x080000
#define PSD_ISI1_BIT  0x040000
#define PSD_ISI0_BIT  0x020000
#define PSD_EFB_BIT   0x000080
#define PSD_UBL_RFMOD 0x000040
#define PSD_SCP_TRIG  0x000020
#define PSD_UBL_SPECT 0x000010
#define PSD_UBL_ERB   0x000008
#define PSD_MTX_UPDT  0x000004
#define PSD_WVE_CLR   0x000002
#define PSD_SLC_MARK  0x000001
#define PSD_SPUI_BIT  0x000100

/* System Update Times */
#define GRAD_UPDATE_TIME 4us
#define RF_UPDATE_TIME 2us
#define SSP_UPDATE_TIME 1us

/* Macros for rounding up or down to a gradient or RF boundary */
/* These macros are also defined in supp_macros.h. Let's check for
   multiple definitions. - GFN - 21/Sep/1997 */
#ifndef RUP_GRD
#define RUP_GRD(A)  (((A)%GRAD_UPDATE_TIME) ? (int)((A) + GRAD_UPDATE_TIME) & ~(GRAD_UPDATE_TIME - 1) : (A))
#endif /* RUP_GRD */

#ifndef RDN_GRD
#define RDN_GRD(A)  ((int)(A) & ~(GRAD_UPDATE_TIME -1))
#endif /* RDN_GRD */

#ifndef RUP_RF
#define RUP_RF(A)  (((A)%RF_UPDATE_TIME) ? (int)((A) + RF_UPDATE_TIME) & ~(RF_UPDATE_TIME - 1) : (A))
#endif /* RUP_RF */

#ifndef RDN_RF
#define RDN_RF(A)  ((int)(A) & ~(RF_UPDATE_TIME -1))
#endif /* RDN_RF */

#define MIN_PLATEAU_TIME (2*GRAD_UPDATE_TIME)

/* Theta path frequency path multiplier */
#define PSD_THETAFREQ_SHIFT 4

/* IPG Instruction Size Allocations */
#define PSD_GRADX_INSTR_SIZE  4096
#define PSD_GRADY_INSTR_SIZE  4032
#define PSD_GRADZ_INSTR_SIZE  4096
#define PSD_RHO1_INSTR_SIZE   4096
#define PSD_RHO2_INSTR_SIZE   4096
#define PSD_THETA_INSTR_SIZE  4096
#define PSD_OMEGA_INSTR_SIZE  4096
#define PSD_SSP_INSTR_SIZE    4096
#define PSD_AUX_INSTR_SIZE     64

/* IPG Exit Codes */
#define ERRNONE 0 /* Normal error */

/* User CV control constants */
#define use0  1
#define use1  2
#define use2  4
#define use3  8
#define use4  16
#define use5  32
#define use6  64
#define use7  128
#define use8  256
#define use9  512
#define use10 1024
#define use11 2048
#define use12 4096
#define use13 8192
#define use14 16384
#define use15 32768
#define use16 65536
#define use17 131072
#define use18 262144
#define use19 524288
#define use20 1048576
#define use21 2097152
#define use22 4194304
#define use23 8388608
#define use24 16777216

/* Advisory panel bitmap posistions
 * Note: These are bit positions and not values.
 * The following are for echos, te, te2, ti, tr,
 * fov, receive bandwidth, and velocity encode. */
#define PSD_ADVECHO 0
#define PSD_ADVTE 1
#define PSD_ADVTE2 2 
#define PSD_ADVTI 3
#define PSD_ADVTR 4
#define PSD_ADVFOV 5
#define PSD_ADVRCVBW 6
#define PSD_ADVVENC 7
#define PSD_ADVRCVBW2 8

#define PSD_ADV_SCAN_PARAMS_MAX 7
/* More advisory panel bit positions.
 * The following are respectively for minimum scan time,
 * max. locations/acq, minimum acquisitions, and maximum
 * yres. */
#define PSD_ADVMINTSCAN PSD_ADV_SCAN_PARAMS_MAX + 1
#define PSD_ADVMAXLOCSPERACQ PSD_ADV_SCAN_PARAMS_MAX + 2
#define PSD_ADVMINACQS PSD_ADV_SCAN_PARAMS_MAX + 3
#define PSD_ADVMAXYRES PSD_ADV_SCAN_PARAMS_MAX + 4

#define PSD_ADV_TIME_MAX PSD_ADV_SCAN_PARAMS_MAX + 4

/* More advisory panel bitmap positions.
 * The following are respectively for minimum inter-sequence
 * time, maximum phases, effective TR, maximum scan locations,
 * available image time. 
 * ***************************************************** */
#define PSD_ADVISEQDELAY PSD_ADV_TIME_MAX + 1
#define PSD_ADVMAXPHASES PSD_ADV_TIME_MAX + 2
#define PSD_ADVEFFTR PSD_ADV_TIME_MAX + 3
#define PSD_ADVMAXSCANLOCS PSD_ADV_TIME_MAX + 4
#define PSD_ADVAVAILIMGTIME PSD_ADV_TIME_MAX + 5

/* VRG pulse Resolutions */
#define RES_VRG_GRD 256
#define RES_VRG_RF1 512
#define RES_VRG_RF2 512
#define RES_NVRG_RF1 800
#define RES_NVRG_RF2 400
#define PSD_HNOVER 8
#define PSD_TRMIN 18ms


/* CV limit constants */
#define ECG_MIN 30
#define ECG_MAX 230
#define FOV_MIN 1
#define FOV_MIN_VMX 30
#define FOV_MIN_PROFILE 80        /* profile 09/11/95 NM */
#define FOV_MAX 480
#define FOV_MAX_VMX 450
#define FOV_MAX_PROFILE 400       /* profile 09/11/95 NM */
#define PSD_GRXROI_LEN 640.0
#define PSD_SEQMODE_OFF 0
#define ILIRMODE PSD_SEQMODE_OFF
#define MIN_TDEL1 10
#define MIN_SEQ_SYS 2048
#define MAX_TDEL1 1600000
#define MIN_RESP_POINT 10
#define MAX_RESP_POINT 90
#define MIN_RESP_WINDOW 10
#define MAX_RESP_WINDOW 90
#define MAX_CINE_PHASES 32
#define MAX_CINE_SLICES 4
#define MAX_STHICK 200
#define MAX_SLICE3D 128
#define MAXTHICK 20
#define MAXVTHICK 1280
#define MAXVQUANT 64
#define MIN_OFFSET -255
#define MIN_SLOC -12000
#define MIN_STHICK 10
#define MINTHICK 0.1
#define MINTHICK_VMX 2.7
#define NEX_MAX 200
#define NECHO_MIN 1
#define NECHO_MAX 4
#define NOIRMODE 0
#define PSD_NECHO_MAX 1024
#define PSD_SEQMODE_ON 1
#define SIRMODE PSD_SEQMODE_ON
#define SHORT_TE 22000
#define TE_MIN 1000
#define TE_MAX 2000000
#define TE2_MIN 20000
#define TI_MIN 50000
#define TI_MAX 4000000
#define TR_MIN 1000
/* VMX VALUE? #define TR_MAX 6000000 */
#define TR_MAX 15000000
#define XRES_MAX 1024
#define YRES_MAX 1024
#define MAXSLQUANT3D 128
#define MAXSLQUANT2D 256
#define PSD_HNOVER 8
#define PHASES_MIN 1
#define PHASES_MAX 512
#define PSD_MINTEFULL 1
#define PSD_MINTE 2
#define PSD_FWINPHS 3
#define PSD_FWOUTPHS 4
#define PSD_MAXTE 5

/* Fat/Water in Phase Range Limits */
#define PSD_LLIMTEIN1  4.2ms
#define PSD_ULIMTEIN1  6.0ms
#define PSD_LLIMTEIN2  8.5ms
#define PSD_ULIMTEIN2  10.0ms
#define PSD_LLIMTEIN3  13.0ms
#define PSD_ULIMTEIN3  TE_MAX

/* Fat/Water out of Phase Range Limits */
#define PSD_LLIMTEOUT1  1.8ms
#define PSD_ULIMTEOUT1  2.8ms
#define PSD_LLIMTEOUT2  6.3ms
#define PSD_ULIMTEOUT2  7.3ms
#define PSD_LLIMTEOUT3  10.8ms
#define PSD_ULIMTEOUT3  12.0ms

/* ************************************************
   CV Processing, Predownload, and RSP
   Initialization Routines

   Structures and Constants 
   
* ************************************************ */
/* Number of entries in data acq table */
#define DATA_ACQ_MAX 512
#define TRIG_ROT_MAX 2*DATA_ACQ_MAX /* double to accomodate graphic sat */
#define PRESCAN_ROT_MAX 1           /* MRIge43968: only one for Prescan */ 
/* Number of entries in scan info table */
#define SLTAB_MAX 256

/* Misc. constants */
#define TARDIS_FREQ_RES 0.59604648
#define RCV_FREQ_TARDIS 187500 /* receiver frequency for Tardis */
#define RCV_FREQ_CERD 125000   /* receiver frequency for CERD */
#define RCV_FREQ_FAST 0   /* receiver frequency offset for fast rcvr */

/* Acquisition Types */
#define TYPSPIN 0   /* Spin Echo */
#define TYPGRAD 1   /* Gradient Recalled */

/* Define Types */
#define TYPNDEF 0   /* Don't caculate */
#define TYPDEF 1    /* Calculate */

/* Sequence  Types */
#define TYPNCAT      0   /* Normal, Non CATSAT */
#define TYPCAT       1   /* CATSAT */
#define TYPXRR       2   /* Cross R-R Imaging */
#define TYPMPMP      3   /* Multiphase multiplanar cardiac */
#define TYPSSMP      4   /* Single Slice Multiphase */
#define TYP3D        5   /* Volume scanning */
#define TYPNORMORDER 6   /* Straight physical order for slices */
#define TYPFASTMPH   7   /* for FGRE MPH slice ordering */
#define TYPF3D       8   /* Fast Volume Scanning */
#define TYP3DMSNCAT  9   /* 3D Multislab non-concat */
#define TYP3DMSCAT  10   /* 3D Multislab concat */
#define TYP3DFSENCAT 11   /* 3D Fast Spin Echo non-concat */
#define TYP3DFSECAT  12   /* 3D Fast Spin Echo concat */
#define TYPRTG       13   /* Respiratory Trigger */
#define TYPF3DMPH       14   /* Fast, Multi-phase 3D */
#define TYPSSFSEINT  15   /* Interleaved slice acq. in ssfse */
#define TYPSSFSESEQ  16   /* Sequential slice acq. in ssfse */
#define TYPSSFSEXRR  17   /* XRR for ssfse */
#define TYPSSFSERTG  18   /* RTG for ssfse */
#define TYPSEQSLIC   19   /* Sequential Slice Ordering */
#define TYPF3DMSMPH  20   /* 3D Multislab Multiphase - added by latha@mr for 3d oblique */

/* Flow Comp Type */
#define TYPNFC 0    /* No Flow Comp */  
#define TYPFC 1     /* Flow Comp */

/* Echo Type */
#define TYPNVEMP 0     /* Normal */
#define TYPVEMP  1     /* VEMP sequence */

/* Resp Comp Type */
#define TYPNORM   0  /* Normal phase ordering */
#define TYPLSORT  1  /* Low Sort Exorcist */
#define TYPHSORT  2  /* High Sort Exorcist */
#define TYPAHSORT 3  /* Average High Sort */

/* Frequency generation type */
#define TYPTRANSMIT   0  /* Generate Transmit frequencies */
#define TYPREC        1  /* Receive frequency */
#define TYPRECGRDEVEN 2  /* Gradient Recall Even echo freq */
/*  following sentences are 5.5 changes. YH 10/14/94 */
#define TYPFASTREC        3 /* Receive frequency - research
                               fast recvr */
#define TYPFASTRECGRDEVEN 4 /* Gradient Recall Even echo freq - research
                                                          fast recvr */

/* Crusher Generation types */
#define PSD_TYPCMEMP 0
#define PSD_TYPCCSMEMP 1
#define PSD_TYPCFCMEMP 2
#define PSD_TYPCPOMP 3
#define PSD_TYPCFCPOMP 4


/* Chopping Codes */
#define CHOP_BL 0    /* Chopper state: chop only baselines (<1NEX) */
#define CHOP_ALL 1   /* Chopper state: chop all views (>1NEX) */
#define CHOP_NONE 2  /* Chopper state: chop nothing */

/* Entry Point Labels */
#define L_CFL 0
#define L_CFH 1
#define L_MPS1 2
#define L_MPS2 3
#define L_APS1 4
#define L_APS2 5
#define L_SCAN 6
/*#define L_TEST 7 */
#define L_FTG 7   /* merged 55 bch into vmx. YH 10/14/94 */
#define L_AUTOSHIM 8
#define L_TEST 9  /* merged 55 bch into vmx. YH 10/14/94 */

/* Autoshim constants */
#define PSD_AUS_ON 65536
#define PSD_AUS_HAS 131072

/* Dab Operations */
#define DABSTORE 0    /* DAB operation to store xcvr data */
#define DABADD 1     /* DAB operation to accumulate data */
#define DABSUBCNTS 2  /* DAB operation to subtract contents from xcvr data */
#define DABSUBXCVR 3   /* DAB operation to subtract xcvr data from contents */

/* Recon Types */
#define RHTYPCHP 1       /* For setting Chop bit in rhtyp */
#define RHTYPCINE  2
#define RHTYPSHIM  4
#define RHTYPGR    8
#define RHTYPFRACTNEX  16
#define RHTYPSTRIP    32
#define RHTYP3D    64
#define RHTYPXOR  128
#define RHTYPNPW   256
#define RHTYPNFW  512
#define RHTYPSPIRAL 1024
#define RHTYPFRACTECHO 2048
#define RHTYP75NEX  8192
#define RHTYPPOMP  16384   /* For setting POMP bit in rhtype */
#define RHTYPTURBO  32768	/* For setting turbo bit in rhtype */

/* More recon types, used in rhtype1 */
#define RHTYP3DM 16     /* 3D multi-slab */
#define RHTYPMAXOVL 32 /* maximum intensity pixel collapse overlap processing */
#define RHTYPMINOVL 64 /* minimum intensity pixel collapse overlap processing */
#define RHTYPAVEOVL 96  /* average intensity pixel collapse overlap processing */
/* *****************************
   Defines for rhrcctrl
   ***************************** */
#define RHRCMAG   1     /* magnitude images   */
#define RHRCPHS   2     /* phase images       */
#define RHRCIMAG  4     /* I magnitude images */
#define RHRCQMAG  8     /* Q magnitude images */
#define RHRCCOMP  16    /* compressed images  */
#define RHRCRAW   128   /* raw image recon */

/* *****************************
   Defines for rhdacqctrl
   ***************************** */
#define RH_FCINE_ET               1024 /* fcine Echotrain data acq. */
#define RH_PASS_THROUGH_CERD_FLAG 2048 /* passthrough data acq. */

/* Power Monitor Scale Factors */
#define PMFULL 255       /* Full scale power monitor.
			    Power monitor values are scaled to this */
#define PMFSPWH 12750    /* Full scale PW in ms. in head coil */
#define PMFSPWB 12750    /* Full scale PW in ms. in body coil */
#define PMFSDCH 0.255    /* Full scale duty cycle in % for head */
#define PMFSDCB 0.255    /* Full scale duty cycle in % for body */
#define PMFSRFH 3300.0   /* Full scale RF power in watts for head */
#define PMFSRFB 22000.0  /* Full scale RF power in watts for body */
#define PMFSRFS 275.0    /* Full scale RF power in watts for surf. */

/* We don't include value for surf. because it is run off the head port.
   Also there isn't any output on RF power amp for surface coil */

#define PMFSPWH_1P5 12750    /* Full scale PW in us. in head coil */
#define PMFSPWB_1P5 12750    /* Full scale PW in us. in body coil */
#define PMFSDCH_1P5 0.255    /* Full scale duty cycle in % for head */
#define PMFSDCB_1P5 0.255    /* Full scale duty cycle in % for body */
#define PMFSRFH_1P5 3300.0   /* Full scale RF power in watts for head */
#define PMFSRFB_1P5 22000.0  /* Full scale RF power in watts for body */

#define PMFSPWH_1P0 30000    /* Full scale PW in us. in head coil */
#define PMFSPWB_1P0 30000    /* Full scale PW in us. in body coil */
#define PMFSDCH_1P0 0.255    /* Full scale duty cycle in % for head */
#define PMFSDCB_1P0 0.255    /* Full scale duty cycle in % for body */
#define PMFSRFH_1P0 1000.0   /* Full scale RF power in watts for head */
#define PMFSRFB_1P0 10000.0  /* Full scale RF power in watts for body */

#define PMFSPWH_0P5 60000    /* Full scale PW in us. in head coil */
#define PMFSPWB_0P5 60000    /* Full scale PW in us. in body coil */
#define PMFSDCH_0P5 0.255    /* Full scale duty cycle in % for head */
#define PMFSDCB_0P5 0.255    /* Full scale duty cycle in % for body */
#define PMFSRFH_0P5 500.0    /* Full scale RF power in watts for head */
#define PMFSRFB_0P5 5000.0   /* Full scale RF power in watts for body */

 /* 
   GRAD_PULSE structure is used by a variety of support routines, as
   a convenient method of passing pulse object parameters.  The PSD
   must keep track of the type and quantity of grad pulses used.
  */  /* merged 55 bch into vmx. YH 10/14/94 */
/* 3/13/95 YI changed for new system safety */

typedef struct {
  int ptype;      /* gradient Type (e.g. ramp, constant, trapezoid, etc.) */
  int *attack;    /* pulse width of attack for trapezoidal pulses */
  int *decay;     /* pulse width of decay for trapezoidal pulses */
  int *pw;        /* pulse width (if trapezoidal, pulse width of center
                                         section) */
  float *amps;    /* starting amplitude of a trapezoidal pulse */
  float *amp;     /* amplitude (if trapezoidal, amplitude of ramp and left
                                         side of flat top) */
  float *ampd;    /* starting amplitude of decay ramp and right side amplitude
                                         of flat top for trapezoidal pulse */
  float *ampe;    /* ending amplitude of a trapezoidal pulse */
  /* old location of "float power" field  */
  char *gradfile; /* external grad filename */
  int num;        /* quantity of this gradpulse used */
  float scale;    /* gradient heating scale factor (e.g. phase encoding) */
  /* time and tdelta are for future use: */
  int *time;      /* location of pulse in time */
  int tdelta;     /* Time delta in microseconds in between multiple occurances
                                         of the pulse */
  float powscale; /* gradient driver current scale factor
                                     (<x,y,z>fs/target)      */
  /* For internal pulses, the function minseqgrddrv computes and fills in the
         following fields. They are NOT scaled by the powscale field.
         For external pulses, the programmer must fill these in with the 
         appropriate pulse properties. Note: for external pulses, the values
         must be normalized by the pulse width and the square of the 
         amplitude.                                          */
  float power;    /* total power in units of Ampere^2 usec   */
  float powpos;   /* positive power in units of Ampere^2 usec  */
  float powneg;   /* negative power in units of Ampere^2 usec  */
  float powabs;   /* absolute power in units of Ampere usec    */
  float amptran;  /* ampere transitions in units of Ampere     */
  int pwm;      /* pulse width modulation time               */
  int bridge;     /* bridge flag: 1 -- left or right crusher; 
                                  2 -- 180 slice select; 
                                  0 -- no bridge.   */ 
  float intabspwmcurr; /* Integral of the absolute value of the
                          current during the ramps. This is used for
                          gradient heating with SGD */
} GRAD_PULSE;   /* merged 55 bch into vmx. YH 10/14/94 */

typedef char EXTERN_FILENAME[80];
typedef char *EXTERN_FILENAME2;
/*
  Constants below are used above for the field ptype
*/

#define G_RAMP 1
#define G_TRAP 2
#define G_SIN  3      /* Half sin , 0 offset */
#define G_CONSTANT 4
/*#define G_SINPHASE 5 */ /* Phase encoding sin wave 
		        (varying amplitude ) */
#define G_ARBTRAP 5 /* Trapezoid with arbitrary start and
                       ending amplitudes and a possible
                       slope to the middle portion of the waveform */
#define G_USER 6     /* User defined.  Use power field. */
#define G_EMPTY -1   /* instructs CV routine to ignore this struct */

/* merged 55 bch into vmx. changed from 25 to 50. YH 10/14/94 */
#define MAX_GRADX_NUM 50 
#define MAX_GRADY_NUM 50
#define MAX_GRADZ_NUM 50
#define MAX_RFPULSE_NUM 50

/* 
  Structure RF_PULSE is used by the rf amplifier heating calcs
  and SAR calcs.  PSD keeps track of the type and quantity of 
  RF pulses used.

  isodelay structure tag is now provided and is intended to
  replace usage of the off90 CV.  It is the time from the zero
  phase reference of the pulse (where gradient phase bookkeeping begins)
  to its end.
  */

/* 3/13/95 YI  changed for new system safety */

typedef struct {
  int *pw;        /* pulse width */
  float *amp;     /* amplitude */
  float abswidth; /* calculated RF absolute width */
  float effwidth; /* calculated RF effective width */
  float area;     /* zero momemt of pulse */ 
  float dtycyc;   /* max % of pulse width above 23% and in any 1  lobe */
  float maxpw;    /* max % of time rf pulse is above 0 amp */
  int num;        /* quantity of this type of RF pulse */
  float max_b1;   /* peak B1 in G under standard conditions */
  float max_int_b1_sq;   /* peak integral B1^2 in GG-msec under standard conditions */
  float max_rms_b1;      /* peak RMS B1 in G under standard conditions */ 
  float nom_fa;   /* flip angle on resonance under standard conditions. */
  float *act_fa;  /* desired flip angle */
  float nom_pw;   /* pulse duration under standard conditions */
  float nom_bw;   /* pulse bandwidth under standard conditions */
  unsigned int activity; /* bitmask showing when pulse is used */
  unsigned char reference; /* flag for pulse used in TG setting */
  int   isodelay; /* time in usec from the zero phase reference of pulse
				     to its end*/
  float scale;    /* duty cycle scale factor */
  int *res; /* pulse resolution *//* vmx 3/13/95 YI changed from short to int */
  int extgradfile; /* TRUE = rfpulse uses external gradient waveform file */
} RF_PULSE;

/* 3/13/95 YI  added for new system safety */

/*********************************************************************
 * Structure RF_PULSE_INFO is used by HOST and IPG to track rf pulse
 * scaling and resolution when large patients cause system safety
 * violations. See 5.5 PSD SYSTEM SAFETY SDD for more specific explanation.
 * The structure is defined in @ipgexports, initialized in HOST by
 * scalerfpulses(), and used by IPG in pulsegen to scale rfpulses using
 * linear interpolation in stretchpulse() routine.
 *********************************************************************/
typedef struct {
  int  change;  /* PSD_ON: rfpulse scaling required, PSD_OFF: no scaling required */
  int  newres;  /* scaled resolution of rfpulse if maxB1 of rf amplifier violated */
} RF_PULSE_INFO;


/* Pulse activity masks */
#define PULSE_OFF 0
#define CFL_ON 1
#define CFL_HAD 2
#define CFH_ON 4
#define CFH_HAD 8
#define MPS1_ON 16
#define MPS1_HAD 32
#define MPS2_ON 64
#define MPS2_HAD 128
#define APS1_ON 256
#define APS1_HAD 512
#define APS2_ON 1024
#define APS2_HAD 2048
#define SCAN_ON 4096
#define SCAN_HAD 8192
/*#define TEST_ON 16384
#define TEST_HAD 32768*/
#define FTG_ON  16384  /* merged 55 bch into vmx. YH 10/14/94 */
#define FTG_HAD 32768
#define AUS_ON 65536
#define AUS_HAD 131072
#define TEST_ON 262144
#define TEST_HAD 524288 /* end of 5.5 changes. */

/* Flow comp axis codes */
#define XGRADFC 1
#define ZGRADFC 2

/* Ramp pulse directions */
#define PSD_POSRAMP 1
#define PSD_NORAMP 0
#define PSD_NEGRAMP -1

/* constants for TRAPEZOID2 macro */
#define TRAP_RAMPA 1
#define TRAP_CONST 2
#define TRAP_RAMPD 4
#define TRAP_SLOPED 8
#define TRAP_ALL 7
#define TRAP_ALL_SLOPED 15
/* Ratio of trapezoidal phase encoding flattop amplitudes.
   Equalt to 1.0 - 64.0/max_pg_wamp */
#define PSDRAMPEDTRAP 0.998047

#define PHASESTEP32 32

/* constants for slice quantity */
#define PSD_SLQUANT8 8
#define PSD_SLQUANT16 16
#define PSD_SLQUANT32 32
#define PSD_SLQUANT64 64
 
/* Default number of filter prefills */
#define DEFPREFILLS 129
 
/* constants for slice quantity */
#define PSD_SLQUANT8 8
#define PSD_SLQUANT16 16
#define PSD_SLQUANT32 32
#define PSD_SLQUANT64 64
 
/* opbloptimize defines */
#define PSD_OBL_RESTRICT 0
#define PSD_OBL_OPTIMAL 1

/* echo planar constants ***************************//* 3/13/95 YI */

/* k-space trajectory constants */
/* These indicate sense (or direction) only */
#define PSD_TOP_DOWN 0    /* top-to-bottom */
#define PSD_CENTER_OUT 1  /* center-to-top/center-to-bottom */
#define PSD_BOTTOM_UP 2   /* bottom-to-top */

/* ky fraction constants */
#define PSD_FULL_KY 0
#define PSD_FRACT_KY 1

/* alternation factor constants */
#define PSD_ALT_NONE 0
#define PSD_ALT_ODD_EVEN 1
#define PSD_ALT_HALVES 2
#define PSD_ALT_SUBGROUPS 3
/* end echo planar constants ***************************/
 
/* GRAM IDENTIFIERS */
#define PSD_NOGRAM      0
#define PSD_GRAM1       1
#define PSD_GRAM2       2
 
/* SR modes */
#define PSD_SR17	17	
#define PSD_SR20	20	
#define PSD_SR77	77	
#define PSD_SR120	120	
#define PSD_SR150	150	
#define PSD_SR230	230	

/* SR amplitude factors  - used to scale loggrd structure */
#define SR17_FACTOR     0.95
#define SR20_FACTOR     1.0
#define SR77_FACTOR     1.0
#define SR120_FACTOR    1.0
#define SR230_FACTOR    1.0

/* Gradient Coil Specifiers */
#define PSD_55_CM_COIL 1
#define PSD_60_CM_COIL 2  /* BRM */
#define PSD_CRM_COIL 6  

 /* bit map of GRAM axis for sigrammode  *//* 3/13/95 YI */
#define XGRAM 1  /* X GRAM */
#define YGRAM 2  /* Y GRAM */
#define ZGRAM 4  /* Z GRAM */

/*
  Structure to contain slice ordering within the pass
  and the pass number.
  */
  
typedef struct {
  short slloc;  /* prescribed location */
  short slpass; /* pass phase is acquired in */
  short sltime; /* time order within pass slice is acquired */
} DATA_ACQ_ORDER;

/*
  Structure to record each slice's loacation,  receive offset 
  location, and rotation matrix.
  */

typedef struct {
  float optloc; /* distance in mm from isocenter */
  float oprloc; /* distance in mm from receive center */
  float opphasoff; /* distance in mm from isocenter in the phase direction*/
  short  oprot[10]; /* rotation matrix */
  } SCAN_INFO;

typedef struct {
  float rsptloc;   /* location in mm from isocenter */
  float rsprloc;   /* receive location in mm */
  float rspphasoff; /*distance in mm from isocenter in the phase direction*/
  int slloc;       /* prescribed location */
 } RSP_INFO;

/*
  Structure to record entry point specific enformation for the power
  monitor and receiver/exciter setup
  */

typedef struct{
  s8     epname[16];		/* name that entry point will be named */

  n8            epamph;		/* power for the head coil*/
  n8            epampb;		/* power for the body coil*/
  n8            epamps;		/* peak power for the surface coil */ 
  n8            epwidthh;	/* max pulse width for the head coil */

  n8            epwidthb;	/* max pulse width for the body coil */
  n8            epwidths;	/* max pulse width for the surface coil */ 
  n8            epdcycleh;	/* peak duty cycle for the head coil */
  n8            epdcycleb;	/* peak duty cycle for the body coil */

  n8            epdcycles;	/* peak duty cycle for the surface coil */
  n8            epsmode;	/* select exciter mode */
  n8            epfilter;	/* initial filter to use */
  n8            eprcvrband;	/* tells whether broadband is used */

  n8            eprcvrinput;	/* receiver port to use */
  n8            eprcvrbias;	/* receiver to bias */
  n8            eptrdriver;	/* tr driver control */
  n8            epfastrec;     /*  type of recevier 0=standard, 1=fast */

  s16 epxmtadd;		/* additional transmit gain to add */
  s16 epprexres;		/* prescan xres */  
  s16 epshldctrl;		/* expansion for shield cooler control */
  s16 epgradcoil;		/* indicate gradient shield mode */
  n32 eppkpower;                /* peak power */
  n32 epseqtime;                /* seq time */
  s16 epstartrec;               /* start receiver */ /* merged 55 bch into vmx. */
  s16 ependrec;                 /* end receiver */   /* YH 10/14/94             */
} ENTRY_POINT_TABLE;

/*
  Structure below is used for filters
*/

typedef struct { 
  int decimation;      /* Input decimation ratio after CERD processing */
  int tdaq;            /* time for data acquisition in microseconds */
  float bw;            /* bandwidth in KHz */
  int fname;           /* filter filename e.g 160 for filter.160 */
  int fslot;           /* filter slot for permanemt filters */
  float output_dec;    /* Final decimation after SINC interpolation */
  float cerd_tsp;      /* Sampling period in usec after CERD decimation*/
  int cerd_out_points; /* Number of points to acquire, i.e, number of CERD
                          output points */
  int fracdec;         /* Flag indicating whether fractional decimation is
                          being used for the current acquisition */
  } FILTER_INFO;

/* phase offset structure and vars.  Prior to release 5.5, this
   was declared in each individual psd */
/*  array to store calculated phase offset and sign */
typedef struct {
        int ysign;  /* sign of the phase offset */
        int yoffs;  /* calculated phase offset from rsp_info structure */
        } PHASE_OFF;

@pulsedef

/* changed cvs from shorts to ints *//* changed for 5.5. YH 10/13/94 */
ACQUIREDATA(acq_name, acq_pos, dab_pos:DEFAULTPOS, xtr_pos:DEFAULTPOS,
                  acq_recvfilter:1, acq_recvnum:0, acq_dabtype:DABNORM,
                  acq_prefills:DEFPREFILLS){
cv:{
  int filter_$[acq_name];
  int rcvr_$[acq_name];
  int prefill_$[acq_name];
}
insert: cvinit =>{
  filter_$[acq_name] = $[acq_recvfilter];
  rcvr_$[acq_name] = $[acq_recvnum];
  prefill_$[acq_name] = DEFPREFILLS;
}
insert: predownload => {
}
var:{
  WF_PULSE $[acq_name] = INITPULSE;
}    
subst:{
  {
    pulsename(&$[acq_name],"$[acq_name]");
    acqq(&$[acq_name], (long)($[acq_pos]),(long)($[dab_pos]),
        (long)($[xtr_pos]),(long)filter_$[acq_name],
        (long)rcvr_$[acq_name],
        (TYPDAB_PACKETS)$[acq_dabtype], (long)$[acq_prefills]);
  }
}
}

ATTENUATOR(atten_name, atten_pos){
var:{
  WF_PULSE $[atten_name] = INITPULSE;
}
subst:{
  {
  pulsename(&$[atten_name],"$[atten_name]");
  createatten(&$[atten_name], (long)($[atten_pos]));
}
}
}

CONST(cnst_wgname,cnst_name,cnst_pos,cnst_dur,cnst_amp,cnst_loggrd) {
cv:{
  float a_$[cnst_name];
  int ia_$[cnst_name];
  int pw_$[cnst_name];
}
insert:  cvinit => {
  a_$[cnst_name] = $[cnst_amp];
  pw_$[cnst_name] = $[cnst_dur];
}
var:{
  WF_PULSE $[cnst_name] = INITPULSE;
}
insert: predownload => {
{
  float target;
  gettarget(&target, $[cnst_wgname], &$[cnst_loggrd]);
  ia_$[cnst_name] = (a_$[cnst_name] / target) * MAX_PG_IAMP;
}
}
subst:{
  {
    pulsename(&$[cnst_name],"$[cnst_name]");
    createconst(&$[cnst_name],$[cnst_wgname],pw_$[cnst_name],MAX_PG_WAMP);
    createinstr( &$[cnst_name],(long)($[cnst_pos]),
		pw_$[cnst_name],ia_$[cnst_name]);
    if (($[cnst_wgname]==TYPRHO1)||($[cnst_wgname]==TYPRHO2))
      {
	addrfbits(&$[cnst_name],0,(long)($[cnst_pos]),pw_$[cnst_name]);
      }
  }
}
}

/* merged 5.5 bch into vmx. YH 10/13/94 */
EFFSLICESELZ(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
                 slsel_cycles:1.0,slsel_usegrad:1,
                         res_gz,extern_grad_file, slsel_userf:1, res_rf,
                 extern_rf_file, slsel_usetheta:0, slsel_define:1,
                         slsel_loggrd, slsel_tune:0){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
  float a_theta$[slsel_name];
  int ia_theta$[slsel_name];
  int pw_theta$[slsel_name];
  int res_theta$[slsel_name];
  int off_theta$[slsel_name] = 0;
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
  a_theta$[slsel_name] = 0;
  res_theta$[slsel_name] = $[res_gz];
  pw_theta$[slsel_name] = $[slsel_dur];
}
insert: predownload => {
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],
              $[slsel_loggrd].tz, $[slsel_loggrd].zrt, $[slsel_define]) == FAILURE)
        return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],
              $[slsel_loggrd].tz, $[slsel_loggrd].zft, $[slsel_define]) == FAILURE)
        return FAILURE;
  ia_gz$[slsel_name] = a_gz$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * max_pg_iamp;
  ia_theta$[slsel_name] = a_theta$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz ;
}
var:{
  EXTERN_FILENAME2 grad_z$[slsel_name];
  EXTERN_FILENAME2 rf_$[slsel_name] ;
  EXTERN_FILENAME2 theta_$[slsel_name];
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
  WF_PULSE theta$[slsel_name]  = INITPULSE;
}
subst:{
  {
   /* Select proper filename */
   grad_z$[slsel_name]=  $[extern_grad_file];
   rf_$[slsel_name] =  $[extern_rf_file];
   theta_$[slsel_name] = $[extern_grad_file];
    /* Now create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    pulsename(&theta$[slsel_name], "theta$[slsel_name]");
    /*  Now create the slice select trapezoid */
        pg_beta = $[slsel_loggrd].zbeta;
    if ( $[slsel_usegrad] == PLAY_GFILE)
        createextwave(&gz$[slsel_name],ZGRAD,
                res_gz$[slsel_name],grad_z$[slsel_name]);
    else {
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               max_pg_wamp,(short)(maxGradRes*(pw_gz$[slsel_name]a/
 
   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
        createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],max_pg_wamp);
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,max_pg_wamp,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/

GRAD_UPDATE_TIME)),pg_beta);                                     
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
                pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
      }
    createinstr( &gz$[slsel_name],(long)$[slsel_pos],
                pw_gz$[slsel_name],ia_gz$[slsel_name]);
    /* Now create the rf pulse */
    if ( $[slsel_userf] == PLAY_RFFILE)
     createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    else
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
               max_pg_wamp,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune],  pw_$[slsel_name],ia_$[slsel_name]);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)$[slsel_pos]
                          + psd_rf_wait + $[slsel_tune], pw_$[slsel_name]);
    /* Now create the theta pulse */
    if ( $[slsel_usetheta] == PLAY_THETA) {
    createextwave(&theta$[slsel_name],TYPOMEGA,
            res_theta$[slsel_name],theta_$[slsel_name]);
    createinstr( &theta$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune],  pw_theta$[slsel_name],ia_theta$[slsel_name]);
    addrfbits(&theta$[slsel_name],off_theta$[slsel_name],(long)$[slsel_pos]
              + psd_rf_wait + $[slsel_tune], pw_theta$[slsel_name]);
  }
    if ( $[slsel_usegrad] == PLAY_GFILE)
    linkpulses(3, &$[slsel_name], &gz$[slsel_name], &theta$[slsel_name]);
    else
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
                           &gz$[slsel_name]d);
}
}
}


/*
 *  EFFSLICESELZ_SPSP
 *  
 *  Type: Macro
 *  
 *  Description:
 *    This macro is based on EFFSLICESELZ and allows the user to
 *    create an EchoTrain on the Host side using a sequence of
 *    trapezoids.  On the IPG side, it will read an external file.
 */
EFFSLICESELZ_SPSP( slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
                   slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
                   slsel_userf:1, res_rf, extern_rf_file, slsel_usetheta:0,
                   slsel_define:1, slsel_loggrd, slsel_tune:0 )
{
cv:{
    float a_gz$[slsel_name];
    int ia_gz$[slsel_name];
    int pw_gz$[slsel_name]a;
    int pw_gz$[slsel_name]d;
    int pw_gz$[slsel_name];
    int res_gz$[slsel_name];
    float a_$[slsel_name];
    int ia_$[slsel_name];
    int pw_$[slsel_name];
    int res_$[slsel_name];
    float cyc_$[slsel_name];
    int off_$[slsel_name] = 0;
    float alpha_$[slsel_name] = 0.46;
    float thk_$[slsel_name];
    float gscale_$[slsel_name] = 1.0;
    float flip_$[slsel_name];
    float a_theta$[slsel_name];
    int ia_theta$[slsel_name];
    int pw_theta$[slsel_name];
    int res_theta$[slsel_name];
    int off_theta$[slsel_name] = 0;
}
insert: cvinit =>{
    flip_$[slsel_name] = $[slsel_flip];
    a_$[slsel_name] = flip_$[slsel_name]/180;
    pw_gz$[slsel_name] = $[slsel_dur];
    res_gz$[slsel_name] = $[res_gz];
    res_$[slsel_name] = $[res_rf];
    pw_$[slsel_name] = $[slsel_dur];
    cyc_$[slsel_name] = $[slsel_cycles];
    thk_$[slsel_name] = $[slsel_thk];
    a_theta$[slsel_name] = 0;
    res_theta$[slsel_name] = $[res_gz];
    pw_theta$[slsel_name] = $[slsel_dur];
}
insert: predownload => {

    if (optramp( &pw_gz$[slsel_name]a,a_gz$[slsel_name],
                 $[slsel_loggrd].tz, $[slsel_loggrd].zrt, 
                 $[slsel_define] ) == FAILURE) {
        return FAILURE;
    }

    if (optramp( &pw_gz$[slsel_name]d,a_gz$[slsel_name],
                 $[slsel_loggrd].tz, $[slsel_loggrd].zft, 
                 $[slsel_define] ) == FAILURE) {
        return FAILURE;
    }

    ia_gz$[slsel_name] = a_gz$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz;

    ia_$[slsel_name] = a_$[slsel_name] * max_pg_iamp;

    ia_theta$[slsel_name] = a_theta$[slsel_name] * max_pg_iamp / $[slsel_loggrd].tz ;

}

var:{
    EXTERN_FILENAME2 grad_z$[slsel_name];
    EXTERN_FILENAME2 rf_$[slsel_name] ;
    EXTERN_FILENAME2 theta_$[slsel_name];
    WF_PULSE gz$[slsel_name]a = INITPULSE;
    WF_PULSE gz$[slsel_name]  = INITPULSE;
    WF_PULSE gz$[slsel_name]d = INITPULSE;
    WF_PULSE $[slsel_name] = INITPULSE;
    WF_PULSE theta$[slsel_name]  = INITPULSE;
}

subst:{
  {
      /* Select proper filename */
      grad_z$[slsel_name]=  $[extern_grad_file];
      rf_$[slsel_name] =  $[extern_rf_file];
      theta_$[slsel_name] = $[extern_grad_file];

      /* Now create the pulses */
      pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
      pulsename(&gz$[slsel_name],"gz$[slsel_name]");
      pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
      pulsename(&$[slsel_name],"$[slsel_name]");
      pulsename(&theta$[slsel_name], "theta$[slsel_name]");

      /*  Now create the slice select trapezoid */
      pg_beta = $[slsel_loggrd].zbeta;

      if ( $[slsel_usegrad] == PLAY_GFILE) {

#ifdef IPG 
          /* Use external gradient file for now */
          createextwave( &gz$[slsel_name], ZGRAD, res_gz$[slsel_name],
                         grad_z$[slsel_name] );
#else /* !IPG */
          /* Create train of trapezoids on the Host side */
          int i;
          int polarity = 1;
       
          pulsepos = $[slsel_pos]; 
       
          for(i = 1; i <= num_rf1lobe; i++) {
              polarity *= -1;

              trapezoid( ZGRAD,"gz$[slsel_name]", &gz$[slsel_name], 
                         &gz$[slsel_name]a, &gz$[slsel_name]d,
                         pw_constant, pw_ss_rampz, pw_ss_rampz, 
                         (polarity*(ia_gz$[slsel_name])),
                         (polarity*(ia_gz$[slsel_name])),
                         (polarity*(ia_gz$[slsel_name])), 0, 0, 
                         pulsepos, TRAP_ALL, &$[slsel_loggrd] );

              pulsepos += pw_constant + 2 * pw_ss_rampz;
          }
#endif /* IPG */

      } else {

          /* Create simple trapezoid for chem sat + rf */
          createramp( &gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,
                      (short)0, max_pg_wamp,
                      (short)(maxGradRes *
                              (pw_gz$[slsel_name]a / GRAD_UPDATE_TIME)),
                      pg_beta );

          createinstr( &gz$[slsel_name]a,
                       (long)($[slsel_pos] - pw_gz$[slsel_name]a),
                       pw_gz$[slsel_name]a, ia_gz$[slsel_name] );

          createconst( &gz$[slsel_name], ZGRAD, pw_$[slsel_name], max_pg_wamp );

          createramp( &gz$[slsel_name]d, ZGRAD, pw_gz$[slsel_name]d,
                      max_pg_wamp, (short)0,
                      (short)(maxGradRes *
                              (pw_gz$[slsel_name]d / GRAD_UPDATE_TIME)),
                      pg_beta );
          createinstr( &gz$[slsel_name]d,
                       (long)($[slsel_pos] + pw_gz$[slsel_name]),
                       pw_gz$[slsel_name]d, ia_gz$[slsel_name] );

      }

#ifdef IPG 
      createinstr( &gz$[slsel_name], (long)$[slsel_pos],
                   pw_gz$[slsel_name], ia_gz$[slsel_name] );
#endif /* IPG */

      /* Now create the rf pulse */
      if ( $[slsel_userf] == PLAY_RFFILE) {
          createextwave( &$[slsel_name],TYPRHO1, res_$[slsel_name],
                         rf_$[slsel_name]);
      } else {
          createsinc( &$[slsel_name],TYPRHO1, res_$[slsel_name],
                      max_pg_wamp,cyc_$[slsel_name], alpha_$[slsel_name] );
      }

      createinstr( &$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                   $[slsel_tune],  pw_$[slsel_name],ia_$[slsel_name]);

      addrfbits( &$[slsel_name], off_$[slsel_name], (long)$[slsel_pos] +
                 psd_rf_wait + $[slsel_tune], pw_$[slsel_name] );

      /* Now create the theta pulse */
      if ( $[slsel_usetheta] == PLAY_THETA) {
          createextwave( &theta$[slsel_name], TYPOMEGA,
                         res_theta$[slsel_name], theta_$[slsel_name] );

          createinstr( &theta$[slsel_name], (long)$[slsel_pos] + psd_rf_wait +
                       $[slsel_tune], pw_theta$[slsel_name],
                       ia_theta$[slsel_name] );

          addrfbits( &theta$[slsel_name], off_theta$[slsel_name],
                     (long)$[slsel_pos] + psd_rf_wait + $[slsel_tune],
                     pw_theta$[slsel_name] );
      }
#ifdef IPG
      if ( $[slsel_usegrad] == PLAY_GFILE) {
          linkpulses( 3,
                      &$[slsel_name], &gz$[slsel_name], &theta$[slsel_name]);
      } else {
          linkpulses( 4,
                      &$[slsel_name], &gz$[slsel_name],
                      &gz$[slsel_name]a, &gz$[slsel_name]d);
      }
#endif /* IPG */
  }
}
}

/* merged 5.5 bch into vmx. YH 10/13/94 */
/* Possible EFFSLICESEL that does not care which axis it uses,
   this macro is not used presently but was added in case a non
   axis specific macro is desired in the future with this functionality   */
EFFSLICESEL( slsel_wgname, slsel_name, slsel_pos, slsel_dur, slsel_thk,
             slsel_flip,slsel_cycles:1.0,slsel_usegrad:1,
             res_g,extern_grad_file, slsel_userf:1, res_rf,
             extern_rf_file, slsel_usetheta:0, slsel_define:1,
             slsel_loggrd, slsel_tune:0 )
{
cv:{
  float a_g$[slsel_name];
  int ia_g$[slsel_name];
  int pw_g$[slsel_name]a;
  int pw_g$[slsel_name]d;
  int pw_g$[slsel_name];
  int res_g$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
  float a_theta$[slsel_name];
  int ia_theta$[slsel_name];
  int pw_theta$[slsel_name];
  int res_theta$[slsel_name];
  int off_theta$[slsel_name] = 0;
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_g$[slsel_name] = $[slsel_dur];
  res_g$[slsel_name] = $[res_g];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
  a_theta$[slsel_name] = 0;
  res_theta$[slsel_name] = $[res_g];
  pw_theta$[slsel_name] = $[slsel_dur];
}  
insert: predownload => {
{
  float target;
  int rise_time, fall_time;
 
  gettarget(&target, $[slsel_wgname],&$[slsel_loggrd]);
  getramptime(&rise_time, &fall_time, $[slsel_wgname],&$[slsel_loggrd]);

  if (optramp(&pw_g$[slsel_name]a,a_g$[slsel_name],                      
              target, rise_time, $[slsel_define]) == FAILURE)
        return FAILURE;
  if (optramp(&pw_g$[slsel_name]d,a_g$[slsel_name],
              target, fall_time, $[slsel_define]) == FAILURE)
        return FAILURE;
  ia_g$[slsel_name] = a_g$[slsel_name] * max_pg_iamp / target;
  ia_$[slsel_name] = a_$[slsel_name] * max_pg_iamp;
  ia_theta$[slsel_name] = a_theta$[slsel_name] * max_pg_iamp / target;
}
}
var:{
  EXTERN_FILENAME2 grad_$[slsel_name];
  EXTERN_FILENAME2 rf_$[slsel_name] ;
  EXTERN_FILENAME2 theta_$[slsel_name];
  WF_PULSE g$[slsel_name]a = INITPULSE;
  WF_PULSE g$[slsel_name]  = INITPULSE;
  WF_PULSE g$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
  WF_PULSE theta$[slsel_name]  = INITPULSE;
}
subst:{
  {

   /* Select proper filename */
   grad_$[slsel_name] =  $[extern_grad_file];
   rf_$[slsel_name] =  $[extern_rf_file];
   theta_$[slsel_name] = $[extern_grad_file];
 
    /* Now create the pulses */
    pulsename(&g$[slsel_name]a,"g$[slsel_name]a");
    pulsename(&g$[slsel_name],"g$[slsel_name]");
    pulsename(&g$[slsel_name]d,"g$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    pulsename(&theta$[slsel_name], "theta$[slsel_name]");
 
    /*  Now create the slice select trapezoid */
        getbeta(&pg_beta, $[slsel_wgname], &$[slsel_loggrd]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
        createextwave(&g$[slsel_name],$[slsel_wgname],
                res_g$[slsel_name],grad_$[slsel_name]);
    else {
    createramp(&g$[slsel_name]a,$[slsel_wgname],pw_g$[slsel_name]a,(short)0,
               max_pg_wamp,(short)(maxGradRes*(pw_g$[slsel_name]a/
                                                      GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]a,(long)($[slsel_pos]-pw_g$[slsel_name]a),
                pw_g$[slsel_name]a,ia_g$[slsel_name]);
        createconst(&g$[slsel_name],$[slsel_wgname], pw_$[slsel_name],max_pg_wamp);
    createramp(&g$[slsel_name]d,$[slsel_wgname],pw_g$[slsel_name]d,max_pg_wamp,
               (short)0,(short)(maxGradRes*(pw_g$[slsel_name]d/
                                                      GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]d,(long)($[slsel_pos]+pw_g$[slsel_name]),
                pw_g$[slsel_name]d,ia_g$[slsel_name]);
      }
    createinstr( &g$[slsel_name],(long)$[slsel_pos],
                pw_g$[slsel_name],ia_g$[slsel_name]);
 
    /* Now create the rf pulse */
    if ( $[slsel_userf] == PLAY_RFFILE)
     createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    else
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
               max_pg_wamp,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune], pw_$[slsel_name],ia_$[slsel_name]);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)$[slsel_pos]
                          + psd_rf_wait + $[slsel_tune], pw_$[slsel_name]);
 
    /* Now create the theta pulse */
    if ( $[slsel_usetheta] == PLAY_THETA) {
    createextwave(&theta$[slsel_name],TYPOMEGA,
            res_theta$[slsel_name],theta_$[slsel_name]);
    createinstr( &theta$[slsel_name],(long)$[slsel_pos] + psd_rf_wait +
                                $[slsel_tune],  pw_theta$[slsel_name],ia_theta$[slsel_name]);
    addrfbits(&theta$[slsel_name],off_theta$[slsel_name],(long)$[slsel_pos]
              + psd_rf_wait + $[slsel_tune], pw_theta$[slsel_name]);
  }
    if ( $[slsel_usegrad] == PLAY_GFILE)
    linkpulses(3, &$[slsel_name], &g$[slsel_name], &theta$[slsel_name]);
    else
    linkpulses(4,&$[slsel_name],&g$[slsel_name],&g$[slsel_name]a,
                           &g$[slsel_name]d);
}
}
}

/* merged 5.5 bch into vmx context.  YH  10/13/94 */
EP_TRAIN( et_pos:0, et_vps:1, et_offset:0, et_vtot,
           et_recvr_type:0, et_filt_slot:4, et_dab_type:0,
           et_dacqdelay:0, et_samp_period:1, et_dab_off:0,
                 et_xtr_off:0, et_acq_prefills:DEFPREFILLS, et_loggrd) {
 
/* EP_TRAIN generates a blipped echo planar sequence with
   optional readout crushers.  Readout is generated on logical XGRAD,
   blips on logical YGRAD.  Data acquisition is generated for standard
   or fast receivers, with control of DAB packet type.

   This macro can be called recursively.  Memory allocation is done once
   on the first interation of the macro (i.e. when et_offset is set to zero).
   The allocation is based on the value of et_vtot; the user is responsibile
   for setting this equal to the views-per-shot (et_vps) times the total
   number of iterations.  An offset argument is provided to allow explicit
   labeling of each Exciter/Receiver(/DAB) packet.

   Argument definitions:                           
   et_pos         -  absolute time position of first non-zero pulsewidth on X
   et_vps         -  views per shot (number of echoes macro generates)
   et_offset      -  numeric offset for view labeling, typically n*et_vps,
                     where n is the current iteration
   et_vtot        -  Total number of frames (for memory allocation).
                     Include number of views for all iterations
   et_recvr_type  -  0: standard receiver, 1: research fast receiver
   et_filt_slot   -  optional filter slot (0-7)
   et_dab_type    -  0: don't create a dab packet
                     1: create a standard dab (1ms prior to RBA),
   et_dacqdelay   -  delay of data acquisition relative to begin of gxw pulse
                     (after gxwl if non-zero) in usec
   et_samp_period -  sample period for fast receiver in usec
   et_dab_off     -  0: default position (1ms prior to RBA),
                     x: time position offset of xtr packet relative to RBA
   et_xtr_off     -  0: default position (100us prior to RBA),
                     x: time position offset of dab packet relative to RBA
   et_acq_prefills-  number of digital filter prefills (standard receiver)
   et_loggrd      -  logical gradient structure name
 
   Pulse attribute CVs are declared (see CV section below).

   The following pulse widths can be set to zero if desired:
   pw_gxcla, pw_gxcl, pwgxcld, pwgxwl, pwgxwr, pw_gxgap, pw_gxcra,
   pw_gxcr, pw_gxcrd.
 
   Combined Exciter/Receiver(/DAB) packets are labeled as echoxxxx (where
   xxxx ranges from 0000 to 9999).  This is useful for programming exciter
   phase and frequency on a per-view basis.
 
*/
 
cv:{
 
  float a_gxcl;
  float a_gxw;
  float a_gxcr;
  float a_gyb;
  int   ia_gxcl;
  int   ia_gxw;
  int   ia_gxcr;
  int   ia_gyb;
  int   pw_gxcla;
  int   pw_gxcl;
  int   pw_gxcld;
  int   pw_gxwl;
  int   pw_gxw;
  int   pw_gxwr;
  int   pw_gxwad;
  int   pw_gxgap;
  int   pw_gxcra;
  int   pw_gxcr;
  int   pw_gxcrd;
  int   pw_gyba;
  int   pw_gyb;
  int   pw_gybd;
 
}
var:{
 
  WF_PULSE gxcla = INITPULSE;
  WF_PULSE gxcl = INITPULSE;
  WF_PULSE gxcld = INITPULSE;
 
  WF_PULSE gxwa = INITPULSE;
  WF_PULSE gxw = INITPULSE;
  WF_PULSE gxwd = INITPULSE;
  WF_PULSE gxwde = INITPULSE;
  WF_PULSE gxcra = INITPULSE;
  WF_PULSE gxcr = INITPULSE;
  WF_PULSE gxcrd = INITPULSE;
 
  WF_PULSE gxgap = INITPULSE;
 
  WF_PULSE gyb = INITPULSE;
  WF_PULSE gyba = INITPULSE;
  WF_PULSE gybd = INITPULSE;
   
  WF_PULSE *echotrain;
 
}
 
insert: cvinit => {
}
 
insert: predownload => {
  ia_gxcl = a_gxcl * max_pg_wamp / $[et_loggrd].tx;
  ia_gxw = a_gxw * max_pg_wamp / $[et_loggrd].tx;
  ia_gxcr = a_gxcr * max_pg_wamp / $[et_loggrd].tx;
  ia_gyb = a_gyb * max_pg_iamp / $[et_loggrd].ty;
}
 
subst:{
    {
        int psd_gxwcnt;
        int psd_pulsepos;
        int psd_eparity;
        long psd_epxtroff;
        long psd_epdaboff;
        float psd_etbetax;
        float psd_etbetay;
        char psd_epstring[EPSTRING_LENGTH];

        psd_pulsepos = $[et_pos];           
 
        /* allocate on 1st pass only  */
        if ( $[et_offset] == 0 ) {
            echotrain = (WF_PULSE *)AllocNode(($[et_vtot] + 3) * sizeof(WF_PULSE));
        }
 
        pulsename(&gxcla, "gxcla");
        pulsename(&gxcl, "gxcl");
        pulsename(&gxcld, "gxcld");
 
        pulsename(&gxwa, "gxwa");
        pulsename(&gxw, "gxw");
        pulsename(&gxwd, "gxwd");
        pulsename(&gxwde, "gxwde");
 
        pulsename(&gxgap, "gxgap");
 
        pulsename(&gyba, "gyba");
        pulsename(&gyb, "gyb");
        pulsename(&gybd, "gybd");
 
        pulsename(&gxcra, "gxcra");
        pulsename(&gxcr, "gxcr");
        pulsename(&gxcrd, "gxcrd");
 
        getbeta(&psd_etbetax, XGRAD, &$[et_loggrd]);
        getbeta(&psd_etbetay, YGRAD, &$[et_loggrd]);
 
        if (pw_gxcla >= GRAD_UPDATE_TIME) {
            createramp(&gxcla, XGRAD, pw_gxcla, (short)0,
                       (short)ia_gxcl, (short)(maxGradRes*(pw_gxcla/
                                                           GRAD_UPDATE_TIME)), psd_etbetax);
            createinstr(&gxcla, (long)(psd_pulsepos),
                        pw_gxcla, max_pg_iamp);
            psd_pulsepos += pw_gxcla;
        }
    
        if (pw_gxcl >= GRAD_UPDATE_TIME) {
            createconst(&gxcl, XGRAD, pw_gxcl, max_pg_wamp);
            createinstr(&gxcl, (long)psd_pulsepos,
                        pw_gxcl, ia_gxcl);
            psd_pulsepos += pw_gxcl;
        }
    
        if (pw_gxcld >= GRAD_UPDATE_TIME) {
            createramp(&gxcld, XGRAD, pw_gxcld, (short)ia_gxcl,
                       (short)ia_gxw, (short)(maxGradRes*(pw_gxcld/
                                                          GRAD_UPDATE_TIME)), psd_etbetax);
            createinstr(&gxcld, (long)psd_pulsepos,
                        pw_gxcld, max_pg_iamp);
            psd_pulsepos += pw_gxcld;
        }
    
        createconst(&gxw, XGRAD, pw_gxwl+pw_gxw+pw_gxwr, max_pg_wamp);
        createinstr(&gxw, (long)psd_pulsepos,
                    pw_gxwl+pw_gxw+pw_gxwr, ia_gxw);
        psd_pulsepos += pw_gxwl;
    
        sprintf(psd_epstring, "echo%04d", $[et_offset]);
        pulsename(&(echotrain[$[et_offset]]), psd_epstring);
    
        if ($[et_dab_off] == 0)
            psd_epdaboff = 0;
        else
            psd_epdaboff = (long)(psd_pulsepos + $[et_dacqdelay] + $[et_dab_off]);            
        if ($[et_xtr_off] == 0)
            psd_epxtroff = 0;
        else
            psd_epxtroff = (long)(psd_pulsepos + $[et_dacqdelay] + $[et_xtr_off]);            
    
        epiacqq(&(echotrain[$[et_offset]]),
                (long)(psd_pulsepos + $[et_dacqdelay]),
                psd_epdaboff, psd_epxtroff,
                (long)$[et_filt_slot], (long)TYPRECVALL, (TYPDAB_PACKETS)DABNORM,
                (long)$[et_acq_prefills],(long)$[et_recvr_type],
                (long)$[et_dab_type]);
    
        psd_pulsepos += pw_gxw + pw_gxwr;      
    
        psd_eparity = 1;
        for (psd_gxwcnt = 2; psd_gxwcnt <= $[et_vps]; psd_gxwcnt++) {
            psd_eparity *= -1;
        
            createramp(&gyba, YGRAD, pw_gyba, 0, max_pg_wamp,
                       (short)((maxGradRes*pw_gyba)/GRAD_UPDATE_TIME), psd_etbetay);
            createinstr(&gyba, (long)(psd_pulsepos + pw_gxwad + pw_gxgap/2 -
                                      (pw_gyba + pw_gyb/2)), pw_gyba, ia_gyb);
        
            if (pw_gyb >= GRAD_UPDATE_TIME) {
                createconst(&gyb, YGRAD, pw_gyb, max_pg_wamp);
                createinstr(&gyb, (long)(psd_pulsepos + pw_gxwad + pw_gxgap/2 -
                                         pw_gyb/2), pw_gyb, ia_gyb);
            }
        
            createramp(&gybd, YGRAD, pw_gybd, max_pg_wamp, 0,
                       (short)((maxGradRes*pw_gybd)/GRAD_UPDATE_TIME), psd_etbetay);
            createinstr(&gybd, (long)(psd_pulsepos + pw_gxwad + pw_gxgap/2 +
                                      pw_gyb/2), pw_gybd, ia_gyb);
        
            linkpulses(3,&gyb,&gyba,&gybd);
        
            if (pw_gxgap == 0) {    /* Combine decay and attack ramps */
                createramp(&gxwd, XGRAD, 2*pw_gxwad, max_pg_wamp, -max_pg_wamp,
                           (short)(maxGradRes*(2*pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwd, (long)psd_pulsepos, 2*pw_gxwad, psd_eparity*
                            (-ia_gxw));
                psd_pulsepos += 2*pw_gxwad;
            
            } else {
                createramp(&gxwd, XGRAD, pw_gxwad, -max_pg_wamp, 0,
                           (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwd, (long)psd_pulsepos, pw_gxwad, psd_eparity*
                            ia_gxw);
                psd_pulsepos += pw_gxwad;
            
                createconst(&gxgap, XGRAD, pw_gxgap, 0);
                createinstr(&gxgap, (long)psd_pulsepos,
                            pw_gxgap, 0);
                psd_pulsepos += pw_gxgap;
            
                createramp(&gxwa, XGRAD, pw_gxwad, 0, max_pg_wamp,
                           (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwa, (long)psd_pulsepos, pw_gxwad, psd_eparity*
                            ia_gxw);
                psd_pulsepos += pw_gxwad;
            }
        
            createconst(&gxw, XGRAD, pw_gxwl+pw_gxw+pw_gxwr, max_pg_wamp);
            createinstr(&gxw, (long)psd_pulsepos,
                        pw_gxwl+pw_gxw+pw_gxwr, psd_eparity*ia_gxw);
            psd_pulsepos += pw_gxwl;
        
            sprintf(psd_epstring, "echo%04d", psd_gxwcnt-1 + $[et_offset]);
            pulsename(&(echotrain[psd_gxwcnt-1+$[et_offset]]), psd_epstring);
        
            if ($[et_dab_off] == 0)                                           
                psd_epdaboff = 0;
            else
                psd_epdaboff = (long)(psd_pulsepos + $[et_dacqdelay] + $[et_dab_off]);
        
            if ($[et_xtr_off] == 0)
                psd_epxtroff = 0;
            else
                psd_epxtroff = (long)(psd_pulsepos + $[et_dacqdelay] +
                                      $[et_xtr_off]);
        
            epiacqq(&(echotrain[psd_gxwcnt-1+$[et_offset]]),                
                    (long)(psd_pulsepos + $[et_dacqdelay]),
                    psd_epdaboff, psd_epxtroff,
                    (long)$[et_filt_slot], (long)TYPRECVALL, (TYPDAB_PACKETS)DABNORM,
                    (long)$[et_acq_prefills],(long)$[et_recvr_type],
                    (long)$[et_dab_type]);
        
            psd_pulsepos += pw_gxw + pw_gxwr;      
        
        } /* for (psd_gxwcnt = 2; psd_gxwcnt <= $[et_vps]; psd_gxwcnt++) */
    
        if (($[et_vps] % 2) == 1) {    /* views per shot is odd */          
            if (pw_gxcra >= GRAD_UPDATE_TIME) {
                createramp(&gxcra, XGRAD, pw_gxcra, (short)ia_gxw,
                           (short)ia_gxcr, (short)(maxGradRes*(pw_gxcra/
                                                               GRAD_UPDATE_TIME)),
                           psd_etbetax);
                createinstr(&gxcra, (long)(psd_pulsepos),
                            pw_gxcra, max_pg_iamp);
                psd_pulsepos += pw_gxcra;
            }
                                         
        } else {                        /* views per shot is even */

            /* single transition ramp into crusher */                  

            if ((ia_gxw == ia_gxcr) && (pw_gxwad == pw_gxcra)) {
                createramp(&gxwd, XGRAD, 2*pw_gxwad, -max_pg_wamp, max_pg_wamp,
                           (short)(maxGradRes*(2*pw_gxwad)/GRAD_UPDATE_TIME),
                           psd_etbetax);
                createinstr(&gxwd, (long)psd_pulsepos, 2*pw_gxwad, ia_gxw);
                psd_pulsepos += 2*pw_gxwad;

            } else {    /* two separate ramps, decay ramp needs new waveform */

                createramp(&gxwde, XGRAD, pw_gxwad, -max_pg_wamp, 0,              
                           (short)(maxGradRes*(pw_gxwad)/GRAD_UPDATE_TIME), psd_etbetax);
                createinstr(&gxwde, (long)psd_pulsepos, pw_gxwad, ia_gxw);
                psd_pulsepos += pw_gxwad;

                if (pw_gxcra >= GRAD_UPDATE_TIME) {
                    createramp(&gxcra, XGRAD, pw_gxcra, (short)0,
                               (short)ia_gxcr, (short)(maxGradRes*(pw_gxcra/
                                                                   GRAD_UPDATE_TIME)),
                               psd_etbetax);
                    createinstr(&gxcra, (long)(psd_pulsepos),
                                pw_gxcra, max_pg_iamp);
                    psd_pulsepos += pw_gxcra;
                }

            }   
        }        
        if (pw_gxcr >= GRAD_UPDATE_TIME) {
            createconst(&gxcr, XGRAD, pw_gxcr, max_pg_wamp);
            createinstr(&gxcr, (long)psd_pulsepos,
                        pw_gxcr, ia_gxcr);
            psd_pulsepos += pw_gxcr;
        }

        if (pw_gxcrd >= GRAD_UPDATE_TIME) {
            createramp(&gxcrd, XGRAD, pw_gxcrd, (short)ia_gxcr,
                       (short)0, (short)(maxGradRes*(pw_gxcrd/

                                                     GRAD_UPDATE_TIME)), psd_etbetax);                             
            createinstr(&gxcrd, (long)psd_pulsepos,
                        pw_gxcrd, max_pg_iamp);
            psd_pulsepos += pw_gxcrd;
        }
 
    }
}

}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
EXTWAVE(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
	extern_file, ext_offset:0, ext_loggrd){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}

insert: cvinit =>{
  a_$[ext_name] = $[ext_amp];
  res_$[ext_name] = $[ext_res];
  pw_$[ext_name] = $[ext_dur];
  off_$[ext_name] = $[ext_offset];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}
}

var:{
  
  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
		      res_$[ext_name],fileloc_$[ext_name]);
    if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
      {
	createinstr( &$[ext_name],(long)($[ext_pos]) + psd_rf_wait, 
		    pw_$[ext_name],ia_$[ext_name]);
	addrfbits(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) + psd_rf_wait,
		  pw_$[ext_name]);
      }
    else
      {
	createinstr( &$[ext_name],(long)($[ext_pos]), 
		    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

/*Meng: 11/2/95, added to take name string for external pulse*/

EXTWAVE_INV(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
	extern_file, ext_offset:0, ext_loggrd){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}

insert: cvinit =>{
  a_$[ext_name] = $[ext_amp];
  res_$[ext_name] = $[ext_res];
  pw_$[ext_name] = $[ext_dur];
  off_$[ext_name] = $[ext_offset];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}
}

var:{
  
/*  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";*/
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
		      res_$[ext_name],$[extern_file]);
    if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
      {
	createinstr( &$[ext_name],(long)($[ext_pos]) + psd_rf_wait, 
		    pw_$[ext_name],ia_$[ext_name]);
	addrfbits(&$[ext_name],off_$[ext_name],(long)($[ext_pos]) + psd_rf_wait,
		  pw_$[ext_name]);
      }
    else
      {
	createinstr( &$[ext_name],(long)($[ext_pos]), 
		    pw_$[ext_name],ia_$[ext_name]);
      }
  }
}
}

/* 3/13/95 YI  added EXTWAVE2
               changed datatype of res_$[ext_name] filed from short to int. */

EXTWAVE2(ext_wgname, ext_name, ext_pos, ext_dur, ext_amp, ext_res,
	extern_file, ext_offset:0, ext_loggrd, rf_slot){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}

insert: cvinit =>{
  a_$[ext_name] = $[ext_amp];
  res_$[ext_name] = $[ext_res];
  pw_$[ext_name] = $[ext_dur];
  off_$[ext_name] = $[ext_offset];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[ext_wgname], &$[ext_loggrd]);
  ia_$[ext_name] = (a_$[ext_name] / target) * MAX_PG_IAMP;
}
}

var:{
  
  EXTERN_FILENAME fileloc_$[ext_name] =  "$[extern_file]";
  WF_PULSE $[ext_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");

    /* Scale waveform if needed */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	createsinc(&$[ext_name], $[ext_wgname],rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,1.0,0.46);
	if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	    ($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait, 
			pw_$[ext_name],ia_$[ext_name]);
	    addrfbits(&$[ext_name],off_$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait,
		      pw_$[ext_name]);
	  }
	else
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]), 
			pw_$[ext_name],ia_$[ext_name]);
	  }

	/* Create some board waveform space, scale the pulse, and then move
	 * the local memory to the reserved board memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[ext_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[ext_name], fileloc_$[ext_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[ext_name],(int)rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[ext_name] = rfpulseInfo[$[rf_slot]].newres;
	
	/* Move immediately into permanent memory */
	movewaveimm(wave_space, &$[ext_name], (int)0, res_$[ext_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[ext_name],$[ext_wgname],
		      res_$[ext_name],fileloc_$[ext_name]);
	if (($[ext_wgname]==TYPRHO1)||($[ext_wgname]==TYPRHO2) ||
	    ($[ext_wgname]==TYPTHETA)||($[ext_wgname]==TYPOMEGA))
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait, 
			pw_$[ext_name],ia_$[ext_name]);
	    addrfbits(&$[ext_name],off_$[ext_name],(LONG)($[ext_pos]) + psd_rf_wait,
		      pw_$[ext_name]);
	  }
	else
	  {
	    createinstr( &$[ext_name],(LONG)($[ext_pos]), 
			pw_$[ext_name],ia_$[ext_name]);
	  }
      }
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
/* Make the use of external RF files easier to switch internally.
   The EXTWAVE macro in epic.h is not quite flexible enough. */
EXTWAVEX(ext_wgname, ext_name, ext_pos, extern_file){

cv:{
  float a_$[ext_name];
  int ia_$[ext_name];
  int pw_$[ext_name];
  int res_$[ext_name];
  int off_$[ext_name];
}
 
insert: predownload =>{
  ia_$[ext_name] = a_$[ext_name] * MAX_PG_IAMP;
}
 
var:{
 
  EXTERN_FILENAME $[extern_file];
  WF_PULSE $[ext_name] = INITPULSE;
}
 
subst:{
  {
    pulsename(&$[ext_name],"$[ext_name]");
    createextwave(&$[ext_name],$[ext_wgname],
                      res_$[ext_name],$[extern_file]);
    createinstr( &$[ext_name],(long)$[ext_pos] + psd_rf_wait,
                pw_$[ext_name],ia_$[ext_name]);
    addrfbits(&$[ext_name],off_$[ext_name],(long)$[ext_pos] + psd_rf_wait,
              pw_$[ext_name]);
  }
}
}
 
/* merged 55 bch into vmx.  YH  10/13/94 */
FREC_DIAGS(fd_name, fd_pos, fd_rinibble, fd_rqnibble, fd_diag_mode:0) {
 
/* FREC_DIAGS creates an ssp packet that sets up the fast receiver with
   diagnostics data nibbles that can be used to test the integrity of the
   data pathways.  This data is sent from the remote fast receiver to
   the dab instead of the actual sampled data.  The diagnostic mode
   'A' must be set explicitly in the fast receiver RBA packet to force
   the receiver to output the diagnostic data nibbles.
 
   Argument definitions:
   fd_name        -  name of packet
   fd_pos         -  position of packet
   fd_rinibble    -  remoted i nibble
   fd_rqnibble    -  remoted q nibble
   fd_diag_mode   -  diagnostic mode, 1=mode A, 2=mode B
 
*/
 
cv:{
}
insert: cvinit =>{
}
insert: predownload => {
}
var:{
  WF_PULSE $[fd_name] = INITPULSE;
}
subst:{
  {
        short inibbleout;
        short qnibbleout;
 
        switch (fast_diag_mode) {
        case 1:
          inibbleout = ($[fd_rinibble] & 0x0F) | 0xC0;
          qnibbleout = ($[fd_rqnibble] & 0x0F) | 0xD0;
          break;
        case 2:
          inibbleout = ($[fd_rinibble] & 0x0F) | 0xE0;
          qnibbleout = ($[fd_rqnibble] & 0x0F) | 0xF0;
          break;
        default:
          break;
        }
 
    pulsename(&$[fd_name],"$[fd_name]");
        FAST_DIAG_bits[2] = SSPD + inibbleout;
        FAST_DIAG_bits[4] = SSPD + qnibbleout;
 
        createbits((WF_PULSE_ADDR)&$[fd_name],
                           (WF_PROCESSOR)TYPSSP,
                           (short)FAST_DIAG_length,
                           (short *)FAST_DIAG_bits);

        createinstr((WF_PULSE_ADDR)&$[fd_name],      
                                (long)$[fd_pos],
                                (long)FAST_DIAG_length,
                                (long)0);
  }
}
}
 
/* merged 55 bch into vmx.  YH  10/13/94 */
FASTACQUIREDATA(facq_name, facq_pos, frecv_type: 1, fdab_switch:1,
                          fdab_pos:DEFAULTPOS, fxtr_pos:DEFAULTPOS, facq_fslot:1,
                          facq_recvval:4,facq_dabtype:DABNORM, facq_prefills:DEFPREFILLS){
 
/* FASTACQUIREDATA creates a single data acquisition frame for either the
   standard or fast receivers, with an optional single frame dab packet.
 
   Argument definitions:
   facq_name      -  name of packet, basename for CVs created
   facq_pos       -  absolute time position of start of acquisition (RBA)
   frecv_type     -  0=standard receiver, 1=fast receiver
   fdab_switch    -  0=don't create dab packet, 1=create a standard dab packet
   fdab_pos       -  absolute time position of dab packet; if zero then default
                     to rules specified in acqq or epiacqq.
   fxtr_pos       -  absolute time position of xtr packet; if zero then default
                     to rules specified in acqq or epiacqq.
   facq_fslot     -  filter slot to use (only applies if frecv_type == 0)
   facq_recvval   -  receiver unit number (0-3 = std recvr, 4 = fast receiver)
   facq_dabtype   -  normal or cine packet
   facq_prefills  -  number of prefills to position DAB packet (only applies
                     if frecv_type == 0 and fdab_switch == 1)
*/
 
cv:{
  int filter_$[facq_name];
  int rcvr_$[facq_name];
  int prefill_$[facq_name];
}
insert: cvinit =>{
  filter_$[facq_name] = $[facq_fslot];
  rcvr_$[facq_name] = $[facq_recvval];
  prefill_$[facq_name] = DEFPREFILLS;
}
insert: predownload => {
}
var:{
  WF_PULSE $[facq_name] = INITPULSE;
}    
subst:{
  {
    pulsename(&$[facq_name],"$[facq_name]");
 
    epiacqq(&$[facq_name], (long)($[facq_pos]),(long)($[fdab_pos]),
             (long)($[fxtr_pos]), (long)(filter_$[facq_name]),
             (long)(rcvr_$[facq_name]), (TYPDAB_PACKETS)($[facq_dabtype]),
                         (long)($[facq_prefills]), (long)($[frecv_type]),
                         (long)($[fdab_switch]));
  }
}
}

/* changed res_$ from short to int YH */
HADAMARD(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_sep,
       snc_res:0, snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46){
cv:{
  float a_$[snc_name];
  int ia_$[snc_name];
  int pw_$[snc_name];
  float sep_$[snc_name];
  int res_$[snc_name];
  float cyc_$[snc_name];
  int off_$[snc_name];
  float alpha_$[snc_name];
}
var:{
  WF_PULSE $[snc_name] = INITPULSE;
}
insert: cvinit =>{
  a_$[snc_name] = $[snc_amp];
  res_$[snc_name] = $[snc_res];
  cyc_$[snc_name] = $[snc_cycles];
  off_$[snc_name] = $[snc_offset];
  alpha_$[snc_name] = $[snc_alpha];
  pw_$[snc_name] = $[snc_dur];
  sep_$[snc_name] = $[snc_sep];
}

insert: predownload =>{
  if (res_$[snc_name] == 0)
    {
    res_$[snc_name] = pw_$[snc_name]/(RF_UPDATE_TIME);
    }
  ia_$[snc_name] = a_$[snc_name] * MAX_PG_IAMP;
}
subst:{
  {
    pulsename(&$[snc_name],"$[snc_name]");
    createhadamard(&$[snc_name],$[snc_wgname],res_$[snc_name],MAX_PG_WAMP,
		   sep_$[snc_name],cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
	($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
	createinstr( &$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
		    pw_$[snc_name],ia_$[snc_name]);
	addrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
		  pw_$[snc_name]);
      }
    else
      {
	createinstr( &$[snc_name],(long)($[snc_pos]),
		    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
HSDAB(hsdab_name, hsdab_pos) {
 
/* HSDAB creates a hyperscan dab packet at the specified position.
 
   Argument definitions:
   hsdab_name      -  name of packet
   hsdab_pos       -  absolute time position of start of hs dab packet
*/
 
cv:{   
}
insert: cvinit =>{
}
insert: predownload => {
}
var:{
  WF_PULSE $[hsdab_name] = INITPULSE;
}    
 subst:{
{
    pulsename(&$[hsdab_name],"$[hsdab_name]");

        createhsdab(&$[hsdab_name], (long)($[hsdab_pos]));
  }
}
}
 
/* merged 55 bch into vmx.  YH 10/13/94 */
INITFASTRECV(ifr_name, ifr_pos, ifr_samps, ifr_tsp, ifr_delay, ifr_lpf:1) {
 
/* INITFASTRECV creates an ssp packet that programs the fast receiver.
 
   Argument definitions:
   ifr_name      -  name of packet
   ifr_pos       -  absolute time position of fast receiver init packet
   ifr_samps     -  number of samples per frame
   ifr_tsp       -  sample period in tics (1 tic = 50ns)
   ifr_delay     -  frame delay in tics (1 tic = 50ns)
   ifr_lpf       -  low pass filter setting (1-5, 1=100kHz,..,5=500kHz)
 
*/
 
cv:{
}
insert: cvinit =>{
}
insert: predownload => {
}
var:{
  WF_PULSE $[ifr_name] = INITPULSE;
}
subst:{
  {
    pulsename(&$[ifr_name],"$[ifr_name]");
 
        initfastrec(&$[ifr_name], (long)($[ifr_pos]),
                  (long)($[ifr_samps]), (long)($[ifr_tsp]),
                  (long)($[ifr_delay]), (long)($[ifr_lpf]));
  }
}
}
 
/* merged 55 bch into vmx.  YH 10/13/94 */
MEMTRAP(trp_wgname,trp_name,trp_pos,trp_area,trp_define:TYPDEF,trp_loggrd) {
  /* Create a Trapezoid completely in memory. This really burns memory
     but it only requires one update call. It was written to address
     a performance issue in the ISI update for the fgre3d killer/rewinder.
     The pulse is first created in user allocated memory with rsp
     calls then moved into reserved waveform memory. The user memory is
     then freed.
         */
 
 
cv:{
  float a_$[trp_name];
  int ia_$[trp_name];
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name];
  int res_$[trp_name];
  int per_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
  s16 *$[trp_name]_mem;         /* temporary memory pointer */
  s16 $[trp_name]_indx;         /* indx into user memory */
}
insert: cvinit => {
}
insert: predownload => {
{
   float target;
   int rtime,ftime;
 
   gettarget(&target, $[trp_wgname], &$[trp_loggrd]);
   getramptime(&rtime,&ftime,$[trp_wgname], &$[trp_loggrd]);
   if ($[trp_define] == TYPDEF) {
     if (amppwgrad((float)($[trp_area]),target,0.0,0.0,rtime,MIN_PLATEAU_TIME,
                                 &a_$[trp_name], &pw_$[trp_name]a, &pw_$[trp_name],
                                 &pw_$[trp_name]d) == FAILURE) return FAILURE;
   }
   ia_$[trp_name] = (a_$[trp_name] / target) * MAX_PG_IAMP;
   if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2) ||
       ($[trp_wgname]==TYPTHETA)||($[trp_wgname]==TYPOMEGA))
     {                          /* Determine min period */
       per_$[trp_name] = (RF_UPDATE_TIME);
     }
   else
     {
       per_$[trp_name] = (GRAD_UPDATE_TIME);
     }
   res_$[trp_name] =            /* Find resolution */
     (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d)/
       per_$[trp_name];
}
}
subst:{
  {
                                /* Allocate user memory */
    $[trp_name]_mem = (s16 *)AllocNode( res_$[trp_name]*sizeof(s16));
    $[trp_name]_indx = 0;
 
    getbeta(&pg_beta, $[trp_wgname], &$[trp_loggrd]);
 
                                /* Up ramp */
    uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
          (pw_$[trp_name]a/per_$[trp_name]),
          (short) 0, MAX_PG_WAMP, pg_beta);
                                /* Clear EOW */
    $[trp_name]_indx = ( pw_$[trp_name]a / per_$[trp_name] );
    $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
                                /* Top const */
    uramp((&$[trp_name]_mem[$[trp_name]_indx]),
          (pw_$[trp_name]/per_$[trp_name]),
          MAX_PG_WAMP, MAX_PG_WAMP, pg_beta);
                                /* Clear EOW */
    $[trp_name]_indx = ( (pw_$[trp_name]a+pw_$[trp_name]) /per_$[trp_name] );
    $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
                                /* Decay Ramp */
    uramp((&$[trp_name]_mem[$[trp_name]_indx]),
          (pw_$[trp_name]d/per_$[trp_name]),
          MAX_PG_WAMP, (short) 0, pg_beta);
                                /* Create pulse and memory */
    pulsename( &$[trp_name], "$[trp_name]");
    createreserve( &$[trp_name], $[trp_wgname], res_$[trp_name]);
    createinstr( &$[trp_name],(long)($[trp_pos]-pw_$[trp_name]a),
                (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d),
                ia_$[trp_name]);
                                /* Move user pulse into waveform mem */
    movewaveimm($[trp_name]_mem, &$[trp_name],
                (int)0, res_$[trp_name], TOHARDWARE);
                                /* Free user memory */
    FreeNode( $[trp_name]_mem );
    if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2))
      {                         /* Add rf control bits if rf pulse */
        addrfbits(&$[trp_name],0,(long)($[trp_pos]),
                  (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d));
      }
  }
}
}

PASSPACK(pass_pack_name, pass_pack_pos){
var:{
  WF_PULSE $[pass_pack_name] = INITPULSE;
}
insert: predownload => {
}
insert: cvinit => {
}
subst:{
  {
    pulsename(&$[pass_pack_name],"$[pass_pack_name]");
    createpass(&$[pass_pack_name],(long)($[pass_pack_pos]));
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
RAMP(rmp_wgname,rmp_name,rmp_pos,rmp_dur,rmp_startamp,rmp_endamp,rmp_res:0,rmp_loggrd) {
cv:{
  float start_$[rmp_name];
  float end_$[rmp_name];
  int ia_st$[rmp_name];
  int ia_end$[rmp_name];
  int pw_$[rmp_name];
  int res_$[rmp_name];
}
var:{
  WF_PULSE $[rmp_name] = INITPULSE;
}
insert: cvinit =>{
  start_$[rmp_name] = $[rmp_startamp];
  end_$[rmp_name] = $[rmp_endamp];
  pw_$[rmp_name] = $[rmp_dur];
  res_$[rmp_name] = $[rmp_res];
}

insert: predownload =>{
{
  float target;

  gettarget(&target, $[rmp_wgname], &$[rmp_loggrd]);
  if (($[rmp_wgname]==TYPRHO1)||($[rmp_wgname]==TYPRHO2)||($[rmp_wgname]==TYPOMEGA)||($[rmp_wgname]==TYPTHETA))
    {
      ia_st$[rmp_name] = start_$[rmp_name] * MAX_PG_WAMP;
      if (start_$[rmp_name])
        {
          ia_end$[rmp_name] = end_$[rmp_name] * MAX_PG_WAMP;
        }
      else
        {
          ia_end$[rmp_name] = end_$[rmp_name] * MAX_PG_IAMP;
        }
     }
  else
    {
      ia_st$[rmp_name] = (start_$[rmp_name] / target) * MAX_PG_WAMP;
      if (start_$[rmp_name])
        {
          ia_end$[rmp_name] = (end_$[rmp_name] / target) * MAX_PG_WAMP;
        }
      else
        {
          ia_end$[rmp_name] = (end_$[rmp_name] / target) * MAX_PG_IAMP;
        }
    }	
}
}

subst:{
  {
    pulsename(&$[rmp_name],"$[rmp_name]");
 
        getbeta(&pg_beta, $[rmp_wgname], &$[rmp_loggrd]);
 
    if (start_$[rmp_name])
      {
        createramp(&$[rmp_name],$[rmp_wgname],pw_$[rmp_name],
                   ia_st$[rmp_name],ia_end$[rmp_name],
                   (short)(maxGradRes*(pw_$[rmp_name]/GRAD_UPDATE_TIME)),
                   pg_beta);
        createinstr( &$[rmp_name],(long)($[rmp_pos]),pw_$[rmp_name],MAX_PG_IAMP);
      }
    else
      {
        createramp(&$[rmp_name],$[rmp_wgname],pw_$[rmp_name],
                   (short)0,MAX_PG_WAMP,
                   (short)(maxGradRes*(pw_$[rmp_name]/GRAD_UPDATE_TIME)),
                   pg_beta);
        createinstr(&$[rmp_name],(long)($[rmp_pos]),pw_$[rmp_name],
                    ia_end$[rmp_name]);
      }
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
RCVRBLANK(rcvbl_name,rcvbl_pos,rcvbl_val:0) {
cv:{
  int ia_$[rcvbl_name];
}   
insert:  cvinit => {
}
insert: predownload => {
  ia_$[rcvbl_name] = $[rcvbl_val];
}
var:{
  WF_PULSE $[rcvbl_name] = INITPULSE;
  short $[rcvbl_name]_pack[4];
}
subst:{
  {
    $[rcvbl_name]_pack[0] = SSPDS+RDC;
    $[rcvbl_name]_pack[1] = SSPOC+RFUBL+RSEL_ALL;
    $[rcvbl_name]_pack[2] = SSPD+RBL;
    $[rcvbl_name]_pack[3] = SSPDS;

    pulsename(&$[rcvbl_name],"$[rcvbl_name]");
    createbits(&$[rcvbl_name],TYPSSP,4,$[rcvbl_name]_pack);
    createinstr( &$[rcvbl_name],(long)($[rcvbl_pos]),4,ia_$[rcvbl_name]);
  }
}
}
 
RCVRUNBLANK(rcvbl_name,rcvbl_pos,rcvbl_val:0) {
cv:{
  int ia_$[rcvbl_name];
}
insert:  cvinit => {
}
insert: predownload => {
  ia_$[rcvbl_name] = $[rcvbl_val];
}
var:{
  WF_PULSE $[rcvbl_name] = INITPULSE;
  short $[rcvbl_name]_pack[4];
}
subst:{
  {
    $[rcvbl_name]_pack[0] = SSPDS+RDC;
    $[rcvbl_name]_pack[1] = SSPOC+RFUBL+RSEL_ALL;
    $[rcvbl_name]_pack[2] = SSPD+RUBL;
    $[rcvbl_name]_pack[3] = SSPDS;

    pulsename(&$[rcvbl_name],"$[rcvbl_name]");
    createbits(&$[rcvbl_name],TYPSSP,4,$[rcvbl_name]_pack);
    createinstr( &$[rcvbl_name],(long)($[rcvbl_pos]),4,ia_$[rcvbl_name]);
  }
}
}


SEQLENGTH(seq_name, seq_reprate, seq_offset){

var:{
  SEQUENCE_ENTRIES  off_$[seq_offset];
  WF_PULSE $[seq_name];
#ifndef IPG
  int idx_$[seq_name];   /* sequence entry index */
#endif /* !IPG */
}
insert: predownload => {
}
insert: cvinit => {
}

subst:{
  {
    pulsename(&$[seq_name],"$[seq_name]");
    createseq(&$[seq_name],$[seq_reprate], off_$[seq_offset]);
#ifndef IPG
    /* Update sequence counter and get current sequence entry index */
    updateIndex( &idx_$[seq_name] );
    printDebug( DBLEVEL1, (dbLevel_t)seg_debug, "SEQLENGTH",
                "idx_$[seq_name] = %d\n", idx_$[seq_name] );
#endif /* !IPG */
  }
}
}

/* merged 55 bch into vmx.  YH 10/13/94 */
/* changed res_$ from short to int YH */
SINC(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
         snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46,snc_loggrd){
cv:{
  float a_$[snc_name];
  int ia_$[snc_name];
  int pw_$[snc_name];
  int res_$[snc_name];
  float cyc_$[snc_name];
  int off_$[snc_name];
  float alpha_$[snc_name];
}
var:{
    WF_PULSE $[snc_name] = INITPULSE;
}
insert: cvinit =>{
  a_$[snc_name] = $[snc_amp];
  res_$[snc_name] = $[snc_res];
  cyc_$[snc_name] = $[snc_cycles];
  off_$[snc_name] = $[snc_offset];
  alpha_$[snc_name] = $[snc_alpha];
  pw_$[snc_name] = $[snc_dur];
}
insert: predownload =>{
{
  float target;
  gettarget(&target, $[snc_wgname],&$[snc_loggrd]);
  if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2)
        ||($[snc_wgname]==TYPOMEGA)||($[snc_wgname]==TYPTHETA))
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(RF_UPDATE_TIME);
        }
      ia_$[snc_name] = a_$[snc_name] * MAX_PG_IAMP;
    }    
  else
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(GRAD_UPDATE_TIME);
        }
      ia_$[snc_name] = (a_$[snc_name] / target) * MAX_PG_IAMP;
    }    
}
}
subst:{
  {
    pulsename(&$[snc_name],"$[snc_name]");
    createsinc(&$[snc_name],$[snc_wgname],res_$[snc_name],
               MAX_PG_WAMP,cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
        ($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
        createinstr( &$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
                    pw_$[snc_name],ia_$[snc_name]);
        addrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]) + psd_rf_wait,
                  pw_$[snc_name]);
      }
    else
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}
}

/* added 55 changes.  YH  10/13/94 */
/* vmx */
SINC2(snc_wgname,snc_name,snc_pos,snc_dur,snc_amp,snc_res:0,
         snc_cycles:1.0,snc_offset:0.0,snc_alpha:0.46,snc_loggrd){
cv:{
  float a_$[snc_name];
  int ia_$[snc_name];
  int pw_$[snc_name];
  int res_$[snc_name];
  float cyc_$[snc_name];
  int off_$[snc_name];
  float alpha_$[snc_name];
}
var:{
    WF_PULSE $[snc_name] = INITPULSE;
}
insert: cvinit =>{
  a_$[snc_name] = $[snc_amp];
  res_$[snc_name] = $[snc_res];
  cyc_$[snc_name] = $[snc_cycles];
  off_$[snc_name] = $[snc_offset];
  alpha_$[snc_name] = $[snc_alpha];
  pw_$[snc_name] = $[snc_dur];
}
insert: predownload =>{
{
  float target;
  gettarget(&target, $[snc_wgname],&$[snc_loggrd]);
  if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2)
        ||($[snc_wgname]==TYPOMEGA)||($[snc_wgname]==TYPTHETA))
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(RF_UPDATE_TIME);
        }
      ia_$[snc_name] = a_$[snc_name] * MAX_PG_IAMP;
    }    
  else
    {
      if (res_$[snc_name] == 0)
        {
          res_$[snc_name] = pw_$[snc_name]/(GRAD_UPDATE_TIME);
        }
      ia_$[snc_name] = (a_$[snc_name] / target) * MAX_PG_IAMP;
    }    
}
}
subst:{
  {
    pulsename(&$[snc_name],"$[snc_name]");
    createsinc(&$[snc_name],$[snc_wgname],res_$[snc_name],
               MAX_PG_WAMP,cyc_$[snc_name],alpha_$[snc_name]);
    if (($[snc_wgname]==TYPRHO1)||($[snc_wgname]==TYPRHO2) ||
        ($[snc_wgname]==TYPTHETA)||($[snc_wgname]==TYPOMEGA))
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
        addrfbits(&$[snc_name],off_$[snc_name],(long)($[snc_pos]),
                  pw_$[snc_name]);
      }
    else
      {
        createinstr( &$[snc_name],(long)($[snc_pos]),
                    pw_$[snc_name],ia_$[snc_name]);
      }
  }
}
}
/* end vmx */

/* merged 55 bch into vmx.  YH 10/13/94 */
/* changed res_$ from short to int YH */
SINUSOID(sin_wgname,sin_name,sin_pos,sin_dur,sin_amp,sin_res:0,
         sin_sphase:0.0,sin_phasel:0.5,sin_offset:0.0,rmp_loggrd){
cv:{
  int ia_$[sin_name]w;
  float a_$[sin_name];
  int ia_$[sin_name];
  int pw_$[sin_name];
  int res_$[sin_name];
  float phs_$[sin_name];
  float phl_$[sin_name];
  int off_$[sin_name];
}
var:{
  WF_PULSE $[sin_name] = INITPULSE;
}

insert: cvinit => {
  a_$[sin_name] = $[sin_amp];
  ia_$[sin_name]w = MAX_PG_WAMP;
  res_$[sin_name] = $[sin_res];
  phs_$[sin_name] = $[sin_sphase];
  phl_$[sin_name] = $[sin_phasel];
  off_$[sin_name] = $[sin_offset];
  pw_$[sin_name] = $[sin_dur];
}

insert: predownload =>{
{
  float target;
 
  gettarget(&target, $[sin_wgname],&$[rmp_loggrd]);
  if (($[sin_wgname]==TYPRHO1)||($[sin_wgname]==TYPRHO2)
        ||($[sin_wgname]==TYPOMEGA)||($[sin_wgname]==TYPTHETA))
    {
      if (res_$[sin_name] == 0)
        {
          res_$[sin_name] = pw_$[sin_name]/(RF_UPDATE_TIME);
        }
      ia_$[sin_name] = a_$[sin_name] * MAX_PG_IAMP;
    }    
  else
    {
      if (res_$[sin_name] == 0)
        {
          res_$[sin_name] = pw_$[sin_name]/(GRAD_UPDATE_TIME);
        }
      ia_$[sin_name] = (a_$[sin_name] / target) * MAX_PG_IAMP;
    }    
 
  if (off_$[sin_name] != 0.0)
    {
      ia_$[sin_name]w = (a_$[sin_name] / target) * MAX_PG_WAMP;
      ia_$[sin_name] = MAX_PG_IAMP;
    }
}
}

subst:{
  {
    pulsename(&$[sin_name],"$[sin_name]");
    createsinusoid(&$[sin_name],$[sin_wgname],res_$[sin_name],
		   ia_$[sin_name]w,phs_$[sin_name],phl_$[sin_name],
		   off_$[sin_name]);
    createinstr(&$[sin_name],(long)($[sin_pos]),pw_$[sin_name],ia_$[sin_name]);
     
    if (($[sin_wgname]==TYPRHO1)||($[sin_wgname]==TYPRHO2))
      {
	addrfbits(&$[sin_name],0,(long)($[sin_pos]),pw_$[sin_name]);
      }
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELX(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float gscale_$[slsel_name] = 1.0;
  float thk_$[slsel_name];
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
                                         pw_$[slsel_name]),
               (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
               (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx,
              $[slsel_loggrd].xrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
                  $[slsel_loggrd].xft,$[slsel_define])
      == FAILURE) return FAILURE;

  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0) 
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;

}
subst:{
  {
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
     pg_beta = $[slsel_loggrd].xbeta;
         createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(long)($[slsel_pos]-pw_gx$[slsel_name]a),
                pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    createconst(&gx$[slsel_name],XGRAD,pw_gx$[slsel_name],MAX_PG_WAMP);
    createinstr( &gx$[slsel_name],(long)($[slsel_pos]),
                pw_gx$[slsel_name],ia_gx$[slsel_name]);
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gx$[slsel_name]d/GRAD_UPDATE_TIME)),
                   pg_beta);
    createinstr( &gx$[slsel_name]d,(long)($[slsel_pos]+pw_gx$[slsel_name]),
                pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
	       &gx$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
    
}
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELY(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name], $[slsel_loggrd].ty,
	      $[slsel_loggrd].yrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name], $[slsel_loggrd].ty, 
	      $[slsel_loggrd].yft,$[slsel_define]) == FAILURE) return FAILURE;

  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0) 
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
	/* First create the pulses */
  pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
  pulsename(&gy$[slsel_name],"gy$[slsel_name]");
  pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
  pulsename(&$[slsel_name],"$[slsel_name]");

	/*  Now create the slice select trapezoid */
  pg_beta = $[slsel_loggrd].ybeta;
  createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,MAX_PG_WAMP,
                        (short)(maxGradRes*(pw_gy$[slsel_name]a/GRAD_UPDATE_TIME))
                        ,pg_beta);
  createinstr( &gy$[slsel_name]a,(long)($[slsel_pos]-pw_gy$[slsel_name]a),
      pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
  createconst(&gy$[slsel_name],YGRAD,pw_gy$[slsel_name],MAX_PG_WAMP);
  createinstr( &gy$[slsel_name],(long)($[slsel_pos]),
      pw_gy$[slsel_name],ia_gy$[slsel_name]);
  createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
                        (short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/GRAD_UPDATE_TIME))
                        ,pg_beta);
  createinstr( &gy$[slsel_name]d,(long)($[slsel_pos]+pw_gy$[slsel_name]),
      pw_gy$[slsel_name]d,ia_gy$[slsel_name]);

	/* Now create the rf pulse */
  createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
  createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
      pw_$[slsel_name],ia_$[slsel_name]);
  linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,&gy$[slsel_name]d);
  addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	pw_$[slsel_name]);

}
}
}

/* 3/13/95 YI  added SLICESELX2 and SLICESELY2
               changed data taype of res_$[slsel_name] from short to int. */

SLICESELX2(slsel_name, rf_slot, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  int temp_res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float gscale_$[slsel_name] = 1.0;
  float thk_$[slsel_name];
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx, 
	      $[slsel_loggrd].xrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
		  $[slsel_loggrd].xft,$[slsel_define]) 
      == FAILURE) return FAILURE;

  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* Modify resolution if scaling required */
    temp_res_$[slsel_name] = res_$[slsel_name];
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].xbeta;
    createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
					       GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(LONG)($[slsel_pos]-pw_gx$[slsel_name]a),
		pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    createconst(&gx$[slsel_name],XGRAD,pw_gx$[slsel_name],MAX_PG_WAMP);
    createinstr( &gx$[slsel_name],(LONG)($[slsel_pos]),
		pw_gx$[slsel_name],ia_gx$[slsel_name]);
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gx$[slsel_name]d/GRAD_UPDATE_TIME)),
		   pg_beta);
    createinstr( &gx$[slsel_name]d,(LONG)($[slsel_pos]+pw_gx$[slsel_name]),
		pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
	       &gx$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
    /* Changed back resolution incase external rf used later in pulsegen. We need
     * original resolution to scale pulses that are external
     */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = temp_res_$[slsel_name];
}
}
}

SLICESELY2(slsel_name, rf_slot, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  int temp_res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define])== FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name],$[slsel_loggrd].ty,
		  $[slsel_loggrd].yrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name],$[slsel_loggrd].ty,
	      $[slsel_loggrd].yft,$[slsel_define]) == FAILURE) return FAILURE;

  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);

}
var:{
  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
    /* Modify resolution if scaling required */
    temp_res_$[slsel_name] = res_$[slsel_name];
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
    /* First create the pulses */
    pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
    pulsename(&gy$[slsel_name],"gy$[slsel_name]");
    pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

	/*  Now create the slice select trapezoid */
  pg_beta = $[slsel_loggrd].ybeta;
  createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,MAX_PG_WAMP,
			(short)(maxGradRes*(pw_gy$[slsel_name]a/GRAD_UPDATE_TIME))
			,pg_beta);
  createinstr( &gy$[slsel_name]a,(LONG)($[slsel_pos]-pw_gy$[slsel_name]a),
      pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
  createconst(&gy$[slsel_name],YGRAD,pw_gy$[slsel_name],MAX_PG_WAMP);
  createinstr( &gy$[slsel_name],(LONG)($[slsel_pos]),
      pw_gy$[slsel_name],ia_gy$[slsel_name]);
  createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
			(short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/GRAD_UPDATE_TIME))
			,pg_beta);
  createinstr( &gy$[slsel_name]d,(LONG)($[slsel_pos]+pw_gy$[slsel_name]),
      pw_gy$[slsel_name]d,ia_gy$[slsel_name]);

    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,&gy$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
    /* Changed back resolution incase external rf used later in pulsegen. We need
     * original resolution to scale pulses that are external
     */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      res_$[slsel_name] = temp_res_$[slsel_name];
}

}
}


/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELZ(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
      $[slsel_loggrd].zrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
          $[slsel_loggrd].zft,$[slsel_define])== FAILURE) return FAILURE;

  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);


}
var:{
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    createconst(&gz$[slsel_name],ZGRAD,pw_gz$[slsel_name],MAX_PG_WAMP);
    createinstr( &gz$[slsel_name],(long)($[slsel_pos]),
                pw_gz$[slsel_name],ia_gz$[slsel_name]);
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/GRAD_UPDATE_TIME)),
                   pg_beta);
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
                pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait, 
	      pw_$[slsel_name]);
  }
}
}

/* 3/13/95 YI addd SLICESELZ2
              changed data type of res_$ and temp_res_$ from short to int. */

SLICESELZ2(slsel_name, rf_slot,slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name] = 0;
  int temp_res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
      $[slsel_loggrd].zrt,$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
	  $[slsel_loggrd].zft,$[slsel_define])== FAILURE) return FAILURE;

  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
			      
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
  if (res_$[slsel_name] == 0)
    res_$[slsel_name] = pw_$[slsel_name]/(RF_UPDATE_TIME);


}
var:{
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
subst:{
  {
    /* Modify resolution if scaling required */
    temp_res_$[slsel_name] = res_$[slsel_name];
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(LONG)($[slsel_pos]-pw_gz$[slsel_name]a),
		pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    createconst(&gz$[slsel_name],ZGRAD,pw_gz$[slsel_name],MAX_PG_WAMP);
    createinstr( &gz$[slsel_name],(LONG)($[slsel_pos]),
		pw_gz$[slsel_name],ia_gz$[slsel_name]);
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/GRAD_UPDATE_TIME)),
		   pg_beta);
    createinstr( &gz$[slsel_name]d,(LONG)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createsinc(&$[slsel_name],TYPRHO1,res_$[slsel_name],
	       MAX_PG_WAMP,cyc_$[slsel_name], alpha_$[slsel_name]);
    createinstr( &$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait, 
	      pw_$[slsel_name]);
    /* Changed back resolution incase external rf used later in pulsegen. We need
     * original resolution to scale pulses that are external
     */
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
       res_$[slsel_name] = temp_res_$[slsel_name];
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
SLICESELEXT(slsel_wgname, slsel_name, slsel_pos, slsel_dur, slsel_thk,
        slsel_flip, slsel_cycles:1.0,slsel_usegrad:1, res_g,extern_grad_file,
        res_rf, extern_rf_file, slsel_define:1,slsel_loggrd){
cv:{
  float a_g$[slsel_name];
  int ia_g$[slsel_name];
  int pw_g$[slsel_name]a;
  int pw_g$[slsel_name]d;
  int pw_g$[slsel_name];
  int res_g$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_g$[slsel_name] = $[slsel_dur];
  res_g$[slsel_name] = $[res_g];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
{
  float target;
  int rise_time, fall_time;
 
  gettarget(&target, $[slsel_wgname],&$[slsel_loggrd]);
  getramptime(&rise_time, &fall_time, $[slsel_wgname],&$[slsel_loggrd]);
 
  if (ampslice(&a_gx$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
                                         pw_$[slsel_name]),
               (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
               (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],target,
              rise_time,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],target,
              fall_time,(int)$[slsel_define])
      == FAILURE) return FAILURE;

  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/target;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
}
}
var:{
  EXTERN_FILENAME grad_$[slsel_name] = "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE g$[slsel_name]a = INITPULSE;                   
  WF_PULSE g$[slsel_name]  = INITPULSE;
  WF_PULSE g$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}
 
subst:{
  {
    getbeta(&pg_beta, $[slsel_wgname], &$[slsel_loggrd]);
        /* First create the pulses */
    pulsename(&g$[slsel_name]a,"g$[slsel_name]a");
    pulsename(&g$[slsel_name],"g$[slsel_name]");
    pulsename(&g$[slsel_name]d,"g$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
    createramp(&g$[slsel_name]a,$[slsel_wgname],pw_g$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_g$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]a,(long)($[slsel_pos]-pw_g$[slsel_name]a),
                pw_g$[slsel_name]a,ia_g$[slsel_name]);
    if ($[slsel_usegrad] == PLAY_GFILE)
      {
        createextwave(&g$[slsel_name],$[slsel_wgname],
                res_g$[slsel_name],grad_$[slsel_name]);
      }
    else
      {
        createconst(&g$[slsel_name],$[slsel_wgname], pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &g$[slsel_name],(long)($[slsel_pos]),
                pw_g$[slsel_name],ia_g$[slsel_name]);

    createramp(&g$[slsel_name]d,$[slsel_wgname],pw_g$[slsel_name]d,MAX_PG_WAMP,
               (short)(maxGradRes*(pw_g$[slsel_name]d/GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &g$[slsel_name]d,(long)($[slsel_pos]+pw_g$[slsel_name]),
                pw_g$[slsel_name]d,ia_g$[slsel_name]);

    /* Now create the rf pulse */                      
    createextwave(&$[slsel_name],TYPRHO1,
            res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
                pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&g$[slsel_name],&g$[slsel_name]a,
               &g$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
              pw_$[slsel_name]);
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELXEXT(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gx,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  int res_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  res_gx$[slsel_name] = $[res_gx];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xft,(int)$[slsel_define])
      == FAILURE) return FAILURE;
 
  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;
}
var:{
  EXTERN_FILENAME grad_x$[slsel_name] = "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
    
  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].xbeta;
    createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(long)($[slsel_pos]-pw_gx$[slsel_name]a),
                pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    if ($[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gx$[slsel_name],XGRAD, 
		res_gx$[slsel_name],grad_x$[slsel_name]);
      }
    else
      {
	createconst(&gx$[slsel_name],XGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gx$[slsel_name],(long)($[slsel_pos]),
		pw_gx$[slsel_name],ia_gx$[slsel_name]);
    
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes * pw_gx$[slsel_name]d/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]d,(long)($[slsel_pos]+pw_gx$[slsel_name]),
		pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1, res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
	       &gx$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
  }
}
}

/********************************************************************************
** To facilitate system safety, pulse and waveform scaling needs to be performed
** inside the SLICESELXEXT macro. This macro will scale the gradient and rfpulse
** waveforms given the position of the rfpulse in the rfpulse structure. The
** gradient scaling is performed by default with larger pw, or explicitly with
** stretchpulse using 1/2 the rfpulse resolution. This is done to ensure that
** the new gradient pw/res is multiple of GRAD_UPDATE_TIME (4usec) while
** RF_UPDATE_TIME(2usec). We assume the gradient resolution <= rfpulse resolution
** in the files.
*********************************************************************************//* vmx 06/07/95 YI  changed res_$[] to int type */
SLICESELXEXT2(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gx,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gx$[slsel_name];
  int ia_gx$[slsel_name];
  int pw_gx$[slsel_name]a;
  int pw_gx$[slsel_name]d;
  int pw_gx$[slsel_name];
  int res_gx$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gx$[slsel_name] = $[slsel_dur];
  res_gx$[slsel_name] = $[res_gx];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gx$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]a,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gx$[slsel_name]d,a_gx$[slsel_name],$[slsel_loggrd].tx,
	      $[slsel_loggrd].xft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gx$[slsel_name] = a_gx$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tx;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_x$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE gx$[slsel_name]a = INITPULSE;
  WF_PULSE gx$[slsel_name]  = INITPULSE;
  WF_PULSE gx$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gx$[slsel_name]a,"gx$[slsel_name]a");
    pulsename(&gx$[slsel_name],"gx$[slsel_name]");
    pulsename(&gx$[slsel_name]d,"gx$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].xbeta;
    createramp(&gx$[slsel_name]a,XGRAD,pw_gx$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gx$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]a,(LONG)($[slsel_pos]-pw_gx$[slsel_name]a),
		pw_gx$[slsel_name]a,ia_gx$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gx$[slsel_name],XGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gx$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gx$[slsel_name],(LONG)($[slsel_pos]),
			pw_gx$[slsel_name],ia_gx$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gx$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gx$[slsel_name], grad_z$[slsel_name]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gx$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gx$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gx$[slsel_name], (int)0, res_gx$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gx$[slsel_name],XGRAD, 
			  res_gx$[slsel_name], grad_z$[slsel_name]);
	    createinstr(&gx$[slsel_name],(LONG)($[slsel_pos]),
			pw_gx$[slsel_name],ia_gx$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gx$[slsel_name],XGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gx$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gx$[slsel_name],ia_gx$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gx$[slsel_name]d,XGRAD,pw_gx$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gx$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gx$[slsel_name]d,(LONG)($[slsel_pos]+pw_gx$[slsel_name]),
		pw_gx$[slsel_name]d,ia_gx$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure cycles have a value */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
		   &gx$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], rf_$[slsel_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name],rf_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gx$[slsel_name],&gx$[slsel_name]a,
		   &gx$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELYEXT(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gy,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  int res_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  res_gy$[slsel_name] = $[res_gy];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name],$[slsel_loggrd].ty,
              $[slsel_loggrd].yrt,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name],$[slsel_loggrd].ty,
              $[slsel_loggrd].yft,(int)$[slsel_define]) == FAILURE) return FAILURE;
  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_y$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
    
  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
    pulsename(&gy$[slsel_name],"gy$[slsel_name]");
    pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].ybeta;
    createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gy$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gy$[slsel_name]a,(long)($[slsel_pos]-pw_gy$[slsel_name]a),
		pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
    if ($[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gy$[slsel_name],YGRAD, 
		res_gy$[slsel_name],grad_y$[slsel_name]);
      }
    else
      {
	createconst(&gy$[slsel_name],YGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gy$[slsel_name],(long)($[slsel_pos]),
		pw_gy$[slsel_name],ia_gy$[slsel_name]);
    createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/GRAD_UPDATE_TIME))
                   ,pg_beta);
    createinstr( &gy$[slsel_name]d,(long)($[slsel_pos]+pw_gy$[slsel_name]),
		pw_gy$[slsel_name]d,ia_gy$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1, res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gy$[slsel_name],
	       &gy$[slsel_name]a,&gy$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);
  }
}
}

/********************************************************************************
** To facilitate system safety, pulse and waveform scaling needs to be performed
** inside the SLICESELYEXT macro. This macro will scale the gradient and rfpulse
** waveforms given the position of the rfpulse in the rfpulse structure. The
** gradient scaling is performed by default with larger pw, or explicitly with
** stretchpulse using 1/2 the rfpulse resolution. This is done to ensure that
** the new gradient pw/res is multiple of GRAD_UPDATE_TIME (4usec) while
** RF_UPDATE_TIME(2usec). We assume the gradient resolution <= rfpulse resolution
** in the files.
*********************************************************************************//* vmx 06/07/95 YI  changed res_$[] to int type */
SLICESELYEXT2(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gy,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gy$[slsel_name];
  int ia_gy$[slsel_name];
  int pw_gy$[slsel_name]a;
  int pw_gy$[slsel_name]d;
  int pw_gy$[slsel_name];
  int res_gy$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gy$[slsel_name] = $[slsel_dur];
  res_gy$[slsel_name] = $[res_gy];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gy$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]a,a_gy$[slsel_name],$[slsel_loggrd].ty,
	      $[slsel_loggrd].yrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gy$[slsel_name]d,a_gy$[slsel_name],$[slsel_loggrd].ty,
	      $[slsel_loggrd].yft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gy$[slsel_name] = a_gy$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].ty;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_y$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE gy$[slsel_name]a = INITPULSE;
  WF_PULSE gy$[slsel_name]  = INITPULSE;
  WF_PULSE gy$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gy$[slsel_name]a,"gy$[slsel_name]a");
    pulsename(&gy$[slsel_name],"gy$[slsel_name]");
    pulsename(&gy$[slsel_name]d,"gy$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].ybeta;
    createramp(&gy$[slsel_name]a,YGRAD,pw_gy$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gy$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gy$[slsel_name]a,(LONG)($[slsel_pos]-pw_gy$[slsel_name]a),
		pw_gy$[slsel_name]a,ia_gy$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gy$[slsel_name],YGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gy$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gy$[slsel_name],(LONG)($[slsel_pos]),
			pw_gy$[slsel_name],ia_gy$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gy$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gy$[slsel_name], grad_z$[slsel_name]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gy$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gy$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gy$[slsel_name], (int)0, res_gy$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gy$[slsel_name],YGRAD, 
			  res_gy$[slsel_name], grad_z$[slsel_name]);
	    createinstr(&gy$[slsel_name],(LONG)($[slsel_pos]),
			pw_gy$[slsel_name],ia_gy$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gy$[slsel_name],YGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gy$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gy$[slsel_name],ia_gy$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gy$[slsel_name]d,YGRAD,pw_gy$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gy$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gy$[slsel_name]d,(LONG)($[slsel_pos]+pw_gy$[slsel_name]),
		pw_gy$[slsel_name]d,ia_gy$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure we have a value for createsinc */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,
		   &gy$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], rf_$[slsel_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name],rf_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gy$[slsel_name],&gy$[slsel_name]a,
		   &gy$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
/* changed res_$ from short to int YH */
SLICESELZEXT(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zrt,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zft,(int)$[slsel_define])
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
    
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gz$[slsel_name],ZGRAD, 
		res_gz$[slsel_name],grad_z$[slsel_name]);
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gz$[slsel_name],(long)($[slsel_pos]),
		pw_gz$[slsel_name],ia_gz$[slsel_name]);
    
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1,
	    res_$[slsel_name],rf_$[slsel_name]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);

}
}
}

/*Meng: 11/2/95, added to take name string for external pulse*/
SLICESELZEXT_INV(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, slsel_define:1, slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(long)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zrt,(int)$[slsel_define])
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
              $[slsel_loggrd].zft,(int)$[slsel_define])
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
/*  EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";
*/
    
  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");
    
    /*  Now create the slice select trapezoid */
    pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
               MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(long)($[slsel_pos]-pw_gz$[slsel_name]a),
                pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	createextwave(&gz$[slsel_name],ZGRAD, 
		res_gz$[slsel_name],$[extern_grad_file]);
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
      }
    createinstr( &gz$[slsel_name],(long)($[slsel_pos]),
		pw_gz$[slsel_name],ia_gz$[slsel_name]);
    
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
               (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
                   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(long)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /* Now create the rf pulse */
    createextwave(&$[slsel_name],TYPRHO1,
	    res_$[slsel_name],$[extern_rf_file]);
    createinstr( &$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
		pw_$[slsel_name],ia_$[slsel_name]);
    linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
	       &gz$[slsel_name]d);
    addrfbits(&$[slsel_name],off_$[slsel_name],(long)($[slsel_pos]) + psd_rf_wait,
	      pw_$[slsel_name]);

}
}
}

/********************************************************************************
** To facilitate system safety, pulse and waveform scaling needs to be performed
** inside the SLICESELZEXT macro. This macro will scale the gradient and rfpulse
** waveforms given the position of the rfpulse in the rfpulse structure. The
** gradient scaling is performed by default with larger pw, or explicitly with
** stretchpulse using 1/2 the rfpulse resolution. This is done to ensure that
** the new gradient pw/res is multiple of GRAD_UPDATE_TIME (4usec) while
** RF_UPDATE_TIME(2usec). We assume the gradient resolution <= rfpulse resolution
** in the files.
*********************************************************************************/
/* 3/13/95 YI  added SLICESELZEXT2.
               changed data type of res_*  from short to int. */

SLICESELZEXT2(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
  EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
  EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]";

  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(LONG)($[slsel_pos]-pw_gz$[slsel_name]a),
		pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gz$[slsel_name],ZGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gz$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gz$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gz$[slsel_name], grad_z$[slsel_name]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gz$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gz$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gz$[slsel_name], (int)0, res_gz$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gz$[slsel_name],ZGRAD, 
			  res_gz$[slsel_name], grad_z$[slsel_name]);
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gz$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gz$[slsel_name],ia_gz$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(LONG)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure we have a value for createsinc */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], rf_$[slsel_name]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name],rf_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}

/**************************************************
 *  allowed string vars to be passed for filenames 
 * in SLICESELZEXT2 -AKG
 **************************************************/

SLICESELZEXT2STR(slsel_name, slsel_pos, slsel_dur, slsel_thk, slsel_flip,
	slsel_cycles:1.0,slsel_usegrad:1, res_gz,extern_grad_file,
	res_rf, extern_rf_file, rf_slot,slsel_define:1,slsel_loggrd){
cv:{
  float a_gz$[slsel_name];
  int ia_gz$[slsel_name];
  int pw_gz$[slsel_name]a;
  int pw_gz$[slsel_name]d;
  int pw_gz$[slsel_name];
  int res_gz$[slsel_name];
  float a_$[slsel_name];
  int ia_$[slsel_name];
  int pw_$[slsel_name];
  int res_$[slsel_name];
  float cyc_$[slsel_name];
  int off_$[slsel_name] = 0;
  float alpha_$[slsel_name] = 0.46;
  float thk_$[slsel_name];
  float gscale_$[slsel_name] = 1.0;
  float flip_$[slsel_name];
}
insert: cvinit =>{
  flip_$[slsel_name] = $[slsel_flip];
  a_$[slsel_name] = flip_$[slsel_name]/180;
  pw_gz$[slsel_name] = $[slsel_dur];
  res_gz$[slsel_name] = $[res_gz];
  res_$[slsel_name] = $[res_rf];
  pw_$[slsel_name] = $[slsel_dur];
  cyc_$[slsel_name] = $[slsel_cycles];
  thk_$[slsel_name] = $[slsel_thk];
}
insert: predownload => {
  if (ampslice(&a_gz$[slsel_name],(LONG)(4000000*cyc_$[slsel_name]/
					 pw_$[slsel_name]),
	       (float)thk_$[slsel_name],(float)gscale_$[slsel_name],
	       (int)$[slsel_define]) == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]a,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zrt,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
  if (optramp(&pw_gz$[slsel_name]d,a_gz$[slsel_name],$[slsel_loggrd].tz,
	      $[slsel_loggrd].zft,(int)$[slsel_define]) 
      == FAILURE) return FAILURE;
 
  ia_gz$[slsel_name] = a_gz$[slsel_name] * MAX_PG_IAMP/$[slsel_loggrd].tz;
  ia_$[slsel_name] = a_$[slsel_name] * MAX_PG_IAMP;

}
var:{
/* 
   EXTERN_FILENAME grad_z$[slsel_name]= "$[extern_grad_file]";
   EXTERN_FILENAME rf_$[slsel_name] = "$[extern_rf_file]"; 
*/

  WF_PULSE gz$[slsel_name]a = INITPULSE;
  WF_PULSE gz$[slsel_name]  = INITPULSE;
  WF_PULSE gz$[slsel_name]d = INITPULSE;
  WF_PULSE $[slsel_name] = INITPULSE;
}

subst:{
  {
    /* First create the pulses */
    pulsename(&gz$[slsel_name]a,"gz$[slsel_name]a");
    pulsename(&gz$[slsel_name],"gz$[slsel_name]");
    pulsename(&gz$[slsel_name]d,"gz$[slsel_name]d");
    pulsename(&$[slsel_name],"$[slsel_name]");

    /*  Now create the slice select trapezoid */
	pg_beta = $[slsel_loggrd].zbeta;
    createramp(&gz$[slsel_name]a,ZGRAD,pw_gz$[slsel_name]a,(short)0,
	       MAX_PG_WAMP,(short)(maxGradRes*(pw_gz$[slsel_name]a/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]a,(LONG)($[slsel_pos]-pw_gz$[slsel_name]a),
		pw_gz$[slsel_name]a,ia_gz$[slsel_name]);
    if ( $[slsel_usegrad] == PLAY_GFILE)
      {
	/*********************************************************************** 
	 ** Now create the waveform & perform required system safety checks
	 ** create a temporary buffer to modify gradient data using createreserve. Here
	 ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the waveform and
	 ** copy stretched data into permanent waveform memory. It is important to
	 ** to have temp buffer have new resolution size waveform memory.
	 ************************************************************************/
	if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
	  {
	    createreserve(&gz$[slsel_name],ZGRAD,rfpulseInfo[$[rf_slot]].newres/2);
	    /********************************************************************* 
	     * Change pulse type to external createreserve zero fills resolution
	     * number of points in waveform memory for use.
	     ********************************************************************/
	    gz$[slsel_name].type = TYPEXTERNAL;
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	    /* Scale the pulse, and then move to the reserved memory */
	    temp_wave_space = (short *)AllocNode(res_gz$[slsel_name]*sizeof(short));
	    uextwave(temp_wave_space, res_gz$[slsel_name], $[extern_grad_file]);
	    wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres/2*sizeof(short));
	    stretchpulse((int)res_gz$[slsel_name],(int)rfpulseInfo[$[rf_slot]].newres/2,
			 temp_wave_space,wave_space);
	    res_gz$[slsel_name] = rfpulseInfo[$[rf_slot]].newres/2;
	    /* Copy over original pulse data */
	    movewaveimm(wave_space, &gz$[slsel_name], (int)0, res_gz$[slsel_name], TOHARDWARE);
	    FreeNode(wave_space);
	    FreeNode(temp_wave_space);
	  }
	else
	  {
	    createextwave(&gz$[slsel_name],ZGRAD, 
			  res_gz$[slsel_name], $[extern_grad_file]);
	    createinstr(&gz$[slsel_name],(LONG)($[slsel_pos]),
			pw_gz$[slsel_name],ia_gz$[slsel_name]);
	  }
      }
    else
      {
	createconst(&gz$[slsel_name],ZGRAD, pw_$[slsel_name],MAX_PG_WAMP);
	createinstr( &gz$[slsel_name],(LONG)($[slsel_pos]),
		    pw_gz$[slsel_name],ia_gz$[slsel_name]);
      }
    /* Decay ramp */
    createramp(&gz$[slsel_name]d,ZGRAD,pw_gz$[slsel_name]d,MAX_PG_WAMP,
	       (short)0,(short)(maxGradRes*(pw_gz$[slsel_name]d/
		   GRAD_UPDATE_TIME)),pg_beta);
    createinstr( &gz$[slsel_name]d,(LONG)($[slsel_pos]+pw_gz$[slsel_name]),
		pw_gz$[slsel_name]d,ia_gz$[slsel_name]);
    
    /*********************************************************************** 
    ** Now create the rf pulse & perform required system safety checks
    ** create a temporary buffer to modify rfpulse data using createsinc. Here
    ** the values of cyc_rf and alpha_rf are irrelevant. Stretch the pulse and
    ** copy stretched data into permanent waveform memory. It is important to
    ** to have temp buffer have new resolution size waveform memory.
    ************************************************************************/
    if (rfpulseInfo[$[rf_slot]].change==PSD_ON)
      {
	cyc_$[slsel_name] = 1.0; /* Make sure we have a value for createsinc */
	createsinc(&$[slsel_name],TYPRHO1,rfpulseInfo[$[rf_slot]].newres,
		   MAX_PG_WAMP,cyc_$[slsel_name],alpha_$[slsel_name]);
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);

	/* Create some RHO waveform space, scale the pulse, and then move
	 * the local memory to the reserved RHO memory, and set pulsepointers
	 * to new stretched pulse
	 */
	temp_wave_space = (short *)AllocNode(res_$[slsel_name]*sizeof(short));
	uextwave(temp_wave_space, res_$[slsel_name], $[extern_rf_file]);
	wave_space = (short *)AllocNode(rfpulseInfo[$[rf_slot]].newres*sizeof(short));
	stretchpulse((int)res_$[slsel_name],rfpulseInfo[$[rf_slot]].newres,
		     temp_wave_space,wave_space);
	res_$[slsel_name] = rfpulseInfo[$[rf_slot]].newres;
        /* Copy over original pulse data */
	movewaveimm(wave_space, &$[slsel_name], (int)0, res_$[slsel_name], TOHARDWARE);
	FreeNode(wave_space);
	FreeNode(temp_wave_space);
      }
    else
      {
	/* No rf scaling required. Use createextwave to read pulse 
	 * and move to HW 
	 */
	createextwave(&$[slsel_name],TYPRHO1,
		      res_$[slsel_name], $[extern_rf_file] );
	createinstr(&$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		    pw_$[slsel_name],ia_$[slsel_name]);
	linkpulses(4,&$[slsel_name],&gz$[slsel_name],&gz$[slsel_name]a,
		   &gz$[slsel_name]d);
	addrfbits(&$[slsel_name],off_$[slsel_name],(LONG)($[slsel_pos]) + psd_rf_wait,
		  pw_$[slsel_name]);
      }
}
}
}





/* changed res_$ from short to int YH */
SPACESAVER(spsave_wgname, spsave_name, spsave_res:1){

cv:{
  int res_$[spsave_name];
}

insert: cvinit =>{
  res_$[spsave_name] = $[spsave_res];
}

insert: predownload => {
}

var:{
  WF_PULSE $[spsave_name] = INITPULSE;
}

subst:{
  {
    pulsename(&$[spsave_name],"$[spsave_name]");
    createreserve(&$[spsave_name],$[spsave_wgname],
		  res_$[spsave_name]);
  }
}
}

SSPPACKET(sspp_name,sspp_pos,sspp_dur,sspp_pack,sspp_val:0) {
cv:{
  int ia_$[sspp_name];
}
insert:  cvinit => {
  ia_$[sspp_name] = $[sspp_val];
}
var:{
  WF_PULSE $[sspp_name] = INITPULSE;
}

insert: predownload => {
}

subst:{
  {
    pulsename(&$[sspp_name],"$[sspp_name]");
    createbits(&$[sspp_name],TYPSSP,sizeof($[sspp_pack])/2,$[sspp_pack]);
    createinstr( &$[sspp_name],(long)($[sspp_pos]),
		$[sspp_dur],ia_$[sspp_name]);
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
THREEDIMDAB(threeddab_name, PosReadOut, threeddab_pos:DEFAULTPOS) {
var:{
  WF_PULSE $[threeddab_name] = INITPULSE;
}
insert: predownload => {
}

subst:{
  {
    pulsename(&$[threeddab_name],"$[threeddab_name]");
    create3dim(&$[threeddab_name],(long)($[PosReadOut]),(long)($[threeddab_pos]));
  }
}
}

/********************************************************
 * 08/01/95 Changed from SSPDS+DABDC to SSPTD+EDC - RJL
 * for CERD changed. DABDC no longer required. Since EDC
 * a global variable and not a #define constant, cannot be
 * located in variable initialization of pack.
 ********************************************************/
TNSON(tnson_name,tnson_pos) {
var:{
  WF_PULSE $[tnson_name] = INITPULSE;
  short $[tnson_name]_pack[4] = {0,SSPOC+DREG,SSPD+DCBL,SSPDS};
}
subst:{
  {
    $[tnson_name]_pack[0] = SSPDS+EDC;
    pulsename(&$[tnson_name],"$[tnson_name]");
    createbits(&$[tnson_name],TYPSSP,4,$[tnson_name]_pack);
    createinstr( &$[tnson_name],(LONG)($[tnson_pos]),4,0);
  }
}
}

/********************************************************
 * 08/01/95 Changed from SSPDS+DABDC to SSPTD+EDC - RJL
 * for CERD changed. DABDC no longer required.Since EDC
 * a global variable and not a #define constant, cannot be
 * located in variable initialization of pack.
 ********************************************************/
TNSOFF(tnsoff_name,tnsoff_pos) {
var:{
  WF_PULSE $[tnsoff_name] = INITPULSE;
  short $[tnsoff_name]_pack[4] = {0,SSPOC+DREG,SSPD,SSPDS};
}
subst:{
  {
    $[tnsoff_name]_pack[0] = SSPDS+EDC;
    pulsename(&$[tnsoff_name],"$[tnsoff_name]");
    createbits(&$[tnsoff_name],TYPSSP,4,$[tnsoff_name]_pack);
    createinstr( &$[tnsoff_name],(LONG)($[tnsoff_pos]),4,0);
  }
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
TRAPEZOID(trp_wgname,trp_name,trp_pos,trp_area,trp_define:1,trp_loggrd) {

cv:{
  float a_$[trp_name];
  int ia_$[trp_name];
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
}

insert: cvinit => {
}
insert: predownload => {
{
  float target;
  int rtime, ftime;

  gettarget(&target, $[trp_wgname],&$[trp_loggrd]);
  if ($[trp_define] == TYPDEF) {
        getramptime(&rtime, &ftime, $[trp_wgname],&$[trp_loggrd]);
        if (amppwgrad((float)($[trp_area]),target, 0.0, 0.0, rtime,
                                  MIN_PLATEAU_TIME,
                                  &a_$[trp_name], &pw_$[trp_name]a, &pw_$[trp_name],
                                  &pw_$[trp_name]d) == FAILURE)
          return FAILURE;
  }
  
  ia_$[trp_name] = (a_$[trp_name] / target) * MAX_PG_IAMP;
}
}

subst:{

  trapezoid($[trp_wgname], "$[trp_name]", &$[trp_name], &$[trp_name]a,
                        &$[trp_name]d, pw_$[trp_name], pw_$[trp_name]a, pw_$[trp_name]d,
                        ia_$[trp_name], 0, 0, 0, 0, $[trp_pos]-pw_$[trp_name]a, TRAP_ALL,
                        &$[trp_loggrd]);
}
}

/* merged 55 bch into vmx.  YH  10/13/94 */
TRAPEZOID2(trp_wgname,trp_name,trp_pos,trp_parts:TRAP_ALL,
         trp_start:0,trp_end:0,trp_scale:1.0,trp_loggrd) {

cv:{
  float a_$[trp_name];
  float a_$[trp_name]a;
  float a_$[trp_name]b;
  int ia_$[trp_name];
  int ia_$[trp_name]wa;
  int ia_$[trp_name]wb;
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
}
 
insert: cvinit => {
}
insert: predownload => {
 
{
   float target;

   gettarget(&target,$[trp_wgname],&$[trp_loggrd]);
   ia_$[trp_name] = ($[trp_scale] * a_$[trp_name] / target) *
                    MAX_PG_IAMP;
   ia_$[trp_name]wa = ($[trp_scale] * a_$[trp_name]a / target) *
                          MAX_PG_IAMP;
   ia_$[trp_name]wb = ($[trp_scale] * a_$[trp_name]b / target) *
                      MAX_PG_IAMP;
}
}

subst:{
    trapezoid($[trp_wgname],"$[trp_name]",
              &$[trp_name],&$[trp_name]a,&$[trp_name]d,
              pw_$[trp_name],pw_$[trp_name]a,pw_$[trp_name]d,
              ia_$[trp_name],ia_$[trp_name]wa,ia_$[trp_name]wb,
              $[trp_start],$[trp_end],$[trp_pos],$[trp_parts],
                          &$[trp_loggrd]);
}
}

WAIT(wait_wgname,wait_name,wait_pos,wait_dur) {
cv:{
  int pw_$[wait_name];
}
insert:  cvinit => {
  pw_$[wait_name] = $[wait_dur];
}
var:{
  WF_PULSE $[wait_name] = INITPULSE;
}
insert: predownload => {
}

subst:{
  {
    pulsename(&$[wait_name],"$[wait_name]");
    createconst(&$[wait_name],$[wait_wgname],pw_$[wait_name],(short)0); 
    createinstr( &$[wait_name],(long)($[wait_pos]),pw_$[wait_name],0);
  }
}
}


SINGLE_TRAP( trp_wgname, trp_name, trp_pos, trp_area:0.0, trp_scale:1.0,
             trp_define:TYPDEF, trp_parts:TRAP_ALL, trp_lead:0, trp_lead_pw:0,
             trp_loggrd )
{
  /*
    Built from MEMTRAP().         TKF 14-Nov-95.

    Create a Trapezoid completely in memory. This really burns memory
    but it only requires one update call. It was written to address 
    a performance issue in the ISI update for the fgre3d killer/rewinder. 
    The pulse is first created in user allocated memory with rsp 
    calls then moved into reserved waveform memory. The user memory is
    then freed.
    
    Supports sloped trapezoid. Special for phase encode.
    trp_lead = 0 no leading edge, 1=leading edge.
    trp_lead_pw = leading edge pulse width
    
    If this is not a sloped trapezoid, builds single normal
    trapezoid with waveform amplitude at max_pg_wamp.
	 */


cv:{
  float a_$[trp_name];
  float a_$[trp_name]a;
  float a_$[trp_name]b;
  int ia_$[trp_name];
  int ia_$[trp_name]wa;
  int ia_$[trp_name]wb;
  int pw_$[trp_name]a;
  int pw_$[trp_name]d;
  int pw_$[trp_name]f;    /* pulse width of leading edge */
  int pw_$[trp_name];
  int res_$[trp_name];
  int per_$[trp_name];
}
var:{
  WF_PULSE $[trp_name]a = INITPULSE;
  WF_PULSE $[trp_name] = INITPULSE;
  WF_PULSE $[trp_name]d = INITPULSE;
  s16 *$[trp_name]_mem;		/* temporary memory pointer */
  s16 $[trp_name]_indx;		/* indx into user memory */
}
insert: cvinit => {
}
insert: predownload => {
{
   float target;
   int rtime,ftime;

   gettarget(&target, $[trp_wgname], &$[trp_loggrd]);
   getramptime(&rtime,&ftime,$[trp_wgname], &$[trp_loggrd]);
   if ($[trp_define] == TYPDEF) {
     if (amppwgrad((float)($[trp_area]),target,0.0,0.0,rtime,MIN_PLATEAU_TIME,
				 &a_$[trp_name], &pw_$[trp_name]a, &pw_$[trp_name],
				 &pw_$[trp_name]d) == FAILURE) return FAILURE;
   }
   if ($[trp_parts] & TRAP_SLOPED)
     {
       ia_$[trp_name] = ($[trp_scale] * a_$[trp_name] / target) * MAX_PG_IAMP;
       ia_$[trp_name]wa = ($[trp_scale] * a_$[trp_name]a / target) * MAX_PG_IAMP;
       ia_$[trp_name]wb = ($[trp_scale] * a_$[trp_name]b / target) * MAX_PG_IAMP;
     }
   else  /* standard trapezoid */
     {
       ia_$[trp_name] = (a_$[trp_name] / target) * MAX_PG_IAMP;
       ia_$[trp_name]wa =  MAX_PG_WAMP;
       ia_$[trp_name]wb = MAX_PG_WAMP;
     }

   if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2) ||
       ($[trp_wgname]==TYPTHETA)||($[trp_wgname]==TYPOMEGA))
     {				/* Determine min period */
       per_$[trp_name] = (RF_UPDATE_TIME); 
     }
   else
     {
       per_$[trp_name] = (GRAD_UPDATE_TIME);
     }

   /* set leading edge pulse width */
   if ($[trp_lead] != 0)
     pw_$[trp_name]f = IMax(2,GRAD_UPDATE_TIME,$[trp_lead_pw]);
   else
     pw_$[trp_name]f = 0;

   if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2) ||
       ($[trp_wgname]==TYPTHETA)||($[trp_wgname]==TYPOMEGA))
     pw_$[trp_name] = 0;    /* no need for leading edge if rf */

   res_$[trp_name] =		/* Find resolution */
     (pw_$[trp_name]f + pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d)/
       per_$[trp_name];
}
}
subst:{
    {
#ifdef IPG
        /* Allocate user memory */
        $[trp_name]_mem = (s16 *)AllocNode( res_$[trp_name]*sizeof(s16));
        $[trp_name]_indx = 0;

        getbeta(&pg_beta, $[trp_wgname], &$[trp_loggrd]);

        /* leading edge of zeros */
        if (($[trp_lead] != 0) && (pw_$[trp_name]f != 0))
        {
            uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
                   (pw_$[trp_name]f/per_$[trp_name]),
                   (short)0, (short)0, pg_beta );
            /* Clear EOW */
            $[trp_name]_indx = ( pw_$[trp_name]f / per_$[trp_name] );
            $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
        }
        /* Up ramp */
        uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
               (pw_$[trp_name]a/per_$[trp_name]),
               (short) 0, ia_$[trp_name]wa , pg_beta);
        /* Clear EOW */
        $[trp_name]_indx = ( (pw_$[trp_name]a + pw_$[trp_name]f) / per_$[trp_name] );
        $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
        /* Top const */
        uramp((&$[trp_name]_mem[$[trp_name]_indx]),
              (pw_$[trp_name]/per_$[trp_name]),
              ia_$[trp_name]wa, ia_$[trp_name]wb, pg_beta);
        /* Clear EOW */
        $[trp_name]_indx = ( (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]f ) / per_$[trp_name] );
        $[trp_name]_mem[$[trp_name]_indx-1] &= ~WEOS_BIT;
        /* Decay Ramp */
        uramp( (&$[trp_name]_mem[$[trp_name]_indx]),
               (pw_$[trp_name]d/per_$[trp_name]),
               ia_$[trp_name]wb, (short) 0, pg_beta );

        /* Create pulse and memory */
        pulsename( &$[trp_name], "$[trp_name]" );
        createreserve( &$[trp_name], $[trp_wgname], res_$[trp_name] );
        createinstr( &$[trp_name],(LONG)($[trp_pos]-pw_$[trp_name]a - 
                                         pw_$[trp_name]f),
                     (pw_$[trp_name]f + pw_$[trp_name]a + 
                      pw_$[trp_name] + pw_$[trp_name]d), 
                     ia_$[trp_name] );
        /* Move user pulse into waveform mem */
        $[trp_name]_mem[res_$[trp_name]-1] |= WEOS_BIT;  
        movewaveimm($[trp_name]_mem, &$[trp_name], 
                    (int)0, res_$[trp_name], TOHARDWARE);
        /* Free user memory */
        FreeNode( $[trp_name]_mem );
        if (($[trp_wgname]==TYPRHO1)||($[trp_wgname]==TYPRHO2))
        {				/* Add rf control bits if rf pulse */
            addrfbits(&$[trp_name],0,(LONG)($[trp_pos]),
                      (pw_$[trp_name]a + pw_$[trp_name] + pw_$[trp_name]d));
        }
#else /* !IPG */
        /* When the SINGLE_TRAP macro is expanded on the Host, we want a real
           trapezoid (a TRAPEZOID2) to be created instead. Note that the start
           and end amplitudes are not provided as arguments to this macro and
           are assumed to be zero. Also, the position of the trapezoid does
           not include the attack and leading parts. This is the same thing 
           that is done in the uramp() calls above. - GFN - 12/Aug/1998 */
        trapezoid( $[trp_wgname], "$[trp_name]",
                   &$[trp_name], &$[trp_name]a, &$[trp_name]d,
                   pw_$[trp_name], pw_$[trp_name]a, pw_$[trp_name]d,
                   ia_$[trp_name], ia_$[trp_name]wa, ia_$[trp_name]wb,
                   0 /* trp_start */, 0 /* trp_end */,
                   (LONG)($[trp_pos] - pw_$[trp_name]a - pw_$[trp_name]f),
                   $[trp_parts], &$[trp_loggrd] );
#endif /* IPG */
    }
}
}

/* This macro sets up the proper SSP control words that tells the
   CERD to reroute the data from the VSB bus to the XD bus. This is
   used to send data to the SPU.
*/
XDCNTRL(spu_pack_name, spu_pack_pos){
var:{
  WF_PULSE $[spu_pack_name] = INITPULSE;
  short $[spu_pack_name]_bits[PASS_LENGTH];
}
insert: predownload => {
}
insert: cvinit => {
}
subst:{
  {
    $[spu_pack_name]_bits[0] = SSPDS + DABDC;
    $[spu_pack_name]_bits[1] = SSPOC + DPASS;
    $[spu_pack_name]_bits[2] = SSPD + 0x10;
    /* Initialize to normal routing of data */
    $[spu_pack_name]_bits[3] = SSPD;
    $[spu_pack_name]_bits[4] = SSPDS;
    $[spu_pack_name]_bits[5] = SSPOC;
    $[spu_pack_name]_bits[6] = SSPDS;

    pulsename(&$[spu_pack_name],"$[spu_pack_name]");

    createbits((WF_PULSE *)&$[spu_pack_name], (WF_PROCESSOR)TYPSSP,
        (SHORT)pass_length, (SHORT *)$[spu_pack_name]_bits);

    createinstr((WF_PULSE *)&$[spu_pack_name], (LONG) $[spu_pack_pos],
        (LONG)pass_length,0L);

    $[spu_pack_name].tag = SSPPASS;
 }
}
}


@reqcv
/* *************************************************
   REQUIRED CVS
   ************************************************ */

/* ****************************
   Patient/Study Parameters 
   ************************** */
float opweight = 50 with {0, 159, 50, VISONLY, "Patient weight in Kg.",};

/* ****************************
   Patient Position Parameters 
   ************************** */
int opcoil = PSD_HEAD with {1,3,PSD_HEAD, VISONLY, 
			  "Coil Type: 1=HEAD, 2=BODY, 3=SURFACE.","Invalid coil type selected.",};

int opentry = 1 with {1,2,1,VISONLY, 
			"Patient Entry: 1=Head First, 2= Feet First.",};

int oppos = 1 with {1,4,1,VISONLY,
		      "Patient Position: 1=Supine, 2=Prone, 3=Left Decub, 4= Right Decub.",};

/* ************************** 
   Imaging Parameter CVs 
   *************************** */
int oppseq = 1 with {1,17,1,VISONLY,
		       "Pulse Sequence: SE GE IR SSFP SPGR TOF PC TOFSP PCSP PROBES PROBEP PRESSCSI STEAMCSI FIDCSI ECHOCSI SPINECHO 3PLANELOC.",};

int opcgate = 0 with {0,2,0, VIS,
			"Cardiac Gating Flag: 0=No gating, 1=Cardiac, 2= Perp. gate.",};

int opexor = 0 with {0,1,0, INVIS, "Exorcist Flag",};

int opfcomp = 0 with {0,1,0, INVIS, "Flow Comp Flag",};

int opplane = PSD_AXIAL with {1,5,PSD_AXIAL,VIS,
			    "Scan Plane: 1=axial, 2=sagittal, 3=coronal, 4=oblique, 5= 3plane .",};

int opgrx = 0 with {0,1,0,VISONLY,
		      "Graphic Rx: 0=off, 1= on",};
int opgrxroi = 0 with {0,1,0,VIS,
			   "Graphic ROI: 0=off, 1=on",
			   EM_PSD_OPGRXROI_INCOMPATIBLE};
int opobplane = PSD_AXIAL with {1,3,PSD_AXIAL, INVIS,
			      "Most like plane for obliques.",};
int opnopwrap = 0 with {0,1,0,VISONLY,
			  "No Phase Wrap. 0=off, 1=on.",};
int opimode = PSD_2D with {1,6,PSD_2D, VISONLY,
		    "Imaging Mode: 1=2D, 2= 3D, 3=CINE, 4=ANGIO, 5=SPECTRO, 6=3D MULTISLAB.",};
int opsat = 0 with {0,1,0, VISONLY,
		      "Saturation switch: 0=off, 1=on.",};
int opptsize = 2 with {2,4,2, VISONLY,
			 "2=16 bit data, 4=32 bit data.",};
int oppomp = 0 with {0,1,0,INVIS,
		       "0=no pomp, 1=pomp",};
int opscic = 0 with {0,1,0,INVIS,
			 "surface coil intensity correction: 1 if enabled.",};
int oprect = 0 with {0,1,0,INVIS,
		       "0=No rect. scan, 1=rect. scan.",};
int opsquare = 0 with {0,1,0,INVIS,
						 "0=No square pixel scan, 1=square pixel scan",};
int opvbw = 0 with {0,1,0,VISONLY,
		      "Variable Bandwidth Option.",};
int opblim = 0 with {0,1,0,INVIS,
			 "0=new memp,1=classic",};
int opfast = 0 with {0,1,0,VIS,
			 "FAST sequence selection: 0=off, 1=on",
			 EM_PSD_OPFAST_INCOMPATIBLE};
int opcs = 0 with {0,1,0,VISONLY,
		       "Improved RF pulse switch: 0=off, 1=on.",
					   EM_PSD_CS_2D_SPIN_ECHO_ONLY};
int opdeprep = 0 with {0,0,0,VIS,
			   "DE prep pulses: 0=off, 1=on",
			   EM_PSD_OPDEPREP_INCOMPATIBLE};
int opirprep = 0 with {0,0,0,VIS,
			   "IR prep pulses: 0=off, 1=on",
			   EM_PSD_OPIRPREP_INCOMPATIBLE};
int opmph = 0 with {0,0,0,VIS,
			"Multi-phase acq: 0=off, 1=on",
		      EM_PSD_OPMPH_INCOMPATIBLE};
int opautotr = 0 with {0, 1, 0, VIS,
                   "Flag for Auto Min TR mode - 1:on, 0:off",};
int opphcor = 0 with {0, 1, 0, VIS,
                   "Flag for Phase Correction - 1:on, 0:off",};
/* cvs for Faster sequence Multi-Phase option */
int opacqo = 1 with {0,1,1,VIS,
			 "Acq. mode: 0=interleaved, 1=sequential",};
int opfphases = PHASES_MIN with {PHASES_MIN,PHASES_MAX,PHASES_MIN,VIS,
   "Images per location in a FAST scan, range between 1 and 512",};
int opsldelay = 50ms with {50ms,20s,50ms,VIS,
			     "Delay(ms) after acq.",};

int opmt = 0 with {0,1,0,VIS,
			 "Magnetization Transfer selection: 0=off, 1=on",
			 EM_PSD_MT_INCOMPATIBLE};

/* *****************
   Saturation CVs 
   **************** */
int opsatx = 0 with {0,4,0,VIS,
		       "Spatial pre-sat in logical X direction: 0=off, 1=negative pre-sat only, 2=pos. pre-sat only, 3=both.",};

int opsaty = 0 with {0,4,0,VIS,
		       "Spatial pre-sat in logical Y direction: 0=off, 1=negative pre-sat only, 2=pos. pre-sat only, 3=both.",};

int opsatz = 0 with {0,4,0,VIS,
		       "Spatial pre-sat in logical Z direction: 0=off, 1=negative pre-sat only, 2=pos. pre-sat only, 3=both.",};

float opsatxloc1 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified right sat location in mm.",};
float opsatxloc2 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified left sat location in mm.",};
float opsatyloc1 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified anterior sat location in mm.",};
float opsatyloc2 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified posterior sat location in mm.",};
float opsatzloc1 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified superior sat location in mm.",};
float opsatzloc2 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified inferior sat location in mm.",};

float opsatxthick = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
			       "User specified logical X Sat thickness.",};
float opsatythick = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
			       "User specified logical Y Sat thickness.",};
float opsatzthick = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
			       "User specified logical Z Sat thickness.",};

int opsatmask = 0 with {0,64,0,INVIS,
			  "Bitmask for SAT in the FOV.",};
int opfat = 0 with {0,1,0,VISONLY,
		      "Fat pre-saturation: 0=off,1=on.",};
int opwater = 0 with {0,1,0,VISONLY,
		      "Water pre-saturation: 0=off,1=on.",};
int opccsat = 0 with {0,1,0,INVIS,
			"1 if concat sat is on",};

/**********************************************
 These are for graphic sats.
***********************************************/
int opexsatmask = 0  with {0,64,0,INVIS,
						"Bitmask, for explicit sat bands.",};
float opexsathick1 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
                      "User specified thickness in mm for explicit Sat 1",};
float opexsathick2 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
                      "User specified thickness in mm for explicit Sat 2",};
float opexsathick3 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
                      "User specified thickness in mm for explicit Sat 3",};
float opexsathick4 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
                      "User specified thickness in mm for explicit Sat 4",};
float opexsathick5 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
                      "User specified thickness in mm for explicit Sat 5",};
float opexsathick6 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
                      "User specified thickness in mm for explicit Sat 6",};

float opexsatloc1 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified location in mm for explicit Sat 1",};
float opexsatloc2 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified location in mm for explicit Sat 2",};
float opexsatloc3 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified location in mm for explicit Sat 3",};
float opexsatloc4 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified location in mm for explicit Sat 4",};
float opexsatloc5 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified location in mm for explicit Sat 5",};
float opexsatloc6 = 9999 with {MIN_SLOC,12000,9999,VIS,
				"User specified location in mm for explicit Sat 6",};

int opexsatparal = 0 with {0,7,0,INVIS,
                  "Bit mask to communicate parallel explicit sat bands.",};

/*
   The opexsatoff<> cvs are for future use when targeted sat pulses
   are implemented 
*/
int opexsatoff1 = 0 with {MIN_SLOC,12000,0,INVIS,
       				"Offset in mm for targeted explicit Sat 1.",};
int opexsatoff2 = 0 with {MIN_SLOC,12000,0,INVIS,
	       			"Offset in mm for targeted explicit Sat 2.",};
int opexsatoff3 = 0 with {MIN_SLOC,12000,0,INVIS,
	       			"Offset in mm for targeted explicit Sat 3.",};
int opexsatoff4 = 0 with {MIN_SLOC,12000,0,INVIS,
	       			"Offset in mm for targeted explicit Sat 4.",};
int opexsatoff5 = 0 with {MIN_SLOC,12000,0,INVIS,
	       			"Offset in mm for targeted explicit Sat 5.",};
int opexsatoff6 = 0 with {MIN_SLOC,12000,0,INVIS,
	       			"Offset in mm for targeted explicit Sat 6.",};
int opexsatlen1 = 480 with {80,640,480,INVIS,
	       			"Length in mm of targeted explicit Sat 1.",};
int opexsatlen2 = 480 with {80,640,480,INVIS,
	       			"Length in mm of targeted explicit Sat 2.",};
int opexsatlen3 = 480 with {80,640,480,INVIS,
	       			"Length in mm of targeted explicit Sat 3.",};
int opexsatlen4 = 480 with {80,640,480,INVIS,
	       			"Length in mm of targeted explicit Sat 4.",};
int opexsatlen5 = 480 with {80,640,480,INVIS,
	       			"Length in mm of targeted explicit Sat 5.",};
int opexsatlen6 = 480 with {80,640,480,INVIS,
	       			"Length in mm of targeted explicit Sat 6.",};
/* end of unused targeted sat cvs */

/* default sat band thicknesses */
float opdfsathick1 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
	       	       "User specified default Sat 1 thickness in mm.",};
float opdfsathick2 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
	       	       "User specified default Sat 2 thickness in mm.",};
float opdfsathick3 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
	       	       "User specified default Sat 3 thickness in mm.",};
float opdfsathick4 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
	       	       "User specified default Sat 4 thickness in mm.",};
float opdfsathick5 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
	       	       "User specified default Sat 5 thickness in mm.",};
float opdfsathick6 = 80 with {MIN_STHICK,MAX_STHICK,80,VIS,
	       	       "User specified default Sat 6 thickness in mm.",};

/* *****************
   Vascular CVs
   ***************** */
float opvenc = 50.0 with {50.0,4000,50.0,INVIS, " Velocity Encode in mm/sec",};
int opflaxx = 0 with {0,12,0,INVIS, "X grad flow encode",};
int opflaxy = 0 with {0,12,0,INVIS, "Y grad flow encode",};
int opflaxz = 0 with {0,12,0,INVIS, "Z grad flow encode",};
int opflaxall = 0 with {0,1,0,INVIS, "all axises encoded",};
int opproject = 0 with {0,2,0,VIS, "Type of projection image",};
int opcollapse = 1 with {0,1,1,VIS,
	"1: Do max-pixel collapse along slice axis, 0: Dont.",}; 
int oprlflow = 0 with {0,1,0, VIS, 
	"1: Create set of Right-Left flow images, 0: Dont.",};
int opapflow = 0 with {0,1,0, VIS, 
	"1: Create set of Anterior-Posterior flow images, 0: Dont.",};
int opsiflow = 0 with {0,1,0, VIS, 
	"1: Create set of Superior-Inferior flow images, 0: Dont.",};
int opmagc = 1 with {0,1,0, VIS, 
	"1: Create set of magnitude images, 0: Dont.",};
int opflrecon = 0 with {0,64,0,VIS,"Flow recon type.",};
int project = 0 with {0,2,0,VIS, "Type of projection image",};
int vas_ovrhd = 0 with {0,,0,INVIS, "Vascular collapse memory overhead",};
int slice_col = 1 with {0,1,1,VIS,
	"1: Do max-pixel collapse along slice axis, 0: Dont.",}; 
int phase_col = 0 with {0,1,0,VIS,
	 "1: Do max-pixel collapse along phase axis, 0: Dont.",};
int read_col = 0 with {0,1,0,VIS,
	 "1: Do max-pixel collapse along readout axis, 0: Dont.",};
int mag_mask = 1 with {0,1,1, VIS,
	 "1: Use magnitude weighting mask, 0: Dont use.",};
int phase_cor = 1 with {0,1,1, VIS, 
	"1: Phase correction enabled 0: No phase correction.",};
int extras = 0 with {0,1,0, VIS, 
	"1: Enable mag. and indiv. axis images, 0: Dont.",};
int mag_create = 1 with {0,1,0, VIS, 
	"1: Create set of magnitude images, 0: Dont.",};
int rl_flow = 0 with {0,1,0, VIS, 
	"1: Create set of Right-Left flow images, 0: Dont.",};
int ap_flow = 0 with {0,1,0, VIS, 
	"1: Create set of Anterior-Posterior flow images, 0: Dont.",};
int si_flow = 0 with {0,1,0, VIS, 
	"1: Create set of Superior-Inferior flow images, 0: Dont.",};
int imagenum = 1 with {0,5,0, VIS, "Total number of images per slice",};
int motsa_ovrhd = 0 with {0,,0,INVIS, "motsa memory overhead for intermediate storage of overlap images",};
int oprampdir = 0 with {-1,1,0,VIS, "Direction of the slab excitation ramp pulse. -1: negative ramp, 0: non-ramp, 1: positive ramp",};
int opfcaxis = 0 with {0,2,0,INVIS,"Flow comp axis: 1=freq, 2=slice.",};


/* **************
   Cardiac CVs 
   ************* */

int ophrate = 60 with {
    ECG_MIN, ECG_MAX, 60, VIS, "Heartrate in beats/min.",
    EM_PSD_HRATE_OUT_OF_RANGE
};
int oparr = 10 with {0,50,0,VIS,
		       "Arrythmia rejection ratio",};
int ophrep = 1 with {1,4,1,VIS,
		       "Number of heart beats per repetition",};

int optdel1 = 20ms with {MIN_TDEL1,MAX_TDEL1,20ms,INVIS,
  "Time of delay from trigger to center of first RF 90",};

int optseq = 1 with {,,,VIS,
		       "Inter-sequence time from scan",};

int opphases = 1 with {1,DATA_ACQ_MAX,1,VIS,
			  "Number of phases of the heart cycle to image",};

int opcardseq = 0 with {0,2,0,INVIS,
			  "0 = other, 1 = minimum, 2 = even",};

int opmphases = 0 with {0,1,0,INVIS,
 			    "0=single phase, 1=multiple phase",};

int oparrmon = 1 with {-10,10,1,VIS,
		       "Arrythmia rejection monitoring flag: 1 = yes, 0 = no",};

int opvps = 8 with {,,8,VIS,
		       "Views per segment",};

/* *******************
   Scan Timing CVs 
   ******************* */

int opetl = 8 with {1,256,8,VIS,
			"Echo Train Length in number of echoes",};

int opnecho = 1 with {NECHO_MIN, PSD_NECHO_MAX, 1, VIS,
			"Number of echoes",};

int opautote = 0 with {0,5,0,VIS,"Flag for Auto Min TE mode",};

int opte = 25ms with {TE_MIN,TE_MAX,25ms,VIS,
			"Echo time",};

int opte2 = 50ms with {TE2_MIN,TE_MAX,50ms,VIS,
			"Time for second echo",};
/* cv for Faster sequence TE selection */
int optefw = 0 with {0,2,0,VIS, 
			 "TE selection: 0 = Minimum TE, 1 = Fat/Water in phase, 2 = Fat/Water out of phase.",};

int opti = TI_MIN with {TI_MIN, TI_MAX, TI_MIN,VIS,
			"Inversion time",};
			 
int opirmode = SIRMODE with {0,1,0,INVIS,
			"Type of IR or GRASS/MPGR",};

int optr = 400ms with {TR_MIN,TR_MAX, 400ms, VIS,
			"Time of repetition",};

float opflip = 90 with {1,180,90,VIS,
			  "Flip angle for RF1 slice.",};

/* *********************
   Scanning Range CVs 
******************** */		

float opfov = FOV_MAX with {FOV_MIN,FOV_MAX,FOV_MAX,VIS,
			  "Field of view size in both the x and y direction",};

float opphasefov = 1 with {0,1,1,VIS,
		 "Fraction of the field of view size in the phase direction, 1=full",};

float opfreqfov = 1 with {0,2,1,VIS,
   "Fraction of the field of view size in the frequency direction, 1=full",};

int opslquant = 1 with {1,SLTAB_MAX,1,VIS,
			"Slice quantity",};

int opileave = 0 with {0,1,0,VISONLY,
			"This CV is set to 1 for INTerleaved slices, 0 otherwise",};

float opslthick = 5 with {MINTHICK,MAXTHICK,5,VIS,
			"Slice thickness in mm.",};
   
float opslspace = 10 with {-200,200,10,VIS,
			     "Slice gap in mm.",};

/* 0 is non coaxial
   1 is coaxial through isocenter
   2 is coaxial not through isocenter */

int opcoax = 1 with {0,2,0,INVIS,
			"Used to determine FOV for CFH",};

float opvthick = 320 with {0,MAXVTHICK,0,INVIS,
                     "Total slab thickness in mm.",};

int opvquant = 1 with {1,MAXVQUANT,1,INVIS,
			"The number of slabs for 3D",};

int opovl = 0 with {0,SLTAB_MAX,0,VIS,"The number of overlapping locations in a multi-slab 3D prescription",};

/* ***********************
   Graphic ROI CVs
   ********************** */


float oplenrl = 0 with {-PSD_GRXROI_LEN,PSD_GRXROI_LEN,0.0,VIS,
			  "Length of ROI in the RL direction in mm",};
float oplenap = 0 with {-PSD_GRXROI_LEN,PSD_GRXROI_LEN,0.0,VIS,
			  "Length of ROI in the AP direction in mm",};
float oplensi = 0 with {-PSD_GRXROI_LEN,PSD_GRXROI_LEN,0.0,VIS,
			  "Length of ROI in the SI direction in mm",};

float oplocrl = 0 with {-PSD_GRXROI_LEN,PSD_GRXROI_LEN,0.0,VIS,
			  "Location of the ROI in the RL direction in mm",};
float oplocap = 0 with {-PSD_GRXROI_LEN,PSD_GRXROI_LEN,0.0,VIS,
			  "Location of the ROI in the AP direction in mm",};
float oplocsi = 0 with {-PSD_GRXROI_LEN,PSD_GRXROI_LEN,0.0,VIS,
			  "Location of the ROI in the SI direction in mm",};

float oprlcsiis = 1 with {-PSD_COR,PSD_COR,1,VIS,
			  "Which logical board is RL direction 1=X,2=Y,3=Z",};
float opapcsiis = 2 with {-PSD_COR,PSD_COR,2,VIS,
			  "Which logical board is RL direction 1=X,2=Y,3=Z",};
float opsicsiis = 3 with {-PSD_COR,PSD_COR,3,VIS,
			  "Which logical board is RL direction 1=X,2=Y,3=Z",};



/* ***********************
   Acquisition Time CVs 
   ********************** */

int opxres = 256 with {256,512,256,VIS,
                     "X(frequency) resolution",};

int opyres = 128 with {128,1024,128,VIS,
                     "Y(phase) resolution",};

float opnex = 1 with {0,150,1,VIS,"Number of Excitations",};

int opslicecnt = 0 with {0,SLTAB_MAX,0,VIS, 
			   "Number of slices before pause.",};

int opspf = 0 with {0,1,0,VIS,
		      "Swap Phase and Frequency. 0 = no swap, 1 = swap",};

int opcfsel = 0 with {0,5,0,INVIS,
			"0=current, 1=mid, 2=water, 3=fat, 4=pk, 5=cent",};
/* oprbw is receive bw for echoes 2-4 for 1.5 T, receive bw for 1st echo
for 0.5 T */
float oprbw = 16.0 with {0,,16.0,VIS,
			"Receive BW in khz",};
float oprbw2 = 16.0 with {0,,16.0,VIS,
			"Receive BW for echoes 2-4 in kHz",};


/* *************
   Cine CVs 
   ************* */
int opchrate = 100 with {
    ECG_MIN, ECG_MAX, 100, VIS, "Heartrate in beats/min.",
    EM_PSD_HRATE_OUT_OF_RANGE
};
int opcphases = 1 with {1, MAX_CINE_PHASES,1,VIS,
			  "Number of cardiac phases for cine.",};
int opclocs = 1 with {1, MAX_CINE_SLICES,1,VIS,
                        "Locs/Acq for CINE",};

/* *******************
    Multi Coil CVs
   ******************* */
int opmctr = 0 with {0,,0,INVIS, "Bit mask for multi-coil T/R driver board configuration.",};
int opmultrecv = 0 with {0,1,0, INVIS, "flag for multicoil",};


/* *******************
    Spectroscopy CVs
   ******************* */
int specnuc = 1 with {1,129,1,VIS,"Current spectro nucleus.",};
int specpts = 256 with {256,16384,256,VIS,"Number of points per frame for spectro.",};
int specwidth = 2000 with {500,32000,2000,VIS,"Spectral width.",};
int specnavs = 1 with {1,2048,1,VIS,"Number of averages for spectro.",};
int specnex = 2 with {1,4096,2,VIS,"Number of excitations for spectro.",};
int specdwells = 1 with {0,4096,1,VIS,"Number of dwell periods for spectro.",};
int acquire_type = 1 with {0,3,1,VIS,"Type of acq:0=1stCERD_1H, 1=2nd_1H, 2=1st_MNS, 3=2nd_MNS",};

/* ********************
   Spectro Hardware 
   ******************** */
int pixmtband = AMP_ERBTEC with {1,3,AMP_ERBTEC,INVIS,"RF amplifier specification",};
int pibbandfilt = 0 with {0,2,0,INVIS, "o/p filter for broadband",};


/* *********************
   Autoshim CVs
   ********************* */
int asslquant = 1 with {0,3,1,INVIS,
			    "number of planes to image in autoshim",};
float asflip = 20 with {0,360,90,INVIS,
			  "flip angle for autoshim entrypoint",};
float asslthick = 10 with {0,,10,INVIS,
			    "slice thickness for autoshim entry point",};
int asxres = 256 with {0,,256,INVIS,
			   "x resolution for autoshim entry point",};
int asyres = 128 with {0,,128, INVIS,
			   "y resolution for autoshim entry point",};
int asbaseline = 8 with {0,,8,INVIS,
			     "baselines for autoshim",};
int asrhblank = 4 with {0,,4,INVIS,
			    "kissoff lines for autoshim",};
int asptsize = 4 with {2,4,4,INVIS,
			   "pt. size for autoshim",};

int opascalcfov = 0 with {0,0,0,VIS, "FOV for Localized Shim Calc",};

/* merged 55 bch into vmx.  YH  10/13/94 */
/* ***************************
    EPI CVs
   *************************** */

int opepi = 0 with {0, 0, 0, VIS,
				  "EPI flag: 0=off, 1=on.",EM_PSD_EPI_INCOMPATIBLE};

int optlrdrf = 0 with {0, 0, 0, VIS,
				  "Tailored RF flag: 0=off, 1=on.",EM_PSD_TLRDRF_INCOMPATIBLE};

int opnshots = 1 with {1, 1024, 1, VIS,
                                  "Number of shots",};

/* merged 55 bch into vmx.  YH  10/13/94 */
/* ***************************
   Resp Trig CVs
   *************************** */
int oprtcgate = 0 with {0,1,0,VIS,"Repiratory Trigger flag",};
int oprtrate = 12 with {3, ECG_MAX, 12, VIS,
				"Respiratory rate  in beats/min.",};

int oprtrep = 1 with {1,5,1,VIS,
				  "Number of breaths per repetition",};

int oprttdel1 = 20ms with {MIN_TDEL1,MAX_TDEL1,20ms,INVIS,
         "Time of delay from trigger to center of first RF 90",};
     
int oprttseq = 1 with {,,,VIS,
                                  "Respiratory Inter-sequence time from scan",};
 
int oprtcardseq = 0 with {0,2,0,INVIS,
                                 "0 = other, 1 = minimum, 2 = even",};
 
int oprtarr = 10 with {0,100,0,VIS,
				  "Respiratory Trigger window",};
 
int oprtpoint= 10 with {0,100,0,VIS,"Respiratroy trigger point",};

/* New imaging options...initially for spiral imaging only (NDG) */
int opssrf = 0 with {0,0,0,VIS,"Spectral-spatial RF", EM_PSD_SSRF_NOT_AVAILABLE};
int opt2prep = 0 with {0,0,0,VIS,"T2 Prep", EM_PSD_T2PREP_NOT_AVAILABLE};
int opspiral = 0 with {0, 0, 0, VIS,
				  "Spiral flag: 0=off, 1=on.",EM_PSD_SPIRAL_INCOMPATIBLE};

/* pi values for spiral */
int piresol = 0 with {0,1,0,VIS,"Flag for resolution in mm field",};
int pioverlap = 0 with {0,1,0,VIS,
			    "Will allow negative sl. spacing when 1",};
 
 
/* **********************
   Lx: FLAIR/FSE CV
   ********************** */
int opfulltrain = 0 with {0,0,0,VIS,"0 = split train, 1 = full train",EM_PSD_FULL_ECHO_TRAIN_NOT_SUPPORTED};

/* **********************
   Lx: FMPVAS/FGRE CVs
   ********************** */
int pi_neg_sp = 0 with {0,1,0,VIS,
			"0 = positive, 1 = negative slice spacing",};
float piisvaldef = 2 with {0,20,2,VIS,
			"default value for the slice overlap",};

/* **********************
   Clock Operation CVs 
   ********************** */
int pidmode = 0 with {0,3,0,INVIS, "0=normal, 1=cardiac, 2=pause, 3=fastcard",};
int piviews = 0 with {0,,0,INVIS,"number of views or reps needed for cardiac scan",};
int piclckcnt = 1 with {0,,1,INVIS,"number of seqs needed before view counter is decremented.",};
float avmintscan = 0 with {0,,1,INVIS,"scan time",};
int pitslice = 0 with {0,,,INVIS, "time for each slice in us",};
float pitscan = 0 with {0,,,INVIS, "time for console clock",};

/* **********************
   Image Creation CVs 
   ********************** */
int pisaveinter = 0 with {0,1,0,VIS,
			    " if 1 save intermediate images",};
int pivextras = 0 with {0,,0,VIS,
			  "number of extra (vascular) image files to create.",};
int pinecho = 0 with {0,,0,VIS,
         "Actual number of echoes for vascular image creation.",};

/* *****************************
   IPG Needs for Table Position 
   ***************************** */
float piscancenter = 0 with {,,,INVIS, " center of scan - used by HPC ",};

/* ******************
   Service CVs
   ***************** */
int pismode = 0 with {0,3,0,VIS,
                 "Service modes: 0=none,1=exciter,2=loopbk,3=exciter+loopbk",};


/* ******************
   Image header CVs
   ****************** */
int ihtr = TR_MIN with {TR_MIN,TR_MAX,0,INVIS,
		       "TR annonation for current image.",};
int ihti = 0 with {0,TI_MAX,0,INVIS,
		       "TI annotation for current image.",};
int ihtdel1 = MIN_TDEL1 with {MIN_TDEL1,MAX_TDEL1,0,INVIS,
			  "Delay from trigger to center of RF1 pulse.",};
float ihnex = 1 with {0,NEX_MAX,1,INVIS,
			"# of excitations for current image.",};
float ihflip = 90 with {0,180,90,INVIS,
 			  "flip angle for the current image.",};
int ihte1 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 1.",};
int ihte2 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 2.",};
int ihte3 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 3.",};
int ihte4 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 4.",};
int ihte5 = 0 with {0,2s,0,INVIS,
		        "TE annotation for echo 5.",};
int ihte6 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 6.",};
int ihte7 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 7.",};
int ihte8 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 8.",};
int ihte9 = 0 with {0,2s,0,INVIS,
		        "TE annotation for echo 9.",};
int ihte10 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 10.",};
int ihte11 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 11.",};
int ihte12 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 12.",};
int ihte13 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 13.",};
int ihte14 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 14.",};
int ihte15 = 0 with {0,2s,0,INVIS,
		        "TE annotation for echo 15.",};
int ihte16 = 0 with {0,2s,0,INVIS,
			"TE annotation for echo 16.",};

float ihvbw1 = 16.0 with {0.0,2s,16.0,INVIS,
                          "VBW annotation for echo 1.",};
float ihvbw2 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 2.",};
float ihvbw3 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 3.",};
float ihvbw4 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 4.",};
float ihvbw5 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 5.",};
float ihvbw6 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 6.",};
float ihvbw7 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 7.",};
float ihvbw8 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 8.",};
float ihvbw9 = 16.0 with {0.0,2s,16.0,INVIS,
			  "VBW annotation for echo 9.",};
float ihvbw10 = 16.0 with {0.0,2s,16.0,INVIS,
			   "VBW annotation for echo 10.",};
float ihvbw11 = 16.0 with {0.0,2s,16.0,INVIS,
			   "VBW annotation for echo 11.",};
float ihvbw12 = 16.0 with {0.0,2s,16.0,INVIS,
			   "VBW annotation for echo 12.",};
float ihvbw13 = 16.0 with {0.0,2s,16.0,INVIS,
			   "VBW annotation for echo 13.",};
float ihvbw14 = 16.0 with {0.0,2s,16.0,INVIS,
			   "VBW annotation for echo 14.",};
float ihvbw15 = 16.0 with {0.0,2s,16.0,INVIS,
			   "VBW annotation for echo 15.",};
float ihvbw16 = 16.0 with {0.0,2s,16,INVIS,
			   "VBW annotation for echo 16.",};

int ihnegscanspacing = 0 with {0,1,0,INVIS,
			"0 = sp, 1 = ov for slice spacing",};

int ihoffsetfreq = 1200 with {400,1600,1200,INVIS,
			"MT offset frequency (hz)",};

/* *******************
   Custom Scan Schema CVs
   ****************** */
int opuser_usage_tag = 0x00000000 with {0xFFFFFFFF,0x7FFFFFFF,0x00000000,
			INVIS,"User CV and data acq usage tag",};
int rhuser_usage_tag = 0x00000000 with {0xFFFFFFFF,0x7FFFFFFF,0x00000000,
			INVIS,"rhuser CV and data acq usage tag",};
int rhFillMapMSW = 0x00000000 with {0x00000000,0x0001FFFF,0x00000000,
			INVIS,"User CV and data acq fillmap MSW",};
int rhFillMapLSW = 0x00000000 with {0xFFFFFFFF,0x7FFFFFFF,0x00000000,
			INVIS,"User CV and data acq fillmap LSW",};

/* *******************
   Recon Header CVs
   ****************** */
int rhbline = 0 with {0,,0,INVIS,
			"# of baseline pairs for NEX=1",};
int rhblank = 4 with {0,,4,INVIS,
			"# of blank pixel lines",};
int rhnavs = 1 with {1,32767,1,INVIS,
		       "Number of averages",};
int rhnslices = 1 with {1,DATA_ACQ_MAX,1,INVIS,
			 "Number of slices*phases.",};
int rhnframes = 256 with {1,YRES_MAX,256,INVIS,
			    "# of recon frames.",};
int rhfrsize = 256 with {1,XRES_MAX,256,INVIS,
			   "# of complex sample pairs per view",};
int rhnecho = 1 with {1,PSD_NECHO_MAX,1,INVIS,
			"Number of echoes ",};

/* ********************************
   Bit patterns for rhtype 
   ------------------------------
   bit 0  Set if chopper data
   bit 1  Set if CINE
   bit 2  Set if SHIM
   bit 3  Set if GRASS
   bit 4  Set for fractional processing
   bit 5  Set for strip scan Y
   bit 6  Set for 3-D processing
   bit 7  Set if exorcist
   bit 8  Set if NPW
   bit 9  Set if NFW
   bit 10 Set if strip scan X.
   bit 12 No longer used.
   bit 13 Set if 3/4 nex.
   bit 14 Set if pomp
   ****************************** */
int rhtype = 0 with {0,,0,INVIS, 
		       "Type of processing for recon.",};
/* ********************************
   Bit patterns for rhtype1
   ------------------------------
   bit 0  Set if regular recon
   bit 1  Set if homodyne recon
   bit 2  Set if nex table per echo is required
   bit 3  Set if mulit-coil superframe
   bit 4  Set if 3D multi-slab
   bit 5 on, bit 6 off  Maximum intersity pixel collapse overlap processing
   bit 5 off, bit 6 on  Minimum intersity pixel collapse overlap processing
   bit 5 on, bit 6 on   Average intersity pixel collapse overlap processing
   bit 7  Set for "fast phase off" in phase-contrast scans
   bit 8  Set if automatic scan/pass detection scheme is enabled.  If set,
           then data acquisition will assert scan and pass packets based on
           frame counter limits.  These limits are set by:
               rhrefframes and rhrefframep for reference scan acquisitions
               rhscnframe and repasframe for other entry points (except
                 prescan)
           
  
   ******************************** */
int rhtype1 = 0 with {0,,0,INVIS,
			  "Type of processing, 0=regular, 1=homodyne",};


/* merged 55 bch into vmx.  YH  10/13/94 */
/* ******************************
   Bit patterns for rhformat
   -----------------------------
   bit 0 set if no grad warp is desired (1)
   bit 1 set if no fermi filtering is desired (2)
   bit 2 For 3D, set if RF is chopped Z-encode (4)
   bit 3 For 3D, set if RF is chopped on Y encode (8)
   bit 4 set if IIC (opscic == PSD_ON) (32)
   bit 5 set if epi dab packet is used (64)
   bit 11 set if row flip file (/usr/g/bin/rowflip.param) is used (2048)
   ********************************************* */
int rhformat = 0 with {0,,0,INVIS,
                         "Raw data format.",};
int rhptsize = 2 with {2,4,2,INVIS,
                         "Number of bytes per I or Q data",};
int rhnpomp = 1 with {1,2,1,INVIS,
                        "# of regular slices/POMP group",};

/* ******************************
   Bit patterns for rhrcctrl
   ------------------------------
   bit 0 set for magnitude images   ; RHRCMAG  = 1
   bit 1 set for phase images       ; RHRCPHS  = 2
   bit 2 set for I magnitude images ; RHRCIMAG = 4
   bit 3 set for Q magnitude images ; RHRCQMAG = 8
   bit 4 set for compressed images  ; RHRCCOMP = 16
   bit 7 set for raw image recon    ; RHRCRAW  = 128
   changed for 7.0 from 17 to 1..gp
   ********************************************* */
int rhrcctrl = 1 with {0,,17,INVIS,        /* 17 = RHRCMAG + RHRCCOMP */
              		"Recon image control",};

/* ******************************
   bit patterns for rhdacqctrl
   ----------------------------
   bit 0	0= NO_REC data, 1=RAW data
   bit 1	Set if even echo phase flip desired.
   bit 2	Set if odd echo phase flip desired.
   bit 3	Set if even echo frequency flip desired.
   bit 4	Set if odd echo frequency flip desired.
   bit 5	Set if RAW collection without DAB SSP packets is desired.
   bit 6	Set if RAW collection should wrap around to the top of the
		buffer if overflow occurs.
   bit 10       set if fcine echotrain data acq. mode is used.
                MRIge56094                RH_FCINE_ET = 1024
   bit 11       Set if passthrough data acq. mode is used.; 
                                          RH_PASS_THROUGH_CERD_FLAG = 2048
   ********************************************* */
int rhdacqctrl = 2 with {0,32767,2,INVIS,
                 	"Recon data acquisition control",};


/* ******************************
   bit patterns for rhexecctrl
   ------------------------------
   bit 0= 1	Set if Auto display desired
   bit 1= 2	Set if auto lock of raw/no_rec files desired
   bit 2= 4	Set if auto perm desired ( BAM memory not released )
   bit 3= 8	Set if images should be transferred to disk
   bit 4= 16	Set if images should be saved in BAM memory
   bit 5= 32	Don't use
   bit 6= 64	Set if intermediate multi coil images are to be saved
 * ********************************************** */
int rhexecctrl = 9 with {0,32767,9,VIS,
			"Recon exective control",};


/* *********************************
   bit patterns for FEEDER control
   ---------------------------------
   bit 0	0= feed DAB, 1= feed filters.
   bit 1	0= locked, 1= unlocked
   bit 2	0= see bit 1, 1= use algorithm
   bit 3	Set if timing simulation desired
 * ********************************************** */
int rhfdctrl = 0 with {0,32767,0,INVIS,
			"Feeder control bits",};


float rhxoff = 0 with {-512,512,0,INVIS,
			"Frequency offset for this image",};
float rhyoff = 0 with {-1024,1024,0,INVIS,
                        "Phase offset for this image",};
int rhrecon = 0 with {0,30000,0,INVIS,
                        "Alternate recon word",};
int rhdatacq = 0 with {0,100,0,INVIS,
			"Alternate data acquisition word",};
int rhvquant = 0 with {0,256,0,INVIS,
			"Number of 3D slabs",};		
int rhslblank = 2 with {0,256,2,INVIS,
			"Number of kissoff slice pairs",};
int rhhnover = 0 with {0,512,0,INVIS,
			"Number of half nex overscans",};
int rhoscans = 0 with {0,1024,0,INVIS,
			"Number of overscans",};
int rhddaover = 0 with {0,256,0,INVIS,
			"Number of half-nex overscans to throw away",};
float rhzeroph = 128.5 with {0,1025,0,INVIS,
			"Zero phase point",};
float rhalpha = 0.46 with {0,1,0.46,INVIS,
			"Alpha value for filter",};
float rhnwin = 0 with {0,256,0,INVIS,
			"Window width",};
float rhntran = 2 with {0,256,2,INVIS,
			"Transition width",};
float rhfermw = 10 with {0,,10,INVIS,
			"Fermi width",};
float rhfermr = 128 with {0,,128,INVIS,
                        "Fermi radius",};
float rhferme = 1 with {0,,1,INVIS,
                        "Fermi eccentricity",};
float rhclipmin = 0 with {-32767,32767,0,INVIS,
                        "Minimum image value",};
float rhclipmax = 16383 with {-32767,32767,16383,INVIS,
                        "Maximum image value",};
float rhdoffset = 0 with {,,0,INVIS,
                        "Gain offset after reconstruction",};
int rhudasave = 0 with {0,,0,INVIS,
			"Size of save area in TPS",};
int rhsspsave = 0 with {0,,0,INVIS,
                        "Size of ssp save area in TPS",};
float rhscalei = 1 with {0,1,0,INVIS,
                        "Recon scale factor for I",};
float rhscaleq = 1 with {0,1,0,INVIS,
                        "Recon scale factor for Q",}; 
int rhnpasses = 1 with {1,,1,INVIS,
			"Number of passes in this scan",};
int rhrawsize = 10000 with {1,,2000000,INVIS,
                        "Size of pass",};
int rhincrpass = 1 with {1,,256,INVIS,
			"Xth pass to increment",};
int rhinitpass = 1 with {1,,256,INVIS,
                        "Minimum # of passes in TPS",};
int rhmethod = 0 with {0,1,0,INVIS,
			"Recon method",};
int rhdaxres = 256 with {0,512,256,INVIS,
			"Points per frame collected",};
int rhdayres = 256 with {0,2049,256,INVIS,
                        "Frames per echo collected",};
int rhrcxres = 256 with {0,1024,256,INVIS,
                        "X transform size",};
int rhrcyres = 256 with {0,1024,256,INVIS,
                        "Y transform size",};
int rhimsize = 256 with {0,1024,256,INVIS,
			"Image size",};
float rhuser0  = 0 with {,,,INVIS,"User data acquisition variable  0",};
float rhuser1  = 0 with {,,,INVIS,"User data acquisition variable  1",};
float rhuser2  = 0 with {,,,INVIS,"User data acquisition variable  2",};
float rhuser3  = 0 with {,,,INVIS,"User data acquisition variable  3",};
float rhuser4  = 0 with {,,,INVIS,"User data acquisition variable  4",};
float rhuser5  = 0 with {,,,INVIS,"User data acquisition variable  5",};
float rhuser6  = 0 with {,,,INVIS,"User data acquisition variable  6",};
float rhuser7  = 0 with {,,,INVIS,"User data acquisition variable  7",};
float rhuser8  = 0 with {,,,INVIS,"User data acquisition variable  8",};
float rhuser9  = 0 with {,,,INVIS,"User data acquisition variable  9",};
float rhuser10 = 0 with {,,,INVIS,"User data acquisition variable 10",};
float rhuser11 = 0 with {,,,INVIS,"User data acquisition variable 11",};
float rhuser12 = 0 with {,,,INVIS,"User data acquisition variable 12",};
float rhuser13 = 0 with {,,,INVIS,"User data acquisition variable 13",};
float rhuser14 = 0 with {,,,INVIS,"User data acquisition variable 14",};
float rhuser15 = 0 with {,,,INVIS,"User data acquisition variable 15",};
float rhuser16 = 0 with {,,,INVIS,"User data acquisition variable 16",};
float rhuser17 = 0 with {,,,INVIS,"User data acquisition variable 17",};
float rhuser18 = 0 with {,,,INVIS,"User data acquisition variable 18",};
float rhuser19 = 0 with {,,,INVIS,"User data acquisition variable 19",};
float rhuser20 = 0 with {,,,INVIS,"User data acquisition variable 20",};
float rhuser21 = 0 with {,,,INVIS,"User data acquisition variable 21",};
float rhuser22 = 0 with {,,,INVIS,"User data acquisition variable 22",};
float rhuser23 = 0 with {,,,INVIS,"User data acquisition variable 23",};
float rhuser24 = 0 with {,,,INVIS,"User data acquisition variable 24",};
float rhuser25 = 0 with {,,,INVIS,"User data acquisition variable 25",};
float rhuser26 = 0 with {,,,INVIS,"User data acquisition variable 26",};
float rhuser27 = 0 with {,,,INVIS,"User data acquisition variable 27",};
float rhuser28 = 0 with {,,,INVIS,"User data acquisition variable 28",};
float rhuser29 = 0 with {,,,INVIS,"User data acquisition variable 29",};
float rhuser30 = 0 with {,,,INVIS,"User data acquisition variable 30",};
float rhuser31 = 0 with {,,,INVIS,"User data acquisition variable 31",};
float rhuser32 = 0 with {,,,INVIS,"User data acquisition variable 32",};
float rhuser33 = 0 with {,,,INVIS,"User data acquisition variable 33",};
float rhuser34 = 0 with {,,,INVIS,"User data acquisition variable 34",};
float rhuser35 = 0 with {,,,INVIS,"User data acquisition variable 35",};
float rhuser36 = 0 with {,,,INVIS,"User data acquisition variable 36",};
float rhuser37 = 0 with {,,,INVIS,"User data acquisition variable 37",};
float rhuser38 = 0 with {,,,INVIS,"User data acquisition variable 38",};
float rhuser39 = 0 with {,,,INVIS,"User data acquisition variable 39",};
float rhuser40 = 0 with {,,,INVIS,"User data acquisition variable 40",};
float rhuser41 = 0 with {,,,INVIS,"User data acquisition variable 41",};
float rhuser42 = 0 with {,,,INVIS,"User data acquisition variable 42",};
float rhuser43 = 0 with {,,,INVIS,"User data acquisition variable 43",};
float rhuser44 = 0 with {,,,INVIS,"User data acquisition variable 44",};
float rhuser45 = 0 with {,,,INVIS,"User data acquisition variable 45",};
float rhuser46 = 0 with {,,,INVIS,"User data acquisition variable 46",};
float rhuser47 = 0 with {,,,INVIS,"User data acquisition variable 47",};
float rhuser48 = 0 with {,,,INVIS,"User data acquisition variable 48",};

int rhdab0s = 0 with {0,15,0,INVIS,
			"Start receiver to poll",};
int rhdab0e = 0 with {0,15,0,INVIS,
                        "End receiver to poll",};
float rhctr = 1 with {0,,1,INVIS,
			"Cine TR in seconds",};
float rhcrrtime = 1 with {0,,1,INVIS,
			"Cine R-R interval in seconds",};
int rhcphases = 1 with {0,,1,INVIS,
			"Number of Cine cardiac phases",};
int rhovl = 0  with {0,SLTAB_MAX,0,INVIS,
			"Number of overlap slices on each interior side of a slab",};

/* **********************************
   Vascular Recon CVs 
   ********************************** */

/* **********************************
   Vascular Recon Types
   1: vascular
   2: phase contrast scan
   4: unused
   8: 2 set processing
   16: anti alias algorithm
   32: phase contrast bit 1
   64: phase contrast bit 2
   128: apply noise suppression mask
   256: display magnitude image
   512: display physical x location
   1024: display physical y location
   2048: display physical z location
   4096: collapse logical z
   8192: collapse logical x
   16384: collapse logical y
   32768: vinnie 1 slice, 2 set
   65536: vinnie 1 slice, 4 set
   131072: vinnie 2 slice, 2 set
   ****************************************** */
int rhvtype = 0 with {0,,0,INVIS,
			"Vascular recon type",};

float rhvenc = 0 with {,,0,INVIS,
			 "Recon header value for velocity encoding.",};
float rhvcoefxa = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefxb = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefxc = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefxd = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefya = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefyb = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefyc = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefyd = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefza = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefzb = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefzc = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};
float rhvcoefzd = 0 with {,,0,INVIS,
			    "Flow to phys translation factor for a phase contrast scan.",};

/* The following are flow to static translation for phase contrast 
   scans if the phase correction bits are set or noise suppression or display
   magnitude bits are set. */

float rhvmcoef1 = 0 with {0.0,1.0,0,INVIS,
			    "Flow to static translation for phase contrast.",};
float rhvmcoef2 = 0 with {0.0,1.0,0,INVIS,
			    "Flow to static translation for phase contrast.",};
float rhvmcoef3 = 0 with {0.0,1.0,0,INVIS,
			    "Flow to static translation for phase contrast.",};
float rhvmcoef4 = 0 with {0.0,1.0,0,INVIS,
			    "Flow to static translation for phase contrast.",};

/* *********************
   Asymmetric FOV cvs
   ********************* */
float rhphasescale = 1 with {0,2,0,INVIS,
						 "Recon phase scale factor for Asymmetric FOV",};

float rhfreqscale = 1 with {0,2,0,INVIS,
   "Future recon frequency scale factor for Asymmetric FOV",};

/* Raw image recon */
int rawmode = 0 with {0,1,0,VIS,"Raw image reconstruction: 0=off, 1=on.",};
							   
/************************/
/* Refernce Scan/EPI recon cvs */
/************************/

int rhileaves = 1 with {1, 512, 1, VIS,
                                  "Number of interleaves",};

int rhkydir = 0 with {0, 2, 0, VIS,
				  "Ky traversal direction:0=top-down,1=centric,2=bottom-up",};

int rhalt = 0 with {0, 3, 0, VIS,
                                  "Alt read sign:0=no,1=odd/evn,2=halves,3=pairs",};

int rhreps = 1 with {1, 256, 1, VIS,
                                  "Number of scan repetitions",};

int rhref = 1 with {0, 1, 1, VIS, "0=use old phase corr, 1=use new phase corr",};

/****************************************/
/* EPI Phase Correction recon header CVs */
/****************************************/

int rhpcthrespts = 2 with {2, 32, 2, VIS,
				  "Adj pts req'd for amp threshold calc",};
                  
int rhpcthrespct = 15 with {0, 100, 15, VIS,
                  "% of projection's peak magnitude for threshold calc",};
 
int rhpcdiscbeg = 0 with {0, 512, 0, VIS,
				  "Points discarded at beginning of post row FT array",};
 
int rhpcdiscmid = 0 with {0, 512, 0, VIS,
				  "Points discarded at middle of post row FT array",};
 
int rhpcdiscend = 0 with {0, 512, 0, VIS,
				  "Points discarded at end of post row FT array",};
 
int rhpcileave = 0 with {0, 2, 0, VIS,
  "Interleaves to use for correction: 0=all, 1=1st, 2=1st interpolated",};
 
int rhpcextcorr = 0 with {0, 1, 0, VIS,
				  "Ext pc file /usr/g/bin/pc.dat: 0=don't use, 1=use",};
 
int rhrefframes = 0 with {0, , 0, VIS,
				  "Total number of frames acquired for an entire REF scan",};
/* to avoid compiling error on IFCC   3/17/95 YI */
int rhpcsnore = 0 with {0, 1, 0, VIS,
                                  "SNORE processing switch for REF data: 0=off,1=on",};

                                     
int rhpcspacial = 0 with {0, 512, 0, VIS,
				  "PC space specificity: 0=use all, >=1 for one slice",};
 
int rhpctemporal = 0 with {0, 512, 0, VIS,
				  "PC temporal specificity: 0=use all, >=1 for one phase",};
 
float rhpcbestky = 64.0 with {1.0, 1024.0, 64.0, VIS,
				  "Best ky index for coefficient remap",};
 
int rhhdbestky = 0 with {0,512, 0, VIS, "Homodyne best ky",};
/* to avoid compiling error on IFCC   3/17/95 YI */
int rhpcinvft = 0 with {0, 1, 0, VIS,
        "Inverse row FT switch for post fix time domain image: 0=off, 1=on",};
 
int rhpcctrl = 0 with {0, 32768, 0, VIS,
        "Control for various phase correction tests",};
/* to avoid compiling error on IFCC   3/17/95 YI */
int rhpctest = 0 with {0, 1, 0, VIS,
        "Test mode control: 0=off, 1=msgs. to terminal/vectors to disk",};

int rhpcgraph = 0 with {0, 1, 0, VIS, "UNUSED",};

int rhpclin = 0 with {0, 2, 0, VIS, "Linear correction: 0=off,1=on",};
 
int rhpclinnorm = 0 with {0, 1, 0, VIS,
        "Linear corr norm. switch: 0=weight, 1=normalize",};
 
int rhpclinnpts = 0 with {0, 256, 0, VIS,
		"Linear correction fit points (for ord>=2)",};
 
int rhpclinorder = 2 with {0, 4, 0, VIS,
        "Linear fit order: 0=Ky spcfc;1=Kybest;2=line;3,4=poly",};
 
int rhpclinfitwt = 0 with {0, 0, 0, VIS,
        "Linear corr fit weight: 0=equal,1=via kybest,2=via mag",};
 
int rhpclinavg = 0 with {0, 1, 0, VIS,
        "Linear corr averaging for order=1: 0=off, 1=on",};
 
int rhpccon = 0 with {0, 1, 0, VIS, "Constant corr:0=off,1=on",};
 
int rhpcconnorm = 0 with {0, 1, 0, VIS,
        "Constant corr norm. switch: 0=weight, 1=normalize",};
 
int rhpcconnpts = 2 with {2, 256, 0, VIS, "Constant corr fit points",};
 
int rhpcconorder = 2 with {0, 4, 0, VIS,
        "Constant fit order: 0=vu spcfc;1=Kybest;2=line;3,4=poly",};
 
int rhpcconfitwt = 0 with {0, 0, 0, VIS,
        "Constant corr fit weight: 0=equal,1=via kybest,2=via mag",};
 
/****************************************/
/* VRGF recon header CVs */
/****************************************/
 
int rhvrgfxres = 128 with {1, XRES_MAX, 128, VIS,
                                  "VRGF final xres.",};
int rhvrgf = 0 with  {0, 16, 0, VIS,  "VRGF switch: 0=off, 1=on.",};

/****************************************/
/* Bandpass correction recon header CVs */
/****************************************/
 
int rhbp_corr = 0 with {0, 3, 0, VIS,
          "EPI bandpass correction:0=off,1=on,2=magnitude only,3=phase only.",};
 
float rhrecv_freq_s = 0.0 with {-500.0e3, 500.0e3, 0.0, VIS,
          "bandpass correction interpolation range starting frequency (Hz).",};
 
float rhrecv_freq_e = 0.0 with {-500.0e3, 500.0e3, 0.0, VIS,
          "bandpass correction interpolation range ending frequency (Hz).",};
 
int rhhniter = 0 with {0, 5, 0, VIS,
          "selects the type of homodyne reconstrution to be used: 0-I, 1-II.",};
 
int rhfast_rec = 0 with {0, 5, 0, VIS,
          "tells if the fast receiver is being used and its lpf setting.",};


/*************************************/
/* Spiral gridding recon related CVs */
/*************************************/
int rhgridcontrol = 0 with {0,65536,0,VIS, "Mask for gridding related controls.",};
int rhb0map = 0 with {0,2049,0,VIS,"B0 field inhomogeneity correction flag and B0 phase map size bitmask",};
int rhtediff = 0 with {0,32767,0,VIS, "TE delay between the two arms for phase map.",};
float rhradiusa = 0 with {0,100,0,VIS, "Inner trajectory part of a variable trajectory.",};
float rhradiusb = 0 with {0,100,0,VIS, "Outer trajectory part of a variable trajectory.",};
float rhmaxgrad = 0.0 with {,,0.0,VIS, "Maximum gradient based on FOV and BW.",};
float rhslewmax = 0.0 with {,,0.0,VIS, "Maximum slew rate used.",};
float rhscanfov = 0.0 with {0,480,0, VIS, "Scan FOV.in mm",};
float rhtsamp = 0.0 with {,,0.0,VIS, "Sampling time.",};
float rhdensityfactor = 0.0 with {,,0.0,VIS, "Density factor.",};
float rhdispfov = 0.0 with {0,480,0,VIS,"Display FOV.in mm",};
int rhmotioncomp = 0 with {0,1,0,VIS, "Flag for motion compensation (0=No, 1=Yes).",};

/* **********************
   op user CVs
   ********************* */
int pititle = 0 with {0,1,0,INVIS,"User Page Title",};
float opuser0  = 0 with {,,,INVIS,"User CV variable  0",};
float opuser1  = 0 with {,,,INVIS,"User CV variable  1",};
float opuser2  = 0 with {,,,INVIS,"User CV variable  2",};
float opuser3  = 0 with {,,,INVIS,"User CV variable  3",};
float opuser4  = 0 with {,,,INVIS,"User CV variable  4",};
float opuser5  = 0 with {,,,INVIS,"User CV variable  5",};
float opuser6  = 0 with {,,,INVIS,"User CV variable  6",};
float opuser7  = 0 with {,,,INVIS,"User CV variable  7",};
float opuser8  = 0 with {,,,INVIS,"User CV variable  8",};
float opuser9  = 0 with {,,,INVIS,"User CV variable  9",};
float opuser10 = 0 with {,,,INVIS,"User CV variable 10",};
float opuser11 = 0 with {,,,INVIS,"User CV variable 11",};
float opuser12 = 0 with {,,,INVIS,"User CV variable 12",};
float opuser13 = 0 with {,,,INVIS,"User CV variable 13",};
float opuser14 = 0 with {,,,INVIS,"User CV variable 14",};
float opuser15 = 0 with {,,,INVIS,"User CV variable 15",};
float opuser16 = 0 with {,,,INVIS,"User CV variable 16",};
float opuser17 = 0 with {,,,INVIS,"User CV variable 17",};
float opuser18 = 0 with {,,,INVIS,"User CV variable 18",};
float opuser19 = 0 with {,,,INVIS,"User CV variable 19",};
float opuser20 = 0 with {,,,INVIS,"User CV variable 20",};
float opuser21 = 0 with {,,,INVIS,"User CV variable 21",};
float opuser22 = 0 with {,,,INVIS,"User CV variable 22",};
float opuser23 = 0 with {,,,INVIS,"User CV variable 23",};
float opuser24 = 0 with {,,,INVIS,"User CV variable 24",};
float opuser25 = 0 with {,,,INVIS,"User CV variable 25",};
float opuser26 = 0 with {,,,INVIS,"User CV variable 26",};
float opuser27 = 0 with {,,,INVIS,"User CV variable 27",};
float opuser28 = 0 with {,,,INVIS,"User CV variable 28",};
float opuser29 = 0 with {,,,INVIS,"User CV variable 29",};
float opuser30 = 0 with {,,,INVIS,"User CV variable 30",};
float opuser31 = 0 with {,,,INVIS,"User CV variable 31",};
float opuser32 = 0 with {,,,INVIS,"User CV variable 32",};
float opuser33 = 0 with {,,,INVIS,"User CV variable 33",};
float opuser34 = 0 with {,,,INVIS,"User CV variable 34",};
float opuser35 = 0 with {,,,INVIS,"User CV variable 35",};
float opuser36 = 0 with {,,,INVIS,"User CV variable 36",};
float opuser37 = 0 with {,,,INVIS,"User CV variable 37",};
float opuser38 = 0 with {,,,INVIS,"User CV variable 38",};
float opuser39 = 0 with {,,,INVIS,"User CV variable 39",};
float opuser40 = 0 with {,,,INVIS,"User CV variable 40",};
float opuser41 = 0 with {,,,INVIS,"User CV variable 41",};
float opuser42 = 0 with {,,,INVIS,"User CV variable 42",};
float opuser43 = 0 with {,,,INVIS,"User CV variable 43",};
float opuser44 = 0 with {,,,INVIS,"User CV variable 44",};
float opuser45 = 0 with {,,,INVIS,"User CV variable 45",};
float opuser46 = 0 with {,,,INVIS,"User CV variable 46",};
float opuser47 = 0 with {,,,INVIS,"User CV variable 47",};
float opuser48 = 0 with {,,,INVIS,"User CV variable 48",};

/* *************************************************
   MORE REQUIRED CVS 
   ************************************************ */

int pishldctrl= PSD_OFF with {PSD_OFF,PSD_ON,PSD_OFF,VIS,
			"Shield cooler control CV. 0=Turn off for scan",};

int pinolr=PSD_OFF with {PSD_OFF,PSD_ON,PSD_OFF,VIS,
		"Turn off left-right shading fix. 0=fix on, 1=no fix",};

int pinoadc=PSD_OFF with {PSD_OFF,PSD_ON,PSD_OFF,VIS,
		"Turn off ADC correction. 0=correction on, 1=no fix",};

int pimixtime = 0 with {0,,,INVIS,"mixing time",};

int psd_board_type = 0 with {0,,,VIS,"type of transceiver",};

/* vmx 1/10/95 YI moved here from reqexport section */
int cfcoilres;      /* coil resistance, 1LSB = 16ohm */
int cftxgate0;      /* Indicates 0 degree transmit gate enable: 0=Disable,
		       1=Enable */
int cftxgate90;      /* Indicates 90 degree transmit gate enable: 0=Disable,
		       1=Enable */
int cfcoilportvu;    /* Indicates coil port voltage Upper Byte */
int cfcoilportvl;    /* Indicates coil port voltage Lower Byte */
int cfcoilbias;      /* Coil Bias select: 0=Disable, 1=Head, 2=Body,
			3=Surface */
int cfgradcoil = 2;  /* Indicate gradient coil type : 1:CRD 2:Roemer
                        101:HGC 102:Vectra 103:Permanent */
/* end vmx */

@reqexport
/* *************************************************************
 * reqexport
 *
 * The following are common variables between the PSD and the PSD
 * manager.  They are used primarily to communicate the values of
 * the advisory panel.
 * ************************************************************* */

/* Scan info table holds information filled in by
 * scan in prescribed order. Each entry holds the slice
 * location in mm from isocenter, the receive location of
 * each slice in mm, and the rotation matrix */

SCAN_INFO scan_info[SLTAB_MAX];

/* Data acquisition order table holds the pass and time order
 * within the pass of each phase. */

DATA_ACQ_ORDER data_acq_order[DATA_ACQ_MAX];

ENTRY_POINT_TABLE entry_point_table[ENTRY_POINT_MAX];

int *ihtdeltab;
int *ihtrtab;

/* Scan Timing Advisory Variables */

int avminnecho;
int avmaxnecho;
int avminte;
int avmaxte;
int avminte2;
int avmaxte2;
int avminti;
int avmaxti;
int avminbspti;   /* Minimum Blood Suppression TI */
int avmaxbspti;   /* Maximum Blood Suppression TI */
int avmintr;
int avmaxtr;

/* Cardiac Gating Advisory Variables */

int avmaxphases;
int avmintseq;
int avmintdel1; /* min cardiac delay */
int pitdel1;   /* recommended delay with SAT modules */

/* Scanning Range Advisory Variables */

float avminfov;
float avmaxfov;
int avminslquant;
int avmaxslquant;
int avmaxacqs;

/* Acquisition time Advisory Variables */

int avmaxyres;
int avmaxxres;

float avminrbw;  /* minimum bw in KHz (echoes 2-4 for 1.5T, echo 1 for 0.5T */
float avmaxrbw;  /* maximum bandwith in KHz (echoes 2-4 for 1.5 T, echo
				  one for 0.5T */
float avminrbw2; /* minimum bw in KHz (echoes 2-4, for 0.5T only) */
float avmaxrbw2; /* maximum bandwith in KHz (echoes 2-4, for 0.5T only) */



/* Vascular Velocity Encoding Advisory Panel Variables.
   Min and Max velocity encoding value in cm/sec */
float avminvenc;
float avmaxvenc;

/* Delay after acquisition.  Needed in cardiac routines */
int avminsldelay;		/* Minimum Delay after acquisition */
int avmaxsldelay;		/* Maximum Delay after acquisition */
int avminfphases;		/* Minimum Number of phases per locations */
int avmaxfphases;		/* Maximum Number of phases per locations */

/* Overlapping slices, in Motsa */
int avmaxovl; /* Maximum number of overlapping slices */

/* psd information variables */

int piimages = 1;

/* scanning range */
int pisatthick = 80;
int pisatthickx = 80;
int pisatthicky = 80;
int pisatthickz = 80;

int piautopause = 0;
int pislblank = 2;

/* cardiac gating */
int pitseq;
int piait;
int pietr;

/* Graphic ROI inquiry CVs */
int picsifov;			/* Field of view for CSI phase encoding */
int pirlcsi;			/* Number of phase encodes in the RL dir */
int piapcsi;			/* Number of phase encodes in the AP dir */
int pisicsi;			/* Number of phase encodes in the SI dir */
int piroigrx=PSD_OFF;		/* Whether or not to do Grx ROI */


/* advisory panel */
int piadvise = 0;
/* *************************************************
 * The following variables are read by Scan Rx to 
 * determine which advisory panel entries should be 
 * displayed.  
 * piadvmin and piadvmax are the bitmasks for respectively
 * displaying the min and max values for echos, TE, TE2,
 * TI, TR, FOV, receive bandwidth, and velocity encoding.
 * piadvtime is the bitmask for selectively displaying
 * the scan time, max. Locs/Acq, minimum # of acqs, and the
 * acquisition matrix.
 * piadvcard is the bitmask for selectively displaying the
 * cardiac adv. panel entries.  These entries are inter-sequence
 * delay, # of phases, effective TR, max # of scan locs, and
 * available image time.  It should be noted that these 
 * entries will never be displayed if cardiac gating is not 
 * selected.  
 * The bitmask position for each of these parameters is 
 * listed up above in the global section.
 * ************************************************* */

/* bit mask for minimum adv. panel values */
int piadvmin = (1<<PSD_ADVECHO) +
  (1<<PSD_ADVTE) + (1<<PSD_ADVTE2) + (1<<PSD_ADVTI) + (1<<PSD_ADVTR) +
  (1<<PSD_ADVFOV) + (1<<PSD_ADVRCVBW) + (1<<PSD_ADVVENC) + (1<<PSD_ADVRCVBW2); 
int piadvmax = (1<<PSD_ADVECHO) +
  (1<<PSD_ADVTE) + (1<<PSD_ADVTE2) + (1<<PSD_ADVTI) + (1<<PSD_ADVTR) +
  (1<<PSD_ADVFOV) + (1<<PSD_ADVRCVBW) + (1<<PSD_ADVVENC) + (1<<PSD_ADVRCVBW2); 

/* bit mask for scan time adv. panel values */
int piadvtime = (1<<PSD_ADVMINTSCAN) + (1<<PSD_ADVMAXLOCSPERACQ) +
  (1<<PSD_ADVMINACQS) + (1<<PSD_ADVMAXYRES);

/* bit mask for cardiac adv. panel values */
int piadvcard = (1<<PSD_ADVISEQDELAY) 
   + (1<<PSD_ADVMAXPHASES) + (1<<PSD_ADVEFFTR)
   + (1<<PSD_ADVMAXSCANLOCS) + (1<<PSD_ADVAVAILIMGTIME);


/* misc pi variables */
int pifilt4 = 0;
int pifilt5 = 0;
int pifilt6 = 0;
int pifilt7 = 0;
int pitfeextra= 0;


/* SAR reporting */
float pipsar;  
float piasar;

/* APS */
int pitr;
int pichop;
int pitsp1;
int pitsp2;
int picalmode;
int pislquant;
int pinex;

/* screen control */

/* user CV */
int piuset;

int pimphscrn =0;		/* controls the Multi-Phase screen,
				   0: no multi-phase,
				   1: multi-phase acq.*/

int pifphasenub=0;	/* buttons for number of phases per location */
int pifphaseval2 = 1;
int pifphaseval3 = 2;
int pifphaseval4 = 4;
int pifphaseval5 = 8;
int pifphaseval6 = 16;

int pisldelnub=0; 	/* buttons for delay after acquisition, value 0-6 */
int pisldelval3 = 500ms;
int pisldelval4 = 1s;
int pisldelval5 = 2s;
int pisldelval6 = 5s;

int piacqnub=0;		/* buttons for phase acquisition order, value 0-2 */

/* pisctim */
int pisctim = 1;

int pifanub = 0;
int pifaval2 = 10;
int pifaval3 = 20;
int pifaval4 = 30;
int pifaval5 = 40;
int pifaval6 = 50;

int pisatnub = 1; /* 1 if Sat buttons should appear */
int piccsatnub = 1; /* if 1, concatsat button should
		       appear */
int pisupnub = 1; /* if 1, chemsat buttons will appear */

int pietlnub = 0;		/* Number of ETL buttons */
int pietlval2 = 2;
int pietlval3 = 4;
int pietlval4 = 8;
int pietlval5 = 16;
int pietlval6 = 32;

int piechnub = 3;
int piechval1 = 1;
int piechval2 = 2;
int piechval3 = 4;
int piechval4 = 0;
int piechval5 = 0;

int pitetype = PSD_LABEL_TE_NORM;  /* Flag for TE annotation */
int pite1nub = 63;
int pite1val2 = 10ms;
int pite1val3 = 20ms;
int pite1val4 = 25ms;
int pite1val5 = 30ms;
int pite1val6 = 35ms;

int pite2nub = 0;
int pite2val2 = 40ms;
int pite2val3 = 60ms;
int pite2val4 = 80ms;
int pite2val5 = 100ms;
int pite2val6 = 120ms;

int pitrnub = 6;
int pitrval2 = 300ms;
int pitrval3 = 500ms;
int pitrval4 = 800ms;
int pitrval5 = 1000ms;
int pitrval6 = 2000ms;

int pititype   = PSD_LABEL_TI_IR;  /*  Flag for TI annotation  */
int pitinub    = 0;
int pitidefval = 0;    /* Default value for TI */
int pitival2   = 50ms;
int pitival3   = 130ms;
int pitival4   = 200ms;
int pitival5   = 300ms;
int pitival6   = 400ms;

int pirbwpage = PSD_BW_SCREEN_SET;  /*  Flag for RBW screen  */
int pircbnub = 6; /* number of variable bandwidth buttons */
float pircbval2 = 2.0;
float pircbval3 = 4.0;
float pircbval4 = 8.0;
float pircbval5 = 12.80;
float pircbval6 = 16.0;

int pipscoptnub = 1; /* Bit map of number of Prescan option buttons 
					   0=none, 1=autoshim, 2=phase corr */

    /* piflosup has become obsolete but can't be changed. Now its pivascop */
int piflosup = 0; /* Set to 1 if flow suppression screen
		     required (i.e. phase contrast) */
int piflanub = 0; /* if 1, flow axis buttons will appear */
int pivelnub = 0; /* if 1, velocity encoding prompt will appear */
int piprojnub = 0; /* bitmask for num of projetion buttons */
int piaddinub = 0; /* bitmask for num of additional image buttons */
int piflrcnub = 0; /* bit mask for the flow recon type */

/* scanning range */
int piscran = 1;

int pifovnub = 6;
float pifovval2 = 80;
float pifovval3 = 120;
float pifovval4 = 160;
float pifovval5 = 200;
float pifovval6 = 240;

int piphasfovnub = 0; /* bitmap for variable fov buttons to appear of
						 Aquisition Timing page, 0=off, 7=on */
int pifreqfovnub = 0; /* bitmap for future frequency fov buttons */

int pistnub = 6;
float pistval2 = 3;
float pistval3 = 4;
float pistval4 = 5;
float pistval5 = 7;
float pistval6 = 10;

int piisnub = 5;
int piisil = 1;
float piisval2 = 1.5;
float piisval3 = 2.5;
float piisval4 = 5;
float piisval5 = 10;
float piisval6 = 15;

int pilocnub = 0;
int pilocval2 = 28;
int pilocval3 = 60;
int pilocval4 = 124;
int pilocval5 = 252;
int pilocval6 = 508;

/* acquisition timing */
int piactim = 1;
/* piamnub is now a bitmap */
int piamnub = 7;
char piamval1[8] = "256x128";
char piamval2[8] = "256x192";
char piamval3[8] = "256x256";
char piamval4[8] = "512x256";
char piamval5[8] = "512x384";
char piamval6[8] = "512x512";

int piyresnub = 15;  /* bitmask */
int piyresval2 = 160;
int piyresval3 = 192;
int piyresval4 = 224;
int piyresval5 = 256;
int piyresval6 = 512;

int pixresnub = 2; /* bitmask */
int pixresval2 = 256;
int pixresval3 = 512;
/* other xres values are not defined */
int pixresval4 = 256;
int pixresval5 = 256;
int pixresval6 = 256;

int pinexnub = 63;
float pinexval2 = 0.5;
float pinexval3 = 0.75;
float pinexval4 = 1;
float pinexval5 = 2;
float pinexval6 = 4; 

float pisctim1 = 0;
float pisctim2 = 0;
float pisctim3 = 0;
float pisctim4 = 0;
float pisctim5 = 0;
float pisctim6 = 0;

int pipautype = PSD_LABEL_PAU_LOC;  /*  Flag for Pause annotation  */
int pipaunub = 0;
int pipauval2 = 0;
int pipauval3 = 1;
int pipauval4 = 2;
int pipauval5 = 3;
int pipauval6 = 4;

int pircb2nub = 6; /* number of variable bandwidth buttons */
float pircb2val2 = 2.0;
float pircb2val3 = 4.0;
float pircb2val4 = 8.0;
float pircb2val5 = 12.80;
float pircb2val6 = 16.0;


/* scan setup */
int pisetup = 1;

/* Cardiac heart rate buttons */
int pihrepnub=30;		/* Bitmask for hrep buttons */
int pihrepval2=4;		/* Button 2 value */
int pihrepval3=3;		/* Button 3 value */
int pihrepval4=2;		/* Button 4 value */
int pihrepval5=1;		/* Button 5 value */
int pihrepval6=9;		/* Button 6 value */

int pite2type = PSD_LABEL_TE_NORM;  /* Flag for TE annotation */

/* Flow comp axis buttons */
int pifsefcnub = 0;  /* bitmask - buttons for flow comp axis selection */
int pideffcaxis = 0; /* Default value for flow comp direction */

/* Number of locations per slab buttons */
int pislqnub = 15;  /* Bitmask for Number of locations per slab button */
int pislqval2 = 16; /* Button 2 value */
int pislqval3 = 32; /* Button 3 value */
int pislqval4 = 64; /* Button 4 value */
int pidefslq = 32;  /* Default value for Number of loc.s per slab */
int pislqval5 = 128; /* add a button when combining 3d-multi and 3d */

/* Ramp direction buttons */
int pirampnub = 0; /* Bitmask for Ramp Pulse buttons */
int pideframp = 0; /* Default value for Ramp Pulse direction, 0: nonramp pulses, 1: positive ramp pulse */

/* Overlap slices */
int pipctovl = 25; /* Percentage of overlapping region thickness over whole slab thickness. */
int pidefovl = 1; /* Indicate default button for overlap slices; 0: "Other" button, 1: "Recommended" button. */
int piovlnub = 0;  /* overlap locations on 3D MS scanning range (bitmap) */

/* Screen control for cardiac gating */
int pitdel1nub = 7; /* Bitmask for Trigger Delay buttons */
int pitrigwinnub = 63; /* Bitmask for Trigger Window buttons */
int pitseqnub = 7; /* Bitmask for Inter-Sequence Delay buttons */
int piphasenub = 3; /* Bitmask for Phase buttons */
int piphslnub = 2; /* Bitmask for Phases/Slices feedback fields */
int piviewseg = 0;  /* Field to prompt for views per segment field */

PSD_FILTER_GEN psd_filt_spec[PSD_FILTER_MAX];

int pivascop = 0; /* Set to 1 if flow suppression screen
		     required (i.e. phase contrast) */
int pimultigroup = 1; /* Multi group capability for scan. 1=on, 0 = off */
int pimultislab  = 0; /* Multi slab capability for scan. 1=on, 0=off *//* 55 change. YH 10/14/94 */

/* bit maps for default selection on vascular enhancement screens */
int pidefproj = 5;     /* projections */
int pidefflax = 8;     /* flow axes selection */
int pidefaddimg = 8;   /* additional images */
int pidefflrc = 1;     /* flow recon type */

/* changed from short to int. YH *//* changed to short again  2/16/95 YI */
short eg_sat_rot[6][9]; /* rotation matrices for sat */

int pivpsdef=8;		/* default number of views per seg for fastcard */

int pidefrbw = 15.63;      /* default rbw setting in kHz: 0 = default to the
              minimum rbw allowed, any other value indicates
              the desired default rbw. */
int pigradcoil = 1;    /* gradient shield mode: 0 = unshielded gradient
			  coil, 1 = shielded gradient coil */
float dfscale = 1.0;   /* Digital Filter Scale Factor *//* 55 change. YH 10/14/94 */

/* Prescan button defaults */
int pipscdef = 1;  /* bitmask control for default backlighting of prescan
					  buttons */
int avminrttseq; /* Advisory panel min sequence time */
 
int pitetr = 0;  /* Effective TR determined by PSD, used by resp trig screen */

int pirtrigwinnub = 5; /* number of trigger window buttons */
int pirtwindefval = 30;
int pirtwinval2 = 10;
int pirtwinval3 = 20;
int pirtwinval4 = 30;
int pirtwinval5 = 40;
int pirtwinval6 = 50;

int pirtseqnub = 7;    /* inter-seq delay buttons (bitmap) */ 
int pirttseq;/* pi inter sequence delay time for resp trig */
int pirtait; /* pi avaiable imaging time for resp trig */
int pirtetr; /* pi effective tr for resp trig */
 
int pirtrepnub = 63; /* bit mask for resp rep buttons */
int pirtrepval2 = 5;
int pirtrepval3 = 4;
int pirtrepval4 = 3;
int pirtrepval5 = 2;
int pirtrepval6 = 1;
 
int pirtpointnub = 30;
int pirtpointval2 = 10;
int pirtpointval3 = 20;
int pirtpointval4 = 30;
int pirtpointval5 = 40;
int pirtpointval6 = 50;

int pishotnub = 0;  /* number of buttons to display, not bit mask */
int pishotval2 = 1;
int pishotval3 = 2;
int pishotval4 = 4;
int pishotval5 = 8;
int pishotval6 = 16;
 
/* int piphasfovnub = 0; defined above */
/* float piphasfovval2 = 1.0; */
/* float piphasfovval3 = 0.5; */
float piphasfovval2 = .75;    /* 5.5-QT */
float piphasfovval3 = 0.5;
float piphasfovval4;  /* not used - only 3 buttons are visible */
float piphasfovval5;  /* not used - only 3 buttons are visible */
float piphasfovval6;  /* not used - only 3 buttons are visible */

int rec_mode = 0;

int opnewgeo = 1;

/* Used to create simulation matrices in obloptimize */
/* If set equal to 1 obloptimize will create rotation matrices */
/*                 0 the rotation matrices from scan will be used */
int simulation = 0;

/* config file variables */

float cflinfrq = 60;
float cffield = 15000;
float cfhpdl = 800;
float cfbpdl = 5000;
float cfhpsl = 350;
float cfbpsl = 4000;
float cfhpv = 3000;
float cfbpv = 6000;
float cfhqpc = 0.15;
float cfbqpc = 0.7;
float cfhllr = 857;
float cfbllr = 394;
float cfloss = 1.0715;

int cfbwmin = 2;
int cfbwmin1 = 2;		/* First echo minimum bw for 0.5 T (in kHz) */
float cfmaxave = 2.0;
float cfmaxpeak = 8;
int cftpssize = 32000000;
float cccal = 1.3;
float ccjcoil = 0.04;
int cfxfull = 32752;
int cfyfull = 32752;
int cfzfull = 32752;
int cfdbmax = 100;
int cfbbmod = 0;
int cftrnew = 0;
int cfrecvst = 0;
int cfrecvend = 0;
int cfgradamp = G8607;  /* Indicate gradient amplifier type */
int cfhtdel = 10000; /* Fixed hardware trigger delay in us */
int cfcftdel = 28000; /* cine filter trigger delay in us */
float cfcgain = 1;      /* coil recon gain */
int cfcoilatten = 0; /* coil attentuation in tenths of dB */

/* config CVs for new 0.5T RF amp/Power mon, 5/18/93 */
int cfrfrapb = 16000; /* Rated Output Power(body), in unit of Watt */
int cfrfraph = 2000;  /* Rated Output Power(head), in unit of Watt */
int cfrfmapb = 1000;  /* Maximum Average Power(body), in unit of Watt */
int cfrfmaph = 100;   /* Maximum Average Power(head), in unit of Watt */
float cfrfmpeb = 60.0;  /* Maximum Pulse Energy(body), in unit of J */
float cfrfmpeh = 6.0;  /* Maximum Pulse Energy(head), in unit of J */
int cfrfmpwb = 20000;  /* Maximum Pulse Width(body), in unit of us */
int cfrfmpwh = 20000;  /* Maximum Pulse Width(head), in unit of us */
float cfrfmdcb = 0.60;  /* Maximum Duty Cycle(body) */
float cfrfmdch = 0.60;  /* Maximum Duty Cycle(head) */
int cfrfamptyp = 0;     /* RF Amplifier type: 0=tube type, 1=solid state type 2=vectra rf amp */
int cfpwrmontyp = 0;    /* Power Monitor type: 0=Shared head and spectro PMON settings, 1=Unique spectro and head PMON settings, 2=vectra type */
int cfpsdgraddly = 120;  /* Gradient system delay: default to 120us for 0.5T*/
int cfpsdrfdly = 56;    /* rf system delay: default to 56us */
int cfxrdelay = 180; /* group delay in x dir for spiral */
int cfyrdelay = 180; /* group delay in y dir for spiral */
int cfzrdelay = 180; /* group delay in z dir for spiral */

int piphasfovnub2= 0; /* Used to select the "other" button in phase fov */
int piswapfc = 0;/* Used to change the default (highlighted) opspf value */
int pidltime = 100000000; /* Time in us that scan allows for wave form 
                          download in IPG before time out error */
float piphasfovval1 = 1.0;

/*more config file CVs to support vmx/vectra electronics */
int cfcoilshld = 0;  /* Indicates if a system has switchable grad shield:
			0=Not switchable, 1=switchable */
int cfrfunblank;     /* unblank time for rf amplifier */


/************************************
following parameters are new for 5.5
************************************/

/* X gradient parameters */

int cfrmp2xfs = 600;
int cffall2x0 = 600;
float cfxfs = 1;
float cfxfa = 70;
float cfxcc = 31;
float cfxbeta = 1;

/* Y gradient parameters */

int cfrmp2yfs = 600;
int cffall2y0 = 600;
float cfyfs = 1;
float cfyfa = 70;
float cfycc = 31;
float cfybeta = 1;

/* Z gradient parameters */

int cfrmp2zfs = 600;
int cffall2z0 = 600;
float cfzfs = 1;
float cfzfa = 70;
float cfzcc = 31;
float cfzbeta = 1;

int cffrecvst = 4;  /* Fast receiver start ID */
int cffrecvend = 4; /* Fast receiver end ID */
int cffrecvnum = 1; /* Number fast receivers */
 
int cfxgram = PSD_NOGRAM;    /* GRAM: 0 = no gram, 1 = gram-1 2 = gram-2 */
int cfygram = PSD_NOGRAM;
int cfzgram = PSD_NOGRAM;
int cfxasm = YES;    /* ASM present */
int cfyasm = YES;
int cfzasm = YES;
int cfxgasm = NO;    /* GASM present */
int cfygasm = NO;
int cfzgasm = NO;
int cfxseries = NO;  /* Axis in series */
int cfyseries = NO;
int cfzseries = NO;
int cfxnumpower = 1; /* Number of power modules for gradient */
int cfynumpower = 1;
int cfznumpower = 1;

int cftuning = GRAM_TUNE_ANALOG;  /* GRAM tuning board type */
 
int cfrealtime = PSD_ON; /* real-time monitoring */
  
int cfcompress = 100;  /* compression factor from config file. If 100
                          then don't set RHRCCOMP in rhrcctrl */
/* Patient dB/dt exposure limitations */
float cfdbdtts = 45.0;    /* dB/dt limit (Tesla/sec) */
float cfdbdtper = 0;      /* dB/dt limit (percent of limit) */
float pidbdtts = 0;       /* dB/dt value (Tesla/sec) */
float pidbdtper = 0;      /* dB/dt value (percent of limit) */

int cfgcoiltype = PSD_55_CM_COIL;

int cfsrmode = PSD_SR17;

float cfgpeakirms = 110;  /* Peak rms current for gradient coil (Amps) */
float cfgcontirms = 50;   /* Continuous rms current for gradient coil (Amps) */
float cfgburstime = 10.0; /* longest burst at peak rms current (minutes) */

float cfxirms = 42;       /* RMS current, X driver (Amps) */
float cfyirms = 42;       /* RMS current, Y driver (Amps) */
float cfzirms = 42;       /* RMS current, Z driver (Amps) */

float cfxipeak = 90;      /* Peak current ouput, X driver (Amps) */
float cfyipeak = 90;      /* Peak current ouput, Y driver (Amps) */
float cfzipeak = 90;      /* Peak current ouput, Z driver (Amps) */
 
float cfxamptran = 100;   /* Amp transition current, X driver (kA/sec) */
float cfyamptran = 100;   /* Amp transition current, Y driver (kA/sec) */
float cfzamptran = 100;   /* Amp transition current, Z driver (kA/sec) */

float cfxiavrgabs = 100;  /* Average absolute value current, X driver (Amps) */
float cfyiavrgabs = 100;  /* Average absolute value current, Y driver (Amps) */
float cfziavrgabs = 100;  /* Average absolute value current, Z driver (Amps) */

float cfxirmspos = 35;    /* Positive RMS current, X driver (Amps) */
float cfyirmspos = 35;    /* Positive RMS current, Y driver (Amps) */
float cfzirmspos = 35;    /* Positive RMS current, Z driver (Amps) */

float cfxirmsneg = 35;    /* Negative RMS current, X driver (Amps) */
float cfyirmsneg = 35;    /* Negative RMS current, Y driver (Amps) */
float cfzirmsneg = 35;    /* Negative RMS current, Z driver (Amps) */

float cfxpwmdc = 0.2;     /* Pulse width modulation duty cycle, X driver */
float cfypwmdc = 0.2;     /* Pulse width modulation duty cycle, Y driver */
float cfzpwmdc = 0.2;     /* Pulse width modulation duty cycle, Z driver */

/* GRAM freewheel mode slew rates */
int cfrmp2xfsfw = 600;
int cfrmp2yfsfw = 600;
int cfrmp2zfsfw = 600;
int cffall2x0fw = 600;
int cffall2y0fw = 600;
int cffall2z0fw = 600;

/* RF magnetic field limitations */
float cfmaxb1 = 25.0;     /* Maximum B1 strength (uTesla) */
float cfmaxb1sqrd = 8.0;  /* Maximum integrated (B1)^2 per pulse (uT^2sec) */
float cfmaxb1rms = 3.6;   /* Maximum RMS B1 strength, long term average
							 (uTesla) */

/* Distances from isocenter where dB/dt in measured, physical X, Y, & Z axes */
float cfdbdtdx = 34.4;  /* centimeters */
float cfdbdtdy = 34.4;
float cfdbdtdz = 34.4;

int sigrammode = 0; /* bitmask filled in by scan: 0 = freewheel or no gram,
                       1 = active gram.  Bit 0 = X, Bit 1 = Y, Bit 2 = Z */

@reqcv
/* *************************************************
   MORE REQUIRED CVS
   ************************************************ */

/*  ADD NEW CVs HERE (before next "@") UNTIL YOU CAN BUMP UP THE
	REVISION NUMBER */

int rhrefframep = 0 with {0, , 0, VIS,
				  "Number of frames per pass for a REF scan",};
int rhscnframe = 0 with {0, , 0, VIS,
				  "Total number of frames acquired for an entire SCAN",};
int rhpasframe = 0 with {0, , 0, VIS,
				  "Number of frames per pass",};
 
@reqexport
/* *************************************************
   MORE REQUIRED EXPORT CVS 
   ************************************************ */

/*  ADD NEW CVs HERE (before next "@") UNTIL YOU CAN BUMP UP THE
	REVISION NUMBER */

float cfsrmodeconv = 77.0; /* maximum slew rate limit for conventional scans */
float cfsrmodeact = 77.0;  /* actual slew rate limit to use for conventional scans */

@reqcv
/* *************************************************
   MORE REQUIRED CVS 
   ************************************************ */
int cont_flag=PSD_OFF with {PSD_OFF,PSD_ON,PSD_OFF,VIS,
		"Acq. mode, 0=normscan, 1=contscan.",};
int optabent=1 with {1,3,1,VIS,
		"Table Entry: 1=Front, 2=Side, 3=Vertical.",};
int sifsetwokey = 0 with {PSD_OFF,PSD_ON,PSD_OFF,INVIS,
                          "Flag to enable fse-II options. 0=off, 1=on"};
int iheesp = 0 with {0,10ms,0,INVIS,
					   "Annotation for effective echo spacing (usec)",};

int oplandmark = PSD_OFF with {PSD_OFF, PSD_ON, PSD_OFF, VIS,
                         "A valid landmark exists. 0=false, 1=true",};

int opautosldelay = PSD_OFF with {PSD_OFF, PSD_ON, PSD_OFF, VIS,
                            "Flag for auto sldelay mode. 0=off, 1=on",};

int rhpcfitorig = 1 with {0, 1, 1, VIS,
                          "1=adjust view indices so bestky view = 0",};
int rhpcshotfirst = 0 with {0, 512, 0, VIS,
                            "First view within an echo group",};
int rhpcshotlast = 0 with {0, 512, 0, VIS,
                           "Last view within an echo group",};
int rhpcmultegrp = 0 with {0, 1, 0, VIS,
                           "1 = force pts from other echo groups to be used",};
int rhpclinfix = 1 with {0, 2, 1, VIS,
                         "1=force neg slope to pos,2=fix to rhpclinslope",};
float rhpclinslope = 0.0 with {-6.28318, 6.28318, 0, VIS,
                               "Value for linear correction slope if fixed",};
int rhpcconfix = 1 with {0, 2, 1, VIS,
                         "1=force neg slope to pos,2=fix to rhpcconslope",};
float rhpcconslope = 0.0 with {-6.28318, 6.28318, 0, VIS,
                               "Value for const correction slope if fixed",};
int rhpccoil = 1 with {0, 4, 1, VIS,
                       "0=coil specific, 1=use 1, 2=use 2, 3=use 3, 4=use 4",};
int piforkvrgf = 0;  /*  1 causes scan to spawn the vrgf process upon download */
int pinofreqoffset = 0; /*  1 disables fov offset in frequency direction */
int opssfse = 0 with {0,0,0,INVIS,"Single Shot FSE flag, (0)off, (1)on",EM_PSD_SINGLE_SHOT_INCOMPATIBLE};
int t1flair_flag = 0 with {0,0,0,INVIS,"On(=1) Flag for t1flair scan",};
                                                                        
float rhmaxcoef1a = 0 with {,,0,VIS,
  "Z^2 Maxwell Term for Flow Image 1",};
float rhmaxcoef1b = 0 with {,,0,VIS,
  "X^2+Y^2 Maxwell Term for Flow Image 1",};
float rhmaxcoef1c = 0 with {,,0,VIS,
  "XZ Maxwell Term for Flow Image 1",};
float rhmaxcoef1d = 0 with {,,0,VIS,
  "YZ Maxwell Term for Flow Image 1",};
float rhmaxcoef2a = 0 with {,,0,VIS,
  "Z^2 Maxwell Term for Flow Image 2",};
float rhmaxcoef2b = 0 with {,,0,VIS,
  "X^2+Y^2 Maxwell Term for Flow Image 2",};
float rhmaxcoef2c = 0 with {,,0,VIS,
  "XZ Maxwell Term for Flow Image 2",};
float rhmaxcoef2d = 0 with {,,0,VIS,
  "YZ Maxwell Term for Flow Image 2",};
float rhmaxcoef3a = 0 with {,,0,VIS,
  "Z^2 Maxwell Term for Flow Image 3",};
float rhmaxcoef3b = 0 with {,,0,VIS,
  "X^2+Y^2 Maxwell Term for Flow Image 3",};
float rhmaxcoef3c = 0 with {,,0,VIS,
  "XZ Maxwell Term for Flow Image 3",};
float rhmaxcoef3d = 0 with {,,0,VIS,
  "YZ Maxwell Term for Flow Image 3",};


@reqexport
int avmaxtdel1; /* max cardiac delay */
int avminphases;
int avminetl;
int avmaxetl;
int avminyres;
int avminslicecnt;
int avmaxslicecnt;
int avmaxtseq;
int avminxres;
int avminnshots;
int avmaxnshots;
float avmaxphasefov;
float avminphasefov;
float avminslthick;
float avmaxslthick;
float avminnex;
float avmaxnex;
float avminflip;
float avmaxflip;
float avminslspace;
float avmaxslspace;
/* New Maximum RMS B1 strength for Head Coil, long term average (uTesla) */
float cfmaxb1rmshead = 7.2;

@reqcv
/********************************************************/
/*   EPI DWI cv's					*/
/********************************************************/

int opdiffuse=0 with {0,0,0,VIS,"Diffusion,0=off,1=on",EM_PSD_DIFF_INCOMPATIBLE};
int opsavedf=0 with {0,4,0,VIS,"1=T2,Comb,2=T2,Diff,Comb",};	
int opmintedif = 1 with {0,1,1,VIS,"Minimize Diffusion Timing",};

int opdfaxx=0;		/*   diffusion direction variables      */
int opdfaxy=0;
int opdfaxz=0;
int opdfaxall=0;

int opbval=0 with {0,1000,0,VIS,"B Value for Diffusion",};

int rhdptype = 0 with {0, , 0, VIS,
				  "Diffusion / Perfusion imaging option",};
int rhutctrl = 0 with {0, , 0, VIS,
				  "Recon utility control",};

/********************************************************/
/*   EPI FLAIR cv's					*/
/********************************************************/
int opflair = 0 with { 0, 0, 0, VIS, "Flair, 0=OFF, 1=ON", };

/* *************************************************
   SmartPrep Required CVs
   ************************************************ */

float opmonfov = 200 with {20,FOV_MAX,200,VIS,
			  "Length of monitor pulse in mm.",};


float opmonthick = 20 with {5,100,20,VIS,
			"Monitor thickness in mm.",};

float opdose = 0 with {0,100,0,VIS,"Gadolinium dose in ml.","Contrast dose must be between 0 and 100 ml."};

float rhzipfact = 0 with {0, 4, 0, VIS, "Recon slice ZIP factor.",};



int opzip512 = 0 with {0, 0, 0, VIS,
                "512 In-plane Zero Interpolation Padding: 0=off, 1=on",EM_PSD_NO_512_ZIP};

int opzip1024 = 0 with {0, 0, 0, VIS,
                "1024 In-plane Zero Interpolation Padding: 0=off, 1=on",EM_PSD_NO_1024_ZIP};

int opslzip2 = 0 with {0, 0, 0, VIS,
                "Slice Zero Interpolation Padding x 2: 0=off, 1=on",EM_PSD_ZIP2_ONLY_3D_GE_ANDTOF_COMPATIBLE};

int opslzip4 = 0 with {0, 0, 0, VIS,
                "Slice Zero Interpolation Padding x 4: 0=off, 1=on", EM_PSD_ZIP4_ONLY_3D_GE_ANDTOF_COMPATIBLE};


@reqexport
/********************************************************/
/*   EPI DWI pi variables			        */
/********************************************************/
int pidifpage=0;	/*   Control of diffusion page and diffusion option     */

int pidifaxnub=15;			/*   diffusion direction variables      */
char pidifaxval1[6]="L/R";
char pidifaxval2[6]="A/P";
char pidifaxval3[6]="S/I";
char pidifaxval4[6]="ALL";
char pidifaxval5[6]="SLICE";
 
int pidefbval=1000;		/* MRIge47732 b value variables       */
int pibvnub=15;
int pibval2=500;
int pibval3=750;
int pibval4=1000;
 
int pidifrecnub=1;		/* recon option variables       */

char pidifrecval1[30]="SAVE DIFFUSION IMAGES";
char pidfirecval2[30];
char pidfirecval3[30];
char pidfirecval4[30];
char pidfirecval5[30];

/* *************************************************
   SmartPrep Required Exports
   ************************************************ */
int pimonitor;  /* Enable monitor */

/* Monitor FOV */
int pimonfovnub=15;
float pimonfovval2=50.;
float pimonfovval3=100.;
float pimonfovval4=200.;
float pidfmonfov=200.;

/* Monitor Thickness */
int pimonthicknub=15;
float pimonthickval2=20.;
float pimonthickval3=40.;
float pimonthickval4=80.;
float pidfmonthick=20.;

/* Monitor location - returned by scan */
SCAN_INFO mon_loc;

/* float cfmaxb1rmshead = 7.2;*/  /* max b1rms for 1.0T/head coil */

@reqcv
/* *************************************************
   MORE REQUIRED CVS 
   ************************************************ */

/* Neuro Vascular Coil CV    */
int opnvcoil = 0 with {0,1,0,VIS,"Neuro Vas Coil Switch",};
int opcmon = 0 with {0,0,0,VISONLY,
			  "Cardiac Compensation. 0=off, 1=on.",EM_PSD_CMON_PSEQ_INCOMPATIBLE};
int opsmartprep = 0 with {0,0,0,VISONLY,"Smartprep. 0=off, 1=on.", EM_PSD_SMARTPREP_ONLY_ONE_COMPATIBLE};


@reqexport
/* *************************************************
   MORE REQUIRED EXPORT CVS
   ************************************************ */
int pizmult = 0;	/* Multi group capability for scan in fse-xl. */
int piccsat_obl = 0;	/* Concat sat capability for oblique scan in fse-xl. */

/* FastCINE number of phases buttons */
int pifcinenub    = 0; 
int pifcinedefval = 0;
int pifcineval2   = 0;
int pifcineval3	  = 0;
int pifcineval4	  = 0;

/* Cardiac Tagging buttons */
int pitagging      = 0; /* Cardiac Tagging Selection */
int pitagspcdefval = 0;
int pitagspcval2   = 0;
int pitagspcval3   = 0;
int pitagspcval4   = 0;

/* Black Blood Suppression buttons */
int pibsptinub    = 0;
int pibsptidefval = 0;
int pibsptival2   = 0;
int pibsptival3   = 0;
int pibsptival4   = 0;
int pibsptival5   = 0;
int pibsptival6   = 0;

/* Configuration variables to support SGD gradient heating and
   increased CERD receiver bandwidth */
float cfxmgrampow = 1500.0;
float cfymgrampow = 1500.0;
float cfzmgrampow = 1500.0;
float cfsdlim = 0.60;
float cfxrsat = 0.022;
float cfyrsat = 0.022;
float cfzrsat = 0.022;
float cfxvsat = 4.8;
float cfyvsat = 4.8;
float cfzvsat = 4.8;
float cfgpmpow = 6300.0;
float cfmgps = 9000.0;
float cfvhr = 17.0;
float cfrcoil = 0.35;
float cflcoil = 1.4;
float cfraccoil = 152.0;
float cfpmgs = 3000;
float cfrhr = 0.1;
float cfxvpwm = 35.0;
float cfyvpwm = 35.0;
float cfzvpwm = 35.0;
float cfcerdbw1 = 125.0;
float cfcerdbw2 = 125.0;
float cfcerdbw3 = 125.0;
float cfcerdbw4 = 125.0;

/* MRIge47735  Faster prescan cv */
int cffastprescan = 1;

@reqcv
/* *************************************************
   MORE REQUIRED CVS 
   ************************************************ */
/* Cardiac Gating */
int opcgatetype = 0 with {
    0, 2, 0, VIS, "0=OFF, 1=ECG, 2=PG",
};
int opadvgate = 0 with {
    0, 1, 0, VIS, "Enable Advanced ECG Gating.",
};

/* Fast CINE */
/* Enable selection by changing cvmax field */
int opfcine = 0 with {
    0, 0, 0, VIS, "Fast CINE Mode.", EM_PSD_FCINE_INCOMPATIBLE
};
int ihfcineim = 0 with {
    0, 2, 1, VIS, "Annotation for Fast CINE interpolation method "
                  "(0=None, 1=Linear, 2=Nearest Neighbor)",
};
int ihfcinent = 0 with {
    0, 2, 1, VIS, "Annotation for Fast CINE normalization type "
                  "(0=None, 1=Systole-Diastole, 2=Uniform)",
};
int rhfcinemode = 0 with {
    0, , 0, INVIS, "Fast CINE mode bitmask.",
};
int rhfcinearw = 10 with {
    0, 100, 10, INVIS, "Fast CINE Arrhythmia Rejection Window (ARW)",
};
int rhvps = 8 with {
    1, 1024, 8, INVIS, "Views per Segment (VPS)",
};
int rhvvsaimgs = 1 with {
    1, DATA_ACQ_MAX, 1, VIS, "Number of original images.",
};
int rhvvstr = 0 with {
    0, ,0, VIS, "Variable-view sharing TR in us",
};
int rhvvsgender = 0 with {
    0, 1, 0, VIS, "Gender (0=Male, 1=Female)",
};

/* Black Blood Suppression */
/* Enable selection by changing cvmax field */
int opbsp = 0 with {
    0, 0, 0, VIS, "2/3 IR Blood Suppression.", EM_PSD_BSP_INCOMPATIBLE
};
int opbspti = TI_MIN with {
    TI_MIN, TI_MAX,TI_MIN, VIS, "2/3 IR Blood Suppression TI.",
    EM_PSD_BSP_INCOMPATIBLE
};
int opautoti = 0 with {
    0, 1, 0, VIS, "Flag for Auto TI mode",
};
int opautobti = 0 with {
    0, 1, 0, VIS, "Flag for Auto BSP TI mode",
};
int ihbspti = TI_MIN with {
    TI_MIN, TI_MAX, TI_MIN, INVIS, "Blood Suppression TI annotation for current image.",
};

/* Cardiac Tagging */
/* Enable selection by changing cvmax field */
int optagging = 0 with {
    0, 0, 0, VIS, "Cardiac Tagging (0=None, 1=Stripe, 2=Grid)",
    EM_PSD_TAG_INCOMPATIBLE
};
int optagspc = 7 with {
    0, 1024, 7, VIS, "Cardiac Tagging spacing/separation (pixels)",
};
float ihtagfa = 180.0 with {
    0.0, 180.0, 180.0, VIS, "Annotation for Cardiac Tagging Flip Angle",
};
float ihtagor = 45.0 with {
    -180.0, 180.0, 45.0, VIS, "Annotation for Cardiac Tagging Orientation",
};

/* Added for SNR Index */
float pifractecho = 1.0
    with {0.5,1.0,1.0, VISONLY,"Fractional echo ratio for SNR monitor",};

/* Added for RTIA, RJF */
int oprealtime = 0 with {
    0, 0, 0, VIS, "Realtime Interactive Scanning Option.",
    EM_PSD_RTIA_REALTIME_NOT_AVAILABLE
};

/* Added for Echotrain */
int opET = 0 with {
  0, 0, 0, VIS, "Echotrain imaging Option.",
    EM_PSD_ECHOTRAIN_NOT_AVAILABLE
};


/* Bolus Chasing CVs - CMC */
int opmultistation = 0 with {
    0, 0, 0, VIS, "The multi station button input from scan",
    "MultiStation not available for this PSD"
};

int opnostations = 1 with {
    1, 4, 1, VIS, "The total number of stations for the current meta-series",
};

int opstation = 1 with {
    1, 4, 1, VIS, "The current station number",
};

int pscahead = 0 with {
    0, 1, 0, VIS, "Enable the Prescan Ahead option",
};

int opprescanopt = 0 with {
    0, 1, 0, VIS, "The option for skipping Prescan",
};

int autoadvtoscn = 0 with {
    0, 1, 0, VIS, "Automate the table movement",
};

int opprotRxMode = 0 with {0,1,0,VIS,"0 = Scan Mode, 1 = Protocol Mode",};  /* Added to indicate whether Procol/Scan mode -TAA */


@reqexport
/* Bolus Chasing CVs - CMC */
int pimultistation = 0; /* Doing MultiStation? */
int piautostep = 0;     /* Doing AutoStep? */
int pisioverlap = 0;    /* S/I Overlap in mm. (percent from FOV) */

/* Spectroscopy interface variables */
int csi_grid_on = 0;  /*csi grid 0=off, 1=probeSI, 2=research mode*/
int pispecprescan = 0; /*Spectro Prescan button 0=off or 1=on*/
int picsimode = 0;
int rhrlfov = 0;
int rhapfov = 0;
int rhsifov = 0;

/*
 * MRIge53080 - Added 'cfcerdtype' config variable to indicate type of CERD.
 * The value will be obtained from the MRconfig.cfg file which contains a
 * 'cerdType' entry.
 * 
 * cerdType = "n01" -> standard CERD in slot 1
 *            "n02" -> Universal CERD in slot 1
 *            "n21" -> standard CERD in slot 1, Universal CERD in slot 2
 *            "n22" -> Universal CERD in slots 1 and 2 (dual UCERD)
 *    where n = 0 for Milwaukee, 1 for YMS
 * 
 */
int cfcerdtype = 1;

/* MRIge56470 - define a cfpicture for "Picture This". */
int cfpicture = 0;

@ipgexport
/* *******************
   ipgexport
   ******************* */
RSP_INFO rsp_info[DATA_ACQ_MAX];
/* changed following 2 parameters from short to int. YH */
long rsprot[TRIG_ROT_MAX][9];    /* rotation matrix for this slice */
long rsptrigger[TRIG_ROT_MAX];   /* trigger type */

long ipg_alloc_instr[PSD_MAX_PROCESSORS] = {
PSD_GRADX_INSTR_SIZE,
PSD_GRADY_INSTR_SIZE,
PSD_GRADZ_INSTR_SIZE,
PSD_RHO1_INSTR_SIZE,
PSD_RHO2_INSTR_SIZE,
PSD_THETA_INSTR_SIZE,
PSD_OMEGA_INSTR_SIZE,
PSD_SSP_INSTR_SIZE,
PSD_AUX_INSTR_SIZE};


RSP_INFO asrsp_info[3];   /* transmit, receive locations for autoshim */
/* changed from short to in.  YH */
long sat_rot_matrices[14][9]; /* rotation matrices for sp sat */
int TARDIS_FREQ_OFFSET;

/* following parameters are new for 55 *//* added  YH 10/14/94 */
PHYS_GRAD phygrd;         /* physical gradient characteristics */
LOG_GRAD  loggrd;         /* logical gradient characteristics */
LOG_GRAD  satloggrd;      /* logical gradient chars. for graphic sat */
 
LOG_GRAD  asloggrd;       /* logical gradient characteristics */
SCAN_INFO asscan_info[3];
/* MRIge43968 (BJM): redefined from long PSrot[10] to the following.. */
/* redefined to long PSrot from int as per CARDIAC34.01 version */
long PSrot[PRESCAN_ROT_MAX][9];             /* prescan rotation matrix */
 
PHASE_OFF phase_off[DATA_ACQ_MAX];
int yres_phase;  /* offset in phase direction in mm */
int yoffs1;  /* intermediate phase offset variable */

/*** RT ***/
/* For use in SpSat.e */
/* storage of original concat sat offsets */
int off_rfcsz_base[DATA_ACQ_MAX];
/* storage of original matrix location */
SCAN_INFO scan_info_base[1];

/* For use in Prescan.e and psds */
/* storage of original x, y, and z offsets */
float xyz_base[DATA_ACQ_MAX][3];
/* storage of original rotation matrices */
long rsprot_base[TRIG_ROT_MAX][9];
/*** End RT ***/


/* Begin RTIA */
int rtia_first_scan_flag = 1 ; 
/* End RTIA */

@rspvar
/* id tags - one for MROR-WS, one for pulse sequence, 0 based */
int cont_wsid, cont_psdid;
/* time stamp to recon for MROR header */
int cont_time;
/* variable communicating to recon that real time is on */
int cont_synch;
/* stops the cont imaging after acquisition of the last pass */
int cont_stop, cont_stop_usr;
/* x, y, and z offsets from original prescription - mm units, 1/10 mm
   accuracy, range TBD */
float cont_xoffset, cont_yoffset, cont_zoffset;
/* alpha, beta, and gamma offsets from original prescription - degree
   units, 1/10 degree accuracy, range 0-360 degrees */
float cont_alpha, cont_beta, cont_gamma;

/* variable for checking scan plane offset (cont_x/y/zofset )change */
int cont_sp_changed;

/* Fix for spr MRIge46008 making sure the following prescan vars*/
/* are available for all psds */
/* The following are set by prescan upon successful completion: */
int pscR1;  /* R1 receive attenuation (dB) */
int pscR2;  /* R2 receive attenuation (barrel shift) */
int pscCF;  /* CF center frequency (Hz) */
int pscTG;  /* TG transmit gain (dB) */


@cv
/* ************************************************************
 * CVs
 * Certain CVs are not necessary for Scan/PSD communication
 * but are essential intermediate calculations for determining 
 * recon CV values and pulsegen values.
 * ********************************************************* */

int acqs = 1 with {0,,1,INVIS,"# of acquisitions",};

int avround = 1 with {0,1,1,INVIS, "if 1 advis routines round",};
int baseline = 0 with {0,,0,INVIS,"number of baseline pairs.",};

/* CV nex has value 1 for .5 nex and .75 nex scans */
int nex = 1 with {1,,1,VIS,"number of excitations."};

/* ***************
 * fn 1 full kspace
 *    .5 half nex
 *    .75 3/4 nex 
 **************** */
float fn = 1 with {0.5,1,1,INVIS,"Fractional Nex Indicator",};
/* no phase wrap is used for exorcist high sort and avg high sort */

float nop = 1 with {1,2,0,INVIS, "2 if no phase wrap processing used",};
int acq_type = TYPSPIN with {,,,INVIS,"Spin or grad recall",};
int seq_type = TYPNCAT with {,,,INVIS,"NCAT, CAT, MPMP...",};
int num_images = 1 with {1,,1,INVIS,"Total number of images acquired",};

/* Image Type CVs */
int mag = 1 with {0,1,1,VIS, "Magnitude Image if 1",};
int pha = 0 with {0,1,0,VIS, "Phase Image if 1 ",};
int imag = 0 with {0,1,0,VIS, "Real image if 1 ",};
int qmag = 0 with {0,1,0,VIS, "Imag image if 1 ",};

/* Nex can not be accumulated with exorcist running.  exnex
 * calculates the number of frames/view that must be stored in BAM */
int exnex = 1 with {0,300,1,INVIS,"used for BAM considerations",};

/* slquant1 is number of pomp groups imaged in first pass for pomp */
int slquant1 = 1 with {0,SLTAB_MAX,1,INVIS,"# of locs in first pass",};
/* changed from psd_grad_acq_delay to psd_grd_wait.  YH  10/14/94 */
int psd_grd_wait = 56 with {0,,0,INVIS,
                            "data acquisition/gradient subsystem delay",};
int psd_rf_wait = 0 with {0,,0,INVIS,
			"delay between rf and gradient subsystems",};

/* pos_moment_start holds the time in us from the start of the sequence
   to the middle of the alpha pulse.  This is used to automate flow
   compensation and zeroth moment graphing tests.   */
int pos_moment_start = 0 with {0,,,INVIS, "Testing CV for moments.",};

/* mps1rf1_inst and scanrf1_inst are used to hold the index into
   the rf1 instruction for scan and mps1. This allows the code
   for MPS1Prescan to simply copy the rf1 waveform used in scan.
   Thus, MPS1 is simplified for non-typical rf pulses  */
int mps1rf1_inst = 0 with {0,,0,INVIS,"Instr. number for mps1 rf1 pulse",};
int scanrf1_inst = 0 with {0,,0,INVIS,"Instr. number for scan rf1 pulse",};

/* cfcarddelay holds the delay of the cardiac hardware  */
int cfcarddelay = 10 with {0,,10,INVIS, "Delay of the cardiac hardware (ms)",};

float GAM = 4257.59 with {0,,4257.59,INVIS, "Gamma for current nucleus.",};

int psd_card_hdwr_delay = 0 with {0,,0,INVIS,
				    "Cardiac hardware trigger delay.",};
int off90 = 80 with {0,,80,INVIS,"Offset to where real 90 occurs",};
int TR_SLOP = 2ms with {0,,2ms,INVIS,"Slack in TR for line gating",};
int TR_PASS = 50ms with {0,,50ms, INVIS,"Repetition time for pass entry pt",};
int TR_PASS3D = 550ms with {0,,550ms,INVIS,
			      "TR for pass entry pt in 3d scans",};
int csweight= 100 with {0,180,100,INVIS,
                   "Patient weight threshold for CS pulse width switch",};
float truenex = 0 with {,,0,INVIS,"Actual nex for odd nex npw scans",};
int eg_phaseres with {0,,128,INVIS,"Phase encode res after asym fov calcs",};
int sp_satcard_loc = 0 with {0,,,INVIS,"Flag sat placement with cardiac",};

int min_rfdycc; /* minimum seq time based on duty cycle (us) */
int min_rfavgpow; /* minimum seq time based on avg. power (us) */
int coll_prefls = 1 with {0,1,1,VIS,
                 "if 1, then adjust RBA to collect half the number of taps",};
/* following parameters are new for 55.  YH  10/14/94 */
int maxGradRes = 1 with {0,1,1,VIS,
                 "Maximize ramp resolution (0=no,1=yes)?",};

float dfg = 2 with {1.0,4.0,1.0,INVIS,
                 "Digital Filter Gain",};

float pg_beta = 1.0 with {0.0,1.0,1.0,VIS,
                  "Ramp transition time factor for pulsegen",};
     
int split_dab = 0 with
                  {0,1,0,INVIS,"Split dab packets: 0=no, 1=yes",};
 
float freq_scale = 1.0 with {0,10,,VIS,
          "FOV scale factor in frequency y direction",};
int numrecv = 1 with {1,,1,VIS, "number of receivers",};
 
/* for phase encoding */
int pe_on = 1 with {0,1,1,VIS,
                                          "Phase encoding on/off (0=off, 1=on).",};
 
float psd_targetscale = 1.0; /* %fullscale for amps-set in obloptimize */
 
/* CVs used to display logical gradient values calculated by
   obloptimize */
float logxfs; /* set equal to loggrd.xfs */
float logyfs; /* set equal to loggrd.yfs */
float logzfs; /* set equal to loggrd.zfs */
int logxrt; /* set equal to loggrd.xrt */
int logyrt; /* set equal to loggrd.yrt */
int logzrt; /* set equal to loggrd.zrt */
int logxft; /* set equal to loggrd.xft */
int logyft; /* set equal to loggrd.yft */
int logzft; /* set equal to loggrd.zft */
float logxfa; /* set equal to loggrd.xfa */
float logyfa; /* set equal to loggrd.yfa */
float logzfa; /* set equal to loggrd.zfa */
float logxcc; /* set equal to loggrd.xcc */
float logycc; /* set equal to loggrd.ycc */
float logzcc; /* set equal to loggrd.zcc */
float logxbeta; /* set equal to loggrd.xbeta */
float logybeta; /* set equal to loggrd.ybeta */
float logzbeta; /* set equal to loggrd.zbeta */
float logtx; /* set equal to loggrd.tx */
float logty; /* set equal to loggrd.ty */
float logtz; /* set equal to loggrd.tz */
float logtx_xy; /* set equal to loggrd.tx_xy */
float logtx_xz; /* set equal to loggrd.tx_xz */
float logty_xy; /* set equal to loggrd.ty_xy */
float logty_yz; /* set equal to loggrd.ty_yz */
float logtz_xz; /* set equal to loggrd.tz_xz */
float logtz_yz; /* set equal to loggrd.tz_yz */
float logtx_xyz; /* set equal to loggrd.tx_xyz */
float logty_xyz; /* set equal to loggrd.ty_xyz */
float logtz_xyz; /* set equal to loggrd.tz_xyz */

int min_rfrmsb1; /* minimum seq time based on rms B1 limitation (us). To be moved below
		  * min_avgpow later on 
                  */

float psd_zero = 0.0 with {0.0, 0.0, 0.0, INVIS, 
        "Dummy address of start/end amplitude for bridged pulse.",};


int minseqgram_t;              /* min seq time based on gram heating  */

/* gram pulse modulation width time per logical axis */
int lx_pwmtime; 
int ly_pwmtime;
int lz_pwmtime;

/* gram pulse modulation width time per physical axis  */
int px_pwmtime; 
int py_pwmtime;
int pz_pwmtime;

int minseqcoil_t;  /* minseq time based on coil heating  */

/* per axis loading in units of A^2*uSec */
float xa2s;
float ya2s;
float za2s;

/* min seq time based on gradient driver heating  */
int minseqgrddrv_t;      /* minseqtime based on gradient driver heating */
int minseqgrddrvx_t;     /* minseqtime based on X gradient driver heating */
int minseqgrddrvy_t;     /* minseqtime based on Y gradient driver heating */
int minseqgrddrvz_t;     /* minseqtime based on Z gradient driver heating */
float powerx;             /* total scaled power in X in Ampere^2 usec     */
float powery;             /* total scaled power in Y in Ampere^2 usec     */
float powerz;             /* total scaled power in Z in Ampere^2 usec     */
float pospowerx;          /* positive scaled power in X in Ampere^2 usec  */
float pospowery;          /* positive scaled power in Y in Ampere^2 usec  */
float pospowerz;          /* positive scaled power in Z in Ampere^2 usec  */
float negpowerx;          /* negative scaled power in X in Ampere^2 usec  */
float negpowery;          /* negative scaled power in Y in Ampere^2 usec  */
float negpowerz;          /* negative scaled power in Z in Ampere^2 usec  */
float amptrans_lx;          /* logical X ampere trans in (Amp/usec)*usec   */
float amptrans_ly;          /* logical Y ampere trans in (Amp/usec)*usec   */
float amptrans_lz;          /* logical Z ampere trans in (Amp/usec)*usec   */
float amptrans_px;        /* physical X ampere trans in (Amp/usec)*usec   */
float amptrans_py;        /* physical X ampere trans in (Amp/usec)*usec   */
float amptrans_pz;        /* physical Y ampere trans in (Amp/usec)*usec   */
float abspower_lx;          /* logical Z abs avrg ampere in Ampere * usec   */
float abspower_ly;          /* logical Y abs avrg ampere in Ampere * usec   */
float abspower_lz;          /* logical Z abs avrg ampere in Ampere * usec   */
float abspower_px;        /* physical X abs avrg amperere in Amp * usec   */
float abspower_py;        /* physical Y abs avrg amperere in Amp * usec   */
float abspower_pz;        /* physical Y abs avrg amperere in Amp * usec   */

int time_pgen = 0;       /* timing variable added to monitor pulsegen execution time RK 6/11/96 */

int cont_debug = 0 with { 0, 3, 0, VIS, "debug mode: 0=off, 1=plane, 2=sat, 3=slthk",};

/* CVs added for Maxwell correction for phase-contrast */
int maxpc_cor = 0 with {0,1,0, VIS,	"1: Maxwell correction enabled.",};
int maxpc_debug = 0 with {0,1,1, VIS, "1: Print out Maxwell coefficients.",};
int maxpc_points = 500 with {100,10000,500,VIS, 
 "Number of points to use for Maxwell correction",};

/*
 * MRIge47485 - Improved Gradient Duty Cycle
 */
/* Linear segment heating model */
int tsamp = 4 with {
    1,
    256,
    4,
    VIS,
    "Sampling rate for waveform digitization (usec).",
    ""
};
int seg_debug = 0 with {
    0,
    10,
    0,
    VIS,
    "Waveform segmentation debug level (0-10).",
    ""
};
int gradHeatMethod = PSD_OFF with {
    PSD_OFF,
    PSD_ON,
    PSD_ON,
    VIS,
    "Gradient Heating Method (0=Traditional, 1=Optimized).",
    ""
};
/* SGD gradient heating */
int minseqpwm_x;
int minseqpwm_y;
int minseqpwm_z;
int minseqgpm_t;

/* SGD performance simulation flag CV added by RJF for RTIA */
/* See minseqseg.c, minseqgrad.c for details. */
int sgd_perf_simulate = PSD_OFF with {
    PSD_OFF,
    PSD_ON,
    PSD_ON,
    VIS,
    "SGD option key flag.",
    ""
};
int gradHeatFile = PSD_OFF with {
    PSD_OFF,
    PSD_ON,
    PSD_ON,
    VIS,
    "Write Corner Points Files (0=OFF, 1=ON).",
    ""
};
int seqEntryIndex = 0 with {
    0,
    ,
    0,
    VIS,
    "Sequence Entry Index used for Heating Limits calculations.",
    ""
};


/* dB/dtOpt CVs - RJF */
int dbdt_debug = 0 with {
    0,
    32767, 
    0,
    VIS,
    "debug bitmask for dbdtOpt feature",
    ""
};

int reilly_mode = 0 with { 
    0, 
    1, 
    1, 
    VIS, 
    "Reilly Fraction estimation model - 0: Rectangular 1: convolution integral",
    ""
};

/* Use this cv to manually turn on/off dB/dt feature */

int dbdt_disable = 0 with { 
    0, 
    1, 
    0, 
    VIS, 
    "Switch to disable SlewRate optimization based on actual dB/dt", 
    ""
};

/* Add the following cv as a logic flag.  This depends on 3 conditions:
   1)Reilly Model being used, 2)CRM is present, 3)dB/dt feature is turned on.*/

int use_dbdt_opt = 1 with { 
    0, 
    1, 
    1, 
    INVIS, 
    "PSD Internal Flag for dB/dt optimization ", 
    ""
};

float srderate =  1.0 with { 
    1.0, 
    ,
    1.0,
    VIS,
    "Final Slew-rate derating factor ",
    ""
};

