/***************
POINTEREXAMPLE 

This program will generate a segmentation
fault, since there is no value of a to be 
stored at memory location p.
 *********/

#include<iostream>
using namespace std;

int main()
{

  int * p; //p is declared as a pointer
  int a;
  *p=a;//the value of integer a is put as the value pointed
       //to by p

   return 0;
}
