// Created by caokang on 2023/4/30.
// https://leetcode.cn/problems/perfect-squares/
#include <vector>
#include <iostream>

using namespace std;

// 完全背包, 没强调顺序
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums = square(n);

        // dp[j]: 装满容量为j的背包，最小的物品数为dp[j]
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {     // 物品
            for (int j = nums[i]; j <= n; ++j) {    // 背包   正序遍历背包容量是完全背包
                dp[j] = min(dp[j], dp[j - nums[i]] + 1);
            }
        }

        // 任何正整数都能用完全平方数去凑，只要有1，就没有凑不成的n
        return dp[n];
    }

    // 求1~n之间的完全平方数
    vector<int> square(int n) {
        vector<int> squareNum = {};
        for (int i = 1; i <= n; ++i) {
            if (i * i <= n) {
                squareNum.push_back(i * i);
            }
        }
        return squareNum;
    }
};

class Solution2 {
public:
    int numSquares(int n) {
        // dp[j]: 装满容量为j的背包，最小的物品数为dp[j]
        vector<int> dp(n + 1, INT32_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; ++i) {              // 物品
            for (int j = i * i; j <= n; ++j) {      // 背包   正序遍历背包容量是完全背包
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        return dp[n];
    }
};