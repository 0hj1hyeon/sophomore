#include <iostream>
using namespace std;

template<class T>
T larger(T a, T b) {
    
    if (a > b) return a;
    else return b;
}
//string larger(Circle a, Circle b) {
  //  return a.getRadius() < b.getRadius() ? b.getName() : a.getName();
//}

class Circle {
    string name;
    int radius;
public:
    friend ostream& operator<<(ostream& os, Circle c);
    Circle(string name, int radius) {
        this->name = name;
        this->radius = radius;
    };
    bool operator>(Circle & c) {
        cout << this->radius<<"h" <<c.radius<< endl;
        return this->radius > c.radius;
        
    }
  
    int getRadius() {
        return radius;
    }
    string getName() {
        return name;
    }
};
ostream& operator<<(ostream& os, Circle c) {
    os << c.name;
    return os;
}

int main()
{
    cout << larger<int>(5,6) << endl;
    cout << larger<char>('A','B') << endl;

    cout << larger<float>(5.6,3.2) << endl;
    cout << larger<string>("Hello","Happy") << endl;

    Circle waffle("waffle", 10), pizza("Pizza", 20);
    cout << larger(waffle, pizza) << endl;
    return 0;
}

