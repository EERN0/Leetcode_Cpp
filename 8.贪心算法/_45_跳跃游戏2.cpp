// https://leetcode.cn/problems/jump-game-ii/
// Created by caokang on 2023/9/20.
#include <vector>
#include <iostream>

using namespace std;
// 确实复杂！！
class Solution45 {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) return 0;

        int cur = 0;        // 当前能跳到的最大下标   (当前的覆盖范围)
        int next = 0;       // 下一次能跳到的最大下标 (下一步的覆盖范围)
        int result = 0;     // 跳跃的次数

        for (int i = 0; i < nums.size(); ++i) {
            next = max(next, i + nums[i]);

            if (i == cur) {
                if (i != nums.size() - 1) {     // 当i等于cur时，且没有走到最后一个元素，说明当前的最大覆盖范围走完了，必须要跳下一次了
                    result++;
                    cur = next;     // 跳一次之后，当前的覆盖范围(最大下标) 等于 下一次的覆盖范围(最大下标)

                    if (cur >= nums.size() - 1) {   // 走到最后一个元素了
                        break;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    nums = {1, 2, 1, 1, 1};
    Solution45 solution;
    int res = solution.jump(nums);
    cout << res << endl;
}