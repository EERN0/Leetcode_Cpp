#include<iostream>
#include<vector>
#include<queue>
// https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> result;
        queue<TreeNode *> que;
        if (root == NULL) return {};
        que.push(root);

        while (!que.empty()) {
            int length = que.size();
            vector<int> temp;
            int max = que.front()->val;
            for (int i = 0; i < length; i++) {
                TreeNode *node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                // 找该层的最大值
                if (max < temp[i]) max = temp[i];
            }
            // 找该层的最大值
//            int max = temp[0];
//            for (int j = 1; j < temp.size(); ++j) {
//                if (temp[j] > max) max = temp[j];
//            }
            result.push_back(max);
        }
        return result;
    }
};
