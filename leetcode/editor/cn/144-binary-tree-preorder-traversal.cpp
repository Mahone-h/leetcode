//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,2,3]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 示例 5： 
//
// 
//输入：root = [1,null,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点数目在范围 [0, 100] 内 
// -100 <= Node.val <= 100 
// 
//
// 
//
// 进阶：递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 
// 👍 571 👎 0


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

    void preorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        /**
         * 迭代
         */
//        vector<int> res;
//        preorder(root, res);
//        return res;
/**
         * 模拟迭代
         */
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        stack<pair<TreeNode *, bool>> stack;
        stack.push(make_pair(root, 0));
        while (!stack.empty()) {
//            auto[node, type]=stack.top(); //c++17
            TreeNode* node = stack.top().first;
            bool type = stack.top().second;
            stack.pop();
            if (type == 0) {
                if (node->right) stack.push(make_pair(node->right, 0));
                if (node->left) stack.push(make_pair(node->left, 0));
                stack.push(make_pair(node, 1));
            } else{
                res.emplace_back(node->val);
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