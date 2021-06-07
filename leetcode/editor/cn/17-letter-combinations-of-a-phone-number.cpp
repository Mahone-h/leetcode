//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
// Related Topics 深度优先搜索 递归 字符串 回溯算法 
// 👍 1334 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void helper(vector<string> &res, string &digits, int begin,string &tmp,vector<string> &map){
        if (begin == digits.size()) {
            res.emplace_back(tmp);
            return;
        }
        string v = map[digits[begin]-'2'];
        for (int j = 0; j < v.size(); ++j) {
            tmp.push_back(v[j]);
            helper(res, digits, begin + 1, tmp, map);
            tmp.pop_back();
        }

    }


    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) {
            return res;
        }
        //unordered_map<char, string> map;
        //map.emplace('2', "abc");
        //map.emplace('3', "def");
        //map.emplace('4', "ghi");
        //map.emplace('5', "jkl");
        //map.emplace('6', "mno");
        //map.emplace('7', "pqrs");
        //map.emplace('8', "tuv");
        //map.emplace('9', "wxyz");
        vector<string> map;
        map.emplace_back("abc");
        map.emplace_back("def");
        map.emplace_back("ghi");
        map.emplace_back("jkl");
        map.emplace_back("mno");
        map.emplace_back("pqrs");
        map.emplace_back("tuv");
        map.emplace_back("wxyz");
        string tmp;
        helper(res, digits, 0, tmp, map);
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.letterCombinations("23");
    
}