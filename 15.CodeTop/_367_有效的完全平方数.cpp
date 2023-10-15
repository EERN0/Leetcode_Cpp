// https://leetcode.cn/problems/valid-perfect-square/description/
// Created by caokang on 2023/7/28.

// 二分查找
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            long mid = (left + right) / 2;

            if (mid * mid == num) return true;
            else if (mid * mid < num) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};