/*
 * https://leetcode.cn/problems/permutations/
 * */
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(vector<int> nums, vector<bool> used) {
        // 终止条件，排列大小为size时，收集起来
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // 单层递归逻辑
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {  // used[i]==true，表示已经取过nums[i]了
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;

            // 递归
            backtracking(nums, used);

            // 回溯操作
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        vector<bool> used(nums.size(), false);

        backtracking(nums, used);

        return result;
    }
};