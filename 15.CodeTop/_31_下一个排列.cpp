/*
 * 步骤有点难记
 * https://leetcode.cn/problems/next-permutation/
 * */
#include <vector>

using namespace std;

/*
 * 1.从后向前，找到第一个顺序对（即a[i] < a[i+1]），此时[较小数]为a[i]，[i+1,n)是降序序列(逆序的)
 * 2.在[i+1, n)中，从后向前找到第一个大于a[i]的数a[j]，此时a[j]为[较大数]
 * 3.交换较小数和较大数a[i]和a[j]，再把降序排序[i+1, n)区间的元素反转成升序（用双指针反转，不用sort）
 * */
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int smallerIndex = -1, biggerIndex = -1;
        int i = 0;

        // 从后向前，找[较小数]
        for (i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                smallerIndex = i;
                break;
            }
        }   // i == -1

        // 逆置降序区间为升序
        int left = i + 1, right = nums.size() - 1;

        // smallerIndex == -1，表明整个数组没有顺序对，都是逆序对（数组是单调递减的，例如4321，没有下一个排列）
        // 此时，认为[单调递减的序列的]下一个排列是逆置这个降序数组为升序的，把4321逆置为1234
        if (smallerIndex == -1) {
            while (left < right) {
                swap(nums[left++], nums[right--]);
            }
            return;
        }

        // 在[i+1, n)区间内，从后往前找到第一个[较大数]
        for (int j = nums.size() - 1; j >= i + 1; --j) {
            if (nums[j] > nums[i]) {
                biggerIndex = j;
                break;
            }
        }

        // 交换较小数和较大数
        swap(nums[smallerIndex], nums[biggerIndex]);

        // 逆置降序区间为升序
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
};