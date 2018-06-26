/*************************
Substitution: x^3-10x+10
        By Dongming Jin
**************************/
#include<iostream>
#include<math.h>
using namespace std;
double f(double x)//function f(x)=x^3-10x+10
{
  return(pow(x,3)-10*x+10);
}
double df(double x)//deviation of f(x), f'(x)=3x^2-10
{
  return(3*pow(x,2)-10);
}
int main()
{
  double x,eps=1.0e-5;//Accuracy 1.0e-5
  cout<<"Enter initial guess"<<endl;
  cin>>x;
  int k=1;//counter for substitution
  while(fabs(f(x))>=eps)
    {
      cout<<x<<'\t'<<k<<endl;
      k++;
      if(k>100)
	break;
      x=x-f(x)/df(x);//Newtownion method
    }
  return(0);
}
