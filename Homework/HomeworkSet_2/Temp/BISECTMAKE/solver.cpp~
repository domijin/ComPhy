/*************************
Bisection: x^3-10x+10=0
        By Dongming Jin
**************************/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;
extern double f(double);
int digits(double eps)
{
  int k=0;
  while(eps<1)
    {
      eps=eps*10;
      k++;
    }
  return k;
}
int main(int argc, char *argv[])
{
  double a,b,xlow,xhigh,eps=1.0e-12;//Default accuracy 1.0e-12

  cout<<"  ********************************************\n";
  cout<<"  * The default eps is 1.0e-12. To specify   *\n";
  cout<<"  * another accuracy, rerun the program with *\n";
  cout<<"  * the option -t.                           *\n";
  cout<<"  ********************************************\n";
  //Read in accuracy
  if(argc>1&&strcmp(argv[1],"-t")==0)
    {
      cout<<"On the next line, specify the accuracy\n";
      cin>>eps;
    }
  cout<<"Please input xlow and xhigh"<<endl;
  cin>>a>>b;
  while(f(a)*f(b)>0)//Try until function gets different signs for input numbers
    {
      cout<<"Please try again"<<endl;
      cin>>a>>b;
    }
  // The one has positive value is assigned to xhigh
  if(f(a)>0)
    {
      xhigh=a;
      xlow=b;
    }
  else
    {
      xlow=a;
      xhigh=b;
    }
  double temp=(xlow+xhigh)/2;//Set middle point to temp
  while(fabs(f(xlow)-f(xhigh))>eps)
    {
      if(f(temp)>0)
	 xhigh=temp;
      else xlow=temp;
      temp=(xlow+xhigh)/2;
    }
  cout.precision(digits(eps));//Output corresponding to the accuracy
  cout<<"the result is "<<fixed<<(xlow+xhigh)/2<<endl;
}
