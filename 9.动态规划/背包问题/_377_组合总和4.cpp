// Created by caokang on 2023/4/29.
// https://leetcode.cn/problems/combination-sum-iv/
#include <iostream>
#include <vector>

using namespace std;

// 完全背包，强调元素顺序，求装满容量为target的背包的方法数，递推公式dp[j]+=dp[j-nums[i]]
// 注意：不是元素组合，而是元素排列，有顺序的，eg:(1,1,2)和(2,1,1)算两个
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        // dp[j]: 容量为j的背包，装满该背包的元素排列的方案数为dp[j]
        vector<int> dp(target + 1, 0);
        dp[0] = 1;  // 背包容量为0时，有一种方法。其余情况都初始化为0

        for (int j = 0; j <= target; ++j) {                 // 背包，正序遍历（每个物品可以取多次）
            for (int i = 0; i < nums.size(); ++i) {         // 物品
                if (nums[i] <= j && dp[j] < INT32_MAX - dp[j - nums[i]]) {
                    // 题目数据保证答案符合32位整数范围，忽略超过INT32_MAX的数据
                    dp[j] += dp[j - nums[i]];
                }
            }
        }
        return dp[target];
    }
};