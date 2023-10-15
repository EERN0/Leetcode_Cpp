// https://leetcode.cn/problems/non-decreasing-subsequences/
// Created by caokang on 2023/6/13.
// 太难了，我是沙比
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

// 本题和子集2有区别，本题去重不能排序，用set来去重
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> &nums, int startIndex) {
        if (path.size() >= 2) {
            result.push_back(path);
        }

        // 每一个树层都有一个uset，存当前加入到递增子序列path中的元素，用来去重
        unordered_set<int> uset;
        for (int i = startIndex; i < nums.size(); ++i) {
            // 当前元素nums[i]要大于path最后一个元素，才收集到递增子序列path中
            if (!path.empty() && nums[i] < path.back() || uset.count(nums[i])) {
                continue;
            }

            path.push_back(nums[i]);
            uset.insert(nums[i]);

            backtracking(nums, i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int> &nums) {
        if (nums.size() <= 1) return {};

        backtracking(nums, 0);
        return result;
    }
};