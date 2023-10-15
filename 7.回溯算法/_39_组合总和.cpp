/*
 * https://leetcode.cn/problems/combination-sum/
 *
 * candidates[]中无重复元素
 * */
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &candidates, int target, int sum, int startIndex) {
        if (sum > target) return;
        if (sum == target) {
            result.push_back(path);
            return;
        }

        for (int i = startIndex; i < candidates.size(); ++i) {
            path.push_back(candidates[i]);
            sum += candidates[i];

            //递归，元素可以重复用，传入的是i(不是i+1)
            backtracking(candidates, target, sum, i);

            //回溯，撤销处理结果
            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return result;
    }
};