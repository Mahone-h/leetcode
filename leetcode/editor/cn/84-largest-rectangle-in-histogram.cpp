//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 
//
// 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。 
//
// 
//
// 
//
// 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。 
//
// 
//
// 示例: 
//
// 输入: [2,1,5,6,2,3]
//输出: 10 
// Related Topics 栈 数组 
// 👍 1329 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        //暴力1  时间o(n^3)
        /*int maxArea = 0;
        int minHeight;
        for (int i = 0; i < heights.size(); ++i) {
            for (int j = i; j < heights.size(); ++j) {
                minHeight = INT32_MAX;
                for (int k = i; k <= j; ++k) {
                    minHeight = min(minHeight, heights[k]);
                }
                maxArea = max(maxArea,minHeight * (j - i + 1));
            }
        }
        return maxArea;*/
        //暴力2_1  O(n^2)    枚举宽  宽度每次改变  高度找最小
//        int maxArea = 0;
//        int minHeight;
//        for (int i = 0; i < heights.size(); ++i) {
//            minHeight = INT_MAX;
//            for (int j = i; j < heights.size(); ++j) {
//                minHeight = min(minHeight, heights[j]);
//                maxArea = max(maxArea,minHeight * (j - i + 1));
//            }
//        }
//        return maxArea;
        //暴力2_2 O(n^2)    枚举高 高度固定 向左右两边扩散 找高度比当前高度小的
        /* int maxArea = 0;
         for (int i = 0; i < heights.size(); ++i) {
             // 枚举高
             int height = heights[i];
             int left = i, right = i;
             // 确定左右边界
             while (left - 1 >= 0 && heights[left - 1] >= height) {
                 --left;
             }
             while (right + 1 < n && heights[right + 1] >= height) {
                 ++right;
             }
             // 计算面积
             maxArea = max(maxArea, (right - left + 1) * height);
         }
         return maxArea;*/
        // 栈   左右加哨兵
        if (heights.size() == 0) return 0;
        if (heights.size() == 1) return heights[0];
        int ans = 0;
        //类似 枚举高 高度固定 找宽
        // 先放入哨兵，在循环里就不用做非空判断 有了这两个柱形：
        //左边的柱形（第 1 个柱形）由于它一定比输入数组里任何一个元素小，它肯定不会出栈，因此栈一定不会为空；
        //右边的柱形（第 2 个柱形）也正是因为它一定比输入数组里任何一个元素小，它会让所有输入数组里的元素出栈（第 1 个哨兵元素除外）。
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        st.push(0);   //省去判断st非空
        for (int i = 1; i < heights.size(); ++i) {
            while (heights[i] < heights[st.top()]) { //向右找到第一个小于栈顶的元素
                int height = heights[st.top()];
                st.pop();
                ans = max(ans, height * (i - st.top() - 1));
            }
            st.push(i);
        }
        return ans;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> vec={2,1,5,6,2,3};
    s.largestRectangleArea(vec);
}