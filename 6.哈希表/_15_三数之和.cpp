/*
 * https://leetcode.cn/problems/3sum/
 *
 * advance: 16.最接近的三数之和
 * https://leetcode.cn/problems/3sum-closest/
 * */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 15. 三数之和
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        // a+b+c=0
        for (int i = 0; i < nums.size(); i++) {
            // 对a去重
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {  // left==right时，只有两个数了，不满足
                if (nums[i] + nums[left] + nums[right] > 0) {       // a+b+c大了，缩小c
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {  // a+b+c小了，增大b
                    left++;
                }
                else {  // a+b+c==0
                    // 收集一个结果先
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 缩小搜索范围
                    left++, right--;

                    // 对b、c去重
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        // 排序
//        sort(nums.begin(), nums.end());
        quickSort(nums, 0, nums.size() - 1);
        vector<vector<int>> result;

        // -4 -1 -1 0 1 2
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return result;     // 最小的数都大于0，三数之和必不为0

            int left = i + 1;
            int right = nums.size() - 1;

            // 去重, nums = [-1, -1, -1, -1, 2, 2, 2]
            // 为什么不是nums[i]==nums[i+1]时跳过? 当条件为nums[i]==nums[i+1]时会跳过结果{-1,-1,2}
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {   // 缩小right
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {  // 增大left
                    left++;
                }
                else {
                    // 收获一个结果后, 左右指针收缩(一个减小一个增大), 继续找
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // 去重, 第2和第3个数也不重复选取
                    // left和左边的数一样, left右移
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    // right和右边的数一样, right左移
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return result;
    }

    void quickSort(vector<int> &nums, int low, int high) {
        if (low >= high) return;

        int left = low, right = high;

        srand(time(nullptr));
        int random = rand() % (high - low + 1) + low;
        int pivot = nums[random];
        swap(nums[low], nums[random]);

        while (low < high) {
            while (low < high && nums[high] >= pivot) high--;
            nums[low] = nums[high];
            while (low < high && nums[low] <= pivot) low++;
            nums[high] = nums[low];
        }
        nums[low] = pivot;

        quickSort(nums, left, low - 1);
        quickSort(nums, low + 1, right);
    }
};


// 打印二维数组
void printMatrix(vector<vector<int>> &A) {
    // 二维数组——A[[], [], []]  A.size()表示里面一维数组的个数
    int m = A.size();       // m行
    int n = A[0].size();    // n列

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == 0 && j == 0) cout << "[";
            if (j == 0) cout << "[";
            if (j != n - 1) {
                cout << A[i][j] << ", ";
            }
            else if (j == n - 1) {
                cout << A[i][j] << "]";
            }
            if (i == m - 1 && j == n - 1) cout << "]";
        }
    }
}


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
//    vector<int> nums = {-2, 0, 1, 1, 2};
    Solution s1;
    vector<vector<int>> A = s1.threeSum(nums);

    printMatrix(A);

    return 0;
}