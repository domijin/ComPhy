/*****************************************************
Written Feb 16.

Example of a stiff equation addressed by an adaptive step size.

The sudden rise in the solution around x=50 requires a very small step size,
but for larger x, the stepsize can be very large.  
This is accomplished with an error monitor that adjusts the 
stepsize.

This example also illustrates C++ style output.

The results are qualitatively good for tolerance chosen less than 0.5

********************************************************/

#include<iostream>
#include<fstream>//<-- needed for C++ style output file
#include<iomanip>//<--necessary for "setw" spacer in output
#include<math.h>//<--needed for cube root
using namespace std;

double f(double x, double y){
  return(y*y*(1-y));}

int main()
{ofstream  output;          // C++ style output
  output.open ("out.dat");

  double x=0, y=0.01,y_c,h2,k1,k1_c,k2,k2_c;
  double tolerance=.01;//should be less than .05 for qual correc., =<0.1 for good
  double err;
  

  double h=0.001;while(x<200)
    {k1=h*f(x,y);k2=h*f(x+h,y+k1);
      y=y+(k1+k2)/2.;
  /**** Comparison solution*******/      
       h2=h/2.;
       k1_c=h2*f(x,y);k2_c=h*f(x+h2,y+k1_c);
       y_c=y+(k1_c+k2_c)/2.;     
       err=y-y_c;

 /****comment out the next two line to change the program to pure Richardson****/
    if(fabs(err)>tolerance){h=h*0.9*pow(tolerance/fabs(err),.333);}
     if(fabs(err)<10.*tolerance){h=min(1.,h*0.1*pow(tolerance/fabs(err),.333));}
/***************************************************************************/ 
      y=(8*y_c-y)/7.;  // Richardson improvement
      x=x+h;

output<<setw(5)<<setprecision(7)<<x<<"  "<<setw(10)<<setprecision(7)<<y<<"   "<<h<<endl;



          
}
  output.close();
  return(0);
}
