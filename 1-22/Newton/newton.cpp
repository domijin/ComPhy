/********************************************
*  This program, written on Jan 3, 2014,     *
*  solves the equation fun(x)=0 for an       *
*  externally defined function fun, using    *
*  Newton's method. The user supplies the    *
*  the intial guesses for xroot.             *    
*********************************************/


#include<iostream>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

//Declare the functions "fun" and its deriv
extern double fun(double );
extern double funprime(double);

double xold, xnew;
double  eps=1.0e-12;

int main(int argc, char *argv[]){
  cout<<"  ********************************************\n";
  cout<<"  * The default eps is 1.0e-12. To specify   *\n";
  cout<<"  * another accuracy, rerun the program with * \n";
  cout<<"  * the option -t.                           *  \n";                       
  cout<<"  ********************************************\n";
//Read in accuracy
 if(argc>1&&strcmp(argv[1],"-t")==0)
{
  cout<<"On the next line, specify the accuracy\n";
  cin>>eps;
 }
//Read in initial x values
  cout<<"On the next line, give a first guess at the root"<<endl;
  cin>>xold;


//This while loop gives the Newton-Raphson update for the root

while(fabs(fun(xold))>eps)
{
  xnew=xold-fun(xold)/funprime(xold);
  xold=xnew;
  cout<<xnew<<endl;
    }

//The final printout line is below

printf("the result is %3.14lf\n",xnew);
return(0);}
