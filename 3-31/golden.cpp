/*************************************************************************************
COMPUTATIONAL PHYSICS
Liliana Ruiz Diaz

Golden Section Method: find a minimum
-User inputs initial guesses
-Bracketing the inputs and find the triplets
-Find the new x using using golden ratio method

We will try to find one of the minimums of x^2-5x+4 located at x=2.5
/*************************************************************************************/

#include<math.h>
#include<stdio.h>
#include<iostream>
#include <cmath>  // for abs
using namespace std;

//Define variables
int yes=1, j; //for loop purposes
double ai, ci, a, b, c, fa, fb, fc, fx;
double x, w, v;
float  gr =(3 - sqrt(5))/2;
//float gr=0.1;
float z = (1-2*gr);

//Define function from which minimums are being calculated
extern "C++" double lafunction(double);

//Main program
int main ()
{

cout<<"This is the minimum calculator"<<endl;
cout<<"Input your initial guesses to calculate the position of the minimum"<<endl; 
cin>>ai>>ci;

/****************************Bracketing**********************************/

	while (yes==1){ //User input data lopp
		
		//Ordering data
		if (ai > ci){
			a = ci;
			c = ai;
			}
		else	{
			a = ai;
			c = ci;
			} 



 	//b = 0.98*(a + c)/2; //half point slighty moved to the left	
	b = (c + gr*a)/(1 + gr); //point using golden ratio rule
	
	//Evaluate function at a, b, and c points
	fa = lafunction(a);
	fb = lafunction(b);
	fc = lafunction(c);
	cout<<"Initial  a,  b,  c: "<<a<<"  "<<b<<"  "<<c<<endl; //show the triplets
	cout<<"Initial fa, fb, fc: "<<fa<<" "<<fb<<" "<<fc<<endl;//show the values
		
		//This part of the program decides if the initial guess is good
		if ((fa > fb) && (fc > fb)){
			cout<<("This is a good bracketing")<<endl;
			yes=0;
				}
		else   {
			cout<<"This is not a good bracketing"<<endl; 			
			cout<<"Input your initial guesses"<<endl; 
			cin>>ai>>ci;
			yes=1;
			}

	}
/**************************************************************************/
	
	//Program will keep getting closer to the minimum after a j=# of loops; 
	
	for( j=0; j<10; j++ ) { 

		w = (b-a);   //distance between a and b
		v = (c-b);   //distance between b and c
              
		fa = lafunction(a);
		fb = lafunction(b);
		fc = lafunction(c);


		if (v>w){x = b + z*(c-a) ; //Use golden ratio to the right of x

		fx = lafunction(x); //Evaluate function at x

				if (fb < fx ){
					a=a;
					b=b;
					c=x;
						}
				else   {
					a=b;
					b=x;
					c=c;
	
					}
			}
		else{ x = b - z*(c-a) ;  //Use golden ratio to the right of x

		fx = lafunction(x); //Evaluate function at x
	
				if (fb < fx ){
					a=x;
					b=b;
					c=c;
						}
				else   {
					a=a;
					b=x;
					c=c;
	
					}
			}
		
	cout<<"These are the new a, b, c: "<<a<<" "<<b<<" "<<c<<endl;		
		
	}

printf("Theoretical minimum is at %2.16f  \n",2.5 );
printf("Our minimun is at b %2.16f  \n",b );

	return(0);

}
