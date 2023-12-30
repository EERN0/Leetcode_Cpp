// https://leetcode.cn/problems/basic-calculator/
// Created by caokang on 2023/12/27.
#include <string>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution224 {
public:
    // 运算符优先级
    unordered_map<char, int> umap = {
            {'+', 1},
            {'-', 1},
            {'*', 2},
            {'/', 2}
    };

    int calculate(string s) {
        stack<int> stNum;   // 数字栈
        stack<char> stOpt;  // 操作符栈

        // 双指针，原地去除字符串中的空格
        removeSpace(s);

        // 负号要特殊处理，'-': 负数、减号。统一负数和减法运算，遇到负数，要在'-'前面补0，相当于减法运算
        stNum.push(0);      // 加个0，以防万一。最后返回的是stNum的栈顶元素，多个0无所谓
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {     // 左括号特殊，不是运算符。而且后面可能会跟一个负数
                stOpt.push(s[i]);
                if (i + 1 < s.size() && s[i + 1] == '-') {  // 负数前面加一个0
                    stNum.push(0);
                    // i++;
                }
            }
            else if (s[i] == ')') {     // 遇到了右括号，计算(...)。有')'栈里面必须有'('
                while (stOpt.top() != '(') {
                    myCalculate(stNum, stOpt);
                }
                // 退出while，栈顶是左括号，直接弹出
                stOpt.pop();
            }
            else if (s[i] >= '0' && s[i] <= '9') {    //  数字，处理多为数字 123
                int start = i;
                while (i + 1 < s.size() && isdigit(s[i + 1])) {
                    i++;
                }
                // 退出while，s[i+1]不是数字字符,或者 i+1到头了。s[i]还是数字字符
                stNum.push(stoi(s.substr(start, i - start + 1)));
            }
            else {  // s[i]是运算符 + - * /
                // 如果当前运算符优先级低于或等于stOpt.top()，计算栈中数据
                while (!stOpt.empty() && stOpt.top() != '(' && umap[stOpt.top()] >= umap[s[i]]) {   // 遇到‘(’停止
                    myCalculate(stNum, stOpt);
                }
                // 退出while，说明stOpt栈为空，或者栈顶是'('，或者栈顶运算符优先级低。将当前运算符加入栈中
                stOpt.push(s[i]);
            }
        }
        // 扫完s之后，栈非空，例如: 1+2
        while (!stOpt.empty()) {
            myCalculate(stNum, stOpt);
        }
        return stNum.top();
    }

    // 双指针，原地去除字符串中的空格  he llo world
    void removeSpace(string &str) {
        int j = 0;  // 非空格字符
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ' ') {    // s[i]非空格，进行处理
                str[j++] = str[i];
            }
        }
        // 最后的下标j就是去除空格后字符串的大小
        str.resize(j);
    }

    // 两个数才能参与运算，负数前面需要事先在stNum栈中加上0
    void myCalculate(stack<int> &stNum, stack<char> &stOpt) {
        if (stOpt.empty()) return;
        if (stNum.empty() || stNum.size() < 2) return;

        // 弹出两个数
        int b = stNum.top();
        stNum.pop();
        int a = stNum.top();
        stNum.pop();

        // 弹出运算符
        char opt = stOpt.top();
        stOpt.pop();
        int result = 0;
        switch (opt) {
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
        }
        // 将结果塞到stNum栈中
        stNum.push(result);
    }
};

int main() {
    Solution224 solution;
    string s = "1-( -2)";
    int res = solution.calculate(s);
    cout << res << endl;
}