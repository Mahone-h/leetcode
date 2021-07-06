//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 示例 1: 
//
// 输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "rat", t = "car"
//输出: false 
//
// 说明: 
//你可以假设字符串只包含小写字母。 
//
// 进阶: 
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
// Related Topics 排序 哈希表 
// 👍 383 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //1.暴力 排序o(nLogn)
    //2.hash map 统计每个字符频次
    bool isAnagram(string s, string t) {
        //暴力
        /*if (s.length() != t.length()) {
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;*/

        //hash
        int freq[26]{};  //==int freq[26] ={0};
        for (char ch : s) ++freq[ch - 'a'];
        for (char ch : t) --freq[ch - 'a'];
        for (int i = 0; i < 26; ++i) {
            if (freq[i]!=0) {
                return false;
            }
        }
      //return  all_of(begin(freq), end(freq), [](int x) { return x == 0; });
        return true;

/*        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> table;
        for (int i = 0; i < s.length(); ++i) {
            table[s[i]]++;
        }
        for (int i = 0; i < t.length(); ++i) {
            if (table.count(t[i]) == 0) {
                return false;
            } else {
                table[t[i]]--;
            }
        }
        for (auto iter = table.begin(); iter != table.end(); ++iter) {
            if (iter->second !=0) {
                return false;
            }
        }
        return true;
        //需要c++ 17
//        return unordered_multiset(begin(s), end(s)) == unordered_multiset(begin(t), end(t));*/

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.isAnagram("anagram", "nagaram");
}