// https://leetcode.cn/problems/is-subsequence/
// Created by kang on 2023/8/30.
#include <string>
#include <vector>

using namespace std;

// 判断s和t的最长公共子序列的长度，如果等于s的长度，说明s是t的子序列
class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        // dp[i][j]：下标为i-1的s，和下标为j-1的t的最长公共子序列的长度为dp[i][j]
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= t.size(); ++j) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    else {
                        // s是子串，判断的是t中是否包含s，所以s可以不缩减，缩减t就行
                        dp[i][j] = dp[i][j - 1];

                        // 写成最长公共子序列那样也可以
                        // dp[i][j] = max(dp[i-1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        else return false;
    }
};