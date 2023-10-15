/*
 * https://leetcode.cn/problems/longest-increasing-subsequence/
 * */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// 直接dp，没给出具体序列
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 1;

        // dp[i]: 以nums[i]结尾的最长递增子序列的数目
        vector<int> dp(nums.size());

        // 初始化，dp[i]都大于或等于1
        dp[0] = 1;

        int result = 0;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = 1;  // dp数组全初始化为1
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {    // 严格单增
                    // 递推关系
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            // 遍历dp数组，取最大值
            result = max(result, dp[i]);
        }
        return result;
    }
};


// 输出其中一个最长递增子序列
class Solution2 {
public:
    vector<int> lengthOfLIS(vector<int> &nums) {
        // dp[i]：以nums[i]结尾的最长严格递增子序列的长度为dp[i]
        vector<int> dp(nums.size(), 1);
        int maxLength = INT32_MIN;

        vector<int> res;
        int endIndex;   // 最长递增子序列最后的下标

        for (int i = 0; i < nums.size(); ++i) {
            dp[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {    // j...i，当nums[j]小于nums[i]时，更新dp[i]，dp[i]至少可以为dp[j]+1
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (maxLength < dp[i]) {
                maxLength = dp[i];
                endIndex = i;
            }
        }

        // 记录子序列的路径
        // 把dp数组列出来，从后往前找关系推，很容易就能推出来
        res.push_back(nums[endIndex]);
        int j = endIndex - 1;
        while (true) {
            if (dp[j] == dp[endIndex] - 1 && nums[j] < nums[endIndex]) {
                res.push_back(nums[j]);
                endIndex = j;
            }
            j--;

            if (res.size() == maxLength) break;
        }
        reverse(res.begin(), res.end());

        return res;
    }
};

int main() {
    Solution2 solution2;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    vector<int> res = solution2.lengthOfLIS(nums);
    cout << res.size() << endl;

    for (int re: res) {
        cout << re << " ";
    }

    return 0;
}