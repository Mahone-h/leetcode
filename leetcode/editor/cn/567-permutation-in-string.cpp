//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。 
//
// 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。 
//
// 
//
// 示例 1： 
//
// 
//输入: s1 = "ab" s2 = "eidbaooo"
//输出: True
//解释: s2 包含 s1 的排列之一 ("ba").
// 
//
// 示例 2： 
//
// 
//输入: s1= "ab" s2 = "eidboaoo"
//输出: False
// 
//
// 
//
// 提示： 
//
// 
// 输入的字符串只包含小写字母 
// 两个字符串的长度都在 [1, 10,000] 之间 
// 
// Related Topics 哈希表 双指针 字符串 滑动窗口 
// 👍 370 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> need(26, 0);
        vector<int> windows(26, 0);
        int m = s1.size();
        for (int i = 0; i < m; ++i) {
            need[s1[i] - 'a']++;
            windows[s2[i] - 'a']++;
        }
        if (need == windows) return true;
        for (int i = m; i < s2.size(); ++i) {
            windows[s2[i] - 'a']++;
            windows[s2[i - m] - 'a']--;
            if (windows == need) return true;
        }
        return false;

        /**还可以在保证 cnt 的值不为正的情况下，去考察是否存在一个区间，其长度恰好为 nn。*/





    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}