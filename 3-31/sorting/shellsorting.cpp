/***************************************************************************
This program sort data by using a method called the shell short method.The 
shell sort repeatedly compares elements that are a certain distance away
from each other (d represents this distance). The value of d starts out 
as half the input size and is halved after each pass through the array. 
The elements are compared and swapped when needed.  The equation 
d = (N + 1) / 2  is used. 
***************************************************************************/

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

/******The random number genterator**********/
  int a[N];
  int i;
 
  srand(time(NULL));
  
  for(i=0; i<N; i++)
    {
      a[i]=rand()%101;
    }
/**********Displaying and Sorting******************************/
  
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
This function perfoms an ascending-order shell method on array.
The parameter N holds the number of elements in the array.
*******************************************************/
void sortArray(int a[],int N)
{
 
int i, j, increment,temp,number_of_elements=N;
     for(increment = number_of_elements/2;increment > 0; increment /= 2)
       {
	 for(i = increment; i<number_of_elements; i++)
	   {
	     temp = a[i];
	  for(j = i; j >= increment ;j-=increment)
	    {
	      if(temp < a[j-increment])
		 {
		   a[j] = a[j-increment];
		 }
	       else
		 {
		   break;
		  }
	     }
	     a[j] = temp;
	   }
       }
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
