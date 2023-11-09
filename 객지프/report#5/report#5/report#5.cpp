#include <iostream>
using namespace std;

class Shape {
private:
	string name;
	float area;
public:
	string getName() { return name; };
	float getArea() { return area; };
	void setArea(float n) { area = n; };
	Shape(string n);
};

Shape::Shape(string n) {
	name = n;
}

class Circle : public Shape {
private: 
	int radius;
public:
	Circle(string n, int r);

};
Circle::Circle(string n, int r) : Shape(n){
	radius = r;
	setArea(3.14 * r * r);
}

class Rectangle : public Shape {
private:
	int width, height;
public:
	Rectangle(string n, int w, int h);
};
Rectangle::Rectangle(string n, int w, int h) :Shape(n) {
	width = w;
	height = h;
	setArea(w * h);
}

class Triangle : public Shape {
private:
	int a,b,c,p;
public:
	Triangle(string n, int a, int b, int c);
};
Triangle::Triangle(string n, int a, int b, int c) : Shape(n) {
	this->a = a;
	this->b = b;
	this->c = c;
	p = (a + b + c) / 2;
	setArea(sqrt(p*(p-a)*(p-b)*(p-c)));


}


int main() {
	Shape* s[3];
	s[0] = new Circle("Circle", 20);
	s[1] = new Rectangle("Rectangle", 10, 20);
	s[2] = new Triangle("Triangle", 5, 6, 7);
	for (auto& e : s)
		cout << "Name: " << e->getName() << "\tArea: " << e->getArea() << endl;
	for (auto& e : s)
		delete e;
}