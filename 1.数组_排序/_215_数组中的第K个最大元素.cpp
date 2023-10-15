/*
 * https://leetcode.cn/problems/kth-largest-element-in-an-array/
 * 数组中的第K个最大元素, 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 快速排序时间复杂度O(nlogn), 空间复杂度O(1)
 * */
#include <iostream>
#include <vector>

using namespace std;

// 快排后，再查找第k大的元素
// 时间复杂度高O(nlogn)
class Solution_QuickSort {
public:
    int findKthLargest(vector<int> &nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k];
    }

    void quickSort(vector<int> &A, int low, int high) {
        if (low >= high) return;    // 递归结束条件
        int left = low, right = high;

        // 随机选取一个元素作为基准
        srand(time(nullptr));   // 随机数种子
        int random = rand() % (high - low + 1) + low;
        int pivot = A[random];
        swap(A[low], A[random]);     // 把基准换到第一个位置

        while (low < high) {
            while (low < high && A[high] >= pivot) high--;
            A[low] = A[high];   // 交换，把大的放到基准左边
            while (low < high && A[low] <= pivot) low++;
            A[high] = A[low];
        }
        // 基准放到最终的位置上
        A[low] = pivot;

        // 递归处理左右区间
        quickSort(A, left, low - 1);
        quickSort(A, low + 1, right);
    }
};

// 快速选择，不用对整个数组进行快排，一次快排可以确定一个基准元素的位置，和k比较一下，可以省掉几次快排
class Solution_QuickSelect {
public:
    void quickSelect(vector<int> &A, int low, int high, int target) {
        if (low >= high) return;    // 递归结束条件
        int low_init = low, high_init = high;

        // 随机选取一个元素作为基准
        srand(time(nullptr));   // 随机数种子
        int random = rand() % (high - low + 1) + low;
        int pivot = A[random];
        swap(A[low], A[random]);     // 把基准换到第一个位置

        while (low < high) {
            while (low < high && A[high] >= pivot) high--;
            A[low] = A[high];   // 交换，把小的放到基准左边
            while (low < high && A[low] <= pivot) low++;
            A[high] = A[low];
        }
        // 基准放到最终的位置上, low是当前基准的位置
        A[low] = pivot;

        // 基准后面有几个比基准大的元素？A.size()-1-low个, 基准所在的是第(A.size()-1-low + 1)大的
        int n = A.size() - 1 - low + 1;
        if (target == n) return;
        if (target > n) {   // 要找的数比基准小,在基准的左边
            quickSelect(A, low_init, low - 1, target);
        }
        if (target < n) {   // 第target大的，比基准大，在基准右边
            quickSelect(A, low + 1, high_init, target);
        }

    }

    int findKthLargest(vector<int> &nums, int k) {
        quickSelect(nums, 0, nums.size() - 1, k);
        return nums[nums.size() - k];
    }
};


// 打印 vector
void printVector(vector<int> &v) {
    for (auto &it: v) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
//    vector<int> nums = {3,1,2,4};
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6, 7, 7, 8, 2, 3, 1, 1, 1, 10, 11, 5, 6, 2, 4, 7, 8, 5, 6};
    nums = {7, 6, 5, 4, 3, 2, 1};

    Solution_QuickSort s1;
    Solution_QuickSelect s2;

    int k = 2;
    int n = s2.findKthLargest(nums, k);
    printVector(nums);
    cout << "the " << k << "th " << "largest num = " << n << endl;
}