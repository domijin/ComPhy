#include<stdio.h>
#include<math.h>
double f(double x)
{
  return (pow(x,-1./3)+x/10.);
}
double x(double y)
{
  return pow(y,3./2);
}
double p(double x)
{
  return 2./3*pow(x,-1./3);
}
void g()
{
  printf("Exact = 1.55\n");
}
