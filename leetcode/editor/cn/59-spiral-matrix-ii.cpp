//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 矩阵 模拟 
// 👍 441 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/
     * 当 num <= tar 时，始终按照 从左到右 从上到下 从右到左 从下到上 填入顺序循环，每次填入后：
            执行 num += 1：得到下一个需要填入的数字；
            更新边界：例如从左到右填完后，上边界 t += 1，相当于上边界向内缩 1。
     * @param n
     * @return
     */
    vector<vector<int>> generateMatrix(int n) {
        int l = 0, r = n - 1, t = 0, b = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        while (true) {
            //左到右
            for (int i = l; i <= r; ++i) res[t][i] = num++;
            if (++t > b) break;
            //上到下
            for (int i = t; i <= b; ++i) res[i][r] = num++;
            if (--r < l) break;
            //右到左
            for (int i = r; i >= l; i--) res[b][i] = num++;
            if (--b < t) break;
            //下到上
            for (int i = b; i >= t; i--) res[i][l] = num++;
            if (++l > r) break;
        }
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}