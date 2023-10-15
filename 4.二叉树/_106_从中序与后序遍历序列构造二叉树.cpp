// Created by caokang on 2023/5/3.
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
#include<iostream>
#include<vector>
#include "二叉树结构体.hpp"

using namespace std;

class Solution {
public:
    TreeNode *traversal(vector<int> &inorder, vector<int> &postorder) {
        // 递归结束条件
        if (postorder.empty()) return nullptr;

        int rootValue = postorder[postorder.size() - 1];    // 根节点
        auto *root = new TreeNode(rootValue);

        if (postorder.size() == 1) return root;

        // 单层处理逻辑
        // 在中序数组中找到中间节点(根节点)的下标
        int rootIndex = 0;
        for (int i = 0; i < postorder.size(); ++i) {
            if (inorder[i] == rootValue) {
                rootIndex = i;
                break;
            }
        }

        // 分割中序数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex+1);      // 左子树中序数组
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());   // 右子树中序数组

        // 分割后序数组
        postorder.resize(postorder.size() - 1);     // 去掉根节点
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());       // 左子树后序数组
        vector<int> rightPostorder(postorder.begin() + leftInorder.size() + 1, postorder.end());    // 右子树后序数组
        for (auto o: leftPostorder) {
            cout << o << " ";
        }
        cout << endl;

        // 左、右子树
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty()) return nullptr;
        return traversal(inorder, postorder);
    }
};

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution solution;
    TreeNode *root = solution.buildTree(inorder, postorder);

    return 0;
}