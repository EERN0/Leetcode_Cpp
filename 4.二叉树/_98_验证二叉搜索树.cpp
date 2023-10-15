/*
 * https://leetcode.cn/problems/validate-binary-search-tree/
 * 二叉搜索树：中序遍历的结果是从小到大有序的
 * */
#include<iostream>
#include<vector>
#include<stack>
#include "二叉树结构体.hpp"

using namespace std;

class Solution98 {
public:
    TreeNode *pre = nullptr;    // 用于记录前一个结点
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;

        bool left = isValidBST(root->left); // 左

        if (pre != nullptr && pre->val >= root->val) return false;  // 中
        pre = root;

        bool right = isValidBST(root->right);   // 右

        return left && right;
    }
};

// 迭代法，中序遍历二叉树
class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;

        TreeNode *cur = root;
        TreeNode *prev = nullptr;   // 存储上一个节点的值
        stack<TreeNode *> st;

        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);

                cur = cur->left;    // 往左走
            }
            else {  // 左边走到头了
                // 处理中间节点
                cur = st.top();
                st.pop();
                if (prev != nullptr && prev->val >= cur->val) return false;
                prev = cur;     // 保留前一个访问的节点

                cur = cur->right;   // 往右走
            }
        }
        return true;
    }
};


int main() {
/* 创建二叉树
        5
      /   \
     4     6
          / \
         3   7
*/
    TreeNode *node4 = new TreeNode(4, nullptr, nullptr);

    TreeNode *node5 = new TreeNode(3, nullptr, nullptr);
    TreeNode *node6 = new TreeNode(7, nullptr, nullptr);
    TreeNode *node7 = new TreeNode(6, node5, node6);

    TreeNode *node0 = new TreeNode(5, node4, node7);

    Solution98 s1;
    bool res = s1.isValidBST(node0);

    cout << res << endl;

    return 0;
}