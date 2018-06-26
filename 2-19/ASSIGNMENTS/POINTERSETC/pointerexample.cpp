/***************
Example reference:
http://www.cplusplus.com/doc/tutorial/pointers/

 *********/

#include<iostream>
using namespace std;

int main()
{
  int a=15,b;
  int * p; //p is declared as a pointer
  
  p=&a;





  
cout<<"p= "<<p<<endl;  
  cout<<"The value at p  is "<<*p<<endl;
  /* *p=b;
    cout<<"p= "<<p<<endl;  
  cout<<"Now the value of at p is "<<b<<endl;

  */

  //cout<<"The value of aa is "<<&a<<endl;
  return 0;
}
