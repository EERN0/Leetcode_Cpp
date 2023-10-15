/*
 * https://leetcode.cn/problems/average-of-levels-in-binary-tree/
 * */
#include<iostream>
#include<vector>
#include<queue>
#include "../二叉树结构体.hpp"

using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> result;
        queue<TreeNode *> que;
        if (root == NULL) return {};
        que.push(root);
        while (!que.empty()) {
            int length = que.size();
            double sum = 0;
            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();
                sum += node->val;
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
            result.push_back(sum / length);
        }
        return result;
    }
};