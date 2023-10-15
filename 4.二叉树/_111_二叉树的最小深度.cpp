/*
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量
 * */
#include<iostream>
#include<vector>
#include<queue>
#include "二叉树结构体.hpp"

using namespace std;


class Solution_recursion {
public:
    int minDepth(TreeNode *root) {
        // 递归结束条件
        if (root == nullptr) return 0;

        // 求最小深度，主要要考虑【单支树】，不然可以直接 返回 min(left,right)
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (leftDepth && rightDepth) {    // 非单支树
            return min(leftDepth, rightDepth) + 1;
        }
        else {    // 单支树
            return leftDepth + rightDepth + 1;
        }
    }
};

// 迭代，BFS层序遍历（借助队列）
class Solution_iterate {
public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> que;
        que.push(root);

        int depth = 0;
        // 当左右孩子都为空，才能说明遍历到叶子
        while (!que.empty()) {
            int size = que.size();
            // 一层
            depth++;
            while (size--) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);

                // 当左右孩子都为空的时候，说明遇到了叶子节点，此时遇到的是第一个叶子节点，直接返回最小高度
                if (node->left == nullptr && node->right == nullptr) return depth;
            }
        }
        return depth;
    }
};


int main() {
    /*
     *          1
     *           \
     *             2
     *           /   \
     *          3     6
     *               /
     *              5
     *  最小深度是3
     * */
    auto *left = new TreeNode(2, nullptr, nullptr);
    auto *right = new TreeNode(3, nullptr, nullptr);
    auto *root = new TreeNode(1, left, right);

    Solution_iterate s;

    int depth = s.minDepth(root);
    cout << "二叉树的最小深度是：" << depth << endl;
    return 0;
}

