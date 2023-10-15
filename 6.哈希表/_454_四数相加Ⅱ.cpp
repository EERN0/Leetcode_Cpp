/*
 * https://leetcode.cn/problems/4sum-ii/
 * */

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
        // key存数组值, value存出现次数
        unordered_map<int, int> map;
        for (int a: nums1) {
            for (int b: nums2) {
                map[a + b]++;
            }
        }

        // num1 = [ 1, 1, 1], num2 = [ 1, 1, 1]
        // num3 = [-1,-1,-1], num4 = [-1,-1,-1]
        int count = 0;
        for (int c: nums3) {
            for (int d: nums4) {
                if (map.find(0 - (c + d)) != map.end()) {
                    count += map[-(c + d)];
                }
            }
        }

        return count;
    }
};