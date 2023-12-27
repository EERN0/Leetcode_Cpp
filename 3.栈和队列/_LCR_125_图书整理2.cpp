// https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/description/
// Created by caokang on 2023/11/15.
//

#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> st1;
    stack<int> st2;

    CQueue() {

    }

    void appendTail(int value) {
        st1.push(value);    // 将元素全存在st1
    }

    int deleteHead() {
        if (st2.empty()) {  // st2为空，说明元素全在st1里面
            if (st1.empty()) return -1;
            else {
                while (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
        }
        // st2有元素，且栈顶是最早入栈st1的
        int top = st2.top();
        st2.pop();
        return top;
    }
};