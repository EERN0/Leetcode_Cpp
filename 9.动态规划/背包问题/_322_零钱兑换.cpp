// Created by caokang on 2023/4/28.
// https://leetcode.cn/problems/coin-change/
#include <vector>
#include <iostream>

using namespace std;

// 完全背包，本题求钱币最小个数，并不强调集合是组合还是排列
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        // dp[j]: 装满容量为j的背包，所需最少物品数为dp[j]
        vector<int> dp(amount + 1, INT32_MAX);

        dp[0] = 0;  // 容量为0的背包，最少能装物品数是0

        // 先遍历物品，再遍历背包，组合数
        for (int i = 0; i < coins.size(); ++i) {        // 物品
            for (int j = coins[i]; j <= amount; ++j) {  // 背包容量（正序遍历是完全背包）
                if (dp[j - coins[i]] == INT32_MAX) {
                    // dp[j-coins[i]]==INT32_MAX，加1后超过int的最大范围，会溢出
                    // 直接跳过这种情况
                    continue;
                }
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);   // dp[]是最少硬币数，是+1，而不是+coins[i]，拓竹面试写错了
            }
        }

        if (dp[amount] == INT32_MAX) {  // 没有物品组合能装满背包，例如，coins=[2,5]，amount=3
            return -1;
        }
        else return dp[amount];
    }
};

int main() {
    Solution solution;
    int num;
    vector<int> coins;
    // cin输入一个数组
    while (true) {
        // 遇到回车符结束输入
        if (cin.get() == '\n') {
            break;
        }

        cin >> num;
        coins.push_back(num);
    }

    int amount = 0;
    cin >> amount;

    int res = solution.coinChange(coins, amount);
    cout << res << endl;

    return 0;
}