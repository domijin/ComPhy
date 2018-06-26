/*******************************
A small program to demonstrate 
how to solve using substitution
with an externally defined 
function
*******************************/
#include<iostream>
using namespace std;

double x,y,z;

extern double cubeandmult(double, double); // declaration of 
                                         // external function

  int main()
      {cout<<"enter x\n";    cin>>x;
	cout<<"enter y\n";   cin>>y;
        z=cubeandmult(x,y);
	cout<<"x^3y=  "<<z<<endl;
	return(0);
      }
