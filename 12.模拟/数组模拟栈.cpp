// 数组模拟栈
// Created by kang on 2023/8/16.
#include <vector>
#include <iostream>

using namespace std;

class MyStack {
public:
    void push(int x) {
        v.push_back(x);
    }

    int top() {
        return v.back();
    }

    int pop() {
        int value = v.back();
        v.pop_back();
        return value;
    }

private:
    vector<int> v;  // 数组尾部作为栈口
};

int main() {
    MyStack st;
    st.push(1);
    st.push(2);
    st.push(3);

    int top = st.top(); // 3
    cout << top << endl;

    int removeNum = st.pop();   // 3
    cout << removeNum << endl;

    top = st.top(); // 2
    cout << top << endl;

    return 0;
}