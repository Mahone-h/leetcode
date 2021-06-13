//你现在手里有一份大小为 N x N 的 网格 grid，上面的每个 单元格 都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋单
//元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的。 
//
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - 
//x1| + |y0 - y1| 。 
//
// 如果网格上只有陆地或者海洋，请返回 -1。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[[1,0,1],[0,0,0],[1,0,1]]
//输出：2
//解释： 
//海洋单元格 (1, 1) 和所有陆地单元格之间的距离都达到最大，最大距离为 2。
// 
//
// 示例 2： 
//
// 
//
// 输入：[[1,0,0],[0,0,0],[0,0,0]]
//输出：4
//解释： 
//海洋单元格 (2, 2) 和所有陆地单元格之间的距离都达到最大，最大距离为 4。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length == grid[0].length <= 100 
// grid[i][j] 不是 0 就是 1 
// 
// Related Topics 广度优先搜索 图 
// 👍 200 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        queue<vector<int>> queue;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j]==1){
                    queue.emplace(vector<int>{i, j});
                }
            }
        }
        //都是海洋或都是陆地
        if (queue.empty() || queue.size() == N * N) {
            return -1;
        }
        vector<vector<int>> moves={ {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int distance=-1;
        while (!queue.empty()) {
            distance++;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                vector<int> node=queue.front();
                queue.pop();
                int r = node[0];
                int c = node[1];
                for (vector<int> move : moves) {
                    int r2 = r + move[0];
                    int c2 = c + move[1];
                    if (inArea(grid, r2, c2) && grid[r2][c2] == 0) { //找海
                        grid[r2][c2] = 2;
                        queue.emplace(vector<int>{r2, c2});
                    }
                }
            }
        }
        return distance;
    }
    bool inArea(vector<vector<int>> &grid, int r, int c) {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}