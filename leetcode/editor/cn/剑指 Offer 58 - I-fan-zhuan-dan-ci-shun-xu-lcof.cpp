//输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
//则输出"student. a am I"。 
//
// 
//
// 示例 1： 
//
// 输入: "the sky is blue"
//输出: "blue is sky the"
// 
//
// 示例 2： 
//
// 输入: "  hello world!  "
//输出: "world! hello"
//解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
// 
//
// 示例 3： 
//
// 输入: "a good   example"
//输出: "example good a"
//解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
// 
//
// 
//
// 说明： 
//
// 
// 无空格字符构成一个单词。 
// 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。 
// 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
// 
//
// 注意：本题与主站 151 题相同：https://leetcode-cn.com/problems/reverse-words-in-a-string/ 
//
//
// 注意：此题对比原题有改动 
// Related Topics 双指针 字符串 👍 124 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
        /**
         * 字符串拼接
         */
        //stringstream ss(s);
        //vector<string> tmp;
        //while (ss >> s) {
        //    tmp.emplace_back(s);
        //}
        //string res;
        //for (int i = tmp.size()-1; i >=0 ; i--) {
        //    res += tmp[i] + " ";
        //}
        //if (!res.empty()) res.pop_back();
        //return res;
        /**
         * 双指针
         */
        string res;
        if (s.empty()) return res;
        int left, right = s.size() - 1;
        while (right >= 0) {
            //从右往前找第一个字符
            while (right >= 0 && s[right]==' ') right--;
            if (right < 0) break;

            //从右向左找第一个空
            left = right;
            while (left >= 0 && s[left]!=' ') left--;

            //添加单词
            res += s.substr(left + 1, right - left);
            res += " ";
            //继续
            right = left -1;
        }
        if (!res.empty()) res.pop_back();
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}