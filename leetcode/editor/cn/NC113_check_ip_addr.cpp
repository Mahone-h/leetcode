//
// Created by Mahone on 2022/1/19.
//
#include "include/headers.h"

vector<string> split(const string str, const char &del) {
    stringstream ss(str);
    string temp;
    vector<string> ret;
    while (getline(ss, temp, del)) {
        ret.push_back(temp);
    }
    return ret;
}

/***
 * 多了首位'0'
    超过0-255范围
    出现 ..
 * @param ip
 * @return
 */
bool if_ipv4(string ip) {
    if (ip.find('.') == ip.npos || ip.size() < 7 || ip.size() > 15) return false;
    vector<string> str = split(ip, '.');
    if (str.size() != 4) return false;
    for (int i = 0; i < str.size(); ++i) {
        if ((str[i].size() > 1 && str[i][0] == '0') || str[i].size() > 4 || str[i].empty()) return false;
        for (int j = 0; j < str[i].size(); ++j) {
            if (str[i][j] < '0' || str[i][j] > '9') return false;
        }
        int v = stoi(str[i]);
        if (v < 0 || v > 255) return false;
    }
    return true;
}

//多余0
//出现::
//字符不在0-9 a-f A-F之间
bool if_ipv6(string ip) {
    if (ip.find(':') == ip.npos || ip.size() < 15 || ip.size() > 39) return false;
    vector<string> str = split(ip, ':');
    if (str.size() != 8)return false;
    for (int i = 0; i < str.size(); ++i) {
        string &tmp = str[i];
        if (tmp.empty() || tmp.size() > 4 ) return false;

        for (int j = 0; j < tmp.size(); ++j) {
            char &c = tmp[j];
            if (!((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || (c >= '0' && c <= '9'))) {
                return false;
            }
        }

    }
    return true;
}


class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    string solve(string IP) {
        // write code here
        if (if_ipv4(IP)) return "IPv4";
        if (if_ipv6(IP)) return "IPv6";
        return "Neither";
    }
};


int main() {

    string a = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    Solution s;
    s.solve(a);

}