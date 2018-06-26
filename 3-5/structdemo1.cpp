/*************
   March 1, 2014
Demonstration of the simple use of a struct

Note that the definition of the struct must precede the definition
of the function that is going to use that struct. Try reversing them
and note that it won't compile.
*****************/

#include<iostream>
using namespace std;
/********* Define struct data type *****/
struct  paer{
double x;
int n;
};

/******* Define function that uses the struct data type ****/
double raise(paer bpair)//compare: double f(int m) in which m is
// placeholder
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


