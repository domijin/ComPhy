/* compile with -l gsl 
the form of the cubic is 
a x^2+b x+ cx=0
The results are stored in 
x0,x1,x2
*/
#include<iostream>
#include<gsl/gsl_poly.h>

using namespace std;

double A=0.,B=-10., C=1;
double X0,X1;
//  double x0,x1,x2;
int k=5;
int main ()
{

  k=gsl_poly_solve_quadratic(A,B,C,&X0,&X1);
  cout<< k  <<endl;
  //  cout<<X0<<"  " <<X1<<"  " <<endl;

  return 0;
}
