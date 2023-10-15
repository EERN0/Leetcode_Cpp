// Created by caokang on 2023/5/1.
// https://leetcode.cn/problems/multiply-strings/
#include <string>
#include <vector>

using namespace std;

// 超级麻烦，根据乘积结果的索引来模拟乘法运算过程
class Solution2 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        // 两个数相乘(分别是m位和n位数)，乘积的位数最多为m+n，或者是m+n-1（有前导0）
        vector<int> result(num1.size() + num2.size(), 0);

        // nums1第i位和nums2第j位相乘的结果在乘积中的位置是[i+j, i+j+1]，分别是进位、本位
        for (int i = num2.size() - 1; i >= 0; --i) {
            for (int j = num1.size() - 1; j >= 0; --j) {
                int product = (num2[i] - '0') * (num1[j] - '0'); // 本轮中，i位和j位相乘的结果放在结果的[i+j,i+j+1]
                // 当前计算的结果（本位 进位），加上上一轮乘积结果的进位（由于本轮中j减1了，所以是i+j+1）
                int sum = product + result[i + j + 1];

                // 本位[i+j+1]已经加上了上一轮结果的进位，所以可直接更新本轮结果的本位
                result[i + j + 1] = sum % 10;
                // 本轮结果的进位，要加上之前该位置上的数字，再更新该进位值给下一轮使用
                result[i + j] += sum / 10;
            }
        }

        string ans;
        for (int i = 0; i < result.size(); ++i) {
            if (i == 0 && result[0] == 0) {
                continue;
            }
            else {
                ans.append(to_string(result[i]));
            }
        }
        return ans;
    }
};

//
class Solution1 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        vector<int> sum(num1.size() + num2.size() - 1, 0);

        for (int i = 0; i < num2.size(); ++i) {
            for (int j = 0; j < num1.size(); ++j) {
                sum[i + j] += (num1[i] - '0') * (num2[i] - '0');
            }
        }

        // 从后往前，算出本位和进位
        for (int i = sum.size() - 1; i >= 1; --i) {
            sum[i - 1] += sum[i] / 10;  // 进位
            sum[i] = sum[i] % 10;       // 本位
        }

        string ans;
        for (int i = 0; i < sum.size(); ++i) {
            if (i == 0 && sum[0] == 0) {
                continue;
            }
            else {
                ans.append(to_string(sum[i]));
            }
        }
        return ans;
    }
};