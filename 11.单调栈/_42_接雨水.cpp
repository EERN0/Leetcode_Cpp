/*
 * https://leetcode.cn/problems/trapping-rain-water/
 * */
#include <vector>
#include <stack>

using namespace std;

// 接雨水：就是求当前列左边比它大的元素和右边比它大的元素，计算凹槽的面积

// 暴力解法，力扣超时,时间O(n^2)，空间O(1)
// 思路：当前列雨水面积，列宽为1：min(左边柱子的最高高度，记录右边柱子的最高高度) - 当前柱子高度
class Solution1 {
public:
    int trap(vector<int> &height) {
        int sum = 0;
        // 计算列号为i的柱子能接多少雨水
        for (int i = 0; i < height.size() - 1; i++) {
            // 第一个和最后一个柱子不接雨水
            if (i == 0 || i == height.size() - 1) continue;

            // i的左、右两边最长柱子的高度（至少是i列柱子的高度）
            int lHeight = height[i];
            int rHeight = height[i];

            // i左边柱子最长的高度
            for (int l = i - 1; l >= 0; --l) {
                if (height[l] >= lHeight) lHeight = height[l];
            }
            // i右边柱子最长的高度
            for (int r = i + 1; r < height.size(); ++r) {
                if (height[r] >= rHeight) rHeight = height[r];
            }

            // i列能接的雨水
            int h = min(lHeight, rHeight) - height[i];

            // 存在h==0的情况，就是i列左边或右边没有更高的柱子了
            if (h > 0) sum += h;
        }
        return sum;
    }
};


// 双指针、动态规划（打表，避免两层for嵌套），时间O(n)，空间O(n)
// 思想还是一样的：当前列雨水面积，列宽为1：min(左边柱子的最高高度，记录右边柱子的最高高度) - 当前柱子高度
// maxLeft[i]: i列及其左边的最高柱子的高度；maxRight[i]: i列及其右边的最高柱子高度
class Solution2 {
public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) return 0;

        int size = height.size();
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);

        maxLeft[0] = height[0];
        // 从左向右遍历，得到i列及其左边柱子的最高值
        for (int i = 1; i < size; ++i) {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }

        maxRight[size - 1] = height[size - 1];
        // 从右向左遍历，得到i列及其右边柱子的最高值
        for (int i = size - 2; i >= 0; --i) {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }

        int sum = 0;
        for (int i = 0; i < size; ++i) {
            // 计算每一列的雨水量
            int h = min(maxLeft[i], maxRight[i]) - height[i];

            // h要么大于0，要么等于0
            sum += h;
        }
        return sum;
    }
};

// 单调栈
class Solution3 {
public:
    int trap(vector<int> &height) {
        if (height.size() <= 2) return 0;
        int sum = 0;

        // 单调栈，递增栈，存下标
        stack<int> st;
        st.push(0);     // 第一个柱子下标入栈
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            }
            else if (height[i] == height[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    // 中间的柱子下标
                    int mid = st.top();
                    // 弹出中间柱子后，新栈顶是中间柱子mid左边第一个高于mid的柱子
                    st.pop();
                    // 弹栈后，要进行判空操作
                    if (!st.empty()) {
                        // height[i]是中间柱子mid右边第一个高于mid的柱子
                        // 计算凹槽的高度h
                        int h = min(height[i], height[st.top()]) - height[mid];
                        // 计算凹槽的宽度w
                        int w = i - st.top() - 1;   // 左边高于mid的柱子，和右边高于mid的柱子，中间的宽度为w

                        // 容纳雨水的面积
                        sum += h * w;
                    }
                }
                // 单调栈为空，当前下标入栈
                st.push(i);
            }
        }
        return sum;
    }
};