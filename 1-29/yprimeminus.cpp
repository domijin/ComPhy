/******
Solving y'=-0.3y
Demo starting x=1  y=exp(-.3)
Exact solution y=exp(-.3x)
Read in N
Note that answer is accurate to first order,
i.e., error is prop to h^1

*****/

#include<iostream>
#include<math.h>

using namespace std;

double h,y;

int main()
{
/****SET UP*********************/
  double x=1,y=exp(-.3);
  cout<<"How many divisions would you like"<<endl;
  int N;
  cin>>N;  
  cout<<"Up to what value of x do you want to compute?\n";
  cin>>x;
  y=exp(-0.3*x);
  h=1./N;
/*********COMPUTE***************/


  for(int k=0;k<N;++k)
    {x=x+h;
     y=(1.-0.3*h)*y;
    }
  double exact=exp(-0.3*x);
  
  /*************WRITE OUT *********/
cout<<"x= "<<x<<"   y= "<<y<<"  exp(-0.3x)= "<< exact<<" relative error= "<<fabs(y-exact)/exact <<endl;

}
