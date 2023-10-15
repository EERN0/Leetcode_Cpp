// Created by caokang on 2023/4/30.
// https://leetcode.cn/problems/house-robber-ii/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 打家劫舍，房子连成环
class Solution {
public:
    // 打家劫舍普通版本
    int robNormal(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        // dp[i]: 考虑下标i(含i)以内的房子，可以偷的最大金额为dp[i]
        vector<int> dp(nums.size(), 0);
        // 初始化
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        // 递推公式
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }

    // 房子连成环的打家劫舍
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];
        // 将nums分为: 包含第1个房子但不包含最后1个房子[0, size-2]、不包括第1个房子但包括最后1个房子[1, size-1]两种情况
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());

        int maxMoney1 = robNormal(nums1);
        int maxMoney2 = robNormal(nums2);

        return max(maxMoney1, maxMoney2);
    }
};