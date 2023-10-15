// Created by caokang on 2023/5/3.
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include <iostream>
#include <vector>
#include <algorithm>
#include "二叉树结构体.hpp"

using namespace std;

class Solution105 {
public:
    TreeNode *traversal(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) return nullptr;

        TreeNode *root = new TreeNode(preorder[0]);

        // 划分出左子树、右子树的中序数组
        vector<int> leftInorder(inorder.begin(), find(inorder.begin(), inorder.end(), root->val));
        vector<int> rightInorder(find(inorder.begin(), inorder.end(), root->val) + 1, inorder.end());

        // 划分左、右子树前序数组
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftPreorder.size(), preorder.end());

        // 左子树
        root->left = traversal(leftPreorder, leftInorder);
        // 右子树
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return traversal(preorder, inorder);
    }
};

class Solution {
public:
    TreeNode *traversal(vector<int> &preorder, vector<int> &inorder) {
        // 递归结束条件
        if (preorder.empty()) return nullptr;

        int rootValue = preorder[0];
        auto *root = new TreeNode(rootValue);

        // 找到根节点在中序数组的下标
        int rootIndex = 0;
        for (; rootIndex < inorder.size(); ++rootIndex) {
            if (inorder[rootIndex] == rootValue) break;
        }

        // 先切分中序数组，得到左、右子树数组
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());

        // 再切分前序数组
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
        vector<int> rightPreorder(preorder.begin() + leftInorder.size() + 1, preorder.end());

//        // 以下为日志
//        cout << "----------" << endl;
//
//        cout << "leftInorder :";
//        for (int i: leftInorder) {
//            cout << i << " ";
//        }
//        cout << endl;
//
//        cout << "rightInorder :";
//        for (int i: rightInorder) {
//            cout << i << " ";
//        }
//        cout << endl;
//
//        cout << "leftPreorder :";
//        for (int i: leftPreorder) {
//            cout << i << " ";
//        }
//        cout << endl;
//        cout << "rightPreorder :";
//        for (int i: rightPreorder) {
//            cout << i << " ";
//        }
//        cout << endl;

        root->left = traversal(leftPreorder, leftInorder);
        root->right = traversal(rightPreorder, rightInorder);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty()) return nullptr;
        return traversal(preorder, inorder);
    }
};

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Solution solution;
    TreeNode *root = solution.buildTree(preorder, inorder);

    return 0;
}