/*********************************
f(x)=exp(-x)*sin(pi*x)
I = −0.6793261834020956
*********************************/
#include<stdio.h>
#include<math.h>
#define exact -0.6793261834020956
#define pi 4.*atan(1)
// define function
double f(double x)
{
  return (exp(-x)*sin(pi*x)*sqrt(1-x*x));
}

int main()
{
  int n;
  printf("Please specify the number of Chebyshev nodes to use\n");
  scanf("%d",&n);
  double w=pi/n,y=0;// Initilize weight and integral value
  for (int i=1;i<=n;i++)// For nodes starting from x_1 to x_n
    {
      double x=cos((i-0.5)*pi/n);// calculate x_i based on first kind Chebyshev–Gauss quadrature
      y+=w*f(x);
    }
  printf("estimate for the integral is \t      %2.14f\nerror with fairly precision value is  %2.14f\n",y,y-exact);
}
