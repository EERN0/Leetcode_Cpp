// https://leetcode.cn/problems/count-primes/  给定整数 n ，返回 所有小于非负整数 n 的质数的数量
// Created by caokang on 2023/5/30.
// 拓竹面试，没写出来，忘记怎么判断质数了

// 质数的定义：在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数
#include <iostream>

using namespace std;

// 枚举法，超时
class Solution {
public:
    int countPrimes(int n) {
        if (n == 0 || n == 1) return 0;

        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (isPrimers(i)) {
                cnt++;
            }
        }
        return cnt;
    }

    bool isPrimers(int n) {
        if (n == 0 || n == 1) return false;

        for (int i = 2; i * i <= n; ++i) {
            // n能整除i(i>=2)，说明n不是质数
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int res = solution.countPrimes(858232);
    cout << res << endl;

    return 0;
}