// lab_week11_2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;


class A {
	int a;
public:
	A() {
		a = 0;
		cout << "생성자 A: " << a << endl;
	}
	virtual ~A() {
		cout << "소멸자 A" << endl;
	}
	void f() {
		cout << " f() in A" << endl;
	}
	virtual void v() {
		cout << " v() in A" << endl;
	}
};

class B : public A {
	int b;
public:
	B() {
		b = 0;
		cout << "생성자 B: " << b << endl;
	}
	~B() {
		cout << "소멸자 B" << endl;
	}
	void f() {
		cout << " f() in B" << endl;
	}
	void v() {
		cout << " v() in B" << endl;
	}
};

class C : public B {
	int c;
public:
	C() {
		c = 0;
		cout << "생성자 C: " << c << endl;
	}
	~C() {
		cout << "소멸자 C" << endl;
	}
	void f() {
		cout << " f() in C" << endl;
	}
	void v() {
		cout << " v() in C" << endl;
	}

};
int main() {
	A a;
	B b;
	C c;
	A* pa;
	C* pc;

	cout << "===================================" << endl;
	pa = &b;
	pa->f(); // f() in A
	pa->v(); // v() in B

	cout << "===================================" << endl;

	pc = new C();
	pa = pc;
	pa->f(); // f() in A 
	pa->v(); // v() in C
	// virtual이 아니면 선언된 포인터타입 기준 virtual이면 객체 타입 기준
	cout << "===================================" << endl;
	delete pa;
	cout << "===================================" << endl;

}