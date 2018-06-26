/*****************************************************
Written Feb 16.
The equation y'=-y^2, with y=1 at x=0 is solved by an 
implicit Euler first order scheme. Note the instability
as h approaches 1. Compare this with the implicit 
Euler first order solution in implicit.h

********************************************************/

#include<iostream>
#include<fstream>//<-- needed for C++ style output file
#include<iomanip>//<--necessary for "setw" spacer in output
using namespace std;

  double x=0,y=1, disc;  
int main()
{ofstream  output;          // C++ style output
  output.open ("out.dat");

  double h=.01;while(x<1){
y=y+h*(-y*y);
      x=x+h;
      output<<setw(5)<<setprecision(7)<<x<<"  "<<setw(10)<<setprecision(7)<<y<<"  "<<1./(1.+x)<<endl;
}
  output.close();
  return(0);
}
