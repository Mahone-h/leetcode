//
// Created by Mahone on 2021/8/18.
//
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> split(const string str,const char &del) {
    stringstream ss(str);
    string temp;
    vector<string> ret;
    while (getline(ss, temp, del)) {
        ret.push_back(temp);
    }
    return ret;
}

//第二
vector<string> splitString1(const string &source,  const char &split) {
    vector<string> v;
    string::size_type pos1, pos2;
    pos2 = source.find(split);
    pos1 = 0;
    int spSize = 1;
    while (string::npos != pos2) {
        v.emplace_back(source.substr(pos1, pos2 - pos1));
        pos1 = pos2 + spSize;
        pos2 = source.find(split, pos1);
    }
    if (pos1 != source.length())
        v.push_back(source.substr(pos1));
}

int main()
{
    string str_cin("one#two#three\none#two#three");
    vector<string> res= split(str_cin, '#');
    for (auto c : res)
        cout << c << endl;
    return 0;
}
