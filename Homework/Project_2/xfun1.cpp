#include<stdio.h>
#include<math.h>
double f(double x)
{
  return (pow(x,-1./3)+x/10.);
}
double x(double y)
{
  return y;
}
double p(double x)
{
  return 1;
}
void g()
{
  printf("Exact = 1.55\n");
}
