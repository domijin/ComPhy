/*****************************************************
Written Feb 16.
The equation y'=-y^2, with y=1 at x=0 is solved by an 
implicit Euler first order scheme. Note the stability 
even for large h, like h=1. Compare this with the explicit 
Euler first order solution in explicit.h
********************************************************/

#include<iostream>
#include<fstream>//<-- needed for C++ style output file
#include<iomanip>//<--necessary for "setw" spacer in output
#include<math.h>//<--needed for sqrt
using namespace std;

double x=0,y=1, disc;  
int main()
{ofstream  output;          // C++ style output
  output.open ("out.dat");

  double h=1.;while(x<20){
  disc=pow(1+4.*y*h,.5);
  y=.5*(-1.+disc)/h;//NOTE: NOT y=y+
  x=x+h;

output<<setw(5)<<setprecision(7)<<x<<"  "<<setw(10)<<setprecision(7)<<y<<"  "<<1./(1.+x)<<endl;
}
  output.close();
  return(0);
}
