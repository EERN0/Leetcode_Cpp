/*
 * https://leetcode.cn/problems/edit-distance/
 * */
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]: 以下标i-1为结尾的字符串word1，和以下标j-1为结尾的字符串word2，最近编辑距离(最少操作数)为dp[i][j]
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT32_MAX));

        // dp[i][0]: 下标i-1结尾的字符串word1转换为空串的最少操作数为i次
        for (int i = 0; i <= word1.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    // 删除和增加是一样的
                    // 替换操作：ab  ac进行替换时，都往前走一个，然后替换后面一个字符就行，所以是由dp[i-1][j-1]+1推过来的
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};


int minDistance(string word1, string word2) {
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    // dp[i][j]：下标i-1结尾的word1 转换成 下标j-1结尾的word2所使用的【最少操作次数】为dp[i][j]
    // i的取值范围0~word1.size
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, INT32_MAX));

    // 初始化
    // dp[i][0]：以下标i-1结尾的字符串word1，转换为空串(以下标-1结尾的word2是空串)的最少操作次数为dp[i][0]=i (word1下标0~i-1，共i个字符)
    // dp[0][j]=j，同理

    dp[0][0] = 0;
    for (int i = 1; i <= word1.size(); ++i) {
        dp[i][0] = i;
        for (int j = 1; j <= word2.size(); ++j) {
            dp[0][j] = j;

            // dp[i][j]的递推关系，由word1[i-1]和word2[j-1]是否相同决定
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                // word1[i-1]!=word2[j-1]，让word1转换为word2
                // word1删除字符word1[i-1] 转换成 word2，dp[i][j]=dp[i-1][j]+1
                // word1增加字符 转换成 word2，相当于word2删除字符word2[j-1]，dp[i][j]=dp[i][j-1]+1
                // word1修改字符word1[i-1] 变为 word2，dp[i][j]=dp[i-1][j-1]+1
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
            }
        }
    }
    return dp[word1.size()][word2.size()];
}