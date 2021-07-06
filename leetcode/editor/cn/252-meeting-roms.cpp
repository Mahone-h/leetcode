//力扣 252. 会议室
//难度：Easy
//
// 给定一个会议时间安排的数组 intervals ，每个会议时间都会包括开始和结束的时间
// intervals[i] = [starti, endi] ，请你判断一个人是否能够参加这里面的全部会议。
//
//示例 1:：
//输入: intervals = [[0,30],[5,10],[15,20]]
//输出: false
//解释: 存在重叠区间，一个人在同一时刻只能参加一个会议。
//
//示例 2:：
//输入: intervals = [[7,10],[2,4]]
//输出: true
//解释: 不存在重叠区间。


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:

    bool canAttendMeetings(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                return false;
            }
        }
        return true;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.isAnagram("anagram", "nagaram");
}