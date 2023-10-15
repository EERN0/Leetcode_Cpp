#include<iostream>
#include<vector>
#include<queue>
// https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (root == NULL) return NULL;
        queue<Node *> que;
        que.push(root);
        while (!que.empty()) {
            Node *node;
            Node *nodePre;
            int length = que.size();

            for (int i = 0; i < length; ++i) {
                if (i == 0) {   // 取出一层的头结点
                    node = que.front();
                    que.pop();
                    nodePre = node;
                } else {
                    node = que.front();
                    que.pop();
                    nodePre->next = node;   // 链接一层的结点
                    nodePre = nodePre->next;
                }
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            nodePre->next = NULL;
        }
        return root;
    }
};

int main() {
    return 0;
}