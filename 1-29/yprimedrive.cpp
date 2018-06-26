/******
Solving y'=0.3y+sin(x)
Demo starting x=0  y=1
Exact solution is
y=[-0.3*sin(x)-cos(x)+2.09*exp(x)]/1.09 
Read in N.
Note that answer is accurate to first order,
i.e., overall error is prop to h^1
*****/

#include<iostream>
#include<math.h>

using namespace std;

int main()
{
/****SET UP*********************/
  double x=0,y=1;   //Starting conditions
  cout<<"How many divisions would you like"<<endl;
  int N;
  cin>>N;
  double h=1./N;
/*********COMPUTE***************/


  for(int k=0;k<N;++k)    //the computation loop
    {x=x+h;
      y=(1.+0.3*h)*y+h*sin(x);
    }
  double exact=(-0.3*sin(x)-cos(x)+2.09*exp(.3*x))/1.09;
  
  /*************WRITE OUT *********/
cout<<"x= "<<x<<"   y= "<<y<<"  exact= "<< exact<<" relative error= "<<fabs(y-exact)/exact <<endl;

}
