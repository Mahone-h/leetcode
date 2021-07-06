//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。 
//
// '?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
// 
//
// 两个字符串完全匹配才算匹配成功。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "*"
//输出: true
//解释: '*' 可以匹配任意字符串。
// 
//
// 示例 3: 
//
// 输入:
//s = "cb"
//p = "?a"
//输出: false
//解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 
//
// 示例 4: 
//
// 输入:
//s = "adceb"
//p = "*a*b"
//输出: true
//解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 
//
// 示例 5: 
//
// 输入:
//s = "acdcb"
//p = "a*c?b"
//输出: false 
// Related Topics 贪心 递归 字符串 动态规划 
// 👍 711 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         *  p null s !null 不匹配
         *         s null 匹配
         *  s null p !null *
         *  dp[i][j]   p的n-1和s的i-1是否匹配
         *  + null 行和列
         *  if s[i-1] == p[j-1] || p[j-1]=='?'   dp[i][j] = dp[i-1][j-1]
         *  else p[j-1]=='*' 零或任意多个小写字母
         *        dp[i][j] = dp[i-1][j] || dp[i][j-1]
         */
        if (p.empty()) {
            if (s.empty()) return true;
            else return false;
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        //s null p null
        dp[0][0] = 1;
        //s null，p !null，由于*可以匹配0个字符，所以有可能为true  如 s null p a*
        for (int j = 1; j < dp[0].size(); ++j) {
            if (p[j - 1] == '*') dp[0][j] = true;
            else break;
        }

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}