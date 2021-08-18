//给定一个平衡括号字符串 S，按下述规则计算该字符串的分数： 
//
// 
// () 得 1 分。 
// AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。 
// (A) 得 2 * A 分，其中 A 是平衡括号字符串。 
// 
//
// 
//
// 示例 1： 
//
// 输入： "()"
//输出： 1
// 
//
// 示例 2： 
//
// 输入： "(())"
//输出： 2
// 
//
// 示例 3： 
//
// 输入： "()()"
//输出： 2
// 
//
// 示例 4： 
//
// 输入： "(()(()))"
//输出： 6
// 
//
// 
//
// 提示： 
//
// 
// S 是平衡括号字符串，且只含有 ( 和 ) 。 
// 2 <= S.length <= 50 
// 
// Related Topics 栈 字符串 👍 233 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int scoreOfParentheses(string s) {
        /**
         * 事实上，我们可以发现，只有 () 会对字符串 S 贡献实质的分数，
         * 其它的括号只会将分数乘二或者将分数累加。找到每一个 () 对应的深度 x，那么答案就是 2^x 的累加和。
         */
        int ans = 0, depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i]=='('){
                depth++;
            } else{
                depth--;
                if (s[i - 1] == '(') {
                    ans += 1 << depth;
                }
            }
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}