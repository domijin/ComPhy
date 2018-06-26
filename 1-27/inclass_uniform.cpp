/********************************************************
       For PHYSCS 6352  Program written Jan 25 for     
    inclass demo. You have an infinite pile of cards
    numbered 0 to 9. You choose N cards at random. 
    The program prints out the cards, and prints out 
    the average numerical value.
 *******************************************************/

#include<iostream>
#include<stdlib.h>   //needed for RAND
#include<time.h>     //this is needed for true randomness

using namespace std;

int main()
{
  int x,N;
  int p[2]={0,0};  //p[0] is no. of low cards; p[1] of high cards

   cout<<" How many times do you want to run the experiment?\n";
   cin>>N;
   srand (time(NULL));            //so that "rand" gives a true random variable



   for(int k=0;k<N;k++)   // This is the loop that does all the work.
   {x=14.*rand()/RAND_MAX;
     if(x<=4){++p[0];}// condition for low cards
     if(x>4){++p[1];}// condition for high
   }


 cout<<"\n";

 cout<<"number of low cards= "<<p[0]<<" "<<"number of high cards= "<<p[1]<<"\n ";
 double average=(p[0]*2.+p[1]*7.)/(1.*N);
 cout<<"Averge= "<<average<<endl;
 
  return(0);
}
