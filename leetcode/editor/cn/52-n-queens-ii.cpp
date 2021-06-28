//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 4
//输出：2
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 回溯算法 
// 👍 264 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void DFS(int &n, int row, int col, int ld, int rd, int &res) {
        if (row >= n) {
            res++;
            return;
        }
        int pos = (~(col | ld | rd)) & ((1 << n) - 1);  //获取所有空位
        while (pos > 0) {
            int p = pos & (-pos);  //最后一个1   例：1010 返回  0010
            pos &= (pos - 1);   //清零最低位的 1
            DFS(n, row + 1, col | p, (ld | p) << 1, (rd | p) >> 1, res);
        }
    }


    int totalNQueens(int n) {
        int res = 0;
        DFS(n, 0, 0, 0, 0, res);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}