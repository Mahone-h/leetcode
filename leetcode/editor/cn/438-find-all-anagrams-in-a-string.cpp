//给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。 
//
// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。 
//
// 说明： 
//
// 
// 字母异位词指字母相同，但排列不同的字符串。 
// 不考虑答案输出的顺序。 
// 
//
// 示例 1: 
//
// 
//输入:
//s: "cbaebabacd" p: "abc"
//
//输出:
//[0, 6]
//
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
// 
//
// 示例 2: 
//
// 
//输入:
//s: "abab" p: "ab"
//
//输出:
//[0, 1, 2]
//
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
// 
// Related Topics 哈希表 字符串 滑动窗口 
// 👍 553 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (p.size() > s.size() || s.empty()) return res;
        vector<int> need(26, 0);
        vector<int> windows(26, 0);
        int m = p.size();
        for (int i = 0; i < m; ++i) {
            need[p[i] - 'a']++;
            windows[s[i] - 'a']++;
        }
        if (windows == need) res.emplace_back(0);

        for (int i = m; i < s.size(); ++i) {
            windows[s[i] - 'a']++;
            windows[s[i - m] - 'a']--;
            if (windows == need) res.emplace_back(i - m + 1);
        }


        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> tmp = s.findAnagrams("cbaebabacd", "abc");
    for (int num:tmp) {
        cout << num << endl;
    }

}