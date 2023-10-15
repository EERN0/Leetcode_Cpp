/*
 * https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/
 * */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include "../二叉树结构体.hpp"

using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;
        if (root == NULL) return {};
        que.push(root);

        while (!que.empty()) {
            int length = que.size();
            vector<int> inner;  // 只记录同一层的结点
            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();
                inner.push_back(node->val);
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(inner);
        }
        // 翻转result数组，再输出
        reverse(result.begin(), result.end());
        return result;
    }
};
