/********************************************************************
This program sort data by using a method called the quick sort. 
Quicksort is regarded as one of the efficient sorting algorithm.
The main idea behind quicksort is to divide the original problem
into subproblems that can be solved more easily and quickly. 
A quicksort is best understood with 3 terms: Pivot, Partition 
and recursion.
**********************************************************************/
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int Partition(int [], int , int);
void sortArray(int[],int,int);
void showArray(int[],int);


int main ()
{
/********** Specifying the number of radom number generated***********/
  int  N;
  cout<<"Please specify the number of random numbers generated: "<<endl;
  cin >> N ; 
  cout<<endl;
  N=N-1;
/******The random number genterator***********/
  int a[N],beg,end;
  
 
  srand(time(NULL));
  
  for(int i=0; i<=N; i++)
    {
      a[i]=rand()%101;
    }
  
  beg=0;
  end=N;
/**********Displaying and Sorting******************************/
  
  //Display the values
  cout<<"The unsorted values are:"<<endl;
  showArray(a,N);
  cout<<endl<<endl;
  //Sort the values
  sortArray(a,beg,end);
  //Display sort values
  cout<<"The sorted values are:"<<endl;
  showArray(a,N); 
  cout<<endl;
 
 return 0; 
}
/***********************************************************************
The partition function.
Pivot:
A pivot can be any number from the input array i.e it can be first,
middle or last. There is no such restriction for choosing the pivot value.

Partition:
This pivot value is used to create 2 sub-arrays(may be of non-equal size)
from the original array where the left array has numbers less than the pivot
value and the right sub-array has numbers greater than the pivot value. 
Values equal to the pivot can stay in any part of the array.

How partition works:
There are two indices i and j and at the beginning of the partition
algorithm where i points to the first element and j points to the last one.
Then i moves forward until an element with value greater or equal to the
pivot is found. Similarly j moves backward, until an element with value 
lesser or equal to the pivot is found. Once the elements found and i ≤ j
then they are swapped. i is incremented to next position (i + 1) and 
j is decremented to the previous one (j - 1). The partition algorithm 
stops when i becomes greater than j.

*************************************************************************/

int Partition(int a[], int beg, int end)  //Funtion to find pivot point
{
int p=beg, pivot=a[beg];

for(int i=beg+1;i<=end;i++)
{
if(pivot>a[i])
{
a[p]=a[i];
a[i]=a[p+1];
a[p+1]=pivot;

p=p+1;
}
}
return p;
}


/************************************************************
Definition of the fuction sortArray
This function perfoms an ascending-order quicksort.cpp on array.

Recursion:
Once partition is done then recursively sort the new sub-arrays 
till all the elements are sorted.

*******************************************************/
// The quicksort recursive function
void sortArray(int a[], int beg, int end)
{
    if ( beg < end )
    {
      int j = Partition(a, beg, end);    //calling Procedure to Find Pivot  
      sortArray(a, beg, j-1);       //calls itself(Recursion)
      sortArray(a, j+1, end);      //calls itself(Recursion)
    }                          //(Divides the list into two Sub list)
}  

/*************************************************************
Definition of function showArray
This funtion displays the contents of the array. 
The parameter N holds the number of elements in the array.
*************************************************************/
void showArray(int a[], int N)
{
  

    for ( int i = 0; i <=N; i++ )
      {
	cout << a[i] << " ";
      }
}

//Jackie Reser
