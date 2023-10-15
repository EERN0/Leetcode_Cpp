/*
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * */
#include<iostream>
#include<vector>
#include<queue>
#include "二叉树结构体.hpp"

using namespace std;


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> result;
        queue<TreeNode *> que;
        if (root == nullptr) return {};
        que.push(root); // 队尾元素入队

        // 要求一层层输出
        while (!que.empty()) {
            int length = que.size();     // 每层节点的个数
            vector<int> inner;           // 必须重新初始化，里面一层，也是vector容器

            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();  // 队头元素出队
                inner.push_back(node->val);

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            result.push_back(inner);
        }
        return result;
    }
};
