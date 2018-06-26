/************************************
This program was written on April 20, 2014
to demonstrate to 6352 students the use of 
the complex class in C++.
**************************************/
#include<iostream>
#include<math.h>
#include<complex>// THIS DEFINES THE COMPLEX CLASS
using namespace std;

typedef complex<double> dcmplx;//With this type def, we reduce 
/*****************
By defining "dcmplx" this way, we reduce the typing.
We no longer have to use "complex<double>" We can 
simply type "dcmplx"
******************/

int main(void){

  dcmplx a(5.,6.); //define a and initialize it as 5+6i
  complex<double> b(0,1); // This is to demonstrate the standard syntax
  dcmplx c;

  cout<<"a= "<<a<<"= "<<real(a)<<"+"<<imag(a)<<"i\n";
dcmplx five(5.,0);
cout<<"5a= "<<five*a<<"= "<<5*real(a)<<"+"<<5*imag(a)<<"i\n";
cout<<"a+5= "<<five+a<<"= "<<5+real(a)<<"+"<<imag(a)<<"i\n";


  cout<<"b= "<<b<<"= "<<real(b)<<"+"<<imag(b)<<"i\n"<<endl;
  cout<<"a+b= "<<a+b<<"= "<<real(a+b)<<"+"<<imag(a+b)<<"i\n"<<endl;
  cout<<"a*b= "<<a*b<<"= "<<real(a*b)<<"+"<<imag(a*b)<<"i\n"<<endl;
  cout<<"conj(a)= "<<conj(a)<<"= "<<real(conj(a))<<""<<imag(conj(a))<<"i\n"<<endl;
  dcmplx sqt=sqrt(a);
  cout<<"sqrt(a)= "<<sqt<<"= "<<real(sqt)<<"+"<<imag(sqt)<<"i\n\n";
  dcmplx d(0,4.*atan(1.)/3);
  //cout<<endl<<endl;
  cout<<"d= "<<d<<"= "<<real(d)<<"+"<<imag(d)<<"i\n";
  dcmplx f=cosh(d);
  cout<<"cosh(d)= "<<f<<"= "<<real(f)<<"+"<<imag(f)<<"i\n";
return(0);}
