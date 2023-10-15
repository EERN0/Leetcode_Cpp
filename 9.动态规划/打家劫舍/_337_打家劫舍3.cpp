// Created by caokang on 2023/5/1.
// https://leetcode.cn/problems/house-robber-iii/
#include "../../4.二叉树/二叉树结构体.hpp"
#include <vector>

using namespace std;

// 树形dp
class Solution1 {
public:
    // 每个节点只有偷和不偷两种状态，dp[0]: 不偷该节点能获得的最高金额；dp[1]: 偷该节点能获得的最高金额

    // 后序遍历，把左、右子树打劫的最高金额返回给中间节点
    // robtree()的返回值：数组有两个元素  {不偷cur节点获得金额的最大值, 偷cur节点获得金额的最大值}
    vector<int> robtree(TreeNode *cur) {
        // 递归结束
        if (cur == nullptr) return {0, 0};

        vector<int> leftdp = robtree(cur->left);    // 打劫左子树能获得的最高金额
        vector<int> rightdp = robtree(cur->right);  // 打劫右子树能获得的最高金额

        // 偷当前节点cur，就不能偷cur的孩子节点了
        int val1 = cur->val + leftdp[0] + rightdp[0];
        // 不偷当前节点cur，偷不偷cur的孩子节点由偷孩子节点获得的最大收益决定
        int val0 = max(leftdp[0], leftdp[1]) + max(rightdp[0], rightdp[1]);

        return {val0, val1};
    }

    int rob(TreeNode *root) {
        vector<int> maxMoney = robtree(root);

        return max(maxMoney[0], maxMoney[1]);
    }
};


// 暴力+优化——记忆化递归
class Solution2 {
public:
    int rob(TreeNode *root) {

    }
};