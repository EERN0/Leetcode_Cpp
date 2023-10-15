/*
 * https://leetcode.cn/problems/spiral-matrix-ii/
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 初始化一个值全为0的二维数组
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int mid = n / 2;
        int startX = 0, startY = 0;
        int count = 1;
        int offset = 1;
        int loop = n / 2;

        while (loop--) {
            // 起始位置startX，startY
            for (i = startX, j = startY; j < n - offset; j++) {
                matrix[i][j] = count++;
            }
            for (i = startX; i < n - offset; i++) {
                matrix[i][j] = count++;
            }
            for (; j > startY; j--) {
                matrix[i][j] = count++;
            }
            for (; i > startX; i--) {
                matrix[i][j] = count++;
            }
            startX++;
            startY++;
            offset++;
        }
        if (n % 2) {
            matrix[mid][mid] = count;
        }
        return matrix;
    }
};


// 打印二维数组
void printMatrix(vector<vector<int>> &A) {
    // 二维数组——A[[], [], []]  A.size()表示里面一维数组的个数
    int m = A.size();       // m行
    int n = A[0].size();    // n列

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) cout << "[";
            if (j == 0) cout << "[";
            if (j != n - 1) {
                cout << A[i][j] << ", ";
            }
            else if (j == n - 1) {
                if (i != m - 1) cout << A[i][j] << "]" << endl;
                else cout << A[i][j] << "]";
            }
            if (i == m - 1 && j == n - 1) cout << "]";
        }
    }
}

int main() {
    vector<vector<int>> A = {{0}};
    Solution s;
    A = s.generateMatrix(4);
    printMatrix(A);
}