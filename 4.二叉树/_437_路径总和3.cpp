// https://leetcode.cn/problems/path-sum-iii/
// Created by kang on 2023/9/3.

#include "二叉树结构体.hpp"

// 从父节点到子节点的总和，不要求从根到叶子

// 递归，双重递归
class Solution437_1 {
public:
    // 搜索从当前节点出发，路径和为targetSum的路径数
    int dfs(TreeNode *root, long targetSum) {
        if (root == nullptr) return 0;

        int sum = 0;
        if (targetSum == root->val) {
            sum++;
        }

        sum += dfs(root->left, targetSum - root->val);  // 当前节点的左子树
        sum += dfs(root->right, targetSum - root->val); // 当前节点的右子树

        return sum;
    }

    int pathSum(TreeNode *root, long targetSum) {
        if (root == nullptr) return 0;

        // 包含根节点，路径和为targetSum的路径
        int n = dfs(root, targetSum);

        // 不包含根节点
        int left = pathSum(root->left, targetSum);
        int right = pathSum(root->right, targetSum);

        return n + left + right;
    }
};

// 前缀和
class Solution437_2 {
public:
    int pathSum(TreeNode *root, int targetSum) {

    }
};