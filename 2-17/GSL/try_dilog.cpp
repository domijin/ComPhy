

#include<iostream>
#include<gsl/gsl_sf_dilog.h>

using namespace std;

int main ()
{
  double x=5.0;
  double y=gsl_sf_dilog(x);
  cout<<y<<endl;

  return 0;
}
