//编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性： 
//
// 
// 每行中的整数从左到右按升序排列。 
// 每行的第一个整数大于前一行的最后一个整数。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
//输出：false
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
// -104 <= matrix[i][j], target <= 104 
// 
// Related Topics 数组 二分查找 
// 👍 443 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        /**
         * 两次二分
         */
        //int m = matrix.size() - 1;
        //int n = matrix[0].size() - 1;
        //int l1 = 0, r1 = matrix.size() - 1, l2 = 0, r2 = n;
        //while (l1 < r1) {
        //    int mid = (l1 + r1) / 2;
        //    if (target <= matrix[mid][n]) {
        //        r1 = mid;
        //    } else {
        //        l1 = mid + 1;
        //    }
        //}
        //while (l2 <= r2) {
        //    int mid = (l2 + r2) / 2;
        //    if (matrix[l1][mid] == target) {
        //        return true;
        //    }
        //    if (matrix[l1][mid] < target) {
        //        l2 = mid + 1;
        //    } else {
        //        r2 = mid - 1;
        //    }
        //}
        //return false;
        /**
         * 一次二分
         */
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int x = matrix[mid / n][mid % n];
            if (x < target) {
                left = mid + 1;
            } else if(x>target){
                right = mid - 1;
            } else{
                return true;
            }
        }
        return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> tmp;
    tmp.emplace_back(vector<int>{1, 3, 5, 7});
    tmp.emplace_back(vector<int>{10, 11, 16, 20});
    tmp.emplace_back(vector<int>{23, 30, 34, 60});
    s.searchMatrix(tmp, 16);


}