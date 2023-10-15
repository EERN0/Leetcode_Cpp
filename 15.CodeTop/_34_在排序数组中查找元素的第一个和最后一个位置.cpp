// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
// https://www.bilibili.com/video/BV1AP41137w7/?spm_id_from=333.1007.top_right_bar_window_custom_collection.content.click&vd_source=db7abf4aab2386b9c9d7338027b06e76
// Created by caokang on 2023/10/1.
#include <vector>

using namespace std;

class Solution34 {
public:
    // 数组已经有序了，用两次二分查找：先找到第一个等于target的，再用一次二分找到第一个大于target的
    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound1(nums, target);     // 找 >= target的数

        // 判断一波
        // 全是小于target的数（返回的left是数组的长度）    或者      没有等于target的数（只有大于target的）
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }

        // 前面已经判断了，存在target这个数
        int end = lower_bound2(nums, target);       // 找 <= target的数，能保证nums[end]就是等于target的

        return {start, end};
    }

    // 找 >= target 的数
    int lower_bound1(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }

    // 找 <= target 的数   <==>    找 > target的数 的左边第一个数    <==>    找 >= target+1 的数 的左边第一个数
    int lower_bound2(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target + 1) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};