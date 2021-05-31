//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 回溯算法 
// 👍 1803 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n < 1) return result;
        string parens;
        collect(result, parens, n, n);
        return result;
    }
    void collect(vector<string> &result, string &parens, int left, int right) {
        if (left > right || left < 0) return;
        if (left + right == 0) {
            result.push_back(parens);
            return;
        }
        parens.push_back('(');
        collect(result, parens, left - 1, right);
        parens.pop_back();
        parens.push_back(')');
        collect(result, parens, left, right - 1);
        parens.pop_back();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}