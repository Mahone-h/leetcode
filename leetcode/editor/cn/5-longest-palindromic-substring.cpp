//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 示例 3： 
//
// 
//输入：s = "a"
//输出："a"
// 
//
// 示例 4： 
//
// 
//输入：s = "ac"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母（大写和/或小写）组成 
// 
// Related Topics 字符串 动态规划 
// 👍 3782 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int start,max_len;
    string longestPalindrome(string s) {
        /**
         * 1.暴力 枚举ij (起点和重点) 判断是否回文
         * 2. 中心扩展
         * 3.dp
         */
        /** 2*/
        for (int i = 0; i < s.size(); ++i) {
            palindrome(s, i, i);
            palindrome(s, i, i + 1);
        }
        return s.substr(start, max_len);
        /**3      慢 */
        //dp[i][j] i-j是不是回文子串
        // dp[i][j]=  i == j && (dp[i+1][j-1] || j-i<2)   长度 < 2
        //i j需要知道 i+1   倒着遍历

        //int n = s.size();
        //int max_len = 0,l;
        //vector<vector<int>> dp(n, vector<int>(n, 0));
        //for (int i = n-1; i >= 0 ; i--) {
        //    for (int j = i; j < n; ++j) {
        //        dp[i][j] = s[i] == s[j] && ((j - i < 2) || dp[i + 1][j - 1]);
        //        if (dp[i][j] && j - i + 1 > max_len) {
        //            max_len = j - i + 1;
        //            l = i;
        //        }
        //    }
        //}
        //return s.substr(l, max_len);

    }

    void palindrome(string &s,int l, int r){
        while (l>=0 && r < s.size() && s[l]==s[r]) {
            l--;
            r++;
        }
        if (max_len < r - l - 1) {
            max_len = r - l - 1;
            start = l + 1;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.longestPalindrome("babad");
}