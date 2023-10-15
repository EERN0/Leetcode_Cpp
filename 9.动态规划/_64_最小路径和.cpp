// https://leetcode.cn/problems/minimum-path-sum/description/
// Created by kang on 2023/9/4.
#include <vector>
#include <iostream>

using namespace std;

class Solution64 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        // dp[i][j]：从(0,0)到(i,j)的最小路径和为dp[i][j]
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 避免dp[0][0]被累加多次！这样会导致grid只有一个元素时出错
        dp[0][0] = grid[0][0];

        // 初始化第一行（排除dp[0][0]）
        for (int j = 1; j < n; ++j) {
            for (int k = 0; k <= j; ++k) {
                dp[0][j] += grid[0][k];
            }
        }
        // 初始化第一列（排除dp[0][0]）
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][0] += grid[j][0];
            }
        }
//        cout << "dp[0][0]: " << dp[0][0] << endl;

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    vector<vector<int>> grid = {{1}};
    Solution64 solution;
    int res = solution.minPathSum(grid);
    cout << res << endl;
}