// Created by caokang on 2023/5/8.
// https://www.nowcoder.com/questionTerminal/78bdfba0a5c1488a9aa8ca067ce508bd?f=discussion
// 和lc96 不同的二叉搜索树 基本一样
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 计算二叉树个数
     * @param n int整型 二叉树结点个数
     * @return int整型
     */
    int numberOfTree(int n) {
        // write code here
        if (n == 1) return 1;
        if (n == 2) return 2;

        // dp[i]表示i个节点，有dp[i]个二叉树
        vector<long> dp(n + 1, 0);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;

        for (int i = 3; i <= n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                dp[i] += dp[j] * dp[i - j - 1];
                // 题目说的输出答案要对(10^9+7)取模
                dp[i] %= 1000000007;
            }
        }

        return dp[n];
    }
};