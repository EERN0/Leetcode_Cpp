// Created by caokang on 2023/10/1.

// 彻底解决二分！！
// 题目：34. 在排序数组中查找元素的第一个和最后一个位置
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <vector>

using namespace std;

// 左闭右闭区间
/*
 * 1. 查找 >= target 的数:
 * ① 有大于等于target的数时，返回的left是大于或等于target的下标;
 * ② 没有大于等于target的数时，left的值等于数组的长度nums.size()
 * */
int lower_bound(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;    // 避免直接 [(left+right)/2] 溢出
        if (nums[mid] < target) {
            left = mid + 1;         // [mid+1, right]
        }
        else {
            right = mid - 1;        // [left, mid-1]
        }
    }
    return left;
}

/*
 * 2. 找 > target 的数      <===>  找 >= target+1 的数    (数组中均为整数时可用)
 *
 * 3. 找 < target 的数      <===>  找 (>= target) 左边第一个数
 *
 * 4. 找 <= target 的数     <===>  找 (> target) 左边第一个数、
 *
 * */

// case2: 找 > target 的数
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
    return left;
}

// case3: 找 < target 的数   等价于   找 >= target 的数 的左边第一个数
int lower_bound3(vector<int> &nums, int target) {
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
    return left - 1;
}

// case4: 找 <= target 的数    等价于     找 > target 的数 的左边第一个数       等价于     找 >= target+1 的数 的左边第一个数
int lower_bound4(vector<int> &nums, int target) {
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