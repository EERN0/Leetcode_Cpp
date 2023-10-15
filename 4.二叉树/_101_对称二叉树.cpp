/*
 * https://leetcode.cn/problems/symmetric-tree/
 * 同类型题目：lc100、lc572
 * */
#include<iostream>
#include <stack>
#include <queue>
#include "二叉树结构体.hpp"

using namespace std;

// 递归
class Solution {
public:
    // 一、递归函数的参数和返回值
    bool compare(TreeNode *left, TreeNode *right) {
//        // 二、终止条件
//        // 1.排除空节点
//        if (left == nullptr && right != nullptr) return false;
//        else if (left != nullptr && right == nullptr) return false;
//        else if (left == nullptr && right == nullptr) return true;
//            // 2.再排除节点数值不相同的情况
//        else if (left->val != right->val) return false;
//
//        // 三、单层递归逻辑
//        bool outside = compare(left->left, right->right);   // 外侧节点
//        bool inside = compare(left->right, right->left);    // 内侧节点
//        bool result = outside && inside;
//
//        return result;

        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr || right == nullptr) {
            // 左、右只有一个为空，肯定不对称
            return false;
        }
        // 左、右都非空
        return (left->val == right->val)
               && compare(left->left, right->right)
               && compare(left->right, right->left);
    }

    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;
        return compare(root->left, root->right);
    }
};

// 迭代，使用队列，也可以用栈，只要两个节点一起入队列（入栈）就行
class Solution2_1 {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) return true;

        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

//        if (que.empty()) return true;   // 只有一个根节点
        while (!que.empty()) {
            TreeNode *leftNode = que.front();
            que.pop();
            TreeNode *rightNode = que.front();
            que.pop();

            // 左、右节点均为空，对称
            if (!leftNode && !rightNode) continue;

            // 左、右只有一个是空，或左右都非空但数值不同
            // leftNode是null，那么rightNode必然非空
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
                return false;
            }

            // 剩下的情况是左右节点均非空
            // 外侧节点，成对放入队列
            que.push(leftNode->left);
            que.push(rightNode->right);
            // 内侧节点
            que.push(leftNode->right);
            que.push(rightNode->left);
        }

        return true;
    }
};