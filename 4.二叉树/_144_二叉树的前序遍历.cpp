// https://leetcode.cn/problems/binary-tree-preorder-traversal/
#include<iostream>
#include<vector>
#include<stack>
#include "二叉树结构体.hpp"

using namespace std;


// 递归
class Solution_recursion {
public:
    void traversal(vector<int> &v, TreeNode *cur) {
        // 递归结束条件
        if (cur == NULL) return;
        v.push_back(cur->val);       // 打印根结点
        traversal(v, cur->left);     // 左
        traversal(v, cur->right);    // 右
    }

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;     // 存遍历元素顺序的数组
        traversal(result, root);
        return result;
    }
};

// 迭代
class Solution_iterate {     // 用栈实现二叉树遍历的非递归
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};

        vector<int> result;
        stack<TreeNode *> st;       // 栈中存放的是结点指针
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();   // 结点出栈
            result.push_back(node->val);    // 输出结点

            // 右结点先进栈（先进后出）
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }
        return result;
    }
};


int main() {
    TreeNode *left = new TreeNode(2, NULL, NULL);
    TreeNode *right = new TreeNode(3, NULL, NULL);
    TreeNode *root = new TreeNode(1, left, right);

    Solution_iterate s;
    vector<int> vec;
    vec = s.preorderTraversal(root);

    for (auto o: vec) {
        cout << o << " ";
    }

    return 0;
}
