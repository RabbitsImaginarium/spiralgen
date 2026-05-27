
/* FILE is plr.h */
#define ACCURATE
#undef ACCURATE
#ifdef ACCURATE
  typedef double REAL;
  typedef struct {
					double x;
					double y;
                  } COMPLEX;
#define CALLOC_REAL(n) (REAL *) malloc((n)* sizeof(double))
#define CALLOC_COMPLEX(n) (COMPLEX *) malloc((n)*2*sizeof(double))
#else
  typedef float REAL;
  typedef struct {
					float x;
					float y;
                 } COMPLEX;
#define CALLOC_REAL(n) (REAL *) calloc(1,(unsigned)((n)*sizeof(float)))
#define CALLOC_COMPLEX(n) (COMPLEX *)calloc((unsigned)n,(unsigned)sizeof(COMPLEX))
#endif
/*                    COMPLEX MACROS                                    */
/*----------------------------------------------------------------------*/

		   /*|||   z = z1 + z2   |||*/
#define _CADD(z1,z2,z)  { z.x=z1.x+z2.x; z.y=z1.y+z2.y; }

		   /*|||   z = z1 - z2   |||*/
#define _CSUB(z1,z2,z)   { z.x=z1.x-z2.x; z.y=z1.y-z2.y; }



	    /*|||    sc = < z1 | z2 > = conjg(z1) *z2  |||*/
#define _CDOT(z1,z2,sc)  { auto REAL _dingo;\
			   _dingo = z1.x * z2.x + z1.y * z2.y ;\
			   sc.y = z1.x * z2.y - z2.x * z1.y;\
			   sc.x = _dingo ;\
			 }


		   /*|||   z = z1 * z2   |||*/
#define _CMUL(z1,z2,z) {auto REAL _donald;\
   _donald  = z1.x * z2.x - z1.y * z2.y;\
   z.y = z1.x * z2.y + z2.x * z1.y;\
   z.x = _donald ;\
 }

		   /*|||    z = conjg(z)  |||*/
#define _CONJG(z)        { z.y = -z.y; }
#define _CNEG(z)   { z.x = -z.x; z.y = -z.y ; }

		   /*|||    r = |z|**2    |||*/
#define _CNORM(z,r)      { r = z.x * z.x + z.y * z.y ; }

		   /*|||    z = z1 / z2    |||*/
#define _CDIV(z1,z2,z) {auto  REAL _dingo;\
					    auto  REAL _donald;\
			    _dingo =  z2.x * z2.x + z2.y * z2.y;\
			    _donald = (z1.x * z2.x + z1.y * z2.y)/_dingo ;\
			    z.y = (- z1.x * z2.y + z2.x *z1.y)/_dingo;\
			    z.x = _donald ; \
			 }
#define _CINV(z1,z)   {auto REAL _dingo;\
				  _dingo = z1.x * z1.x + z1.y * z1.y;\
                  z.x = z1.x / _dingo;\
				  z.y = -z1.y / _dingo;\
				  }
#define _CSQRT(z1,z)  {auto REAL _dingo;\
					   auto REAL _donald;\
					   _donald = hypot(z1.x,z1.y);\
					   if (_donald !=0.0)\
					   _dingo = atan2(z1.y,z1.x);\
					   _donald = sqrt(_donald);\
					   _dingo = 0.5 * _dingo;\
					   z.x = _donald * cos(_dingo);\
					   z.y = _donald * sin(_dingo);\
					   }
		   /*|||    z = z + z1 * z2  |||*/
#define _CMUAC(z1,z2,z)  {\
			   z.x += z1.x * z2.x - z1.y * z2.y ;\
			   z.y += z1.x * z2.y + z2.x * z1.y ;\
			 }
		    /*|||     z = (x , y)   |||*/
#define _CMPLX(re,im,z)    { z.x =re ; z.y =im; }

		    /*|||     z2 = z1 * r   |||*/
#define _CRMUL(z1,r,z2)  { z2.x = z1.x * r ; z2.y = z1.y *r; }

#define _CEQU(z1,z2) { z2.x = z1.x ; z2.y = z1.y ; }

/*-------------------------------------------------------------------*/
/* Complex scalar functions                                          */
/*-------------------------------------------------------------------*/
void plrerror();
COMPLEX Csqrt();
/*--------------------------------------------------------------------*/
/*            COMPLEX ARRAY functions declarations                    */
/*                                                                    */
/*  as an example:                                                    */
/*                                                                    */
/*     cvmule(a,b,c,n,stepa,step_a,step_b,step_c)                     */
/*                                                                    */
/*  will perform the component by component multiplication  of the    */
/*  complex vector a by the complex vector b , resuult in c           */
/*        c[i*step_c] = a[i*step_a] * b[i*step_b]                     */
/*                i = 0..n-1                                          */
/*  the steps are here for easy multidimensionnal extension           */
/*              see sources   VECT.C                                  */
/*--------------------------------------------------------------------*/
/* void cvmule(COMPLEX* ,COMPLEX*,COMPLEX*,int,int,int,int)  ;*/
             /*     a        b        c     n  sta stb stc  */
	         /*            c[]= a[] * b[]                   */

  void cvmule();

/* void cvadde(COMPLEX *,COMPLEX *,COMPLEX *,int,int,int,int)  ; */
	         /*            idem cvmule                      */
	         /*            c[]= a[] + b[]                   */

  void cvadde();

/* void cvsmule(COMPLEX *,COMPLEX *,COMPLEX *,int,int,int)     ;*/
        	  /*     a        k         c     n  sta  stc    */
	          /*            c[]= k *a[]                      */

  void cvsmule();
	
/* void cvsadde(COMPLEX *,COMPLEX *,COMPLEX *,int,int,int)     ; */
	 /*             idem cvsadde                     */
	 /*             c[]=k + a[]                      */

  void cvsadde();
  
/* void cvdote(COMPLEX *,COMPLEX *,COMPLEX *,int,int,int)      ;*/
	 /*      a       b        k      n   sta stb     */
	 /*             k = conj(a[]) * b                */

   void cvdote();

/* void cvmove(COMPLEX *,COMPLEX *,int,int,int);*/
	 /*     a         c       n  sta  stc            */
	 /*              c[] = a[]                        */

  void cvmove();
  void cvsma();
  void cvfdot();
  void cvrvrs();
  void cvconjg();
  void cvmode();
/*-------------------------------------------------------------------*/
/* void cffx:  executes the fft of length n, wether direct sens >0   */
/*             or reverse sens <0, of complex array "data"           */
/*             you have first to call (once for possibly several FFT)*/
/*             cffini:                                               */
/*             main()                                                */
/*             void *wrkftn;                                         */
/*             COMPLEX *data;                                        */
/*             void *cffini(),cffx,cffend()                          */
/*             {                                                     */
/*              data = CALLOC_COMPLEX(n);                            */
/*              wrkftn = cffini(n) ; reserves and init work arrays   */
/*              cffx(data,sens,wrkftn)                               */
/*              cffx ________________                                */
/*              cffend(wrkftn);      frees memory                    */
/*-------------------------------------------------------------------*/

/* void cffx(COMPLEX *,int,void *); */

  void cffx();

/*--------------------------------------------------------------------*/
/*  void *cffini(n): initialize dynamic work arrays for the FFT of    */
/*                   length n. Computes  once for all the COS and SIN */
/*                   and the bit reverse addresses                    */
/*  see cffx                                                          */
/*--------------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* void ccfend(): release work arrays used by FFT                   */
/*------------------------------------------------------------------*/

typedef struct
{
   int  length;
   COMPLEX *sw;
   int     *sbr;
} P_INFO;


