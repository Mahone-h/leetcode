//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法 
// 👍 592 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    //void helper(int start, int &n, int &k, vector<int> &vec, vector<vector<int>> &res) {
    //    if (vec.size() == k) {
    //        res.emplace_back(vec);
    //        return;
    //    }
    //    for (int i = start; i <= n - (k - vec.size()) + 1; ++i) {
    //        vec.emplace_back(i);
    //        helper(i + 1, n, k, vec, res);
    //        vec.pop_back();
    //    }
    //}
    //
    //vector<vector<int>> combine(int n, int k) {
    //    vector<vector<int>> res;
    //    if (k <= 0 || n < k) {
    //        return res;
    //    }
    //    vector<int> vec;
    //    helper(1, n, k, vec, res);
    //    return res;
    //}
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> res;
        if (k <= 0 || n < k) {
            return res;
        }
        vector<int> vec;
        dfs(1, n, k, vec, res);
        return res;
    }
    void dfs(int start, int &n, int k, vector<int> &vec, vector<vector<int>> &res){
        if (k == 0) {
            res.emplace_back(vec);
            return;
        }
        if (n - start + 1 < k) {
            return;
        }
        //不选当前
        dfs(start + 1, n, k, vec, res);
        //选当前
        vec.emplace_back(start);
        dfs(start + 1, n, k - 1, vec, res);
        vec.pop_back();
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

    vector<vector<int>> res = s.combine(4, 2);
    for (int i = 0; i < res.size(); ++i) {
        cout << "[";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j];
        }
        cout << "]";
    }
}