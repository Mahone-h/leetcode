//一条基因序列由一个带有8个字符的字符串表示，其中每个字符都属于 "A", "C", "G", "T"中的任意一个。 
//
// 假设我们要调查一个基因序列的变化。一次基因变化意味着这个基因序列中的一个字符发生了变化。 
//
// 例如，基因序列由"AACCGGTT" 变化至 "AACCGGTA" 即发生了一次基因变化。 
//
// 与此同时，每一次基因变化的结果，都需要是一个合法的基因串，即该结果属于一个基因库。 
//
// 现在给定3个参数 — start, end, bank，分别代表起始基因序列，目标基因序列及基因库，请找出能够使起始基因序列变化为目标基因序列所需的最少变
//化次数。如果无法实现目标变化，请返回 -1。 
//
// 注意： 
//
// 
// 起始基因序列默认是合法的，但是它并不一定会出现在基因库中。 
// 如果一个起始基因序列需要多次变化，那么它每一次变化之后的基因序列都必须是合法的。 
// 假定起始基因序列与目标基因序列是不一样的。 
// 
//
// 
//
// 示例 1： 
//
// 
//start: "AACCGGTT"
//end:   "AACCGGTA"
//bank: ["AACCGGTA"]
//
//返回值: 1
// 
//
// 示例 2： 
//
// 
//start: "AACCGGTT"
//end:   "AAACGGTA"
//bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
//
//返回值: 2
// 
//
// 示例 3： 
//
// 
//start: "AAAAACCC"
//end:   "AACCCCCC"
//bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
//
//返回值: 3
// 
// 👍 77 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        /**
         * 单搜0
         */
        //unordered_set<string> banks(bank.begin(), bank.end());
        //if (banks.empty() || banks.count(end) == 0) {
        //    return -1;
        //}
        //vector<char> change={'A','C','G','T'};
        //queue<string> queue;
        //int count=0;
        //queue.emplace(start);
        //banks.erase(start);
        //while (!queue.empty()) {
        //    int n = queue.size();
        //    while (n--) {
        //        string cur = queue.front();
        //        queue.pop();
        //        for (int i = 0; i < cur.size(); ++i) {
        //            char tmp = cur[i];
        //            for (int j = 0; j < change.size(); ++j) {
        //                if (cur[i] == change[j]) {
        //                    continue;
        //                }
        //                cur[i] = change[j];
        //
        //                if (banks.count(cur)) {
        //                    if (cur == end) {
        //                        return count + 1;
        //                    } else{
        //                        queue.emplace(cur);
        //                        banks.erase(cur);
        //                    }
        //                }
        //            }
        //            cur[i] = tmp;
        //        }
        //    }
        //    count++;
        //}
        //return -1;
        unordered_set<string> banks(bank.begin(),bank.end());
        if (banks.empty() || banks.find(end) == banks.end()) {
            return -1;
        }
        unordered_set<string> beginSet,endSet;
        beginSet.emplace(start);
        endSet.emplace(end);
        banks.erase(start);
        banks.erase(end);
        vector<char> change={'A','C','G','T'};

        int step = 0;
        while (!beginSet.empty()&&!endSet.empty()) {
            unordered_set<string> newSet;
            for (string cur:beginSet) {
                for (int i = 0; i < cur.size(); ++i) {
                    char tmp = cur[i];
                    for (int j = 0; j < change.size(); ++j) {
                        if (cur[i] == change[j]) {
                            continue;
                        }
                        cur[i] = change[j];
                        if (endSet.count(cur)) {
                            return step + 1;
                        }
                        if (banks.count(cur)) {
                            newSet.emplace(cur);
                            banks.erase(cur);
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
        return -1;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}