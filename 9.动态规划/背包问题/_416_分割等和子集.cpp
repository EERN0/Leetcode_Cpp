// Created by caokang on 2023/4/29.
// https://leetcode.cn/problems/partition-equal-subset-sum/
#include <vector>

using namespace std;

// 0-1背包，两堆价值相等
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = 0;
        for (const auto &num: nums) {
            sum += num;
        }
        if (sum % 2 == 1) return false;

        // dp[j]: 容量为j的背包，能装物品的最大价值是dp[j]
        vector<int> dp(sum / 2, 0);

        // nums[i]既是物品i的重量，也是价值
        for (int i = 0; i < nums.size(); ++i) {     // 物品
            for (int j = sum / 2; j >= nums[i]; --j) {    // 背包容量，倒序遍历
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);

                if (dp[j] == sum / 2) return true;
            }
        }
        return false;
    }
};