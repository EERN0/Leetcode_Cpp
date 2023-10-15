// https://leetcode.cn/problems/island-perimeter/
// Created by kang on 2023/8/28.
//
#include <vector>
#include <iostream>

using namespace std;

/*
 * 对于一个陆地格子的每条边，它被算作岛屿的周长: 当且仅当这条边为网格的边界，或者相邻的另一个格子为水域
 * */
class Solution463 {
public:
    int perimeter = 0;  // 岛屿周长

    void dfs(vector<vector<int>> &grid, int m, int n, int x, int y) {
        // 遍历陆地(x,y)周围的格子，超出了边界，或者周围的格子是水域时，才会提供一个周长
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0) {
            perimeter++;
            return;
        }

        if (grid[x][y] == 1) {    // 当前遍历的是陆地
            // 把遍历过的陆地，置为2，避免和水域0混了
            grid[x][y] = 2;

            // 把陆地四周的全遍历一遍
            dfs(grid, m, n, x - 1, y);
            dfs(grid, m, n, x + 1, y);
            dfs(grid, m, n, x, y - 1);
            dfs(grid, m, n, x, y + 1);
        }
    }

    int islandPerimeter(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 因为恰好只有一个岛屿，可以一次dfs全部搜出来相连的陆地
                if (grid[i][j] == 1) {
                    // 直接搜索(i,j)上下左右的陆地
                    dfs(grid, m, n, i, j);
                }
            }
        }
        return perimeter;
    }
};

int main() {
    vector<vector<int>> grid = {{0, 1, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 1, 1},
                                {1, 1, 0, 0}};
    Solution463 s;
    int res = s.islandPerimeter(grid);
    cout << res << endl;

}