//给定一个 N 叉树，返回其节点值的 前序遍历 。 
//
// N 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。 
//
// 
// 
// 
//
// 进阶： 
//
// 递归法很简单，你可以使用迭代法完成此题吗? 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [1,null,3,2,4,null,5,6]
//输出：[1,3,5,6,2,4]
// 
//示例 2：
//
// 
//
// 
//输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,
//null,13,null,null,14]
//输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
// 
//
// 
//
// 提示： 
//
// 
// N 叉树的高度小于或等于 1000 
// 节点总数在范围 [0, 10^4] 内 
// 
// 
// 
// Related Topics 树 
// 👍 161 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void traversal(Node *root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        res.emplace_back(root->val);
        for (int i = 0; i < root->children.size(); ++i) {
            traversal(root->children[i], res);
        }
    }
    vector<int> preorder(Node *root) {
        /**
         * 递归
         */
        //vector<int> res;
        //traversal(root, res);
        //return res;
        /**
         * 迭代 模拟递归
         */
//        vector<int> res;
//        stack<pair<Node *, bool>> stack;
//        stack.push(make_pair(root, 0));
//        while (!stack.empty()) {
////            auto[node, type]=stack.top(); //c++17
//            Node* node = stack.top().first;
//            bool type = stack.top().second;
//            stack.pop();
//            if (node== nullptr) continue;
//            if (type == 0) {
//                for (int i = node->children.size()-1; i >=0; i--) {
//                    stack.push(make_pair(node->children[i], 0));
//                }
//                stack.push(make_pair(node, 1));
//            } else{
//                res.emplace_back(node->val);
//            }
//        }
//        return res;
        vector<int> result;
        if (root == NULL) return result;
        stack<Node*> st;
        st.push(root);
        while (!st.empty()) {
            Node* node = st.top();
            st.pop();
            result.push_back(node->val);
            // 注意要倒叙，这样才能达到前序（中左右）的效果
            for (int i = node->children.size() - 1; i >= 0; i--) {
                if (node->children[i] != NULL) {
                    st.push(node->children[i]);
                }
            }
        }
        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;

}