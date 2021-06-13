//实现 int sqrt(int x) 函数。 
//
// 计算并返回 x 的平方根，其中 x 是非负整数。 
//
// 由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。 
//
// 示例 1: 
//
// 输入: 4
//输出: 2
// 
//
// 示例 2: 
//
// 输入: 8
//输出: 2
//说明: 8 的平方根是 2.82842..., 
//     由于返回类型是整数，小数部分将被舍去。
// 
// Related Topics 数学 二分查找 
// 👍 692 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int mySqrt(int x) {
        /**
         * 二分   直接模版先。
         */
        if (x == 0 || x == 1) {
            return x;
        }
        int left = 1, right = x/2;
        //==的时候最后判断下。
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid < x / mid) { //防止溢出
                left = mid + 1;
            } else if (mid > x / mid) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        //r一定会停在mid**2 <= x的最大那个mid的位置，因为mid**2=x的mid如果存在的话在上面
        // 就已经返回了，所以这里只需要返回r就好了
        return right;
        /**
         * 牛顿迭代法
         */
        //if (x == 0) {
        //    return 0;
        //}
        //double C = x, x0 = x;
        //while (true) {
        //    double xi = 0.5 * (x0 + C / x0);
        //    if (fabs(x0 - xi) < 1e-7) {
        //        break;
        //    }
        //    x0 = xi;
        //}
        //return int(x0);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.mySqrt(8);
}