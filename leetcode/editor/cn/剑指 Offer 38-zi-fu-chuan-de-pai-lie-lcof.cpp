//输入一个字符串，打印出该字符串中字符的所有排列。 
//
// 
//
// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。 
//
// 
//
// 示例: 
//
// 输入：s = "abc"
//输出：["abc","acb","bac","bca","cab","cba"]
// 
//
// 
//
// 限制： 
//
// 1 <= s 的长度 <= 8 
// Related Topics 回溯算法 
// 👍 280 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void helper(string &s, vector<string> &res, string &tmp, vector<bool> &used) {
        if (tmp.size() == s.size()) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!used[i]) {
                if (i > 0 && s[i - 1] == s[i] && !used[i - 1]){
                    continue;
                }
                tmp.push_back(s[i]);
                used[i] = true;
                helper(s, res, tmp, used);
                tmp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<string> permutation(string s) {
        vector<string> res;
        if (s.empty()) {
            return res;
        }
        string tmp;
        vector<bool> used(s.size(), false);
        sort(s.begin(), s.end());
        helper(s, res, tmp, used);
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}