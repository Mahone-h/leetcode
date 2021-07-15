//给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。 
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯 
// 👍 615 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> res;

    bool isValid(string &s) {
        if (s.empty() || s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backTrack(string path, string s, int count) {
        if (count == 3 && isValid(s)) {
            res.emplace_back(path + s);
        }
        for (int i = 1; i <= 3 && i < s.size(); ++i) {
            if (s.size() - i > 3 * (4 - count)) continue;
            string tmp = s.substr(0, i);
            if (isValid(tmp)) {
                backTrack(path + tmp + '.', s.substr(i), count + 1);
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12) {
            return res;
        }
        backTrack("", s, 0);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}