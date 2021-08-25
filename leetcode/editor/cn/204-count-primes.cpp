//统计所有小于非负整数 n 的质数的数量。 
//
// 
//
// 示例 1： 
//
// 输入：n = 10
//输出：4
//解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
// 
//
// 示例 2： 
//
// 输入：n = 0
//输出：0
// 
//
// 示例 3： 
//
// 输入：n = 1
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 5 * 10⁶ 
// 
// Related Topics 数组 数学 枚举 数论 👍 731 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        /**
         * 2 ~ 根号x 超时
         */
        //int res = 0;
        //for (int i = 2; i < n; ++i) {
        //    if (isPrime(i)) {
        //        res++;
        //    }
        //}
        //return res;



        /**
         * 埃氏筛法
         * 如果我们在进行顺序遍历时，每取得一个数（排除0、1），
         * 如果将它所有的倍数（排除0、1、本身）都清除，那么，剩下的数是不是必为素数？
         */
        int count = 0;
        //初始默认所有数为质数
        vector<int> signs(n, 1);
        for (int i = 2; i < n; i++) {
            if (signs[i]) {
                count++;
                //j 从 i * i 而不是从 i + i开始
                //i*(2~i-1)时已经被筛去
                if ((long long )i*i<n){
                    for (int j = i * i; j < n; j += i) {
                        //排除不是质数的数
                        signs[j] = 0;
                    }
                }
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    s.countPrimes(10);
    
}