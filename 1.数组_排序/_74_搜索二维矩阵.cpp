// https://leetcode.cn/problems/search-a-2d-matrix/
// Created by kang on 2023/8/27.
//
#include <vector>

using namespace std;

// O(nlgn)，n次二分
bool searchMatrix1(vector<vector<int>> &matrix, int target) {
    for (auto nums: matrix) {
        // 标准的左闭右闭区间，left <= right，left = mid + 1，right = mid - 1
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
    }
    return false;
}

// O(lgm+lgn)==>O(lgmn)，两次二分，最后一列找到大于且最接近target的元素，然后在那一行用二分
bool searchMatrix2(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    // 二分，找到大于target且最小的数
    int left = 0, right = m - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (matrix[mid][n - 1] == target) {
            return true;
        }
        else if (matrix[mid][n - 1] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    // matrix[left][n-1]就是大于target的第一个数?    在left那一行
    // left的行数超过了矩阵的行数【关键】
    if (left >= m) return false;

    // 再用二分来查找left那一行
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (matrix[left][mid] == target) {
            return true;
        }
        else if (matrix[left][mid] < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}


// 一次二分查找 O(lgm*n)，因为下一行的第一个数大于上一行的最后一个数，可以用一次二分
// 二维矩阵元素索引编号，idx = 0 ~ m*n-1。

// idx/n : 编号idx所在的行    （n是列数）
// idx%n : 编号idx所在的列
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    int l = 0, r = m * n - 1;   // 左闭右闭，l<=r, l=mid-1, r=mid+1
    while (l <= r) {
        int mid = (l + r) / 2;
        int x = matrix[mid / n][mid % n];   // 编号mid所在的行(mid/n)、列(mid%2)

        if (x == target) return true;
        else if (x < target) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return false;
}