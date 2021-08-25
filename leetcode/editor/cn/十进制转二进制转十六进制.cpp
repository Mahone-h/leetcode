//
// Created by Mahone on 2021/8/20.
//

#include <string>
#include <cstring>

#include <algorithm>

using namespace std;

string int_to_radix(int n, int radix) {
    string res;
    while (n) {

        int t = n % radix;
        if (t >= 0 && t <= 9) res += t + '0';
        else res += t - 10 + 'a';
        n /= radix;
    }
    reverse(res.begin(), res.end());
    return res;
}


int radix_to_int(string s, int radix) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        char t = s[i];
        if (t >= '0' && t <= '9') ans = ans * radix + t - '0';
        else ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}