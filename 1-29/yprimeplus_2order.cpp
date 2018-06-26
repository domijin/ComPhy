/******
Solving y'=0.3y
Demo starting x=1  y=exp(.3)
With higher order representation
of the error.
Read in N
Note that answer is accurate to third order
*****/
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
  double x=1,y=exp(.3);

  cout<<"How many divisions would you like"<<endl;
  int N;
  cin>>N;
  double h=1./N;
  for(int k=0;k<N;++k)
    {x=x+h;
      y=(1.+0.3*h/2.)*y/(1.-0.3*h/2.);//higher order FD
    }
  double exact=exp(0.3*x);
  cout<<"x= "<<x<<"   y= "<<y<<"  exp(0.3x)= "<< exact<<" relative error= "<<fabs(y-exact)/exact <<endl;

}
