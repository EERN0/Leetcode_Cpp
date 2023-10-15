// Created by caokang on 2023/3/24.
/*
 * https://leetcode.cn/problems/median-of-two-sorted-arrays/
 * 要求时间复杂度为O(lg(m+n))，分治
 * */
#include <iostream>
#include <vector>

using namespace std;

// 暴力，扫面两个数组，时间O(m+n)，就算只扫描每个数组的一半，也要O((m+n)/2)
class Solution1 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> newVector = merge(nums1, nums2);
        int n = newVector.size();

        if (n % 2 == 1) {
            return newVector[n / 2];
        }
        else {
            double mid = newVector[n / 2] + newVector[n / 2 - 1];
            return mid / 2;
        }
    }

    vector<int> merge(vector<int> &nums1, vector<int> &nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> result(size1 + size2, 0);

        int i = 0, j = 0;

        while (i < size1 && j < size2) {
            if (nums1[i] <= nums2[j]) {
                result[i + j] = nums1[i];
                i++;
            }
            else {
                result[i + j] = nums2[j];
                j++;
            }
        }   // 有一个数组走完了

        while (i < size1) {     // num2走完了
            result[i + j] = nums1[i];
            i++;
        }

        while (j < size2) {    // num1走完了
            result[i + j] = nums2[j];
            j++;
        }
        return result;
    }
};



// 分治
/*
 * 有序数组中位数的下标，奇数数组中位数为(0+size-1)/2, 偶数数组中位数为(0+size-1)/2、(0+size-1)/2+1再除以2
 * 有序数组中位数的下标为i，对应的是数组第(i+1)小的元素
 * 所以，奇数数组的中位数就是找第[(0+size-1)/2+1]小元素，
 * 偶数数组的中位数就是要找第[(0+size-1)/2+1]、第[(0+size-1)/2+2]小元素
 * */
class Solution2 {
public:
    /*
     * findTheKth(): 给定两个排序数组，找到他们合在一起后的第k小元素
     * */

    // i：nums1的起始位置, j：nums2的起始位置，
    // 两数组的规模在不断变化(去除一些元素变成新数组), 用i,j来控制两个数组的下标起始位置
    int findTheKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        // 一、递归结束条件
        if (i >= nums1.size()) {
            // 下标起始位置i大于nums1的最大下标，nums1为空，返回nums2新数组(下标从j开始)的第k小的元素，下标为k-1
            return nums2[j + k - 1];
        }
        if (j >= nums2.size()) {
            return nums1[i + k - 1];
        }
        // 当k=1时，找新数组(下标为i,j的两数组)的最小值，即两数组中最小的元素
        if (k == 1) return min(nums1[i], nums2[j]);

        // 二、单层递归逻辑
        // k永远表示第几小, 对应的数组下标为k-1
        int size1 = nums1.size() - i;
        int size2 = nums2.size() - j;
        // 越界处理
        int k1 = min(k / 2, size1);
        int k2 = min(k - k1, size2);
        if (nums1[i + k1 - 1] < nums2[j + k2 - 1]) {
            // 去除nums1中的前k1个元素，就是num1的下标从k1开始，再与nums2合并
            return findTheKth(nums1, i + k1, nums2, j, k - k1);
        }
        else {
            // nums1[i + k1 - 1] >= nums2[j + k2 - 1]，去除nums2中的前k2个元素，再与nums1合并
            return findTheKth(nums1, i, nums2, j + k2, k - k2);
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int size = nums1.size() + nums2.size();
        double result = 0;
        if (size % 2 == 0) {
            // 偶数个元素，找第k小的，和第k+1小的元素，再除以2
            double left = findTheKth(nums1, 0, nums2, 0, (0 + size - 1) / 2 + 1);
            double right = findTheKth(nums1, 0, nums2, 0, (0 + size - 1) / 2 + 2);
            result = (left + right) / 2;
        }
        else {
            result = findTheKth(nums1, 0, nums2, 0, (0 + size - 1) / 2 + 1);
        }
        return result;
    }
};


int main() {
    Solution2 s;
//    vector<int> v1 = {5, 6, 7, 8, 9, 10};
//    vector<int> v2 = {1, 2, 3, 4};
    vector<int> v1 = {1, 3, 5, 7};
    vector<int> v2 = {2, 4, 6, 8, 9};

    double a = s.findMedianSortedArrays(v1, v2);

    cout << "中位数是: " << a << endl;

    return 0;
}