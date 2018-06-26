/***************************************
This exercise involves using 4th order Runge-Kutta
to solve a de-dimensionalized Schroedinger equation
of the form psi"+K(x-1)^2 psi=-E* psi

This program is the same as schroed.cpp, except
that it assumes even modes, i.e., symmetric about 
x=0.

*****************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<cstdlib>
using namespace std;


double f(double x, double y, double E)
{double K=10;
  double result=-(K*(x-1.)*(x+1.)+E)*y;
  return(result);}
  

int main (int argc, char *argv[]){
  if(argc<=1){cout<< "specify E value!!\n";
    exit(0);}
  double E =atof(argv[1]);

 FILE *datawrite;
   datawrite=fopen("out.dat","w");
   double k1,k2,k3;
   double xin,yin,yprime;
   double x,y;
   int N=100;

  double h=1./N;
 
  x=0.;  y=1.; yprime=0;  //<--  NOTE THESE CONDITIONS
 for(int k=0;k<N;++k)//The RK loop
    {
      k1=h*f(x,y,E);
      k2=h*f(x+h/2,y+h/2*yprime+h/8*k1,E);
      k3=h*f(x+h,y+h*yprime+h/2*k2,E);
 
      y=y+h*(yprime+(k1+2*k2)/6);
      yprime=yprime+(k1+4*k2+k3)/6;
      x=x+h;
      fprintf(datawrite,"%lf   %12.10f\n",x,y);
    }
      fclose(datawrite);
      printf("psi at x=1   %12.10f\n",y);

  return 0;
}
