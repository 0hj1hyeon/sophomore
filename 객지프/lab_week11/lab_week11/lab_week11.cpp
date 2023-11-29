#include <iostream>
using namespace std;

class A {
    int a;
public:
    A(int a) { cout << "생성자 A: " << a << endl; }
    ~A() { cout << "소멸자 A" << endl; }


};
class B:public A {
    int b;
public:
    B(int a, int b) : A(a){cout << "생성자 B: " << b << endl; }
    ~B() { cout << "소멸자 B" << endl; }
};

class C :public B {
    int c;
public:
    C(int a = 0, int b = 0, int c = 0):B(a,b) {cout << "생성자 C: " << c << endl; }
    ~C() { cout << "소멸자 C" << endl; }
};


int main()
{
   // A a;
    //B b;
    //C c;
    C(10, 20, 30);
    return 0;
}

