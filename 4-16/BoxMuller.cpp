/********************************************************
       April 13, 2014
       For PHYSCS 6352            
             
This program uses the RAND function to generate two variables
x,y uniformly distributed over 0,1. It then uses the Box Muller 
transormation to create a variable z that is normally distributed
(i.e., distributed in a Gaussian). 

The user inputs N the number of samples taken. For N larger than 
around 500 the agreement is pretty good. For N=1000000 the agreement
is excellent.


 ******************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>           // needed for rand
#include<time.h>             //this is needed for true randomness
#include<math.h>
using namespace std;
const double PI=4.*atan(1.);

int k,N;
double x,y,z;
double bin[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main()
{

/*** Choose the number of samples that will be used**/
cout<<"Choose N\n";
cin>>N;

 srand (time(NULL));            //so that "rand" gives a true random variable


/********************************************************
Do the Box Muller transform from the x,y to z. We could also
compute an independent normally distributed variable by replacing
the cosine with the sine.
*************************************************************/
 double sum0=0,sum1=0,sum2=0,sum3=0,sum4=0;
 for(k=0;k<N;k++)
   {
     x=(1.0*rand())/RAND_MAX;
     y=(1.0*rand())/RAND_MAX;
     z=sqrt(-2.*log(x))*cos(2.*PI*y);
     sum0+=1;sum1+=z;sum2+=z*z;sum3+=z*z*z;sum4+=z*z*z*z;
   } 

/**************************************
Now put the results in bins with spacing
of delta Z=0.5
 ************************************/
/*
if(z<-3.5) ++bin[0];
if(z<-3&&z>-3.5) ++bin[1];
if(z<-2.5&&z>-3) ++bin[2];
if(z<-2&&z>-2.5) ++bin[3];
if(z<-1.5&&z>-2) ++bin[4];
if(z<-1&&z>-1.5) ++bin[5];
if(z<-0.5&&z>-1) ++bin[6];
if(z<0&&z>-.5) ++bin[7];
if(z<0.5&&z>0) ++bin[8];
if(z<1&&z>0.5) ++bin[9];
if(z>1&&z<1.5) ++bin[10];
if(z>1.5&&z<2) ++bin[11];
if(z>2&&z<2.5) ++bin[12];
if(z>2.5&&z<3) ++bin[13];
if(z>3&&z<3.5) ++bin[14];
if(z>3.5) ++bin[15];
    }

//Normalize the bins
for(int kk=0;kk<15;kk++)bin[kk]=(2.0*bin[kk])/(1.0*N);

//Write out the results and compare to a normal distrib
FILE *datawrite;
datawrite=fopen("distrib.dat","w");
for(int j=0;j<15;++j){
double zz=(j-8)*0.5+0.25;
fprintf(datawrite, "%7.6f    %10.6f    %10.6f\n", zz,  bin[j], exp(-zz*zz/2)/sqrt(2.*PI));
}
fclose(datawrite);
*/


  return(0);
}
