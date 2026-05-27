#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include "math.h"
#include "values.h"
#include "stdio.h"
#include "support_decl.h"

using namespace std;


#define GAM 4257.0              /*gamma divided by 2 pi*/
#define LOCAL


#ifdef LOCAL
void exit(int status);
void thetadot(float t, float *y, float *ydot);		/*function which calculates time derivative of theta*/
void rkdumb(float *vstart,int nvar,float x1,float h,int nstep,void (*derivs)(float t, float *y, float *ydot));
void rk4(float *y,float *dydx,int n,float x,float h,float *yout,void (*derivs)(float t, float *y, float *ydot));
void thetadot2(float t,float *y,float *ydot);
STATUS vd_spiral_wf_gen();

  //GE Surrogate section
 
  float a,bb,ks;
  int nspirals = 4;
  int nright = 4096;
  int nleft = 0;
  float res_grad_ms =.004;
  float th[3];
  float thd[3];
  short gx_space[16384];
  short gy_space[16384];
  float yy[3][3];           /*for 4th order Runge-Kutta*/
  float xx[3];              /*ditto*/
  int ipx =1;
float gmax=2.935933;
float slewmax=10.30;
//float a_spiral;                 /*Amplitude constant for spiral generation*/
//float b_spiral;                 /*phase constant for spiral generation*/
float grad;			/*gradient magnitude*/
float tempa,tempb,d;			/*temporary variables*/
int opxres = 4096;
int opyres = 20;
float opfov = 200; 
int rhimsize = 128;
float density_factor = 10;
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
int main(int argc, char ** argv) {
  cout << acos(-.86);
    
}
#endif
