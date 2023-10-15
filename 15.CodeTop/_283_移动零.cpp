// https://leetcode.cn/problems/move-zeroes/
// Created by caokang on 2023/10/8.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution283 {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() <= 1) return;
        int left = 0, right = 0;
        while (right < nums.size()) {
            // nums[right]等于0的时候跳过，不做处理
            // nums[right]不为0的时候，与nums[left]交换，nums[left]此时必然是0
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 2, 0, 0, 3, 0, 5};
    Solution283 solution;
    solution.moveZeroes(nums);
    for (auto num: nums) {
        cout << num << " ";
    }
}