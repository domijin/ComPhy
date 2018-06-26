#include<stdio.h>
#include<math.h>
#define pi 4*atan(1)
double f(double x)
{
  return (exp(-x*x/2)*x);
}
double ierf(double x)
{
  return (sqrt(pi)/2.*(x+pi/12.*pow(x,3)+7.*pi*pi/480.*pow(x,5)));
}
double x(double y)
{
  return 2./3*acos(1.-2.5*y);
}
double p(double x)
{
  return 0.6*sin(1.5*x);
}
void g()
{
  printf("Exact = 0.393469\n");
}
