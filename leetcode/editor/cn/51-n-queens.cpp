//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。 
//
// 
// 
// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4
//输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[["Q"]]
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
// 👍 893 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    void backtrack(int &n, int row,vector<int> &cols, vector<int> &xy_dif, vector<int> &xy_sum, vector<vector<string>> &res,
                   vector<string> &tmp) {
        if (row == n) {
            res.emplace_back(tmp);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols[col] && xy_dif[n - 1 + row - col] && xy_sum[row + col]) {
                cols[col] = xy_dif[n - 1 + row - col] = xy_sum[row + col] = 0;
                tmp[row][col] = 'Q';
                backtrack(n, row + 1, cols, xy_dif, xy_sum, res, tmp);
                cols[col] = xy_dif[n - 1 + row - col] = xy_sum[row + col] = 1;
                tmp[row][col] = '.';
            }
        }
    }
    int getPos(int n) {
        int count = 0;
        while (n != 1) {
            n = n >> 1;
            count++;
        }
        return count;
    }

    void DFS(int n, int row, int col, int ld, int rd, vector<vector<string>> &res, vector<string> tmp) {
        if (row == n) {
            res.emplace_back(tmp);
            return;
        }
        int blank = (~(col | ld | rd)) & ((1 << n) - 1);  //获取所有空位
        while (blank > 0) {
            int p = blank & (-blank);  //最后一个1   例：1010 返回  0010
            int pos = getPos(p);
            blank &= (blank - 1);
            tmp[row][pos] = 'Q';
            DFS(n, row + 1, col | p, (ld | p) << 1, (rd | p) >> 1, res, tmp);
            tmp[row][pos] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        /**
         *  row col n
         *  斜线两个方向有 2*n-1
         *  45°   row+col 相等
         *  135°  row-col 相等
         *  用set 也可以 直接
         *  https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.
         */
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        vector<int> cols(n, 1), xy_dif(2 * n - 1, 1), xy_sum(2 * n - 1, 1);
        backtrack(n,0,cols,xy_dif,xy_sum,res,tmp);
        return res;
        //vector<vector<string>> res;
        //vector<string> tmp(n, string(n, '.'));
        //DFS(n, 0, 0, 0, 0, res, tmp);
        //return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.getPos(0b0100) << endl;


}