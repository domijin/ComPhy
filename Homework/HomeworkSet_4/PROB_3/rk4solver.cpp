/************************
Runge-Kutta
          Dongming Jin
           Feb. 6 2014
************************/
#include<stdio.h>// If only printf & scanf are used for input & output.
#include<math.h>// function exp
#include<string.h>// function strcmp

extern double f(double, double);

int main(int argc, char *argv[])
{
  printf("  *************************************** *\n");
  printf("  * The default is Runge-Kutta solution   *\n");
  printf("  * To get Richardsonized solution, rerun *\n");
  printf("  * the code with option -r.              *\n");
  printf("  *************************************** *\n");
  // readin  and setting up 
  double xin,xfin,yin;
  int N;
  printf("Enter values of xin and xfin\n");
  scanf("%lf%lf",&xin,&xfin);
  printf("Enter value of yin\n");
  scanf("%lf",&yin);
  printf("Enter value of N\n");
  scanf("%d",&N);

  double h=(xfin-xin)*1.0/N;
  double x=xin,yh=yin,yh2=yin;
  double k1,k2,k3,k4;

  // first order section
  // Runge-Kutta
  for(int i=0;i<N;++i)
    {
      k1=h*f(x,yh);
      k2=h*f(x+h/2.,yh+k1/2.);
      k3=h*f(x+h/2.,yh+k2/2.);
      k4=h*f(x+h,yh+k3);
      yh=yh+k1/6.+k2/3.+k3/3.+k4/6.;
      x=x+h;// If put in first line of the for loop as you did in richardson.cpp, I won't get the same result as you give in email.
    }

  // reload
  h=(xfin-xin)/2./N;
  x=xin;

  // second order section
  // Runge-Kutta
  for(int i=0;i<2*N;++i)
    {
      k1=h*f(x,yh2);
      k2=h*f(x+h/2.,yh2+k1/2.);
      k3=h*f(x+h/2.,yh2+k2/2.);
      k4=h*f(x+h,yh2+k3);
      yh2=yh2+k1/6.+k2/3.+k3/3.+k4/6.;
      x=x+h;
    }
  printf("Result for h\t\t%2.12lf\nResult for h/2\t\t%2.12lf\n",yh,yh2);
  
  // Richardsonized solution section when with option "-r"
    if(argc>1&&strcmp(argv[1],"-r")==0)
    {
      double yrich=4./3.*yh2-yh/3.;// According to wikipedia, A=(4A_1(h/2)-A_1(h)/3)+O(h^3), your note also shows that yexact = y2 - 1/3 (y1-y2)=4/3*y2-1/3*y1
      printf("Richrdson result\t%2.12lf\n",yrich);
    }
  return 0;
}
