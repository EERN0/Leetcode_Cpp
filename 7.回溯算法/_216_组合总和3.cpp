/*
 * https://leetcode.cn/problems/combination-sum-iii/
 *
 * 和77基本一样，想清楚递归逻辑
 * */
#include <vector>

using namespace std;

// 回溯
class Solution1 {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int k, int targetSum, int sum, int startIndex) {
        if (sum > targetSum || path.size() > k) return;
        if (path.size() == k && sum == targetSum) {
            result.push_back(path);
        }

        for (int i = startIndex; i <= 9; ++i) {
            path.push_back(i);
            sum += i;
            // 每个数字只能出现1次
            backtracking(k, targetSum, sum, i + 1);

            // 回溯撤销
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 0, 1);
        return result;
    }
};

// 之前乱写的
class Solution2 {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int k, int n, int startIndex) {
        // 终止条件，k个数，和为n
        if (path.size() == k) {
            int sum = 0;
            for (const auto &o: path) {
                sum += o;
            }

            if (sum == n) {
                result.push_back(path);
                return;
            }
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i <= 9; ++i) {    // 1~9的数，startIndex避免重复
            // 收集结果
            path.push_back(i);

            // 递归
            backtracking(k, n, i + 1);

            // 回溯，撤销处理结果
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1);

        return result;
    }
};