// https://leetcode.cn/problems/maximum-product-subarray/
// Created by caokang on 2023/10/3.
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 动态规划
class Solution152 {
public:
    // nums[i]之前的数的乘积可能是正的，也可能是负的。
    // 如果nums[i]是正数，希望之前子数组的乘积是正的，这样才能越乘越大；如果nums[i]是负数，那就希望之前子数组的乘积是负的并且要负的越大才好，这样负负得正。
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];

        vector<int> maxF(nums.size(), 0);      // maxF[i]: 以nums[i]结尾的子数组的最大值（正数要大，✖正数才能更大）
        vector<int> minF(nums.size(), 0);      // minF[i]: 以nums[i]结尾的子数组的最小值（负数要负的最小，这样✖负数才会更大），主要是为了提取出负的最大的数
        maxF[0] = nums[0], minF[0] = nums[0];

        // 因为nums[i]可能是正数，也可能是负数，所以要记一下前面负数乘积的最小值
        // 四种情况，逐一判断正、负很麻烦，所以可以直接按下面这种方式处理
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = max(maxF[i - 1] * nums[i], max(minF[i - 1] * nums[i], nums[i]));
            minF[i] = min(minF[i - 1] * nums[i], min(maxF[i - 1] * nums[i], nums[i]));
        }
        return *max_element(maxF.begin(), maxF.end());
    }
};

// 暴力，爆内存了
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];

        int result = INT16_MIN;
        vector<vector<int>> product(nums.size(), vector<int>(nums.size(), 0));

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (i == j) {
                    product[i][j] = nums[i];
                }
                else {
                    product[i][j] = product[i][j - 1] * nums[j];
                }
                result = max(result, product[i][j]);
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
//    nums = {0, 10, 10, 10, 10, 10, 10, 10, 10, 10, -10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0};   // 10^9就快溢出int了，这个minF就已经溢出int了

    Solution152 solution;
    int res = solution.maxProduct(nums);
    cout << res << endl;
}