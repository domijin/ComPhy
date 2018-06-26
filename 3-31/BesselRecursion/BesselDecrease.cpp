/***************************************************************************
* The “recursion” relationship for the Bessel function is given by         *
*             Jm+1 (x) = (2m/x)Jm (x) − Jm−1 (x)                           *
* This program evaluates Bessel Function in the direction of decreasing m. *
* And it does give the correct values for Jm (x) of lower m.               *
* The recursion is stable                                                  *
***************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

int main()
{
 double x=1.; //specified x at 1
 double y[11];
  y[10]=0; //starting point of y
  y[9]=1.;
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
 for(n=8;n>=0;n--) //evaluate Bessel Function at nth order 
   {
     y[n]=2*(n+1)*y[n+1]/x-y[n+2];
   }
 double scale=j[0]/y[0]; //scale factor
/*****print out estimate and exact values**************/
 cout<<"n"<<"\t"<<"   yn"<<"\t"<<"          yn*Jn"<<"\t"<<"          Jn(1)"<<endl;
 for(n=10;n>=0;n--)
   {
     printf("%d\t%9.1f\t%1.10f\t%1.10f\n",n,y[n],y[n]*scale,j[n]);
   }
 printf("Scale factor=J0(1)/y0=%1.10f/%9.1f=%e \n",j[0],y[0],scale);

 return(0);
}
     
