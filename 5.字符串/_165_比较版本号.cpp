// Created by caokang on 2023/4/28.
// https://leetcode.cn/problems/compare-version-numbers/
#include <string>

using namespace std;

class Solution {
public:
    long long strToNum(string &s, int &ind) {   // 下标ind传的是引用，会对传入的ind进行修改
        long long t = 0;

        // 从ind开始，遇到"."结束，把其中的字符串转换为数字
        while (ind < s.size() && (s[ind] >= '0' && s[ind] <= '9')) {
            t = t * 10 + s[ind] - '0';
            ind++;
        }
        return t;
    }

    int compareVersion(string version1, string version2) {
        int ind1 = 0, ind2 = 0;
        while (ind1 < version1.size() || ind2 < version2.size()) {
            long long num1 = strToNum(version1, ind1);
            long long num2 = strToNum(version2, ind2);

            if (num1 > num2) {
                return 1;
            }
            if (num1 < num2) {
                return -1;
            }
            // num1 == num2的情况：跳过"."，找到下一个数字字符串
            ind1++;
            ind2++;
        }
        return 0;   // 其他情况
    }
};