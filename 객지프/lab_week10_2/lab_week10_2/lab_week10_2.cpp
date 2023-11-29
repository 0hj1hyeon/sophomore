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
    /*Complex& operator++() {
        this->re++;
        this->im++;
        return *this;
    }
    Complex& operator++(int i) {
        Complex temp = *this;
        this->re++;
        this->im++;
        return temp;
    }*/
    friend Complex& operator++(Complex& c);
    friend Complex& operator++(Complex& c, int i);
    friend ostream& operator<<(ostream& os, const Complex& c);
     

};
ostream& operator<<(ostream& os, const Complex& c) {
    os << c.re << "+" << c.im << "i" << endl;
    return os;
}
Complex& operator++(Complex& c) {
    c.re++;
    c.im++;
    return c;
}

Complex& operator++(Complex& c, int i) {
    Complex temp = c;
    c.re++;
    c.im++;
    return temp;
}
int main() {
    Complex c1(1, 2), c2;
    cout << c1 << endl;
    cout << c2 << endl;

    c2 = ++c1;
    cout << "\nAfter prefix++: " << endl;
    cout << c1 << c2 << endl;
    c2 = c1++;
    cout << "\nAfter prefix++: " << endl;
    cout << c1 << c2 << endl;
    return 0;
}