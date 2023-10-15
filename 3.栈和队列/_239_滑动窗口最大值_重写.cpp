/*
 * https://leetcode.cn/problems/sliding-window-maximum/
 * */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 单调队列
class Solution {
    class MyQueue {
    public:
        deque<int> que;

        // 弹出队头元素，维持滑动窗口的size最大为k
        void pop(int val) {
            if (!que.empty() && que.front() == val) {
                que.pop_front();
            }
        }

        // 插入val前，要把队列中所有小于val的元素弹出，保持队列单调递减
        void push(int val) {
            while (!que.empty() && val > que.back()) {
                que.pop_back();
            }
            que.push_back(val);
        }

        // 取出滑动窗口的最大值
        int getMaxValue() {
            return que.front();
        }
    };
// 1 3 -1 -3 5 3 6 7
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        MyQueue myQueue;
        vector<int> result;

        // 先插入前k个元素 nums[0]~nums[k-1]
        for (int i = 0; i < k; ++i) {
            myQueue.push(nums[i]);
        }
        // 拿到前k个元素的最大值
        result.push_back(myQueue.getMaxValue());

        // 处理nums[k]~nums[size-1]的元素
        for (int i = k; i < nums.size(); ++i) {
            // [i-k+1 ~ i]共k个元素
            myQueue.pop(nums[i - k]);     // 弹出队头，维持窗口大小<=k

            // 队列加入新元素
            myQueue.push(nums[i]);

            // 拿到队列窗口的最大值
            result.push_back(myQueue.getMaxValue());
        }

        return result;
    }
};

// 用栈超时
class Solution_fail {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        stack<int> mystack;
        mystack.push(nums[0]);
        vector<int> result;

        for (int i = 0; i < nums.size() - k + 1; ++i) {
            for (int j = i; j < i + k; ++j) {
                int big = mystack.top();
                if (nums[j] > big) {
                    mystack.pop();
                    mystack.push(nums[j]);
                }
            }
            // 处理完k个数后，向栈顶添加一个很小的元素
            mystack.push(-10 * 10 * 10 * 10 - 1);
        }

        // 弹出最后一轮栈顶添加的元素
        mystack.pop();

        int size = mystack.size();
        while (size--) {
            result.push_back(mystack.top());
            mystack.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
//    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> nums = {1};
    int k = 1;

    Solution_fail solution;

    vector<int> res = solution.maxSlidingWindow(nums, k);

    for (int num: res) {
        cout << num << " ";
    }

    return 0;
}