#include <cmath>

/*
 * https://leetcode.cn/problems/sqrtx/
 * */

// 二分查找
class Solution69 {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            // 先把mid转换为long类型，mid*mid后才不会溢出
            if ((long) mid * mid == x) return mid;
            else if ((long) mid * mid < x) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// 用指数+对数模拟开根号
class Solution1 {
public:
    int mySqrt(int x) {
        int res = exp(0.5 * log(x));

        // int类型的精度：-2^31 ~ 2^31-1 (-2147483648 ~ 2147483647)
        if ((long long) (res + 1) * (res + 1) <= x) {
            res = res + 1;
        }

        return res;
    }
};

// 二分法，有精度要求
class Solution2 {
public:
    double mySqrt1(int c) {
        double err = 1e-9;
        double x0 = 0;
        double x1 = c;
        while (true) {
            x0 = 0.5 * x1 + 0.5 * c / x1;
            if (abs(x1 - x0) < err) {
                break;
            }
            x1 = x0;
        }
        return x1;
    }
};


