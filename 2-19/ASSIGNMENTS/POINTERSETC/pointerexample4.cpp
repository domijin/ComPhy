/***************
POINTEREXAMPLE 
Here the operator & is demonstrated. This operator
extracts the address of a variable.
 *********/

#include<iostream>
using namespace std;

int main()
{
  int * p; //p is declared as a pointer
  int a;
  p=&a;//The address of a is assigned as the address
       //of p.
  a=15;//This makes 15 the value stored at p.
  cout<<"The value of p is "<<p<<endl;
  cout<<"The value stored at p is "<<*p<<endl;
  /****** NOTE THE FOLLOWING *****/ 
  a=23;
  cout<<"\n NOW \n"<<"The value of p is "<<p<<endl;
  cout<<"The value stored at p is "<<*p<<endl;

   return 0;
}
