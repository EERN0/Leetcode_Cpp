// Created by caokang on 2023/4/29.
// https://leetcode.cn/problems/last-stone-weight-ii/
#include <vector>

using namespace std;

// 0-1背包，两堆价值(重量)最接近
class Solution {
public:
    int lastStoneWeightII(vector<int> &stones) {
        int sum = 0;    // 所有石头的总重量
        for (const int &stone: stones) {
            sum += stone;
        }
        int target = sum / 2; //  一堆石头最多能容纳的重量

        // dp[j]：背包容量为j，能容纳的石头的最大重量
        vector<int> dp(1501, 0);    // 可以全初始化为0

        for (int i = 0; i < stones.size(); ++i) {
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);  // stones[i]既是重量又是价值
            }
        }

        int result = sum - dp[target] - dp[target];
        return result;
    }
};