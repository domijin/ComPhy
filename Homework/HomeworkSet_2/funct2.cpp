#include<math.h>
double f(double x)//function f(x)=x^2-10+10/x
{
  return(pow(x,2)-10+10/x);
}
double df(double x)//deviation of f(x), f'(x)=2x-10/pow(x,2)
{
  return(2*x-10.0/pow(x,2));
}
