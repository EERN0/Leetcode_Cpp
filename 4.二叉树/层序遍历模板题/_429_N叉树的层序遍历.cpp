#include<iostream>
#include<vector>
#include<queue>
// https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/
using namespace std;

// N叉树结点
class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        queue<Node *> que;
        if (root == NULL) return {};
        que.push(root);
        while (!que.empty()) {
            int length = que.size();
            vector<int> inner;
            for (int i = 0; i < length; i++) {
                Node *node = que.front();
                que.pop();
                inner.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++) {
                    if (node->children[j] != NULL) que.push(node->children[j]);
                }
            }
            result.push_back(inner);
        }
        return result;
    }
};
