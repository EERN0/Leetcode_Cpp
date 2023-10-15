// Created by caokang on 2023/3/24.
// https://leetcode.cn/problems/maximum-subarray/
#include <iostream>
#include <vector>

using namespace std;
/*
 *  0  1   2  3   4  5  6   7  8
 * -2, 1, -3, 4, -1, 2, 1, -5, 4
 * */

// 分治, 时间复杂度O(nlog2n), T(n)=2T(n/2)+O(n)
/*
 * 中间线(含)左边最大，中间线右边最大，跨中间线最大
 * */
class Solution1 {
public:
    int getMax(vector<int> &nums, int left, int right) {
        // 递归结束条件
        if (left == right) return nums[left];    // 只有一个元素时，最大就是自己

        int mid = left + (right - left) / 2;
        // 1.左区间最大值
        int leftMax = getMax(nums, left, mid);
        // 2.右区间最大值
        int rightMax = getMax(nums, mid + 1, right);

        // 3.跨越中间线的最大值, 时间O(n)
        int leftSum = INT32_MIN, rightSum = INT32_MIN;
        for (int i = mid, sum = 0; i >= left; i--) {        // 从中间线(含)向左
            sum += nums[i];
            leftSum = max(sum, leftSum);
        }
        for (int j = mid + 1, sum = 0; j <= right; j++) {   // 中间线的右边
            sum += nums[j];
            rightSum = max(sum, rightSum);
        }

        int crossSum = leftSum + rightSum;
        return max(max(leftMax, rightMax), crossSum);
    }


    int maxSubArray(vector<int> &nums) {
        return getMax(nums, 0, nums.size() - 1);
    }
};

// 动态规划
// 求出最大子数组
class Solution53 {
public:
    vector<int> maxSubArray(vector<int> &nums) {
        if (nums.size() == 1) return {nums[0]};

        // dp[i]：以nums[i]结尾的最大子数组和为dp[i]
        vector<int> dp(nums.size(), INT32_MIN);

        int maxSum = nums[0];
        int startIndex = 0;     // 最大子数组的起始位置
        int endIndex = 0;       // 最大子数组的终止位置

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i];
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            }

            if (dp[i] > maxSum) {
                maxSum = dp[i];
                endIndex = i;
            }
        }

        // 拿到最大和以及终止位置后，从子数组终止位置往前推，最大值减为0就是子数组的起始下标
        int maxCopy = maxSum;
        for (int i = endIndex; i >= 0; --i) {
            maxCopy -= nums[i];
            if (maxCopy == 0) {
                startIndex = i;
                break;
            }
        }

        // [起始位置，终止位置]
        vector<int> subArray(nums.begin() + startIndex, nums.begin() + endIndex + 1);
        return subArray;
    }
};

// 只求和
class Solution2 {
public:
    int maxSubArray(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int maxResult = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = nums[i];
            if (dp[i - 1] >= 0) {
                dp[i] += dp[i - 1];
            }

            maxResult = max(maxResult, dp[i]);
        }

        return maxResult;
    }
};


int main() {
    Solution1 s1;
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int res = s1.maxSubArray(v);

    cout << "最大子数组和: " << res;

    return 0;
}