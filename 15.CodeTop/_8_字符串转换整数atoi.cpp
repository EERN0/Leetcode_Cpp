/*
 * https://leetcode.cn/problems/string-to-integer-atoi/
 * */
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int startIndex = 0;     // 去掉前导空格
        int minus = 0;          // 判断正负号
        string strNum;          // 收集数字字符
        double result = 0;      // long long会溢出

        // 走到开头空格的后一位
        while (true) {
            if (s[startIndex] == ' ' && startIndex < s.size()) {
                startIndex++;
                continue;
            }
            else break;
        }

        // 确定结果是正数还是负数，不存在+、-号就是正数
        if (s[startIndex] == '-') {
            minus = -1;
            startIndex++;
        }
        else if (s[startIndex] == '+') {
            minus = 1;
            startIndex++;
        }
        else if (isNum(s, startIndex)) {
            minus = 1;
        }

        // 收集数字字符
        for (int i = startIndex; i < s.size(); ++i) {
            if (isNum(s, i)) strNum.push_back(s[i]);
            else break;
        }
        // 逆置数字字符，低位在前，高位在后
        reverse(strNum.begin(), strNum.end());

        for (int i = 0; i < strNum.size(); ++i) {
            result += pow(10, i) * (strNum[i] - '0');
        }

        result = result * minus;    // 加上正负号
        // 限制结果范围 INT32_MIN ~ INT32_MAX
        if (result < INT32_MIN) result = INT32_MIN;
        if (result > INT32_MAX) result = INT32_MAX;


        return (int) result;
    }

    bool isNum(string s, int i) {
        if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            return true;
        }
        else return false;
    }
};

int main() {
    Solution s;
    int res = s.myAtoi("20000000000000000000");
    cout << res << endl;

    return 0;
}