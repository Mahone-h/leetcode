//
// 
// 有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连
//。 
//
// 省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。 
//
// 给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 
//isConnected[i][j] = 0 表示二者不直接相连。 
//
// 返回矩阵中 省份 的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 200 
// n == isConnected.length 
// n == isConnected[i].length 
// isConnected[i][j] 为 1 或 0 
// isConnected[i][i] == 1 
// isConnected[i][j] == isConnected[j][i] 
// 
// 
// 
// Related Topics 深度优先搜索 并查集 
// 👍 564 👎 0


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
    int findCircleNum(vector<vector<int>> &isConnected) {
        /**
         * 1.DFS BFS 染色
         * 2.disjoint set 并查集
         * a. N->各自独立
         * b. 遍历关系矩阵  合并
         * c.有多少孤立的集合
         */
        /**DFS*/
        //vector<int> visited(isConnected.size());
        //int res = 0;
        //for (int i = 0; i < isConnected.size(); ++i) {
        //    if (!visited[i]) {
        //        res++;
        //        dfs(isConnected, visited, i);
        //    }
        //}
        //return res;
        /** BFS*/
        //int n = isConnected.size();
        //vector<int> visited(n);
        //int res = 0;
        //queue<int> q;
        //for (int i = 0; i < n; ++i) {
        //    if (!visited[i]) {
        //        q.push(i);
        //        visited[i] = 1;
        //        while (!q.empty()) {
        //            int j = q.front(); q.pop();
        //            for (int k = 0; k < n; ++k) {
        //                if (isConnected[j][k] == 1 && !visited[k]) {
        //                    q.push(k);
        //                    visited[k]=1;
        //                }
        //            }
        //        }
        //        res++;
        //    }
        //}
        //return res;
        /**uf*/
        UnionFind uf(isConnected.size());
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected.size(); ++j) {
                if (isConnected[i][j] == 1) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.get_count();
    }

    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}