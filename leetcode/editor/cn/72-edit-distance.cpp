//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 
// 👍 1649 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]   word1 substr(0...i) 到 word2 substr(0...j) 之间的编辑距离
        //word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]；
        //word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
        //其中，dp[i-1][j-1]+1 表示替换操作，dp[i-1][j]+1 表示删除操作，dp[i][j-1]+1 表示插入操作。

        /**
         *  w1   ....x
         *  w2    ...y
         *  word1[i - 1] == word2[j - 1]   dp[i][j] = dp[i - 1][j - 1]  相同的就不用考虑了
         *
         *  edit(i,j)= min(
         *  edit[i-1][j-1],      x改成y
         *  edit[i-1][j],        x删掉
         *  edit[i][j-1]) + 1    y删掉
         * */

        //https://leetcode-cn.com/problems/edit-distance/solution/edit-distance-by-ikaruga/
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = j;
        }
        //word1[i - 1] == word2[j - 1]   对应dp里面的ij 下标
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min({dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]}) + 1;
            }
        }
        return dp.back().back();


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
}