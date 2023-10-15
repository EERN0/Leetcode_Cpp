// Created by caokang on 2023/4/30.
// https://leetcode.cn/problems/word-break/
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 回溯也可以写！
// 完全背包，只能先遍历背包，再遍历物品
class Solution139 {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> wordSet;
        for (const string &str: wordDict) {
            wordSet.insert(str);
        }

        // dp[i]: 字符串长度为i，dp[i]为true，表示该字符串可以拆分为一个或多个在字典中出现的单词
        vector<bool> dp(s.size() + 1, false);

        // 为了递推公式，dp[0]必须被初始为true，否则dp[]全为false
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {    // 遍历背包
            for (int j = 0; j < i; ++j) {        // 遍历物品
                // dp[j]是0~j-1的字符串，dp[i]是0~i-1的字符串，要验证的是[j, i-1]的子串在不在字典中
                string word = s.substr(j, (i - 1) - j + 1);     // substr(起始位置, 截取个数)

                // dp[j]为true 且 s的子串[j,i-1]在字典中时，dp[i]才为true.    dp[i]是0~i-1的子串
                if (dp[j] && wordSet.find(word) != wordSet.end()) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};
