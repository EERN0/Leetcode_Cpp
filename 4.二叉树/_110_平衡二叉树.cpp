/*
 * https://leetcode.cn/problems/balanced-binary-tree/
 * */

#include<iostream>
#include<vector>
#include<queue>
#include "二叉树结构体.hpp"

using namespace std;

// 二刷再看迭代的方法

// 递归，后序遍历
class Solution110 {
public:
    bool isBalanced(TreeNode *root) {
        int res = getHeight(root);
        if (res == -1) return false;
        else return true;
    }

    int getHeight(TreeNode *node) {
        if (node == nullptr) return 0;

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // -1表示不是一棵平衡二叉树
        if (leftHeight == -1) return -1;
        if (rightHeight == -1) return -1;


        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        else {
            return 1 + max(leftHeight, rightHeight);
        }
    }
};