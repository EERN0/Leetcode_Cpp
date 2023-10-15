/*
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 简单dp，不输出具体连续递增子序列
class Solution1 {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() == 1) return 1;

        int size = nums.size();

        // dp[i]表示以nums[i]结尾的最长连续递增序列的长度
        vector<int> dp(size, 0);
        dp[0] = 1;

        int result = 0;
        for (int i = 1; i < size; ++i) {
            // 初始化dp[]，递增子序列长度最少是1
            dp[i] = 1;
            if (nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }

            result = max(result, dp[i]);
        }

        return result;
    }
};

// 输出最长连续递增子序列
// 最长连续递增子序列的索引为endIndex，在求maxLength时可以得到。后面把这几个数依次存到result数组中，逆序输出
class Solution2 {
public:
    vector<int> findLengthOfLCIS(vector<int> &nums) {
        if (nums.size() == 1) return nums;

        int size = nums.size();

        // dp[i]表示以nums[i]结尾的最长连续递增序列的长度
        vector<int> dp(size, 1);    // 初始化dp[]，递增子序列长度最少是1

        int maxLength = 1;
        int endIndex = 0; // 最长连续递增序列结束的位置
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = max(dp[i], dp[i - 1] + 1);
            }

            if (dp[i] > maxLength) {
                maxLength = dp[i];
                endIndex = i;
            }
        }

        vector<int> result;
        // 输出最长连续递增序列
        for (int i = endIndex; i >= endIndex - maxLength + 1; --i) {
            result.push_back(nums[i]);
        }

        reverse(result.begin(), result.end());  // 逆置
        return result;
    }
};

int main() {
    Solution2 s2;
    vector<int> nums = {1, 3, 5, 4, 7};  // 1 3 5
    nums = {1, 9, 2, 5, 7, 3, 4, 6, 8, 0};  // 3 4 6 8

    vector<int> res = s2.findLengthOfLCIS(nums);

    for (const auto &num: res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}