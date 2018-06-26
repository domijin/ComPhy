/************************************************
                   FEB 24, 2014
This program is a modification of the example in the 
interpolation chapter of the GSL manual. Here the gsl
calls have been changed from the spline case, done in
the manual, to the "poly" case (i.e., Lagrange interp).
Also, the data have been changed. Here the x spacing
is even, and the function to be interpolated is y=
x*exp(-20x^2).

Here also, for plotting, fprintf calls have been 
added to print to files out1.dat and out2.dat.

NOTE: remember to compile with -lgsl flag!
*********************************************/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_interp.h>//Note the "includes" in this header, such as
                          //gsl_types.h
//using namespace std;

int main (void){
FILE * output1;
FILE * output2;
output1 =fopen("out1.dat","w");
output2=fopen("out2.dat","w");
 int i;
double xi, yi, x[10], y[10];
/*********************************/
     printf ("#m=0,S=2\n");
/*********************************/
/**** GENERATE THE DATA***********/
for (i = 0; i < 10; i++)
  {double iby=1.0*i;        //<---  for scaling possibility
x[i] = -.9+0.2*iby;
y[i] = x[i]*exp(-20.*x[i]*x[i]);
     fprintf (output1,"%g %g\n", x[i], y[i]);
     printf ("%g %g\n", x[i], y[i]);
        }
/*********************************/
    printf ("#m=1,S=0\n");
/*********************************/

    
gsl_interp_accel *acc= gsl_interp_accel_alloc ();  
gsl_interp *polynomial=gsl_interp_alloc(gsl_interp_polynomial,10);
gsl_interp_init(polynomial,x,y,10);


for (xi = x[0]; xi <x[9]; xi += 0.01)
      { yi = gsl_interp_eval (polynomial, x,y,xi,  acc);
	fprintf (output2,"%g %g\n", xi, yi);
	printf ("%g %g\n", xi, yi);
       }

gsl_interp_free (polynomial);
fclose(output1);
fclose(output2);

return 0;
}
