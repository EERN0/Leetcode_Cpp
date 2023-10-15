// 155. 最小栈     https://leetcode.cn/problems/min-stack/
// Created by kang on 2023/8/16.
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {}

    void push(int val) {
        st1.push(val);
        if (!stmin.empty()) {   // 最小栈非空
            stmin.push(min(stmin.top(), val));
        }
        else {  // 最小栈为空
            stmin.push(val);
        }
    }

    void pop() {
        st1.pop();
        stmin.pop();
    }

    int top() {
        return st1.top();
    }

    int getMin() {
        return stmin.top();
    }

private:
    stack<int> st1;
    stack<int> stmin;   // 最小栈，栈口元素最小
};