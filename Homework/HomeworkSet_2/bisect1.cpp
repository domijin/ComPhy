/*************************
Bisection: x^3-10x+10=0
        By Dongming Jin
**************************/
#include<stdio.h>
#include<math.h>
double f(double x)//function f(x)=x^3-10x+10
{
  return(pow(x,3)-10*x+10);
}
int main()
{
  double eps=1.0e-12,a=2,b=4,xmed;//Accuracy 1.0e-12
  while(fabs(f(a)-f(b))>eps)//compare the difference with required accuracy
    {
      if(f((a+b)/2)>0)
	b=(a+b)/2;//If middle point is positive, b is updated, otherwise a is updated by middle point.
      else a=(a+b)/2;
    }
  xmed=(a+b)/2;
  printf("the result is %2.14lf\n",xmed);
}
