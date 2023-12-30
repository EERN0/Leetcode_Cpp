// https://leetcode.cn/problems/course-schedule/
// Created by caokang on 2023/12/29.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution207 {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<int> indegree(numCourses, 0);       // 顶点的入度
        vector<vector<int>> adj(numCourses);              // 邻接表
        for (auto pre: prerequisites) {
            indegree[pre[1]]++;
            adj.push_back({pre[1], pre[0]});
        }
    }
};

int main() {
    vector<int> indegree(5);
}