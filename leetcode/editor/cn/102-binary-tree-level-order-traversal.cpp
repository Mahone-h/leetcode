
//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层序遍历结果： 
//
// 
//[
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索 
// 👍 890 👎 0


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

    vector<vector<int>> levelOrder(TreeNode* root) {
        /**
         * bfs 层序遍历
         */
        vector<vector<int>> res;
        queue<TreeNode *> queue;
        if (root != nullptr) {
            queue.emplace(root);
        }
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> level;
            for (int i = 0; i < n; ++i) {
                TreeNode *tmp = queue.front();
                queue.pop();
                level.emplace_back(tmp->val);
                if (tmp->left!= nullptr) {
                    queue.emplace(tmp->left);
                }
                if (tmp->right!= nullptr) {
                    queue.emplace(tmp->right);
                }
            }
            res.emplace_back(level);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Solution s;
    
}