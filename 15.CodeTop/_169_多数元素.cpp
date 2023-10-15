// https://leetcode.cn/problems/majority-element/
// Created by caokang on 2023/9/30.
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 摩尔投票：
 * 投票vote数为0，假设为众数（出现次数超过一般的数），遇到众数，vote+1，遇到非众数，vote-1
 *
 * 题解看这：https://leetcode.cn/problems/majority-element/solutions/2362000/169-duo-shu-yuan-su-mo-er-tou-piao-qing-ledrh/
 * */
class Solution169 {
public:
    int majorityElement(vector<int> &nums) {
        int vote = 0;
        int candidate = 0;      // 出现次数超过一半的

        for (auto num: nums) {
            if (vote == 0) {    // 投票数vote为0，把当前遇到的数视为众数。相当于重置了一波
                candidate = num;
            }

            if (num == candidate) { // 当前遇到的是众数
                vote++;
            }
            else {  // 当前遇到的不是众数
                vote--;
            }
        }
//        return candidate;

        // 由于题目保证有元素出现次数大于n/2的，所以不用判断。
        // 如果自己判断，可以统计candidate的出现次数：
        int cnt = 0;
        for (auto num: nums) {
            if (num == candidate) cnt++;
        }
        if (cnt > nums.size() / 2) return candidate;
        else return -1;     // 没有出现次数大于n/2的元素
    }
};

// 哈希表，时间O(n)，空间O(n)
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> umap;
        for (auto num: nums) {
            umap[num]++;
        }

        for (auto num: umap) {
            if (num.second > nums.size() / 2) {
                return num.first;
            }
        }
        return -1;
    }
};

// 1 1 2 2 2        2 2 2 2 4 5
// 排序后，中间的数nums[nums.size()/2]一定是出现次数大于 n/2 的数