//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
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
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 104] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 设计 
// 👍 570 👎 0


#include "include/headers.h"

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "null,";
        }
        string left=serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + right;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> strList = split(data, ',');
        TreeNode *root = build(strList);
        return root;
    }
    TreeNode* build(list<string> &strList){
        string tmp = strList.front();
        strList.pop_front();
        if (tmp == "null") {
            return nullptr;
        }
        TreeNode *res = new TreeNode(stoi(tmp));
        res->left = build(strList);
        res->right = build(strList);
        return res;
    }

    list<string> split(string &str,char c){
        list<string> res;
        size_t pos = str.find(c);
        string tmp;
        int last = 0;
        while (pos != str.npos) {
            tmp = str.substr(last, pos-last);  //从last开始几个
            res.emplace_back(tmp);
            last=pos+1;
            pos = str.find(c,last);
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


int main()
{
    Codec s;
    TreeNode *root=new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left=new TreeNode(4);
    root->right->right = new TreeNode(5);
    string tmp = s.serialize(root);
    cout << tmp<< endl;
    delete root->right->left,root->right->right,root->left,root->right;
    root = s.deserialize(tmp);
    delete root->right->left,root->right->right,root->left,root->right;


}