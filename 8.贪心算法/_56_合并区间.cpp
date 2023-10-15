/*
 * https://leetcode.cn/problems/merge-intervals/
 * */
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() < 2) return intervals;

        // 按照数组第一个元素，从小到大排序。自定义排序方式使用lambda表达式，返回值会自动推导是bool类型
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

        vector<vector<int>> result;

        // 先把第一个区间放进去，后面for循环从第2个区间开始
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            // intervals[i]的前一个区间在result数组中
            // 前一个区间a的尾大于等于后一个区间b的头，a、b区间有重叠
            if (result.back()[1] >= intervals[i][0]) {
                // 合并区间: 取出result数组的最后一个区间，把该区间的尾取这两个区间尾的最大值
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            else {  // 区间b和前一个区间a没有重叠，把区间b放进结果数组
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};