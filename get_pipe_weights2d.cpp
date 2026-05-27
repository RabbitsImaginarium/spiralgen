#include <cstdio>
//#include <stdlib>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std; 
#define PI 3.1415926535



int main() 
{
    
    /*----------------------- config file ---------------------------*/ 
	float* conf = new float[8];             // config file, 8 elements
	char* fn_conf = new char[40];
	sprintf(fn_conf,"INPUT_conf");
       ifstream *fin_conf;
   	fin_conf = new ifstream (fn_conf, ios::binary);
   	if (!fin_conf->is_open()) {
		cout << "Error opening config file" << endl;
		exit (-1);
	}
    float temp; 
    for (int i=0; i < 4; i++) {
	    fin_conf->read((char*)&temp,sizeof(float));
		conf[i] = temp;
    }
    int Ggrid = (int)conf[0];                 // 0
    int nsamples = (int)conf[1];              // 1    
    int ntab = (int)conf[2];		          // 2
	float w = conf[3];                        // 3
    	
	cout << "grid to compute weights..." << endl; 
	cout << "   Ggrid = " << Ggrid << endl; 


	/*-------------- input output variables ------------ */			
	int ixmin,ixmax;
	int iymin,iymax;
	//int izmin,izmax;	
	float dkx, dky;	//,dkz;
	float dk, dk_sq; 			
	float fracdk;
	float fracpos;
	float pos; 
	int ind1, ind2;  			
	float kernvalue;	
	int gridcenter = (Ggrid+10)/2; 
	float kernr = (double)w/(double)(2*Ggrid);	
	float kernr_sq; 

	//------ temp variables for weights interpolation
	int xlow;
	int ylow;
	//int zlow;
	float xd;
	float yd;
	//float zd;
	float i1;
	float i2;
	//float j1;
	//float j2; 
	//float w1;
	//float w2;
	float kxtemp;
	float kytemp;
	//float kztemp;

    /*--------------------- file IO ----------------------  */
	float* kx = new float[nsamples];   // note: locations are scaled -0.5 to 0.5
	float* ky = new float[nsamples];  
	//float* kz = new float[nsamples];
	float* wcol = new float[nsamples];
	float* datwtr = new float[nsamples];  // product of dat and weights
	float* ktab = new float[ntab];
	float* wcol2 = new float[nsamples];		// new output weights
	
    /* filenames */
	char* fn_kx = new char[40];
    	char* fn_ky = new char[40];
    	//char* fn_kz = new char[40];
    	char* fn_wcol = new char[40];
    	char* fn_ktab = new char[40];
    	char* fn_outr = new char[40];
    	char* fn_wcol2 = new char[40];    

    	sprintf(fn_kx,"INPUT_kx");
    	sprintf(fn_ky,"INPUT_ky");
    	//sprintf(fn_kz,"INPUT_kz");
    	sprintf(fn_wcol,"INPUT_wcol");
    	sprintf(fn_ktab,"INPUT_ktab");
    	sprintf(fn_outr,"OUTPUT_outr");
    	sprintf(fn_wcol2,"OUTPUT_wcol2");

    	ifstream *fin_kx;
	ifstream *fin_ky;
	//ifstream *fin_kz;
	ifstream *fin_wcol;
	ifstream *fin_ktab;
	ofstream *fin_outr;
	ofstream *fin_wcol2;
	
	fin_kx = new ifstream (fn_kx, ios::binary);
	fin_ky = new ifstream (fn_ky, ios::binary);
	//fin_kz = new ifstream (fn_kz, ios::binary);
	fin_wcol = new ifstream (fn_wcol, ios::binary);
	fin_ktab = new ifstream (fn_ktab, ios::binary);
    	fin_outr = new ofstream (fn_outr, ios::binary);
	fin_wcol2 = new ofstream (fn_wcol2, ios::binary);


    /* open files */
	if (!fin_kx->is_open()) {
		cout << "Error opening kx file" << endl;
		exit (-1);
	}
	if (!fin_ky->is_open()) {
		cout << "Error opening ky file" << endl;
		exit (-1);
	}
	//if (!fin_kz->is_open()) {
	//	cout << "Error opening kz file" << endl;
	//	exit (-1);
	//}
	if (!fin_wcol->is_open()) {
		cout << "Error opening weights file" << endl;
		exit (-1);
	}
	if (!fin_ktab->is_open()) {
		cout << "Error opening kernel table file" << endl;
		exit (-1);
	}
	if (!fin_outr->is_open()) {
		cout << "Error opening outr file" << endl;
		exit (-1);
	}
	if (!fin_wcol2->is_open()) {
		cout << "Error opening outr file" << endl;
		exit (-1);
	}
	
	/* read from file */
	float temp1;
	float temp2;
	float temp3;
	float temp4;

	for (int i=0; i < nsamples; i++) {
		fin_kx->read((char*)&temp1,sizeof(float));
		fin_ky->read((char*)&temp2,sizeof(float));
		//fin_kz->read((char*)&temp3,sizeof(float));
		fin_wcol->read((char*)&temp4,sizeof(float));
		kx[i] = temp1;
		ky[i] = temp2;
		//kz[i] = temp3;
		wcol[i] = temp4;
	}
    for (int i=0; i < ntab; i++) {
	    fin_ktab->read((char*)&temp1,sizeof(float));
		ktab[i] = temp1;
    }
 

/*---------------- initalize stuff -----------------------*/
//float ***outr; 
//outr = new float**[Ggrid+1];			// add one more row to x/y/z for easier interpolation later			

float **outr; 
outr = new float*[Ggrid+20];				
for(int i=0; i<Ggrid+20; i++)	{
	outr[i] = new float[Ggrid+20];
	//for(int j=0; j<Ggrid+1; j++)	{
	//	outr[i][j] = new float[Ggrid+1];
    	//}
}
for (int i=0; i < Ggrid+20; i++) {
    for (int j=0; j < Ggrid+20; j++) {
        //for (int k=0; k < Ggrid+1; k++) {
        //    outr[i][j][k] = 0;
        //}
	 outr[i][j] = 0;
    }
}

kernr_sq = kernr*kernr;

/*------------------- regrid ------------------------ */

for (int kcount = 0; kcount < nsamples; kcount++) {
    

	ixmin = (int) floor(kx[kcount]*Ggrid + gridcenter - w/2) - 1;
	iymin = (int) floor(ky[kcount]*Ggrid + gridcenter - w/2) - 1;
	//izmin = (int) floor(kz[kcount]*Ggrid + gridcenter - w/2) - 1;
	ixmax = (int) ceil(kx[kcount]*Ggrid + gridcenter + w/2) - 1;
	iymax = (int) ceil(ky[kcount]*Ggrid + gridcenter + w/2) - 1;
	//izmax = (int) ceil(kz[kcount]*Ggrid + gridcenter + w/2) - 1;

	

	if (ixmin < 0) ixmin = 0;
	if (iymin < 0) iymin = 0;
	//if (izmin < 0) izmin = 0;
	//if (ixmax > Ggrid-1) ixmax = Ggrid - 1;	
	//if (iymax > Ggrid-1) iymax = Ggrid - 1;
	//if (izmax > Ggrid-1) izmax = Ggrid - 1;	


for (int i = ixmin; i <= ixmax; i++) {



	dkx = (float)(i-gridcenter) / (float)Ggrid - kx[kcount];

       for (int j = iymin; j <= iymax; j++) {

		dky = (float)(j-gridcenter) / (float)Ggrid - ky[kcount];

		//for (int k = izmin; k <= izmax; k++) {
 
            		//dkz = (float)(k-gridcenter) / (float)Ggrid - kz[kcount];
			
			dk_sq = dkx*dkx + dky*dky; // + dkz*dkz;	 	
	

			if (dk_sq <= kernr_sq)  {


				dk = sqrt(dk_sq);
			     	fracdk = (float)dk/kernr; 
			     	pos = (float)fracdk*ntab; 
			     	ind1 = (int)floor(pos); 
			     	ind2 = (int)ceil(pos);
			      	fracpos = pos - ind1;
  				kernvalue = ktab[ind1] - fracpos*(ktab[ind1] - ktab[ind2]); 
			

	                	//outr[i][j][k] = outr[i][j][k] + kernvalue * wcol[kcount];
				outr[i][j] = outr[i][j] + kernvalue * wcol[kcount];

			   

		   }  /* dk <= kernr */
		
		
        	//}  /* k loop */
        	
        }  /* j loop */
  
     }  /* i loop */



  }  /* kcount */



for (int n = 0; n < nsamples; n++) {

	kxtemp = kx[n]*Ggrid + gridcenter;
	kytemp = ky[n]*Ggrid + gridcenter;
	//kztemp = kz[n]*Ggrid + gridcenter;

	xlow = (int)floor(kxtemp); 
	ylow = (int)floor(kytemp); 
	//zlow = (int)floor(kztemp); 
 

	xd = kxtemp - xlow;
	yd = kytemp - ylow;
	//zd = kztemp - zlow;

	// tri-linear interpolation
	//i1 = outr[xlow][ylow][zlow]*(1-zd) + outr[xlow][ylow][zlow+1]*zd; 
	//i2 = outr[xlow][ylow+1][zlow]*(1-zd) + outr[xlow][ylow+1][zlow+1]*zd; 
	//j1 = outr[xlow+1][ylow][zlow]*(1-zd) + outr[xlow+1][ylow][zlow+1]*zd; 
	//j2 = outr[xlow+1][ylow+1][zlow]*(1-zd) + outr[xlow+1][ylow+1][zlow+1]*zd; 
	//	w1 = i1*(1-yd) + i2*yd;
	//	w2 = j1*(1-yd) + j2*yd;
	//	wcol2[n] = w1*(1-xd) + w2*xd;
	
	// bi-linear interpolation
    i1 = yd*outr[xlow][ylow+1] + (1-yd)*outr[xlow][ylow];
	i2 = yd*outr[xlow+1][ylow+1] + (1-yd)*outr[xlow+1][ylow];
	wcol2[n] = i2*xd + i1*(1-xd);


}  // n loop


/*------------------ write output weights to file --------------------*/  
	
    for (int n = 0; n < nsamples; n++) {
	temp1 = wcol2[n];
	fin_wcol2->write((char*)&temp1,sizeof(float));
    }

cout << "wrote output files" << endl;    

    fin_kx->close();
    fin_ky->close();
    //fin_kz->close();
    fin_wcol->close();
    fin_ktab->close();
    fin_conf->close();
    fin_outr->close();
    fin_wcol2->close();
     

    
	delete[] kx;
	delete[] ky;
	//delete[] kz; 
	delete[] wcol;
	delete[] ktab;
       delete[] conf;
	delete[] outr;
	delete[] wcol2;

	
	cout << "saved weights file to " << fn_wcol2 << endl;

    	return 0;

} /* main function */
