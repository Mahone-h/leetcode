//
// Created by Mahone on 2021/8/18.
//
#include <string>

using namespace std;

class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串
     * @return string字符串
     */
    string solve(string str) {
        // write code here
        int len=str.size();
        for(int i=0;i<len/2;i++){
            swap(str[i], str[len-1-i]);
        }
        return str;
    }
};