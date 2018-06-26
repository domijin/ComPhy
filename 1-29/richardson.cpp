/*******************************************
Program written Jan 25, 2014
Solving y'=0.3y Demo starting x=1  y=exp(.3)
Here the first order finite diff solution 
from yprimeplus.cpp and the second-order 
solution from yprimeplus_2order.cpp are 
combined using Richardson extrapolation
to get an answer that is demonstrably good
to fourth order.
********************************************/

#include<iostream>
#include<math.h> // needed for exp

using namespace std;

int main()
{
  double x=1,y=exp(.3);//starting conditions (must be reset for 2nd order comp.

  cout<<"How many divisions would you like"<<endl;
  int N;
  cin>>N;
/**********  FIRST ORDER SECTION***************/
  double h=1./N;
  for(int k=0;k<N;++k)// loop for first order computation
    {x=x+h;
      y=(1.+0.3*h/2.)*y/(1.-0.3*h/2.); //1st order FD rep
    }
  double exact=exp(0.3*x);
  cout<<"x= "<<x<<"   y= "<<y<<"  exp(0.3x)= "<< exact<<" relative error= "<<fabs(y-exact)/exact <<endl;
  double yh=y;// store for later use in Richardson

/**********  SECOND ORDER SECTION***************/
  x=1; y=exp(.3);// reset x and y
  h=1./2/N;      // h-->h/2
  for(int k=0;k<2*N;++k)
    {x=x+h;
      y=(1.+0.3*h/2.)*y/(1.-0.3*h/2.);//2nd order FD rep 
    }

  cout<<"x= "<<x<<"   y= "<<y<<"  exp(0.3x)= "<< exact<<" relative error= "<<fabs(y-exact)/exact <<endl;
 
/**********  RICHARDSON SECTION*****************/

  double kayh2=(4./3.)*(yh-y);
  cout<<kayh2<<endl;

    double yrich=y-kayh2/4;

  cout<<"x= "<<x<<"   y= "<<yrich<<"  exp(0.3x)= "<< exact<<" relative error= "<<fabs(yrich-exact)/exact <<endl;

}
