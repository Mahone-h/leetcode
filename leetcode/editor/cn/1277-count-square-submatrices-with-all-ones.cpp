//给你一个 m * n 的矩阵，矩阵中的元素不是 0 就是 1，请你统计并返回其中完全由 1 组成的 正方形 子矩阵的个数。 
//
// 
//
// 示例 1： 
//
// 输入：matrix =
//[
//  [0,1,1,1],
//  [1,1,1,1],
//  [0,1,1,1]
//]
//输出：15
//解释： 
//边长为 1 的正方形有 10 个。
//边长为 2 的正方形有 4 个。
//边长为 3 的正方形有 1 个。
//正方形的总数 = 10 + 4 + 1 = 15.
// 
//
// 示例 2： 
//
// 输入：matrix = 
//[
//  [1,0,1],
//  [1,1,0],
//  [1,1,0]
//]
//输出：7
//解释：
//边长为 1 的正方形有 6 个。 
//边长为 2 的正方形有 1 个。
//正方形的总数 = 6 + 1 = 7.
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 300 
// 1 <= arr[0].length <= 300 
// 0 <= arr[i][j] <= 1 
// 
// Related Topics 数组 动态规划 矩阵 
// 👍 159 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //dp[i][j] = 表示到ij最大的变长
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        matrix[i][j] = min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]}) + 1;
                    }
                    res += matrix[i][j];
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<int>> tmp={{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout << s.countSquares(tmp)<< endl;
}