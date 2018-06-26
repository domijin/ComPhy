/*************************************************************************
This program sort data straight-forward by using a method called the bubble 
sort. Bubble sort works by comparing each element with its neighbor and
swapping them if they are not in the desired order. The bubble sort is 
inefficent for sorting larg arrays because repeated data are often required
to place a single item in its corect position.
 *************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void sortArray(int[],int);
void showArray(int[],int);


int main ()
{
/********** Specifying the number of radom number generated***********/
  int  N;
  cout<<"Please specify the number of random numbers generated: "<<endl;
  cin >> N ; 
  cout<<endl;

/******The random number genterator and strate foward sorting********/
  int a[N];
  int i;
 
  srand(time(NULL));
  
  for(i=0; i<N; i++)
    {
      a[i]=rand()%101;
    }
/**********Displaying and sorting******************************/
  
  //Display the values
  cout<<"The unsorted values are:\n";
  showArray(a,N);
  //Sort the values
  sortArray(a,N);
  //Display sort values
    cout<<"The sorted values are:\n";
  showArray(a,N); 
 
 return 0; 
}
/************************************************************
Definition of the fuction sortArray
This function perfoms an ascending-order bubble sort on array.
The parameter N holds the number of elements in the array.
*******************************************************/
void sortArray(int a[],int N)
{
   double temp;
  bool swap;
 do //bubble sorting method used to sort a[i] out in a incressing order
{
swap=false;
for(int i=0; i<N ;i++)
  { 
  if(a[i]>a[i+1])
    {
       temp=a[i];
       a[i]=a[i+1];
       a[i+1]=temp;
       swap=true;  
     } 
  }
}while(swap);
}
/*************************************************************
Definition of function showArray
This funtion displays the contents of the array. 
The parameter N holds the number of elements in the array.
*************************************************************/
void showArray(int a[],int N)
{ 
   for(int i=0; i<N; i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

//Jackie Reser
