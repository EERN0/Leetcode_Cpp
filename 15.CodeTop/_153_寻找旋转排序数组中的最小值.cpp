// https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/
// Created by caokang on 2023/10/6.
//
#include <vector>

using namespace std;

// 画个图，旋转后数组最后一个元素为x，最小值和最后一个元素之间的元素都小于x，数组第一个元素到最小值之间的元素都大于x
class Solution153 {
public:
    int findMin(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {   // 中间元素在最小值的右边
                right = mid;    // nums[mid]有可能是最小值，不能写成right=mid-1;
            }
            else {      // 中间元素在最小值的左边
                left = mid + 1;
            }
        }
        return nums[left];
    }
};