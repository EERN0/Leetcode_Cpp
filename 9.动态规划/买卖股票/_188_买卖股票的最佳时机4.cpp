// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
// Created by caokang on 2023/7/2.
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        if (n <= 1 || k == 0) return 0;

        // 最多可以买卖k次股票，有2k+1种状态，dp[i][0]（不操作）~ dp[i][2k]（第k次不持有股票）的最大现金
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));   // 0~n-1天一个n天
        dp[0][0] = 0;   // 不操作
//        // 第1次持有股票
//        dp[0][1] = 0 - prices[0];
//        // 第1次不持有股票
//        dp[0][2] = 0;
//        // 第2次持有股票
//        dp[0][3] = 0 - prices[0];

        // 初始化
        for (int i = 0; i < 2 * k + 1; ++i) {
            // 不持有股票
            if (i % 2 == 0) {
                dp[0][i] = 0;
            }
            else {  // 持有股票
                dp[0][i] = -prices[0];
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 2 * k + 1; ++j) {
                if (j == 0) {           // 不操作，维持前一天的状态
                    dp[i][0] = dp[i - 1][0];
                }
                else if (j % 2 == 0) {  // 不持有股票
                    // dp[i-1][j-1]是第i-1天不持有持有股票的最大现金
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                }
                else {  // 持有股票
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }
            }
        }
        // 最后一天，k次买卖股票后的最大现金
        return dp[n - 1][2 * k];
    }
};

int main() {
    Solution solution;
    vector<int> prices = {2, 4, 1};
    int res = solution.maxProfit(2, prices);
    cout << res << endl;

    return 0;
}