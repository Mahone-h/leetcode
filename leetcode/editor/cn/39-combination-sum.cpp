//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法 
// 👍 1368 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 排序后从begin开始 前面的组合时包含了后面的
     * 12    不需要21
     * @param res
     * @param candidates
     * @param tmp
     * @param target
     * @param begin
     */
    void helper(vector<vector<int>> &res, vector<int> &candidates, vector<int> &tmp, int target,int begin) {
        if (target == 0) {
            res.emplace_back(tmp);
            return;
        }
        for (int i = begin; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                break;
            }
            tmp.emplace_back(candidates[i]);
            //可以重复用 i开始下一层
            helper(res, candidates, tmp, target - candidates[i],i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(res, candidates, tmp, target,0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}