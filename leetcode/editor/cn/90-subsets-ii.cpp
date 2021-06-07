//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
// 
// 
// Related Topics 数组 回溯算法 
// 👍 581 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void helper(vector<vector<int>> &res,vector<int>& nums,vector<int> &path,int begin){
        res.emplace_back(path);
        for (int i = begin; i < nums.size(); ++i) {
            if (i > begin && nums[i] == nums[i - 1]) {
                continue;
            }
            path.emplace_back(nums[i]);
            helper(res, nums, path, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(res, nums, path, 0);
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}