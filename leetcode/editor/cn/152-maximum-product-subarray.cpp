//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 
//
// 
//
// 示例 1: 
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
// 
//
// 示例 2: 
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。 
// Related Topics 数组 动态规划 
// 👍 1141 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        /**  当前位置的最优解未必是由前一个位置的最优解转移得到的。
         *  前面负的留到后面可能有用
         *  a:子问题     max_mul[i]=max(min[i-1]*nums[i],max[i-1]*nums[i],nums[i])
         *  b:状态数组定义 f[i]
         *  c:DP方程  f[i]=max(min[i-1]*nums[i],max[i-1]*nums[i],nums[i])
         */
        int maxF = 1, minF = 1, res = INT_MIN, mx, mn;
        for (int num:nums) {
            mx = maxF;
            mn = minF;
            maxF = max(mx * num, max(mn * num, num));
            minF = min(mx * num, min(mn * num, num));
            res = max(maxF, res);
        }
        return res;
        //int res = INT_MIN, imax = 1, imin = 1;
        //for (int i = 0; i < nums.size(); i++) {
        //    if (nums[i] < 0) {
        //        int tmp = imax;
        //        imax = imin;
        //        imin = tmp;
        //    }
        //    imax = max(imax * nums[i], nums[i]);
        //    imin = min(imin * nums[i], nums[i]);
        //
        //    res = max(res, imax);
        //}
        //return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}