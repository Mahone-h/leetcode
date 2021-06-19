//给定一个三角形 triangle ，找出自顶向下的最小路径和。 
//
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果
//正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
//输出：11
//解释：如下面简图所示：
//   2
//  3 4
// 6 5 7
//4 1 8 3
//自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
// 
//
// 示例 2： 
//
// 
//输入：triangle = [[-10]]
//输出：-10
// 
//
// 
//
// 提示： 
//
// 
// 1 <= triangle.length <= 200 
// triangle[0].length == 1 
// triangle[i].length == triangle[i - 1].length + 1 
// -104 <= triangle[i][j] <= 104 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？ 
// 
// Related Topics 数组 动态规划 
// 👍 774 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /**
         * 1.暴力 递归 n层 left or right 2^n
         * 2.DP  a.重复性(分治) problem(i,j)=min(sub(i+1,j)+sub(i+1,j+1)+a(i,j))
         *       b.定义状态数组 f[i,j]
         *       c.DP方程      f[i,j]=min(f[i+1,j]+f[i+1,j+1])+a(i,j)
         */

        //使用原数组
        //for (int i = triangle.size()-2; i >=0; i--) {
        //    for (int j = 0; j<triangle[i].size() ; ++j) {
        //        triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        //    }
        //}
        //return triangle[0][0];

        //O(N) 空间 开个新的
        vector<int> dp(triangle.back());
        for (int i = triangle.size()-2; i >=0; i--) {
            for (int j = 0; j < triangle[i].size() ; ++j) {
                dp[j] = min(dp[j], dp[j+1])+triangle[i][j];
            }
        }
        return dp[0];


        //递归
        //return minPath(triangle,0,0);

    }
    int minPath(vector<vector<int>>& triangle, int level, int index) {
        int n = triangle.size();
        // just in case, though this case never hits
        if(level >= n) return 0;
        if(level == n-1)  // we are on last level right now, this must be starting point
            return triangle[level][index];
        // you either come from (level+1, index+1) or (level+1, index), we choose min here
        return min(minPath(triangle,level+1, index),minPath(triangle,level+1, index+1)) + triangle[level][index];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
  
}