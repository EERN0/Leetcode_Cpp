// https://leetcode.cn/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
// Created by caokang on 2023/12/28.
#include <vector>

using namespace std;

class Node {
public:
    int val{};
    Node *left{};
    Node *right{};

    Node() {}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node *_left, Node *_right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    // 中序遍历(左根右)，将节点存到数组中
    void traversal(vector<Node *> &vec, Node *cur) {
        if (cur == nullptr) return;

        traversal(vec, cur->left);
        vec.push_back(cur);
        traversal(vec, cur->right);
    }

    Node *treeToDoublyList(Node *root) {
        vector<Node *> vec;
        traversal(vec, root);   // 中序遍历拿到从小到大的序列
        if (vec.empty()) return nullptr;

        for (int i = 0; i < vec.size(); ++i) {
            if (i != vec.size() - 1) {
                vec[i]->right = vec[i + 1];
            }
            else {
                vec[i]->right = vec[0];
            }
        }

        for (int i = vec.size() - 1; i >= 0; --i) {
            if (i != 0) {
                vec[i]->left = vec[i - 1];
            }
            else {
                vec[i]->left = vec[vec.size() - 1];
            }
        }
        return vec[0];
    }
};