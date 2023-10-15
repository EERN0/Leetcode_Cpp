/*
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
 * */
#include "二叉树结构体.hpp"

// 递归，后序遍历
class Solution1 {
public:
    // p、q一定是二叉树的节点
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 递归结束条件
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);      // 左子树找p、q
        TreeNode *right = lowestCommonAncestor(root->right, p, q);    // 右子树找p、q

        // 左、右子树的返回值给双亲节点
        if (left != nullptr && right != nullptr) return root;       // 左、右均有返回值，即p、q找到了，分别在左、右子树上
        else if (left == nullptr && right != nullptr) return right; // 左没有返回节点，右有返回节点，说明p、q均在右
        else if (left != nullptr && right == nullptr) return left;
        else return nullptr;
    }
};