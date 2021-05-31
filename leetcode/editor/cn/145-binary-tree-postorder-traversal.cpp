//给定一个二叉树，返回它的 后序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [3,2,1] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 
// 👍 590 👎 0


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
    void postorder(TreeNode *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        postorder(root->left, res);
        postorder(root->right, res);
    }

    vector<int> postorderTraversal(TreeNode *root) {


        //vector<int> res;
        //postorder(root, res);
        //return res;

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
                stack.push(make_pair(node, 1));
                if (node->right) stack.push(make_pair(node->right, 0));
                if (node->left) stack.push(make_pair(node->left, 0));
            } else{
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