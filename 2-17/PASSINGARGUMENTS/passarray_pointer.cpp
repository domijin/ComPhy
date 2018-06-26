/*************************************
This program was written on Jan 28 to illustrate, in class,
how to pass arrays into functions.

Example references:
http://www.cplusplus.com/doc/tutorial/arrays/
http://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm

**********************************************************/



#include<iostream>
using namespace std;


/******* the "shift" function ***********/
void shift(int *p){
  for (int k=0;k<5;++k)
    {p[k]=p[k]+5;}
    }

 /******* the main function ***********/
int main()
{
  int p[5]={1,2,3,4,5};
  
  shift(p);

  cout<<p[0]<<"  "<<p[1]<<"  "<<p[2]<<"  "<<p[3]<<"  "<<p[4]<<endl;

  return 0;
}
