/********************************************************
       April 15, 2014
       For PHYSCS 6352            
             
This program uses the RAND function to generate a random x
in (0,1), then asks whether p(x) is greater than a random
y in (0,1). If it is, the x is kept. This gives a distribution
of x's with a distribution proportional to p(x).

The following program bins the values of x. The bins are 
normalized so that the sum of the bins gives a probability 
distribution that integrates to unity.


 ******************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>           // needed for rand
#include<time.h>             //this is needed for true randomness
#include<math.h>
using namespace std;

int k,N;
double x,y;
double bin[11]={0,0,0,0,0,0,0,0,0,0,0};



double p(double x){return (exp(-3*x));}



int main()
{


/*** Choose the number of samples that will be used**/
cout<<"Choose N\n";
cin>>N;

 srand (time(NULL));            //so that "rand" gives a true random variable

/*************************************************************/
 for(k=0;k<N;k++)
   {
     x=(1.0*rand())/RAND_MAX;
     y=(1.0*rand())/RAND_MAX;
  
/**************************************
Now put the results in bins with distribution p(x)
 ************************************/
if(x<0.1&&y<p(x)) ++bin[0];
 if(x>0.1&&x<0.2&&y<p(x)) ++bin[1];
 if(x>0.2&&x<0.3&&y<p(x)) ++bin[2];
 if(x>0.3&&x<0.4&&y<p(x)) ++bin[3];
 if(x>0.4&&x<0.5&&y<p(x)) ++bin[4];
 if(x>0.5&&x<0.6&&y<p(x)) ++bin[5];
 if(x>0.6&&x<0.7&&y<p(x)) ++bin[6];
 if(x>0.7&&x<0.8&&y<p(x)) ++bin[7];
 if(x>0.8&&x<0.9&&y<p(x)) ++bin[8];
 if(x>0.9&&y<p(x)) ++bin[9];
    }

 //  cout<<bin[0]<<" "<<bin[1]<<" "<<bin[2]<<" "<<bin[3]<<" "<<bin[4]<<" "<<bin[5]<<" "<<bin[6]<<" "<<bin[7]<<" "<<bin[8]<<" "<<bin[9]<<endl;



//Normalize the bins, so that the sum of the bins, with each bin weighted 
//by 0.1, is unity.
 double sum=0;
for(int kk=0;kk<10;kk++)sum+=bin[kk];
 for(int kk=0;kk<10;kk++)bin[kk]=10.0*bin[kk]/sum;





//Write out the results and compare to a normal distrib
double norm=(1.-exp(-3.))/3.;// This is needed to normalize the analytic answer
FILE *datawrite;
datawrite=fopen("distrib.dat","w");
for(int j=0;j<10;++j){
  double xx=j*0.1+0.05;
  fprintf(datawrite, "%7.6f    %10.6f    %10.6f\n", xx,  bin[j], 1./norm*exp(-3.*xx));
}
fclose(datawrite);


  return(0);
}
