//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 输入："abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 输入："aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 输入的字符串长度不会超过 1000 。 
// 
// Related Topics 字符串 动态规划 
// 👍 617 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        /**
         * dp[i][j]  i-j之间的子串是否回文子串  i<=j
         * 1个字符 i==j
         * 2个字符 j-i==1  && s[i]==s[j]
         *  s[i]==s[j]  && s[i+1][j-1]  把两边去掉后 中间必须还是子串
         *  注意遍历方向
         */
        //int n = s.size();
        //int count = 0;
        //vector<vector<bool>> dp(n, vector<bool>(n, 0));
        //for (int j = 0; j < n; ++j) {
        //    for (int i = 0; i <= j; ++i) {
        //        if (i == j) {
        //            dp[i][j] = true;
        //            count++;
        //        } else if (j - i == 1 && s[i] == s[j]) {
        //            dp[i][j] = true;
        //            count++;
        //        } else if (j - i > 1 && s[i] == s[j] && dp[i + 1][j - 1]) {
        //            dp[i][j] = true;
        //            count++; //左下角格子 所以按列遍历
        //        }
        //    }
        //}
        //return count;
        /** 降维*/
        int n = s.size();
        int count = 0;
        vector<bool> dp(n, 0);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j] && (j - i <= 1 || dp[i + 1])){
                    dp[i] = true;
                    count++;
                }
            }
        }
        return count;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}