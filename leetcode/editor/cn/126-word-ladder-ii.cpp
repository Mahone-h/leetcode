//按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s
//1 -> s2 -> ... -> sk 这样的单词序列，并满足： 
//
// 
// 
// 
// 每对相邻的单词之间仅有单个字母不同。 
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单
//词。 
// sk == endWord 
// 
//
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的
// 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g","cog"]
//输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//解释：存在 2 种最短的转换序列：
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g"]
//输出：[]
//解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 7 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有单词 互不相同 
// 
// 
// 
// Related Topics 广度优先搜索 数组 字符串 回溯算法 
// 👍 438 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        vector<vector<string>> res;
        if (wordSet.empty() || wordSet.find(endWord) == wordSet.end()) {
            return res;
        }
        queue<string> queue;
        queue.emplace(beginWord);
        wordSet.erase(beginWord);
        unordered_map<string,unordered_set<string>> bfsMap;
        //bfs 找所有顶点相邻
        int ifFound=0;
        while (!queue.empty()) {
            int n = queue.size();
            unordered_set<string> subSet;
            while (n--) {
                string cur = queue.front();
                string original=cur;
                queue.pop();
                for (int i = 0; i < cur.size(); ++i) {
                    char tmp = cur[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        if (j == tmp) {
                            continue;
                        }
                        cur[i] = j;
                        if (wordSet.count(cur)) {
                            if (cur == endWord) {
                                ifFound=1;
                            } else{
                                queue.push(cur);
                                subSet.emplace(cur);
                            }
                            bfsMap[original].emplace(cur);
                        }
                    }
                    cur[i]=tmp;
                }
            }
            for (string tmp:subSet) {
                wordSet.erase(tmp);
            }
            if (ifFound == 1) {
                break;
            }
        }
        vector<string> path={beginWord};
        dfs(res, beginWord, endWord, bfsMap,path);
        return res;
    }

    void dfs(vector<vector<string>>& res,string beginWord,string endWord,unordered_map<string,unordered_set<string>>& map,vector<string> &path){
        if (beginWord == endWord) {
            res.emplace_back(path);
            return;
        }
        //dfs过程中没找到到
        if (map.count(beginWord) == 0) {
            return;
        }
        for (string tmp:map.find(beginWord)->second) {
            path.emplace_back(tmp);
            dfs(res, tmp, endWord, map, path);
            path.pop_back();
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<string> input = {"ted","tex","red","tax","tad","den","rex","pee"};
    s.findLadders("red", "tax", input);
}