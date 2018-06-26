/********************
Overloadable operators

+    -    *    /    =    <    >    +=   -=   *=   /=   <<   >>
<<=  >>=  ==   !=   <=   >=   ++   --   %    &    ^    !    |
~    &=   ^=   |=   &&   ||   %=   []   ()   ,    ->*  ->   new 
delete    new[]     delete[]
**********************/
#include <iostream>
using namespace std;

class CVector {
  public:
    int x,y;
    CVector () {};//default constructor
    CVector (int a,int b) : x(a), y(b) {}//overloaded constructor
    CVector operator + (const CVector&);//this is a prototype of a function of return type Cvector that takes an argument CVector
};

CVector CVector::operator+ (const CVector& param) {
  CVector temp;
  temp.x = x + param.x; //adds the x of the object to the x of the object passed to the function and stores it in the x of the temp object
  temp.y = y + param.y;
  return temp;
}

int main () {
  CVector A (3,1);//declares vector A=(3,1)
  CVector B (1,2);//declares vector B=()
  CVector result[2];
  result[0] = A + B;
  result[1] = A.operator+(B);
  cout << result[0].x << "," << result[0].y << endl;
  cout << result[1].x << "," << result[1].y << endl;
  cin.get();
  return 0;
}
