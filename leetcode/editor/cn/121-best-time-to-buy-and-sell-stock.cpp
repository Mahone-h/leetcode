//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。 
//
// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。 
//
// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。 
//
// 
//
// 示例 1： 
//
// 
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 
//
// 示例 2： 
//
// 
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 105 
// 0 <= prices[i] <= 104 
// 
// Related Topics 数组 动态规划 
// 👍 1668 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        /** dp[i][k][0/1]表示利润 i天数  k交易次数 买入算一次  0/1 不持有/持有
         *                    保持之前       前一次的基础上卖出 /买入
         * dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
         * dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
         *             = max(dp[i-1][1][1], -prices[i])
            解释：k = 0 的 base case，所以 dp[i-1][0][0] = 0。
         * k=1
         */
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); ++i) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;

        //一次遍历
        //int minprice = INT_MAX,maxprofit=0;
        //for (int price:prices) {
        //    maxprofit = max(maxprofit, price - minprice);
        //    minprice = min(minprice, price);
        //}
        //return maxprofit;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}