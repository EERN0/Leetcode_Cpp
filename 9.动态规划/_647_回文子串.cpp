/*
 * https://leetcode.cn/problems/palindromic-substrings/
 * */
#include <string>
#include <vector>

using namespace std;

// 动态规划
class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len == 0) return 0;

        int cnt = 0;
        // [i...j]是回文串，dp[i][j]==true
        vector<vector<bool>> dp(len, vector<bool>(len, false));     // dp数组全初始化为false

        /* 遍历顺序很有讲究
         * 如果是从上到下，从左到右（i=0 -> len-1, j=0 -> len-1），在判断[i...j]时会用到没判断过的[i+1...j-1]
         * 由[i+1...j-1] => [i...j]时，一定要从下到上，从左到右（或先遍历列，再遍历行），保证先计算过dp[i + 1][j - 1]
         * */

//        // 从下到上，从左到右遍历
//        for (int i = len - 1; i >= 0; --i) {
//            for (int j = i; j < len; ++j) {
//                if (s[i] == s[j]) {
//                    if (j - i <= 1) {     // 只有1个或2个字符时，是回文串
//                        dp[i][j] = true;
//                        cnt++;
//                    }
//                    else if (dp[i + 1][j - 1]) { // 若[i+1 ... j-1]是回文的
//                        dp[i][j] = true;
//                        cnt++;
//                    }
//                }
//            }
//        }

        // 先遍历列，再遍历行，保证求[1...4]时，[2...3]已经计算过了
        for (int j = 0; j < len; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {     // 只有1个或2个字符时，是回文串
                        dp[i][j] = true;
                        cnt++;
                    }
                    else if (dp[i + 1][j - 1]) { // 若[i+1 ... j-1]是回文的
                        dp[i][j] = true;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};