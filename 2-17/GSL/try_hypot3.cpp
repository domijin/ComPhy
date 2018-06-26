/*
compile with -l gsl
 */

#include<iostream>
#include<gsl/gsl_math.h>

using namespace std;

int main ()
{
  double x=5.0;
  double y=gsl_hypot3(x,2.*x, 5*x);
  cout<<y<<endl;

  return 0;
}
