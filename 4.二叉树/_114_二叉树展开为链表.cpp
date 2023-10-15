// https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
// Created by kang on 2023/8/22.
#include "二叉树结构体.hpp"

class Solution114 {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;

        TreeNode *cur = root;
        while (cur) {
            if (cur->left != nullptr) {
                // 拿到当前节点的左孩子
                TreeNode *tempLeft = cur->left;
                // 找到该左孩子的最右节点
                while (tempLeft->right) {
                    tempLeft = tempLeft->right;
                }
                tempLeft->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
        return;
    }
};
