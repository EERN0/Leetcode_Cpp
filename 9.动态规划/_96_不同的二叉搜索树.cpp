/*
 * https://leetcode.cn/problems/unique-binary-search-trees/
 *
 * 二叉搜索树：根左边的值都小于根的值，根右边节点的值都大于根节点的值
 * */

#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;   // 两个节点只有两种布局  小的为根、大的为根

        // dp[i]表示i个节点有dp[i]种二叉搜索树
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            for (int j = 1; j <= i; j++) {  // 以j为根节点,j左边有j-1个小的节点，j右边有i-j个大的节点
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};