//字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列： 
//
// 
// 序列中第一个单词是 beginWord 。 
// 序列中最后一个单词是 endWord 。 
// 每次转换只能改变一个字母。 
// 转换过程中的中间单词必须是字典 wordList 中的单词。 
// 
//
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，找到从 beginWord 到 endWord 的 最短转换序列 中
//的 单词数目 。如果不存在这样的转换序列，返回 0。 
// 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g","cog"]
//输出：5
//解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g"]
//输出：0
//解释：endWord "cog" 不在字典中，所以无法进行转换。 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 10 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有字符串 互不相同 
// 
// Related Topics 广度优先搜索 
// 👍 776 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /**
         * BFS  不使用visited  wordlist直接删掉就行了
         */
        //unordered_set<string> wordSet(wordList.begin(),wordList.end());
        //if (wordSet.empty() || wordSet.find(endWord) == wordSet.end()) {
        //    return 0;
        //}
        //queue<string> queue;
        //queue.emplace(beginWord);
        //wordSet.erase(beginWord);
        //int step = 1;
        //while (!queue.empty()) {
        //    int n = queue.size();
        //    while (n--) {
        //        string cur = queue.front();
        //        queue.pop();
        //        for (int i = 0; i < cur.size(); ++i) {
        //            char tmp = cur[i];
        //            for (char j = 'a'; j <= 'z'; ++j) {
        //                if (j == tmp) {
        //                    continue;
        //                }
        //                cur[i] = j;
        //                if (wordSet.find(cur) != wordSet.end()) {
        //                    if (cur == endWord) {
        //                        return step + 1;
        //                    } else{
        //                        queue.push(cur);
        //                        wordSet.erase(cur);
        //                    }
        //                }
        //            }
        //            cur[i]=tmp;
        //        }
        //    }
        //    step++;
        //}
        //return 0;
        /**
         * 双向bfs
         */
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if (wordSet.empty() || wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        unordered_set<string> beginSet,endSet;
        beginSet.emplace(beginWord);
        endSet.emplace(endWord);
        wordSet.erase(beginWord);
        wordSet.erase(endWord);

        int step = 1;
        while (!beginSet.empty()&&!endSet.empty()) {
            unordered_set<string> newSet;
            for (string cur:beginSet) {
                for (int i = 0; i < cur.size(); ++i) {
                    char tmp = cur[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        if (j == tmp) {
                            continue;
                        }
                        cur[i] = j;
                        if (endSet.count(cur)) {
                            return step + 1;
                        }
                        if (wordSet.count(cur)) {
                            newSet.emplace(cur);
                            wordSet.erase(cur);
                        }
                    }
                    cur[i]=tmp;
                }
            }
            if (newSet.size() < endSet.size()) {
                beginSet = newSet;
            } else{
                beginSet = endSet;
                endSet = newSet;
            }
            step++;
        }
        return 0;

    }





};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<string> tmp{"hot", "dog"};

    s.ladderLength("hot", "dog", tmp);
}