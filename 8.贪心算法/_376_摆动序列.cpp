// Created by caokang on 2023/9/19.
// https://leetcode.cn/problems/wiggle-subsequence/
#include <vector>
#include <iostream>

using namespace std;

// 贪心，边界多
class Solution376 {
public:
    int wiggleMaxLength(vector<int> &nums) {
        if (nums.size() == 1) return 1;
        if (nums.size() == 2) {
            if (nums[0] != nums[1]) return 2;
            else return 1;
        }

        int curdif = 0;     // 当前一对的差值
        int predif = 0;     // 前一对的差值
        int result = 1;

        for (int i = 0; i < nums.size() - 1; ++i) {
            curdif = nums[i + 1] - nums[i];
            // 出现峰值
            if ((predif >= 0 && curdif < 0) || (predif <= 0 && curdif > 0)) {
                result++;
                // 只有在有摆动变化的时候更新predif
                predif = curdif;
            }
        }
        return result;
    }
};

// 动态规划
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {

    }
};


int main() {
    Solution376 s;
    vector<int> nums = {1, 7, 4, 9, 2, 5};
    int res = s.wiggleMaxLength(nums);
    cout << res << endl;
}