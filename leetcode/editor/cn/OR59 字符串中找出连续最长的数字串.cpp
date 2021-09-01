#include <string>
#include  <iostream>

using namespace std;


void main() {
    string test;
    cin >> test;
    string tmp;
    string res;
    for (char &c:test) {
        if (c >= '0' && c <= '9') {
            tmp += c;
        } else if (!tmp.empty()) {
            if (tmp.size() >= res.size()) {
                res = tmp;
            }
            tmp.clear();
        }
    }
    if (tmp.size() >= res.size()) {
        res = tmp;
    }
    cout << res<< endl;


}