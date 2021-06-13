//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,-1], k = 1
//输出：[1,-1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [9,11], k = 2
//输出：[11]
// 
//
// 示例 5： 
//
// 
//输入：nums = [4,-2], k = 2
//输出：[4] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 1 <= k <= nums.length 
// 
// Related Topics 堆 Sliding Window 
// 👍 967 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //暴力O(n*k)
        /*vector<int> res;
        for (int i = 0; i <= nums.size() - k; ++i) {
            int maxValue = INT_MIN;
            for (int j = i; j < i+k; ++j) {
                maxValue = max(nums[j], maxValue);
            }
            res.emplace_back(maxValue);
        }
        return res;*/
        //优先队列  堆
//        priority_queue<pair<int,int>> q;
//        for (int i = 0; i < k; ++i) {
//            q.emplace(nums[i], i);
//        }
//        vector<int> res = {q.top().first};
//        for (int i = k; i < nums.size(); ++i) {
//            q.emplace(nums[i], i);
              //不在窗口中的移除
//            while (q.top().second <= i - k) {
//                q.pop();
//            }
//            res.emplace_back(q.top().first);
//        }
//        return res;
        //单调队列
        if (nums.empty() || nums.size() < 2) {
            return nums;
        }
        // 双向队列 保存当前窗口最大值的数组位置 保证队列中数组位置的数值按从大到小排序
        deque<int> dq;
        vector<int> ans;
        //先构建窗口
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
        }
        ans.emplace_back(nums[dq.front()]);
        for (int i = k; i < nums.size(); ++i) {
            // 保证从大到小 如果前面数小则需要依次弹出，直至满足要求
            if (!dq.empty() &&dq.front() <= i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            ans.emplace_back(nums[dq.front()]);
        }
        return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> vec={1,3,-1,-3,5,3,6,7};
    s.maxSlidingWindow(vec, 3);
}