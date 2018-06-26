#include<iostream>
/***************************************************************************
* The “recursion” relationship for the Bessel function is given by         *
*             Jm+1 (x) = (2m/x)Jm (x) − Jm−1 (x)                           *
* This program evaluates Bessel Function in the direction of increasing m. *
* But it does not give the correct values for Jm (x) of higher m.          *
* The recursion is unstable                                                *
***************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
 double x=1.; //specified x at 1
 double y[11];
  y[0]=0.7651976866; //starting points of y
  y[1]=0.4400505857;
 double j[11]; //exact values of Bessel Function from order 0 to 10 at x=1
  j[0]=0.7651976866;
  j[1]=0.4400505857;
  j[2]=0.1149034849;
  j[3]=0.0195633540;
  j[4]=0.0024766390;
  j[5]=0.0002497577;
  j[6]=0.0000209383;
  j[7]=0.0000015023;
  j[8]=0.0000000942;
  j[9]=0.0000000052;
  j[10]=0.0000000003;
 int n;
 for(n=2;n<11;n++) //evaluate Bessel Function at nth order
   {
     y[n]=2*(n-1)*y[n-1]/x-y[n-2];
   }

/*****print out estimate and exact values**************/
 cout<<"n"<<"\t"<<" yn"<<"\t"<<"          Jn(1)"<<endl;
 for(n=0;n<11;n++)
   {
     printf("%d\t%1.10f\t%1.10f\n",n,y[n],j[n]);
   }
 return(0);
}
     
