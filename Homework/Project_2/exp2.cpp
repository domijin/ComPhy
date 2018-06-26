#include<stdio.h>
#include<math.h>
#define pi 4*atan(1)
double f(double x)
{
  return (exp(-x*x/2));
}
double ierf(double x)
{
  return (sqrt(pi)/2.*(x+pi/12.*pow(x,3)+7.*pi*pi/480.*pow(x,5)));
}
double x(double y)
{
  return sqrt(2)*ierf(2*y-1);
}
double p(double x)
{
  return 1/sqrt(2*pi)*exp(-x*x/2);
}
void g()
{
  printf("Exact = %1.14f\n",sqrt(2*pi));
}
