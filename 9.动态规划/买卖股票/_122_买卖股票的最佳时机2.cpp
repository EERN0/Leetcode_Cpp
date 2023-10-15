/*
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
 * */
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        /*
         * dp[i][0]: [第i天]  [不持有股票]的最大现金（股票卖出可以在第i天，也可以在第i天之前）
         * dp[i][1]: [第i天]  [持有股票]的最大现金（可以在第i天买入股票，也可以在第i天之前买入股票）
         * */
        vector<vector<int>> dp(n, vector<int>(2, 0));

        dp[0][0] = 0;
        dp[0][1] = 0 - prices[0];

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);    // 第i天卖出股票、第i天之前卖出股票

            // 注意：可以多次买卖股票，最多只能持有一支股票：第i天买入股票时，第i-1天的最大现金是dp[i-1][0]，不是0
            // 第i天之前买入股票、第i天买入股票
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        }

        return dp[n-1][0];  // 最后一天不持有股票的最大现金
    }
};