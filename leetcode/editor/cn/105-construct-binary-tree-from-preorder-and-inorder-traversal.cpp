//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组 
// 👍 1055 👎 0


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
    int preIndx;

        /**
         *  start end 代表中序遍历的开头结尾  用来计算左右子树有几个元素
         *  preindex用来遍历preorder
         */
    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int start, int end, unordered_map<int, int> &map) {
        if (start > end) {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[preIndx]);
        int i = map[preorder[preIndx++]];
        root->left = helper(preorder, inorder, start, i - 1, map);
        root->right = helper(preorder, inorder, i + 1, end, map);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        preIndx = 0;
        unordered_map<int, int> map;
        for (int i = 0; i < inorder.size(); ++i) {
            map[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, inorder.size() - 1, map);

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}