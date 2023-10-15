// https://leetcode-cn.com/problems/min-stack/
#include<iostream>
#include<stack>

using namespace std;

class MinStack {
public:
    stack<int> normalStack;
    stack<int> minStack;

    MinStack() {}

    void push(int val) {
        normalStack.push(val);

        if (minStack.empty()) {
            minStack.push(val);
        }
        else {
            // 每次取出 最小栈栈顶元素 和 要入栈的元素 的最小值，放入最小栈
            minStack.push(min(minStack.top(), val));
        }
    }

    void pop() {    // 删除栈顶元素
        normalStack.pop();
        minStack.pop();
    }

    int top() {     // 拿到栈顶元素
        return normalStack.top();
    }

    int getMin() {  // 取出栈顶最小元素，时间O(1)
        return minStack.top();
    }
};

