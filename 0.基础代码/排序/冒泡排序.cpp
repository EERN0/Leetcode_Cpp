//
// Created by caokang on 2023/6/3.
//
#include <iostream>
#include <vector>

using namespace std;

/*
 * 冒泡排序：每一趟比较相邻的两个元素，若左边的元素大于右边的元素，就交换它们的位置，一趟结束后，最大的元素就确定在最右边了
 * n个元素，一般要进行n躺排序，每一趟都能找到大元素的最终位置
 * */
void bubbleSort(vector<int> &nums) {
    bool flage = false;     // 标记这一趟有没有发生交换，如果没有交换的话，就说明元素全部有序了，退出冒泡排序
    for (int i = 0; i < nums.size(); ++i) {     // 趟数
        flage = false;
        for (int j = 1; j < nums.size(); ++j) { // 比较元素大小
            if (nums[j - 1] > nums[j]) {    // 左边的元素大了，要发生交换
                swap(nums[j - 1], nums[j]);
                flage = true;
            }
        }

        // 这一趟没有发生交换，说明序列都是递增的
        if (flage == false) {
            return;
        }
    }
}

int main() {
    vector<int> nums = {4, 3, 6, 5, 1, 2};
    bubbleSort(nums);
    for (auto o: nums) {
        cout << o << " ";
    }
}