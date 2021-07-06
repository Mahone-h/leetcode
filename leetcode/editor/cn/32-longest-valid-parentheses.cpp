//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 104 
// s[i] 为 '(' 或 ')' 
// 
// 
// 
// Related Topics 栈 字符串 动态规划 
// 👍 1353 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        //栈  保持栈底元素 最后一个没有被匹配的右括号的下标
        //stack<int> stk;
        //int res=0;
        //stk.push(-1);
        //for (int i = 0; i < s.size(); ++i) {
        //    if (s[i] == '(') {
        //        stk.push(i);
        //    } else{
        //        stk.pop();//  提前加了个-1 要不先遇到)  pop空stack会导致错误
        //        if (stk.empty()) {
        //            stk.push(i);  //最后一个不配对的
        //        } else{
        //            res = max(res, i - stk.top());
        //        }
        //    }
        //}
        //return res;

        /** DP
         * dp[i] 包含下标i处元素（以i处元素结尾）的有效子串。
         * 思路1
        **/
        //if s[i] == '(' :
        //    dp[i] = 0
        //if s[i] == ')' :
        //    if s[i - 1] == '(' :
        //        dp[i] = dp[i - 2] + 2 #要保证i - 2 >= 0
        //    if s[i - 1] == ')' and s[i - dp[i - 1] - 1] == '(' :
        //        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2 #要保证i - dp[i - 1] - 2 >= 0



        //思路2：
        // dp[i] 包含下标i处元素（以i处元素结尾）的有效子串。
        // s[i]=='('  dp[i]=0
        //s[i]==')'     找 j = i-dp[i-1]-1 =='(' 和当前对应的位置
        //         j-1 >=0  dp[i] = dp[i-1] + 2 + dp[j-1]
        vector<int> dp(s.size(), 0);
        int res = 0;
        for (int i = 1; i < s.size(); ++i) {
            int j = i - dp[i - 1] - 1;//和当前对应的位置
            if (s[i]==')'  && j>=0 &&s[j]=='('){
                dp[i] = dp[i - 1] + 2;
                if (j - 1 >= 0) {  //如果前面还有  因为j处截断了 dp[i - 1] 不可能包含j之前的
                    dp[i] += dp[j - 1];
                }
                res = max(res, dp[i]);
            }
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.longestValidParentheses(")()())");
    
}