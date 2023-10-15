#include<iostream>
#include<vector>
#include<stack>
#include "二叉树结构体.hpp"

using namespace std;

// 中序遍历：左、中、右
// 中序遍历-递归
class Solution_recursion {
public:
    void traversal(vector<int> &v, TreeNode *cur) {
        // 递归结束条件
        if (cur == nullptr) return;
        traversal(v, cur->left);      // 左
        v.push_back(cur->val);               // 根
        traversal(v, cur->right);    // 右
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        traversal(result, root);
        return result;
    }
};

// 迭代
class Solution_iterate {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};

        vector<int> result;         // 输出数组
        stack<TreeNode *> st;       // 栈
        TreeNode *cur = root;       // 扫描指针

        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {      // 扫描指针所指结点非空，入栈，并且往左走
                st.push(cur);
                cur = cur->left;       // 左孩子
            }
            else {                     // 扫描指针为空，说明上一个节点是叶子或者只有右孩子，处理栈中的元素
                cur = st.top();
                st.pop();
                result.push_back(cur->val);     // 中间节点存入数组
                cur = cur->right;       // 右孩子
            }
        }
        return result;
    }
};


// Morris 中序遍历


int main() {
    auto *left = new TreeNode(2, nullptr, nullptr);
    auto *right = new TreeNode(3, nullptr, nullptr);
    auto *root = new TreeNode(1, left, right);

    Solution_iterate s;
    vector<int> vec;
    vec = s.inorderTraversal(root);

    for (auto o: vec) {
        cout << o << " ";
    }

    return 0;
}

