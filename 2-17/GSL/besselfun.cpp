
#include<iostream>
#include<fstream>
#include<gsl/gsl_sf_bessel.h>

using namespace std;

double x,y;

int main ()
{
  ofstream output;
  output.open ("out.dat");
for(int n=0;n<100;++n)
  {x=n/10.;
  y=gsl_sf_bessel_J0(x);
output<<x<<"    "<<y<<endl;}
  output.close();
  return 0;
}
