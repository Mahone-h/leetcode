//给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。如果不存在最后一个单词，请返回 0 。 
//
// 单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "Hello World"
//输出：5
// 
//
// 示例 2： 
//
// 
//输入：s = " "
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 仅有英文字母和空格 ' ' 组成 
// 
// Related Topics 字符串 
// 👍 327 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int count = 0;
        //从右向左 从第一个不是“ ”开始到下一个“ ”
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && count != 0) {
                break;
            }
            if (s[i] != ' ') {
                count++;
            }
        }
        return count;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}