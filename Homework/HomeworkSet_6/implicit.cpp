/*****************************************************
The equation y'=y+y^2, with y=1 at x=0 is solved by an 
implicit Euler first order scheme. Note the stability 
even for large h, like h=1. Compare this with the explicit 
Euler first order solution in explicit.h
A figure of N=1000 is attached as plot.png
********************************************************/
#include<iostream>
#include<fstream>//<-- needed for C++ style output file
#include<math.h>//<--needed for sqrt
#include<stdio.h>
using namespace std;
int main()
{
  ofstream  output;    
  double x=0,y=0.5,disc,yexact;
  output.open("out.dat");
  int N;
  // y(1)~10, to maintein disc>=0, 1-2h+h^2-40h>0 => h<1/42 => N>42, with pertubation, N needs to be larger to be more accurate.
  cout<<"Specify N (N>50 recommended)"<<endl;
  cin>>N;

  double h=1./N;// set steps

  for(x=0;x<=1;x+=h)
    {
      // Exact solution: y=e^x/(3-e^x); singularity at x=ln(3)
      double ex=exp(x);
      yexact=ex/(3-ex);
      output<<x<<'\t'<<y<<'\t'<<yexact<<endl;

      // y'=y+y^2 -> y-y_=h*(y+y^2) -> h*y^2+(h-1)*y+y_=0
      disc=(h-1)*(h-1)-4*h*y;
      y=.5*(1.-h-sqrt(disc))/h;          
    }
  output.close();
  return(0);
}
