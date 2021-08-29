#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        //dp[i][j]
        //if s[i-1]==s[j-1] dp[i][j]=dp[i-1][j-1]+1
        //else dp[i-1][k-1]==0
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int end = 0;
        int max_len = 0;
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max_len) {
                        max_len = dp[i][j];
                        end = i - 1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return str1.substr(end - max_len + 1, max_len);

    }
};