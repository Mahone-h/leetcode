//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。 
//
// 有效字符串需满足： 
//
// 
// 左括号必须用相同类型的右括号闭合。 
// 左括号必须以正确的顺序闭合。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "()[]{}"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：s = "(]"
//输出：false
// 
//
// 示例 4： 
//
// 
//输入：s = "([)]"
//输出：false
// 
//
// 示例 5： 
//
// 
//输入：s = "{[]}"
//输出：true 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅由括号 '()[]{}' 组成 
// 
// Related Topics 栈 字符串 
// 👍 2368 👎 0


#include "include/headers.h"

/**
 *  1. 暴力法 不断replace匹配到的括号 o(n^2)
 *  2. stack
 */
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isValid(string s) {
        /**
         * 有hash
         */
//        if (s.size()%2==1) {
//            return false;
//        }
//        unordered_map<char, char> dic = {{'{', '}'},
//                                         {'[', ']'},
//                                         {'(', ')'}};
//        char tmp;
//        deque<char> deq;
//        for (int i = 0; i < s.length(); ++i) {
//            tmp = s[i];
//            if (dic.count(tmp) > 0){
//                deq.push_back(dic[tmp]);
//            } else if(deq.size()>0&&deq.back()==tmp){
//                deq.pop_back();
//            }else{
//                return false;
//            }
//        }
//        return deq.empty();
        /**
         * 无hash
         */
        if (s.size()%2==1) {
            return false;
        }
        stack<char> stack;
        for (char c:s) {
            if(c=='(')
                stack.push(')');
            else if(c=='{')
                stack.push('}');
            else if(c=='[')
                stack.push(']');
            else if(stack.empty()||c!=stack.top())
                return false;
            else{
                stack.pop();
            }
        }
        return stack.empty();

  }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.isValid("()");
}