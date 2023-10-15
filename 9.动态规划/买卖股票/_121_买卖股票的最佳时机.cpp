/*
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 * */
#include <vector>
#include <iostream>

using namespace std;


// 动态规划
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n <= 1) return 0;   // 只有1天，不能获得利润

        /* 只能买卖一次，买之前的现金为0
         * dp[i][0]: 第i天或之前，不持有股票的最大现金（不持有股票：一直没买或之前卖出了股票）
         * dp[i][1]: 第i天或之前，持有股票的最大现金（第i天买入、第i-1天或之前就买入了）
         * */
        vector<vector<int>> dp(n, vector<int>(2));  // dp[i][0]或dp[i][1]，第二位就这两种取值

        dp[0][0] = 0;   // 初始现金为0
        dp[0][1] = -prices[0];  // 第0天买入股票

        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 第i天没有卖掉股票(或者根本就没买股票)、第i天卖掉了股票(第i-1天肯定是持有股票的)
            dp[i][1] = max(0 - prices[i], dp[i - 1][1]);            // 第i天买入了股票、第i天没有买入股票
        }

        // 返回最后一天不持有股票时的最大现金
        return dp[n - 1][0];
    }
};

// 贪心
class Solution2 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;   // 没有利润

        int minBuyIn = prices[0];    // 最小买入价格
        int maxProfit = 0;           // 最大利润

        for (int price: prices) {
            // 最小买入价格
            minBuyIn = min(minBuyIn, price);
            // 利润 = 第i天卖出-最小买入价格，取最大者
            maxProfit = max(maxProfit, price - minBuyIn);
        }

        return maxProfit;
    }
};

// 贪心，记录买入和卖出的日期
class Solution3 {
public:
    pair<int, int> maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return {0, 0};   // 没有利润

        int minPrice = prices[0];    // 最小买入价格
        int maxProfit = 0;           // 最大利润

        int buyDataIndex = 0, saleDataIndex = 1;    // 买入和卖出不能在同一天

        for (int i = 1; i < prices.size(); i++) {
            // 最小买入价格
            minPrice = min(minPrice, prices[i]);

            // 第i天卖出 - 之前买入的最小价格
            if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
                saleDataIndex = i;

                // 获得最大利润后，更新最小价格买入股票的时间（可以保证在卖出之前买入股票）
                for (int j = 0; j < prices.size(); ++j) {
                    if (minPrice == prices[j]) buyDataIndex = j;
                }
            }
        }
        pair<int, int> res = {buyDataIndex, saleDataIndex};
        return res;
    }
};

int main() {
    vector<int> prices = {7, 4, 5, 10, 1, 2};
    Solution3 s;
    pair<int, int> res = s.maxProfit(prices);

    cout << "buyDate: " << res.first << ", saleDate: " << res.second << endl;

    return 0;
}