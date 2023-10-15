// https://leetcode.cn/problems/subtree-of-another-tree/
// 字节面试题，判断二叉树B是不是A的子结构,Created by caokang on 2023/5/30.
// 100(相同的树) -> 101(对称二叉树) -> 572(另一棵树的子树)
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}

    TreeNode(int value, TreeNode *left, TreeNode *right) : val(value), left(left), right(right) {}
};

// 双递归，还有kmp、树哈希（看不懂了）
class Solution {
public:
    // 判断两树是否相同
    bool isSameTree(TreeNode *r, TreeNode *t) {
        if (r == nullptr && t == nullptr) return true;
        return (r != nullptr) && (t != nullptr)
               && r->val == t->val
               && isSameTree(r->left, t->left)
               && isSameTree(r->right, t->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        // root和subRoot都为null，二者相同
//        if (root == nullptr && subRoot == nullptr) return true;

        // root为null，subRoot不会是root的子树
        // 题目中subRoot不为null，subRoot不会改变；而root是递归值，可以是root的孩子节点，只要root变为null了，subRoot就不会是root的子树
        if (root == nullptr) return false;

        // 两树相同 || B是A左子树的子树 || B是A右子树的子树
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *subRoot = new TreeNode(4, node1, node2);

//    TreeNode *n1 = new TreeNode(0);
    TreeNode *n2 = new TreeNode(2, nullptr, nullptr);
    TreeNode *n3 = new TreeNode(1);
    TreeNode *n4 = new TreeNode(4, n3, n2);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *root = new TreeNode(3, n4, n5);

    Solution solution;
    cout << solution.isSubtree(root, subRoot) << endl;

    return 0;
}