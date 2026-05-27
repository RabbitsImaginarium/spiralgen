#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <math.h>
/*#include <values.h>*/
#include <stdio.h>
/*#include <support_decl.h>*/

using namespace std;


#define GAM 4257.0              /*gamma divided by 2 pi*/
#define LOCAL
#define PI 3.14159

#ifdef LOCALa
void exit(int status);
void thetadot(float t, float *y, float *ydot);		/*function which calculates time derivative of theta*/
void rkdumb(float *vstart,int nvar,float x1,float h,int nstep,void (*derivs)(float t, float *y, float *ydot));
void rk4(float *y,float *dydx,int n,float x,float h,float *yout,void (*derivs)(float t, float *y, float *ydot));
void thetadot2(float t,float *y,float *ydot);
int vd_spiral_wf_gen();

//GE Surrogate section

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
/*float gmax=2.935933;
 * float slewmax=10.30;*/
/*these numbers are in gauss/cm*/
float gmax=2.28; //3.285;
float slewmax=5;//11.498;

//float a_spiral;                 /*Amplitude constant for spiral generation*/
//float b_spiral;                 /*phase constant for spiral generation*/
float grad;			/*gradient magnitude*/
float tempa,tempb,d;			/*temporary variables*/
int opxres = 512;
int opyres = 32;
float opfov = 380;
int rhimsize = 64;
float density_factor = 10;
float k_a = 00;
float k_b = 100;
int ipx_B0 = 1;
int pts_per_spiral = opxres;
float A_spiral, A_spiral_1;
float A_spiral_a = nspirals * ipx / (2.0*PI*(opfov)/10.0);
float A_spiral_b = density_factor * A_spiral_a;
float A_spiral_B0 = 1.0 * ipx_B0 / (2.0*PI*((opfov)/10.0));
float theta_a = .5*k_a/100.0/A_spiral_a/(float)opfov*((float)rhimsize*10.0);
float theta_b = (k_b/100.0/(float)opfov*((float)rhimsize*10.0) + theta_a*(A_spiral_b - A_spiral_a))/(A_spiral_b + A_spiral_a);
float bw=125;
//float glscale=1000000;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char ** argv) {
    if(argc>1){
        opxres = atoi(argv[1]);
        nright = opxres;
        opyres = atoi(argv[2]);
        opfov = atoi(argv[3]);
        bw = atof(argv[4]); //130104 atof
        slewmax = atof(argv[5]);
        gmax = atof(argv[6]);
    }
    cout<< "Generating " << opyres << " Spirals with " << opxres << " pts";
    cout << "\n";
    res_grad_ms = 1/bw;
    pts_per_spiral = opxres;
    nspirals = opyres;
    A_spiral_a = nspirals * ipx / (2.0*PI*(opfov)/10.0);
    A_spiral_b = density_factor * A_spiral_a;
    A_spiral_B0 = 1.0 * ipx_B0 / (2.0*PI*((opfov)/10.0));
    theta_a = .5*k_a/100.0/A_spiral_a/(float)opfov*((float)rhimsize*10.0);
    theta_b = (k_b/100.0/(float)opfov*((float)rhimsize*10.0) + theta_a*(A_spiral_b - A_spiral_a))/(A_spiral_b + A_spiral_a);
    cout << theta_a << " " << theta_b << "\n";
    vd_spiral_wf_gen();
}
#endif

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
    int nrewind = 0;
    float buf[3*16384*512];//buf[3*(opxres+nrewind)*(opyres+0)];
    int buf3[3*16384*512];//[3*(opxres+nrewind)*(opyres+0)];
    int buf2[5];
    float largest,largest_rho;
    float gx3,gy3; //temporary holders
#ifdef LOCAL
/*FILE *f1;
FILE *f2;*/
char message[80];
#endif
/*GLend*/

a = GAM*slewmax/1000.0;    /*units 1/(cm-msec*msec)*/
bb = 1000.0/(GAM*gmax);     /*units cm-msec*/

/*#ifndef LOCAL
printdbg("Entering SpiralPG routine", debugstate);
#endif
*/
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
    /*gx_space[nleft+i] = (short)(max_pg_wamp*gx) & ~WEOS_BIT;
     * gy_space[nleft+i] = (short)(max_pg_wamp*gy) & ~WEOS_BIT;*/
    tstart=xx[2];
    thetastart[1]=yy[1][2];
    thetastart[2]=yy[2][2];
    /*remove the scaling factor max_pg_wamp*/
    buf[count] =gx; //these are gradients.
    buf[count+1] = gy;
//    buf3[count] = (int)glscale*gx;
//    buf3[count+1] = (int)glscale*gy;
    count +=3;
    if (i==(nleft-1)) {
        kx0=ks*c;
        ky0=ks*s;
        gx0=gx;
        gy0=gy;
    }
}
/*GL120425 rewind this bytch*/
A_spiral_a = 0;
A_spiral_b = 0;
for(i=0;i<nrewind;i++){
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
    //gx_space[nleft+i] = (short)(max_pg_wamp*gx) & ~WEOS_BIT;
    //gy_space[nleft+i] = (short)(max_pg_wamp*gy) & ~WEOS_BIT;
    tstart=xx[2];
    thetastart[1]=yy[1][2];
    thetastart[2]=yy[2][2];
    /*remove the scaling factor max_pg_wamp*/
    buf[count] =(float)glscale*(float)gx; //these are gradients.
    buf[count+1] = (float)glscale*(float)gy;
    count +=3;
}
/*if (ipx==2) {
 * for (i=0;i<nleft;i++) {
 * gx_space[nleft-1-i]=gx_space[nleft+i];
 * gy_space[nleft-1-i]=gy_space[nleft+i];
 * }
 * }*/

kx1=ks*c;
ky1=ks*s;
gx1=gx;
gy1=gy;


//find the actual kspace position and density
//cumulative sum of all the gradients gives the k-space position
largest_rho=0;
largest = 0;
/*for(i=3;i<3*pts_per_spiral;i+=3)
 * {
 * gx3 = buf[i];           //store contents before changing
 * gy3 = buf[i+1];
 * buf[i] += buf[i-3];     //kx
 * buf[i+1] += buf[i-2];   //ky
 * buf[i+2] = fabs(gx3*buf[i] + gy3*buf[i+1]);  //density
 * }
 * GLREMOVED this kx scaling factor, want the actual gradient*//*GL120420, remove the normalization factor
  * if (buf[i+2] > largest_rho)
  * largest_rho = buf[i+2];
  * //what a hack. Normalize to +.5 to -.5
  * x = fabs((buf[i]*buf[i] + buf[i+1]*buf[i+1]));
  * if (x > largest)
  * largest = x;
  * }
                                                                *
  * //normalize the points as well
  * //calculated for largest^2
  * largest = sqrt(largest);
  * for(i=0;i<3*pts_per_spiral;i+=3)
  * {
                                                                *
  * buf[i] = buf[i]/(2*largest);
  * buf[i+1] = buf[i+1]/(2*largest);
  * buf[i+2] = buf[i+2]/largest_rho;
  * }
  */
//rotate the trajectory for all nspirals

for (i=1;i<nspirals;i++) {
    theta=i*2.0*PI/nspirals;
    c=cos(theta);
    s=sin(theta);
    /* JAS
     * l=3*2*nsamp*B0map; */
    l=0;
    for (k=0;k<pts_per_spiral;k++) {
        buf[count]=c*buf[l]-s*buf[l+1];
        buf[count+1]=s*buf[l]+c*buf[l+1];
        buf[count+2]=buf[l+2];
        l+=3;
        count +=3;
    }
} //for (i=1;i<nspirals)

#ifdef LOCAL
l=0;
for(i=0;i<50;i++)
{
    cout << buf[l] << "," << buf[l+1] << "," << buf[l+2] << "\n";
    l+=3;
}
#endif

//GL120419 DO NOT skip this for local compiling
#ifdef LOCAL
if (!(f1=fopen("kspc","w"))) {
    sprintf(message,"Couldn't open output file\n");
    perror(message);
    exit(1);
}
/*printf("%i\n%i\n%f\n%f\n",opxres,opyres,float(buf[1]),float(buf[2]));
 * fprintf(f1,"%i\n%i\n",opxres, opyres);*/
/*if ((int)(fwrite(buf,sizeof(float),3*(opxres+nrewind)*opyres,f1))!=(int)3*(opxres+nrewind)*opyres) {
 * printf("OUtput error\n");*/
fwrite(buf3,sizeof(int),3*(opxres+nrewind)*opyres,f1);

/*write a frigging header file*/
f2 = fopen("kspc.hdr","w");
buf2[0] = opxres;
buf2[1] = opyres;
buf2[2] = rhimsize;
buf2[3] = (int)opfov;
buf2[4] = (int)bw;
fwrite(buf2,sizeof(int),5,f2); //opxres,opyres,rhimsize,(int)opfov);
#endif
#ifndef LOCAL
rsp_ampx_0 = gx0*max_pg_wamp;
rsp_ampy_0 = gy0*max_pg_wamp;
rsp_ampx_1 = gx1*max_pg_wamp;
rsp_ampy_1 = gy1*max_pg_wamp;

/* set end-of-waveform bit on gx_space and gy_space */
gx_space[res_spiral_rd - 1] |= WEOS_BIT;
gy_space[res_spiral_rd - 1] |= WEOS_BIT;

rsp_ardx_0 = kx0*1000000.0/GAM + 0.5*(float)pw_gxwa*gx0*gmax;
rsp_ardy_0 = ky0*1000000.0/GAM + 0.5*(float)pw_gywa*gy0*gmax;
rsp_ardx_1 = kx1*1000000.0/GAM + 0.5*(float)pw_gxwd*gx1*gmax;
rsp_ardy_1 = ky1*1000000.0/GAM + 0.5*(float)pw_gywd*gy1*gmax;
rsp_fov = opfov;
rsp_rbw = oprbw;
rsp_nspirals = nspirals;
rsp_pts_per_spiral = pts_per_spiral;
rsp_slew = slewmax;
rsp_gmax = gmax;
rsp_nleft = nleft;
rsp_A_spiral_a = A_spiral_a;
rsp_A_spiral_b = A_spiral_b;
rsp_theta_a = theta_a;
rsp_theta_b = theta_b;
rsp_density_factor = density_factor;


printdbg("Calc spirals okay, starting pulse definitions", debugstate);

#endif

/*GLend*/
return 0;//SUCCESS;
}


#ifdef LOCAL
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
        if (x+h == x) printf("Step size too small in routine RKDUMB\n");
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
#endif
