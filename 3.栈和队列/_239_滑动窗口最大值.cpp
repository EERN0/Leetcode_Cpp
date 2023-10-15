/*
 * https://leetcode-cn.com/problems/sliding-window-maximum/
 * */

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

}

// 暴力，时间复杂度O(n*k)，通过不了测试案例 41
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        // 如果数组为空，或者滑动窗口大小非正数，直接返回空，空的vector容器直接用{}表示
        if (nums.empty() || k < 1) {
            return {};
        }
        // 如果滑动窗口大小为1，直接返回原数组
        if (k == 1) return nums;

        // 滑动窗口的个数为 n-(k-1)
        int N = nums.size() - (k - 1);
        vector<int> winMax(N, 0);
        for (int i = 0; i < N; i++) {
            int maxIndex = i;
            // k个数求最大值
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] > nums[maxIndex]) maxIndex = j;
            }
            winMax[i] = nums[maxIndex];
        }
        return winMax;
    }
};

// 使用双端队列
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty() || k < 1) return {};
        if (k == 1) return nums;
        vector<int> winMax(nums.size() - (k - 1), 0);     // 滑动窗口的最大值
        deque<int> dq;          // 双端队列，存放nums数组的索引
        // 遍历nums数组，时间复杂度O(n)
        for (int ri = 0; ri < nums.size(); ri++) {
            // 只要nums[队尾] <= nums[ri]，就删除队尾元素(保证nums[队头]最大，且递减)，直到 nums[队尾] > nums[ri]
            while (!dq.empty() && nums[ri] >= nums[dq.back()]) {
                dq.pop_back();  // 删除队尾元素
            }
            // 将 ri 加到队尾
            dq.push_back(ri);
            // 检查 li 的合法性，ri-li+1 = k
            int li = ri - k + 1;
            if (li < 0) continue;    // li不是滑动窗口的第一个元素，结束本轮循环
            // li >= 0 :
            // 如果队头 < li，说明队列中的队头 不属于 该滑动窗口元素的索引，要将队头元素移除队列
            if (dq.front() < li) {  //保证滑动窗口的最大值为nums[队头]
                dq.pop_front();
            }
            // 设置滑动窗口的最大值为 nums[队头]
            winMax[li] = nums[dq.front()];
        }
        return winMax;
    }
};


int main() {
    vector<int> v = {0, 3, -1, -3, 5, 3, 6, 7};
    printVector(v);
    int k = 3;
    Solution1 s1;

    Solution2 s2;
    vector<int> v2 = s2.maxSlidingWindow(v, k);
    printVector(v2);
    return 0;
}


