//给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。 
//
// 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。 
//
// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿
//的周长。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
//输出：16
//解释：它的周长是上面图片中的 16 个黄色的边 
//
// 示例 2： 
//
// 
//输入：grid = [[1]]
//输出：4
// 
//
// 示例 3： 
//
// 
//输入：grid = [[1,0]]
//输出：4
// 
//
// 
//
// 提示： 
//
// 
// row == grid.length 
// col == grid[i].length 
// 1 <= row, col <= 100 
// grid[i][j] 为 0 或 1 
// 
// Related Topics 哈希表 
// 👍 409 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int islandPerimeter(vector<vector<int>> &grid) {
        /**
         * dfs
         * 判断碰到了哪个边
         * 超出范围  + 碰到海洋
         */
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, i, j);
                }
            }
        }
        return 0;
        /**
         *  一块土地原则上会带来 4 个周长，但岛上的土地存在接壤，每一条接壤，会减掉 2 个边长。
         *  所以，总周长 = 4 * 土地个数 - 2 * 接壤边的条数。
         *  扩散找
         */
        //int land = 0;//土地数量
        //int border = 0;//接壤边的条数
        //
        //for (int i = 0; i < grid.size(); ++i) {
        //    for (int j = 0; j < grid[0].size(); ++j) {
        //        if (grid[i][j] == 1) {
        //            ++land;
        //            if (i < grid.size() - 1 && grid[i + 1][j] == 1) {//该土地的下方有土地就说明下面这条边就是接壤边
        //                ++border;
        //            }
        //            if (j < grid[0].size() - 1 && grid[i][j + 1] == 1) {//该土地的右方有土地就说明右面这条边就是接壤边
        //                ++border;
        //            }
        //        }
        //    }
        //}
        //return 4 * land - 2 * border;

    }

    int dfs(vector<vector<int>> &grid, int r, int c) {
        //差不多。
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) {
            return 1;
        }
        if (grid[r][c] == 0) {
            return 1;
        }
        if (grid[r][c] == 2) {
            return 0;
        }
        grid[r][c] = 2;
        return  dfs(grid, r - 1, c)
               + dfs(grid, r + 1, c)
               + dfs(grid, r, c - 1)
               + dfs(grid, r, c + 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}