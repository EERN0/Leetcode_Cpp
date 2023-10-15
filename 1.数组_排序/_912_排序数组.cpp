/*
 * https://leetcode.cn/problems/sort-an-array/
 * */
#include <iostream>
#include <vector>

using namespace std;

// 普通快排过不了这一题
class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
//        // 特判, 过五万个2的测试样例
//        vector<int> count(nums.size(), 0);
//        for (int num: nums) {
//            count[num]++;
//        }
//        if (count[nums[0]] == nums.size()) return nums;
//        else {
//
//        }

        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &A, int low, int high) {
        if (low >= high) return;
        int left = low, right = high;

        srand(time(nullptr));
        int random = rand() % (right - left + 1) + left;
        int pivot = A[random];
        swap(A[left], A[random]);

        while (left < right) {
            while (left < right && A[right] >= pivot) right--;
            A[left] = A[right];
            while (left < right && A[left] <= pivot) left++;
            A[right] = A[left];
        }
        A[left] = pivot;

        quickSort(A, low, left - 1);
        quickSort(A, left + 1, high);
    }
};

int main() {
    vector<int> nums = {1,2,3,4,6,7};

    Solution solution;
    vector<int> A = solution.sortArray(nums);

    return 0;
}