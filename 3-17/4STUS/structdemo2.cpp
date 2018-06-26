/*************
   March 1, 2014
Demonstration of the simple use of a struct
Note that the definition of the struct must precede the definition
of the function that is going to use that struct. Try reversing them
and note that it won't compile.

The difference between this and structdemo1.cpp is that here,
we create "apair" as an integral part of defining the struct
"paer".

*****************/
#include<iostream>
using namespace std;

/********* Define struct data type *****/
struct  paer{
double x;
int n;
} apair ;  //apair is defined immediately to be of paer type 
/******* Define function that uses the struct data type ****/
double raise(paer bpair)
{double prod=1.;
for(int k=0;k<bpair.n;++k){
prod=prod*bpair.x;}
return(prod);}


int main(){
apair.x=4.5;
apair.n=2;

cout<<raise(apair)<<endl;

  return(0);}


