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
    int Ggrid = (int)conf[0];                 	// 0
    int nsamples = (int)conf[1];              	// 1    
    int ntab = (int)conf[2];		       		// 2
    float w = conf[3];                        	// 3
    	
	cout << "regcpp..." << endl; 
    cout << "   nsamples = " << nsamples << endl; 
	cout << "   ntab = " << ntab << endl; 
	cout << "   Ggrid = " << Ggrid << endl; 


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

	
    /*--------------------- file IO ----------------------  */
	float* kx = new float[nsamples];   // note: locations are scaled -0.5 to 0.5
	float* ky = new float[nsamples];  
	float* wcol = new float[nsamples];
	float* datr = new float[nsamples];
	float* dati = new float[nsamples];
	float* datwtr = new float[nsamples];  // product of dat and weights
    float* datwti = new float[nsamples];
	float* ktab = new float[ntab];

	
    /* filenames */
    char* fn_kx = new char[40];
    char* fn_ky = new char[40];
    char* fn_wcol = new char[40];
    char* fn_datr = new char[40];
    char* fn_dati = new char[40];
    char* fn_ktab = new char[40];
    char* fn_outr = new char[40];
    char* fn_outi = new char[40];
    
    sprintf(fn_kx,"INPUT_kx");
    sprintf(fn_ky,"INPUT_ky");
    sprintf(fn_wcol,"INPUT_wcol");
    sprintf(fn_datr,"INPUT_datr");
    sprintf(fn_dati,"INPUT_dati");
    sprintf(fn_ktab,"INPUT_ktab");
    sprintf(fn_outr,"OUTPUT_outr");
    sprintf(fn_outi,"OUTPUT_outi");
 
    	ifstream *fin_kx;
	ifstream *fin_ky;
	ifstream *fin_wcol;
	ifstream *fin_datr;
	ifstream *fin_dati;
	ifstream *fin_ktab;
	ofstream *fin_outr;
	ofstream *fin_outi;
	
	fin_kx = new ifstream (fn_kx, ios::binary);
	fin_ky = new ifstream (fn_ky, ios::binary);
	fin_wcol = new ifstream (fn_wcol, ios::binary);
	fin_datr = new ifstream (fn_datr, ios::binary);
	fin_dati = new ifstream (fn_dati, ios::binary);
	fin_ktab = new ifstream (fn_ktab, ios::binary);
    	fin_outr = new ofstream (fn_outr, ios::binary);
	fin_outi = new ofstream (fn_outi, ios::binary);

    /* open files */
	if (!fin_kx->is_open()) {
		cout << "Error opening kx file" << endl;
		exit (-1);
	}
	if (!fin_ky->is_open()) {
		cout << "Error opening ky file" << endl;
		exit (-1);
	}
	if (!fin_wcol->is_open()) {
		cout << "Error opening weights file" << endl;
		exit (-1);
	}
	if (!fin_datr->is_open()) {
		cout << "Error opening datr file" << endl;
		exit (-1);
	}
	if (!fin_dati->is_open()) {
		cout << "Error opening dati file" << endl;
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
	if (!fin_outi->is_open()) {
		cout << "Error opening outi file" << endl;
		exit (-1);
	}
	
	/* read from file */
	float temp1;
	float temp2;
	float temp4;
	float temp5;
	float temp6;
	for (int i=0; i < nsamples; i++) {
		fin_kx->read((char*)&temp1,sizeof(float));
		fin_ky->read((char*)&temp2,sizeof(float));
		fin_wcol->read((char*)&temp4,sizeof(float));
		fin_datr->read((char*)&temp5,sizeof(float));
		fin_dati->read((char*)&temp6,sizeof(float));
		kx[i] = temp1;
		ky[i] = temp2;
		wcol[i] = temp4;
		datr[i] = temp5;
		dati[i] = temp6;
	}
    for (int i=0; i < ntab; i++) {
	    fin_ktab->read((char*)&temp1,sizeof(float));
		ktab[i] = temp1;
    }
 

/*---------------- initalize stuff -----------------------*/
float **outr; 
float **outi;
outr = new float*[Ggrid];	
outi = new float*[Ggrid];		
for(int i=0; i<Ggrid; i++)	{
	outr[i] = new float[Ggrid];
	outi[i] = new float[Ggrid];
}
for (int i=0; i < Ggrid; i++) {
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

for (int i = ixmin; i <= ixmax; i++) {

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



/*------------------ write output to file --------------------*/  
	
    for (int i = 0; i < Ggrid; i++) {
          for (int j = 0; j < Ggrid; j++) {
			temp1 = outr[i][j];
       		temp2 = outi[i][j]; 	
			fin_outr->write((char*)&temp1,sizeof(float));
			fin_outi->write((char*)&temp2,sizeof(float));
	   } 
    }
    
    fin_kx->close();
    fin_ky->close();
    fin_wcol->close();
    fin_datr->close();
    fin_dati->close();
    fin_ktab->close();
    fin_conf->close();
    fin_outr->close();
    fin_outi->close();

    
	delete[] kx;
	delete[] ky;
	delete[] datr;
	delete[] dati;
       delete[] datwtr;
	delete[] datwti;
	delete[] wcol;
	delete[] ktab;
       delete[] conf;
	delete[] outr;
	delete[] outi;
	
	//cout << "saved real file to " << fn_outr << endl;
	//cout << "saved img file to " << fn_outi << endl;
    //   cout << "done" << endl;
    
	return 0;

} /* main function */
