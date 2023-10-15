// Created by caokang on 2023/5/9.
// https://leetcode.cn/problems/subsets-ii/
// 去重，和lc40组合总和2一样
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &nums, int startIndex, vector<bool> &used) {
        result.push_back(path);
        // 可以不加递归终止条件，当startIndex等于nums.size时，会自动return
//        if (startIndex >= nums.size())  {
//            return;
//        }

        for (int i = startIndex; i < nums.size(); ++i) {
            if (i >= 1 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;

            backtracking(nums, i + 1, used);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        backtracking(nums, 0, used);

        return result;
    }
};