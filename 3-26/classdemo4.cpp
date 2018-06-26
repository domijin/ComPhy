// pointer to classes example
#include <iostream>
using namespace std;

class Rectangle {
  int width, height;
public://constructor with member initialization
  Rectangle(int x, int y) : width(x), height(y) {}
  int area() { return width * height; }
};


int main() {
  Rectangle a (3, 4);
  Rectangle * b, * c, * d;
  b = &a;
  c = new Rectangle (5, 6);
  d = new Rectangle[2] { {2,5}, {3,6} };
  cout << "a's area: " << a.area() << '\n';
  cout << "*b's area: " << (*b).area() << '\n';
  cout << "*c's area: " << c->area() << '\n';
  cout << "d[0]'s area:" << d[0].area() << '\n';
  cout << "d[1]'s area:" << d[1].area() << '\n';       
  delete c;
  delete[] d;
  cin.get();
  return 0;
}	
