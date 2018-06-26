/*************
   March 1, 2014
Demonstration of the simple use of a struct
The idea is that the struct contains a double x and an int n.
The action of a function "raise" is to multiply the double x
by itself n times.


compile with g++ structdemo1.cpp
run with a.out


Note that the definition of the struct must precede the definition
of the function that is going to use that struct. Try reversing them
and note that it won't compile.
*****************/

#include<iostream>
using namespace std;
/********* Define struct data type *****/
struct  paer{//This defines the struct type "paer."
//I couldn't use "pair" since that already had a meaning in C
double x;
int n;
};

/******* Define function that uses the struct data type 
What's going on here is that we define a function "raise" 
that takes as input "bpair" which is of datatype "par".
In the function cll, "m" is a placeholder. Below we will
use actual data of type "paer." This is the variable "apair."
****/
double raise(paer bpair)
{double prod=1.;
for(int k=0;k<bpair.n;++k){
prod=prod*bpair.x;}
 return(prod);}//returns x^n

int main(){
paer apair;  //defines "apair" to be a struct of the paer type.
apair.x=4.5;
apair.n=2;
 cout<<raise(apair)<<endl;//function is called with only struct argument
  return(0);}


