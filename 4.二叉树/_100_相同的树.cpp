// https://leetcode.cn/problems/same-tree/
// 100(相同的树) -> 101(对称二叉树) -> 572(另一棵树的子树)
// Created by caokang on 2023/6/3.

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution100 {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        else if (p == nullptr || q == nullptr) {    // p、q只有一个为null
            return false;
        }

        // p、q都非null
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};