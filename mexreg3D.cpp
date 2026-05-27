#include <matrix.h>
#include <mex.h>
#include <cstdio>
//#include <stdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;
#define PI 3.1415926535

/* Definitions to keep compatibility with earlier versions of ML */
#ifndef MWSIZE_MAX
typedef int mwSize;
typedef int mwIndex;
typedef int mwSignedIndex;

#if (defined(_LP64) || defined(_WIN64)) && !defined(MX_COMPAT_32)
/* Currently 2^48 based on hardware limitations */
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

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    printf(" Welcome to 3d Regrid\n");
//declare variables
    mxArray *conf_in_m, *kx_in_m, *ky_in_m, *wcol_in_m, *datr_in_m, *dati_in_m, *ktab_in_m;
    mxArray *datr_out_m, *dati_out_m;
    const mwSize *dims;
    double *conf, *kx, *ky, *wcol, *datr, *dati, *ktab;
    double *datr_out, *dati_out;
    //121204
    double *kz;
    mxArray *kz_in_m;//121204
    
    //int dimx, dimy, numdims;
    int i;//,j;
    
//associate inputs
    conf_in_m = mxDuplicateArray(prhs[0]);
    kx_in_m = mxDuplicateArray(prhs[1]);
    ky_in_m = mxDuplicateArray(prhs[2]);
    kz_in_m = mxDuplicateArray(prhs[3]);//121204 incremented everything
    wcol_in_m = mxDuplicateArray(prhs[4]);
    datr_in_m = mxDuplicateArray(prhs[5]);
    dati_in_m = mxDuplicateArray(prhs[6]);
    ktab_in_m = mxDuplicateArray(prhs[7]);
//
//associate input pointers
    conf = mxGetPr(conf_in_m);
    kx = mxGetPr(kx_in_m);
    ky = mxGetPr(ky_in_m);
    kz = mxGetPr(kz_in_m); //121204
    wcol = mxGetPr(wcol_in_m);
    datr = mxGetPr(datr_in_m);
    dati = mxGetPr(dati_in_m);
    ktab = mxGetPr(ktab_in_m);
    
    
    //parse the configuration matrix
    int Ggrid = (int)conf[0];
    int zlocations = (int)conf[1]; //121204
    int nsamples = (int)conf[2];
    int ntab = (int)conf[3];
    float w = (float)conf[4];
    //int weighting=(float)(conf[5]);
    printf("Gridsize=%i ZLocs=%i nsamples=%i ntab=%i width=%f\n", Ggrid, zlocations, nsamples, ntab, w);// Ggrid << " " << w << " " << nsamples;
    
//associate outputs
    datr_out_m = plhs[0] = mxCreateDoubleMatrix(Ggrid*Ggrid*zlocations,1,mxREAL);
    dati_out_m = plhs[1] = mxCreateDoubleMatrix(Ggrid*Ggrid*zlocations,1,mxREAL);
    
//associate output pointers
    datr_out = mxGetPr(datr_out_m);
    dati_out = mxGetPr(dati_out_m);
    
    
    
    float* datwtr = new float[nsamples];  // product of dat and weights
    float* datwti = new float[nsamples];
    
    
    //dims = mxGetDimensions(ktab_in_m);
    //int ntab = (int)dims[0];
    
    /*-------------- input output variables ------------ */
    int ixmin,ixmax;
    int iymin,iymax;
    float dkx, dky;
    float dkz;    //121204
    int izmin, izmax; //121204
    float dk;
    float fracdk;
    float fracpos;
    float pos;
    int ind1, ind2;
    float kernvalue;
    int gridcenter = Ggrid/2;
    int gridcenterz = zlocations/2;//121204
    float kernr = (double)w/(double)(2*Ggrid);
    
    struct node {
        int	data;
        struct node* next;  // node pointer
    };
    
    /*---------------- initalize stuff -----------------------*/
    float ***outr;
    float ***outi;
    outr = new float**[Ggrid];
    outi = new float**[Ggrid];
/*    for(i=0; i<Ggrid; i++)	{
        outr[i] = new float[Ggrid];
        outi[i] = new float[Ggrid];
    }
    for (i=0; i < Ggrid; i++) {
        for (int j=0; j < Ggrid; j++) {
            outr[i][j] = 0.0;
            outi[i][j] = 0.0;
        }
    }*/
    for (i=0; i < Ggrid; i++) {
        outr[i] = new float*[Ggrid];
        outi[i] = new float*[Ggrid];
        for (int j=0; j < Ggrid; j++) {
            outr[i][j] = new float[zlocations];
            outi[i][j] = new float[zlocations];
            for(int k=0;k<zlocations;k++){
                outr[i][j][k] = 0.0;
                outi[i][j][k] = 0.0;
            }
        }
    }
    
    for (int kcount = 0; kcount < nsamples; kcount++) {    
        datwtr[kcount] = datr[kcount] * wcol[kcount];   // product of data and weights
        datwti[kcount] = dati[kcount] * wcol[kcount];
    }
    printf("kernr=%f\n",kernr);
    
    /*------------------- regrid ------------------------ */
    for (int kcount = 0; kcount < nsamples; kcount++) {
        ixmin = (int) floor(kx[kcount]*Ggrid + gridcenter - w/2) - 1;
        iymin = (int) floor(ky[kcount]*Ggrid + gridcenter - w/2) - 1;
        ixmax = (int) ceil(kx[kcount]*Ggrid + gridcenter + w/2) - 1;
        iymax = (int) ceil(ky[kcount]*Ggrid + gridcenter + w/2) - 1;
        //121204
        //only want it to spread onto 1 slice at most
 //       izmin = (int) floor(kz[kcount]*zlocations + gridcenterz - w/2) - 1;
 //       izmax = (int) ceil(kz[kcount]*zlocations + gridcenterz + w/2) - 1;
        izmin = (int) floor(kz[kcount]*zlocations + gridcenterz ) - 1;
        //izmax = (int) ceil(kz[kcount]*zlocations + gridcenterz ) - 1;
        izmax = izmin+1; //single slice
        //printf("kz[kcount]=%f izmin=%i izmax=%i\n", kz[kcount], zlocations, gridcenterz, izmin, izmax);
        
        if (ixmin < 0) ixmin = 0;
        if (iymin < 0) iymin = 0;
        if (ixmax > Ggrid-1) ixmax = Ggrid - 1;
        if (iymax > Ggrid-1) iymax = Ggrid - 1;
        //121204
        if (izmin < 0) izmin = 0;
        if (izmax > zlocations-1) izmax = zlocations - 1;
        
        for (i = ixmin; i <= ixmax; i++) {
            
            dkx = (float)(i-gridcenter) / (float)Ggrid - kx[kcount];
            
            for (int j = iymin; j <= iymax; j++) {
                
                dky = (float)(j-gridcenter) / (float)Ggrid - ky[kcount];
                
                for (int k = izmin; k<= izmax; k++) {
                    
                    dkz = (float)(k-gridcenterz)/ (float)zlocations - kz[kcount];
                    
      
                    dk = sqrt(dkx*dkx + dky*dky + dkz*dkz); 
                    //printf("izmin=%i, izmax=%i, dk=%f, kzcount=%f\n ", izmin, izmax,dk, kz[kcount]);
                    //fflush(stdout);
                    
                    if (dk <= kernr)  {
                        fracdk = (float)dk/kernr;
                        pos = (float)fracdk*ntab;
                        ind1 = (int)floor(pos);
                        ind2 = (int)ceil(pos);
                        fracpos = pos - ind1;
                        kernvalue = ktab[ind1] - fracpos*(ktab[ind1] - ktab[ind2]);
                        outr[i][j][k] = outr[i][j][k] + kernvalue*datwtr[kcount];
                        outi[i][j][k] = outi[i][j][k] + kernvalue*datwti[kcount];
                        }  /* dk <= kernr */                
                }/*k loop*/        
            }  /* j loop */
        }  /* i loop */
    }  /* kcount */
  //  if(weighting==0){
        int count=0;
        for (i = 0; i < Ggrid; i++) {
            for (int j = 0; j < Ggrid; j++) {
                for(int k=0; k < zlocations; k++) {
                    
                    datr_out[count]= outr[i][j][k];
                    dati_out[count] = outi[i][j][k];
                    count++;
                }
                delete outr[i][j];
                delete outi[i][j];
            }
            delete outr[i];
            delete outi[i];
        }
        delete datwtr;
        delete datwti;
        
        return;
  /*  } else {
        printf("Generating Weights\n");
        printf("Ggrid=%i, gridcenter=%f, gridcenterz=%f", Ggrid,gridcenter, gridcenterz);
        float kxtemp;
        float kytemp;
        float kztemp;
        int xlow;
        int ylow;
        int zlow;
        float xd;
        float yd;
        float zd;
        float i1;
        float i2;
        float* wcol2 = new float[nsamples];		// new output weights
        for (int n = 0; n < nsamples; n++) {
            
            kxtemp = kx[n]*Ggrid + gridcenter;
            kytemp = ky[n]*Ggrid + gridcenter;
            kztemp = kz[n]*zlocations + gridcenterz;
            
            xlow = (int)floor(kxtemp);
            ylow = (int)floor(kytemp);
            zlow = (int)floor(kztemp);
            if(xlow>=Ggrid-2) {xlow=Ggrid-2;}
            if(ylow>=Ggrid-2) {ylow=Ggrid-2;}
            if(zlow>=zlocations-1) {zlow=zlocations-1;}
            
            if(xlow<=1) {xlow=1;}
            if(ylow<=1) {ylow=1;}
            if(zlow<=1) {zlow=1;}
            xd = kxtemp - xlow;
            yd = kytemp - ylow;
            zd = kztemp - zlow;
            
            // tri-linear interpolation
            //i1 = outr[xlow][ylow][zlow]*(1-zd) + outr[xlow][ylow][zlow+1]*zd;
            //i2 = outr[xlow][ylow+1][zlow]*(1-zd) + outr[xlow][ylow+1][zlow+1]*zd;
            //j1 = outr[xlow+1][ylow][zlow]*(1-zd) + outr[xlow+1][ylow][zlow+1]*zd;
            //j2 = outr[xlow+1][ylow+1][zlow]*(1-zd) + outr[xlow+1][ylow+1][zlow+1]*zd;
            //	w1 = i1*(1-yd) + i2*d;
            //	w2 = j1*(1-yd) + j2*yd;
            //	wcol2[n] = w1*(1-xd) + w2*xd;
            
            // bi-linear interpolation
            if(n>4000){printf("n=%i, xd=%f yd=%f zd=%f xlow=%i ylow=%i zlow=%i\n",n,xd, yd, zd, xlow, ylow, zlow);} 
            i1 = yd*outr[xlow][ylow+1][zlow] + (1-yd)*outr[xlow][ylow][zlow];
            i2 = yd*outr[xlow+1][ylow+1][zlow] + (1-yd)*outr[xlow+1][ylow][zlow];
            datr_out[n] = i2*xd + i1*(1-xd);       
            //datr_out[n] = wcol2[n];
            //printf("i1=%f i2=%f\n", i1, i2);
        }  // n loop
        delete datwtr;
        delete wcol2;
        delete outr;
        
    }*/
}

