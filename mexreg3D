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
    printf(" Welcome to regrid\n");
//declare variables
    mxArray *conf_in_m, *kx_in_m, *ky_in_m, *wcol_in_m, *datr_in_m, *dati_in_m, *ktab_in_m;
    mxArray *datr_out_m, *dati_out_m;
    const mwSize *dims;
    double *conf, *kx, *ky, *wcol, *datr, *dati, *ktab;
    double *datr_out, *dati_out;
    //int dimx, dimy, numdims;
    int i;//,j;
    
//associate inputs
    conf_in_m = mxDuplicateArray(prhs[0]);
    kx_in_m = mxDuplicateArray(prhs[1]);
    ky_in_m = mxDuplicateArray(prhs[2]);
    wcol_in_m = mxDuplicateArray(prhs[3]);
    datr_in_m = mxDuplicateArray(prhs[4]);
    dati_in_m = mxDuplicateArray(prhs[5]);
    ktab_in_m = mxDuplicateArray(prhs[6]);
//
//associate input pointers
    conf = mxGetPr(conf_in_m);
    kx = mxGetPr(kx_in_m);
    ky = mxGetPr(ky_in_m);
    wcol = mxGetPr(wcol_in_m);
    datr = mxGetPr(datr_in_m);
    dati = mxGetPr(dati_in_m);
    ktab = mxGetPr(ktab_in_m);
    
    
    //parse the configuration matrix
    int Ggrid = (int)conf[0];
    int nsamples = (int)conf[1];
    int ntab = (int)conf[2];
    float w = (float)conf[3];
    printf("%i %i %i %f\n", Ggrid, nsamples, ntab, w);// Ggrid << " " << w << " " << nsamples;
    
//associate outputs
    datr_out_m = plhs[0] = mxCreateDoubleMatrix(Ggrid*Ggrid,1,mxREAL);
    dati_out_m = plhs[1] = mxCreateDoubleMatrix(Ggrid*Ggrid,1,mxREAL);
    
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
    float dk;
    float fracdk;
    float fracpos;
    float pos;
    int ind1, ind2;
    float kernvalue;
    int gridcenter = Ggrid/2;
    float kernr = (double)w/(double)(2*Ggrid);
    
    struct node {
        int	data;
        struct node* next;  // node pointer
    };
    
    /*---------------- initalize stuff -----------------------*/
    float **outr;
    float **outi;
    outr = new float*[Ggrid];
    outi = new float*[Ggrid];
    for(i=0; i<Ggrid; i++)	{
        outr[i] = new float[Ggrid];
        outi[i] = new float[Ggrid];
    }
    for (i=0; i < Ggrid; i++) {
        for (int j=0; j < Ggrid; j++) {
            outr[i][j] = 0.0;
            outi[i][j] = 0.0;
        }
    }
    
    for (int kcount = 0; kcount < nsamples; kcount++) {
        
        datwtr[kcount] = datr[kcount] * wcol[kcount];   // product of data and weights
        datwti[kcount] = dati[kcount] * wcol[kcount];
    }
    
    
    /*------------------- regrid ------------------------ */
    
    for (int kcount = 0; kcount < nsamples; kcount++) {
        
        //cout << "kcount=" << kcount << endl;
        ixmin = (int) floor(kx[kcount]*Ggrid + gridcenter - w/2) - 1;
        iymin = (int) floor(ky[kcount]*Ggrid + gridcenter - w/2) - 1;
        ixmax = (int) ceil(kx[kcount]*Ggrid + gridcenter + w/2) - 1;
        iymax = (int) ceil(ky[kcount]*Ggrid + gridcenter + w/2) - 1;
        
        
        
        if (ixmin < 0) ixmin = 0;
        if (iymin < 0) iymin = 0;
        if (ixmax > Ggrid-1) ixmax = Ggrid - 1;
        if (iymax > Ggrid-1) iymax = Ggrid - 1;
        
        for (i = ixmin; i <= ixmax; i++) {
            
            dkx = (float)(i-gridcenter) / (float)Ggrid - kx[kcount];
            
            for (int j = iymin; j <= iymax; j++) {
                
                dky = (float)(j-gridcenter) / (float)Ggrid - ky[kcount];
                
                dk = sqrt(dkx*dkx + dky*dky);
                
                if (dk <= kernr)  {
                    
                    fracdk = (float)dk/kernr;
                    pos = (float)fracdk*ntab;
                    ind1 = (int)floor(pos);
                    ind2 = (int)ceil(pos);
                    fracpos = pos - ind1;
                    
                    kernvalue = ktab[ind1] - fracpos*(ktab[ind1] - ktab[ind2]);
                    outr[i][j] = outr[i][j] + kernvalue*datwtr[kcount];
                    outi[i][j] = outi[i][j] + kernvalue*datwti[kcount];
                    
                }  /* dk <= kernr */
                
            }  /* j loop */
            
        }  /* i loop */
        
    }  /* kcount */
    
    int count=0;
    for (i = 0; i < Ggrid; i++) {
        for (int j = 0; j < Ggrid; j++) {
            datr_out[count]= outr[i][j];
            dati_out[count] = outi[i][j];
            count++;
        }
        delete outr[i];
        delete outi[i];
    }
    
    delete datwtr;
    delete datwti;
    
    
    return;
}

