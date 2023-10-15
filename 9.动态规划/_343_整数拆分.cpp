/*
 * https://leetcode.cn/problems/integer-break/
 * */

#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {

        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 1;   // 2=1x1
        // dp[i]表示i拆成的几个数最大乘积为dp[i]
        vector<int> dp(n + 1, 0);

        /*
         * dp[i]最少能拆成2个数：j*(i-j)
         * 拆成3个数及以上：j*dp[i-j]
         * */
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i] = max(max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }
        return dp[n];
    }
};
