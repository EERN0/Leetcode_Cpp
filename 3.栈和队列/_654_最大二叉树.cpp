#include<iostream>
#include<vector>
#include<stack>

using namespace std;

// https://leetcode-cn.com/problems/maximum-binary-tree/

// 树节点定义
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
    // 分治法 —— 递归找出[l, r)的根节点(最大值)
    TreeNode *findMaxIdx(vector<int> &nums, int l, int r) {
        // 递归结束条件
        if (l == r) return NULL;
        int maxIdx = l;
        for (int i = l + 1; i < r; i++) {
            // 得到nums数组的[l,r)区间最大值索引
            if (nums[maxIdx] < nums[i]) maxIdx = i;
        }

        // 根节点
        TreeNode *root = new TreeNode(nums[maxIdx]);
        // 根节点的左子树
        root->left = findMaxIdx(nums, l, maxIdx);
        // 根节点的左子树
        root->right = findMaxIdx(nums, maxIdx + 1, r);

        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) return NULL;
        return findMaxIdx(nums, 0, nums.size());
    }
};

// 变种题 —— 返回一个数组，数组里面存放着每个父节点的索引（双亲表示法）
// 利用【单调递减栈】求左、右第一个比它大的元素
class stackDecrease {
public:
    vector<int> parentIndexes(vector<int> &nums) {
        // 分别用两个数组保存该元素左边、右边第一个比它大的索引
        vector<int> lmaxIdx;
        vector<int> rmaxIdx;
        stack<int> s;   // 栈中存放的是数组nums的索引
        // 初始化两个数组，-1表示该元素 左边或 右边没有比它大的
        for (int i = 0; i < nums.size(); ++i) {
            lmaxIdx[i] = -1;
            rmaxIdx[i] = -1;
        }

        // 扫描一边数组nums，维持单调递减栈
        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                // 元素右边第一个比它大的索引是i
                rmaxIdx[s.top()] = i;
                s.pop();
            }
            if (!s.empty()) {
                lmaxIdx[i] = s.top();
            }
            // 元素索引入栈
            s.push(i);
        }
    }
};


void test() {
    vector<int> nums = {3, 2, 1, 6, 0, 5};
}

int main() {
    test();
    return 0;
}