//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重
//复的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：nums = [0]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= nums.length <= 3000 
// -105 <= nums[i] <= 105 
// 
// Related Topics 数组 双指针 
// 👍 3267 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        /**
         * 暴力 超时
         */
        //if(nums.size() < 3){
        //    return {};
        //}
        //set<vector<int>> set; //不能用unordered
        //sort(nums.begin(), nums.end());
        //for(int i = 0; i < nums.size()-2; i++){
        //    for(int j = i+1; j < nums.size()-1; j++){
        //        for(int k = j+1; k < nums.size(); k++){
        //            if(nums[i] + nums[j] + nums[k] == 0){
        //                set.emplace(vector<int>{{nums[i], nums[j], nums[k]}});
        //            }
        //        }
        //    }
        //}
        //vector<vector<int>> res(set.begin(),set.end());
        //return res;
        /**
         * 夹逼 排序加双指针
         *
         * i+l+r=0
         * l=i+1  r=nums.size-1
         */

        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 3) { return res; }
        int l, r;
        // 找出a + b + c = 0
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size() - 2; i++) {
            // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {//相等
                continue;
            }
            l = i + 1;
            r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    res.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums={-1,0,1,2,-1,-4};
    s.threeSum(nums);

}