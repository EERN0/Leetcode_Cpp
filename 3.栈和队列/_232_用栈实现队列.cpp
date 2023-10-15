/*
 * https://leetcode.cn/problems/implement-queue-using-stacks/
 * */
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue() {

    }

    void push(int x) {  // 向将元素存在栈1
        stack1.push(x);
    }

    // 从队头弹出元素
    int pop() {
        // 栈2为空时,说明元素全在栈1中,将栈1的元素全导入栈2
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int top = stack2.top();
        stack2.pop();
        return top;
    }

    int peek() {
        // 栈2为空,直接从栈1导入元素
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);

    int a = obj->peek();
    cout << a << endl;

    int b = obj->pop();
    cout << b << endl;

    if (obj->empty()) cout << "que is empty" << endl;
    else cout << "que is not empty" << endl;

    return 0;
}