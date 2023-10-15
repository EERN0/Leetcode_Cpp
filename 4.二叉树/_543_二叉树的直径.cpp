// Created by caokang on 2023/5/10.
// https://leetcode.cn/problems/diameter-of-binary-tree/
#include "二叉树结构体.hpp"
#include <algorithm>
#include <iostream>
using namespace std;
/* 分两种情况：
 * ① 经过根节点的最大路径：左子树的高度+右子树的高度
 * ② 不经过根节点的最大路径：最大路径存在于左子树，或右子树中
 *
 * 统一处理方法：记录每个节点的左、右子树高度之和，取最大者即为最长路径
 * */
class Solution {
public:
    int MAX = INT32_MIN;

    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;

        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);

        // 记录所有节点左右子树的最大路径的最大值
        if (leftHeight + rightHeight > MAX) {
            MAX = leftHeight + rightHeight;
        }

        return max(leftHeight, rightHeight) + 1;    // 节点的高度
    }

    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return MAX;
    }
};