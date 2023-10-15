/*
 * https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/
 * */
#include "二叉树结构体.hpp"
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};

        // 层序遍历
        queue<TreeNode *> que;
        que.push(root);

        vector<vector<int>> res;
        TreeNode *node;
        int cnt = 1;    // 遍历二叉树第几层

        while (!que.empty()) {
            int size = que.size();
            vector<int> inner;

            while (size--) {
                node = que.front();
                que.pop();
                inner.push_back(node->val);

                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }

            if (cnt % 2 == 0) {     // 偶数层，逆置内层数组inner
                reverse(inner.begin(), inner.end());
            }
            res.push_back(inner);

            ++cnt;  // 一层遍历完，cnt++
        }
        return res;
    }
};