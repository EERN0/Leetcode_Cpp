// https://leetcode.cn/problems/next-greater-element-ii/
// Created by caokang on 2023/6/9.
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        if (nums.size() <= 1) return {0};
        vector<int> loopNum(2 * nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            loopNum[i] = nums[i];
            loopNum[nums.size() + i] = nums[i];
        }

        vector<int> result(nums.size(), -1);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < loopNum.size(); ++j) {
                if (nums[i] == loopNum[j]) {
                    int temp = nums[i];
                }
            }
        }
    }
};