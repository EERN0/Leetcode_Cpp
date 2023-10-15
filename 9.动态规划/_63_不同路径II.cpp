/*
 * https://leetcode.cn/problems/unique-paths-ii/
 * 有障碍物
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();    // 二维数组的行数
        int n = obstacleGrid[0].size(); // 二维数组的列数

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            // 起点和终点有障碍物
            return 0;
        }

        // dp[i][j]表示从(0,0)到(i,j)的不同路径数
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 初始化dp
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n && obstacleGrid[0][j] == 0; j++) {
            dp[0][j] = 1;
        }

        // 递推公式
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // obstacleGrid[i][j]=1表示无法到达(i,j), dp[i][j]默认为0
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};