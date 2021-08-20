//给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。 
//
// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例 1: 
//
// 
//输入: [3,2,1,5,6,4] 和 k = 2
//输出: 5
// 
//
// 示例 2: 
//
// 
//输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
//输出: 4 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= nums.length <= 10⁴ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 👍 1232 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int partition(vector<int> &array, int begin, int end) { //常规的快排划分，但这次是大数在左
        int pivot = end, cur = begin;
        for (int i = begin; i < end; ++i) {
            if (array[i] > array[pivot]) { //从大到小
                swap(array[cur], array[i]);
                cur++;
            }
        }
        swap(array[pivot], array[cur]);
        return cur;
    }

    int quickSort(vector<int> &array, int begin, int end, int k) {
        //if (begin >= end) {
        //    return;
        //}
        int p = partition(array, begin, end);
        if (p - begin + 1 == k) return array[p];
        else if (p - begin + 1 > k) return quickSort(array, begin, p - 1, k);  //在左边
        else return quickSort(array, p + 1, end, k - (p - begin + 1));         //在右边 但是需要减去左边更大的数字的数量
    }

    int findKthLargest(vector<int> &nums, int k) {
        //priority_queue<int, vector<int>, less<int>> maxHeap;
        //for (int x : nums)
        //    maxHeap.push(x);
        //for (int _ = 0; _ < k - 1; _ ++)
        //    maxHeap.pop();
        //return maxHeap.top();
        return quickSort(nums, 0, nums.size() - 1, k);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}