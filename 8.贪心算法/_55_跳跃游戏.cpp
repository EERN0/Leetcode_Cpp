// https://leetcode.cn/problems/jump-game/
// Created by caokang on 2023/9/19.
//
#include <vector>

using namespace std;

class Solution55 {
public:
    bool canJump(vector<int> &nums) {
        int cover = 0;      // 能跳到的最大下标（覆盖的最大下标）

        // 在已有的覆盖范围内遍历
        for (int i = 0; i <= cover; ++i) {      // i<=cover，要在覆盖范围cover内移动
            cover = max(cover, i + nums[i]);    // nums[i]就是能跳多少格。i+nums[i]就是从当前位置开始，最多能跳到哪个下标

            if (cover >= nums.size() - 1) {     // 覆盖到最后一个下标
                return true;
            }
        }
        return false;
    }
};