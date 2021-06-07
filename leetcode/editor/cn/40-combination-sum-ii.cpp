//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 说明： 
//
// 
// 所有数字（包括目标数）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
// 
//
// 示例 2: 
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//] 
// Related Topics 数组 回溯算法 
// 👍 592 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void helper(vector<vector<int>> &res, vector<int> &candidates, vector<int> &tmp, int target, int begin) {
        if (target == 0) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = begin; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            //i>begin 第一个会选
            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }
            // 元素不可重复利用，使用下一个即i+1
            tmp.emplace_back(candidates[i]);
            helper(res, candidates, tmp, target - candidates[i], i + 1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(res, candidates, tmp, target, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> vec = {10, 1, 2, 7, 6, 1, 5};
    s.combinationSum2(vec, 8);
}