/*
 * https://leetcode.cn/problems/intersection-of-two-arrays/
 * */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 直接使用set
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // unordered_set<>中无重复元素
        unordered_set<int> num_set(nums1.begin(), nums1.end());
        unordered_set<int> res;

        for (int num: nums2) {
//            if (num_set.count(num)) {     // num_set.count(num)——获取容器中指定元素值的元素个数
//                res.insert(num);
//            }

            if (num_set.find(num) != num_set.end()) {   // 若集合中没有指定元素num，返回num_set.end()
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};


/*
 * 数组模拟哈希表,
 * 由于题目给了限制1 <= nums1.length, nums2.length <= 1000, 所以可以用数组模拟哈希表
 * */
class Solution2 {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        vector<int> A(1001, 0);
        unordered_set<int> res;     // unordered_set<>中无重复元素

        for (int num: nums1) {
            A[num] = 1;
        }

        for (auto num: nums2) {
            if (A[num] == 1) {      // num1中有的元素，num2中也有
                res.insert(num);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};