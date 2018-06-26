// class templates
//------------>Use with <complex>  
#include <iostream>
using namespace std;

template <class T>//template for a class with arbitrary type T
class mypair {
    T a, b;// declares two private variables or arbitrary type
  public:
  mypair (T first, T second):a(first),b(second) {}//constructor
  //  {a=first; b=second;}
    T getmax ();//prototype for function with arbitrary return type T
};

template <class T>//function template
T mypair<T>::getmax ()
{
  T retval;
  retval = a>b? a : b;
  return retval;
}

int main () {
  mypair <double> myobject (100, 75);//declaration of object with parameters of type int 
  cout << myobject.getmax()<<endl;
  return 0;
}
