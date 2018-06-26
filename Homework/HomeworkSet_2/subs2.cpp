/*************************
Substitution: x^2-10+10/x
        By Dongming Jin
**************************/
#include<iostream>
#include<math.h>
using namespace std;
double f(double x)//function f(x)=x^2-10+10/x
{
  return(pow(x,2)-10+10/x);
}
double df(double x)//deviation of f(x), f'(x)=2x-10/pow(x,2)
{
  return(2*x-10.0/pow(x,2));
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
