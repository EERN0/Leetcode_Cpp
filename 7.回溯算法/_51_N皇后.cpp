// https://leetcode.cn/problems/n-queens/
// Created by caokang on 2023/6/13.
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    // n是棋盘的大小，数组有n个字符串元素，每个字符串长度为n
    // row是当前遍历的行0~n-1行，当row等于n时，收集结果
    void backtracking(vector<string> &chessboard, int n, int row) {
        if (row == n) {
            result.push_back(chessboard);
            return;
        }

        // i是列数
        for (int i = 0; i < n; ++i) {
            // 放皇后Q的位置合法
            if (isValid(row, i, chessboard, n)) {
                chessboard[row][i] = 'Q';

                backtracking(chessboard, n, i + 1);

                // 回溯撤销
                chessboard[row][i] = '.';
            }
        }
    }

    // 判断皇后位置是否合法
    bool isValid(int row, int col, vector<string> &chessboard, int n) {
        // 同一行
        for (int i = 0; i < col; ++i) {
            if (chessboard[row][i] == 'Q') {
                return false;
            }
        }
        // 同一列
        for (int i = 0; i < row; ++i) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }

        // 由于是从第0行到第n-1行放皇后，所以斜线方向只用检查左上、右上的
        // 左下、右下一开始没放皇后
        // 左上
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 右上
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        // 初始化一个 n*n 的棋盘，初始值全为"."
        vector<string> chessboard(n, string(n, '.'));  // 字符串数组

        backtracking(chessboard, n, 0);
        return result;
    }
};