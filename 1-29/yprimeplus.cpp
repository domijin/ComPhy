/******
Solving y'=0.3y
Demo starting x=1  y=exp(.3)
Exact answer: y=exp(0.3*x)
Read in N
Note that answer is accurate to first order,
i.e., overall error is prop to h^1

*****/
#include<iostream>
#include<math.h>

using namespace std;

int main()
{
/****SET UP*********************/
  double x=1,y=exp(.3);// Starting conditions
  cout<<"How many divisions would you like"<<endl;
  int N;
  cin>>N;
  double h=1./N;// Maximum x will be 1
/*********COMPUTE***************/

  for(int k=0;k<N;++k)
    {x=x+h;
     y=(1.+0.3*h)*y;
    }
  double exact=exp(0.3*x);
  
  /*************WRITE OUT *********/
cout<<"x= "<<x<<"   y= "<<y<<"  exp(0.3x)= "<< exact<<" relative error= "<<fabs(y-exact)/exact <<endl;

}
