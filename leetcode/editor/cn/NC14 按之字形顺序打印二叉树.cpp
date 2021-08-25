
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
    val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (pRoot == nullptr) {
            return res;
        }
        q.emplace(pRoot);
        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            while (n--) {
                TreeNode *node = q.front();
                q.pop();
                tmp.emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            if (level++ % 2 == 0) {
                reverse(tmp.begin(), tmp.end());
            }
            res.emplace(tmp);
        }
        return res;
    }

};