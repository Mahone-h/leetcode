/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
#include <queue>
#include <string>
#include "/include/headers.h"

using namespace std;

class Solution {
public:
    /**
     * 二叉树层序遍历
     * @param root TreeNode类
     * @return int整型
     */
    int sumNumbers(TreeNode* root) {
        // write code here
        int res = 0;
        queue<TreeNode *> q1;
        queue<string> q2;
        if (root == nullptr) {
            return res;
        }
        q1.emplace(root);
        q2.emplace(root->val);
        while (!q1.empty()) {
            TreeNode *tmp = q1.front();
            string s=q2.front();
            q1.pop();
            q2.pop();
            if (tmp->left != nullptr && tmp->right != nullptr) {
                res += stoi(s);
            } else{
                if (tmp->left != nullptr) {
                    q1.emplace(tmp->left);
                    q2.emplace(s + to_string(tmp->left->val));
                }
                if (tmp->right != nullptr) {
                    q1.emplace(tmp->right);
                    q2.emplace(s + to_string(tmp->right->val));
                }
            }
        }
        return res;

    }
};