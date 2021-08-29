//给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不
//是 4 次，则需要在最终答案中包含该字符 3 次。 
//
// 你可以按任意顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 输入：["bella","label","roller"]
//输出：["e","l","l"]
// 
//
// 示例 2： 
//
// 输入：["cool","lock","cook"]
//输出：["c","o"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 100 
// 1 <= A[i].length <= 100 
// A[i][j] 是小写字母 
// 
// Related Topics 数组 哈希表 字符串 👍 235 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int hash[26] = {0};
        for (int i = 0; i < words[0].size(); ++i) {
            hash[words[0][i] - 'a']++;
        }
        int hash2[26] = {0};
        for (int i = 1; i < words.size(); ++i) {
            memset(hash2, 0, sizeof(int) * 26);
            for (int j = 0; j < words[i].size(); ++j) {
                hash2[words[i][j] - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                hash[j] = min(hash[j],hash2[j]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i) {
            while (hash[i]-- > 0) {
                res.emplace_back(string(1,i + 'a'));  //char to string
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