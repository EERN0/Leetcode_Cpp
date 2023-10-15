/*
 *https://leetcode.cn/problems/top-k-frequent-elements/
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // 仿函数
    class MyCompare {
    public:
        bool operator()(pair<int, int> l, pair<int, int> r) {
            // 优先队列里面l>r是小根堆（top、pop输出元素是从小到大排序）
            return l.second > r.second;     // 比较value值的大小
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> umap;

        for (auto o: nums) {
            umap[o]++;  // key是nums中的元素, value是出现次数
        }

        // 最小优先队列，按照value从小到大排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> priorityQueue;

        // 把map中的元素加入到最小优先队列中, 建立大小为k的小根堆
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++) {
            // 最小优先队列的插入会调整小根堆，出现次数最少的元素在堆顶
            priorityQueue.push(*it);

            // 维持小根堆大小为3
            if (priorityQueue.size() > k) {
                priorityQueue.pop();    // 弹出堆顶最小元素，最后剩下的是k个出现次数最多的元素
            }
        }

        vector<int> result;
        for (; !priorityQueue.empty(); priorityQueue.pop()) {
            result.push_back(priorityQueue.top().first);    // result中是key出现频率从小到大的顺序，要逆置
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5, 5};
    int k = 2;

    Solution solution;

    vector<int> res = solution.topKFrequent(nums, k);

    for (auto o: res) {
        cout << o << " ";
    }

    return 0;
}