/************************************
Monte Carlo Integration
I = integral_a^b f(x)dx
 ************************************/
#include<stdio.h>
#include<iostream>
#include<time.h>
#include<random>
#include<math.h>
#include<fstream>
using namespace std;
// Extern function to be integraded
extern double f(double);
extern double x(double);
extern double p(double);
extern void g();
// Straight Monte Carlo Integration
double mcintST(double a, double b, double n)
{
  srand (time(NULL));// cpu time as random seed
  double y=0,yy=0;
  double xi,err;

  // file operation
  ofstream output;
  output.open("uniform.dat");

  for (int i=0;i<n;i++)
    {
      xi = 1.0*rand()/(RAND_MAX+1.)*(b-a) + a;// random xi in [a,b]
      y+=f(xi);
      yy+=pow(f(xi),2);
      err=(b-a)*sqrt((yy/n - pow((y/n),2))/n);
      output<<xi<<"\t"<<f(xi)<<"\t"<<err<<endl;
    }
  output.close();
  return y*(b-a)/n;
}
// Importance Sampling
double mcintIS(double a, double b, double n)
{
  srand (time(NULL));
  double y=0,yy=0;
  double yi,xi,err;

  // file operation
  ofstream output;
  output.open("import_sampling.dat");

  for (int i=0;i<n;i++)
    {
      yi = 1.0*rand()/(RAND_MAX+1.);
      xi = x(yi);
      y+=f(xi)/p(xi);
      yy+=pow(f(xi)/p(xi),2);
      err=(b-a)*sqrt((yy/n - pow((y/n),2))/n);

      //output: yi uniform in (a,b), xi new variable, new function, err
      output<<yi<<"\t"<<xi<<"\t"<<f(xi)/p(xi)<<"\t"<<err<<endl;
    }
  output.close();
  return y/n;
}

int main(int argc, char *argv[])// option -t to define range and number of points
{
  // default range and number of points
  double a=0,b=1;
  int n=100;

  if(argc>1)
    {
      if(strcmp(argv[1],"-t")==0)
	{
	  cout<<"On the next line, specify the range\n";
	  cin>>a>>b;
	  cout<<"On the next line, specify the number of points\n";
	  cin>>n;
	}
      else
	n=atof(argv[1]);
    }

  printf("%1.14f\n",mcintST(a,b,n));
  printf("%1.14f\n",mcintIS(a,b,n));
  g();
  return 0;
}
