// https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/?envType=study-plan&envId=lcof&plan=lcof&plan_progress=x9qj47kg
// Created by caokang on 2023/5/30.
#include <stack>
#include <iostream>

using namespace std;

class CQueue {
public:
    stack<int> st1;     // 放入队元素
    stack<int> st2;     // 队头元素在st2的栈顶

    CQueue() {

    }

    // 队列尾部添加元素
    void appendTail(int value) {
        st1.push(value);
    }

    // 队头出元素
    int deleteHead() {
        if (st1.empty() && st2.empty()) return -1;

        // 栈2顶部存的是队头元素，只有在栈2为空时，才能把栈1的元素放到栈2中
        if (st2.empty()) {
            while (!st1.empty()) {
                int top = st1.top();
                st1.pop();
                st2.push(top);
            }
        }

        // 栈2有元素时，栈顶元素就是队头元素
        int front = st2.top();
        st2.pop();
        return front;
    }
};

int main() {
    CQueue *obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    int first = obj->deleteHead();
    obj->appendTail(4);
    obj->appendTail(5);
    int second = obj->deleteHead();
    int third = obj->deleteHead();
    int fourth = obj->deleteHead();

    cout << first << ", " << second << ", " << third << ", " << fourth << endl;

    return 0;
}