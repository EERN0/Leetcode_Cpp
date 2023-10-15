// Created by caokang on 2023/5/9.
// https://leetcode.cn/problems/sum-root-to-leaf-numbers/
#include "二叉树结构体.hpp"

// 递归，DFS深度优先搜索
class Solution {
public:
    int result = 0;

    void dfs(TreeNode *root, int preValue) {
        if (root == nullptr) return;

        // 当前节点的值
        int sum = preValue * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            // 叶子节点，收集结果
            result += sum;
        }
        else {  // 非叶子节点
            if (root->left != nullptr) {  // 左子树非空，继续往左走，直至叶子节点
                dfs(root->left, sum);   // 当前节点的值sum传给下一个节点
            }

            if (root->right != nullptr) {
                dfs(root->right, sum);
            }
        }
    }

    int sumNumbers(TreeNode *root) {
        dfs(root, 0);   // 根节点之前的值是0
        return result;
    }
};

// BFS，广度优先搜索
class Solution2 {
public:
    int sumNumbers(TreeNode *root) {

    }
};