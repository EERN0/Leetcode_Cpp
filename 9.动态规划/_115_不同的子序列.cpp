// https://leetcode.cn/problems/distinct-subsequences/
// Created by kang on 2023/8/30.
#include <string>
#include <vector>

using namespace std;

// 有点难理解了
// s中删除元素能不能变成t
class Solution115 {
public:
    int numDistinct(string s, string t) {
        // dp[i][j]：以s[i-1]结尾的子序列中，有以t[j-1]结尾的子序列的个数为dp[i][j]
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        // 初始化：dp[i][0]=1，t是空串，在s[i-1]子序列出现的次数是1次
        // dp[0][j]=0，s是空串，t[j-1]子序列在空串出现的次数是0
        for (int i = 0; i <= s.size(); ++i) {
            for (int j = 0; j <= t.size(); ++j) {
                if (i == 0 || j == 0) {
                    if (i == 0 && j == 0) dp[0][0] = 1; // 两个都是空串
                    else if (i == 0) dp[0][j] = 0;
                    else dp[i][0] = 1;
                }
                else {
                    if (s[i - 1] == t[j - 1]) {
                        // s[i-1]==t[i-1]时，s、t都往前移动一个，或者不考虑s[i-1]，相当于删除了s[i-1]字符，类似s=bagg、t=bag的情况
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    }
                    else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};