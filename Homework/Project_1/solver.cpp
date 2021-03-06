/**************************************
Projectile problem, air drag is proportional 
to nth power of velocity. Calculate the
optimal angel.
Project #1         by Dongming Jin
 *************************************/
#include<iostream>
#include<math.h>
#define PI 3.14159265358979
#define g 10 // gravational constant
using namespace std;
int N;//Accuracy
double n,C;//Air resistance factor and power

// x"=-C v^(n-1)x'
// y"=-C v^(n-1)y'-g
// Ronge-Kutta Method
double fx(double t, double x, double vx,double v)
{
  return(vx);
}

double gx(double t, double x, double vx,double v)
{
  return(-C*pow(v,n-1)*vx);
}

double fy(double t, double y, double vy, double v)
{
  return(vy);
}

double gy(double t, double y, double vy, double v)
{
  return(-C*pow(v,n-1)*vy-g);
}

double rk4(double vx,double vy,double v)
{
  double k1,k2,k3,k4,j1,j2,j3,j4;
  double x=0,y=0,t=1.0/N,h=t;
  do
    {
      k1=t*fx(t,x,vx,v);                    j1=t*gx(t,x,vx,v);
      k2=t*fx(t+h/2,x+k1/2,vx+j1/2,v);      j2=t*gx(t+h/2,x+k1/2,vx+j1/2,v);
      k3=t*fx(t+h/2,x+k2/2,vx+j2/2,v);      j3=t*gx(t+h/2,x+k2/2,vx+j2/2,v);
      k4=t*fx(t+h,x+k3,vx+j3,v);            j4=t*gx(t+h,x+k3,vx+j3,v);
  
      x=x+1.0/6*(k1+2*k2+2*k3+k4);
      vx=vx+1.0/6*(j1+2*j2+2*j3+j4);
      
      v=sqrt(vx*vx+vy*vy);// Updating v
            
      k1=t*fy(t,y,vy,v);                    j1=t*gy(t,y,vy,v);
      k2=t*fy(t+h/2,y+k1/2,vy+j1/2,v);      j2=t*gy(t+h/2,y+k1/2,vy+j1/2,v);
      k3=t*fy(t+h/2,y+k2/2,vy+j2/2,v);      j3=t*gy(t+h/2,y+k2/2,vy+j2/2,v);
      k4=t*fy(t+h,y+k3,vy+j3,v);            j4=t*gy(t+h,y+k3,vy+j3,v);

      y=y+1.0/6*(k1+2*k2+2*k3+k4);
      vy=vy+1.0/6*(j1+2*j2+2*j3+j4);

      v=sqrt(vx*vx+vy*vy);// Updating v
      t=t+1.0/N;
    }
  while (y>0);//When kit the ground, y=0
  return x;
}

int main()
{
  N=1000000;
  for(n=0;n<6;n+=0.1)// Air resistance order range
    {
      double Max=0,Maxtheta=0;// Record for the max theta0
      double v0=1.1;
      C=0.03;
      for(double theta0=10;theta0<80;theta0+=0.01)// Initial angel
	{
	  double vx=v0*cos(theta0*PI/180),vy=v0*sin(theta0*PI/180);
	  double temp=rk4(vx,vy,v0);
	  if(temp>Max)// Record the Maximun distance and corresponding theta0
	    {
	      Max=temp;
	      Maxtheta=theta0;
	    }
	}
      cout<<n<<'\t'<<Maxtheta<<endl; //Output the theta0 for n
    }
  return 0;
}
