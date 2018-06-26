/*********************
generate A matrix and B vector
for f"+f=1/(z+1)+1/(z+1)^3
with user defined dimension n
 ********************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h> //for malloc
#include<math.h>
#include<stdlib.h>
#define pi 4*atan(1)
using namespace std;

int main()
{
  // file operation
  FILE *Aout,*Bout;
  Aout=fopen("A.dat","w");
  Bout=fopen("B.dat","w");

  int n,i;
  cout<<"Please Specify n"<<endl;
  cin>>n;
  
  // assign ram address to desired array and matrix
  double *a_data,*b_data;
  a_data = (double *)malloc(n*n*sizeof(double));
  b_data = (double *)malloc(n*sizeof(double));
  double h=2.5*pi/(n+1),f0=2,fn=1+1./(1+2.5*pi);

  // calculate vector B.dat 
  for (i=1;i<n-1;i++)
    {
      double z=(i+1)*h;//z[i]=(i+1)*h
      b_data[i]=1./(z+1)+2./pow(z+1,3);
    }
  b_data[0]=1./(h+1)+2./pow(h+1,3)-f0/h/h;
  b_data[n-1]=1./(n*h+1)+2./pow(n*h+1,3)-fn/h/h;
  
  // calculate matrix A.dat
  for (i=0;i<n*n;i++)
    a_data[i]=0;// initilization

  for (i=0;i<n;i++)
    a_data[i*n+i]=1.-2./h/h;//middle term in equations

  for (i=0;i<n-1;i++)
    {
      a_data[i*n+i+1]=1./h/h;
      a_data[(i+1)*n+i]=1./h/h;
    }
  
  for (i=0;i<n*n;i++)
    fprintf(Aout,"%1.8g\n",a_data[i]);

  for (i=0;i<n;i++)
    fprintf(Bout,"%1.8g\n",b_data[i]);

  fclose(Aout);
  fclose(Bout);
  return 0;
}
