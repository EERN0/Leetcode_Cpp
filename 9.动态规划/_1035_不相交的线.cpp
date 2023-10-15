// https://leetcode.cn/problems/uncrossed-lines/
// Created by kang on 2023/8/30.
// 和最长公共子序列一模一样
#include <vector>

using namespace std;

class Solution1035 {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        // dp[i][j]：以nums1[i-1]结尾的子序列，和以nums2[i-2]结尾的最长公共子序列的长度为dp[i][j]
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        for (int i = 0; i <= nums1.size(); ++i) {
            for (int j = 0; j <= nums2.size(); ++j) {
                if (i == 0 || j == 0) { // 和空序列的公共子序列的长度为0
                    dp[i][j] = 0;
                }
                else {
                    if (nums1[i - 1] == nums2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};
