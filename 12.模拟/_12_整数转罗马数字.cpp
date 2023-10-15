// https://leetcode.cn/problems/integer-to-roman/
// Created by kang on 2023/8/20.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution12 {
public:
    string intToRoman(int num) {
        // 【逆序】排出13个 int-string 罗马-数字映射表
        pair<int, string> romanMap[] = {{1000, "M"},
                                        {900,  "CM"},
                                        {500,  "D"},
                                        {400,  "CD"},
                                        {100,  "C"},
                                        {90,   "XC"},
                                        {50,   "L"},
                                        {40,   "XL"},
                                        {10,   "X"},
                                        {9,    "IX"},
                                        {5,    "V"},
                                        {4,    "IV"},
                                        {1,    "I"}};

        string result;
        // 每次最接近num的数（最大的数），减掉之后，然后再选出最接近减去之后的数，直到减为0
        // 140 ==> 140-100(C)=40 ==> 40-40(XL)=0 ==> CXL
        for (const auto &[val, roman]: romanMap) {
            while (num >= val) {
                result.append(roman);
                num -= val;

                if (num == 0) break;
            }
        }
        return result;
    }
};

int main() {
    Solution12 solution12;
    string res = solution12.intToRoman(1994);
    cout << res << endl;    // "MCMXCIV"
    return 0;
}