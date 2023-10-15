// Created by caokang on 2023/5/11.
// https://leetcode.cn/problems/path-sum/
#include "二叉树结构体.hpp"
#include <vector>

using namespace std;

class Solution112 {
public:
    vector<int> result;

    // dfs()求根到叶子路径总和
    // preValue是root上一个节点的值
    void dfs(TreeNode *root, int preValue) {
        if (root == nullptr) return;
        int sum = 0;
        // 叶子节点，计算路径和
        if (root->left == nullptr && root->right == nullptr) {
            sum = preValue + root->val;
            // 收集结果
            result.push_back(sum);
            return;
        }
        else {
            // root不是叶子节点
            dfs(root->left, sum);
            dfs(root->right, sum);
        }
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return false;
        dfs(root, 0);
        for (auto num: result) {
            if (num == targetSum) return true;
        }
        return false;
    }
};