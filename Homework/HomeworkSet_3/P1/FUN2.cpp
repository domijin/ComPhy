#include<math.h>
double f2(double x,double y)//function f2(x,y)=x^4+y^4-1
{
  return(pow(x,4)+pow(y,4)-1);
}
double df2x(double x,double y)//derivation against x, f2'x(x,y)=4*x^3
{
  return(4*pow(x,3));
}
double df2y(double x,double y)//derivation against y, f2'y(x,y)=4*x^3
{
  return(4*pow(y,3));
}
