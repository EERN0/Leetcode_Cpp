/*
 * https://leetcode.cn/problems/first-missing-positive/
 * */
#include <vector>
#include <unordered_set>

using namespace std;

// 原地哈希
// 把n放在原数组的第n位,不用辅助数组：时间O(n)，空间O(1)
class Solution3 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();

        // 把元素k放到数组第k位(下标为k-1)
        for (int i = 0; i < size; ++i) {
            // nums[i]在1~size的范围内，而且n不在nums数组的第n位，就把n交换到数组的第n位
            // 例如，数组中元素1，放到数组下标0的位置上
            while (nums[i] >= 1 && nums[i] <= size && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 走出for循环[3, 4, -1, 1]变为[1, -1, 3, 4]

        // 遍历排序后的数组
        for (int i = 1; i <= size; ++i) {
            if (nums[i-1] != i) {     // 第i个数字不是i，那就是缺失的正数
                return i;
            }
        }
        return size + 1;
    }
};


// 使用额外空间，用一个bool数组，大小为size，原数组nums出现过就记为true：时间O(n)，空间O(n)
class Solution2 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int size = nums.size();
        // bool数组表示1~size的正数，原数组中出现了，就将这个位置置为true，eg: 原数组中有2，就将第2个位置置为true
        vector<bool> visited(size, false);

        for (int i = 0; i < size; ++i) {
            if (nums[i] >= 1 && nums[i] <= size) {
                visited[nums[i] - 1] = true;
            }
        }

        for (int j = 0; j < size; ++j) {
            if (!visited[j]) return j + 1;
        }

        return size + 1;
    }
};


// 用哈希表记录nums的每一个数,从1遍历到size，若没在哈希表中出现，说明是缺失的第一个正数
// 时间O(n)，空间O(n)，不符合空间O(1)的要求
class Solution1 {
public:
    int firstMissingPositive(vector<int> &nums) {
        unordered_set<int> hashset;
        for (const auto &o: nums) {
            hashset.insert(o);
        }

        int i = 1;
        for (i = 1; i <= nums.size(); ++i) {
            // 从1遍历到size，哈希表中没出现的就是最小正数
            if (hashset.count(i) == 0) {
                return i;
            }
        }
        return i;   // 数组nums={1}时，返回2
    }
};