// https://leetcode.cn/problems/daily-temperatures/
// Created by caokang on 2023/6/9.
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 暴力，两层for循环时间O(n^2)，超时
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> ans(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); ++i) {
            for (int j = i + 1; j < temperatures.size(); ++j) {
                if (temperatures[j] > temperatures[i]) {
                    ans[i] = j - i;
                    break;
                }
            }
        }
        return ans;
    }
};

// 单调栈：找右边更大的元素，栈中存放遍历过的元素
class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        if (temperatures.size() <= 1) return {0};

        int n = temperatures.size();
        vector<int> result(n, 0);
        // 单调栈存温度数组的下标
        stack<int> st;

        st.push(0); // 第一个元素下标入栈
        for (int i = 1; i < n; ++i) {
            if (temperatures[i] <= temperatures[st.top()]) {     // 当前元素小于等于栈顶元素，当前元素入栈
                st.push(i);
            }
            else {
                // temperatures[i]>temperatures[st.top()]时，记录结果
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    result[st.top()] = i - st.top();    // 记录结果
                    st.pop();   // 弹出栈顶元素
                }
                // 退出while，说明栈st为空，或者当前元素temperatures[i]<=temperatures[st.top()]，当前元素得入栈
                // 处理完栈中小于当前元素temperatures[i]的元素后，把i入栈。当栈为空时，也要把i入栈
                st.push(i);
            }
        }
        return result;
    }
};

// 单调栈，自己写的，乱了些
/*
 * 单调栈，找比当前元素左、右更大或更小的值，典型的空间换时间。单调栈中存的是扫描过的值
 *
 * */
class Solution3 {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        if (temperatures.size() <= 1) return {0};

        int n = temperatures.size();
        vector<int> result(n, 0);
        // 单调栈存温度数组的下标
        stack<int> st;

        st.push(0);
        for (int i = 1; i < n; ++i) {
            while (!st.empty() && i < n && temperatures[i] > temperatures[st.top()]) {  // 当前扫描的元素大于栈顶元素，弹出栈顶元素
                result[st.top()] = i - st.top();
                st.pop();

                if (st.empty()) {
                    st.push(i);
                    i++;
                }
            }

            if (i < n && temperatures[i] <= temperatures[st.top()]) {
                // 求右边更大元素，单调栈递减（栈底——>栈顶）
                st.push(i);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {73, 76, 74, 74, 73, 75, 71, 69, 72, 77, 73};
//    nums = {30, 40, 50, 60};
    Solution739 solution;
    vector<int> ans = solution.dailyTemperatures(nums);
    for (auto o: ans) {
        cout << o << " ";
    }

    return 0;
}