#include "mystring2.h"
//#include "mystring2.hpp"
#include <iostream>

using namespace std;

int main() {
    mystring a("are you sure?"), b('a'), c, d;
    char ch;

    if (a != b) {
        cout << "字符串a和字符串b不相等！" << endl;
    } else {
        cout << "字符串a和字符串b相等！" << endl;
    }

    d = a;
    cout << "请输入字符串c的值：";
    cin >> c;

    cout << "a=" << a << endl;
    cout << b.compare(c) << endl;
    cout << "c=" << c << endl;
    cout << "d=" << d << endl;
    cout << c[1] << endl;

    return 0;
}
