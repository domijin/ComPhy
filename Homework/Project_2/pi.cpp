#include <stdio.h>
#include <math.h>
#include <random>
#include <time.h>
#include <iostream>
using namespace std;
int main()
{
  double x = 0;
  double y = 0;
  double inside = 0;
  double total = 0;
  srand(time(NULL));
  int n=10000;
  cin>>n;
  for (int i=0;i<n;i++)
    {
      x = 1.0*rand()/(RAND_MAX+1.);
      y = 1.0*rand()/(RAND_MAX+1.);
      double sqrtxy = sqrt(x*x+y*y);
      if (sqrtxy<=1)
	inside = inside + 1.;
      total = total + 1.;
      printf("%f\n",4.*inside/total);
    }
  printf("PI is %f\n",4.*inside/total);
  return 0;
}
