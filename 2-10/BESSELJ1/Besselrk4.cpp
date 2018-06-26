/**************************************
This program, written for Phys6352 on Feb 8, 
illustrates the use of RK4 for a second order ODE.
The application is to the bessel function J_1.


This involves solving 
    y"+y'/x+(1-m^2/x^2)y=0
for m=1.  The program computes from x=0 to x=10.

The scheme used is that from Abramowicz & Stegun,
eq.25.5.18 on p.897. To ease reading, the exact same notation
was used.

The starting values of J are found from the power
series, eq.7-50 of Matthews and Walker, or eq.46 in
http://mathworld.wolfram.com/BesselFunctionoftheFirstKind.html

Some relevant values are
J_1(10)=0.0434727462
zero at: 3.83171
 **************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
using namespace std;



extern double f(double, double, double);
extern double g(double, double, double);
extern double series(double);
extern double seriesderiv(double);


int N;

int main(int argc, char *argv[]){
cout<<"Enter N\n";cin>>N;
 FILE *datawrite;
 datawrite=fopen("out.dat","w");


 /*****   FIRST ROUND OF RK4 **********/
double h=10./N;
double x=h, y=1, z=1;
double k1,k2,k3,k4;
double l1,l2,l3,l4;
 fprintf(datawrite,"%lf   %12.10f   %12.10f  \n",x,y,z);//To include the first point
                                                        //in the output.
for (int n=0; n<N-1;++n)
  {
    k1=h*f(x,y,z);               l1=h*g(x,y,z);  
    k2=h*f(x+h/2,y+k1/2,z+l1/2); l2=h*g(x+h/2,y+k1/2,z+l1/2);
    k3=h*f(x+h/2,y+k2/2,z+l2/2); l3=h*g(x+h/2,y+k2/2,z+l2/2);
    k4=h*(x+h,y+k3,z+l3);        l4=h*g(x+h,y+k3,z+l3);  
      y=y+(k1+2*k2+2*k3+k4)/6.;
      z=z+(l1+2*l2+2*l3+l4)/6.;
      x=x+h;
      fprintf(datawrite,"%lf   %12.10f   %12.10f  \n",x,y,z);
   }

 fclose(datawrite);
 double exact=.0434727462;
 double y1=y;
 printf(" Error for h      %12.10e\n", y1-exact);


if(argc>1&&strcmp(argv[1],"-rich")==0){// This flag is for 
                                          // continuation with Richardson
     /** SECOND ROUND RK4 ****/           // extrapolation


 h=h/2;
 x=h; y=series(h); z=seriesderiv(h);
for (int n=0; n<2*N-1;++n)
  {
    k1=h*f(x,y,z);               l1=h*g(x,y,z);  
    k2=h*f(x+h/2,y+k1/2,z+l1/2); l2=h*g(x+h/2,y+k1/2,z+l1/2);
    k3=h*f(x+h/2,y+k2/2,z+l2/2); l3=h*g(x+h/2,y+k2/2,z+l2/2);
    k4=h*(x+h,y+k3,z+l3);        l4=h*g(x+h,y+k3,z+l3);  
      y=y+(k1+2*k2+2*k3+k4)/6.;
      z=z+(l1+2*l2+2*l3+l4)/6.;
      x=x+h;
      //      fprintf(datawrite,"%lf   %12.10f   %12.10f  \n",x,y,z);
   }
 double y2=y;

  printf(" Error for h/2    %12.10e\n", y2-exact);


  /****** RICHARDSON RESULT **********************/

  printf(" Richardson error  %12.10e\n", (16.*y2-y1)/15-exact);}

 return(0);
}
