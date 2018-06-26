/********************************************
*  This program, written on Jan 2, 2014,     *
*  solves the equation fun(x)=0 for an       *
*  externally defined function fun, using    *
*  the secant method. The user supplies the  *
*  the intial guesses for xlow and xhigh,    *
*  the x values that bracket the root.       *
*********************************************/


#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//Declare the function "fun" which is elsewhere
extern double fun(double );

double xlow, xhigh, xnew;
double  fhigh, flow, fnew;
double  eps=1.0e-12;

int main(int argc, char *argv[]){ //<------   main can take arguments!!
  cout<<"  ********************************************\n";
  cout<<"  * The default eps is 1.0e-12. To specify   *\n";
  cout<<"  * another accuracy, rerun the program with * \n";
  cout<<"  * the option -t.                           *  \n";                       
  cout<<"  ********************************************\n";
//Read in accuracy
  if(argc>1&&strcmp(argv[1],"-t")==0) //<--argc is the number of arguments 
    {                                      //on the "run" line
      cout<<"On the next line, specify the accuracy\n"; //Only if the-t option used
  cin>>eps;
 }
//Read in initial x values
  cout<<"On the next line, give two values of x between which there may be a root"<<endl;
  cin>>xlow; cin>>xhigh;
//If the function doesn't change signs between the root
//then try again
  while(fun(xlow)*fun(xhigh)>0)
{  
cout<<"There may not be a zero in this range\n";
cout<<"Choose a new set of x values\n";
  cin>>xlow; cin>>xhigh;
}

//We've now established that the root is bracketed by
//xlow and xhigh
  flow=fun(xlow);fhigh=fun(xhigh);
  xnew=(xlow*fhigh-xhigh*flow)/(fhigh-flow);
  fnew=fun(xnew);

  cout<<xnew<<endl;
//The while loop is the iteration for the secant solution 

while(fabs(fun(xnew))>eps)
{
  xlow=xhigh; xhigh=xnew;
  flow=fhigh; fhigh=fnew;
  xnew=(xlow*fhigh-xhigh*flow)/(fhigh-flow);
  fnew=fun(xnew);
  //  cout<<xnew<<endl;
    }

//The final printout line is below

printf("the result is %3.14lf\n",xnew);
return(0);}
