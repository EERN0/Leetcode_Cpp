/*
 * 题目：https://leetcode.cn/problems/remove-element/
 * 代码随想录：https://www.bilibili.com/video/BV12A4y1Z7LP/
 *
 * vector中的删除erase，时间复杂度是O(n)
 * */
#include <iostream>
#include <vector>

using namespace std;

// [3 2 4 1 1 5]
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        // fast获取新数组中需要的元素
        // slow是获取新数组中需要更新的位置
        int fast, slow;
        // 更新数组中的元素（找到目标值val就不更新新数组）
        for (fast = 0, slow = 0; fast < nums.size(); fast++) {
            // 只处理不等于val的元素，等于val的元素后面直接被覆盖
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main() {
    vector<int> nums = {3, 2, 2, 3};
    Solution s1;
    int n = s1.removeElement(nums, 3);
    cout << "len == " << n << endl;
}
