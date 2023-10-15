// https://leetcode.cn/problems/maximal-square/
// Created by caokang on 2023/6/18.
#include <vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        // 行或列为0，直接返回0
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size();

        // dp[i][j]：以(i,j)为右下角的正方形的最大边长为dp[i][j]
        vector<vector<int>> dp(row, vector<int>(col, 0));
        // 初始化，当行为0，或列为0时，且matrix[i][j]=='1'时，即以(i,0)或(0,j)为右下角的正方形最大边长只能是1

        int maxSlide = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    // 第一行或第一列，初始化为1
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    else {
                        // (i,j)形成的最大正方形边长由它上方、左方、左上方三个相邻位置的dp值决定
                        // 若三方dp有一个为0，(i,j)为右下角的正方形的最大边长为0+1=1
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    }
                }

                maxSlide = max(maxSlide, dp[i][j]);
            }
        }
        return maxSlide * maxSlide;
    }
};