// https://leetcode.cn/problems/diagonal-traverse/
// Created by caokang on 2023/11/22.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution498 {
public:
    // 遍历第1行元素的左下角所有元素 和 最后一列元素的所有左下角元素
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int m = mat.size();     // 行
        int n = mat[0].size();  // 列
        if (m * n == 0) return {};

        vector<vector<int>> data;

        bool flag = true;   // flag: true-左上方向（正向）, false-左下方向（反向）
        // 第1行所有元素的左下角元素
        for (int j = 0; j < n; ++j) {       // i=0
            vector<int> temp = traversal(0, j, mat);

            if (flag) {  // 左上方向，traversal遍历的是左下方向，要逆置
                reverse(temp.begin(), temp.end());
                data.push_back(temp);
            }
            else {      // 左下，无需逆置
                data.push_back(temp);
            }
            flag = !flag;
        }

        // 最后1列所有元素的左下角元素（排除和前面重复的）
        for (int i = 1; i < m; ++i) {   // j=n-1
            vector<int> temp = traversal(i, n-1, mat);

            if (flag) { // flag为true，要左上方遍历的结果，逆置一波
                reverse(temp.begin(), temp.end());
                data.push_back(temp);
            }
            else {
                data.push_back(temp);
            }
            flag = !flag;
        }

        // 将二维数组存放一位结果数组中
        vector<int> result;
        for (vector<int> v: data) {
            for (int num: v) {
                result.push_back(num);
            }
        }
        return result;
    }

    // 遍历(x,y)左下角所有元素，存到数组中
    vector<int> traversal(int x, int y, vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        for (; x >= 0 && x < m && y >= 0 && y < n; ++x, --y) {
            res.push_back(mat[x][y]);
        }
        return res;
    }
};

int main() {
    // vector<vector<int>> mat = {
    //         {1, 2, 3},
    //         {4, 5, 6},
    //         {7, 8, 9}
    // };
    vector<vector<int>> mat = {
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10}
    };

    Solution498 solution;
    vector<int> res = solution.findDiagonalOrder(mat);

    for (auto o: res) {
        cout << o << " ";
    }

}