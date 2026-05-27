/* Miscellaneous macros used by CV programmer to access CV structures.
   The comment between the '_' and the 'cv' allows the C preprocessor to
   recognize 'cv' as an argument to the macro.  For example, 'cvmax(optr, 5s)'
   gets expanded to '_optr.maxval = 5s'. 

   08/06/96 RJL  Added setpopup macro 
   05/01/97 RDJ  Add Ansi/krcc conditional
	         CONCAT3 is to concatonate prefix, macro argument, and
                 suffix for either ANSI or K&R

   09/21/1997 GFN Added a #ifndef block to avoid multiple inclusions.

   12/16/1997 BJM Initial cdp1 merge w/lx2 for CV1
*/

#ifndef epic_macros_h
#define epic_macros_h


#ifdef __STDC__
#define CONCAT3(a,b,c) a ## b ## c
#else
#define CONCAT3(a,b,c) a/**/b/**/c
#endif

/* changing the fields in a CV */
#define cvmax(cv,expr) CONCAT3(_,cv,.maxval) = expr
#define cvmin(cv,expr) CONCAT3(_,cv,.minval) = expr
#define cvdef(cv,expr) CONCAT3(_,cv,.defval) = expr
#define cvdesc(cv,string) CONCAT3(_,cv,.descr) = string
#define errornum(cv,num) CONCAT3(_,cv,.errnum) = num 
#define errorstring(cv,string) CONCAT3(_,cv,.errstr) = string
#define setexist(cv,val) CONCAT3(_,cv,.existflag) = val
#define setpopup(cv,val) CONCAT3(_,cv,.popupflag) = val
#define cvmod(cv,min,max,def,desc,num,string)\
    CONCAT3(_,cv,.minval) = min;\
    CONCAT3(_,cv,.maxval) = max;\
    CONCAT3(_,cv,.defval) = def;\
    CONCAT3(_,cv,.descr) = desc;\
    CONCAT3(_,cv,.errnum) = num;\
    CONCAT3(_,cv,.errstr) = string

/* accessing the fields in a CV */
#define exist(cv) (CONCAT3(_,cv,.existflag) ? cv : CONCAT3(_,cv,.defval))
#define existcv(cv) CONCAT3(_,cv,.existflag)
#define modified(cv) CONCAT3(_,cv,.modifiedflag)

/* Changing the fields in an export variable.  This is useful for dynamic
   sized export variables.  The first argument must be the name of the
   export variable whose size is changing and must contain the address
   of the data.  The second argument contains the new size of the
   export variable.  Example:

       some_struct *anExport;   --declaration of the export variable

       free(anExport);  --if there are any previous allocations, it is the
			-- caller's responsibility to free them
       newsize = 5 * sizeof(some_struct);  --reserve space for 5 structures
       anExport = (some_struct *)malloc(newsize);
       exportaddr(anExport, newsize);      --change the address and size
*/
#define exportaddr(exvar, nbytes)\
    CONCAT3(_,exvar,.addr) = (char *)exvar;\
    CONCAT3(_,exvar,.size) = nbytes

/* defining the PSD "header" */
#define abstract(string) char _header_abstract[] = string
#define psdname(string) char _header_name[] = string


#endif /* epic_macros_h */
