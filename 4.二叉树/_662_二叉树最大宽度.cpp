// https://leetcode.cn/problems/maximum-width-of-binary-tree/
// Created by kang on 2023/8/25.
struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 完全二叉树，数组形式存储
// 父节点下标为i，左子树的下标：2*i，右子树的下标：2*i+1
#include <queue>

using namespace std;

// int类型全换成unsigned long long类型才能通过
class Solution662 {
public:
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode *, int>> que;
        que.push({root, 1});
        int maxKuan = 0;

        while (!que.empty()) {
            int size = que.size();
            // 同一层的节点，第一个节点和最后一个节点的下标
            int left = que.front().second;  // 队列中，第一个节点的下标
            int right = left;               // 队列中，最后一个节点的下标

            while (size--) {
                auto [node, idx] = que.front();
                que.pop();

                right = idx;
                if (node->left) {
                    que.push({node->left, 2 * idx});
                }
                if (node->right) {
                    que.push({node->right, 2 * idx + 1});
                }
            }
            // 一层处理完了，right就是一层最后一个节点的下标了
            maxKuan = max(maxKuan, right - left + 1);
        }
        return maxKuan;
    }
};