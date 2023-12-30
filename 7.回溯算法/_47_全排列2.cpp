// Created by caokang on 2023/5/13.
// https://leetcode.cn/problems/permutations-ii/
#include <vector>
#include <unordered_set>

using namespace std;

// nums有重复元素，要去重
// 树层去重，可以用set；也可以排序nums数组后，用used数组来去重，和子集2一样
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, vector<bool> used) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        unordered_set<int> uset;    // 同一个父节点的树层共用一个uset
        for (int i = 0; i < nums.size(); ++i) {
            // nums[i]已经在path里了
            // 或者 树的每一层有重复元素，eg：1 1 2 第一轮选了1（后面选1、2），第二轮又选了1（后面也可以选1、2），这样肯定就重复了
            // 这两种情况直接跳过本次循环
            if (used[i] || uset.count(nums[i])) {
                continue;
            }
            else {
                path.push_back(nums[i]);
                used[i] = true;
                uset.insert(nums[i]);

                backtracking(nums, used);

                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

int main() {
    vector<int> nums = {1, 2, 1};
    Solution solution;
    vector<vector<int>> res = solution.permuteUnique(nums);

}