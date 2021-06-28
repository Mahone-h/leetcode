//给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。 
//
// 你需要返回给定数组中的重要翻转对的数量。 
//
// 示例 1: 
//
// 
//输入: [1,3,2,3,1]
//输出: 2
// 
//
// 示例 2: 
//
// 
//输入: [2,4,3,5,1]
//输出: 3
// 
//
// 注意: 
//
// 
// 给定数组的长度不会超过50000。 
// 输入数组中的所有数字都在32位整数的表示范围内。 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 
// 👍 288 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    int mergeSort(vector<int> &array, int left, int right) {
        if (left >= right) {
            return 0;
        }
        //int mid = left + ((right - left) >> 1);
        //int res = mergeSort(array, left, mid) + mergeSort(array, mid + 1, right);
        //vector<int> tmp(right - left + 1);
        //int i = left, t = left, c = 0;
        //for (int j = mid+1; j <= right; j++,c++) {
        //    //nums[i] > 2*nums[j]
        //    //不满条件 i++ 左半部分有序 有一个满足剩下的都满足
        //    while (i <= mid && array[i] <= 2L* array[j]) i++;
        //    res += mid - i + 1;
        //    //归并 左边小于j 的加到新数组
        //    while (t<=mid && array[t]<array[j]) tmp[c++] = array[t++];
        //    tmp[c] = array[j];//下一个j>=当前j
        //}
        //while (t <= mid) tmp[c++] = array[t++];//剩余的赋值
        //copy(tmp.begin(), tmp.end(), array.begin() + left);
        //return res;
        int mid = left + ((right - left) >> 1);
        int res = mergeSort(array, left, mid) + mergeSort(array, mid + 1, right);
        for (int i = left,j=mid+1; i <=mid; ++i) {
            //左右两部分有序  array[i]  >2* array[j]  符合条件 j++
            while (j <= right && array[i]  >2L* array[j]) {
                j++;
            }
            //j已经到right  i还没到 因为升序  每次都得+
            res += j-(mid+1);
        }
        sort(array.begin() + left, array.begin() + right + 1);
        return res;
    }
    int reversePairs(vector<int>& nums) {
        /**
         * 1.暴力 两个嵌套循环 O(n^2)
         * 2.merge-sort O(nlogn)
         */
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<int> tmp={2,4,3,5,1};
    s.reversePairs(tmp);


}