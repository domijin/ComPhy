/**************************
Problem 1
     By Dongming Jin
**************************/
#include<iostream>
#include<math.h>
using namespace std;
extern double f1(double,double);
extern double df1x(double,double);
extern double df1y(double,double);
extern double f2(double,double);
extern double df2x(double,double);
extern double df2y(double,double);
int main()
{
  double x,y,eps=1.0e-10;
  cout<<"enter x"<<endl;
  cin>>x;
  cout<<"enter y"<<endl;
  cin>>y;
  int k=0;
  while(fabs(f1(x,y))>=eps||fabs(f2(x,y))>=eps)
    {
      cout.precision(11);
      cout<<x<<'\t'<<y<<'\t'<<f1(x,y)<<'\t'<<f2(x,y)<<endl;
      x=x-(df2y(x,y)*f1(x,y)-df1y(x,y)*f2(x,y))/(df1x(x,y)*df2y(x,y)-df1y(x,y)*df2x(x,y));
      y=y+(df2x(x,y)*f1(x,y)-df1x(x,y)*f2(x,y))/(df1x(x,y)*df2y(x,y)-df1y(x,y)*df2x(x,y));
      k++;
      if (k>100)
	break;
    }
  cout<<x<<'\t'<<y<<'\t'<<f1(x,y)<<'\t'<<f2(x,y)<<endl;
  return 0;
}
