#include <iostream>
#include <vector>

using namespace std;

class Sort {
public:
    /*
     * 简单选择排序: 在每一趟待排序元素中选取关键字最小（或最大）的元素加入有序子序列
     * 时间复杂度O(n^2)，空间复杂度O(1)
     * 不稳定
     * */
    void SelectSort(vector<int> &A) {
        int n = A.size();
        int temp;
        for (int i = 0; i < n - 1; i++)     // 一共进行n-1趟
        {
            int min = i;                    // 记录最小元素的位置
            for (int j = i + 1; j < n; j++) // 在A[i...n-1]中选择最小的元素
            {
                if (A[j] < A[min]) min = j; // 更新最小元素的位置
                if (min != i) swap(A[i], A[min]);
            }
        }
    }

    /*
     * 插入排序
     * */
    void insertSort(vector<int> &nums) {
        if (nums.size() <= 1) return;

        int temp;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = i; j > 0 && nums[j - 1] > nums[j]; --j) {
                swap(nums[j - 1], nums[j]);
            }
        }
    }
};

int main() {
    Sort sort;
    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
    sort.insertSort(nums);

    for (auto o: nums) {
        cout << o << " ";
    }
    return 0;
}