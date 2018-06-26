// member initialization
#include <iostream>
using namespace std;

class Circle {
    double radius;
  public://uses member initialization
    Circle(double r) : radius(r) { }//constructor with empty function brackets
    double area() {return radius*radius*3.14159265;}
};

class Cylinder {
    Circle base;//nested class
    double height;
  public:
    Cylinder(double r, double h) : base (r), height(h) {}
    double volume() {return base.area() * height;}
};

int main () {
  Cylinder taco (10,20);

  cout << "taco's volume: " << taco.volume() << '\n';
  return 0;
}	
