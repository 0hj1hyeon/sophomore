#include <iostream>
using namespace std;

class Complex {
    double re, im;

public:
    Complex(double r = 0.0, double i = 0.0) {
        re = r; im = i;
    }
    void show() {
        cout << re << " + " << im << " i " << endl;
    }
    /*Complex& operator+(const Complex& c1) {
        Complex c;
        c.re = this->re + c1.re;
        c.im = this->im + c1.im;
        return c;
       
    }
  
    Complex& operator+=(const Complex& c1) {

       this->re += c1.re;
       this->im += c1.im;
       return *this;
    }*/
    friend Complex& operator+(Complex& c1, Complex& c2);
    friend Complex& operator+=(Complex& c1, Complex& c2);

};
Complex& operator+(Complex& c1, Complex& c2) {
    Complex temp;
    temp.re = c1.re + c2.re;
    temp.im = c1.im + c2.im;
    return temp;
}

Complex& operator+=(Complex& c1, Complex& c2) {
    c1.re = c1.re + c2.re;
    c1.im = c1.im + c2.im;
    return c1;
}

int main() {
    Complex c1(1, 2), c2(3, 4), c3;
    c3 = c1 + c2;
    cout << "\nAfter+: " << endl;
    c3.show();

    c3 += c1;
    cout << "\nAfter+: " << endl;
    c3.show();

    return 0;
  

}

