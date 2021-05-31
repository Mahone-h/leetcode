//给定一个二叉树的根节点 root ，返回它的 中序 遍历。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3]
//输出：[1,3,2]
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
//输出：[2,1]
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
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表 
// 👍 960 👎 0


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
    void inorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        inorder(root->left, res);
        res.emplace_back(root->val);
        inorder(root->right, res);
    }

    vector<int> inorderTraversal(TreeNode *root) {
        /**
         * 递归
         */
//        vector<int> res;
//        inorder(root, res);
//        return res;
        /**
         * 迭代 非递归
         */
//        vector<int> res;
//        stack<TreeNode *> stk;
//        while (root != nullptr || !stk.empty()) {
//            while (root != nullptr) {
//                stk.push(root);
//                root=root->left;
//            }
//            root = stk.top();
//            stk.pop();
//            res.emplace_back(root->val);
//            root = root->right;
//        }
//        return res;
        /**
         * 模拟递归   white=0 gray=1
         * 使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
            如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
            如果遇到的节点为灰色，则将节点的值输出。
         */
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        stack<pair<TreeNode *, bool>> stack;
        stack.push(make_pair(root, 0));
        while (!stack.empty()) {
//            auto[node, type]=stack.top(); //c++17
            TreeNode *node = stack.top().first;
            bool type = stack.top().second;
            stack.pop();
            //if (node== nullptr) continue;
            if (type == 0) {
                if (node->right) stack.push(make_pair(node->right, 0));
                stack.push(make_pair(node, 1));
                if (node->left) stack.push(make_pair(node->left, 0));
            } else {
                res.emplace_back(node->val);
            }
        }
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}