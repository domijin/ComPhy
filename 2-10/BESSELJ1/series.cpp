/*** This function -- written Feb 8, 2014 --- gives the 
     series solution for the Bessel function J_1(x)***/

double series(double x){
  double term=1.;
  double sum=1;
  
  /*** THE SERIES LOOP****/
  for(int n=1;n<1000;++n){
      term=-term/n/(n+1)*(x/2.)*(x/2);
      sum=sum+term;}
  return(x/2*sum);}
