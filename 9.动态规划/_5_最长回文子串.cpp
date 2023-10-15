/*
 * https://leetcode.cn/problems/longest-palindromic-substring/
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 只输出1个结果
class Solution1 {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        int size = s.size();
        // 至少两个字符
        int maxLength = 0;
        int maxStart;   // 最长回文字串的起点

        // dp[i][j]: 若[i,j]子串是回文的，则dp[i][j]=true
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        // 根据递推式决定初始化dp数组的顺序, 由dp[i+1][j-1]推出dp[i][j], 所以要这个顺序
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                // [i,j]是回文子串的条件
                if (s[i] == s[j]) {
                    if (j - i <= 2) {   // s[i]到s[j]最多一共3个字符，且s[i]==s[j]，那么s[i,j]是回文子串。例如，aa，aba
                        dp[i][j] = true;
                    }
                    else {   // s[i...j]不止三个字符，因为s[i]==s[j]，只有在[i+1,j-1]是回文串时，[i,j]才能是回文串
                        if (dp[i + 1][j - 1]) {
                            dp[i][j] = true;
                        }
                    }
                }

                if (dp[i][j] && (j - i + 1 > maxLength)) {  // [i,j]是回文的，更新最大值
                    maxStart = i;
                    maxLength = j - i + 1;
                }
            }
        }

        string res = s.substr(maxStart, maxLength);
        return res;
    }
};


// 输出所有最长回文子串
class Solution2 {
public:
    vector<string> longestPalindrome(string s) {
//        if (s.size() <= 1) return s;

        int size = s.size();
        // dp[i][j]：[i,j]子串是回文子串，则dp[i][j]==true
        vector<vector<bool>> dp(size, vector<bool>(size, false));

        vector<string> res;
        vector<string> res2;

        int maxLength = 0;
        int startIndex = 0;
        // 回文子串要满足的条件见笔记
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {    // [i,j]，j必须大于等于i
                // s[i]==s[j]时，[i,j]才有可能是回文子串
                if (s[i] == s[j]) {
                    if (j - i <= 2) {   // [i,j]最多三个字符时，且s[i]等于s[j]，一定是回文子串。例如：aa，aba
                        dp[i][j] = true;
                    }
                    else {  // [i,j]不止3个字符，只有在[i+1,j-1]是回文串时，[i,j]才能是回文串
                        if (dp[i + 1][j - 1]) {
                            dp[i][j] = true;
                        }
                    }
                }

                // 获取所有的回文子串
                if (dp[i][j] && j - i + 1 >= maxLength) {
                    maxLength = j - i + 1;
                    startIndex = i;
                    res.push_back(s.substr(startIndex, maxLength));
                }
            }
        }

        // 拿到最长的回文子串
        for (string &str: res) {
            if (str.size() == maxLength) {
                res2.push_back(str);
            }
        }
        return res2;
    }
};

int main() {
    Solution1 solution1;
    string s = "abcdasdfghjkldcba";
    s = "cbbd";
    string res = solution1.longestPalindrome(s);

    cout << res << endl;
    return 0;
}