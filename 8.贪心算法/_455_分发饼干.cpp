// Created by caokang on 2023/5/4.
// https://leetcode.cn/problems/assign-cookies/
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        if (s.empty()) return 0;

        // 给胃口小的小孩分配最小能填满肚子的饼干
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0, cookies = 0;
        // children=[1,2], cookie=[1,2,3]
        while (child < g.size() && cookies < s.size()) {
            if (g[child] <= s[cookies]) {   // 小饼干能填满肚子
                child++;
                cookies++;
            }
            else {  // 小饼干不能填满肚子，找大一点的饼干
                cookies++;
            }
        }

        return child;
    }
};