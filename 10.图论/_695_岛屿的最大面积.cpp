// https://leetcode.cn/problems/max-area-of-island/
// Created by kang on 2023/8/28.
#include <vector>
#include <queue>

using namespace std;

/*
 * 跟200岛屿数量思路一样，用全局变量记录递归搜索时得到的岛屿面积
 * 遇到(i,j)陆地后，把这块岛屿的面积置为0，然后开始搜索(i,j)附近的陆地，累加面积。计算完后，更新最大面积
 * */
// dfs
class Solution695 {
public:
    int thisArea = 0;   // 当前这块陆地+附近陆地的面积
    int maxArea = 0;    // 岛屿的最大面积

    void dfs(vector<vector<int>> &grid, int m, int n, int x, int y) {
        // (x,y)坐标越界，或者不是陆地，不用计算面积
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1) {
            return;
        }
        // (x,y)是陆地
        thisArea++;     // 岛屿面积+1
        grid[x][y] = 0; // 陆地置为0，避免再次访问到

        // 访问陆地(x,y)附近的陆地
        dfs(grid, m, n, x - 1, y);
        dfs(grid, m, n, x + 1, y);
        dfs(grid, m, n, x, y - 1);
        dfs(grid, m, n, x, y + 1);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 遇到了一块陆地，初始化这块陆地的面积为0，因为dfs函数中做的就是面积++的操作
                if (grid[i][j] == 1) {
                    thisArea = 0;   // dfs中，初始化当前岛屿面积为0.    bfs初始当前岛屿面积为1

                    // 搜索(i,j)附近的陆地，累计岛屿的面积
                    dfs(grid, m, n, i, j);

                    maxArea = max(maxArea, thisArea);
                }
            }
        }
        return maxArea;
    }
};

// bfs
class Solution695_bfs {
public:
    int thisArea = 0;   // 当前这块陆地+附近陆地的面积
    int maxArea = 0;    // 岛屿的最大面积

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        // 陆地队列
        queue<pair<int, int>> que;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // 遇到了一块陆地
                if (grid[i][j] == 1) {
                    thisArea = 1;                   // 初始化这块陆地的面积为1
                    grid[i][j] = 0;                 // 置为0，避免再次访问
                    que.push({i, j});               // 把当前的陆地加入队列

                    // 搜索(i,j)附近的陆地，累计岛屿的面积
                    while (!que.empty()) {
                        int x = que.front().first;
                        int y = que.front().second;
                        que.pop();
                        // 遍历(x,y)周围的陆地，累加岛屿面积
                        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                            que.push({x - 1, y});   // 后续还要搜索(x-1,y)附近的陆地
                            thisArea++;
                            grid[x - 1][y] = 0;
                        }
                        if (x + 1 < m && grid[x + 1][y] == 1) {
                            que.push({x + 1, y});
                            thisArea++;
                            grid[x + 1][y] = 0;
                        }
                        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                            que.push({x, y - 1});
                            thisArea++;
                            grid[x][y - 1] = 0;
                        }
                        if (y + 1 < n && grid[x][y + 1] == 1) {
                            que.push({x, y + 1});
                            thisArea++;
                            grid[x][y + 1] = 0;
                        }
                    }
                    // 更新(i,j)这块岛屿的最大面积
                    maxArea = max(maxArea, thisArea);
                }
            }
        }
        return maxArea;
    }
};