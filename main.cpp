
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include "leetcode/editor/cn/include/headers.h"
#include <ctime>
#include <sstream>

using namespace std;

//输出二进制
void BinaryBitset(int n) {
    cout << bitset<8>(n) << endl;
}

//class A {
//public:
//
//    virtual void print(){
//        cout << "aaaaaaa"<< endl;
//    }
//}; // 1+4 =补齐= 8
//
//class B : public A //如果还是虚继承，那么需要再加1个虚指针空间，最多就2个虚指//针空间。
//{
//public:
//    B(){ print(); }
//
//    void print() override{
//        cout << "bbbbbbbb"<< endl;
//    }
//
//};
//
//int main() {
//    A a;
//    B b;
//
//    return 0;
//}


#include <iostream>

using namespace std;

class A {
public:
    //A() { cout << "A()" << endl; }
    A(int a) { cout << "A(int " << a << ")" << endl; }
};

class B {
public:
    B() : a(1) {
        //b = A(2);
    }
    A a;
    A b;
};


int main() {
    B b;
    return 0;
}
