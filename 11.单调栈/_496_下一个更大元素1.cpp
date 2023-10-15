// https://leetcode.cn/problems/next-greater-element-i/
// Created by caokang on 2023/6/9.
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

// 暴力，三个for循环，时间O(n^3)，无重复元素才能这样处理
class Solution1 {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        vector<int> result(nums1.size(), -1);

        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    for (int k = j; k < nums2.size(); ++k) {
                        if (nums1[i] < nums2[k]) {
                            result[i] = nums2[k];
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};


// 单调栈
// 无重复元素，所以可以用map来处理
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.empty()) return nums1;
        vector<int> result(nums1.size(), -1);
        unordered_map<int, int> umap;   // 哈希表存nums1中出现的值和下标

        for (int i = 0; i < nums1.size(); ++i) {
            umap[nums1[i]] = i;
        }

        // 遍历nums2，递增单调栈，存下标
        stack<int> st;  // 栈中存放的是遍历过的元素
        st.push(0);
        for (int i = 1; i < nums2.size(); ++i) {
            if (nums2[i] < nums2[st.top()]) {
                st.push(i);
            }
            else if (nums2[i] == nums2[st.top()]) {
                st.push(i);
            }
            else {
                // nums2[i]>nums2[st.top()]，找到了比栈顶大的元素
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    // nums1数组中含有nums2[st.top()]该元素，且num2[i]大于该元素，要收集结果
                    if (umap.count(nums2[st.top()])) {
                        result[umap[nums2[st.top()]]] = nums2[i];
                    }
                    // nums1中不存在nums2[st.top()]这个元素，也得弹出栈顶元素
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};


int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    nums1 = {2, 4};
    nums2 = {1, 2, 3, 4};
    Solution solution;
    vector<int> ans = solution.nextGreaterElement(nums1, nums2);
    for (auto o: ans) {
        cout << o << " ";
    }

    return 0;
}