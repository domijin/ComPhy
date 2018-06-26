#include<iostream>
using namespace std;

void Swap(int *u, int *v)
{
  int *a,*b;
  *b=*v; *a=*u;
  *u=*b; *v=*a;
}
 
int main()
{ 
  int x=3,y=4;

  cout << "Before swap, x,y = " << x<<"  "<<y << endl;
  Swap(&x,&y);
  cout << "Before swap, x,y = " << x<<"  "<<y << endl;

  return 0;
}
