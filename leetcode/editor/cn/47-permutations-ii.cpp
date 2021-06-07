//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 回溯算法 
// 👍 707 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void dfs(vector<int> &tmp, vector<int> &nums, vector<bool> &used,vector<vector<int>> &res) {
        if (tmp.size() == nums.size()) {
            res.emplace_back(tmp);
            return;
        }
        /**
         * 0ms  用set的话10ms左右
         */
         //set<int> unique;
        for (int i = 0; i < nums.size(); ++i) {
            if (!used[i]) {
                // !used[i - 1]前面的在用 并且 用现在的没事
                // !used[i - 1]前面的没在用 和现在的相等 重复
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                    continue;
                }
                //unique.emplace(nums[i]);
                used[i] = true;
                tmp.emplace_back(nums[i]);
                dfs(tmp, nums, used, res);
                used[i] = false;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(),nums.end());
        dfs(tmp, nums, used, res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}