/********************************************************
 *      For PHYSCS 6352  students                       *
 *  How to use the C rand() function.                   *
 *  To see the effect of the random seed, run the       * 
 *  program with the srand line commented out. Every    *
 *  time you run it you will get the same pattern of    *
 *  0s and 1s. With the srand line in place, you will   *
 *  get  different patterns.                            *
 ******************************************************/
#include<iostream>
#include<stdlib.h>           // needed for rand
#include<time.h>             //this is needed for true randomness

using namespace std;

int k,x;

int main()
{
   srand (time(NULL));            //so that "rand" gives a true random variable

 for(k=0;k<10;k++)
   {
     x=(1.0*rand()/1.0/RAND_MAX)+.5;
    cout<<x<<endl;
   }
  return(0);
}
