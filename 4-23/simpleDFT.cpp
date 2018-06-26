/************************************
This program was written on April 20, 2014
to demonstrate to 6352 students a simple 
example of a discrete fourier transform.

The trial functions include a sine, a near-sine, 
and a sawtooth wave.

**************************************/

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<complex>// THIS DEFINES THE COMPLEX CLASS
using namespace std;

typedef complex<double> dcmplx;//With this type def, we reduce 
const double PI=4.*atan(1.);

//double f(double z){return(z*(z-0.5)*(z-1.)/0.0481125   );}//kinda like a sine
double f(double z) {return(sin(z*2.*PI));} //truly a sine
//double f(double z){return(z);}//sawtooth
int N;

int main(void){
  cout<<"Read in N\n";
  cin>>N;

/*** ALL VARIABLES BELOW ARE IN SAME NOTATION AS NOTES**/
double T=10;
double t[N];
double x[N];
dcmplx X[N];  


FILE *datatime;
datatime=fopen("timedom.dat","w"); 

FILE *datafreqR;
datafreqR=fopen("fdomR.dat","w"); 

FILE *datafreqI;
datafreqI=fopen("fdomI.dat","w"); 

/**** COMPUTE t_k, x_k  ****/  
for(int j=0;j<N;++j)
  {t[j]=T*(1.0*j)/(1.0*N);
   x[j]=f(t[j]/T);
fprintf(datatime,"%10.5f  %10.5f\n",t[j],x[j]);
}

/****  COMPUTE X_k*****/
for(int n=0;n<N;++n){
X[n]=(0,0);
for(int k=0;k<N;++k){
real(X[n])+=x[k]*cos(2.*PI*n*k/N);
imag(X[n])+=-x[k]*sin(2.*PI*n*k/N);
}

cout<<n<<"   "<<X[n]<<endl;  

fprintf(datafreqR,"%i    %10.7f\n",n,real(X[n])     );
fprintf(datafreqI,"%i    %10.7f\n",n, imag(X[n])     );
}
fclose(datatime);fclose(datafreqR);fclose(datafreqI);

  return(0);}
