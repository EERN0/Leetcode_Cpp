// Created by caokang on 2023/5/13.
// 牛客，要构建树才能用树形dp

#include <iostream>
#include <vector>

using namespace std;

// 二叉树结构体
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;

    TreeNode() : val(0), left(nullptr), right(nullptr), parent(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right((nullptr)), parent(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right, TreeNode *parent) : val(x),
                                                                         left(left), right(right), parent(parent) {}
};

int main() {
    int n = 0;
    cin >> n;
    int temp = n;
    vector<int> val(n, 0);
    vector<int> parent(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> parent[i];
    }
    // 构建一颗二叉树
    for (int i = 0; i < n; ++i) {
        auto node = new TreeNode()
    }
}