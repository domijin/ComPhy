/*********************************************************
A closed surface consists of a cone topped by a segment of a spherical suface, centered on the apex of the cone. The opening angle of the cone is denoted θ0.
The conical sides are grounded, i.e., are at electrical potential zero. The spherical cap is at some nonzero potential V0. Inside the closed surface, the interior electric field intensity vanishes at the apex (if θ0 < π/2). At a distance r from the apex the electric field strength has a magnitude that behaves as E~r^k

This program will automatically search for the first 10 terms of l of a given θ0 using bisection method and Runge-Kutta 4th order 
*********************************************************/

/********************************************************
Instruction:
   All function are included in the main code,"solver.cpp"
The executable file a.out is compiled from solver.cpp.
It will generate a "out.dat" file with set of theta0 and 
corresponding k. The default theta0 in this program is 
15, 30, 45, 60, 75, 90. 
 *******************************************************/
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979
//global variable for searching step
int N;
double h;

// f=z(x,y,z)=y'
double f(double x, double y, double z)
{
  return(z);
}

// g=z'(x,y,y',l)=y"
double g(double x, double y, double z, double l)
{
  return(2*x/(1-x)/(1+x)*z-l*(l+1)/(1-x)/(1+x)*y);
}

// Runge-Kutta 4th order
double rk4(double x,double y,double z,double l)
{
  double k1,k2,k3,k4,j1,j2,j3,j4;
  for(int k=0;k<N;++k)
    {
      k1=h*f(x,y,z);                    j1=h*g(x,y,z,l);
      k2=h*f(x+h/2,y+k1/2,z+j1/2);      j2=h*g(x+h/2,y+k1/2,z+j1/2,l);
      k3=h*f(x+h/2,y+k2/2,z+j2/2);      j3=h*g(x+h/2,y+k2/2,z+j2/2,l);
      k4=h*f(x+h,y+k3,z+j3);            j4=h*g(x+h,y+k3,z+j3,l);

      x=x+h;
      y=y+1.0/6*(k1+2*k2+2*k3+k4);
      z=z+1.0/6*(j1+2*j2+2*j3+j4);
    }
  return z;// return y', when y'=0, l is the eigenvalue
}

// find the next l which makes y' has different sign, then using bisection to search for the eigenvalue between them
double nextl(double x,double y,double z,double lin)
{
  double temp=rk4(x,y,z,lin);// y' with initial l
  double lfin=lin+1;// first guess of the next l
  while (temp*rk4(x,y,z,lfin)>0)// if y'(lfin) still has the same sign with y'(lin), add more for l
    {
      lfin=lfin+0.1;
    }
  return lfin;
}

int main ()
{
  // file operation
  FILE *datawrite;
  datawrite=fopen("out.dat","w");

  double theta;// the given theta0

  for(theta=PI/2;theta>0.0001;theta=theta-15.0*PI/180)// for a serier of theta
    {

  // Presicion
  N=1000;
  h=(cos(theta)-1)/N;
  double eps=1.0e-6;
  
  // Start point: at the axis, theta=0, x=1+h(to avoid INF), potential is very small and doesn't change, so I set z=y'=0
  double x=1+h,y=-h,z=0,lin=-h,lfin,l;
  
  int NO=0;// Counter for total term number of l
 
  while(NO<1) // Total term number
    {
      lfin=nextl(x,y,z,lin);// find the range of l
      //      cout<<lin<<'\t'<<lfin<<endl;
      // bisection to solve for l
      while(fabs(rk4(x,y,z,lin)-rk4(x,y,z,lfin))>eps)
	{
	  l=(lin+lfin)/2;
	  if(rk4(x,y,z,lin)*rk4(x,y,z,l)>0)
	    lin=l;
	  else lfin=l;
	}
      //      cout<<l<<'\t'<<lin<<'\t'<<lfin<<endl;
      fprintf(datawrite,"%12.10f\t%12.10f\n",theta/PI*180,l-1);// print theta0 &k into file
      NO++;
      lin=lfin;// new searching start
    }
    }

  fclose(datawrite);
  return 0;
}
