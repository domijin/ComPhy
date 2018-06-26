/***************
POINTEREXAMPLE 1

This program will generate a segmentation
fault, since no actual memory location has
been established for p.
 *********/

#include<iostream>
using namespace std;

int main()
{

  int * p; //p is declared as a pointer
  
  *p=15;//the value 15 is put in the memory 
        //location p

   return 0;
}
