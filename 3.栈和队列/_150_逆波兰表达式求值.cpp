/*
 * https://leetcode.cn/problems/evaluate-reverse-polish-notation/
 *
 * 逆波兰(后缀)表达式
 * 后缀表达式求值：https://www.bilibili.com/video/BV1iz4y1k7Ct/?spm_id_from=333.788.recommend_more_video.-1&vd_source=db7abf4aab2386b9c9d7338027b06e76
 * 遇到数字入栈，遇到运算符，弹出两个数字运算，结果压入栈中，最后栈中的数即为所求
 * 9 3 1 - 3 * + 10 2 / +
 *
 * 常见的求值表达式是中缀表达式
 * */

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        // 数字进栈
        stack<int> mystack;

        // 扫描一遍tockens
        for (auto token: tokens) {
            // 字符串string是""，字符char是''
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = mystack.top();
                mystack.pop();
                int num2 = mystack.top();
                mystack.pop();

                if (token == "+") mystack.push(num2 + num1);
                else if (token == "-") mystack.push(num2 - num1);   // 栈中更深的元素放在运算符左边
                else if (token == "*") mystack.push(num2 * num1);
                else if (token == "/") mystack.push(num2 / num1);
            }
            else {  // 扫描到数字，加入栈中
                mystack.push(stoi(token));  // stoi()将字符串类型转换为int类型
            }
        }

        // 最终结果存在栈中
        int result = mystack.top();
        mystack.pop();  // 释放栈空间

        return result;
    }
};