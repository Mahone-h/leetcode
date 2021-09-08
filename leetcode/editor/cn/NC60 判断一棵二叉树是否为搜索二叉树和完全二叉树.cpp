//
// Created by Mahone on 2021/9/7.
//

//关于搜索二叉树的知识：搜索二叉树左子树上所有值小于根节点，右子树上所有值大于根节点，中序遍历后得到的是一个递增序列。
//关于完全二叉树的知识：完全二叉树叶节点只能出现在最下层和次下层，
// 并且最下面一层的节点都集中在该层最左边的若干位置的二叉树，出现叶子节点以后的节点都是叶子。
//由此，可用二叉树的中序遍历检查是否为一个递增序列判断是否为搜索二叉树，
// 可用二叉树的层次遍历，判断叶子节点之后是否还有非叶子节点。
//中序遍历：递归


/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    int pre=INT_MIN;
    bool judgeSBT(TreeNode* root){ //判断是否为搜索二叉树：递归中序遍历
        if(root == NULL) return true;
        if(!judgeSBT(root->left)) return false;
        if(root->val<=pre) return false;
        pre=root->val;
        return judgeSBT(root->right);
    }
    bool judgeCBT(TreeNode* root){ //判断是否为完全二叉树：层次遍历
        TreeNode* head = root;
        if(head == NULL)
            return true; //如果是空，则一定是完全二叉树
            queue<TreeNode*> temp; //队列存储，进行层次遍历
            temp.push(head);
            TreeNode* p;
            bool flag = false; //记录是否开始出现叶子结点
            while(!temp.empty()){
                p = temp.front();
                temp.pop();
                if(p == NULL) {//如果是空，说明其后面都没有孩子了
                    flag= true;
                    continue;
                }
                if(flag)  return false;//如果是true，说明前面出现过叶子结点
                //存入左右孩子作为下一个层次
                temp.push(p->left);
                temp.push(p->right);
            }
            return true;
    }
    vector<bool> judgeIt(TreeNode* root) {
        vector<bool> res;
        res.push_back(judgeSBT(root));
        res.push_back(judgeCBT(root));
        return res;
    }
};