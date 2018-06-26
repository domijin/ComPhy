/***********************************
            FEB 25 2014
This is a bare-bones Simpson integration 
routine for interval x0=0 to xf=1. (Modify 
as needed.)  Note that the user specifies
half the number of intervals, to ensure that 
the number of intervals used is even.
************************************/
#include<iostream>
using namespace std;

extern double f(double);

int main()
{double h, x0=0,xf=1,sum=0;
  int N;
  cout<<"Specify half the number of divisions?\n";
  cin>>N;
  h=(xf-x0)/2./N;

  sum=f(x0);
for(int n=0;n<2*N;n+=2){
sum+=4.*f(x0+h+n*h)+2.*f(x0+n*h);
     }
    sum+=f(xf);
  cout<<"Answer is "<<sum*h/3.<<endl;
  return(0);
}
