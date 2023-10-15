#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include "二叉树结构体.hpp"

using namespace std;

// 后序遍历
class Solution_recursion {
public:
    void traversal(vector<int> &v, TreeNode *cur) {
        // 递归结束条件
        if (cur == nullptr) return;
        traversal(v, cur->left);     // 左
        traversal(v, cur->right);    // 右
        v.push_back(cur->val);           // 根
    }

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(result, root);
        return result;
    }
};

class Solution_iterate {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        if (root == nullptr) return {};
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            // 左子树结点先进栈，后出
            if (node->left != nullptr) st.push(node->left);
            if (node->right != nullptr) st.push(node->right);
        }
        // result数组中存的是 “根 右 左”，逆置转为后序遍历输出
        reverse(result.begin(), result.end());   // 要加上头文件 algorithm
        return result;
    }
};


int main() {
    TreeNode *left = new TreeNode(2, NULL, NULL);
    TreeNode *right = new TreeNode(3, NULL, NULL);
    TreeNode *root = new TreeNode(1, left, right);

    Solution_iterate s;
    vector<int> vec;
    vec = s.postorderTraversal(root);

    return 0;
}

