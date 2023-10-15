/*
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
 * */
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int> &nums1, vector<int> &nums2) {
        // dp[i][j]: nums1[i-1]和nums2[j-1]最长重复子数组的长度
        // dp[i][0]和dp[0][j]没有意义，初始化为0
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        int maxLength = 0;
        for (int i = 1; i <= nums1.size(); ++i) {
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                if (maxLength < dp[i][j]) maxLength = dp[i][j];
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};