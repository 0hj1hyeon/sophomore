#include <iostream>
using namespace std;


class  T {
    static int a;
    int b;

public:
    T() { a++; }
    int f(){ return a;}
    int g() { return b;}
    static int h() { return a;}
   // static int s() { return b;} static 함수에 리턴값은 static이 아니므로 오류
}; // 1번

int T::a = 0;
class ArrayUtility {


public:
    void static intToDouble(int x[], double y[], int num) {
        for (int i = 0; i < num; i++)
            y[i] = (double)x[i];
    }
    void static doubleToInt(double z[], int x[], int num) {
        for (int i = 0; i < num; i++)
            x[i] = (int)z[i];
    }

};

int main()
{
    /*int count;
    T t1, t2;
    T t3[5];
    T* p = new T[10];
    count = t1.f() + T::h() + t3[0].f() + (p + 3)->f();
    cout << count << endl;
    return 0;*/ // 2번

    int x[] = { 1,2,3,4,5 };
    double y[5];
    double z[] = { 9.9,8.8,7.7,6.6,5,6 };
    ArrayUtility::intToDouble(x, y, 5); // x의 배열 요소를 실수로 변환하여 배열 y에 저장
    for (int i = 0; i < 5; i++) 
        cout << y[i] << "";
    cout << endl;
   
    ArrayUtility::doubleToInt(z, x, 5);

    for (int i = 0; i < 5; i++) 
        cout << x[i] << "";
    cout << endl;
    
}
