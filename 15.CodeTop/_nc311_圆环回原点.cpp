// https://www.nowcoder.com/practice/16409dd00ab24a408ddd0c46e49ddcf8?tpId=196&tqId=40267&ru=/exam/oj
// Created by kang on 2023/8/28.
#include <vector>
#include <iostream>

using namespace std;
/*
 * 字节面试题：
 * 0-12共13个数构成一个环，从0出发，每次走1步，走n步回到0共有多少种走法（2020.09 字节跳动-广告-后端）[1]
 * 0-8组成一个圆环，从0出发，每次可以逆时针和顺时针走，走n步能回到0有多少种情况（2020.09 字节跳动-people-后端）[2]
 * 0~9的环，从0出发，N步后能否走回0。（2020.07 字节跳动-电商-后端）[3]
 * 圆环回原点问题 (2020.08 字节跳动-飞书-后端)[4]
 * */

/*
 * 题目：圆环上有10个点，编号为0~9。从0点出发，每次可以逆时针和顺时针走一步，问走n步回到0点共有多少种走法。
 * */

// dp[i][j]：从0点出发，走i步到j点的【方案数】为dp[i][j]
// 走i步到j点的方案数 == 走i-1步到j-1点的方案数 + 走i-1步到j+1点的方案数
int circle(int n) {
    int length = 10;    // 0~9个点，一共10个数
    vector<vector<int>> dp(n + 1, vector<int>(length, 0));
    // dp[0][j]（j!=0），从0点出发，走0步到j点，方案数都是0
    dp[0][0] = 1;       // 走0步到0点，我这里是定义为1种方案，只能这样定义！！

    // 从0点出发，走1步到j点，下面的方案数标出来了。到其他点的方案数为0。递推式可以推出来
//    dp[1][0] = 0;
//    dp[1][1] = 1;
//    dp[1][9] = 1;

    for (int i = 1; i <= n; ++i) {              // n步
        for (int j = 0; j < length; ++j) {      // 环的长度
            // j==0、j==length-1时要额外处理，会越界
            // 由于是个环，length=10, (0-1+length) % length==9 ， (9+1)%length==0
            dp[i][j] = dp[i - 1][(j - 1 + length) % length] + dp[i - 1][(j + 1) % length];
        }
    }
    return dp[n][0];    // 从原点出发，走n步回到原点的方案数
}

int main() {
    int res = circle(2);
    cout << res << endl;
}