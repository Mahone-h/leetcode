//给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。 
//
// 进阶：不要 使用任何内置的库函数，如 sqrt 。 
//
// 
//
// 示例 1： 
//
// 
//输入：num = 16
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：num = 14
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= num <= 2^31 - 1 
// 
// Related Topics 数学 二分查找 
// 👍 223 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 0 || num == 1) {
            return true;
        }
        int left = 2, right = num / 2;
        //==的时候最后判断下。
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == num / mid && num % mid == 0) {//mid == num / mid
                return true;
            } else if (mid > num / mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.isPerfectSquare(5);
}