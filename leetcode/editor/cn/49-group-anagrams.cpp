//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串 
// 👍 735 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //暴力 排序 判断set里面有没有
        //时间复杂度：(nklogk)，其中 n 是 strs中的字符串的数量，k是strs 中的字符串的的最大长度
        //空间复杂度：O(nk)O(nk)
        map<string,vector<string>> res;
        vector<vector<string>> re;
        string sorted;
        for (int i = 0; i < strs.size(); ++i) {
            sorted = strs[i];
            sort(sorted.begin(),sorted.end());
            res[sorted].emplace_back(strs[i]);
        }
        for (auto iter = res.begin(); iter != res.end(); ++iter) {
            re.emplace_back(iter->second);
        }
        return re;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}