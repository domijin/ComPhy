#include<math.h>
double f(double x)//function f(x)=x^3-10x+10
{
  return(pow(x,3)-10*x+10);
}
double df(double x)//deviation of f(x), f'(x)=3x^2-10
{
  return(3*pow(x,2)-10);
}
