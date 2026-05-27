#ifndef GLSATSORT //do not run this entire section for the actual pseq
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


void exit(int status);
STATUS dotest();

  //GE Surrogate section

float gmax=2.935933;
float slewmax=10.30;

int opxres = 4096;
int opyres = 20;
float opfov = 200;
int rhimsize = 128;


    float ave_sar, peak_sar;	  /* sar values based on reg tr */
    float cave_sar;
    float cave_satsar;
    int slice;                      /* IR PREP (pjg) */
    int sl_index, half_slice_sign;
    int i,j;

    float origin_y, origin_z, delta_ky, delta_kz, dist_ky, dist_kz, sq_dist_ky;
    int superindex;


typedef struct zy_dist {
       float distance;
       unsigned int view;
       unsigned int slice;
       unsigned int xz_done;
} ZY_DIST;



ZY_DIST *zy_sort;   /*  Use dynamic memory allocation for zy_sort.*/
ZY_DIST *temp_sort; /*GL040622 temporary storage for resorted partitions*/
ZY_DIST *temp_sort2;
 FILE *presort_file, *postsort_file, *export_file;

int count; /*GL040622 Crude way to do this*/
int frames_left;
int frames_list[1024];
int gldebug=0;
int ellipt_flag=1;
int reverse_ellipt_flag;
int ellipt_debug_files=1;
int ellipt_debug;
int glpartition=128;
int glinout = 1;
int glPePerPartition,glsegment,gcount;
float ethick=160;
int rhhnover=0;
int rhnframes = 32;
int equant=1;
float act_tr = 24500;
int T1Blood = 1200000;

typedef struct magnetization {
  float m;
  int pulse;
} magnetization;

magnetization * mag_t;
magnetization * mag_t2;
float mag_e;

int magcompare( const void *m1,const void *m2 )
{
  //  printf("(magnetization *)m2)->m = %f,((magnetization *)m2)->m = %f, return %f\n) ",((magnetization *)m2)->m,(((magnetization *)m2)->m < ((magnetization *)m2)->m )? 1: -1 );
    return (((magnetization *)m2)->m < ((magnetization *)m1)->m )? 1: -1;
}   /* end magcompare() */

#define ELLIPT_CEN_MAX  65536  /*512x128: Maximum size for zy structures for
                                 elliptical centric k-space order*/
int distcompare( const void *dist1,
             const void *dist2 )
{
    return (((ZY_DIST *)dist2)->distance < ((ZY_DIST *)dist1)->distance )? 1: -1;
}   /* end distcompare() */
typedef struct zy_exp {
     unsigned int view;
     unsigned int slice;
     unsigned int xz_done;
} ZY_EXPORT;



ZY_EXPORT zy_export[ELLIPT_CEN_MAX];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(int argc, char ** argv) {
  if(argc>=2)
    {
      glpartition = atoi(argv[1]);
      printf("%d = partition\n",glpartition);
    }
  if(argc>=3)
    {
     rhnframes = atoi(argv[2]);
      printf("N Frames = %d\n",rhnframes);
    }
  if(argc>=4)
    {
      equant = atoi(argv[3]);
      printf("equant =%d\n", equant);
    }
  if(argc>=5)
    {
      gldebug=1;
      printf("Debug On");
    }



    dotest();

}


STATUS dotest()
{
  /* MRIge57602 - added reverse elliptical centric encoding */
  if ( (ellipt_flag == 1) || (reverse_ellipt_flag == 1) )
    {

      if ((zy_sort = (ZY_DIST *) malloc(sizeof(ZY_DIST) * (rhnframes +
							   rhhnover) * equant)) == NULL) {
	printf("Failure allocating zy_sort.\n");
	return FAILURE;
      }


      origin_z = (float)(equant-1)/2.0 - 0.01;
      origin_y = (float)(rhnframes-1)*(1.0/(2.0*1)) - 0.01;
      delta_ky = 1.0/(opfov*1*1); /* inverse mm */
      delta_kz = 1.0/ethick;  /* inverse mm also */
      superindex = 0;
      for (i=0; i<rhnframes+rhhnover; i++)
        {
	  dist_ky = delta_ky*(i-origin_y);
	  sq_dist_ky = dist_ky*dist_ky;
	  for (j=0; j<equant; j++)
            {
	      zy_sort[superindex].view=i;
	      zy_sort[superindex].slice=j;  /*slices start at 0*/
	      if (reverse_ellipt_flag == PSD_ON )
                {

		  zy_sort[superindex].xz_done =
		    (j==equant/2-1) ? 1:0;

                }
	      else /* forward elliptical */
                {
		  zy_sort[superindex].xz_done =
		    (j==equant-1) ? 1:0;
                }
	      dist_kz = delta_kz*(j-origin_z);
	      zy_sort[superindex].distance = sqrt(sq_dist_ky + dist_kz*dist_kz);

	      superindex +=1;
            }
        }
      qsort(zy_sort,(rhnframes+rhhnover)*equant,sizeof(ZY_DIST),distcompare);

#endif /*ifndef GLSATSORT*/
      /*Include this portion in the processing! GL040721*/
      /********************************************************************************************************************************************/
      /*GL040622*/
      /*Resort the ordering to ensure that the middle sections of k-space are adequately saturated*/
      if (glpartition > 0)
	{

	  /*GL040622 Allocate temp_sort*/
	  if(gldebug)
	    {
	      printf("Allocating Tempsort\n");
	      fflush(stdout);
	    }

	  if ((temp_sort = (ZY_DIST *) malloc(sizeof(ZY_DIST) * (rhnframes +
								 rhhnover) * equant)) == NULL) {
	    printf("Failure allocating temp_sort.\n");
	    return FAILURE;
	  }

	  if ((temp_sort2 = (ZY_DIST *) malloc(sizeof(ZY_DIST) * (rhnframes +
								  rhhnover) * equant)) == NULL) {
	    printf("Failure allocating temp_sort.\n");
	    return FAILURE;
	  }
	  /*Added 040728 to ensure that we have a sensible number of PePerPartitions*/
	  while(((rhnframes+rhhnover)*equant)%glpartition!=0)
	    {
	      glpartition--;
	    }

	  glPePerPartition = (superindex+1) / glpartition; /*number of phase encodes in each partition*/


	  printf("glpartition = %d, Pe Per Partition=%d\n", glpartition, glPePerPartition);
	  fflush(stdout);
	  gcount =0; /*initialize the damn pointer GL040623*/

	  if(glinout ==1)
	    {
	      if(gldebug)
		printf("In Out Part 2\n");
	      /*build up the magnetization vector*/
	      if ((mag_t = (magnetization *) malloc(sizeof(magnetization) * (glpartition*glPePerPartition))) == NULL)
		{
		  printf("Failure allocating magnetization\n");
		  return FAILURE;
		}
	      if ((mag_t2 = (magnetization *) malloc(sizeof(magnetization) * (glpartition*glPePerPartition))) == NULL)
		{
		  printf("Failure allocating magnetization\n");
		  return FAILURE;
		}

	      //equililbrium magnetization
	      mag_e = (float)(1-exp(-((float)glpartition*(float)act_tr)/(float)T1Blood) )/ (1+exp(-((float)glpartition*(float)act_tr)/(float)T1Blood));
	      if(gldebug)
		{
		  j=10;
		  printf("act_tr =%f, t1Blood = %d mag_e = %f\n", act_tr,T1Blood,(float)mag_e);
		  fflush(stdout);
		}
	      /*Calculate the magnetization as a function of time for each partition*/
	      for(i=0;i<glPePerPartition;i++)
		{
		  for(j=0;j<glpartition;j++)
		    {
		      glsegment = j+i*glpartition;
		      mag_t[glsegment].m = (float)fabs((float)-mag_e * (exp(-(float)j*(float)act_tr/(float)T1Blood)) + (1-exp(-(float)j*(float)act_tr/(float)T1Blood)));
		      mag_t[glsegment].pulse = j+i*glpartition;
		      if(gldebug)
			printf("magvector: m(%d) = %f\n", mag_t[j+i*glpartition].pulse, mag_t[j+i*glpartition].m);
		    }
		}
	      /*now the magnetization vector has a m and a pulse number
		sort this vector by size of magnetization*/
	      qsort(mag_t,glpartition*glPePerPartition, sizeof(magnetization),magcompare);

	      if(gldebug)
		{
		  for(i = 0;i<glpartition*glPePerPartition;i++)
		    {
		      printf("magsort: i = %d, resort m=%f , pn=%d\n", i,mag_t[i].m, mag_t[i].pulse);
		    }
		}

	      /*zy_sort is in increasing order of distance, assign each one of these to a pulse number*/
	      for(j=0;j<glPePerPartition*glpartition;j++)
		{
		  /*the order in which the data should be acquired*/
		  glsegment = mag_t[j].pulse;
		  temp_sort[glsegment].view = zy_sort[j].view;
		  temp_sort[glsegment].slice = zy_sort[j].slice;
		  temp_sort[glsegment].distance = zy_sort[j].distance;
		  temp_sort[glsegment].xz_done = 0; //Should be initialized to something!
		  mag_t2[glsegment].pulse = mag_t[j].pulse;
		  mag_t2[glsegment].m = mag_t[j].m;
		  if(gldebug)
  		  printf("assign: view=%d, slice = %d, distance = %f, pulse=%d, m=%f\n",temp_sort[glsegment].view,temp_sort[glsegment].slice, temp_sort[glsegment].distance,glsegment,mag_t2[glsegment].m);
		}


	      // 	    else //glinout !=2
	      // 	      {
	      // 		if(gldebug)
	      // 		  printf("Doing Old Partitions\n");

	      // 		/*loop through each element and pick one from each of the partitions*/
	      // 		for(i = 0; i<glPePerPartition; i++)
	      // 		  {
	      // 		    for(j=0;j<glpartition;j++)
	      // 		      {
	      // 			if(gldebug)
	      // 			  printf("%d of %d, %d of %d\n",j,glpartition-1,i,glPePerPartition-1);
	      // 			glsegment = i+j*glpartition;
	      // 			temp_sort[gcount].view = zy_sort[glsegment].view;
	      // 			temp_sort[gcount].slice = zy_sort[glsegment].slice;
	      // 			temp_sort[gcount].xz_done = 0; /*zy_sort[glsegment].xz_done; Need to rewrite this done algorithm!*/
	      // 			temp_sort[gcount].distance = zy_sort[glsegment].distance;
	      // 			gcount++;
	      // 		      }
	      // 		  } /*end for glPePerPartition*/


	      // 		/*do the in-out K-space acquisition from this*/
	      // 		if(glinout == 1)
	      // 		  {
	      // 		    if(gldebug)
	      // 		      printf("In Out part 1\n");
	      // 		    /*do this once for every PePerPartition*/
	      // 		    for(j=0;j<glPePerPartition;j++)
	      // 		      {

	      // 			//for(i=0;i<glPePerPartition/2;i++) //GL040719
	      // 			for(i=0;i<glpartition/2;i++)
	      // 			  {
	      // 			    /*should try to sort from 0 1 2 3 4 5 6 7
	      // 			      to                      7 5 3 1 0 2 4 6*/
	      // 			    /*AND then 8  9  10 11 12 13 14 15 */
	      // 			    /*         15 13 11 9  8 10 12 14*/
	      // 			    glsegment = j*glpartition;
	      // 			    temp_sort2[i+glsegment].view =temp_sort[glsegment+glpartition-1-2*i].view;
	      // 			    temp_sort2[i+glsegment].slice =temp_sort[glsegment+glpartition-1-2*i].slice;
	      // 			    temp_sort2[i+glsegment].distance =temp_sort[glsegment+glpartition-1-2*i].distance;
	      // 			    temp_sort2[i+glsegment+glpartition/2].view = temp_sort[glsegment+2*i].view;
	      // 			    temp_sort2[i+glsegment+glpartition/2].slice = temp_sort[glsegment+2*i].slice;
	      // 			    temp_sort2[i+glsegment+glpartition/2].distance = temp_sort[glsegment+2*i].distance;
	      // 			    //printf("%d into %d and %d into %d\n",glsegment+glPePerPartition-1-2*i,i+glsegment,glsegment+2*i,i+glsegment+glPePerPartition/2);
	      // 			    //fflush(stdout);
	      // 			  } //end glpartition
	      // 		      } //end glpeperpartition

	      // 		    /*Dump temp_sort2 back into temp_sort1 so don't have to rewrite the done algorithm*/
	      // 		    for(i=0;i<(rhnframes+rhhnover)*equant-1;i++)
	      // 		      {
	      // 			if(gldebug)
	      // 			  printf("%d of %d\n", i, rhnframes*equant - 1);
	      // 			temp_sort[i].view = temp_sort2[i].view;
	      // 			temp_sort[i].slice = temp_sort2[i].slice;
	      // 			temp_sort[i].distance = temp_sort2[i].distance;
	      // 		      }
	      // 		  } //end of glinout == 1
	      /*END !glinout == 2*/


	      /*write this routine to figure out the xz_done stage*/
	      /*initialize all the variables*/
	      frames_left =(int) rhnframes;

	      /*initialize the frames_list variables*/
	      for(i=0;i<frames_left;i++)
		{
		  frames_list[i] = 0;
		}

	      /*loop backwards through the list to find the last occurence of every frame and mark it as done*/
	      // while (frames_left >=1) to forever get rid of this done problem! GL040721
	      for(gcount=glpartition*glPePerPartition-1;gcount>=0;gcount--)
		{
		  if(frames_list[temp_sort[gcount].view]==0)
		    {
		      if(gldebug)
			printf("done: view %d done at SI %d\n", temp_sort[gcount].view, gcount);
		      frames_list[temp_sort[gcount].view]=1;
		      temp_sort[gcount].xz_done=1;
		      frames_left--;
		    }
		  else
		    {
		      temp_sort[gcount].xz_done=0;
		    }
		} /*end while frames_left >1*/


	      /* rewrite this temporary storage into the zy_sort matrix*/
	      /*GL040729 rewrite the last element as well!*/
	      for (i=0;i<glpartition*glPePerPartition;i++)
		{
		  zy_sort[i].view = temp_sort[i].view;
		  zy_sort[i].slice = temp_sort[i].slice;
		  zy_sort[i].xz_done = temp_sort[i].xz_done;
		  zy_sort[i].distance = temp_sort[i].distance;
		  if(gldebug)
		  printf("rewrite: view=%d, slice=%d, done=%d, distance=%f, pulse=%d, m=%f\n",zy_sort[i].view, zy_sort[i].slice, zy_sort[i].xz_done,zy_sort[i].distance,mag_t2[i].pulse,mag_t2[i].m);
		} /*end for i=0->superindex*/

	      if(gldebug)
		{
		  printf("Out of resort\n");
		  fflush(stdout);
		  /*Dump this to file*/

		} /*end gldebug*/
	      postsort_file = fopen("postsort.csv","w");
		  for (i = 0; i <superindex ; i++)
		    {
		      if(gldebug)
		      printf("dump: v=%d,s=%d,d=%d,dist=%4f,mag=%f,pn=%d\n",
			      zy_sort[i].view, zy_sort[i].slice,zy_sort[i].xz_done,zy_sort[i].distance,mag_t2[i].m,mag_t2[i].pulse);
		      fprintf(postsort_file,"%d,%d,%d,%d,%4f,%f,%d\n",
			      zy_sort[i].view, zy_sort[i].slice,zy_sort[i].xz_done,i,zy_sort[i].distance,mag_t2[i].m,mag_t2[i].pulse);
		    }
		  fclose(postsort_file);
	    } //end glinout == 2


	} /*END if glpartition >0*/
      /*GLEND*/
	/****************************************************************************************************************************************/

#ifndef GLSATSORT
    }
    return SUCCESS;
}
#endif
