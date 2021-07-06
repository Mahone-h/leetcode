//给定一个字符串 S，返回 “反转后的” 字符串，其中不是字母的字符都保留在原地，而所有字母的位置发生反转。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入："ab-cd"
//输出："dc-ba"
// 
//
// 示例 2： 
//
// 输入："a-bC-dEf-ghIj"
//输出："j-Ih-gfE-dCba"
// 
//
// 示例 3： 
//
// 输入："Test1ng-Leet=code-Q!"
//输出："Qedo1ct-eeLg=ntse-T!"
// 
//
// 
//
// 提示： 
//
// 
// S.length <= 100 
// 33 <= S[i].ASCIIcode <= 122 
// S 中不包含 \ or " 
// 
// Related Topics 双指针 字符串 
// 👍 80 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while ( l < r &&(s[l] < 'A' || s[l] > 'z' || ('Z' < s[l] && s[l] < 'a'))) {
                l++;
            }
            while (l < r && s[r] < 'A' || s[r] > 'z' || ('Z' < s[r] && s[r] < 'a')) {
                r--;
            }
            if (l < r) {
                swap(s[l++], s[r--]);
            }
        }
        return s;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    string tmp = "7_28]";
    s.reverseOnlyLetters(tmp);

}