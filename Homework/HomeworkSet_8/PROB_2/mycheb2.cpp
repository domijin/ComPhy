/*********************************
f(x)=exp(-x)*sin(pi*x)
I = −0.6793261834020956
For the last homework, I was supposed to use gsl to do chebyshev interpolation but didn't follow your instruction. I just realized that with the interpolation of the function, the integral is just the summation over the range. So I modify that program to do the same work
*********************************/
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_interp.h>//Note the "includes" in this header, such as
                          //gsl_types.h
#define pi 4.*atan(1)
#define exact -0.6793261834020956
// Define function
double f(double x)
{
  return (exp(-x)*sin(pi*x));
}

int main (void)
{
  int i,n;
  double xi, yi, *x, *y, result=0;// set up pointer for dynamical array
  printf("Please specify the number of Chebyshev nodes to use\n");
  scanf("%d",&n);
  x=(double *)malloc(n*sizeof(double));
  y=(double *)malloc(n*sizeof(double));

  /**** GENERATE THE DATA***********/
  for (i = 0; i < n; i++)
    {
      x[i] = (i-(n-1)*.5) / ((double)n-1)*2.;// n nodes equally from -1 to 1 
      y[i] = f(x[i]);
    }

  gsl_interp_accel *acc= gsl_interp_accel_alloc ();  
  gsl_interp *polynomial=gsl_interp_alloc(gsl_interp_polynomial,n);
  gsl_interp_init(polynomial,x,y,n);

  for (xi = x[0]; xi <x[n-1]; xi += 0.01)// sampling the data from the interpolation
      { 
	yi = gsl_interp_eval (polynomial,x,y,xi,acc);
	result+= yi;
      }

  printf("estimate for the integral is \t      %2.14f\nerror with fairly precision value is  %2.14f\n",result/100.,result/100.-exact);
  gsl_interp_free (polynomial);
  
  free(x);
  free(y);
  return 0;
}
