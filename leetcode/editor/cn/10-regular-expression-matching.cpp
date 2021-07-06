//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// 
// '.' 匹配任意单个字符 
// '*' 匹配零个或多个前面的那一个元素 
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。 
// 
//
// 示例 1： 
//
// 
//输入：s = "aa" p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 
//输入：s = "aa" p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3： 
//
// 
//输入：s = "ab" p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 示例 4： 
//
// 
//输入：s = "aab" p = "c*a*b"
//输出：true
//解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 
//
// 示例 5： 
//
// 
//输入：s = "mississippi" p = "mis*is*p*."
//输出：false 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 20 
// 0 <= p.length <= 30 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 保证每次出现字符 * 时，前面都匹配到有效的字符 
// 
// Related Topics 递归 字符串 动态规划 
// 👍 2214 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        /**
         * dp[i][j] p的前[n-1]个字符能否匹配s的前[m-1]个字符
         * 初始化+null行和列
         * p null s !null  不匹配
         *        s  null   true
         * s null  p!=null  只可能是右端是星号，它干掉一个字符后，把 p 变为空串
         * dp[0][j]=dp[0][j-2]
         *
         * s[i-1]==p[j-1] || p[j-1]=='.'  dp[i][j] = dp[i-1][j-1]
         * else
         *   if p[j-1]=='*'  //p[j−1] 星号可以让 p[j-2] 在 p 串中消失、出现>=1次
         *      if s[i-1]==p[j-2] || p[j-2]=='.'
         *           p[j-2] 出现0次      dp[i][j]=dp[i][j-2]
         *           p[j-2] 出现>=1      dp[i][j]=dp[i-1][j]    拿出一个 和s[i-1]抵清
         *      else   //   p[j-1]和p[j-2] 被干掉
         * j         dp[i][j]=dp[i][j-2]
         *
         *   else false
         */
        if(p.empty()) {
            if (s.empty()) return true;
            else return false;
        }
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        //s null p null
        dp[0][0] = 1;
        //s null，p !null，由于*可以匹配0个字符，所以有可能为true  如 s null p a*
        for (int j = 2; j < dp[0].size(); ++j) {
            if (p[j-1] == '*') dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (s[i-1] == p[j-1] || p[j-1]=='.'){
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(p[j-1] == '*'){
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    } else{   // a* 删掉
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp.back().back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}