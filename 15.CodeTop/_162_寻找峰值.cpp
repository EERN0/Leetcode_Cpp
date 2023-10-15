// https://leetcode.cn/problems/find-peak-element/description/
// Created by kang on 2023/8/25.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// 题目保证了：nums[i] != nums[i + 1]

// 寻找峰值：人往高处走，往高处搜索。用二分，时间O(lgn)
class Solution162 {
public:
    int findPeakElement(vector<int> &nums) {
        int left = 0, right = nums.size() - 1;

        // 不能加等于号，left==right一直成立，会死循环
        // eg：[1, 2, 3]、[1, 2, 3, 1]
        while (left < right) {
            int mid = (left + right) / 2;

            // 往大的数搜（往高处走）
            if (nums[mid] < nums[mid + 1]) {    // 往mid+1的方向搜
                left = mid + 1;
            }
            else if (nums[mid] > nums[mid + 1]) {   // 往mid的方向搜
                right = mid;
            }
        }
        return left;
    }
};


int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    Solution162 solution162;
    int res = solution162.findPeakElement(nums);
    cout << res << endl;
}

//// 暴力，时间O(n)
//int findPeakElement(vector<int> &nums) {
//    // 找到最大值就是峰值
//    int maxValueIndex = max_element(nums.begin(), nums.end()) - nums.begin();
//    return maxValueIndex;
//}