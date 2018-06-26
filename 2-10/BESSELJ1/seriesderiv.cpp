/*** This function -- written Feb 8, 2014 --- gives the 
     series solution for series solution of the the Bessel function J_1(x)***/

double seriesderiv(double x){
  double term=1;
  double sum=1;
      for(int n=1;n<1000;++n){
	term=-term*(2.*n+1.)/(2.*n)/n/(2.*n-1.)*(x/2.)*(x/2.);
     sum=sum+term;}
  return(1./2.*sum);}
