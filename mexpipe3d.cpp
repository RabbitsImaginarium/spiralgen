#include <matrix.h>
#include <mex.h>

#include <math.h>

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
//declare variables
    mxArray *conf_in_m, *kx_in_m, *ky_in_m, *wcol_in_m, *ktab_in_m;
    mxArray *datr_out_m;
    const mwSize *dims;
    double *conf, *kx, *ky, *wcol, *ktab;
    double *datr_out;
    //int dimx, dimy, numdims;
    int i;//,j;
    //121204
    double *kz;
    mxArray *kz_in_m;//121204
    
//associate inputs
    conf_in_m = mxDuplicateArray(prhs[0]);
    kx_in_m = mxDuplicateArray(prhs[1]);
    ky_in_m = mxDuplicateArray(prhs[2]);
    //121204
    kz_in_m = mxDuplicateArray(prhs[3]);
    wcol_in_m = mxDuplicateArray(prhs[4]);
    ktab_in_m = mxDuplicateArray(prhs[5]);
//
//associate input pointers
    conf = mxGetPr(conf_in_m);
    kx = mxGetPr(kx_in_m);
    ky = mxGetPr(ky_in_m);
    kz = mxGetPr(kz_in_m);
    wcol = mxGetPr(wcol_in_m);
    ktab = mxGetPr(ktab_in_m);
    
    //parse the configuration matrix
    int Ggrid = (int)conf[0];
    int zlocations = (int)conf[1]; //121205
    int nsamples = (int)conf[2];
    int ntab = (int)conf[3];
    float w = (float)conf[4];
    
//associate outputs
    datr_out_m = plhs[0] = mxCreateDoubleMatrix(nsamples,1,mxREAL);
    
//associate output pointers
    datr_out = mxGetPr(datr_out_m);
    
    
    
    /*-------------- input output variables ------------ */
    int ixmin,ixmax;
    int iymin,iymax;
    int izmin,izmax;
    float dkx, dky, dkz;
    float dk, dk_sq;
    float fracdk;
    float fracpos;
    float pos;
    int ind1, ind2;
    float kernvalue;
    int gridcenter = (Ggrid+10)/2;
    int zgridcenter = (zlocations+1)/2;
    float kernr = (double)w/(double)(2*Ggrid);
    float kernr_sq;
    
    //------ temp variables for weights interpolation
    int xlow;
    int ylow;
    int zlow;
    float xd;
    float yd;
    float zd;
    float i1;
    float i2;
    //float j1;
    //float j2;
    //float w1;
    //float w2;
    float kxtemp;
    float kytemp;
    float kztemp;
    //float* kz = new float[nsamples];
    float* datwtr = new float[nsamples];  // product of dat and weights
    float* wcol2 = new float[nsamples];		// new output weights
    
    
    
    /*---------------- initalize stuff -----------------------*/

    float ***outr;
    outr = new float**[Ggrid+20];
    for(int i=0; i<Ggrid+20; i++)	{
        outr[i] = new float*[Ggrid+20];
        for(int j=0; j<Ggrid+20; j++)	{
        	outr[i][j] = new float[zlocations+1];
            for(int k=0;k<zlocations+1;k++){
                outr[i][j][k] = 0;
            }
        }
    }
//    for (int i=0; i < Ggrid+20; i++) {
 //       for (int j=0; j < Ggrid+20; j++) {
            //for (int k=0; k < Ggrid+1; k++) {
            //    outr[i][j][k] = 0;
            //}
  //          outr[i][j] = 0;
  //      }
  //  }
    
    kernr_sq = kernr*kernr;
    printf("Intialized\n");
    
    /*------------------- regrid ------------------------ */
    
    for (int kcount = 0; kcount < nsamples; kcount++) {
        
        
        ixmin = (int) floor(kx[kcount]*Ggrid + gridcenter - w/2) - 1;
        iymin = (int) floor(ky[kcount]*Ggrid + gridcenter - w/2) - 1;
        izmin = (int) floor(kz[kcount]*zlocations + zgridcenter - w/2) - 1;
        ixmax = (int) ceil(kx[kcount]*Ggrid + gridcenter + w/2) - 1;
        iymax = (int) ceil(ky[kcount]*Ggrid + gridcenter + w/2) - 1;
        izmax = (int) ceil(kz[kcount]*zlocations + zgridcenter + w/2) - 1;
        
        
        
        if (ixmin < 0) ixmin = 0;
        if (iymin < 0) iymin = 0;
        if (izmin < 0) izmin = 0;
        //if (ixmax > Ggrid-1) ixmax = Ggrid - 1;
        //if (iymax > Ggrid-1) iymax = Ggrid - 1;
        //if (izmax > Ggrid-1) izmax = Ggrid - 1;
        
        
        for (int i = ixmin; i <= ixmax; i++) {
            
            
            
            dkx = (float)(i-gridcenter) / (float)Ggrid - kx[kcount];
            
            for (int j = iymin; j <= iymax; j++) {
                
                dky = (float)(j-gridcenter) / (float)Ggrid - ky[kcount];
                
                for (int k = izmin; k <= izmax; k++) {
                
                dkz = (float)(k-zgridcenter) / (float)zlocations - kz[kcount];
                
                dk_sq = dkx*dkx + dky*dky + dkz*dkz;
            
                
                if (dk_sq <= kernr_sq)  {
                    
                    
                    dk = sqrt(dk_sq);
                    fracdk = (float)dk/kernr;
                    pos = (float)fracdk*ntab;
                    ind1 = (int)floor(pos);
                    ind2 = (int)ceil(pos);
                    fracpos = pos - ind1;
                    kernvalue = ktab[ind1] - fracpos*(ktab[ind1] - ktab[ind2]);
                    
                    
                    //outr[i][j][k] = outr[i][j][k] + kernvalue * wcol[kcount];
                    outr[i][j][k] = outr[i][j][k] + kernvalue * wcol[kcount];
                    
                    
                    
                }  /* dk <= kernr */
                
                
                }  /* k loop */
                
            }  /* j loop */
            
        }  /* i loop */
        
        
        
    }  /* kcount */
    printf("here\n");
    for (int n = 0; n < nsamples; n++) {
        
        kxtemp = kx[n]*Ggrid + gridcenter;
        kytemp = ky[n]*Ggrid + gridcenter;
        kztemp = kz[n]*zlocations + zgridcenter;
        
        xlow = (int)floor(kxtemp);
        ylow = (int)floor(kytemp);
        zlow = (int)floor(kztemp);
        
        
        xd = kxtemp - xlow;
        yd = kytemp - ylow;
        zd = kztemp - zlow;
        
        // tri-linear interpolation
        //i1 = outr[xlow][ylow][zlow]*(1-zd) + outr[xlow][ylow][zlow+1]*zd;
        //i2 = outr[xlow][ylow+1][zlow]*(1-zd) + outr[xlow][ylow+1][zlow+1]*zd;
        //j1 = outr[xlow+1][ylow][zlow]*(1-zd) + outr[xlow+1][ylow][zlow+1]*zd;
        //j2 = outr[xlow+1][ylow+1][zlow]*(1-zd) + outr[xlow+1][ylow+1][zlow+1]*zd;
        //	w1 = i1*(1-yd) + i2*yd;
        //	w2 = j1*(1-yd) + j2*yd;
        //	wcol2[n] = w1*(1-xd) + w2*xd;
        
        // bi-linear interpolation
        i1 = yd*outr[xlow][ylow][zlow+1] + (1-yd)*outr[xlow][ylow][zlow];
        i2 = yd*outr[xlow][ylow+1][zlow+1] + (1-yd)*outr[xlow+1][ylow][zlow+1];
        wcol2[n] = i2*xd + i1*(1-xd);
        
    
        
    }  // n loop
    for (int n=0; n<nsamples;n++){
        datr_out[n] = wcol2[n];
    }
    delete datwtr;
    delete wcol2;
    delete outr;
    
    return;
}
