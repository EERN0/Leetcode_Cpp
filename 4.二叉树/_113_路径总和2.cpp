// https://leetcode.cn/problems/path-sum-ii/
// Created by kang on 2023/8/25.
//
#include "二叉树结构体.hpp"
#include <vector>

using namespace std;

// 代码随想录——回溯模板
class Solution113 {
public:
    vector<int> path;
    vector<vector<int>> res;

    void backtracking(TreeNode *root, int sum) {
        // 遇到了叶子节点，且路径和等于sum，收集结果
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            res.push_back(path);
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {   // 走到了叶子节点，但是总和不等于sum，直接返回
            return;
        }

        // 处理root的左子树
        if (root->left != nullptr) {
            path.push_back(root->left->val);    // 第一个放的是根节点的左孩子，根节点不在这里放进来
            sum -= root->left->val;

            // 回溯递归
            backtracking(root->left, sum);
            // 回溯撤销
            path.pop_back();
            sum += root->left->val;
        }
        // 处理root的右子树
        if (root->right != nullptr) {
            path.push_back(root->right->val);
            sum -= root->right->val;
            backtracking(root->right, sum);
            path.pop_back();
            sum += root->right->val;
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return {};
        res.clear(), path.clear();
        // 上面的backtracking没加上根节点
        path.push_back(root->val);

        backtracking(root, targetSum - root->val);
        return res;
    }
};

// 回溯，我不理解！！
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(TreeNode *root, int targetSum) {
        if (root == nullptr) return;

        path.push_back(root->val);
        targetSum -= root->val;

        // 叶子节点, 且从根到叶子的总和为targetSum
        if (root->left == nullptr && root->right == nullptr && targetSum == 0) {
            res.push_back(path);
            // 不能直接return，回溯撤销操作还没做。只收集了一个结果
        }
        else {
            // 回溯递归，当root是叶子的时候，全部return，再执行撤销操作
            dfs(root->left, targetSum);
            dfs(root->right, targetSum);
        }
        // 回溯撤销操作
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
};