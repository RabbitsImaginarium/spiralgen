#include <matrix.h>
#include <mex.h>
#include <math.h>
#ifndef MWSIZE_MAX
typedef int mwSize;
typedef int mwIndex;
typedef int mwSignedIndex;

#if (defined(_LP64) || defined(_WIN64)) && !defined(MX_COMPAT_32)
/* Currentlyti 2^48 based on hardware limitations */
# define MWSIZE_MAX    281474976710655UL
# define MWINDEX_MAX   281474976710655UL
# define MWSINDEX_MAX  281474976710655L
# define MWSINDEX_MIN -281474976710655L
#else
# define MWSIZE_MAX    2147483647UL
# define MWINDEX_MAX   2147483647UL
# define MWSINDEX_MAX  2147483647L
# define MWSINDEX_MIN -2147483647L
#endif
#define MWSIZE_MIN    0UL
#define MWINDEX_MIN   0UL
#endif

#define PI 3.14159265
//#define GAM 4257.0              /*gamma divided by 2 pi in units of Hz/G*/
#define LOCAL
void thetadot(float t, float *y, float *ydot);		/*function which calculates time derivative of theta*/
void rkdumb(float *vstart,int nvar,float x1,float h,int nstep,void (*derivs)(float t, float *y, float *ydot));
void rk4(float *y,float *dydx,int n,float x,float h,float *yout,void (*derivs)(float t, float *y, float *ydot));
void thetadot2(float t,float *y,float *ydot);
int vd_spiral_wf_gen();
float a,bb,ks;
int nspirals = 32;
int nright = 512;
int nleft = 0;
float res_grad_ms =.004;
float th[3];
float thd[3];
short gx_space[16384];
short gy_space[16384];
float yy[3][3];           /*for 4th order Runge-Kutta*/
float xx[3];              /*ditto*/
int ipx =1;
/*these numbers are in gauss/cm*/
float gmax=2.28; //3.285;
float slewmax=5;//11.498;
float grad;			/*gradient magnitude*/
float tempa,tempb,d;			/*temporary variables*/
int opxres = 512;
int opyres = 32;
int opfov = 380;
int rhimsize = 64;
int nucleus=1;
float density_factor = 1;
float k_a = 50;
float k_b = 60;
int ipx_B0 = 1;
int pts_per_spiral = opxres;
float A_spiral, A_spiral_1;
float A_spiral_a = nspirals * ipx / (2.0*PI*(opfov)/10.0);
float A_spiral_b = density_factor * A_spiral_a;
float A_spiral_B0 = 1.0 * ipx_B0 / (2.0*PI*((opfov)/10.0));
float theta_a = .5*k_a/100.0/A_spiral_a/(float)opfov*((float)rhimsize*10.0);
float theta_b = (k_b/100.0/(float)opfov*((float)rhimsize*10.0) + theta_a*(A_spiral_b - A_spiral_a))/(A_spiral_b + A_spiral_a);
float bw=125;
double buf[2*16384];
float GAM = 4257;//4257 for 1H, 3240 for 3He, 1177 for 129Xe

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    
//declare variables
    mxArray *a_in_m, *gx_out_m, *gy_out_m;
    const mwSize *dims;
    double *a, *c, *d;
    int dimx, dimy, numdims;
    int i,j;
    
//associate inputs
    a_in_m = mxDuplicateArray(prhs[0]);
    
//figure out dimensions
    dims = mxGetDimensions(prhs[0]);
    numdims = mxGetNumberOfDimensions(prhs[0]);
    dimy = (int)dims[0]; dimx = (int)dims[1];
//associate input pointers
    a = mxGetPr(a_in_m);
    
    
    opxres = (int)a[0]; //points
    nright=opxres;
    opyres = (int)a[1]; //points
    opfov = (int)a[2]; //mm
    bw = (float)a[3]; //kHz
    slewmax = (float)a[4]; //gauss/cm/s
    gmax = (float)a[5];  //gauss/cm
    k_a = (int)a[6]; //percentage
    k_b = (int)a[7];//percentage
    density_factor = (float)a[8];
    nucleus = (int)a[9]; //nucleus
    rhimsize = (int)a[10]; //image size
    
    if(nucleus==129)
        GAM = 1177;//4257 for 1H, 3240 for 3He, 1177 for 129Xe
    else if (nucleus==3)
        GAM = 3240;
    else
        GAM = 4257;
    
    res_grad_ms = 1/(float)bw;
    pts_per_spiral = opxres;
    nspirals = opyres;
    A_spiral_a = nspirals * ipx / (2.0*PI*(opfov)/10.0);
    A_spiral_b = density_factor * A_spiral_a;
    A_spiral_B0 = 1.0 * ipx_B0 / (2.0*PI*((opfov)/10.0));
    theta_a = .5*k_a/100.0/A_spiral_a/(float)opfov*((float)rhimsize*10.0);
    theta_b = (k_b/100.0/(float)opfov*((float)rhimsize*10.0) + theta_a*(A_spiral_b - A_spiral_a))/(A_spiral_b + A_spiral_a);
     vd_spiral_wf_gen();
    //associate outputs
    gx_out_m = plhs[0] = mxCreateDoubleMatrix(opxres,1,mxREAL);
    gy_out_m = plhs[1] = mxCreateDoubleMatrix(opxres,1,mxREAL);
    
    c = mxGetPr(gx_out_m);
    d = mxGetPr(gy_out_m);
    int count = 0;
    for(int i=0;i<opxres;i++){
        c[i] = (double)buf[count];
        d[i] = (double)buf[count+1];
        count+=2;
    }
    return;
}

int vd_spiral_wf_gen()
{
    float gx,gy;                          /*x and y gradients*/
    float gx0,gy0;                        /*x and y gradients when i=nleft*/
    float gx1,gy1;                        /*x and y gradients when i=nright*/
    float kx0,ky0;                        /*kx and ky when i=nleft*/
    float kx1,ky1;                        /*kx and ky when i=nright*/
    float tstart;                         /*start time for spiral*/
    float theta;                          /*rotation angle*/
    float thetastart[3];                  /*start value of theta and its time derivative*/
    float s,c;                            /*sine and cosine of theta*/
    float x;                            /*temporary variable*/
    int i,k,l;                          /*loop counters*/
    int count;
    /*GL*/
    int nrewind = 400;
    /*GL removed on mexing
     * float buf[3*(opxres+nrewind)*(opyres+0)];
     * int buf3[3*(opxres+nrewind)*(opyres+0)];
     * int buf2[5];
     * float largest,largest_rho;
     * float gx3,gy3; //temporary holders
     *
     * FILE *f1;
     * FILE *f2;
     * char message[80];*/
    
    /*GLend*/
    
    a = GAM*slewmax/1000.0;    /*units 1/(cm-msec*msec)*/
    bb = 1000.0/(GAM*gmax);     /*units cm-msec*/
    /*GL*/
    tstart=0;
    thetastart[1]=0;
    thetastart[2]=0;
    l=0;
    count = 0;
    for (i=0;i<nright;i++) {
        rkdumb(thetastart,2,tstart,res_grad_ms,1,thetadot2);
        th[1]=yy[1][1];
        th[2]=yy[2][1];
        theta = yy[1][1];
        (*thetadot2)(tstart,th,thd);
        x=yy[2][1]*bb;
        c=cos(theta);
        s=sin(theta);
        gx=(A_spiral*c-ks*s)*x;
        gy=(A_spiral*s+ks*c)*x;
        tstart=xx[2];
        thetastart[1]=yy[1][2];
        thetastart[2]=yy[2][2];
        buf[count] =(double)gx; //these are gradients.
        buf[count+1] = (double)gy;
        // mexPrintf("%f, %f\n", (float)buf[count], (float)buf[count+1]);
        count +=2;
    }
    
//    removed rotations for now
//    kx1=ks*c;
//     ky1=ks*s;
//     gx1=gx;
//     gy1=gy;
//
//     for (i=1;i<nspirals;i++) {
//         theta=i*2.0*PI/nspirals;
//         c=cos(theta);
//         s=sin(theta);
//         /* JAS
//          * l=3*2*nsamp*B0map; */
//         l=0;
//         for (k=0;k<pts_per_spiral;k++) {
//             buf[count]=c*buf[l]-s*buf[l+1];
//             buf[count+1]=s*buf[l]+c*buf[l+1];
//             buf[count+2]=buf[l+2];
//             l+=3;
//             count +=3;
//         }
//     } //for (i=1;i<nspirals)
//
//     l=0;
    
//GL120419 DO NOT skip this for local compiling
    
    /*   GL removed on mexing */
//    if (!(f1=fopen("kspc","w"))) {
//         sprintf(message,"Couldn't open output file\n");
//         perror(message);
//         exit(1);
//     }
//     /*printf("%i\n%i\n%f\n%f\n",opxres,opyres,float(buf[1]),float(buf[2]));
//      * fprintf(f1,"%i\n%i\n",opxres, opyres);*/
//     /*if ((int)(fwrite(buf,sizeof(float),3*(opxres+nrewind)*opyres,f1))!=(int)3*(opxres+nrewind)*opyres) {
//      * printf("OUtput error\n");*/
//     fwrite(buf3,sizeof(int),3*(opxres+nrewind)*opyres,f1);
//
//     /*write a frigging header file*/
//     f2 = fopen("kspc.hdr","w");
//     buf2[0] = opxres;
//     buf2[1] = opyres;
//     buf2[2] = rhimsize;
//     buf2[3] = (int)opfov;
//     buf2[4] = (int)bw;
//     fwrite(buf2,sizeof(int),5,f2); //opxres,opyres,rhimsize,(int)opfov);
//
//     /*GLend*/
     mexPrintf("Designing Spirals for\n%i points %i arms, FOV=%imm BW=%fkHz\nSlew=%fG/cm/ms Gmax=%fG/cm, Gamma=%fMHz/T, imagesize %i\n", opxres, opyres, opfov, bw, slewmax, gmax, (float)GAM/100, rhimsize);
    mexPrintf("Derived Params:\nA_a=%f, A_b=%f, t_a=%f, t_b=%f , res_grad=%f \n", A_spiral_a, A_spiral_b,theta_a, theta_b, res_grad_ms);

    return 1;
      
}



void thetadot(float t, float *y,float *ydot)

{
    float eps=.99;			/*fraction of max gradient for gradient-limited case*/
    float y1,y2,y12,y22;		/*temporary variables*/
    float g,v,w,x,z;			/*temporary variables*/
    
    y1=y[1];
    y2=y[2];
    y12=y1*y1;
    y22=y2*y2;
    x=1.0+y12;
    
    ydot[1]=y2;
    ydot[2]=-y1*y22;
    g=y2*tempb*sqrt(x);			/*gradient magnitude normalized to 1*/
    
    if (g<eps) {			/*slew-rate limited case*/
        w=y22*(2.0+y12);
        v=tempa+d*(1.0-g);
        z=v*v*x-w*w;
        if (z<0) z=0;
        ydot[2]+=sqrt(z);
    }
    ydot[2]/=x;
}

void rk4(float *y,float *dydx,int n,float x,float h,float *yout,void(*derivs)(float t, float *y, float *ydot))
{
    int i;
    float xh,hh,h6;
    float dym[3],dyt[3],yt[3];
    hh=h*0.5;
    h6=h/6.0;
    xh=x+hh;
    for (i=1;i<=n;i++) yt[i]=y[i]+hh*dydx[i];
    (*derivs)(xh,yt,dyt);
    for (i=1;i<=n;i++) yt[i]=y[i]+hh*dyt[i];
    (*derivs)(xh,yt,dym);
    for (i=1;i<=n;i++) {
        yt[i]=y[i]+h*dym[i];
        dym[i] += dyt[i];
    }
    (*derivs)(x+h,yt,dyt);
    for (i=1;i<=n;i++)
        yout[i]=y[i]+h6*(dydx[i]+dyt[i]+2.0*dym[i]);
}

void rkdumb(float *vstart,int nvar,float x1,float h,int nstep,void (*derivs)(float t, float *y, float *ydot))
{
    int i,k;
    float x;
    float v[3],vout[3],dv[3];
    
    for (i=1;i<=nvar;i++) {
        v[i]=vstart[i];
        yy[i][1]=v[i];
    }
    xx[1]=x1;
    x=x1;
    for (k=1;k<=nstep;k++) {
        (*derivs)(x,v,dv);
        rk4(v,dv,nvar,x,h,vout,derivs);
        if (x+h == x) printf("Step size too small in routine RKDUMB");
        x += h;
        xx[k+1]=x;
        for (i=1;i<=nvar;i++) {
            v[i]=vout[i];
            yy[i][k+1]=v[i];
        }
    }
}

void thetadot2(float t,float *y,float *ydot)

/*Calculates derivatives for 4th order Runge-Kutta*/

{
    float eps=.99;
    float y1,y2,y4,y22;         /*temporary variables*/
    float g,v,w,x,z;                /*temporary variables*/
    float x1;                   /*temporary variables*/
    
    y1=y[1];                        /*theta*/
    y2=y[2];                        /*thetadot*/
    y22=y2*y2;                      /*thetadot squared*/
    
    if (y1>theta_b) {
        x=1;
        x1=0;
        ks=A_spiral_a*theta_b+.5*(A_spiral_b-A_spiral_a)*(theta_b-theta_a)+A_spiral_b*(y1-theta_b);
    }
    else if (y1>theta_a) {
        x=(y1-theta_a)/(theta_b-theta_a);
        x1=1/(theta_b-theta_a);
        ks=A_spiral_a*y1+(A_spiral_b-A_spiral_a)*(theta_b-theta_a)*x*x*x*(1-.5*x);
    }
    else {
        x=0;
        x1=0;
        ks=A_spiral_a*y1;
    }
    
    A_spiral=A_spiral_a+(A_spiral_b-A_spiral_a)*x*x*(3-2*x);
    
    A_spiral_1=(A_spiral_b-A_spiral_a)*x1*6*x*(1-x);
    
    v=ks*ks+A_spiral*A_spiral;
    
    ydot[1]=y2;
    
    y4=-A_spiral*y22*(ks+A_spiral_1)/v;             /*thetadotdot for gradient limited case*/
    
    g=bb*y2*sqrt(v);                 /*gradient magnitude normalized to 1*/
    
    if (fabs(g)<eps) {                      /*slew-rate limited case*/
        w=ks*ks+2*A_spiral*A_spiral;
        w=w*w+ks*A_spiral_1*(ks*A_spiral_1-2*ks*ks-4*A_spiral*A_spiral);
        z=a*a*v-y22*y22*w;
        if (z<0) z=0;
        ydot[2]=sqrt(z)/v+y4;
    }
    else {                                          /*gradient limited case*/
        ydot[2]=y4;
    }
    
} /* end thetadot2 */

