/***********************************
            FEB 25 2014
This is a bare-bones trapezoidal integration 
routine for interval x0=0 to xf=1. (Modify 
as needed.)  
************************************/

#include<iostream>
using namespace std;

extern double f(double);

int main()
{double h, x0=0,xf=1,sum=0;
  int N;
  cout<<"How many divisions?\n";
  cin>>N;
  h=(xf-x0)/N;
  sum=0.5*f(x0);
  for(int n=1;n<N;++n)
    {sum+=f(x0+n*h);
     }
    sum+=0.5*f(xf);
  cout<<"Answer is "<<sum*h<<endl;
  return(0);
}
