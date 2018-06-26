/***************************************************************************
*        Evaluation of Bessel functions by downward recursion              *
* The “recursion” relationship for the Bessel function is given by         *
*             Jm+1 (x) = (2m/x)Jm (x) − Jm−1 (x)                           *
* However,starting from m=1 and using this relationship does not give      *
* the correct values for Jm (x) of higher m. The recursion is unstable     *
* in the direction of increasing m. But it is stable going in the opposite *
* direction, i.e., starting from large m, which is downward recursion.     *
* This program evaluates Bessel Function with downward recursion.          *
***************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<vector> //to use vector
#include<gsl/gsl_sf_bessel.h> //to use Bessel Functions in gsl

using namespace std;

int main()
{
 double x;
 double JN,Jexact,Jestimate,J0;
 int n,N,i;

 /*************define values of x, order of the Bessel Function and starting point*******/ 
 cout<<"Please enter the value of x and the order N of the Bessel Function"<<endl;
 cin>>x;
 cin>>N;
 cout<<"Please select the starting point of the index, at lease five steps ahead of the order N"<<endl;
 cin>>n;
 vector<double> y(n);//claim a vector to store estimated values

 /****************Estimate and normalize the Bessel Function *************/
 if(n-x<5) {
   cout<<"Please select starting point bigger"<<endl; 
   exit(0);}

 y[n]=0.;
 y[n-1]=1.;
 for(i=n-2;i>=0;i--) //for loop to calculate values of Bessel Function downward to 0
   {
     y[i]=2*(i+1)*y[i+1]/x-y[i+2];
     if(i==N)
       JN=y[i];
   }

 J0=gsl_sf_bessel_J0 (x);
 double scale=J0/y[0]; //normalize constant
 Jestimate=JN*scale; //estimate value
 Jexact=gsl_sf_bessel_Jn(N, x); //exact value 

 /****************print out the results***********************/
 printf("Values of the %dth order of Bessel Function at %f\n",N,x);
 printf("Estimate value: %1.10f,\tExact Value: %1.10f\n",Jestimate,Jexact);
 printf("error: %e\n",Jestimate-Jexact);
 printf("Scale factor=J0(%f)/y0=%1.10f/%9.1f=%e \n",x,J0,y[0],scale);

 return(0);
}
     
