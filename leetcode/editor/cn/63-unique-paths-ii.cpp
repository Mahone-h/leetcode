//一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。 
//
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。 
//
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？ 
//
// 
//
// 网格中的障碍物和空位置分别用 1 和 0 来表示。 
//
// 
//
// 示例 1： 
//
// 
//输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
//输出：2
//解释：
//3x3 网格的正中间有一个障碍物。
//从左上角到右下角一共有 2 条不同的路径：
//1. 向右 -> 向右 -> 向下 -> 向下
//2. 向下 -> 向下 -> 向右 -> 向右
// 
//
// 示例 2： 
//
// 
//输入：obstacleGrid = [[0,1],[0,0]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == obstacleGrid.length 
// n == obstacleGrid[i].length 
// 1 <= m, n <= 100 
// obstacleGrid[i][j] 为 0 或 1 
// 
// Related Topics 数组 动态规划 
// 👍 567 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 动态规划的题目分为两大类，一种是求最优解类，典型问题是背包问题，
     * 另一种就是计数类，比如这里的统计方案数的问题，它们都存在一定的递推性质。
     * 前者的递推性质还有一个名字，
     * 叫做 「最优子结构」 ——即当前问题的最优解取决于子问题的最优解，后者类似，
     * 当前问题的方案数取决于子问题的方案数。所以在遇到求方案数的问题时，我们可以往动态规划的方向考虑。
     */
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> cur(n);
        cur[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //遇到障碍 当前为0
                if (obstacleGrid[i][j] == 1) {
                    cur[j] = 0;
                    continue;
                }
                //&& obstacleGrid[i][j - 1] == 0   有没有都一样。 没有相当于 左0+上值
                if (j >= 1 && obstacleGrid[i][j - 1] == 0) {
                    //cur[j] 最开始就是pre[j]
                    cur[j] += cur[j - 1];
                }
            }
        }
        return cur[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> tmp={{0,0,0},{1,0,0},{0,0,0}};
    s.uniquePathsWithObstacles(tmp);
}