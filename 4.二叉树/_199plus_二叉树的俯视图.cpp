#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include "二叉树结构体.hpp"

using namespace std;

// 俯视图
class Solution_Top {
public:
    vector<int> topView(TreeNode *root) {
        if (root == nullptr)
            return {};

        TreeNode *temp = nullptr;

        queue<pair<TreeNode *, int>> queue;

        map<int, int> mp;

        vector<int> result;

        // 根节点的坐标x为0，左节点为负，右节点为正
        queue.push({root, 0});

        while (!queue.empty()) {
            temp = queue.front().first;
            int x = queue.front().second;
            queue.pop();

            // map中没有坐标x，把节点的val值存到map中，map的key为坐标x
            // 坐标值x只存第一次出现的
            if (mp.find(x) == mp.end()) {
                mp[x] = temp->val;
            }

            if (temp->left != nullptr) {
                queue.push({temp->left, x - 1});
            }

            if (temp->right != nullptr) {
                queue.push({temp->right, x + 1});
            }
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            // map的第二个元素才是节点值
            result.push_back((*it).second);
        }

        return result;
    }
};

int main() {
    /* 创建二叉树
            1
          /   \
         2     3
          \   / \
           4 5  10
          /
         6
        /
       7
     */
    TreeNode *node1 = new TreeNode(7, nullptr, nullptr);
    TreeNode *node2 = new TreeNode(6, node1, nullptr);
    TreeNode *node3 = new TreeNode(4, node2, nullptr);
    TreeNode *node4 = new TreeNode(2, nullptr, node3);

    TreeNode *node5 = new TreeNode(5, nullptr, nullptr);
    TreeNode *node6 = new TreeNode(10, nullptr, nullptr);
    TreeNode *node7 = new TreeNode(3, node5, node6);

    TreeNode *node0 = new TreeNode(1, node4, node7);

    Solution_Top s1;
    vector<int> res = s1.topView(node0);

    for (auto o: res) {
        cout << o << " ";
    }

    return 0;
}
