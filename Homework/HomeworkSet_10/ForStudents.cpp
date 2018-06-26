/*******************************
PROBLEM 1: (30 points) You were given a program “ForStudents.cpp” that reads in 8 complex numbers and stores them as x[0], x[1],...x[7]. It then computes and prints to the screen the values of the DFT coefficients X[0], X[1],...X[7].
Add to that program a section that reconstructs the x[k] from the X[n]. Print out the reconstructed x[k] in the same format as the printout of the X[n]. Lastly, use the “by hand” FFT to find an alternative computation of the
X[n]. Print these out in the same format as that used for the original X[n].
*********************************/
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<complex>
using namespace std;
double const PI=4*atan(1.);

typedef complex<double> dcmplx;

dcmplx x[8],ex;
dcmplx CapX[8],X[8];

int main(void)
{
  /********READ IN DATA*******************/
  FILE *randread;
  //randread=fopen("unrandom.dat","r");   //Choose input data
  randread=fopen("random.dat","r");

  for(int k=0;k<9;++k)
    {
      fscanf(randread,"%lf   %lf\n",&real(x[k]),&imag(x[k]));
    }
  
  cout<<"\n Original x[n]\n";                
  for(int h=0;h<8;++h)
    {
      cout<<h<<"   "<<x[h]<<endl;
    }
  fclose(randread);
	 
/*****************COMPUTE THE DFT COEFFS CapX[n]******/
  for(int n=0;n<8;++n)
    {
      CapX[n]=0.;
      for(int k=0;k<8;++k)
	{
	  real(ex)=cos(-PI*n*k/4.);
	  imag(ex)=sin(-PI*n*k/4.);
	  CapX[n]+=ex*x[k];  
	}           
    } 
           
  cout<<"\n DFT coeffs X[n]\n";                 //Write DFT
  for(int h=0;h<8;++h)
    {
      cout<<h<<"   "<<CapX[h]<<endl;
    }
	
  /*************COMPUTE THE REVERSED x[n]**********/
  cout<<endl<<" Reverse x[n]"<<endl;
  for(int n=0;n<8;++n)
    {
      X[n]=0.;
      for(int k=0;k<8;++k)
	{
	  real(ex)=cos(PI*n*k/4.);
	  imag(ex)=sin(PI*n*k/4.);
	  X[n]+=ex*CapX[k];
	}
    }
  dcmplx eight(8.,0);
  for(int h=0;h<8;++h)
    cout<<h<<"    "<<X[h]/eight<<endl;

  /**********COMPUTE THE FFT X[n]**********/
  cout<<endl<<" FFT coeffs X[n]"<<endl;
  dcmplx EE0,EO0,EE1,EO1,OE0,OO0,OE1,OO1;
  dcmplx minusi(0,-1.),pi34(-sqrt(2)/2.,-sqrt(2)/2.),pi4(sqrt(2)/2.,-sqrt(2)/2.);
  dcmplx E[4],O[4],FFT_X[8];
  // step a
  {
    EE0=x[0]+x[4]; OE0=x[2]+x[6];
    EO0=x[1]+x[5]; OO0=x[3]+x[7];
    EE1=x[0]-x[4]; OE1=(x[2]-x[6])*minusi;
    EO1=(x[1]-x[5])*pi4; OO1=(x[3]-x[7])*pi34;
  }
  // step b
  {
    E[0]=EE0+OE0; E[1]=EE1+OE1;
    O[0]=EO0+OO0; O[1]=EO1+OO1;
    E[2]=EE0-OE0; E[3]=EE1-OE1;
    O[2]=(EO0-OO0)*minusi; O[3]=(EO1-OO1)*minusi;
  }

  for (int i=0;i<4;i++)
    {
      FFT_X[i]=E[i]+O[i];
      FFT_X[i+4]=E[i]-O[i];
    }
  for (int i=0;i<8;i++)
    cout<<i<<"    "<<FFT_X[i]<<endl;

  return(0);
}
