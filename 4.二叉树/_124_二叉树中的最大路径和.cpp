/*
 * https://leetcode.cn/problems/binary-tree-maximum-path-sum/
 * */
#include <vector>
#include <iostream>
#include "二叉树结构体.hpp"

using namespace std;

// 递归，只能拿到最大路径和，不能打印路径
class Solution {
public:
    int maxSum = INT32_MIN;

    int maxValue(TreeNode *node) {
        // 递归结束条件
        if (node == nullptr) return 0;

        // 后序遍历
        // 如果子树路径和为负则应当置0，表示最大路径不包含子树
        int leftContribute = max(maxValue(node->left), 0);
        int rightContribute = max(maxValue(node->right), 0);

        // 计算 左+中+右 的最大路径和（包括中间结点的路径）
        int mid = leftContribute + rightContribute + node->val;

        // 更新最大路径和 maxSum
        maxSum = max(maxSum, mid);

        // 递归返回时，只返回较大的一边（左+中，或者 右+中）
        return node->val + max(leftContribute, rightContribute);
    }

    int maxPathSum(TreeNode *root) {
        maxValue(root);
        return maxSum;
    }
};


// 打印路径，没看
class Solution2 {
private:
    struct Node { // 用一个结构体去存储一个节点的值和状态
        int val;
        vector<int> path;

        Node() : val(0) {}

        Node(int _val) : val(_val) {}

        Node(int _val, vector<int> _path) : val(_val), path(_path) {}
    };

    int ans = INT32_MIN;
    vector<int> Path;

public:
    int maxPathSum(TreeNode *root) {
        scan(root);
        for (auto p: Path) {
            cout << p << "->";
        }
        return ans;
    }

    Node *scan(TreeNode *root) {
        if (!root) //当遍历到空的位置的时候返回一个空状态
            return new Node();

        //如果左叶子和右叶子只要是有一个是负数我们就抛弃
        Node *left = scan(root->left);
        if (left->val <= 0)
            left = new Node();
        Node *right = scan(root->right);
        if (right->val <= 0)
            right = new Node();
        vector<int> cur; // 建立一下当前状态
        if (ans < root->val + left->val + right->val) { // 先不处理等于的状态
            ans = root->val + left->val + right->val;
            // 每一个字结构就是左根右 做记录就好
            cur.insert(cur.end(), left->path.begin(), left->path.end());
            cur.push_back(root->val);
            cur.insert(cur.end(), right->path.begin(), right->path.end());
            Path = cur;
        }
        Node *re = new Node();
        if (left->val > right->val) { //如果左边大于右边
            re->val = root->val + left->val; // 当前状态的值为根 + 左
            re->path.push_back(root->val);
            re->path.insert(re->path.end(), left->path.begin(), left->path.end());
        }
        else {
            re->val = root->val + right->val; // 当前状态的值为右 + 根
            re->path.insert(re->path.end(), right->path.begin(), right->path.end());
            re->path.push_back(root->val);
        }
        return re; // 返回当前状态
    }
};