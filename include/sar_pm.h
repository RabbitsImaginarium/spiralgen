/*@Start***********************************************************/
/* GEMSBG Include File
 * Copyright (C) 1990 The General Electric Company
 *
 *      Include File Name:  sar_pm   
 *      Developer:
 *
 * $Source: sar_pm.h $
 * $Revision: 1.9 $  $Date: 2/10/98 17:04:15 $
 *
 */

/*@Synopsis 
	SAR Constants
*/     

/*@Description
 * ******************************************
   sar_pm.h
   Author: Wally Block
   Date:   12/05/89
   
   Description:  File contains all constants
   used in SAR calculations and some power 
   monitor calculations.

   Revision Date    Author     Desc.
   ________________________________________
   6/27/90          wfb        changed constants to reflect
				output from rfstat program.
				Duty cycle and max pulse width
				are substantially different from 4.x
				area, effective width, and absolute
				width for sincs and external pulses
				are within .001 of values used in
				4.x (exception is the silver -hoult)
				Pomp 90 constants are new.  These
				might have to change considering 
				affects of cosine modulation.

   8/30/90	   wfb          Entered new silver hoult
				values due to bug in 
				rfstat.

   1/17/92         CFL		New Constants for SLR pulses		
   				First 5.2 version spawned from version 1.2

   1/29/92     PL      Recovered changes lost in conversion to
                5.2.  New values based on output of latest rfstat
                program in psdrfstat project
   25Mar1992    dack         Add B1 constant for 1/2 sinc used in vasculars 
   02Apr1992    dack         Add B1 constant for sinc2 used in vasculars
   04/15/92     PL      Proper value for MAX_B1_FL901MC_90
                Add NOM_BW_FLPO1, NOM_BW_SEPO1 for pomps
   10/09/92	MHN		Added new parameters for invI0 inversion
                                pulse.
   10/22/92	MHN		Changed addressing RFI to RF0.
   06/03/93	WFB		Added RF constants for new 2dtof and
				3dgrass pulse.
   08/17/93	WFB		Added more constants for new 2dtof and
				3dgrass pulse.
   09/08/93     YS              Added RF constants for noramp pulses in 
                                3dtof/motsa
    9/15/93     PJG             Added 3D FGRE 90 pulse
                                Added chemsat pulses.
    9/17/93     YS              Added SAR_DTYCYC_NORAMP50.
   11/12/93     LP              Corrected  MAX_B1_SE1B4_180 per MRIge18455
5.5 MMS 11/22/93  hsi additions
		CHANGES INCLUDE:
        >  12/30/92  Srinivasan Added constants for INVI0 pulse
        >  05/24/93  MHN Added constants for GR30l pulse
        >  07/19/93  MHN Added constants for spectro-spatial pulse (sp15ms)
        >  08/12/93  MHN Redesigned GR30l pulse
        >  08/13/93  MHN Removed sp15ms, added new spectro-spatial pulse,
        >                for true-null (sstn), and opposed-null (sson)
        >  08/16/93  MHN Added constants for spectro-spatial pulse (sp15ms)
        >                as ssmisc pulse.
        >  08/31/93  MHN More modifications in GR30l pulse, for less ripple
        >                in stop-band.
        >  09/08/93  MHN Added new spect-spat pulses, rfanaon, rfanatn, and
        >                rfstdon.
  04/18/94  MMS    Added sar defines from fgre for truncated sinc pulse
  07/29/94  LP     corrected MAX_B1_SE1B4_180 per MRIge20817
  12/09/94  RJL	   Added new SLR max_int_b1_sq & max_rms_b1 based on new
		   rfstat additions. NOTE: values of -1 are flags for new
		   RF-header s.t. pulse is special. i.e. complex or null
		   pulse for which max_int_b1_sq and max_rms_b1 is not
		   defined. 
  12/16/94 RJL     Removed variables for spatial-spectral pulses removed
                   from psdrffiles:55 by FHE
  12/19/94 RJL     For complex and ramp pulses, ratio of designed max_b1
                   (from ASL) to max_b1 from rfstat is used to find
		   effective flip angle. The eff_flip is then used for
		   max_integral_b1_sq and max_rms_b1 values. This was
		   done after discussions with Matt Bernstein in ASL.
  01/10/95 RJL     Removed adiabatic silverhoult180 pulse. rf no longer
                   supported in product PSD's. See earlier versions
		   for information on this pulse.
  03/26/95 LP      Added remaining constants for ramp1 & ramp5 pulses

  11/30/95 VB      Merged sar_pmMT.h with sar_pm.h to include the data for
                   fermi05.rho.

  02/21/97 VB      Added SAR defines for adiabatic inversion pulse

  09/27/97 LP      MRIge41661. corrected maxpw values for ramp and noramp
                   pulses used in 3dtof. These are relatively high BW
                   RF pulses and the power monitor samples at 50us so it
                   cannot detect all the lobes. This situation was made worse
                   when the pulses were shrunk from the design of 5120 us
                   to 2048 us. This increases the width of the pulse the
                   power monitor expects to see.

 02/10/98 BJM      Added #defines for simple hard 180 for TripleIR in CV1.  
                   Search on *HARD* for relevant additions to file.
******************  Initial CV-1 version ******************

Version    Date    Person        Comment
-----------------------------------------------------------------
sccs1.8    12/12/97 JAP          Merged in changes from Lx-2.
		   09/16/98 RJF			 Added RTIA RF pulse params.

           02/04/99 SGT  MRIge43841 - correct the maxpw and dutycyc for the 60 and 124
                         slices 3D GRASS rf pulse. The origanal values were
                        	SAR_DTYCYC_3D = 0.1764
                        	SAR_MAXPW_3D = 0.1343
                         change them to:
                        	SAR_DTYCYC_3D = 1.0
                        	SAR_MAXPW_3D = 1.0
                         For detailed reason of the change, see proposal written
                         by Steve Tan.
*/
/*@End*********************************************************/

/* only do this once in any given compilation.*/
#ifndef  sar_pm_INCL
#define  sar_pm_INCL

#define NEO_FACTOR 1.4
/* children under 9 kg are neo infants */
#define NEO_WEIGHTLINE 9 
#define PW_STD 1000

/* ***************************************************************
   Effective Widths of Various Pulses
   Values are proportional to the integral of the amplitude squared
   (energy). 
   ************************************************************** */

#define SAR_PFACT 1.0  /* Scale factor to make 3.2, 4.0 to 4.5
			  look like 3.0, set to 1 in releases
			  greater than 4.5 */
#define SAR_PSINC05 0.3071 /* Sinc 05 */
#define SAR_PSINC1 0.2012 /* Sinc 1 */
#define SAR_PSINC2 0.1127 /* Sinc 2 */
#define SAR_PVSAT 0.5195  /* VRG SAT snc 2.1 */
#define SAR_PVSAT5 0.2484  /* VRG SAT snc 2.5 */
#define SAR_PLURIE 0.1122 /* Lurie Pulse */
#define SAR_PV180 0.1377  /* VRG 180 */
#define SAR_PPOMP90 0.2467 /* Pomp 90 */
#define SAR_PFL901MC 0.2516 /* SLR 90 */
#define SAR_PSE1B4 0.1799 /* SLR 180 */
#define SAR_PSEPO1 0.1218 /* SLR pomp 90 */
#define SAR_PFLPO1 0.1427 /* SLR pomp 180 */
#define SAR_PINVI0 0.1270 /* SLR inv 180 */
#define SAR_PPREPET 0.0468 /* SLR prepET 90 */
#define SAR_PRAMP 0.0993 /* SLR ramp */
#define SAR_PRAMP1 0.0959 /* SLR ramp1 */
#define SAR_PRAMP5 0.0942 /* SLR ramp5 */
#define SAR_P2DTF26 0.3579 /* 2D TOF pulse */
#define SAR_P3D 0.0650 /* 3D GRASS 60 and 124 slice pulse */
#define SAR_PNORAMP30 0.0931 /* SLR nonramp 30 */
#define SAR_PNORAMP50 0.0920 /* SLR nonramp 50 */
#define SAR_PALPHA1 0.1005   /* 3D FGRE 90 */
#define SAR_CSM_EFF_WIDTH 0.2468 /* ChemSatM pulse */
#define SAR_CSMIN8_EFF_WIDTH 0.4580 /* ChemSatMIN8 pulse */
#define SAR_CSMAX8_EFF_WIDTH 0.4621 /* ChemSatMax8 pulse */
#define SAR_PGR30L 0.1111 /* SLR GRE (30 deg) */
#define SAR_PFERMI05 0.6500 /* RF MT FERMI05 pulse */
#define SAR_ADIABATIC_EFF_WIDTH 0.3099  /* Adiabatic pulse */
#define SAR_HARD_EFF_WIDTH 1.0  /* simple HARD 180 */

/* ***************************************************************
   Integrated Area - Values are proportional to the integral of the
   waveform file divided by the number of points in the file.
   ************************************************************* */

/* These values were used in 4.x
#define SAR_ASINC1 0.25   Sinc 1 -Kludge to Match 3.0 
#define SAR_ASINC2 0.125 Sinc 2 -Kludge to Match 3.0 
*/


#define SAR_ASINC05 0.4219 /* sinc 0.5 */
#define SAR_ASINC1 0.2506 /* sinc 1 */
#define SAR_ASINC2 0.1245 /* sinc 2 */
#define SAR_AVSAT 0.3442  /* VRG SAT snc 2.1 */
#define SAR_AVSAT5 0.2257 /* VRG SAT snc 2.5 */
#define SAR_ALURIE .1149  /* Lurie pulse */
#define SAR_AV180 0.1160  /* VRG 180 */
#define SAR_APOMP90 0.2249 /* Pomp 90 */
#define SAR_AFL901MC 0.2909 /* SLR 90 */
#define SAR_ASE1B4 0.1867 /* SLR 180 */
#define SAR_ASEPO1 0.1252 /* SLR pomp 90 */
#define SAR_AFLPO1 0.1495 /* SLR pomp 180 */
#define SAR_AINVI0 0.1312 /* SLR inv 180 */
#define SAR_APREPET 0.0488 /* SLR prepET 90 */
#define SAR_ARAMP 0.0895 /* SLR ramp */
#define SAR_ARAMP1 0.0881 /* SLR ramp1 */
#define SAR_ARAMP5 0.0873 /* SLR ramp5 */
#define SAR_A2DTF26 0.4898 /* 2DTOF pulse */
#define SAR_A3D 0.0577 /* 3D GRASS 60 and 124 slice pulse */
#define SAR_ANORAMP30 0.0866 /* 30 degree SLR nonramp */
#define SAR_ANORAMP50 0.0853 /* 50 degree SLR nonramp */
#define SAR_AALPHA1 0.0949   /* 3D FGRE 90 */
#define SAR_CSM_AREA      0.2734 /* ChemSatM pulse */
#define SAR_CSMIN8_AREA      0.6084 /* ChemSatMIN8 pulse */
#define SAR_CSMAX8_AREA      0.6124 /* ChemSatMax8 pulse */
#define SAR_AGR30L 0.1229 /* SLR GRE (30 deg) */
#define SAR_AFERMI05 0.6999 /* RF MT FERMI05 pulse */
#define SAR_A_ADIABATIC 0.4634  /* Adiabatic pulse */
#define SAR_AHARD 1.0  /* Simple HARD 180 */

/* *************************************************************
   Absolute Width - Values are proportional to the integral of 
   absolute value of each point divided by the number of points in
   the file.
   ************************************************************ */


#define SAR_ABS_SINC05 0.4219 /* Sinc 0.5 */
#define SAR_ABS_SINC1 0.2852 /* Sinc 1 */
#define SAR_ABS_SINC2 0.1781 /* Sinc 2 */
#define SAR_ABS_VSAT 0.6287 /* VRG SAT snc 2.1 */
#define SAR_ABS_VSAT5 0.3227  /* VRG SAT snc 2.5 */
#define SAR_ABS_LURIE 0.1902 /* Lurie Pulse */
#define SAR_ABS_V180 0.2444  /* VRG 180 */
#define SAR_ABS_POMP90 0.3215 /* pomp 90 */
#define SAR_ABS_FL901MC 0.3728 /* SLR 90 */
#define SAR_ABS_SE1B4 0.2874 /* SLR 180 */
#define SAR_ABS_SEPO1 0.2142 /* SLR pomp 90 */
#define SAR_ABS_FLPO1 0.2239 /* SLR pomp 180 */
#define SAR_ABS_INVI0 0.2172 /* SLR inv 180 */
#define SAR_ABS_PREPET 0.0945 /* SLR prepET 90 */
#define SAR_ABS_RAMP 0.1941 /* SLR ramp */
#define SAR_ABS_RAMP1 0.1861 /* SLR ramp1 */
#define SAR_ABS_RAMP5 0.1811 /* SLR ramp5 */
#define SAR_ABS_2DTF26 0.4898 /* 2DTOF pulse */
#define SAR_ABS_3D 0.1361 /* 3D GRASS 60 and 124 slice pulse */
#define SAR_ABS_NORAMP30 0.1772 /* 30 degree SLR nonramp */
#define SAR_ABS_NORAMP50 0.1759 /* 50 degree SLR nonramp */
#define SAR_ABS_ALPHA1 0.1878   /* 3D FGRE 90 */
#define SAR_CSM_ABS_WIDTH 0.3652 /* ChemSatM pulse */
#define SAR_CSMIN8_ABS_WIDTH 0.6084 /* ChemSatMin8 pulse */
#define SAR_CSMAX8_ABS_WIDTH 0.6124 /* ChemSatMax8 pulse */
#define SAR_ABS_GR30L 0.1759 /* SLR GRE (30 deg) */
#define SAR_ABS_FERMI05 0.69988 /* RF MT fermi05 pulse */
#define SAR_ABS_ADIABATIC 0.4634  /* Adiabatic pulse */
#define SAR_ABS_HARD 1.0  /* simple HARD 180 */

/* **************************************************************
   %  of Pulse Width whose widest lobe is above 5% power
      (actually widest lobe above .1 %)
   *********************************************************** */

#define SAR_MAXPW_SINC05 1.0   /* sinc 0.5 */
#define SAR_MAXPW_SINC1 0.500 /* Sinc 1 */
#define SAR_MAXPW_SINC2 0.250 /* Sinc 2 */
#define SAR_MAXPW_VSAT5 0.3255 /* VRG sat 2/8.7 */
#define SAR_MAXPW_LURIE 0.2348 /* Lurie Pulse */
#define SAR_MAXPW_V180  0.2422 /* VRG 180 */
#define SAR_MAXPW_POMP90 0.3268 /* Pomp 90 */
#define SAR_MAXPW_FL901MC 0.6160 /* SLR 90 */
#define SAR_MAXPW_SE1B4 0.4486 /* SLR 180 */
#define SAR_MAXPW_SEPO1 0.2947 /* SLR pomp 90 */
#define SAR_MAXPW_FLPO1 0.3260 /* SLR pomp 180 */
#define SAR_MAXPW_INVI0 0.3133 /* SLR inv 180 */
#define SAR_MAXPW_PREPET 0.0978 /* SLR prepET 90 */
#define SAR_MAXPW_RAMP 0.8 /* SLR ramp MRIge41661*/
#define SAR_MAXPW_RAMP1 0.8 /* SLR ramp1 MRIge41661*/
#define SAR_MAXPW_RAMP5 0.8 /* SLR ramp5 MRIge41661*/
#define SAR_MAXPW_2DTF26 0.9923 /* 2D TOF pulse */
#define SAR_MAXPW_3D 1.0 	/* 3D GRASS 60 and 124 slice pulse */
#define SAR_MAXPW_NORAMP30 0.8 /* 30 degree SLR nonramp MRIge41661*/
#define SAR_MAXPW_NORAMP50 0.8 /* 50 degree SLR nonramp MRIge41661*/
#define SAR_MAXPW_ALPHA1 0.2132   /* 3D FGRE 90 */
#define SAR_CSM_MAX_PW    0.5329  /* ChemSatM pulse */
#define SAR_CSMIN8_MAX_PW    0.9950 /* ChemSatMin8 pulse */
#define SAR_CSMAX8_MAX_PW    0.9950 /* ChemSatMax8 pulse */
#define SAR_MAXPW_GR30L 0.2462 /* SLR GRE (30deg) for hi grad st */
#define SAR_MAXPW_FERMI05 1.0 /* RF MT FERMI05 pulse */
#define SAR_MAXPW_ADIABATIC 1.0  /* Adiabatic pulse */
#define SAR_MAXPW_HARD 1.0  /* simple HARD 180 */

/* **************************************************************
   % of Pulse Widths above 5% power
   *********************************************************** */


#define SAR_DTYCYC_SINC05 1.0  /* sinc 0.5 */
#define SAR_DTYCYC_SINC1 0.500 /* Sinc 1 */
#define SAR_DTYCYC_SINC2 0.250 /* Sinc 2 */
#define SAR_DTYCYC_VSAT5 0.4118 /* VRG sat 2/8.7 */
#define SAR_DTYCYC_LURIE 0.2348 /* Lurie Pulse */
#define SAR_DTYCYC_V180  0.3145 /* VRG 180 */
#define SAR_DTYCYC_POMP90 0.4129 /* Pomp 90 */
#define SAR_DTYCYC_FL901MC 0.6160 /* SLR 90 */
#define SAR_DTYCYC_SE1B4 0.4486 /* SLR 180 */
#define SAR_DTYCYC_SEPO1 0.2947 /* SLR pomp 90 */
#define SAR_DTYCYC_FLPO1 0.3260 /* SLR pomp 180 */
#define SAR_DTYCYC_INVI0 0.3133 /* SLR inv 180 */
#define SAR_DTYCYC_PREPET 0.0978 /* SLR prepET 90 */
#define SAR_DTYCYC_RAMP 0.2676 /* SLR ramp */
#define SAR_DTYCYC_RAMP1 0.2500 /* SLR ramp1 */
#define SAR_DTYCYC_RAMP5 0.2441 /* SLR ramp5 */
#define SAR_DTYCYC_2DTF26 0.9923 /* 2DTOF pulse */
#define SAR_DTYCYC_3D 1.0 	/* 3D GRASS 60 and 124 slice pulse */
#define SAR_DTYCYC_NORAMP30 0.2387 /* 30 degree SLR nonramp */
#define SAR_DTYCYC_NORAMP50 0.2368 /* 50 degree SLR nonramp */
#define SAR_DTYCYC_ALPHA1 0.2633   /* 3D FGRE 90 */
#define SAR_CSM_DUTY_CYC  0.5329   /* ChemSatM pulse */
#define SAR_CSMIN8_DUTY_CYC  0.9950 /* ChemSatMin8 pulse */
#define SAR_CSMAX8_DUTY_CYC  0.9950 /* ChemSatMax8 pulse*/
#define SAR_DTYCYC_GR30L 0.2462 /* SLR GRE (30deg) for hi grad st */
#define SAR_DTYCYC_FERMI05 1.0 /* RF MT FERMI05 pulse */
#define SAR_DTYCYC_ADIABATIC 1.0 /* Adiabatic pulse */
#define SAR_DTYCYC_HARD 1.0 /* simple HARD 180 */

/* **************************************************************
   New constants for SLR and Max B1 scaling
   *********************************************************** */

#define RES_FL901MC_RF1 250
#define RES_SE1B4_RF2 400
#define RES_INVI0_RF0 250
#define RES_PREPET    625
#define RES_GR30L_RF1 400
#define RES_SILVER 432 /* adiabatic pulse */
#define RES_HARD 256   /* HARD 180 */

/* Max B1 for a 3.5 ms 1/2 sinc 90 */
#define SAR_MAXB1_SINC05 0.0398  

/* Max B1 for a 3.2ms sinc2 90 */
#define SAR_MAXB1_SINC2_90 0.1474

/* Max B1 for a 3.2ms Sinc 1 90 */
#define MAX_B1_SINC1_90 0.0732

/* Max B1 for a 3.2ms Sinc 1 180 */
#define MAX_B1_SINC1_180 0.1464

/* Max B1 for a 5.12ms LURIE VRG 90 */
#define MAX_B1_LURIE_90 0.0999

/* Max B1 for a 5.12ms VRG 180 */
#define MAX_B1_VRG_180 0.1977

/* Max B1 for a 3.2 ms se1b4 180. This pulse has a designed dip on resonance that is wanted
per Matt Bernstein-ASL */
#define MAX_B1_SE1B4_180 0.177      /* Designed value. eff_max_b1 from rfstat is 0.0197 */

/* Max B1 for a 5.0 ms invI0 180 */
#define MAX_B1_INVI0_180 0.1791

/* Max B1 for a 15 ms prepET 90 */
#define MAX_B1_PREPET_90 0.0803

/* Max B1 for a 4.0 ms fl901mc 90 */
#define MAX_B1_FL901MC_90 0.0505

/* Max B1 for a 4.0 ms dblsatlo 90 */
#define MAX_B1_DBLSATL0 0.0894

/* Max B1 for a 5.12 ms VRG SAT snc 2.5 */
#define MAX_B1_VSAT5 0.1016

/* Max B1 for a 5.12 ms sepo1 180 */
#define MAX_B1_SEPO1_180 0.1831

/* Max B1 for a 5.12 ms flpo1 90 */
#define MAX_B1_FLPO1_90 0.0767

/* Max B1 for 6.4 ms 3mmPOMP pulse */
#define MAX_B1_3MMPOMP90 0.0408

/* Max B1 for a 6.4 ms 3mm VRG180 pulse */
#define MAX_B1_3MMVRG_180 0.1582

/* Max B1 for a 5.12 ms POMP 90 */
#define MAX_B1_POMP_90 0.0510    

/* Max B1 for SLR Ramp, with flip angle of 90 degrees and */
/* pulse width of 3.2 ms. */
#define SAR_MAXB1_RAMP 0.2096      /* Designed value. rfstat values is .2051 */
#define SAR_MAXB1_RAMP1 0.2096      /* Designed value. rfstat values is .2083 */
#define SAR_MAXB1_RAMP5 0.2096      /* Designed value. rfstat values is .2012 */

/* Max B1 for an 3.2ms SLR excitation pulse for GRE (30deg) @ hi grad st */
#define MAX_B1_GR30L 0.0498

/* Max B1 for 2DTOF pulse with flip angle of 90 and 
   pulse width of 2.6 ms */
#define SAR_MAXB1_2DTF26 0.0461 

/* Max B1 for 3DGRASS 60 and 124 slice  pulse with flip angle of 90 and 
   pulse width of 5.0 ms */
#define SAR_MAXB1_3D   0.2037  /* 3D GRASS 60 and 124 slice pulse */

/* Max B1 for SLR NoRamp optimized for 30 excitation, with norminal flip angle 
of 90 degrees and pulse width of 5.12 ms. */
#define SAR_MAXB1_NORAMP30 0.13239

/* Max B1 for SLR NoRamp optimized for 50 degree excitation, with norminal
flip angle of 90 degrees and  pulse width of 5.12 ms. */
#define SAR_MAXB1_NORAMP50 0.1343

/* Max B1 for 3D FGRE 90 degree flip with 9600 usec*/
#define SAR_MAXB1_ALPHA1 0.06463

/* Max B1 for ChemSatM pulse */
#define SAR_CSM_MAX_B1  0.01342

/* Max B1 for ChemSatMin8 pulse */
#define SAR_CSMIN8_MAX_B1 0.01341

/* Max B1 for chemSatMax8 pulse */
#define SAR_CSMAX8_MAX_B1 0.01185

/* Max B1 for MT pulse */
#define SAR_MAXB1_FERMI05 0.10489

/* Max B1 for Adiabatic pulse */
#define MAX_B1_ADIABATIC 0.02934

/* Max B1 for HARD 180 pulse */
#define MAX_B1_HARD 0.114682

/******************************************
 *    New SLR max_int_b1_sq in GG-msec	  *
 ******************************************/

/* Max Integral B1^2 for a 3.5 ms 1/2 sinc 90 */
#define SAR_MAX_INT_B1_SQ_SINC05 0.00170

/* Max Integral B1^2 for a 3.2ms sinc2 90 */
#define SAR_MAX_INT_B1_SQ_SINC2_90 0.00783

/* Max Integral B1^2 for a 3.2ms Sinc 1 90 */
#define MAX_INT_B1_SQ_SINC1_90 0.00345

/* Max Integral B1^2 for a 3.2ms Sinc 1 180 */
#define MAX_INT_B1_SQ_SINC1_180 0.01380

/* Max Integral B1^2 for a 5.12ms LURIE VRG 90 */
#define MAX_INT_B1_SQ_LURIE_90 0.00573

/* Max Integral B1^2 for a 5.12ms VRG 180 */
#define MAX_INT_B1_SQ_VRG_180 0.02754

/* Max Integral B1^2 for a 3.2 ms se1b4 180 */
#define MAX_INT_B1_SQ_SE1B4_180 0.01803

/* Max Integral B1^2 for a 5.0 ms invI0 180 */
#define MAX_INT_B1_SQ_INVI0_180 0.02037

/* Max Integral B1^2 for a 15.0 ms prepET 90 */
#define MAX_INT_B1_SQ_PREPET_90 0.004528

/* Max Integral B1^2 for a 4.0 ms fl901mc 90 */
#define MAX_INT_B1_SQ_FL901MC_90 0.00257

/* Max Integral B1^2 for a 4.0 ms dblsatlo 90 */
#define MAX_INT_B1_SQ_DBLSATL0 0.00470

/* Max Integral B1^2 for a 5.12 ms VRG SAT snc 2.5 */
#define MAX_INT_B1_SQ_VSAT5 0.01313

/* Max Integral B1^2 for a 5.12 ms sepo1 180 */
#define MAX_INT_B1_SQ_SEPO1_180 0.02090

/* Max Integral B1^2 for a 5.12 ms flpo1 90 */
#define MAX_INT_B1_SQ_FLPO1_90 0.00430

/* Max Integral B1^2 for 6.4 ms 3mmPOMP pulse */
#define MAX_INT_B1_SQ_3MMPOMP_90 0.00263

/* Max Integral B1^2 for a 6.4 ms 3mm VRG180 pulse */
#define MAX_INT_B1_SQ_3MMVRG_180 0.02205

/* Max Integral B1^2 for a 5.12 ms POMP 90 */
#define MAX_INT_B1_SQ_POMP_90 0.00328

/* Max Integral B1^2 for SLR Ramp, with flip angle of 90 degrees and */
/* pulse width of 3.2 ms. Calculated using eff_flip, see comment in header */
#define SAR_MAX_INT_B1_SQ_RAMP  0.01395
#define SAR_MAX_INT_B1_SQ_RAMP1 0.01349 
#define SAR_MAX_INT_B1_SQ_RAMP5 0.01325 


/* Max Integral B1^2 for an 3.2ms SLR excitation pulse for GRE (30deg) @ hi grad st */
#define MAX_INT_B1_SQ_GR30L 0.00088

/* Max Integral B1^2 for 2DTOF pulse with flip angle of 90 and 
   pulse width of 2.6 ms */
#define SAR_MAX_INT_B1_SQ_2DTF26 0.001978

/* Max Integral B1^2 for 3DGRASS 60 and 124 slice  pulse with flip angle of 90 and 
   pulse width of 5.0 ms */
#define SAR_MAX_INT_B1_SQ_3D 0.01349  /* 3D GRASS 60 and 124 slice pulse */

/* Max Integral B1^2 for SLR NoRamp optimized for 30 excitation, with norminal flip angle 
of 90 degrees and pulse width of 5.12 ms. */
#define SAR_MAX_INT_B1_SQ_NORAMP30 0.00836

/* Max Integral B1^2 for SLR NoRamp optimized for 50 degree excitation, with norminal
flip angle of 90 degrees and  pulse width of 5.12 ms.								  */
#define SAR_MAX_INT_B1_SQ_NORAMP50 0.00851

/* Max Integral B1^2 for 3D FGRE 90 degree flip with 9600 msec*/
#define SAR_MAX_INT_B1_SQ_ALPHA1 0.00401

/* Max Integral B1^2 for ChemSatM pulse */
#define SAR_CSM_MAX_INT_B1_SQ 0.000712

/* Max Integral B1^2 for ChemSatMin8 pulse */
#define SAR_CSMIN8_MAX_INT_B1_SQ 0.000658

/* Max Integral B1^2 for chemSatMax8 pulse */
#define SAR_CSMAX8_MAX_INT_B1_SQ 0.000519

/* Max Integral B1^2 for MT RF FERMI05 pulse */
#define SAR_MAX_INT_B1_SQ_FERMI05 0.057189

/* Max Integral B1^2 for Adiabatic pulse */
#define MAX_INT_B1_SQ_ADIABATIC 0.00230333

/* Max Integral B1^2 for HARD 180 pulse */
#define MAX_INT_B1_SQ_HARD 0.0134675

/******************************************
 *    New SLR max_rms_b1 in Gauss	  *
 ******************************************/
/* Max RMS B1 for a 3.5 ms 1/2 sinc 90 */
#define SAR_MAX_RMS_B1_SINC05 0.0220

/* Max RMS B1 for a 3.2ms sinc2 90 */
#define SAR_MAX_RMS_B1_SINC2_90 0.0495

/* Max RMS B1 for a 3.2ms Sinc 1 90 */
#define MAX_RMS_B1_SINC1_90 0.0328

/* Max RMS B1 for a 3.2ms Sinc 1 180 */
#define MAX_RMS_B1_SINC1_180 0.0657

/* Max RMS B1 for a 5.12ms LURIE VRG 90 */
#define MAX_RMS_B1_LURIE_90 0.03344

/* Max RMS B1 for a 5.12ms VRG 180 */
#define MAX_RMS_B1_VRG_180 0.0733

/* Max RMS B1 for a 3.2 ms se1b4 180 */
#define MAX_RMS_B1_SE1B4_180 0.0751

/* Max RMS B1 for a 5.0 ms invI0 180 */
#define MAX_RMS_B1_INVI0_180 0.0638

/* Max RMS B1 for a 15.0 ms prepET 90 */
#define MAX_RMS_B1_PREPET_90 0.01738

/* Max RMS B1 for a 4.0 ms fl901mc 90 */
#define MAX_RMS_B1_FL901MC_90 0.0253

/* Max RMS B1 for a 4.0 ms dblsatlo 90 */
#define MAX_RMS_B1_DBLSATL0 0.0343

/* Max RMS B1 for a 5.12 ms VRG SAT snc 2.5 */
#define MAX_RMS_B1_VSAT5 0.0506

/* Max RMS B1 for a 5.12 ms sepo1 180 */
#define MAX_RMS_B1_SEPO1_180 0.0639

/* Max RMS B1 for a 5.12 ms flpo1 90 */
#define MAX_RMS_B1_FLPO1_90 0.0290

/* Max RMS B1 for 6.4 ms 3mmPOMP pulse */
#define MAX_RMS_B1_3MMPOMP_90 0.0203

/* Max RMS B1 for a 6.4 ms 3mm VRG180 pulse */
#define MAX_RMS_B1_3MMVRG_180 0.0587

/* Max RMS B1 for a 5.12 ms POMP 90 */
#define MAX_RMS_B1_POMP_90 0.0253

/* Max RMS B1 for SLR Ramp, with flip angle of 90 degrees and */
/* pulse width of 3.2 ms.								  */
#define SAR_MAX_RMS_B1_RAMP  0.0660
#define SAR_MAX_RMS_B1_RAMP1 0.0649
#define SAR_MAX_RMS_B1_RAMP5 0.0643

/* Max RMS B1 for an 3.2ms SLR excitation pulse for GRE (30deg) @ hi grad st */
#define MAX_RMS_B1_GR30L 0.0166

/* Max RMS B1 for 2DTOF pulse with flip angle of 90 and 
   pulse width of 2.6 ms */
#define SAR_MAX_RMS_B1_2DTF26 0.0276

/* Max RMS B1 for 3DGRASS 60 and 124 slice  pulse with flip angle of 90 and 
   pulse width of 5.0 ms */
#define SAR_MAX_RMS_B1_3D 0.0519  /* 3D GRASS 60 and 124 slice pulse */

/* Max RMS B1 for SLR NoRamp optimized for 30 excitation, with norminal flip angle 
of 90 degrees and pulse width of 5.12 ms. */
#define SAR_MAX_RMS_B1_NORAMP30 0.0404

/* Max RMS B1 for SLR NoRamp optimized for 50 degree excitation, with norminal
flip angle of 90 degrees and  pulse width of 5.12 ms.								  */
#define SAR_MAX_RMS_B1_NORAMP50 0.0408

/* Max RMS B1 for 3D FGRE 90 degree flip with 9600 msec*/
#define SAR_MAX_RMS_B1_ALPHA1 0.02043

/* Max RMS B1 for ChemSatM pulse */
#define SAR_CSM_MAX_RMS_B1 0.00667

/* Max RMS B1 for ChemSatMin8 pulse */
#define SAR_CSMIN8_MAX_RMS_B1 0.00907

/* Max RMS B1 for chemSatMax8 pulse */
#define SAR_CSMAX8_MAX_RMS_B1 0.00806

/* Max RMS B1 for MT RF FERMI05 pulse */
#define SAR_MAX_RMS_B1_FERMI05 0.08455

/* Max RMS B1 for Adiabatic pulse */
#define MAX_RMS_B1_ADIABATIC 0.0163276

/* Max RMS B1 for HARD 180 pulse */
#define MAX_RMS_B1_HARD 0.114682

/* Nominal fwhm bandwidths for RF pulses in Hz */
#define NOM_BW_SINC1_90    1250.0
#define NOM_BW_SINC1_180   1250.0
#define NOM_BW_FL901MC_RF1  886.0
#define NOM_BW_SE1B4        905.0
#define NOM_BW_SEPO1        806.0
#define NOM_BW_FLPO1       1212.0
#define NOM_BW_DBLSATL0    1267.0
#define NOM_BW_INVI0        777.8
#define NOM_BW_PREPET      1250.0
#define NOM_BW_2DTF26       850.0
#define NOM_BW_3D      	   4000.0
#define NOM_BW_SINC2	   2500.0
#define NOM_BW_NORAMP30    2500.0
#define NOM_BW_NORAMP50    2500.0
#define NOM_BW_GR30L       2550.2
#define NOM_BW_HARD        1250.0
#define NOM_BW_RTIA        4000.0 

/* Nominal pulse widths for RF Pulses in us */

#define NOM_PW_3D          5000
#define NOM_PW_2DTF26      2600
#define NOM_PW_NORAMP30    5120
#define NOM_PW_NORAMP50    5120
#define SAR_CSM_NOM_PW    16000
#define SAR_CSMIN8_NOM_PW    8000
#define SAR_CSMAX8_NOM_PW    8000 
#define SAR_FERMI05_NOM_PW   8000
#define NOM_PW_ADIABATIC   8640
#define NOM_PW_HARD        1024
#define NOM_PW_RTIA     800 /* New RF pulse for RTIA - RJF */
#define NOM_PW_PREPET      15000 

/* Nominal flip angles for RF Pulses in degrees */
#define NOM_FA_3D            90.0
#define NOM_FA_2DTF26        90.0
#define SAR_CSM_NOM_FLIP  90.0 
#define SAR_CSMIN8_NOM_FLIP  100.0
#define SAR_CSMAX8_NOM_FLIP  89.0 
#define NOM_FA_RFMT          900.0
#define NOM_FA_ADIABATIC 43.82
#define NOM_FA_RTIA	30.0 /* New RF pulse for RTIA - RJF */
#define NOM_FA_PREPET   90.0


/* Isodelay factors for RF pulses in us,
   assume nominal pulse widths for entire RF pulse width */

#define ISO_3D              450
#define ISO_SINC2          1680
#define ISO_2DTF26         1280
#define ISO_RTIA	    378
#define ISO_PREPET         7584

/* Resolutions for RF Pulses */
#define RES_RF2DTF26        260 
#define RES_RF3D            500
#define RES_RFSINC2         800
#define RES_RFCSM           320 
#define RES_RFCSMIN8        400 
#define RES_RFCSMAX8        200  
#define RES_RFMT           1000
#define RES_RTIA	    400 


/* fgre truncated sinc pulse */
#define SAR_PTRUNC1 0.2673 /* Effective width of truncated sinc1(1 post lobe)*/
#define SAR_ATRUNC1 0.3453 /* Integrated area truncated sinc 1 (1 post lobe) */
#define SAR_ABS_TRUNC1 0.3683 /* truncated sinc 1 (1 post lobe) */
#define SAR_MAXPW_TRUNC1 0.5000 /* truncated sinc 1 (1 post lobe) */
#define SAR_DTYCYC_TRUNC1 0.5000/* truncated sinc 1 (1 post lobe) */
#define MAX_B1_TRUNC1_24_90 0.070/* truncated sinc 1 of 2.4ms pw(1 post lobe) */
#define MAX_B1_TRUNC1_15_90 0.112/* truncated sinc 1 of 1.5ms pw(1 post lobe) */

/* Output of rfstat on the new minimum phase SLR 1ms rf pulse */

#define SAR_PRTIA	    0.2913/* RTIA rfstat for effective width */
#define SAR_ARTIA	    0.4032  /* RTIA rfpulse stat out for area */
#define SAR_ABS_RTIA	    0.4032  /* RTIA rf pulse rfstat out for abs. width */
#define SAR_MAXPW_RTIA 	    0.9784 /* RTIA rfstat for maximum pulse width */
#define SAR_DTYCYC_RTIA     0.9874   /* RTIA rf pulse rfstat output for Duty cycle max*/
#define MAX_B1_RTIA_08_30   0.0606762  /* RTIA rf pulse rfstat output for B1 max */



#endif /* sar_pm_INCL */



