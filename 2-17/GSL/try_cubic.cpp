/***********************************************************
This program demonstrates the use of the gsl cubic solver.
It must be compiled with -lgsl
The form of the cubic is x^3+a x^2+ bx+c=0, so the 
coefficients are declared as doubles.

The function gsl_poly_solve_cubic() has variable declarations
(as stated in the gsl manual)
gsl_poly_solve_cubic(double, double, double, *double, *double, *double).
The output of the function, the roots of the polynomial,
are pointers. This means that IN the function the roots are not
part of the "return."


The results are stored in 
x0,x1,x2
*/
#include<iostream>
#include<gsl/gsl_poly.h>

using namespace std;

double A=0.,B=-10.,C=10.;//these are the values for the substitution
                         //and bisection problems
double X0,X1,X2;

int main ()
{
  cout<<gsl_poly_solve_cubic(A,B,C,&X0,&X1,&X2)  <<endl;
  cout<<"Roots are "<<X0<<",  " <<X1<<",  " <<X2<<endl;

  return 0;
}
