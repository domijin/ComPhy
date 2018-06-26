/*********************************
f(x)=exp(-x)*sin(pi*x)
I = −0.6793261834020956
 *********************************/
#include<stdio.h>
#include<math.h>
#define exact -0.6793261834020956
extern double f(double);
// Abramowitz & Stegun 1972 Page 916
double xi[]=
  {
    -0.906179845938664,
    -0.538469310105683,
    0.,
    0.538469310105683,
    0.906179845938664
  };

double wi[]=
  {
    0.236926885056189,
    0.478628670499366,
    0.568888888888889,
    0.478628670499366,
    0.236926885056189
  };


int main()
{
  double y=0;
  for(int i=0;i<5;i++)
    {
      y+=wi[i]*f(xi[i]);
    }
  printf("estimate for the integral is \t     %1.14lf\nerror with fairly precision value is  %1.14lf\n",y,y-exact);
  return(0);
}
