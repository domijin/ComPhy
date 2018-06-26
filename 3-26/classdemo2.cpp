/******************
This program is to demonstrate the use of constructors
******************/
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public://set_values function has been removed
    Rectangle ();//prototype for the default constructor
    Rectangle (int,int);//prototype for the overloaded constuctor
    int area (void) {return (width*height);}
};

Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle rectb;
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  return 0;
}
