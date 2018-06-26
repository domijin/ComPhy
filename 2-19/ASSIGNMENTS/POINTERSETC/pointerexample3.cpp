/***************
POINTEREXAMPLE 
This program will run since a value is established
for a that can be pointed to by p.
 *********/

#include<iostream>
using namespace std;

int main()
{

  int * p; //p is declared as a pointer
  int a=15;
  *p=a;//the value 15 is put in the memory 
        //location p
   return 0;
}
