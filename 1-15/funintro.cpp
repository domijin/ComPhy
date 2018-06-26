/*******************************
A small program to demonstrate 
how to use a C++ program
*******************************/
#include<iostream>
using namespace std;

//METHOD I straightforward ----------------

double x,y,z;

double cubeandmult(double u, double v)  // FUNCTION DEFINED
//inline double cubeandmult(double u, double v) //"INLINE"
{double w=u*v;  w=w*u; w=w*u; 
return(w);}

  int main()
      {cout<<"enter x\n";    cin>>x;
	cout<<"enter y\n";   cin>>y;
        z=cubeandmult(x,y);
	cout<<"x^3y=  "<<z<<endl;
	return(0);
      }

//----------------------------------------------

//METHOD Ia: "inline function" same as above, but using
//"inline double cubeandmult(double u, double v)"


//----------------------------------------------------
//METHOD II with "prototype
 
/*
double x,y,z;

double cubeandmult(double , double );   //function "prototype"

  int main()
      {cout<<"enter x\n";    cin>>x;
	cout<<"enter y\n";   cin>>y;
        z=cubeandmult(x,y);
	cout<<"x^3y=  "<<z<<endl;
	return(0);
      }


double cubeandmult(double u, double v)
{double w=u*v;  w=w*u; w=w*u; 
return(w);}
*/


