// Created by caokang on 2023/5/13.
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
// 和lc27移除元素基本一样
#include <vector>

using namespace std;

// 双指针
class Solution1 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();

        // nums[0]肯定要留下来的
        int slow = 1;   // slow下标存放只见过1次的数字
        int fast = 1;   // 扫描有序数组

        for (; fast < nums.size(); ++fast) {
            // 只处理和前面一个元素不重复的元素，重复的元素后面会被覆盖掉
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                slow++;
            }
        }

        return slow;    // 新数组的大小就等于slow
    }
};

// 直接暴力，建一个新数组存不重复的数，再回头修改原数组nums
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1) return nums.size();

        vector<int> res;

        res.push_back(nums[0]);     // nums[0]肯定要留下来的
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                res.push_back(nums[i]);
            }
        }

        for (int i = 0; i < res.size(); ++i) {
            nums[i] = res[i];
        }
        return res.size();
    }
};