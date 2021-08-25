//
// Created by Mahone on 2021/8/20.
//
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
     * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，
     * 并保证奇数和奇数，偶数和偶数之间的  **相对位置不变**
     * 相对位置不要求可以首尾双指针
     * @param array int整型vector
     * @return int整型vector
     */

    bool ifOdd(int &x){
        return x % 2 != 0;
    }
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        vector<int> l,r;
        for (int &v:array) {
            if (v%2) l.emplace_back(v);
            else r.emplace_back(v);
        }
        l.insert(l.end(), r.begin(), r.end());
        return l;

    }
};