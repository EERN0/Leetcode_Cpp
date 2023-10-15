/*
 * https://leetcode.cn/problems/implement-stack-using-queues/
 * */
#include <iostream>
#include <queue>

using namespace std;

// 一个队列实现栈
class MyStack {
public:
    queue<int> que;

    MyStack() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        size--;

        // 前(size-1)个元素重新入队出队
        while (size--) {
            que.push(que.front());
            que.pop();
        }

        // 重排队列后, 队头元素即为栈顶元素
        int top = que.front();
        que.pop();

        return top;
    }

    int top() {
        // 不使用que.back()的操作
//        int top;
//        int size = que.size();
//        size--;
//        // 前(size-1)个元素重新入队出队, 拿到队头
//        while (size--) {
//            que.push(que.front());
//            que.pop();
//        }
//        top = que.front();
//
//        // 恢复队列原状
//        que.push(que.front());
//        que.pop();
//        return top;

        // 栈顶元素就是队列尾部元素
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};


int main() {
    MyStack *obj = new MyStack();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);

    cout << "栈顶: " << obj->top() << endl;
    cout << "栈顶: " << obj->top() << endl;

    cout << "出栈元素: " << obj->pop() << endl;
    cout << "出栈元素: " << obj->pop() << endl;
    cout << "出栈元素: " << obj->pop() << endl;


    if (obj->empty()) {
        cout << "queue is empty" << endl;
    }
    else cout << "queue is not empty" << endl;

    return 0;
}