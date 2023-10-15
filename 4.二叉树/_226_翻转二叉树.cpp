// https://leetcode-cn.com/problems/invert-binary-tree/
#include<iostream>
#include <stack>
#include "二叉树结构体.hpp"

using namespace std;

// 递归
class Solution_recursion {
public:
    TreeNode *invertTree(TreeNode *root) {
        // 递归终止条件
        if (root == nullptr) return root;

        // 单层逻辑——交换二叉树的左右结点
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// 迭代，前序遍历，在处理中间节点时，交换左右节点
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        stack<TreeNode *> st;
        if (root == nullptr) return root;

        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            swap(node->left, node->right);
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }
        return root;
    }
};

int main() {
    auto *left = new TreeNode(2, nullptr, nullptr);
    auto *right = new TreeNode(3, nullptr, nullptr);
    auto *root = new TreeNode(1, left, right);

    Solution s;
    s.invertTree(root);

    // 层序输出这棵树

    return 0;
}