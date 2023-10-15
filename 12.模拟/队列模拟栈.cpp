// 队列模拟栈
// 225. 用队列实现栈  https://leetcode.cn/problems/implement-stack-using-queues/
// Created by kang on 2023/8/16.
#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {}

    void push(int x) {
        que.push(x);
    }

    // 队列共n个元素，前面n-1个元素要重新出队、入队
    int pop() {
        if (que.empty()) return -1;

        int n = que.size();
        n = n - 1;
        while (n--) {
            int front = que.front();
            que.pop();
            que.push(front);
        }
        // 现在队头元素就是栈顶元素了
        int top = que.front();
        que.pop();
        return top;
    }

    int top() {
        if (que.empty()) return -1;
        return que.back();
    }

    bool empty() {
        if (que.empty()) return true;
        else return false;
    }

private:
    queue<int> que; // 队列只能队尾入队，队头出队
};