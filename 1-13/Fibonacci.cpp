/****************************
 Fibonacci Program 
             by Domi Jin
 ***************************/
#include<iostream>
using namespace std;
double ratio;
float x,y,temp;//Float as they are
int n;
int main()
{
  cout<<"Enter a float"<<endl;
  cin>>x;
  cout<<"Enter another float"<<endl;
  cin>>y;
  cout<<"Enter an integer"<<endl;//Number of terms to output
  cin>>n;
  cout<<x<<endl<<y<<endl;
  for (int i=0;i<n;i++)//Do n times and output n terms
    {
      temp=x+y;//New term
      cout<<temp<<"\n";
      x=y;//Switch y to x
      y=temp;//Switch new term to y
    }
  cout<<"Last Ratio:\t"<<y/x<<endl;//Calculate the ratio of the last two terms outputed.
}
