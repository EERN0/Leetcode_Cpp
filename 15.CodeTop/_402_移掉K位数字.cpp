// Created by caokang on 2023/11/23.
// https://leetcode.cn/problems/remove-k-digits/

#include <string>
#include <stack>
#include <iostream>

using namespace std;

// 单调栈：存放遍历过的元素/下标
// 单减栈(栈底->栈顶，递减),存遍历过的元素下标
/*
 * 1439229, k=3
 * 10300, k=1
 * */

/*
 * 暴力，最坏时间：O(k*n),单增序列，每次都是删掉最后一个元素（超时）
 * 贪心策略：若下标i前一个元素的值更大，就删掉i前面的元素（若D[i-1]>D[i]，删掉D[i-1]）。每次执行这个策略，删掉1个元素后，对剩下的元素执行相同的操作，共执行k次
 */
class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.empty() || k == 0) return num;
        if (num.size() < k) return "0";

        string result(num.begin(), num.end());

        while (k--) {
            bool flag = true;      // 判断序列是否单增,单增时删除最后一位元素

            // 进了while，必须删掉一个数，若只剩1个数了，直接返回"0"
            if (result.size() == 1) {
                return "0";
            }

            // 按贪心策略，删除i左边更大的元素
            for (int i = 1; i < result.size(); ++i) {
                if (result[i - 1] - '0' > result[i] - '0') {
                    flag = false;   // 序列非单增，删掉左边更大的元素
                    result.erase(i - 1, 1);
                    break;
                }
                else continue;
            }

            if (flag) {     // 遍历序列，发现序列单增，删除最后一个元素
                result.erase(result.size() - 1, 1);
            }
        }

        while (result[0] == '0') {          // 去除前置0
            result.erase(0, 1);
        }
        if (result.empty()) return "0";     // 删掉了所有

        return result;
    }
};


/*
 * 贪心+单调栈
 * */
class Solution402 {
public:
    string removeKdigits(string num, int k) {

    }
};

int main() {
    string num = "1439229";
    int k = 3;

    num = "112";
    k = 1;

    Solution solution;
    string result = solution.removeKdigits(num, k);
    cout << result << endl;
}