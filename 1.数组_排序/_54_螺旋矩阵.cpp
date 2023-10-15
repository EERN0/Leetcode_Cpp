/*
 * https://leetcode.cn/problems/spiral-matrix/
 * */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();      // 矩阵的行数
        int n = matrix[0].size();   // 矩阵的列数
        vector<int> A(m * n, 0);
        int index = 0;
        int i = 0, j = 0;
        int startX = 0, startY = 0;
        int offset = 1;
        while (index < m * n) {
            // 循环不变量
            for (i = startX, j = startY; j < n - offset; j++) {
                A[index++] = matrix[i][j];
                if (index >= m * n) break;
            }
            for (i = startX; i < m - offset; i++) {
                A[index++] = matrix[i][j];
                if (index >= m * n) break;
            }
            for (; j > startY; j--) {
                A[index++] = matrix[i][j];
                if (index >= m * n) break;
            }
            for (; i > startX; i--) {
                A[index++] = matrix[i][j];
                if (index >= m * n) break;
            }
            startX++, startY++;
            offset++;

            // 特殊情况，当m==n且n为奇数时，最中间的一个数访问不到，要手动赋值
            if (m == n && (m * n % 2 == 1) && (index == m * n - 1)) {
                A[index] = matrix[m / 2][n / 2];
                break;
            }
        }
        return A;
    }
};


int main() {
    vector<vector<int>> matrix1 = {{1, 2, 3},
                                   {4, 5, 6},
                                   {7, 8, 9},};

    vector<vector<int>> matrix2 = {{1,  2,  3},
                                   {4,  5,  6},
                                   {7,  8,  9},
                                   {10, 11, 12},
                                   {13, 14, 15}};

    vector<vector<int>> matrix3 = {{1, 2,  3,  4},
                                   {5, 6,  7,  8},
                                   {9, 10, 11, 12}};
    Solution s;

    vector<int> nums = s.spiralOrder(matrix1);
    int i = 0, n = nums.size();
    while (n--) {
        cout << nums[i++] << " ";
    }
    return 0;
}