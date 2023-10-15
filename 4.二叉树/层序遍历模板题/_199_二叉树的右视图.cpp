/*
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/
 * */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include "../二叉树结构体.hpp"

using namespace std;

// 广度优先搜索进行层序遍历（使用队列），result数组记录每层最后一个元素
class Solution_BFS {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> que;
        if (root == nullptr) return {};
        que.push(root);
        while (!que.empty()) {
            int length = que.size();
            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();
                // 如果是层序遍历的最后一个元素，将该元素放入result数组中
                if (i == length - 1) {
                    result.push_back(node->val);
                }
                if (node->left != NULL) que.push(node->left);
                if (node->right != NULL) que.push(node->right);
            }
        }
        return result;
    }
};

// 深度优先搜索DFS，类似先序遍历，采用“根、右、左”方式递归遍历，记录每层访问的第一个节点
// 每一层只用result数组记录一个节点
class Solution_DFS {
public:
    vector<int> result;

    void DFS(TreeNode *cur, int depth) {
        // 递归结束条件
        if (cur == NULL) return;

        // 先访问 当前节点，再递归地访问 右子树 和 左子树
        // 如果当前节点所在深度还没有出现在result里，说明在该深度下当前节点是第一个被访问的节点，因此将当前节点加入result中
        if (depth == result.size()) {
            result.push_back(cur->val);
        }

        depth++;
        DFS(cur->right, depth);
        DFS(cur->left, depth);
    }

    vector<int> rightSideView(TreeNode *root) {
        if (root == NULL) return {};
        // 根节点的深度为0
        DFS(root, 0);
        return result;
    }
};
