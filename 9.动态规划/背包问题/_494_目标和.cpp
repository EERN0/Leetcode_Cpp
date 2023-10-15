// Created by caokang on 2023/4/29.
// https://leetcode.cn/problems/target-sum/
// 在求装满背包有几种方法的情况下，递推公式一般为：dp[j] += dp[j - nums[i]]
#include <vector>
#include <algorithm>

using namespace std;

// 可以用回溯写，但可能超时
// 怎么转换为背包问题？放加法的是1个集合，放减法的是1个集合
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int sum = 0;
        for (const int &num: nums) {
            sum += num;
        }

        if (abs(target) > sum) return 0;    // 没有方案，target的范围是[-sum, sum]
        if ((sum + target) % 2 == 1) return 0;  // sum+target为奇数时，没有方案

        // 加法集合中元素和为addsum，nums中剩下的元素全放到减法集合里，和为b，满足：addsum+b=sum, addsum-b=target，所以addsum=(sum+target)/2
        // 所以，本题可以转换为：装满容量为addsum的背包，共有多少种方式？
        int addsum = (sum + target) / 2;

        // dp[j]：装满容量为j的背包，有dp[j]种方法（添加元素，使集合里元素之和为j的方法有dp[j]种）
        vector<int> dp(addsum + 1, 0);
        // 装满容量为0的背包，有一种方法
        dp[0] = 1;      // dp[0]必须初始化为1

        for (int i = 0; i < nums.size(); ++i) {             // 物品
            for (int j = addsum; j >= nums[i]; --j) {       // 背包
                // 理解递推公式，dp[j]是方法数，例如{1，2，3，4}，装满容量为5的背包。
                // 含有1时，背包容量为4，dp[4]凑成dp[5]；含有2时，背包容量为3，dp[3]凑成dp[5]
                // 含有3时，背包容量为2，dp[2]凑成dp[5]；含有4时，背包容量为1，dp[1]凑成dp[5]
                // 所以，装满容量为5的背包的方法数，是dp[4]+dp[3]+dp[2]+dp[1]
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[addsum];
    }
};