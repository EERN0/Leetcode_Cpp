// Created by caokang on 2023/4/30.
// https://leetcode.cn/problems/house-robber/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 打印路径版本的打家劫舍
class Solution2 {
public:
    // 返回偷窃的房屋下标，从0开始
    vector<int> rob(vector<int> &nums) {
        if (nums.size() == 1) return {0};

        // dp[i][0]: 考虑下标i及以内的，不偷i号房子能获得的最大金额为dp[i][0]
        // dp[i][1]: 考虑下标i及以内的，偷i号房子能获得的最大金额为dp[i][1]
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));

        // 初始化
        dp[0][0] = 0, dp[0][1] = nums[0];
        dp[1][0] = nums[0], dp[1][1] = nums[1];

        for (int i = 2; i < nums.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);     // 不偷i号房子，i-1号偷不偷没有限制
            dp[i][1] = dp[i - 1][0] + nums[i];              // 偷i号房子，肯定不偷i-1号房子
        }
        // 偷取的最大金额，最后一个房子 偷或不偷，二者取最大值
        int maxMoney = max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);

        int target = maxMoney;
        vector<int> route = {};     // 打劫房子的下标

        // 找路径的核心：从打劫的房子往前找，dp[i][1]是打劫的房子
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (dp[i][1] == target) {
                route.push_back(i);
                target -= nums[i];
                i--;    // 不能连着打劫两个房子，所以间隔1个
            }
        }

        // 打印dp[][]数组，可以注释掉
        cout << "        " << "不偷 " << "偷" << endl;
        for (int i = 0; i < nums.size(); ++i) {
            cout << i << "号房子: " << dp[i][0] << "   " << dp[i][1] << endl;
        }

        reverse(route.begin(), route.end());

        return route;
    }
};

// 不输出路径
class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];

        // dp[i]: 考虑下标i(包括i)以内的，最多可以偷的金额为dp[i]
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // 偷完最大下标和之前的，就是偷到的最大值
        return dp[nums.size() - 1];
    }
};


int main() {
    Solution2 solution2;
    vector<int> nums = {5, 2, 3, 3, 3, 2, 5};   // ok
    nums = {5, 2, 1, 3, 1, 2, 5};   // ok
    nums = {2, 7, 9, 3, 1};     // ok
    nums = {1, 1, 1, 1, 1};     // ok

    vector<int> res = solution2.rob(nums);

    cout << "偷取的房子下标：";
    for (const int &o: res) {
        cout << o << " ";
    }

    return 0;
}