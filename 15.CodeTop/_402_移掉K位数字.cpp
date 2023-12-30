// Created by caokang on 2023/11/23.
// https://leetcode.cn/problems/remove-k-digits/
#include <vector>
#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

// 单调栈：存放遍历过的元素/下标
/*
 * 1439229, k=3
 * 10300, k=1
 * */

/*
 * 暴力，分两种情况：序列单增（每次删掉最后一个元素）；非单增序列（若D[i-1]>D[i]，则删除D[i-1]）
 * 最坏时间：O(k*n),单增序列，每次都是删掉最后一个元素（超时）
 * 贪心策略：若下标i前一个元素的值更大，就删掉i前面的元素（若D[i-1]>D[i]，删掉D[i-1]）。每次执行这个策略，删掉1个元素后，对剩下的元素执行相同的操作，共执行k次
 */
class Solution402_1 {
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
 * 单调栈 + 贪心。时间O(n)，空间O(n)
 * 贪心策略：①若D[i-1]>D[i]，删掉D[i-1]; ②若当前序列单增，删除最后的元素
 * 单调递增栈
 * */
class Solution402 {
public:
    string removeKdigits(string num, int k) {
        if (num.empty() || k == 0) return num;
        if (k >= num.size()) return "0";

        stack<int> st;  // 单增栈（栈底->栈顶），存扫描过的元素的下标
        st.push(0);
        string result;

        for (int i = 1; i < num.size(); ++i) {
            if (num[i] - '0' >= num[st.top()] - '0' || k == 0) {   // 当前扫描元素num[i]大于等于栈顶元素，扫描元素入栈 or 不用再删元素了，直接让元素入栈
                st.push(i);
            }
            else if (num[i] - '0' < num[st.top()] - '0') {
                // 当前扫描元素num[i]小于栈顶元素，如果还要删元素(k>0)，删掉栈顶元素（栈里放的是扫描过的元素，D[i-1]>D[i]，删除D[i-1]）
                while (!st.empty() && num[st.top()] > num[i] && k > 0) {
                    st.pop();
                    k--;
                }
                st.push(i);
            }
        }
        // 元素还没删完，说明现在的序列是单增的，只用删掉序列最后几个
        if (k != 0) {
            while (k--) {
                st.pop();
            }
        }

        // 弹出栈中元素，最后结果需要逆置
        while (!st.empty()) {
            result.push_back(num[st.top()]);
            st.pop();
        }

        reverse(result.begin(), result.end());
        // 去除前置0
        while (!result.empty() && result[0] == '0') {
            result.erase(0, 1);
        }

        if (result.empty()) return "0";
        return result;
    }
};

int main() {
    string num = "1439229";
    int k = 3;

    // num = "112";
    // k = 1;

    // num = "10200";
    // k = 1;

    Solution402 solution;
    string result = solution.removeKdigits(num, k);
    cout << result << endl;
}