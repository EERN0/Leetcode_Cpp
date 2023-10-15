// https://leetcode.cn/problems/delete-operation-for-two-strings/
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]：word1[i-1] 和 word[j-1] 变得相同所需要的删除操作最小步数为dp[i][j]
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT32_MAX));

        for (int i = 0; i <= word1.size(); ++i) {
            for (int j = 0; j <= word2.size(); ++j) {
                if (i == 0 || j == 0) {
                    if (i == 0 && j == 0) dp[0][0] = 0;
                    else if (i == 0) {  // dp[0][j]：word2[j-1]转为空串的最小操作次数为j
                        dp[0][j] = j;
                    }
                    else {  // j==0
                        dp[i][0] = i;
                    }
                }
                else {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else {
                        // 删除一个，或者删除两个，取最小值
                        dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 2);
                    }
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};