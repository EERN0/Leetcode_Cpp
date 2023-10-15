// Created by caokang on 2023/5/13.
// https://leetcode.cn/problems/valid-parenthesis-string/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> leftStack;  // 存左括号的下标
        stack<int> startStack; // 存*的下标

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                leftStack.push(i);
            }
            else if (s[i] == '*') {
                startStack.push(i);
            }
            else {   // 遇到了右括号
                if (!leftStack.empty()) {       // 左括号栈leftStack非空，优先弹出左括号
                    leftStack.pop();
                }
                else if (!startStack.empty()) { // leftStack为空，弹出*作为左括号
                    startStack.pop();
                }
                else {   // leftStack和startStack都为空，无法匹配右括号
                    return false;
                }
            }
        }
        // 上面扫描了一遍s，把和右括号匹配的左括号全部弹出（*充当左括号）

        // 若左括号多，*要充当右括号，且左括号下标要小于*号下标才可匹配
        while (!leftStack.empty() && !startStack.empty()) { // 左括号栈leftStack非空，必须得有*作为右括号与之匹配，不然匹配失败
            int leftIndex = leftStack.top();    // 取出左括号下标
            leftStack.pop();

            int startIndex = startStack.top();  // 取出*号下标
            startStack.pop();

            if (leftIndex > startIndex) {    // 左括号在*后面，eg: *  (     无法匹配
                return false;
            }
        }

        if (leftStack.empty()) {     // 左括号栈为空，说明(全匹配上了
            return true;
        }
        else {
            return false;   // 左括号栈非空，没完全匹配
        }
    }
};

int main() {
    Solution solution;
    string s = "(((*)**(())";
    cout << solution.checkValidString(s);

    return 0;
}