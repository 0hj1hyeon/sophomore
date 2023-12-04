#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    using namespace std;
    ofstream os("dict.txt");
    if (!os) {
        cerr << "파일 오픈에 실패" << endl;
        exit(1);

    }
    
    ifstream is("test.txt");
    if (!is) {
        cerr << "파일 오픈에 실패" << endl;
        exit(1);

    }
    vector<string> vc;
    string a;
    while (is>>a) {
        vc.push_back(a);
    
    }
    sort(vc.begin(), vc.end(), [](string s1, string s2) {return  s1 < s2; });

    for (auto a : vc) {
        cout << a << endl;
        os << a << endl;
    
    
    }
    return 0;
}

