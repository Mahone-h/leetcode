//一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。 
//
// 给你石子的位置列表 stones（用单元格序号 升序 表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。 
//
// 开始时， 青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格 1 跳至单元格 2 ）。 
//
// 如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1 个单位。 另请注意，青蛙只能向前方（终点的方向）跳跃。
// 
//
// 
//
// 示例 1： 
//
// 
//输入：stones = [0,1,3,5,6,8,12,17]
//输出：true
//解释：青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2 个单位到第 4 块石子, 然
//后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 个石子（即最后一块石子）。 
//
// 示例 2： 
//
// 
//输入：stones = [0,1,2,3,4,8,9,11]
//输出：false
//解释：这是因为第 5 和第 6 个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。 
//
// 
//
// 提示： 
//
// 
// 2 <= stones.length <= 2000 
// 0 <= stones[i] <= 231 - 1 
// stones[0] == 0 
// 
// Related Topics 数组 动态规划 
// 👍 346 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canCross(vector<int> &stones) {
        //0,1,3,5,6,8,12,17
        /***分治 递归+记忆化*/
        //unordered_map<int, int> map;
        //unordered_map<int, bool> path;  //boolean[石子列表下标][跳跃步数]
        //for (int i = 0; i < stones.size(); ++i) map[stones[i]] = i;
        //if (stones[1] != 1) return false;
        //return dfs(stones, map, path, 1, 1);
        /**
         * dp[i][k]  表示能否从前一个石子 跳k到现在
         * 第一维为可变参数 u，代表石子列表的下标，范围为数组 stones 长度；
         * 第二维为可变参数 k，代表上一步的的跳跃步长，前面也分析过了，最多不超过数组 stones 长度。
         * dp[i][k]=dp[j][k−1] || dp[j][k] || dp[j][k+1]  j∈[0,i−1]
         * */
        int n = stones.size();
        if (stones[1] != 1) return false;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        dp[1][1] = 1;
        for (int i = 2; i < n; ++i) {
            for (int j = 1; j < i; ++j) {
                int k = stones[i] - stones[j];
                if (k <= j + 1) {
                    dp[i][k] = dp[j][k - 1] || dp[j][k] || dp[j][k + 1];
                }
            }
        }
        for (int i = 1; i < n; i++) {
            if (dp[n - 1][i]) return true;
        }
        return false;

    }

    bool dfs(vector<int> &stones, unordered_map<int, int> &map, unordered_map<int, bool> &path, int idx, int k) {
        if (idx == stones.size() - 1) return true;
        int key = idx * 2000 + k;
        if (path.count(key)) return false;//访问过 没找到 肯定false
        for (int i = -1; i <= 1; ++i) {
            if (k + i == 0) continue;
            int next = stones[idx] + k + i;
            if (map.count(next)) {
                bool cur = dfs(stones, map, path, map[next], k + i);
                path[key] = cur;
                if (cur) return true;
            }
        }
        path[key] = false;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> tmp = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << s.canCross(tmp) << endl;
}