// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// 6/11

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 和[1两数之和]的区别在于，输入的数组是有序的

// 双指针
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> result;
        while (left < right) {  // left==right就变成一个数了
            if (numbers[left] + numbers[right] == target) {
                result = {left + 1, right + 1};
                break;
            }
            else if (numbers[left] + numbers[right] > target) {
                right--;
            }
            else {
                left++;
            }
        }
        return result;
    }
};

/*
 * 腾讯面试变形：
 * 给你一个array=[1,9,134,10,25,40,4,7], 给一个target，返回所有A+B=target的（pair对）
 * 比如是target=11，返回[(1,10),(4,7)],每个元素只能用一次
 * */