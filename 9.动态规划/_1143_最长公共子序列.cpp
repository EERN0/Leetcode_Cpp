// https://leetcode.cn/problems/longest-common-subsequence/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // dp[i][j]: 以下标i-1为结尾的text1，和以下标j-1为结尾的text2，最长公共子序列的长度为dp[i][j]
        // dp[0][j]没有意义(空串和另一个串的最长公共子序列的长度是0)，所以dp[i][0]和dp[0][j]都设置为0
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

//        int maxLength = 0;
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                // 如果这两个字符相同，那就在排除这两个元素的状态的基础上，长度+1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else { // 两元素明显不同了，可以不考虑一个元素
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }

//                maxLength = max(maxLength, dp[i][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    Solution solution;
    int res = solution.longestCommonSubsequence("ABCBDAB", "BDCABA");
    cout << res << endl;
    return 0;
}