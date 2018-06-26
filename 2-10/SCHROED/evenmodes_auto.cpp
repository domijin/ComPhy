/***************************************
This exercise involves using 4th order Runge-Kutta
to solve a de-dimensionalized Schroedinger equation
of the form psi"+K(x-1)^2 psi=-E* psi

This program is the same as evenmodes.cpp, except
that it automatically finds the Energy eigenvalue.

The user specifies initial guesses on the command line
when invoking the program. If the Eigenvalue is not 
bracketed, the program asks the user to try again.
*****************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<cstdlib>
using namespace std;

/**** The function that characterizes the Schroed eq.***/
double f(double x, double y, double E)
{double K=10;
  double result=-(K*(x-1.)*(x+1.)+E)*y;
  return(result);}
  
/***    RK for fixed starting conditions ********/
double rk(double E)
{ double x=0,y=1;
  double k1,k2,k3,yprime=0; int N=100;
  double h=1./N;
for(int k=0;k<N;++k)//The RK loop
  {  
      k1=h*f(x,y,E);
      k2=h*f(x+h/2,y+h/2*yprime+h/8*k1,E);
      k3=h*f(x+h,y+h*yprime+h/2*k2,E);
      y=y+h*(yprime+(k1+2*k2)/6);
      yprime=yprime+(k1+4*k2+k3)/6;
      x=x+h;
    }
 return(y);
}



/*******   Main program with initial E guesses ******/
int main (int argc, char *argv[]){
  if(argc<=2){cout<< "specify E1 and E2 value!!\n";
    exit(0);}
  double E1 =atof(argv[1]);//This is the starting value of E
  double E2 =atof(argv[2]);//This is the starting value of E
  double x,y,y1,y2,ynew,Enew;

  y1=rk(E1);  
  y2=rk(E2);  

  if(y1*y2>0){    // Is the eigenvalue bracketed? 
  cout<<"psi1=   "<<y1<<endl;
 cout<<"psi2=   "<<y2<<endl;
 cout<<"Try again\n";
 exit(0);}

  //BISECTION 
  //If the eigen is bracketed, then we go on to use bisection
  //to find an accurate value for the eigenvalue.
  

  while(fabs(y1)+fabs(y2)>1.e-10){  
   Enew=(E1+E2)/2.;  
   ynew=rk(Enew);
   if(ynew*y1>0) {E1=E2;E2=Enew;}
   else {E2=E1;E1=Enew;}
   cout<<y1<<endl;
  y1=rk(E1);  
  y2=rk(E2);  }

printf("Eigenvalue   %12.10f\n",Enew);


//PRINT OUT THE EIGENFUNCTION REUSING THE RK LOOP
     FILE *datawrite;
     datawrite=fopen("out.dat","w");
     x=0;y=1;double h=0.01;
for(int k=0;k<100;++k)//The RK loop
  {  double k1,k2,k3,yprime;
      k1=h*f(x,y,Enew);
      k2=h*f(x+h/2,y+h/2*yprime+h/8*k1,Enew);
      k3=h*f(x+h,y+h*yprime+h/2*k2,Enew);
      y=y+h*(yprime+(k1+2*k2)/6);
      yprime=yprime+(k1+4*k2+k3)/6;
      x=x+h;
            fprintf(datawrite,"%lf   %12.10f\n",x,y);  
  }
       







     fclose(datawrite);
  return 0;
}






      




