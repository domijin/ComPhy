/**************************
This is the input function for
trapezoidal and Simpson integration.
Comment out lines as needed.
 **************************/


#include<math.h>
double f(double x){
using namespace std;
double PI=4.*atan(1.);

//    return(4.*x*x*x);

/*** For the following line the exact int 
     from 0 to 1 is 1.0******************/
return(01.5*PI*sin(3.*PI*x));
}
