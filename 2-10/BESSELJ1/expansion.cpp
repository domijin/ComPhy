/** TRY OUT SERIES ******************************

This program, written Feb8, 2014, explores the use of 
the series soluton for the Bessel function J_1(x).

One use is to examine the relationship of the number of 
terms needed for accuracy, and the value of x. Because 
this is an alternating series, the error is guaranteed to
be smaller than the first omitted term.

Note that the counting index n starts with the term propto x^3.
Thus e.g., in the loop, n<10, means that the first term omitted
is the term propto x^21.

Note that the magnitude of the nth term is 

       (x/2)^(2n+1)/n!/(n+1)!
*******************************************/
#include<iostream>
#include<stdio.h>
using namespace std;


double series(double x){
  double term=1.;
  double sum=1;
  

  /*** THE SERIES LOOP****/
  
  for(int n=1;n<100;++n){
      term=-term/n/(n+1)*(x/2.)*(x/2);
      sum=sum+term;}
  return(x/2*sum);}


/**** THE PROGRAM THAT CALLS THE SERIES***/
int main(){
  double x,J1;
   FILE *datawrite;
   datawrite=fopen("series.dat","w");


  for(int k=0;k<101;++k)
    {
    x=.1*k;
    J1=series(x);
    fprintf(datawrite,"%lf    %12.10f\n",x,J1);
      }
  fclose(datawrite);
  return 0;

}
