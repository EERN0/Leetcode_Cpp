// Created by caokang on 2023/4/29.
// https://leetcode.cn/problems/ones-and-zeroes/
#include <vector>
#include <string>

using namespace std;

// 背包容量有两个维度，能容纳m个0和n个1
class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        // dp[i][j]：含有i个0和j个1的背包，最多能装dp[i][j]个物品
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));   // 背包最大容量m个0和n个1，根据递推式求max可知全初始化为0即可

        for (const string &str: strs) {     // 物品
            int x = 0, y = 0;               // x个0，y个1，统计字符串str中0和1的数量
            for (char c: str) {
                if (c == '0') x++;
                else y++;
            }

            for (int i = m; i >= x; --i) {  // 背包，倒序遍历
                for (int j = n; j >= y; --j) {
                    // 不放物品str时，背包最多能装dp[i-x][j-y]个，加上物品str，最多放dp[i-x][j-y]+1个
                    dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
                }
            }
        }

        return dp[m][n];    // 背包容量m个0和n个1最多能放的物品数
    }
};