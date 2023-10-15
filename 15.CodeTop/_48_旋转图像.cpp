// https://leetcode.cn/problems/rotate-image/description/
// Created by kang on 2023/9/4.

#include <vector>

using namespace std;

// 1.使用两个矩阵，非原地，时间空间都是O(n^2)
// 矩阵中第i行的第j个元素，在旋转后，它出现在倒数第i列的第j个位置：matrix[row][col] ==> matrix[col][n-1-row]
void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    vector<vector<int>> res(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = res;
}


// 2.先水平翻转，再沿着主对角线反转，效果个方法1一样，但是不用创建新矩阵
// matrix[row][col] ==水平翻转==> matrix[n-1-row][col] ==主对角线翻转==> matrix[col][n-1-row]
class Solution48 {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();

        // 沿水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j) {
                swap(matrix[i][j], matrix[n - 1 - i][j]);
            }
        }

        // 沿主对角线翻转
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};