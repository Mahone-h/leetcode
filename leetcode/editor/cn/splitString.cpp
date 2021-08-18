//
// Created by Mahone on 2021/8/18.
//
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(string str, char del) {
    stringstream ss(str);
    string temp;
    vector<string> ret;
    while (getline(ss, temp, del)) {
        ret.push_back(temp);
    }
    return ret;
}
int main()
{
    string str_cin("one#two#three");
    vector<string> res= split(str_cin, '#');
    for (auto c : res)
        cout << c << endl;
    return 0;
}
