// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
#include<iostream>
#include<vector>
#include<queue>
#include "二叉树结构体.hpp"

using namespace std;

// 树的高度是到叶子的距离（高度是叶子往上），深度是到根节点的距离（深度是根往下）
class Solution_recursion {
public:
    int maxDepth(TreeNode *root) {
        // 递归结束条件，走到叶子再递归往上返回
        if (root == nullptr) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // leftDepth、rightDepth都是孩子节点的高度，返回给中间节点的高度要加1
        return 1 + max(leftDepth, rightDepth);
    }
};

class Solution_bfs {
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;

        queue<TreeNode *> que;
        que.push(root);
        int depth = 0;

        while (!que.empty()) {
            int size = que.size(); // 每层的节点数
            while (size--) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);

                // 一层走完了，深度加1
                if (size == 0) depth += 1;
            }
        }
        return depth;
    }
};

class Solution_iterate {     // 用层序遍历bfs
public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) return 0;

        queue<TreeNode *> que;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int length = que.size();    // 一层的结点数
            // 遍历二叉树的一层
            for (int i = 0; i < length; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            depth++;    // 遍历完一层，二叉树的深度加 1
        }
        return depth;
    }
};
