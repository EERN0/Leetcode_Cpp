// Created by caokang on 2023/5/2.
// https://leetcode.cn/problems/longest-valid-parentheses/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 动态规划
class Solution1 {
public:
    int longestValidParentheses(string s) {
        if (s.empty() || s.size() == 1) return 0;
        // 有效括号的开头和结尾必然是 (...)

        int maxValid = 0;
        // dp[i]: 以i字符结尾的最长有效括号的长度为dp[i]
        vector<int> dp(s.size(), 0);        // 全初始化为0

        // 以左括号结尾的有效括号长度直接为0，只用处理右括号
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                // pre是可能与当前右括号i相匹配的左括号下标
                // 1.若前一个字符i-1是'('，dp[i-1]为0，直接匹配上了
                // 2.若前一个字符i-1是')'，则dp[i-1]是前一个右括号形成的有效括号长度，减去该长度再往前找1个
                int pre = i - dp[i - 1] - 1;

                if (pre >= 0 && s[pre] == '(') {    // 找到了与i匹配的左括号
                    dp[i] = dp[i - 1] + 2;

                    // 上面的dp[i]只能处理"( ( ( ) ) )" 这种情况，漏掉了连续最长有效括号的情况，即右括号左边一个总是与之相匹配的左括号: )()()()、())()(()())
                    // dp[i]并不是连续的最长有效括号的长度，要加上当前右括号匹配的左括号s[pre]的前一个有效括号的长度
                    // 遍历是从前往后的，所以每轮只用累加一次
                    if (pre - 1 >= 0) {
                        dp[i] += dp[pre - 1];
                    }
                }
            }
            maxValid = max(maxValid, dp[i]);
        }
        return maxValid;
    }
};

int main() {
    Solution1 solution1;
    string string1 = ")()()()";  // 6
    string1 = "())()(()())";     // 8
    int res = solution1.longestValidParentheses(string1);
    cout << res << endl;

    return 0;
}