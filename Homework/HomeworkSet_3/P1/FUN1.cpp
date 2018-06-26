#include<math.h>
double f1(double x,double y)//function f1(x,y)=sin(x+y)-exp(y/x)+5
{
  return(sin(x+y)-exp(y/x)+5);
}
double df1x(double x,double y)//derivation against x, f1'x(x,y)=cos(x+y)+y*exp(y/x)
{
  return(cos(x+y)+y*exp(y/x)/pow(x,2));
}
double df1y(double x,double y)//derivation against y, f1'y(x,y)=cos(x+y)-exp(y/x)/x
{
  return(cos(x+y)-exp(y/x)/x);
}
