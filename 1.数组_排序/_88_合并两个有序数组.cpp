/*
 * https://leetcode-cn.com/problems/merge-sorted-array/
 * */
#include <iostream>
#include <vector>

using namespace std;

// 和21合并两个有序链表操作相同
class Solution88 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int cur = m + n - 1;
        int i1 = m - 1, i2 = n - 1;

        while (i1 >= 0 && i2 >= 0) {
            if (nums1[i1] < nums2[i2]) {
                nums1[cur--] = nums2[i2--];
            }
            else {
                nums1[cur--] = nums1[i1--];
            }
        }
        // 退出while循环，i1或i2有一个是-1（肯定有一个数组处理完了，另一个没处理完）
        if (i1 == -1) { // nums1中的元素处理完了
            while (cur >= 0) {
                nums1[cur--] = nums2[i2--];
            }
        }
        else {   // nums2中的元素先处理完了
            while (cur >= 0) {
                nums1[cur--] = nums1[i1--];
            }
        }
    }
};

class Solution1 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i1 = m - 1, i2 = n - 1;
        int cur = m + n - 1;    // 大元素下标

        // 停止条件：当 i2 < 0时，说明nums2已经全部合并到nums1中
        while (i2 >= 0) {
            if (i1 >= 0 && nums1[i1] > nums2[i2]) {     // 把大的元素往后挪
                nums1[cur--] = nums1[i1--];
            }
            else {
                // i1 < 0 或 nums2[i2] >= nums1[i1]，两种情况操作相同
                // 1. i1 < 0，说明nums1数组走完了，nums2中剩下的是最小的几个元素，直接将此时nums2[i2]之前的元素赋值给nums1[]
                // 2. nums2[i2] >= nums1[i1]，还是将nums2[i2]赋值给nums1[cur]
                nums1[cur--] = nums2[i2--];
            }
        }
    }
};

int main() {
    int m = 3;
    int n = 3;
    vector<int> v1 = {1, 2, 3, 0, 0, 0};
    vector<int> v2 = {2, 5, 6};

    Solution1 s1;
    s1.merge(v1, m, v2, n);

    for (auto o: v1) {
        cout << o << " ";
    }
    return 0;
}
