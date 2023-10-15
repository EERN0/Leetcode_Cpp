// https://leetcode.cn/problems/longest-consecutive-sequence/
// Created by caokang on 2023/10/2.
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

// 用哈希表去重
// 遍历到一个元素x，先判断x-1在不在哈希表里面，不在的话，一直判断x+1、x+2是否在哈希表里面，记录当前连续长度和最长连续长度。
// 扫描到x+1，发现前驱元素x在哈希表中，跳过不用判断了；扫描到x+3，发现前驱x+2不在哈希表里面，判断x+4、x+5是否在哈希表中，并更新当前连续长度和最长连续长度
class Solution128 {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> uset;
        for (const int &num: nums) {
            uset.insert(num);
        }

        int maxLen = 0;
        for (const auto &x: uset) {
            // 当前元素x的前驱x-1不在哈希表中，才进行判断，因为后面会判断那些后继元素x+1、x+2...之类的，
            // 当x的前驱x-1在哈希表中，说明扫描到x-1时，已经处理了x-1的后继元素x、x+1这些，不用重复处理了
            if (!uset.count(x - 1)) {
                int currNum = x;    // 当前元素x
                int currLen = 1;

                while (uset.count(currNum + 1)) {   // 循环判断当前元素的后继元素在不在哈希表中
                    currNum++;      // x+1在的话，下次判断x+2...
                    currLen++;      // 当前最长连续序列长度+1
                }

                maxLen = max(maxLen, currLen);
            }
        }
        return maxLen;
    }
};


// 暴力，先排个序，再去掉数组中重复的元素，最后判断最长连续序列
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int maxLen = 1; // 最长连续数字的长度
        int cnt = 1;    // 连续数字的个数

        // 去掉重复元素
        vector<int> new_nums;
        new_nums.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) {
                continue;
            }
            else {
                new_nums.push_back(nums[i]);
            }
        }

        for (int i = 1; i < new_nums.size(); ++i) {
            if (new_nums[i - 1] + 1 == new_nums[i]) {   // 靠近的两个数字是连续的，计数++
                cnt++;
            }
            else {  // 两个挨着的数字不连续时，cnt置为1
                cnt = 1;
            }
            maxLen = max(maxLen, cnt);
        }
        return maxLen;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 1, 3, 2};
    Solution solution;
    int res = solution.longestConsecutive(nums);
    cout << res << endl;
}