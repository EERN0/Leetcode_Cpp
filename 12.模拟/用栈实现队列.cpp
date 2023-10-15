// 232. 用栈实现队列  https://leetcode.cn/problems/implement-queue-using-stacks/
// Created by kang on 2023/8/16.
#include <stack>

using namespace std;

class MyQueue {
public:
    MyQueue() {
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            // 栈2为空，把栈1的所有元素放到栈2中
            while (!st1.empty()) {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }
        int value = st2.top();
        st2.pop();
        return value;
    }

    int peek() {
        if (st2.empty()) {
            while (!st1.empty()) {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }
        return st2.top();
    }

    bool empty() {
        if (st1.empty() && st2.empty()) return true;
        else return false;
    }

private:
    stack<int> st1;     // 入栈(队列尾部)
    stack<int> st2;     // 出栈(队列头部)
};