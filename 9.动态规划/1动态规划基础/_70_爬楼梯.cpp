/*
 * https://leetcode.cn/problems/climbing-stairs/
 * */
#include <iostream>
#include <vector>

using namespace std;

// 1 2 3 5 8
// 动态规划
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        // dp[i]表示i个台阶，有dp[i]种方法
        vector<int> dp(n + 1);  // 必须声明数组大小，求dp[n]，必须有n+1个元素
        dp[1] = 1;
        dp[2] = 2;  // 1+1或2

        for (int i = 3; i <= n; i++) {
            // 最后爬1阶，有dp[i-1]种；最后爬2阶，有dp[i-2]种
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};


// 滚动数组
class Solution2 {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int first = 1;
        int second = 2;
        int sum;
        for (int i = 3; i <= n; i++) {
            sum = first + second;
            first = second;
            second = sum;
        }
        return sum;
    }
};

int main() {
    Solution s;
    int res = s.climbStairs(3);
    cout << res;

    return 0;
}