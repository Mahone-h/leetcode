//你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上
//被小偷闯入，系统会自动报警。 
//
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。 
//
// 
//
// 示例 1： 
//
// 
//输入：[1,2,3,1]
//输出：4
//解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//     偷窃到的最高金额 = 1 + 3 = 4 。 
//
// 示例 2： 
//
// 
//输入：[2,7,9,3,1]
//输出：12
//解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//     偷窃到的最高金额 = 2 + 9 + 1 = 12 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 400 
// 
// Related Topics 动态规划 
// 👍 1501 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rob(vector<int> &nums) {
        /**
         * 第一种思路 a[i] 0...i
         * a[i][0,1] 0不偷 1偷
         * a[i][0]=max(a[i-1][0],a[i-1][1])
         * a[i][1]=a[i-1][0]+nums[i]
         *
         * 第二种思路
         *   dp[i] 表示前 i 间房屋能偷窃到的最高总金额
         * a. sub problems
         * b. DP array f[i] =max(a[i-1],a[i-2]+nums[i])
         *  i-1 偷或者i偷
         * c. DP 方程
         */
        //if (nums.empty()) {
        //    return 0;
        //}
        //if (nums.size() == 1) {
        //    return nums[0];
        //}
        //vector<int> dp(nums.size(), 0);
        //dp[0] = nums[0];
        //dp[1] = max(nums[0],nums[1]);
        //int res = dp[1];
        //for (int i = 2; i < nums.size(); ++i) {
        //    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        //    res = max(res, dp[i]);
        //}
        //return res;

        //DP array f[i] =max(a[i-1],a[i-2]+nums[i])
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]),tmp;
        for (int i = 2; i < nums.size(); ++i) {
            tmp = second;
            second = max(first + nums[i], second);
            first = tmp;
        }
        return second;

        /**最精简*/
        //int first = 0, second = 0, tmp;
        //for (int num:nums) {
        //    tmp = second;
        //    second = max(second, first + num);
        //    first = tmp;
        //}
        //return second;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}