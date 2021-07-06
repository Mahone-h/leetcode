//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。 
//
// 子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序
//列。 
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1,0,3,2,3]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：nums = [7,7,7,7,7,7,7]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 2500 
// -104 <= nums[i] <= 104 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以设计时间复杂度为 O(n2) 的解决方案吗？ 
// 你能将算法的时间复杂度降低到 O(n log(n)) 吗? 
// 
// Related Topics 数组 二分查找 动态规划 
// 👍 1677 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        //dp[i] 最长长度
        //mem[i]  最长长度最后的值
        // dp[i] = max(dp[i], dp[j] + 1) for j in [0, i)
        //当前的要和前面的每一个进行比较  看能不能凑子序列
        //vector<int> dp(nums.size(), 1);
        //int res = 0;
        //for (int i = 0; i < nums.size(); ++i) {
        //    for (int j = 0; j < i; ++j) {
        //        if (nums[i] > nums[j]) {
        //            dp[i] = max(dp[i], dp[j] + 1);
        //        }
        //    }
        //    res = max(res, dp[i]);
        //}
        //return res;
        if (nums.size() < 2) {
            return nums.size();
        }
        vector<int> tail = {nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > tail.back()) {
                tail.emplace_back(nums[i]);
            } else{
                int l = 0, r = tail.size();
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (tail[mid] < nums[i]) {
                        l = mid + 1;
                    } else{
                        r = mid;
                    }
                }
                tail[l] = nums[i];
            }
        }
        return tail.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> tmp = {10, 9, 2, 5, 3, 7, 101, 18};
    s.lengthOfLIS(tmp);

}