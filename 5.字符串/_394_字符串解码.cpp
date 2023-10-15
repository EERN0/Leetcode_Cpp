// https://leetcode.cn/problems/decode-string/
// Created by kang on 2023/8/24.
#include <string>
#include <stack>

using namespace std;

// 25[ab2[cd]b] ==> 25个 abcdcdb
class Solution394 {
public:
    string decodeString(string s) {
        stack<int> stNum;         // 存数字的栈，数字表示后面跟着的字符串出现的次数
        stack<string> stStr;      // 存字符串的栈

        int num = 0;
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                // 有多位数字时 25 ==> 2*10+5
                num = num * 10 + s[i] - '0';
            }
            else if (isalpha(s[i])) {   // 是字母
                // 多个字母连在一起，分多次拿出来。eg: abc
                res = res + s[i];
            }
            else if (s[i] == '[') {     // 碰到左括号，把数字num、字母res分别入栈
                stNum.push(num);
                num = 0;

                stStr.push(res);
                res = "";
            }
            else if (s[i] == ']') {         // 碰到右括号
                int times = stNum.top();    // 字符串出现的次数
                stNum.pop();
                for (int i = 0; i < times; ++i) {
                    stStr.top() = stStr.top() + res;
                }
                // res来保存字符栈顶，如果后面s[i]还是字母，那就直接加到res后面，它们是同一级运算。
                // 若后面的s[i]是左括号，那就把res重新压入字符栈中，给上一层运算
                // 若后面的s[i]是右括号，那res就是当前（或最终）的结果了
                res = stStr.top();
                stStr.pop();
            }
        }
        return res;
    }
};