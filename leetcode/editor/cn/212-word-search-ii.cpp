//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。 
//
// 单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使
//用。 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l"
//,"v"]], words = ["oath","pea","eat","rain"]
//输出：["eat","oath"]
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], words = ["abcb"]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 12 
// board[i][j] 是一个小写英文字母 
// 1 <= words.length <= 3 * 104 
// 1 <= words[i].length <= 10 
// words[i] 由小写英文字母组成 
// words 中的所有字符串互不相同 
// 
// Related Topics 字典树 回溯算法 
// 👍 400 👎 0


#include "include/headers.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Trie{
public:
    bool isEnd;
    Trie *next[26];
    Trie(){
        isEnd = false;
        memset(next, 0, sizeof(next));
    }
    ~Trie(){
        for (int i = 0; i < 26; ++i) {
            if(next[i]) delete next[i];
        }
    }
    void insert(string word){
        Trie *node= this;
        for (char ch:word) {
            ch -= 'a';
            if (!node->next[ch]) node->next[ch] = new Trie;
            node = node->next[ch];
        }
        node->isEnd = true;
    }
};
class Solution {
public:

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    unordered_set<string> res;
    int m, n;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /**
         * 1.words  遍历  ->board search  O(N*m*m*4^K)
         * 2.all words ->trie 构建prefix
         * board dfs
         */
        //弄个简便trie
        if (board.empty()) return {};
        if (words.empty()) return {};
        Trie *root = new Trie;
        for (string word:words) {
            root->insert(word);
        }
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (root->next[board[i][j]-'a']!= nullptr){
                    dfs(board, root, i, j, "");
                }
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board,Trie *root,int i,int j,string cur_word){
        cur_word += board[i][j];
        Trie *node = root->next[board[i][j] - 'a'];
        if (node->isEnd) {
            res.emplace(cur_word);
            node->isEnd=false;  //优化   不从其他地方来的相同的？
        }
        char tmp = board[i][j];
        board[i][j] = '#';
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n
                && board[x][y] != '#' && node->next[board[x][y] - 'a']!= nullptr) {
                dfs(board, node, x, y, cur_word);
            }
        }
        board[i][j] = tmp;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    vector<string> words={"oa","oaa"};
    vector<string> res = s.findWords(board, words);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i]<< endl;
    }
}