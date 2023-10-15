// Created by caokang on 2023/5/13.
// https://leetcode.cn/problems/validate-stack-sequences/
#include <vector>
#include <stack>

using namespace std;

// 模拟入栈、出栈顺序
class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        stack<int> st;
        int j = 0;  // 扫描出栈序列poped[]

        for (int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }

        if (st.empty()) return true;
        else return false;
    }
};