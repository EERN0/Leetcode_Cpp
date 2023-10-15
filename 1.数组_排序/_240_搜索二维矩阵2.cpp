// https://leetcode.cn/problems/search-a-2d-matrix-ii/
// Created by kang on 2023/8/27.

#include <vector>

using namespace std;

// 时间O(m+n)
// 右上角(x,y)，减小的方向向左，增大的方向向右
bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int x = 0, y = n - 1;       // 从右上角开始搜

    // 搜索的范围：以matrix左下角(m-1,0)为左下角 ---- 以(x,y)为右上角的矩阵
    // 搜索的方向，x++（向下）、y--（向左）
    while (x < m && y >= 0) {
        if (matrix[x][y] == target) {
            return true;
        }
        else if (matrix[x][y] > target) {   // 大了，往小的方向搜
            // 搜索范围是小矩形，只能y--或者x++
            // 由于每一行、每一列都是递增的，所以变小的方向就是y--
            y--;
        }
        else {  // matrix[x][y]<target，往增大的方向搜，x++
            x++;
        }
    }
    return false;
}

// lower_bound(row.begin(), row.end(), target)：查找大于、等于target的数，用的就是二分
bool searchMatrix2(vector<vector<int>> &matrix, int target) {
    for (const auto &nums: matrix) {
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if (it != nums.end() && *it == target) {
            return true;
        }
    }
    return false;
}

// 每一行来一次二分，O(mlgn)，过不了
bool searchMatrix1(vector<vector<int>> &matrix, int target) {
    for (auto nums: matrix) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
    }
    return false;
}