/******************************************************************
The following program solves the linear system A x = b. The system 
to be solved here is the trivial system

[ 1     0     0 ] [x0]   [12.0]
[ 0     2     0 ] [x1] = [12.0]
[ 0     0     3 ] [x2]   [12.0]


and the solution is found using LU decomposition of the matrix A.
This example is modified from the example found online and in the 
GSL manual.

The program reads in data for the matrix from A.dat and B.dat.
In principle, the only changes that need to be made to handle other
matrices is the establishment of a_data and b_data, along with the 
appropriate changes in size parameters.
***************************************************************/
#include<iostream>
#include <stdio.h>
#include <gsl/gsl_linalg.h>
#include<iomanip>

using namespace std;

  int k;

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
    external file "A.dat" Note the order of the 
    entries in A.dat. All the columns in a row
    are read in, then the next row, then the next
    That is, in the usual row-column index notation
    the order is a_11,a_12,a_13,a_21,a_22,a_23,
    a_31,a_32,a_33.                                    
********************************************/  
    double a_data[16];
    FILE *aread;
    aread=fopen("A.dat","r");
  for(k=0;k<16;++k){
    fscanf(aread,"%lf\n",&a_data[k]);
}
    fclose(aread);

/*************************************
At this point the matrix A and the source column
vectr B have been read in.
*****************************************/
  /****************************************
The lines below- an unnecessary part of the computation - 
print out the matrix in the standard appearance. This is 
only as a demonstration for this simple example. In any 
real example the matrix would be too large to be displayed this 
way.

  cout<<" The input matrix is  "<<endl;
 cout<<a_data[0]<<"   "<<a_data[1]<<"   "<<a_data[2]<<endl;
 cout<<a_data[3]<<"   "<<a_data[4]<<"   "<<a_data[5]<<endl;
 cout<<a_data[6]<<"   "<<a_data[7]<<"   "<<a_data[8]<<endl;
cout<<" The input vector is\n";  
 cout<<b_data[0]<<endl;
 cout<<b_data[1]<<endl;
 cout<<b_data[2]<<endl;
 ***************/


  gsl_matrix_view m 
    = gsl_matrix_view_array (a_data, 4, 4);  
  /***************************************************
gsl_matrix is a struct See top of p.90 in the GSL manual gsl_matrix_view_array  
is a function. The command establishes "m" as the object of type gsl_matrix_view  
This line says "m is the struct of type gsl_matrix view with the arguments
shown. Somehow (although I cannot find it in the documentation) the pointer to 
the actual matrix content is called m.matrix. When a gsl_function needs
as a parameter the input matrix, it should be called as &m.matrix.
See below
Note that the second and third arguments are 3, 3. The first 3 is the number
of rows, and the second is the number of columns. See top of p.90 of GSL manual
  ******************************************************/
  gsl_vector_view b                          
  = gsl_vector_view_array (b_data, 4);
/*****************************************************
In a way similar to the above, this sets up the content of the gsl_vector_view b
 *****************************************************/
cout<<" The solution\n";  
gsl_vector *x = gsl_vector_alloc (4);
/******************************************************
This creates the gsl_vector that will hold the solution column.
 ******************************************************/

  int s;
/*****************************************************
This introduces "sgnum" an integer that keeps track of whether
the permutations are even or odd. 
 *****************************************************/
  gsl_permutation * p = gsl_permutation_alloc (4);
/***************************************************
See p.99 of GSL manual. This defines and creates storage for a pointer p to the 
permutation info. See manual
 ***************************************************/
  gsl_linalg_LU_decomp (&m.matrix, p, &s);

/**************************************************
This takes in the matrix m defined about 30 lines up.
along with other arguments to factorize the matrix into L
and U.
 **************************************************/
  gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);
/***************************************************
This uses the LU method to solve for x in Ax=b.
 ***************************************************/
  printf ("x = \n");//just a title line
  gsl_vector_fprintf (stdout, x, "       %g");
/**************************************************
This  print command does the obvious
 **************************************************/
  gsl_permutation_free (p);
  gsl_vector_free (x);
  

return 0;
}
