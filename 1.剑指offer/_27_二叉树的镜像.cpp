// https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/
// 和226翻转二叉树一样
// Created by kang on 2023/8/20.

#include "../4.二叉树/二叉树结构体.hpp"
#include <stack>

using namespace std;

class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root) {
        if (root == nullptr) return root;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            swap(node->left, node->right);
            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }
        return root;
    }
};