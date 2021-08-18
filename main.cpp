
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include "leetcode/editor/cn/include/headers.h"
#include <ctime>

using namespace std;

void BinaryBitset(int n) {
    cout << bitset<8>(n) << endl;
}




class A {
public:
    static int aa;

    virtual void foo() {
        cout << "A::foo() is called" << endl;
    }

    virtual void print() = 0;
};
void A::print()
{
    cout << "I'am pureVirtualFunc" << endl;
}
int A::aa = 5;
class B : public A {
public:
    void foo() override {
        cout << "B::foo() is called" << endl;
    }
    void print(){
        A::print();
        cout << "I'am B" << endl;
    };
};

class Point {
public:
    static void init() {
        //a=0;//非静态成员引用 错误
        //b=0;//非静态成员引用 错误
        c = 0;
    }

    void output() {
        init();
        c = 200;
    }

private:
    int a;
    int b;
    static int c;
};

int Point::c = 100; //静态成员变量必须初始化



void test(int *nums) {
    cout << sizeof(nums) << endl;
}



void fun(int* p)
{
    cout<< "int* p" <<endl;
}
void fun(int p)
{
    cout<< "int p" <<endl;
}
int function(int x)  {
    int flag = 0;
    while(x)  {
        x = x&(x-1);
        flag ++;
    }
    return flag ;
}


void shellSort(vector<int> &arr){
    int len = arr.size();
    for (int gap = len/2; gap >0; gap/=2) {
        for (int i = gap; i < len; ++i) {
            int j = i;
            int cur = arr[i];
            while (j - gap >= 0 && cur < arr[j - gap]) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = cur;
        }
    }
}

int main() {
    //import java.util.*;
    //
    //public class ForTest {
    //public static int main(String[] args) {
    //        Scanner sc = new Scanner(System.in);
    //        String input = sc.nextLine();
    //        if (!input.contains("o")) {
    //            System.out.println(input.length());
    //            return 0;
    //        }
    //        String[] split = input.split("o");
    //        if(split.length==0){
    //            Boolean isEven =input.length()%2 ==0;
    //            if (isEven){
    //                System.out.println(input.length());
    //            }else {
    //                System.out.println(input.length()-1);
    //            }
    //            return 0;
    //        }
    //        Boolean isEven = split.length % 2 == 0;
    //        if (isEven) {
    //            List<Integer> lenList = new ArrayList<>();
    //            for (String str : split) {
    //                lenList.add(str.length());
    //            }
    //            Collections.sort(lenList);
    //            int length = 0;
    //            for (int i = 1; i <= lenList.size() - 1; i++) {
    //                length += lenList.get(i);
    //            }
    //            length += lenList.size() - 2;17
    //            System.out.println(length);
    //        } else {
    //            System.out.println(input.length());
    //        }
    //        return 0;
    //    }
    //}

    //fun((char*)nullptr);//语句1
    //fun(nullptr);//语句2
    //fun(NULL);//语句3

    vector<int> tmp = {80, 30, 60, 40, 20, 10, 50, 70};
    shellSort(tmp);
    for (int &a:tmp) {
        cout << a<<" ";
    }

    return 0;

    return 0;
}

