//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。 
//
// 
//
// 示例： 
//
// s = "leetcode"
//返回 0
//
//s = "loveleetcode"
//返回 2
// 
//
// 
//
// 提示：你可以假定该字符串只包含小写字母。 
// Related Topics 队列 哈希表 字符串 计数 
// 👍 413 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int,int> map;
        for (char &c:s) {
            map[c]++;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (map[s[i]] == 1) {
                return i;
            }
        }
        return -1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}