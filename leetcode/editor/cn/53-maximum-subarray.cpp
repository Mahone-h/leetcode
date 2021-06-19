//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：nums = [-1]
//输出：-1
// 
//
// 示例 5： 
//
// 
//输入：nums = [-100000]
//输出：-100000
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 104 
// -105 <= nums[i] <= 105 
// 
//
// 
//
// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。 
// Related Topics 数组 分治算法 动态规划 
// 👍 3307 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /**
         * 暴力 O(N^2)
         * DP :
         * a. 分治 子问题： max_sum(i)=Max(max_sum(i-1)+a[i],a[i])
         * b.状态数组定义 f[i]
         * c.DP方程： f[i]=max(f(i-1)+nums[i],nums[i])
         */
        /**空间O(N) */
        //vector<int> dp(nums.size());
        //dp[0] = nums[0];
        //int res=dp[0];
        //for (int i = 1; i < nums.size(); ++i) {
        //    dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        //    res = max(res, dp[i]);
        //}
        //return res;
        /**优化 空间O(1)*/
        int pre = 0,res=nums[0];
        for (int num:nums) {
            pre = max(pre + num, num);
            res = max(res, pre);
        }
        return res;
        /**类似上面的  sum 表示当前子序列和
         * sum>0  留下
         * sum<=0  舍弃  从新开始计算新的
         **/
        //int sum = 0, res = nums[0];
        //for (int num:nums) {
        //    if (sum>0){
        //        sum += num;
        //    } else{
        //        sum = num;
        //    }
        //    res = max(sum, res);
        //}
        //return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
  
}