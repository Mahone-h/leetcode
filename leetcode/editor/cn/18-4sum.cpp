//给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c +
// d 的值与 target 相等？找出所有满足条件且不重复的四元组。 
//
// 注意：答案中不可以包含重复的四元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,0,-1,0,-2,2], target = 0
//输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [], target = 0
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 200 
// -109 <= nums[i] <= 109 
// -109 <= target <= 109 
// 
// Related Topics 数组 双指针 排序 
// 👍 898 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        /**
         * 降到n^3   target是任意的 不是0  不能>target 则返回
         */
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return {};
        for (int i = 0; i < nums.size() - 3; ++i) {
            //if (nums[i] > target) {  //[1,-2,-5,-4,-3,3,3,5]   -11
            //    return res;          //res  [[-5,-4,-3,1]] 1进来就直接没了。
            //}
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int l = j + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[i] + nums[j] + nums[l] + nums[r] < target) {
                        l++;
                    } else if (nums[i] + nums[j] + nums[l] + nums[r] > target) {
                        r--;
                    } else {
                        res.emplace_back(vector<int>{nums[i], nums[j],nums[l], nums[r]});
                        l++;
                        r--;
                        while (l < r && nums[l] == nums[l - 1]) l++;
                        while (l < r && nums[r] == nums[r + 1]) r--;
                    }
                }

            }
        }
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}