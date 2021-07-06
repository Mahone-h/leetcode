//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 104 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 104 
// 
// Related Topics 数组 排序 
// 👍 985 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //默认的排序结果是第一维从小到大，在第一维相同时第二维从小到大排列。
        if (intervals.empty()) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back()[1]<intervals[i][0]) {
                res.emplace_back(intervals[i]);
            } else{
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}