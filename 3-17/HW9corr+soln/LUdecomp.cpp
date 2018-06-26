/******************************************************************

The problem: the diff eq is f"+f=z^2+2
with conditions: f(0)=1   f(Pi/2)=(Pi/2)^2+1
The analytic solution is f=cos(z)+sin(z)+z^2



We want the solution on 0<z<Pi by solving 4 simultaneous 
equations.

Since we know the values at the end point, the unknowns are 
the 4 values at z=Pi/10, 2Pi/10, 3Pi/10, and 4Pi/10.



***************************************************************/
#include<iostream>
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include<iomanip>
#include<math.h>
using namespace std;
const double PI=4.*atan(1.);
  int k;

double analyt(double z){
  return(cos(z)+sin(z)+z*z); }

int  main (void)
{

/*******************************************
    Read in data for the column vector b from the 
    external file "B.dat"                      
********************************************/  
 double b_data[4];

  FILE *bread;
  bread=fopen("B.dat","r");
    for(k=0;k<4;++k){
    fscanf(bread,"%lf\n",&b_data[k]);}
    fclose(bread);

/*******************************************
    Read in data for the matrix A from the 
    external file "A.dat" 

********************************************/  
    double a_data[16];
    FILE *aread;
    aread=fopen("A.dat","r");
  for(k=0;k<16;++k){
    fscanf(aread,"%lf\n",&a_data[k]);
}
    fclose(aread);



/****************************************                                         
The lines below- an unnecessary part of the computation - print out
the matrix in the standard appearance. This is only as a demonstration
for this simple example. In any real example the matrix would be too
large to be displayed this way
**************************************/
  cout<<" The input matrix is  "<<endl;

  printf(" %4.4g %4.4g %4.4g %4.4g\n",a_data[0],a_data[1],a_data[2],a_data[3]);
  printf(" %4.4g %4.4g %4.4g %4.4g\n",a_data[4],a_data[5],a_data[6],a_data[7]);
  printf(" %4.4g %4.4g %4.4g %4.4g\n",a_data[8],a_data[9],a_data[10],a_data[11]);
  printf(" %4.4g %4.4g %4.4g %4.4g\n",a_data[12],a_data[13],a_data[14],a_data[15]);

  cout<<"\n";
cout<<" The input vector is\n";
 cout<<"   "<<b_data[0]<<endl;
 cout<<"   "<<b_data[1]<<endl;
 cout<<"   "<<b_data[2]<<endl;
 cout<<"   "<<b_data[3]<<endl;




  gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, 4, 4);  

  gsl_vector_view b                          
  = gsl_vector_view_array (b_data, 4);

  //cout<<" The solution\n";  
gsl_vector *x = gsl_vector_alloc (4);

  int s;

  gsl_permutation * p = gsl_permutation_alloc (4);
  gsl_linalg_LU_decomp (&m.matrix, p, &s);
  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);

  double start=1.0, finish=3.46740110029;



  /*********** WRITE RESULTS TO EXTERNAL FILES**********/
FILE *datawrite1;
        datawrite1=fopen("numsoln.dat","w");
fprintf(datawrite1,"       %g\n",start);  
  gsl_vector_fprintf (datawrite1, x, "       %g");
  fprintf(datawrite1,"       %g\n",finish);    
  fclose(datawrite1);

FILE *datawrite2=fopen("ansoln.dat","w");  

cout<<"\n"; 
printf ("      analytic solution \n");//just a title line
 fprintf(datawrite2,"    %g\n",analyt(0.));
 fprintf(datawrite2,"    %g\n",analyt(PI/10.));
 fprintf(datawrite2,"    %g\n",analyt(2.*PI/10.));
 fprintf(datawrite2,"    %g\n",analyt(3.*PI/10.));
 fprintf(datawrite2,"    %g\n",analyt(4.*PI/10.));
 fprintf(datawrite2,"    %g\n",analyt(5.*PI/10));

 fclose(datawrite2);
/******************************************************/
  printf ("      numerical solution \n");//just a title line
  printf("       %g\n",start);  
  gsl_vector_fprintf (stdout, x, "       %g");
    printf("       %g\n",finish);    

cout<<"\n"; 
printf ("      analytic solution \n");//just a title line
 printf("    %g\n",analyt(0.));
 printf("    %g\n",analyt(PI/10.));
 printf("    %g\n",analyt(2.*PI/10.));
 printf("    %g\n",analyt(3.*PI/10.));
 printf("    %g\n",analyt(4.*PI/10.));
 printf("    %g\n",analyt(5.*PI/10.));
  gsl_permutation_free (p);
  gsl_vector_free (x);
  
return 0;
}
