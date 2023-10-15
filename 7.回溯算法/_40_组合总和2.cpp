/*
 * https://leetcode.cn/problems/combination-sum-ii/
 *
 * candidates[]中有重复元素
 * */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &candidates, int target, vector<bool> used, int sum, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            // 树层去重操作
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                // i和i-1的两数相同，且used[i-1]为false，说明是树层上的重复(同一层)   eg: nums=[1 1 2]，前面用过[1 2]，后面又到了[1 2](第二个1),这两种是重复的，
                // 若used[i-1]为true，说明是树枝上相同，即取了[1 1]这两个一样的数，符合要求，不用去重(虽然它们之和不为3)
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;

            backtracking(candidates, target, used, sum, i + 1);
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // 先排序
        sort(candidates.begin(), candidates.end());

        vector<bool> used(candidates.size(), false);

        backtracking(candidates, target, used, 0, 0);
        return result;
    }
};