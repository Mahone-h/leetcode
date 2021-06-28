//给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充
//。
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X"
//,"X"]]
//输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
//解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都
//会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
// 
//
// 示例 2： 
//
// 
//输入：board = [["X"]]
//输出：[["X"]]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 200 
// board[i][j] 为 'X' 或 'O' 
// 
// 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 
// 👍 554 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class UnionFind {
private:
    int count;
    vector<int> parent;
public:
    UnionFind(int n) {
        count = n;
        for (int i = 0; i < n; ++i) {
            parent.emplace_back(i);
        }
    }

    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            parent[root_y] = root_x;
            count--;
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int find(int x) { //返回x的根
        //while (parent[x] != x) {
        //    x = parent[x];
        //}
        //路径优化
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    int get_count(){
        return count;
    }


};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /**
         * 从边界O开始 标记 联通的
         * 最后遍历 标记的改回O 其他的o改为x
         * DFS
         */
        //if (board.empty()) return;
        //int m = board.size(), n = board[0].size();
        //for (int i = 0; i < m; ++i) {
        //    for (int j = 0; j < n; ++j) {
        //        bool isEdge = i == 0 || j == 0 || i == m - 1 || j == n - 1;
        //        if (isEdge && board[i][j] == 'O') {
        //            dfs(board, i, j);
        //        }
        //    }
        //}
        //for (int i = 0; i < m; ++i) {
        //    for (int j = 0; j < n; ++j) {
        //        if (board[i][j] == 'O') {
        //            board[i][j] = 'X';
        //        }else if (board[i][j] == '#') {
        //            board[i][j] = 'O';
        //        }
        //    }
        //}
        /**并查集      慢！*/
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        //所有边界上的O都和 uf[0] 连接
        UnionFind uf(m * n + 1);
        vector<vector<int>> move={{1,0},{-1,0},{0,1},{0,-1}};
        int dummy = m * n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j]=='O') {
                    if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                        uf.merge(i * n + j, dummy);
                    } else{
                        for (int k = 0; k < 4; ++k) {
                            int x = i + move[k][0];
                            int y = j + move[k][1];
                            if (board[x][y]=='O'){
                                uf.merge(x * n + y, i * n + j);
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!uf.connected(i*n+j, dummy)) {
                    board[i][j] = 'X';
                }
                cout << board[i][j]<<" ";
            }
            cout << endl;
        }

    }
    void dfs(vector<vector<char>>& board,int i,int j){
        if (i < 0 || j < 0 || i >= board.size()  || j >= board[0].size() || board[i][j] == 'X' || board[i][j] == '#') {
            return;
        }
        board[i][j] = '#';
        dfs(board, i+1, j);
        dfs(board, i-1, j);
        dfs(board, i, j+1);
        dfs(board, i, j-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<char>> board={{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    s.solve(board);
}