/**
 * 
 * Copyright (c) 2019 NUAA Jiang Yang
 * 
 * @file
 * @author   Jiang Yang (pokerpoke@qq.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-08-13
 * Modified By:    Jiang Yang (pokerpoke@qq.com)
 * 
 */
#ifndef _BTREE_H_
#define _BTREE_H_

#include <vector>
#include <iostream>
#include <initializer_list>
#include <queue>
#include <list>

namespace LeetCode {

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    void print_tree(TreeNode *root);

    bool is_same_tree(TreeNode *root1, TreeNode *root2);

    class Node {
    public:
        int val;
        std::vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, std::vector<Node*> _children) {
            val = _val;
            children = _children;
        }
    };

    class Tree {
    public:
        TreeNode *root;

    private:
        std::queue<int> q;

    public:
        Tree(std::initializer_list<int> il);

        ~Tree();

        void print();

        bool operator==(const Tree &t2) const;

    private:
        TreeNode *deserialize(std::queue<int> &in);
    };
} // namespace LeetCode

#endif //!_BTREE_H_