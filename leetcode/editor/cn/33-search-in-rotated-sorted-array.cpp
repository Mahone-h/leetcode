//整数数组 nums 按升序排列，数组中的值 互不相同 。 
//
// 在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[
//k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2
//,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。 
//
// 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [4,5,6,7,0,1,2], target = 0
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：nums = [4,5,6,7,0,1,2], target = 3
//输出：-1 
//
// 示例 3： 
//
// 
//输入：nums = [1], target = 0
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 5000 
// -10^4 <= nums[i] <= 10^4 
// nums 中的每个值都 独一无二 
// 题目数据保证 nums 在预先未知的某个下标上进行了旋转 
// -10^4 <= target <= 10^4 
// 
//
// 
//
// 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？ 
// Related Topics 数组 二分查找 
// 👍 1395 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * 1.暴力 还原 O(logn) ->升序 -> 二分
     * 2.直接二分
     */
    int search(vector<int> &nums, int target) {
        /**
         * 还原
         */
        //if (nums.empty()) {
        //    return -1;
        //}
        //if (nums.size() == 1) {
        //    return nums[0] == target ? 0 : -1;
        //}
        //
        //int left = 0, right = nums.size() - 1;
        //while (left < right) {
        //    int mid = left + (right - left) / 2;
        //    if (nums[mid] < nums[right]) {
        //        right = mid;
        //    } else {
        //        left = mid + 1;
        //    }
        //}
        ////nums[left] 最小值
        //if (left == 0 || nums[0] > target) {
        //    right = nums.size() - 1;
        //} else {
        //    right = left - 1;
        //    left = 0;
        //}
        //while (left <= right) {
        //    int mid = left + (right - left) / 2;
        //    if (nums[mid] == target) {
        //        return mid;
        //    } else if (nums[mid] > target) {
        //        right = mid - 1;
        //    } else {
        //        left = mid + 1;
        //    }
        //}
        //return -1;
        /**
         * 直接二分   找哪部分有序
         */
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {   //已经判断了相等。
                return mid;
            }
            //一直在有序的部分中找
            if (nums[left] <= nums[mid]) {//什么时候=？  剩两个元素 剩一个上面就走了
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left=mid+1;
                } else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> tmp = {1,3};
    s.search(tmp, 3);
}