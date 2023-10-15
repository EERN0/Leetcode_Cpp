/*
 * https://leetcode.cn/problems/search-in-rotated-sorted-array/
 *
 * 定理一：只有在顺序区间内才可以通过区间两端的数值判断target是否在其中（顺序区间才可以用二分法,时间O(lgn)）
 * 定理二：判断顺序区间还是乱序区间，只需要对比 left 和 right 是否是顺序对即可，left <= right，顺序区间，否则乱序区间。
 *
 * 有序数组逆置后，一分为二，其中一个部分一定是有序的，另一个部分可能是有序，也能是部分有序（一个部分无序，另一个部分一定有序）
 * 此时有序部分用二分法查找，无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序，就这样循环.
 * */
#include <iostream>
#include <vector>

using namespace std;

/*
 * 二分的边界条件
 * */
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {     // left==right时，mid就是left或right，
            int mid = (left + right) >> 1;  // 左乘右除，mid为中左
            if (nums[mid] == target) return mid;

            // 左边区间[left, mid]是有序的
            if (nums[left] <= nums[mid]) {
                (nums[left] <= target && target <= nums[mid]) ? right = mid - 1 : left = mid + 1;
            }
            else {  // 右边[mid, right]是有序的
                (nums[mid] <= target && target <= nums[right]) ? left = mid + 1 : right = mid - 1;
            }
        }

        // 原题：return -1;
        /*
         * 改动：若没找到target，返回大于target的第一个数，应该就只有下面的三种情况
         * */
        if (nums[left] > target) return nums[left];
        if (nums[right] > target) return nums[right];
        if (nums[0] > target) return nums[0];

        return -1;  // 没找到返回-1
    }
};

int main() {
    vector<int> nums = {4, 6, 7, 0, 1, 2, 3};
    Solution s;
    int res = s.search(nums, 5);
    cout << res << endl;

    vector<int> nums2 = {4, 5, 7, 0, 1, 2, 3};
    Solution s2;
    int res2 = s2.search(nums2, 6);
    cout << res2 << endl;

    vector<int> nums3 = {5, 7, 9, 10, 12, 14, 1, 3};
    Solution s3;
    int res3 = s3.search(nums3, 4);
    cout << res3 << endl;

    return 0;
}