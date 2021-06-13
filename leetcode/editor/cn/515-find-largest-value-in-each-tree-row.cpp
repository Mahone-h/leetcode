//您需要在二叉树的每一行中找到最大的值。 
//
// 示例： 
//
// 
//输入: 
//
//          1
//         / \
//        3   2
//       / \   \  
//      5   3   9 
//
//输出: [1, 3, 9]
// 
// Related Topics 树 深度优先搜索 广度优先搜索 
// 👍 131 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }
        int maxVal = INT_MIN;
        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *tmp = queue.front();
                queue.pop();
                maxVal = max(maxVal, tmp->val);
                if (tmp->left != nullptr) {
                    queue.emplace(tmp->left);
                }
                if (tmp->right != nullptr) {
                    queue.emplace(tmp->right);
                }
            }
            res.emplace_back(maxVal);
            maxVal = INT_MIN;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}