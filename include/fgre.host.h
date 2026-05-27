/*
 *  fgre.h
 *  
 *  This file contains the prototype declarations of the callback
 *  functions defined in fgre.e.
 *
 *  Language : EPIC/ANSI C
 *  Author   : Gabriel Fernandez
 *  Date     : 13-Jun-1997
 */
/* do not edit anything above this line */

/*
   Version    Author     Date       Comment
----------------------------------------------------------------------
     1.0       GFN    13-Jun-1997   Initial version.

     1.1       GFN    18-Sep-1997   Added Jason's performance enhancements.

     1.2       GFN    21-Dec-1997   Added ssiupdates() and set_dummy_phase()
                                    prototypes. They are for Exorcist and
                                    CMON code.

     1.3       GFN    20-Feb-1998   Removed K&R declarations.

     1.4       GFN    07-Mar-1998   Removed conditional options for
                                    Performance Enhancement.

     1.5       GFN    17-Apr-1998   Changed prototypes for psdisiupdate(),
                                    ssiupdates() and ssisat() to match
                                    definition of isivector().

     1.6       JAP    07-July-1998  Add prototype for get_pos_isi6().

          D. Thayer   01-Sep-1998   Made myscan a void return.

               RJF    16-Sep-1998   Added prototypes for RTIA functions
                                    defined in fgre. These functions may be
                                    moved to a support file later.

               RJF    14-Oct-1998   Deleted IPG side function prototypes
                                    created a new file for them.
                                    This file is renamed as fgre.host.h

               RJF    19-Oct-1998   Deleted the RTIA related function 
                                    prototypes. These are moved to 
                                    RTFgre.host.h now.

               GFN    06-Apr-1999   Removed prototypes already provided by
                                    psd_proto.h.

 */

#ifndef fgre_host_h
#define fgre_host_h

/*
 * @host section
 */
void myscan( void );
STATUS psd_dump_slice_info( void );
STATUS calc_info( DOUBLE bw, INT res, FILTER_INFO *info );
STATUS calc_filter( FILTER_INFO *info, INT res, PSD_FILTER_GEN *spec );
STATUS dump_filter( PSD_FILTER_GEN *spec );
STATUS create_fgre_pulses( PULSE_TABLE *pulse_table );
STATUS set_fgre_targets( PULSE_TABLE *pulse_table, const LOG_GRAD *p_loggrd,
                         INT flag);
STATUS cveval1( INT mod_filtst );

STATUS calc_xresfn( INT *Xres, FLOAT *Fnecholim, INT OPxres );
STATUS fwphase( INT *actte, INT *fullteflag, INT mintefe, INT mintenfe,
                INT llimte1, INT llimte2, INT llimte3,
                INT ulimte1, INT ulimte2, INT ulimte3);
STATUS mintefgre( INT *Minte, INT *Rd1a, INT *Rd1b, INT *tfeextra,
                  INT *a_pwgxw, INT *d_pwgxw, FLOAT *ampgx1,
                  INT *a_pwgx1, INT *c_pwgx1, INT *d_pwgx1,
                  FLOAT *ampgxfc, INT *a_pwgxfc, INT *c_pwgxfc,
                  INT *d_pwgxfc, DOUBLE fecho_factor, INT c_pwgxwl,
                  INT c_pwgxw, INT c_pwgxwr, DOUBLE ampgxw,
                  INT Trf1b, INT fctype, INT minseq1, INT minseq3 );
STATUS calc_vrgf( DOUBLE tsp, INT in_xres, INT out_xres, DOUBLE read_amp,
                  INT read_pw );
STATUS fgre_cveval_rfinit( void );

#endif /* fgre_host_h */

