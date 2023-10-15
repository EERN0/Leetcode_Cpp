#include <iostream>
#include <vector>

using namespace std;

// 0 1 1 2 3 5

// 递归
class Solution1 {
public:
    // 0 1 1 2 3 5
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        return fib(n - 1) + fib(n - 2);
    }
};

// 迭代，滚动数组，类似动态规划
class Solution2 {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int first = 0, second = 1;
        int sum;
        // n=2时，只用加一次; n=3时，加两次
        for (int i = 2; i <= n; i++) {
            sum = first + second;
            first = second;     // first往右移动1个
            second = sum;       // second往右移动1个
        }
        return sum;
    }
};


// 动态规划
class Solution3 {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        // 1. dp[i]：第i个斐波那契数列的数值
        vector<int> dp(n + 1, 0);
        // 2. 初始值
        dp[0] = 0;
        dp[1] = 1;

        // 3. 递推公式 dp[i]=dp[i-1]+dp[i-2]
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution3 s;
    int res = s.fib(2);
    cout << res;

    return 0;
}