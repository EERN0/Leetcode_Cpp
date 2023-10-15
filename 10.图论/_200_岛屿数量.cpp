// https://leetcode.cn/problems/number-of-islands/
#include <vector>
#include <queue>

using namespace std;

// 岛屿数量的思路：就是遍历二维数组，没遇到一个陆地，将它和它周围（上下左右）的陆地都设置为'0'，避免重复计算陆地

// 深度优先搜索DFS，用递归(栈)
class Solution_DFS {
public:
    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size();      // 行
        int col = grid[0].size();   // 列

        if (row == 0 || col == 0) return 0;
        int island = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 遇到陆地
                if (grid[i][j] == '1') {
                    island++;
                    // dfs搜索(i,j)的上下左右
                    dfs(grid, i, j, row, col);
                }
            }
        }
        return island;
    }

    // dfs深度优先搜索（递归），把岛屿island周围（上下左右）的岛屿全部置为'0'，避免被重复计算
    void dfs(vector<vector<char>> &grid, int i, int j, int row, int col) {
        // 递归结束条件：i和j不在搜索的范围内、遇到水域，直接返回
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == '0') {
            return;
        }

        // 执行到这，说明遇到了陆地1，遍历过的陆地置为0，防止下次再遍历到
        grid[i][j] = '0';

        // (i,j)上下左右都扫描一遍，遇到陆地1就进行同化，设置为0
        dfs(grid, i - 1, j, row, col);
        dfs(grid, i + 1, j, row, col);
        dfs(grid, i, j - 1, row, col);
        dfs(grid, i, j + 1, row, col);
    }
};


// BFS，借助队列
class Solution_BFS {
public:
    int numIslands(vector<vector<char>> &grid) {
        int row = grid.size();      // 行
        int col = grid[0].size();   // 列

        if (row == 0 || col == 0) return 0;
        int island = 0;

        int x = 0, y = 0;

        // 存坐标
        queue<pair<int, int>> que;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // 遇到陆地
                if (grid[i][j] == '1') {
                    island++;
                    que.push({i, j});

                    grid[i][j] = '0';   // 遍历过的陆地置为0，避免重复计算

                    // 把该陆地1上下左右的陆地加入队列，并把陆地置为0
                    while (!que.empty()) {
                        pair<int, int> cur = que.front();
                        que.pop();

                        x = cur.first;  // 行坐标
                        y = cur.second; // 列坐标

                        if (x - 1 >= 0 && grid[x - 1][y] == '1') {  // (x,y)的上面也是陆地
                            grid[x - 1][y] = '0';   // 遍历过的陆地置为0
                            que.push({x - 1, y});
                        }
                        if (x + 1 < row && grid[x + 1][y] == '1') {  // (x,y)的下面是陆地
                            grid[x + 1][y] = '0';
                            que.push({x + 1, y});
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == '1') {  // (x,y)的左边是陆地
                            grid[x][y - 1] = '0';
                            que.push({x, y - 1});
                        }
                        if (y + 1 < col && grid[x][y + 1] == '1') {  // (x,y)的右边是陆地
                            grid[x][y + 1] = '0';
                            que.push({x, y + 1});
                        }
                    }
                }
            }
        }
        return island;
    }
};

