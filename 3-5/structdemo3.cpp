/*************
   March 1, 2014
Demonstration of the simple use of a struct

Note that the definition of the struct must precede the definition of
the function that is going to use that struct. Try reversing them and
note that it won't compile.
*****************/

#include<iostream>
using namespace std;
/********* Define struct data type *****/
struct  paer{
double x;
int n;
};

/******* Define function that uses the struct data type ****/
double raise(paer bpair)
{double prod=1.;
for(int k=0;k<bpair.n;++k){
prod=prod*bpair.x;}
return(prod);}

int main(){
  paer apair={4.5,2};

  paer bpair;
  
  bpair.x=3;
  bpair.n=3;


cout<<raise(apair)<<endl;
cout<<raise(bpair)<<endl;

  return(0);}


