// Created by caokang on 2023/5/8.
// https://leetcode.cn/problems/subsets/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(const vector<int> &nums, int startIndex) {
        result.push_back(path);
        // 递归结束条件
        if (startIndex >= nums.size()) {    // // 可以不加递归终止条件，当startIndex等于nums.size时，会自动return
            return;
        }

        // 单层递归逻辑
        for (int i = startIndex; i < nums.size(); ++i) {
            path.push_back(nums[i]);

            backtracking(nums, i + 1);

            // 回溯撤销操作
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        backtracking(nums, 0);

        return result;
    }
};


// 打印二维数组
void printMatrix(vector<vector<int>> &A) {
    // 二维数组——A[[], [], []]  A.size()表示里面一维数组的个数
    int m = A.size();       // m行
    int n = A[0].size();    // n列

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) cout << "[";
            if (j == 0) cout << "[";
            if (j != n - 1) {
                cout << A[i][j] << ", ";
            }
            else if (j == n - 1) {
                if (i != m - 1) cout << A[i][j] << "]" << endl;
                else cout << A[i][j] << "]";
            }
            if (i == m - 1 && j == n - 1) cout << "]";
        }
    }
}

int main() {
    Solution solution;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = solution.subsets(nums);


    return 0;
}