120//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 动态规划 
// 👍 1618 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
        /**
         * 迭代
         */
        //if(n<=2){
        //    return n;
        //}
        //int a=1,b=2,c=3;
        //for(int i=3;i<=n;i++){
        //    c=a+b;
        //    a=b;
        //    b=c;
        //}
        //return c;
        /**DFS*/
        //vector<int> memo(n+1);
        //return dfs(n, memo);

        /** DP
         * 变种3 不能走相同步数  x1, x2, …, xm 步
         * 升维dp[i][k]  k表示最后一步通过几步走过来的
         * a[i][x[j]]+=a[i-x[j]][x[1...m]]   过程中排除   a[i-x[j]][x[j]]
         * * */
        if (n <= 1) return n;
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        //dp[2]=3  变种1 +个3
        for (int i = 2; i < n; ++i) {
            dp[n] = dp[i - 1] + dp[i - 2];
            //变种2   x1, x2, …, xm 步   多种步可以走
            //for (int j = 0; j < m; ++j) {
            //    i-x[j] >=0;
            //    dp[n] += dp[i - x[j]];
            //}
        }
        return dp[n - 1];

    }

    int dfs(int n,vector<int> &memo){
        if (n == 0 || n == 1) {
            return 1;
        }
        if (memo[n] == 0) {
            memo[n] = dfs(n - 1, memo) + dfs(n - 2, memo);
        }
        return memo[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}