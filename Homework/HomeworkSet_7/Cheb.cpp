/***********************
Chebyshev Interpolation for f(x)=x*exp(-20*x*x)

The program generates 10 Chebshev nodes of that function on -1<x<+1, output into screen, it also generates the exact data for the function in "exact.dat" file. The polynomial approximation will output into file "interp.dat"
 **********************/
#include <stdio.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_chebyshev.h> // refer to ref_gsl pages 342, chebyshev example

// The function
double f (double x, void *p) 
{
  return x*exp(-20*x*x);
}

int main (void)
{
  FILE * outputitp;
  FILE * outputex;
  outputitp=fopen("interp.dat","w");
  outputex=fopen("exact.dat","w");

  int i, n = 5;
  gsl_cheb_series *cs = gsl_cheb_alloc (20); // Accuracy in an order of 20th
  gsl_function F;
  F.function = f;
  F.params = 0;
  gsl_cheb_init (cs, &F, -1.0, 1.0); // Initilization

  double x[10];
  for (i = 0; i < 10; i++)
    {
      x[i] = (i-4.5) / ((double)n-0.5); // -1 ... 1, 10 pts
      printf ("%g\t%g\n",x[i], GSL_FN_EVAL(&F, x[i])); // 10 nodes, print out on screen
    }
  for (double xi=x[0];xi< x[9]; xi+=0.01) // generating polynomial approximation data
    {
      double yi = gsl_cheb_eval_n (cs, 20, xi);
      fprintf(outputitp,"%g\t%g\n", xi, yi);
      fprintf(outputex,"%g\t%g\n",xi,xi*exp(-20*xi*xi));
    }
  gsl_cheb_free (cs);
  fclose(outputitp);
  fclose(outputex);
  return 0; 
}
