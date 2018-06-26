/******************************************************************
The problem: the diff eq is f"+f=1/(1+z)+2/(1+z)^3
with conditions: f(0)=2   f(2.5Pi)=1+1/(1+2.5Pi)
The analytic solution is f=cos(z)+sin(z)+1/(z+1)
***************************************************************/
#include<iostream>
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include<iomanip>
#include<math.h>
using namespace std;
const double PI=4.*atan(1.);
int k;

// analytic solution
double analyt(double z)
{
  return(cos(z)+sin(z)+1./(z+1));
}

// calculate L2 error without f0 and fn
double L2(gsl_vector *x,int n)
{
  double err=0;
  for (k=0;k<n;k++)
    err+=pow(gsl_vector_get(x,k)-analyt(PI*2.5/(n+1)*(k+1)),2);
  return sqrt(err/n);
}

int  main (void)
{
  // Readin B.dat and determine n;
  FILE *bread;
  bread=fopen("B.dat","r");
  int n=0;// counter
  double temp;
  while(fscanf(bread,"%lf\n",&temp)!=EOF)// if not end of file, n++
    n++;
  fclose(bread);

  // generate array for A.dat nxn matrix and B.dat 1xn vector
  double *a_data,*b_data;
  a_data = (double *)malloc(n*n*sizeof(double));
  b_data = (double *)malloc(n*sizeof(double));

/*******************************************
    Read in data for the column vector b from the 
    external file "B.dat"                      
********************************************/ 
  FILE *bin;
  bin=fopen("B.dat","r");
  for(k=0;k<n;++k){
    fscanf(bin,"%lf\n",&b_data[k]);}
  fclose(bin);

/*******************************************
    Read in data for the matrix A from the 
    external file "A.dat" 
********************************************/  
  FILE *aread;
  aread=fopen("A.dat","r");
  for(k=0;k<n*n;++k)
    fscanf(aread,"%lf\n",&a_data[k]);
  fclose(aread);

/****************************************                                         
The lines below- an unnecessary part of the computation - print out
the matrix in the standard appearance. This is only as a demonstration
for this simple example. In any real example the matrix would be too
large to be displayed this way
**************************************/
  cout<<" The input matrix is  "<<endl;
  for (k=0;k<n*n;k++)
    {
      printf("\t%1.5g",a_data[k]);
      if ((k+1)%n==0)
	cout<<endl;
    }

  cout<<" The input vector is\n";
  for (k=0;k<n;k++)
    printf("\t%1.8g\n",b_data[k]);


  // gsl_linalg calculation
  gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, n, n);  

  gsl_vector_view b                          
    = gsl_vector_view_array (b_data, n);
  
  gsl_vector *x = gsl_vector_alloc (n);

  int s;

  gsl_permutation * p = gsl_permutation_alloc (n);
  gsl_linalg_LU_decomp (&m.matrix, p, &s);
  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);

  // start point value and end point value
  double f0=2., fn=1+1./(1+2.5*PI);

  /*********** WRITE RESULTS TO EXTERNAL FILES**********/
  // Numerical solution
  FILE *datawrite1;
  datawrite1=fopen("numsoln.dat","w");
  fprintf(datawrite1," Numerical solution\n\tz\t\tf(z)\n");// Title line
  fprintf(datawrite1,"\t%1.8g\t\t%g\n",0.,f0); // Start point
  // n points
  for (k=0;k<n;k++)
    fprintf(datawrite1,"\t%1.8g\t%1.8g\n",2.5*PI/(n+1)*(k+1),gsl_vector_get(x,k));
  fprintf(datawrite1,"\t%1.8g\t%1.8g\n",2.5*PI,fn);// End point
  fclose(datawrite1);

  //Analytic solution
  FILE *datawrite2=fopen("ansoln.dat","w");  
  fprintf(datawrite1," Analytic solution\n\tz\t\tf(z)\n");// Title line
  fprintf(datawrite2,"\t%1.8g\t\t%1.8g\n",0.,2.);
  for (k=1;k<n+2;k++)
    fprintf(datawrite2,"\t%1.8g\t%1.8g\n",2.5*PI/(n+1)*k,analyt(PI*2.5/(n+1)*k));
  fclose(datawrite2);

/****************** WRITE RESULTS TO SCREEN *********************/
  printf(" Numerical solution\n\tz\t\tf(z)\n");
  printf("\t%1.8g\t\t%1.8g\n",0.,f0);
  for (k=0;k<n;k++)
    printf("\t%1.8g\t%1.8g\n",2.5*PI/(n+1)*(k+1),gsl_vector_get(x,k));
  printf("\t%1.8g\t%g\n",2.5*PI,fn);

  printf(" Analytic solution\n\tz\t\tf(z)\n");
  printf("\t%1.8g\t\t%1.8g\n",0.,2.);
  for (k=1;k<n+2;k++)
    printf("\t%1.8g\t%1.8g\n",PI*2.5/(n+1)*k,analyt(PI*2.5/(n+1)*k));

  printf("L2 error = %1.8g\n",L2(x,n));

  gsl_permutation_free (p);
  gsl_vector_free (x);
  return 0;
}
