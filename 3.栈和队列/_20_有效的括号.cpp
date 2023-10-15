/*
 * https://leetcode.cn/problems/valid-parentheses/
 *
 * 代码随想录：括号匹配
 * https://www.bilibili.com/video/BV1AF411w78g/?spm_id_from=333.788&vd_source=db7abf4aab2386b9c9d7338027b06e76
 * */
#include <iostream>
#include <string>
#include <stack>

using namespace std;
/*
 * 括号不匹配有三种：
 * ① 多了左括号 (({[()]}
 * ② 多了右括号 ({[]})}}
 * ③ 括号不匹配 {[(}]}
 *
 * 如果先遇到右括号，直接不匹配
 * */
class Solution {
public:
    bool isValid(string s) {
        stack<char> mystack;

        // 剪枝操作, 总的括号数目为奇数, 一定不匹配
        if (s.size() % 2 == 1) return false;

        // 扫描一遍字符串
        for (int i = 0; i < s.size(); ++i) {
            // 遇到左括号, 把相匹配的右括号入栈
            if (s[i] == '(') mystack.push(')');
            else if (s[i] == '[') mystack.push(']');
            else if (s[i] == '{') mystack.push('}');

                // s[i]是右括号, 与栈顶元素比较, 相同则弹出栈顶元素
                // 要先判断栈非空才能top、pop操作，若先扫描到右括号，栈为空直接不匹配 s="}("
            else if (!mystack.empty() && s[i] == mystack.top()) mystack.pop();

                /* 其他情况：
                 *  ① s[i]是右括号，但与栈顶元素不相同，不匹配
                 *  ② s中右括号多了，此时栈中无元素，不匹配
                 * */
            else if (mystack.empty() || s[i] != mystack.top()) {
                // 进入for循环，就说明没有扫描完s，此时栈还为空，表明s中多了右括号
                return false;
            }
        }

        // ③入栈出栈走完一遍，栈非空，说明有相应的左括号没有右括号来匹配
        if (!mystack.empty()) return false;

        // 不匹配的情况没了，就是匹配
        return true;
    }
};