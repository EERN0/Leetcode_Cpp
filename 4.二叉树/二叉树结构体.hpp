// Created by caokang on 2023/3/20.

#ifndef LEETCODE_二叉树结构体_HPP
#define LEETCODE_二叉树结构体_HPP

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif //LEETCODE_二叉树结构体_HPP
