// https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/?envType=study-plan&envId=lcof&plan=lcof&plan_progress=x9qj47kg
// 力扣155最小栈
// Created by caokang on 2023/5/30.
#include <stack>
#include <iostream>

using namespace std;

class MinStack {
public:
    stack<int> normalStack;     // 正常栈
    stack<int> minStack;        // 最小栈，保证栈顶元素最小

    MinStack() {

    }

    void push(int x) {
        normalStack.push(x);
        if (minStack.empty()) {
            minStack.push(x);
        }
        else {
            int val = x < minStack.top() ? x : minStack.top();
            minStack.push(val);
        }
    }

    void pop() {
        normalStack.pop();
        minStack.pop();
    }

    int top() {
        return normalStack.top();
    }

    int min() {
        return minStack.top();
    }
};
