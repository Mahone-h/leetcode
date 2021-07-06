//给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。 
//
// 题目数据保证总会存在一个数值和不超过 k 的矩形区域。 
//
// 
//
// 示例 1：
//
// 
//输入：matrix = [[1,0,1],[0,-2,3]], k = 2
//输出：2
//解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[2,2,-1]], k = 3
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -100 <= matrix[i][j] <= 100 
// -105 <= k <= 105 
// 
//
// 
//
// 进阶：如果行数远大于列数，该如何设计解决方案？ 
// Related Topics 数组 二分查找 动态规划 矩阵 有序集合 
// 👍 334 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        /** 前缀和 暴力 超时*/
        //int m = matrix.size(), n = matrix[0].size();
        //vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
        //for(int i = 1; i <= m; i++){
        //    for(int j = 1; j <= n; j++){
        //        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
        //    }
        //}
        //int ans = INT_MIN;
        //for(int i = 1; i <= m; i++){
        //    for(int j = 1; j <= n; j++){
        //        for(int p = i; p <= m; p++){
        //            for(int q = j; q <= n; q++){
        //                int cur = sum[p][q] - sum[i - 1][q] - sum[p][j - 1] + sum[i - 1][j - 1];
        //                if(cur <= k){
        //                    ans = max(ans,cur);
        //                }
        //            }
        //        }
        //    }
        //}
        //return ans;
        /** 优化  枚举4个边 进行优化
         * 固定上下  枚举左右
         * Sum(i,j)=sum[j]−sum[i−1] ⩽ k
         * sum[i−1] >=  sum[j]-k
         * sum[j]−sum[i−1] 最小 遍历j的时候找 sum[i−1] 最小
         * */
        int m = matrix.size(), n = matrix[0].size();  //题目说了>=1
        int res = INT_MIN;
        for (int i = 0; i < m; ++i) {
            vector<int> sums(n, 0);  //上界遍历后重置
            for (int j = i; j < m; ++j) {
                //遍历上下界
                for (int l = 0; l < n; ++l) {
                    sums[l] += matrix[j][l];
                }
                set<int> sumSet{0}; // 左边界i=0  所有数都要
                int s = 0;
                for (int &num:sums) {
                    s += num;
                    auto it = sumSet.lower_bound(s - k);
                    if (it != sumSet.end()) {
                        res = max(res, s - *it);
                    }
                    sumSet.emplace(s);
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
    vector<vector<int>> matrix{{2, 2, -1}};
    cout << s.maxSumSubmatrix(matrix, 3)<< endl;
}