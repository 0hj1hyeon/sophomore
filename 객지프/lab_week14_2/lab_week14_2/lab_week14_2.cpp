#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

bool is_div4(int n) {
    return (n % 4 == 0);
}
int main()
{
    vector<int>vc = {1,7,4,9,4,8,12,10,20};
    int count = count_if(vc.begin(), vc.end(), is_div4);
    cout << count << endl;
    
}
