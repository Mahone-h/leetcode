//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 0 <= n <= 3 * 104 
// 0 <= height[i] <= 105 
// 
// Related Topics 栈 数组 双指针 动态规划 
// 👍 2338 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int> &height) {
        //单调递减栈  84是单调增栈
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int h = min(height[i], height[st.top()]) - height[cur];
                ans += (i - st.top() - 1) * h;
            }
            st.push(i);
        }
        return ans;


        //暴力  按列求
//        if (height.size() < 3) {
//            return 0;
//        }
//        int sum = 0;
//深坑  应该是height.size()-1  但是为无符号0-1 溢出 可以加上面的判断
//        for (int i = 1; i + 1 < height.size(); ++i) {
//            //找左边最高
//            int max_left = 0;
//            int max_right = 0;
//            for (int j = 0; j < i; ++j) {
//                max_left = max(max_left, height[j]);
//            }
//            //找右边最高
//            for (int j = i+1; j < height.size(); ++j) {
//                max_right = max(max_right, height[j]);
//            }
//            //找出两端较小的
//            int min_h = min(max_left, max_right);
//            //只有较小的一段大于当前列的高度才会有水，其他情况不会有水
//            if (min_h > height[i]) {
//                sum = sum + (min_h - height[i]);
//            }
//        }
//        return sum;
        //按列优化
        //if (height.size() < 3) {
        //    return 0;
        //}
        //int sum = 0;
        //vector<int> max_left(height.size());
        //vector<int> max_right(height.size());
        //for (int i = 1; i < height.size() - 1; ++i) {
        //    max_left[i] = max(max_left[i - 1], height[i-1]);
        //}
        //for (int i = height.size()-2; i >=0; i--) {
        //    max_right[i] = max(max_right[i + 1], height[i+1]);
        //}
        //for (int i = 1; i < height.size() - 1; ++i) {
        //    int min_h = min(max_left[i], max_right[i]);
        //    if (min_h > height[i]) {
        //        sum += (min_h - height[i]);
        //    }
        //}
        //return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> vec={0,1,0,2,1,0,1,3,2,1,2,1};
    s.trap(vec);
}