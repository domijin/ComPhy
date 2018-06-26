/************************
class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
  ...
} object_names;

Variations
--->Two different types of object declaration
--->Struct anecdote
************************/
#include <iostream>
using namespace std;

class Rectangle {
  private://cannot be accessed outside of Rectangle 
    int width, height;
  public://can be accessesd outside of Rectangle
    void set_values (int,int);//function prototype
    int area() {return width*height;}//inline function
} recta;//Object initialization style 1

//function declared using  the :: scope resolution operator
void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle rectb;
  recta.set_values (3,4);
  rectb.set_values (5,5);
  cout << "area a: " << recta.area() << endl;
  cout << "area b: " << rectb.area() << endl;
  return 0;
}
