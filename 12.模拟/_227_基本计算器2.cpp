// https://leetcode.cn/problems/basic-calculator-ii/
// Created by caokang on 2023/10/4.
// 题解：宫水三叶 https://leetcode.cn/problems/basic-calculator-ii/solutions/648832/shi-yong-shuang-zhan-jie-jue-jiu-ji-biao-c65k/、

#include <unordered_map>
#include <string>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;

class Solution227 {
public:
    // 运算符优先级
    unordered_map<char, int> umap = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2},
            {'%', 2},
            {'^', 3}
    };

    int calculate(string s) {
        stack<int> stNums;    // 存数字的栈
        stack<char> stOpt;    // 存运算符和括号的栈

        // 先往数字栈里面存一个0，防止第一个数是负数（因为运算函数得计算两个数）
        stNums.push(0);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;       // 空格直接跳过
            else if (s[i] == '(') {
                stOpt.push('(');          // (...)新的开始，要防止'('右边第一个是负数，若是负数要加个0
                if (s[i + 1] == '-') {
                    stNums.push(0);
                }
            }
            else if (s[i] == ')') {         // 计算()里面的值，直到最近一个左括号
                while (stOpt.top() != '(') {
                    myCalculate(stNums, stOpt);
                }
                // 退出while，碰到了'('
                stOpt.pop();
            }
            else if ('0' <= s[i] && s[i] <= '9') {  // 处理数字，特别注意处理多为数字
                int start = i;
                // 处理不止一位的数字，类似12这些多位数字，lc394字符串解码有另一种方式
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    i++;
                }   // 退出while，s[i+1]不是数字字符了，s[i]还是数字字符
                stNums.push(stoi(s.substr(start, i - start + 1)));    // 多位数字字符串转换为一位数
            }
            else {  // 遇到运算符，要看优先级了，当前运算符优先级【低于或等于】栈中运算符优先级，弹出栈中元素参与运算        +、-、*、/
                // 因为右括号已经先处理了，符号栈里面就没有右括号，只有运算符和左括号。持续计算运算符优先级高的，直到碰到了'('停止
                while (!stOpt.empty() && stOpt.top() != '(' && umap[stOpt.top()] >= umap[s[i]]) {
                    myCalculate(stNums, stOpt);
                }
                // 计算完符号栈中优先级高的运算符后，将当前运算符加入到符号栈中
                stOpt.push(s[i]);
            }
        }
        // 为啥还有剩余的？确实有剩余的数和运算符！！
        while (!stOpt.empty()) {
            myCalculate(stNums, stOpt);
        }

        return stNums.top();
    }

    // 参数必须用引用的方式，数字和操作符都是操作同一个东西
    void myCalculate(stack<int> &stNums, stack<char> &stOpt) {
        if (stNums.empty() || stNums.size() < 2) return;
        if (stOpt.empty()) return;

        // 取出数字栈的前两个数
        int b = stNums.top();
        stNums.pop();
        int a = stNums.top();
        stNums.pop();
        // 取出运算符
        char op = stOpt.top();
        stOpt.pop();

        int result = 0;
        switch (op) {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            case '%':
                result = a % b;
                break;
            case '^':
                result = (int) pow(a, b);
                break;
        }
        // 把计算出的结果放到数字栈nums中
        stNums.push(result);
    }
};

int main() {
    string s = "-10 +5 *6 / (3-5) +(-10+5)*2";
    Solution227 solution;
    int res = solution.calculate(s);
    cout << res << endl;
}