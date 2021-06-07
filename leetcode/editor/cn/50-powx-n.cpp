//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 2.00000, n = 10
//输出：1024.00000
// 
//
// 示例 2： 
//
// 
//输入：x = 2.10000, n = 3
//输出：9.26100
// 
//
// 示例 3： 
//
// 
//输入：x = 2.00000, n = -2
//输出：0.25000
//解释：2-2 = 1/22 = 1/4 = 0.25
// 
//
// 
//
// 提示： 
//
// 
// -100.0 < x < 100.0 
// -231 <= n <= 231-1 
// -104 <= xn <= 104 
// 
// Related Topics 数学 二分查找 
// 👍 654 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double quickMul(double x, long long N) {
        if (N == 0) {
            return 1.0;
        }
        double y = quickMul(x, N / 2);
        return N % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        /**
         * 递归
         */
        //long long N = n;
        //return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
        /**
         * 快速幂
         */
        if (x == 0) {
            return 0;
        }
        long long N = n;    //n=-n越界
        double res = 1.0;
        if (n < 0) {
            x = 1 / x;
            N = -N;
        }
        while (N > 0) {
            if ((N & 1) == 1) {   //N % 2 == 1
                res *= x;
            }
            x *= x;
            N >>= 1;// N/=2
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}