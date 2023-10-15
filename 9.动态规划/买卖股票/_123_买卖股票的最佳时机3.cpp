// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // i是i天，写成第i天习惯了
        // dp[i][0]：不操作，这里用不上
        // dp[i][1]：第1次持有股票的最大现金       dp[i][2]：第1次不持有股票的最大现金
        // dp[i][3]：第2次持有股票的最大现金       dp[i][4]：第2次不持有股票的最大现金
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][1] = 0 - prices[0];
        dp[0][2] = 0;               // 第0天，卖了又卖了股票
        dp[0][3] = 0 - prices[0];   // 第0天，买了卖了股票，又第二次买入股票
        dp[0][4] = 0;               // 第0天，第二次卖出股票的最大现金

        // 在第i天有没有变: 维持之前的状态，或者，
        for (int i = 1; i < n; ++i) {
            // 第1次持有股票的最大现金
            dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);

            // 第1次不持有股票的最大现金
            // dp[i-1][2]是维持之前不持有股票的状态、dp[i-1][1]+prices[i]是在第i天卖出了股票
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);

            // 第2次持有股票
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);

            // 第2次不持有股票
            // dp[i-1][4]维持之前第2次不持有股票的状态，dp[i-1][3]+prices[i]第i天是第二次卖掉股票了
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }

        // 最多两次买卖股票，max(dp[n-1][2], dp[n-1][4])是一样的
        return dp[n - 1][4];
    }
};