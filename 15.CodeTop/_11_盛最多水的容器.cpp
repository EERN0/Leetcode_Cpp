// https://leetcode.cn/problems/container-with-most-water/
// Created by caokang on 2023/12/28.
//
#include <vector>
#include <iostream>

using namespace std;

// 双指针
class Solution11_1 {
public:
    int maxArea(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int mostWater = 0;
        while (left < right) {
            if (height[left] <= height[right]) {
                mostWater = max(min(height[left], height[right]) * (right - left), mostWater);
                left++;
            }
            else {
                mostWater = max(min(height[left], height[right]) * (right - left), mostWater);
                right--;
            }
        }
        return mostWater;
    }
};