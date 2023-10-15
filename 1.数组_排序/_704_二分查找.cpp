#include <iostream>
#include <vector>

using namespace std;
// nums = [-1,0,3,5,9,12], target = 9

/*
 * 根据区间的定义，left <= right还是left < right，以及更新left和right
 * 1、[left, right]区间，right = num.size-1, while(left<=right), left = mid+1, right = mid-1
 * 2、[left, right)区间，right = num.size, while(left<right), left = mid+1, right = mid
 * */

//左闭右闭区间，[left,right]
class Solution1 {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid;

        while (l <= r) {    // [0, n-1]，l和r在有效区间里面，是合法区间
            mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid - 1;    // nums[mid]已经不符合条件了，所以不用再判断mid
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
};

// 左闭右开区间，[left, right)
class Solution2 {
public:
    int search(vector<int> &nums, int target) {
        int l = 0;
        int r = nums.size();
        int mid;

        while (l < r) {
            mid = (l + r) / 2;
            if (nums[mid] > target) {
                r = mid;    // nums[mid]已经不符合要求了，right=mid，说明是左闭右开区间[left, right)
            }
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else return mid;
        }
        return -1;
    }
};


// 二分查找，找到最接近且大于target的那个数
// 左闭右开区间，left就是大于且最接近target的数
int binarySearch(vector<int> &nums, double target) {
    int left = 0, right = nums.size() - 1;  // 注定左闭右闭区间，left<=right，left=mid-1，right=mid+1
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return nums[mid];
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    // 退出while，说明要么找到target，要么找到大于且最接近target的位置了
    if (left >= nums.size()) {   // 越界判断
        return -1;
    }

    // nums[left]就是那个最接近且大于target的数
    return nums[left];
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
//    Solution1 s1;
//    Solution2 s2;
//    int index = s2.search(nums, 9);
//    cout << "index = " << index << endl;

    cout << "===================" << endl;

    int res = binarySearch(nums, 10);
    cout << res << endl;

    return 0;
}
