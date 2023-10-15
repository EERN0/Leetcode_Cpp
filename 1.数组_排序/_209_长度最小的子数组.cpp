/*
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
 * 代码随想录：滑动窗口https://www.bilibili.com/video/BV1tZ4y1q7XE/
 * */
// 滑动窗口，类似：lc3 无重复字符的最长子串
#include <iostream>
#include <vector>

using namespace std;

class Solution209 {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int left = 0, right = 0;
        int sum = 0;
        int sum2 = 0;   // nums中所有元素加起来都小于target，就返回0
        int minLength = INT32_MAX;
        while (right < nums.size()) {
            sum += nums[right];
            sum2 += nums[right];
            // 缩小滑动窗口，增大left
            while (left <= right && sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        if (sum2 < target) {    // 不存在子数组之和大于target的
            return 0;
        }
        return minLength;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int sum = 0, sum2 = 0;
        int i = 0;
        int result = nums.size();
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            sum2 += nums[j];
            while (sum >= target) {
                int sublen = j - i + 1;
                result = min(sublen, result);
                sum = sum - nums[i];
                i++;
            }
        }
        if (sum2 < target) return 0;

        return result;
    }
};

int main() {
//    vector<int> nums = {2, 3, 1, 2, 4, 3};
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int target = 11;
    Solution s1;
    int len = s1.minSubArrayLen(target, nums);
    cout << "minSubArrayLen = " << len << endl;
}