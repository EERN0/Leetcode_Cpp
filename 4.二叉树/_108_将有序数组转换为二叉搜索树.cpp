// Created by caokang on 2023/5/3.
// https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/

// 用一个数组，构建一个二叉树，即是平衡二叉树，也是二叉搜索树
// 和105从前序与中序遍历序列构造二叉树、106基本一样

#include<vector>
#include "二叉树结构体.hpp"

using namespace std;

class Solution108 {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        // 递归结束条件
        if (nums.empty()) return nullptr;
        if (nums.size() == 1) {     // 只有1个节点时，这个节点作为根直接返回
            return new TreeNode(nums[0]);
        }

        int rootValue = nums[nums.size() / 2];  // 选中右节点作为中间节点
        auto root = new TreeNode(rootValue);


        // 单层递归逻辑
        vector<int> leftNums(nums.begin(), nums.begin() + nums.size() / 2);
        vector<int> rightNUms(nums.begin() + nums.size() / 2 + 1, nums.end());

        root->left = sortedArrayToBST(leftNums);
        root->right = sortedArrayToBST(rightNUms);

        return root;
    }
};