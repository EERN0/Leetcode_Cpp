// Created by caokang on 2023/4/29.
// https://leetcode.cn/problems/coin-change-ii/
#include <vector>

using namespace std;
// 完全背包，组合而非排序，不强调元素顺序
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        // dp[j]: 容量为j的背包，装满背包的硬币组合方案数为dp[j]
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i) {            // 物品
            for (int j = coins[i]; j <= amount; ++j) {      // 背包，正序遍历才是完全背包
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};