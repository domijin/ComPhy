#include<iostream>
#include<complex>
using namespace std;

int main(){
    complex<double> z (1.0,1.0);
    complex<double> x (2.0,2.0);
    complex<double> y;
    cout << "Our Complex number is " << real(z) << " + " << imag(z) << "i" << endl;
    cout << "The polar form of " << z;
    cout << " is " << abs(z) << "*e^i*" << arg(z) << " \n";
    cout << "The complex conjugate is "<< conj(z) <<  endl;
    y=z*x+z;
    cout << "y = z*x + z = " << y << endl;
    cin.get();
    return 0; 
}
    
