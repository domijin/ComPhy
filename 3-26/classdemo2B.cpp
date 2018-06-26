// static members in classes
//-------->Buisinesses and revenues example
#include <iostream>
using namespace std;

class Dummy {
  public:
    static int n;
    Dummy () { n++; };//constructor increments the static variable
    ~Dummy () { n--; };//destructor decrements the static variable
};

int Dummy::n=0;

int main () {
  Dummy a;//one object exists
  Dummy b[5];//six objects exist
  Dummy * c = new Dummy;//seven objects exist
  cout << a.n << endl;
  delete c;//six objects exist
  cout << Dummy::n << endl;//note: would not work if static int n was private
  cin.get();
  return 0;
}
